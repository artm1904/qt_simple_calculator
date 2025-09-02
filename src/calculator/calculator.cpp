#include "calculator.h"

Calculator::Calculator() {}

int Calculator::Reset() {
    value1 = 0;
    value2 = 0;
    oper = CalculatorOperations::EMPTY;
    result = 0;
    return 0;
}

int Calculator::Digit(int d) {
    if (oper == CalculatorOperations::EMPTY) {
        value1 = value1 * 10 + d;
        result = value1;
    } else {
        value2 = value2 * 10 + d;
        result = value2;
    }
    return 0;
}

int Calculator::Operation(Calculator::CalculatorOperations operation) {
    oper = operation;
    return 0;
}

int Calculator::Calculate() {
    switch (oper) {
        case CalculatorOperations::ADDITION:
            result = value1 + value2;
            break;
        case CalculatorOperations::SUBSTRACTION:
            result = value1 - value2;
            break;
        case CalculatorOperations::MULTIPLAY:
            result = value1 * value2;
            break;
        case CalculatorOperations::DIVISION:
            result = value1 / value2;
            break;
    }
    return 0;
}

QString Calculator::GetDisplayText() { return QString::number(result); }
