#include "calculator.h"

Calculator::Calculator() {
    m_operations = {
        {"+", CalculatorOperations::ADDITION},
        {"-", CalculatorOperations::SUBSTRACTION},
        {"*", CalculatorOperations::MULTIPLAY},
        {"/", CalculatorOperations::DIVISION},
    };
}

int Calculator::Reset() {
    m_value1 = 0.0;
    m_value2 = 0.0;
    oper = CalculatorOperations::EMPTY;
    m_result = 0.0;
    m_isDecimalPart = false;
    m_calculationDone = false;
    m_decimalPlace = 0.1;
    m_displayString.clear();
    return 0;
}

int Calculator::Digit(int d) {
    if (m_calculationDone) {
        Reset();
    }

    if (oper == CalculatorOperations::EMPTY) {
        if (!m_isDecimalPart) {
            m_value1 = m_value1 * 10 + d;
        } else {
            m_value1 = m_value1 + d * m_decimalPlace;
            m_decimalPlace *= 0.1;
        }
    } else {
        if (!m_isDecimalPart) {
            m_value2 = m_value2 * 10 + d;
        } else {
            m_value2 = m_value2 + d * m_decimalPlace;
            m_decimalPlace *= 0.1;
        }
    }
    m_displayString.append(QString::number(d));
    return 0;
}

void Calculator::AddDecimalPoint() {
    if (!m_isDecimalPart) {
        if (m_calculationDone) {
            Reset();
        }
        m_isDecimalPart = true;
        m_decimalPlace = 0.1;
        m_displayString.append(".");
    }
}

int Calculator::ApplyUnaryOperation(const QString& operation) {
    double currentValue;
    if (oper == CalculatorOperations::EMPTY) {
        currentValue = m_value1;
    } else {
        currentValue = m_value2;

    }

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

    //Обновляем значение и пересобираем строку для отображения
    if (oper == CalculatorOperations::EMPTY) {
        m_value1 = m_result;
         m_displayString = QString::number(m_value1);
    } else {
        m_value2 = m_result;
        int lastSpace = m_displayString.lastIndexOf(' ');
        if (lastSpace != -1) {
            m_displayString.truncate(lastSpace + 1);
        }
        m_displayString.append(QString::number(m_value2));
    }


    return 0;
}

int Calculator::Operation(Calculator::CalculatorOperations operation) {
    if (oper != CalculatorOperations::EMPTY && !m_calculationDone) {
        Calculate();
    }

    m_calculationDone = false;
    m_isDecimalPart = false;

    m_decimalPlace = 0.1;
    oper = operation;
    m_displayString.append(" " + GetOperationSymbol() + " ");
    return 0;
}

int Calculator::Calculate() {
    switch (oper) {
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
    m_displayString.append(" = " + QString::number(m_result));
    m_calculationDone = true;
    return 0;
}

QString Calculator::GetDisplayText() {
    if (m_displayString.isEmpty()) {
        return "0";
    }
    return m_displayString;
}

QString Calculator::GetOperationSymbol() { return m_operations.key(oper); }

QMap<QString, Calculator::CalculatorOperations>* Calculator::GetOperations() {
    return &m_operations;
}
