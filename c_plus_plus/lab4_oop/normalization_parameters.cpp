#include "normalization_parameters.h"

NormalizationParameters::NormalizationParameters(const float max, const float min, const float dx, const float dy) {
    this->min = min;
    this->max = max;
    this->dxStep = dx;
    this->dyStep = dy;
}


double NormalizationParameters::getMin() {
    return min;
}


double NormalizationParameters::getMax() {
    return max;
}


double NormalizationParameters::getDxStep() {
    return dxStep;
}


double NormalizationParameters::getDyStep() {
    return dyStep;
}
