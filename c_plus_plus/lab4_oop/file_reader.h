#ifndef FILE_READER_H
#define FILE_READER_H
#include "base_file_reader.h"
#include "normalization_parameters.h"
#include "iostream"
#include "facade_operation_result.h"
#include "fstream"
#include "vector"

class FileReader : public BaseFileReader {
private:
    float getMinZ(const std::vector<std::vector<float>>& data);
    float getMaxZ(const std::vector<std::vector<float>>& data);
    std::vector<std::vector<float>> normalize(std::vector<std::vector<float>>& data, NormalizationParameters& parameters);
    std::vector<std::vector<float>> getDataFromFile(const std::string& path);
    std::vector<Vertex>* makeVertices(std::vector<std::vector<float>>& data, NormalizationParameters params);
    std::vector<Edge>* makeEdge(std::vector<Vertex>& vertices, size_t length, size_t width);

public:
    std::shared_ptr<Scene> readScene(const std::string& path, NormalizationParameters& parameters) override;
};

#endif // FILE_READER_H
