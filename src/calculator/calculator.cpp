#include "calculator.h"

Calculator::Calculator() {}

int Calculator::Reset() {
    m_value1 = 0;
    m_value2 = 0;
    m_oper = CalculatorOperations::EMPTY;
    m_result = 0;
    m_isDecimalPart = false;
    m_decimalPlace = 0.1;
    return 0;
}

int Calculator::Digit(int d) {
    if (m_oper == CalculatorOperations::EMPTY) {
        if (m_isDecimalPart == false) {
            m_value1 = m_value1 * 10 + d;
            m_result = m_value1;
        } else {
            m_value1 = m_value1 + d * m_decimalPlace;
            m_decimalPlace++;
            m_result = m_value1;
        }
    } else {
        if (m_isDecimalPart == false) {
            m_value2 = m_value2 * 10 + d;
            m_result = m_value2;
        } else {
            m_value2 = m_value2 + d * m_decimalPlace;
            m_decimalPlace++;
            m_result = m_value2;
        }
    }
    return 0;
}

void Calculator::AddDecimalPoint() { m_isDecimalPart = true; }

int Calculator::Operation(Calculator::CalculatorOperations operation) {
    m_oper = operation;
    return 0;
}

int Calculator::Calculate() {
    switch (m_oper) {
        case CalculatorOperations::ADDITION:
            m_result = m_value1 + m_value2;
            break;
        case CalculatorOperations::SUBSTRACTION:
            m_result = m_value1 - m_value2;
            break;
        case CalculatorOperations::MULTIPLAY:
            m_result = m_value1 * m_value2;
            break;
        case CalculatorOperations::DIVISION:
            m_result = m_value1 / m_value2;
            break;
    }
    return 0;
}

QString Calculator::GetDisplayText() { return QString::number(m_result); }
