#ifndef NORMALIZATION_PARAMETERS_H
#define NORMALIZATION_PARAMETERS_H

class NormalizationParameters {
public:
    NormalizationParameters(const float max, const float min, const float dx, const float dy);
    double getMin();
    double getMax();
    double getDxStep();
    double getDyStep();

private:
    double min;
    double max;
    double dxStep;
    double dyStep;
};

#endif // NORMALIZATION_PARAMETERS_H
