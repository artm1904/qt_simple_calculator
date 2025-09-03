#include "calculator.h"

Calculator::Calculator() {}

int Calculator::Reset() {
    m_value1 = 0.0;
    m_value2 = 0.0;
    m_oper = CalculatorOperations::EMPTY;
    m_result = 0.0;
    m_isDecimalPart = false;
    m_decimalPlace = 0.1;
    return 0;
}

int Calculator::Digit(int d) {
    if (m_oper == CalculatorOperations::EMPTY) {
        if (!m_isDecimalPart) {
            m_value1 = m_value1 * 10 + d;
        } else {
            m_value1 = m_value1 + d * m_decimalPlace;
            m_decimalPlace *= 0.1;
        }
        m_result = m_value1;
    } else {
        if (!m_isDecimalPart) {
            m_value2 = m_value2 * 10 + d;
        } else {
            m_value2 = m_value2 + d * m_decimalPlace;
            m_decimalPlace *= 0.1;
        }
        m_result = m_value2;
    }
    return 0;
}

void Calculator::AddDecimalPoint() {
    m_isDecimalPart = true;
    m_decimalPlace = 0.1;
}

int Calculator::ApplyUnaryOperation(const QString& operation) {
    double currentValue = m_result;

    if (operation == "sqrt") {
        if (currentValue < 0) {
            return -1;
        }
        m_result = std::sqrt(currentValue);
    } else

        if (operation == "x^2") {
        m_result = currentValue * currentValue;
    } else

        if (operation == "%") {
        m_result = currentValue / 100.0;
    } else {
        return -1;
    }

    if (m_oper == CalculatorOperations::EMPTY) {
        m_value1 = m_result;
    } else {
        m_value2 = m_result;
    }

    return 0;
}

int Calculator::Operation(Calculator::CalculatorOperations operation) {
    m_isDecimalPart = false;
    m_decimalPlace = 0.1;
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
            if (m_value2 == 0.0) {
                return -1;
            }
            m_result = m_value1 / m_value2;
            break;
    }

    m_value1 = m_result;
    m_value2 = 0.0;
    return 0;
}

QString Calculator::GetDisplayText() { return QString::number(m_result); }
