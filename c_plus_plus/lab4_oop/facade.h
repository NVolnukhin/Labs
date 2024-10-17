#ifndef FACADE_H
#define FACADE_H

#include <memory>
#include "base_file_reader.h"
#include "file_reader.h"
#include "facade_operation_result.h"
#include "normalization_parameters.h"
#include "transform_matrix_builder.h"

class Facade {
public:
    Facade();
    FacadeOperationResult loadScene(const std::string& path, NormalizationParameters& parameters);
    FacadeOperationResult moveScene(const float x, const float y, const float z);
    FacadeOperationResult rotateScene(const float x, const float y, const float z);
    FacadeOperationResult scaleScene(const float x, const float y, const float z);
    std::shared_ptr<Scene> getScene();
    bool isSceneIsLoaded();
    void clearScene();

private:
    std::shared_ptr<BaseFileReader> _fileReader;
    std::shared_ptr<Scene> _scene;
    bool _sceneIsLoaded;
};

#endif // FACADE_H
