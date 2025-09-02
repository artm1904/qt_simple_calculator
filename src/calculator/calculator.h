#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QString>

class Calculator {
   public:
    enum class CalculatorOperations {
        EMPTY,
        ADDITION,
        SUBSTRACTION,
        MULTIPLAY,
        DIVISION

    };
    Calculator();

    int Reset();
    int Digit(int d);
    int Operation(CalculatorOperations operation);
    int Calculate();
    QString GetDisplayText();

   private:
    double value1;
    double value2;
    double result;
    CalculatorOperations oper;
};

#endif  // CALCULATOR_H
