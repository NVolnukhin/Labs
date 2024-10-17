#include "facade_operation_result.h"

FacadeOperationResult::FacadeOperationResult() : _errorMessage(""), _isSuccess(true) {}

std::string FacadeOperationResult::getErrorMessage() const {
    return _errorMessage;
}

bool FacadeOperationResult::isSuccess() const {
    return _isSuccess;
}

void FacadeOperationResult::setErrorMessage(const std::string& msg) {
    _errorMessage = msg;
    if (_errorMessage != "") {
        _isSuccess = false;
    }
    else {
        _isSuccess = true;
    }
}
