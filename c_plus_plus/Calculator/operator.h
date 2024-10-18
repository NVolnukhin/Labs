#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>

class Operator {
public:
    enum class OperatorPriority {
        LOW = 1,
        MID,
        HIGH,
    };

    enum class Associativity {
        LEFT,
        RIGHT
    };

    Operator(const std::string& name, OperatorPriority priority, double (*func)(double, double), Associativity assoc = Associativity::LEFT):
        _assoc(assoc), _name(name), _priority(priority), _func(func) {};
    Operator() {};

    virtual std::string getName() const;
    virtual OperatorPriority getPriority();
    virtual Associativity getAssociativity();
    virtual double evaluate(double a, double b);

    virtual ~Operator() {};

private:
    Associativity _assoc = Associativity::LEFT;

    const std::string _name;
    OperatorPriority _priority = OperatorPriority::LOW;
    double (*_func)(double, double);
};

#endif // OPERATOR_H
