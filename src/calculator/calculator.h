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
    void AddDecimalPoint();
    int ApplyUnaryOperation(const QString& operation);
    int Operation(CalculatorOperations operation);
    int Calculate();
    QString GetDisplayText();

   private:
    double m_value1;
    double m_value2;
    double m_result;
    CalculatorOperations m_oper;
    bool m_isDecimalPart;
    double m_decimalPlace;
};

#endif  // CALCULATOR_H
