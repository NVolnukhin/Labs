#ifndef FACADE_OPERATION_RESULT_H
#define FACADE_OPERATION_RESULT_H

#include <string>


class FacadeOperationResult {
public:
    FacadeOperationResult();
    std::string getErrorMessage() const;
    bool isSuccess() const;
    void setErrorMessage(const std::string& msg);

private:
    std::string _errorMessage;
    bool _isSuccess;
};

#endif // FACADE_OPERATION_RESULT_H
