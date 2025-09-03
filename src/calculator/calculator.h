#pragma once

#include <QMap>
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
    QString GetOperationSymbol();
    QMap<QString, CalculatorOperations>* GetOperations();

   private:
    double m_value1;
    double m_value2;
    double m_result;
    QString m_displayString;
    bool m_isDecimalPart;
    double m_decimalPlace;
    bool m_calculationDone;
    QMap<QString, CalculatorOperations> m_operations;

   public:
    CalculatorOperations oper;
};
