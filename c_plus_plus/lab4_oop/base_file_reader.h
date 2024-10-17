#ifndef BASE_FILE_READER_H
#define BASE_FILE_READER_H

#include "scene.h"
#include "normalization_parameters.h"


class BaseFileReader {
public:
    virtual std::shared_ptr<Scene> readScene(const std::string& path, NormalizationParameters& parameters) = 0;
    virtual ~BaseFileReader() {};
};

#endif // BASE_FILE_READER_H
