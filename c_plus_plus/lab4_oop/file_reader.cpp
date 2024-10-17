#include "file_reader.h"

float FileReader::getMinZ(const std::vector<std::vector<float>>& data) {
    float res = data[0][0];

    for (size_t i = 0; i < data.size(); i++) {
        for (size_t j = 0; j < data[i].size(); j++) {
            if (res > data[i][j]) {
                res = data[i][j];
            }
        }
    }

    return res;
}

float FileReader::getMaxZ(const std::vector<std::vector<float>>& data) {
    float res = data[0][0];

    for (size_t i = 0; i < data.size(); i++) {
        for (size_t j = 0; j < data[i].size(); j++) {
            if (res < data[i][j]) {
                res = data[i][j];
            }
        }
    }

    return res;
}

std::vector<std::vector<float>> FileReader::normalize(std::vector<std::vector<float>>& data, NormalizationParameters& parameters) {
    float min = getMinZ(data);
    float max = getMaxZ(data);

    for (size_t i = 0; i < data.size(); i++) {
        for (size_t j = 0; j < data[i].size(); j++) {
            data[i][j] = parameters.getMin() + ((data[i][j] - min) * (parameters.getMax() - parameters.getMin())) / (max - min);
        }
    }

    return data;
}

std::vector<std::vector<float>> FileReader::getDataFromFile(const std::string& path) {
    std::vector <std::vector<float>> data;
    FacadeOperationResult result;
    std::ifstream file(path);

    if (!file.is_open()) {
        result.setErrorMessage("File was not opened!");
        throw result.getErrorMessage();
    }

    std::string str;
    while (getline(file, str)) {
        if (str.empty()) {
            result.setErrorMessage("Line is empty!");
            throw result.getErrorMessage();
        }

        std::vector<float> row;
        size_t pos = 0;
        float value;
        str.push_back(',');
        while (str.size()) {
            std::string readedValue;
            pos = str.find(',');
            readedValue = str.substr(0, pos);
            value = stoi(readedValue);
            row.push_back(value);
            str.erase(0, pos + 1);
        }
        data.push_back(row);
    }

    file.close();
    return data;
}

std::vector<Vertex>* FileReader::makeVertices(std::vector<std::vector<float>>& data, NormalizationParameters params) {
    std::vector<Vertex>* res = new std::vector<Vertex>;

    for (size_t i = 0; i < data.size(); i++) {
        for (size_t j = 0; j < data[i].size(); j++) {
            Point tmp_point(i * params.getDxStep(), j * params.getDyStep(), data[i][j]);
            Vertex tmp_vertex(tmp_point);
            res->push_back(tmp_vertex);
        }
    }

    return res;
}

std::vector<Edge>* FileReader::makeEdge(std::vector<Vertex>& vertices, size_t length, size_t width) {
    std::vector<Edge>* res = new std::vector<Edge>;

    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < width; j++) {
            if ((i + 1) < length) {
                Edge horizontal_edge(vertices[width * i + j], vertices[width * (i + 1) + j]);
                res->push_back(horizontal_edge);
            }
            if ((j + 1) < width) {
                Edge vertical_edge(vertices[width * i + j], vertices[width * i + j + 1]);
                res->push_back(vertical_edge);
            }
        }
    }

    return res;
}

std::shared_ptr<Scene> FileReader::readScene(const std::string& path, NormalizationParameters& parameters) {
    FacadeOperationResult res;
    if (path != "") {
        std::vector <std::vector<float>> data = getDataFromFile(path);


        if (data.size() != data[0].size()) {
            res.setErrorMessage("Incorrect file!");
            throw res.getErrorMessage();
        }

        if (parameters.getMax() <= parameters.getMin()) {
            res.setErrorMessage("Max should be greater then Min");
            throw res.getErrorMessage();
        }

        if (parameters.getDxStep() <= 0 && parameters.getDyStep() <= 0) {
            res.setErrorMessage("Steps by X and Y couldn't be <= 0");
            throw res.getErrorMessage();
        }

        if (parameters.getDxStep() <= 0) {
            res.setErrorMessage("Step by X can't be <= 0");
            throw res.getErrorMessage();
        }

        if (parameters.getDyStep() <= 0) {
            res.setErrorMessage("Step by Y can't be <= 0");
            throw res.getErrorMessage();
        }

        data = normalize(data, parameters);
        std::vector<Vertex>* vertices = makeVertices(data, parameters);
        std::vector<Edge>* edges = makeEdge(*vertices, data.size(), data[0].size());
        std::unique_ptr<Figure> figure = std::make_unique<Figure>(vertices, edges);
        std::vector<Figure> figures;

        figures.push_back(*figure);
        std::shared_ptr<Scene> scene = std::make_shared<Scene>(figures);

        return scene;

    } else return nullptr;
}
