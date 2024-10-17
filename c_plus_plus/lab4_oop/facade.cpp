#include "facade.h"

Facade::Facade() {
    _fileReader = std::make_shared<FileReader>();
    _scene = std::make_shared<Scene>();
    _sceneIsLoaded = false;
}


FacadeOperationResult Facade::loadScene(const std::string& path, NormalizationParameters& parameters) {
    FacadeOperationResult result;
    try {
        _scene = _fileReader->readScene(path, parameters);
    } catch (const char* err) {
        throw err;
    }

    _sceneIsLoaded = true;

    if (_scene == nullptr) {
        throw "Scene was not drew!";
    }

    return result;
}

FacadeOperationResult Facade::moveScene(const float x, const float y, const float z) {
    FacadeOperationResult result;
    TransformMatrix matrix = TransformMatrixBuilder::createMoveMatrix(x, y, z);
    _scene->transformFigures(matrix);

    return result;
}

FacadeOperationResult Facade::rotateScene(const float x, const float y, const float z) {
    FacadeOperationResult result;
    TransformMatrix matrix;

    if (x != 0) {
        matrix = TransformMatrixBuilder::createRotationMatrixX(x);
        _scene->transformFigures(matrix);
    }
    if (y != 0) {
        matrix = TransformMatrixBuilder::createRotationMatrixY(y);
        _scene->transformFigures(matrix);
    }
    if (z != 0) {
        matrix = TransformMatrixBuilder::createRotationMatrixZ(z);
        _scene->transformFigures(matrix);
    }


    return result;
}

FacadeOperationResult Facade::scaleScene(const float x, const float y, const float z) {
    FacadeOperationResult result;
    if (x <= 0 || y <= 0 || z <= 0) {
        result.setErrorMessage("Scale should be > 0");
    }

    TransformMatrix matrix = TransformMatrixBuilder::createScaleMatrix(x, y, z);
    _scene->transformFigures(matrix);

    return result;
}


std::shared_ptr<Scene> Facade::getScene() {
    return _scene;
}


bool Facade::isSceneIsLoaded() {
    return _sceneIsLoaded;
}


void Facade::clearScene() {
    _scene.reset();
    _sceneIsLoaded = false;
}
