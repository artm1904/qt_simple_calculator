
#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    calc.Reset();

    connect(ui->but_0, &QPushButton::clicked, this, &MainWindow::DigitButtonPressed);
    connect(ui->but_1, &QPushButton::clicked, this, &MainWindow::DigitButtonPressed);
    connect(ui->but_2, &QPushButton::clicked, this, &MainWindow::DigitButtonPressed);
    connect(ui->but_3, &QPushButton::clicked, this, &MainWindow::DigitButtonPressed);
    connect(ui->but_4, &QPushButton::clicked, this, &MainWindow::DigitButtonPressed);
    connect(ui->but_5, &QPushButton::clicked, this, &MainWindow::DigitButtonPressed);
    connect(ui->but_6, &QPushButton::clicked, this, &MainWindow::DigitButtonPressed);
    connect(ui->but_7, &QPushButton::clicked, this, &MainWindow::DigitButtonPressed);
    connect(ui->but_8, &QPushButton::clicked, this, &MainWindow::DigitButtonPressed);
    connect(ui->but_9, &QPushButton::clicked, this, &MainWindow::DigitButtonPressed);

    connect(ui->but_a, &QPushButton::clicked, this, &MainWindow::OperationButtonPressed);
    connect(ui->but_s, &QPushButton::clicked, this, &MainWindow::OperationButtonPressed);
    connect(ui->but_m, &QPushButton::clicked, this, &MainWindow::OperationButtonPressed);
    connect(ui->but_d, &QPushButton::clicked, this, &MainWindow::OperationButtonPressed);

    connect(ui->but_e, &QPushButton::clicked, this, [this]() {
        if (calc.Calculate() != 0) {
            ui->screen->setText("Error");
        } else {
            ui->screen->setText(calc.GetDisplayText());
        }
    });

    connect(ui->but_c, &QPushButton::clicked, this, [this]() {
        calc.Reset();
        ui->screen->setText(calc.GetDisplayText());
    });

    connect(ui->but_dot, &QPushButton::clicked, this, [this]() { calc.AddDecimalPoint(); });

    connect(ui->but_sqrt, &QPushButton::clicked, this, &MainWindow::UnaryOperationPressed);
    connect(ui->but_x2, &QPushButton::clicked, this, &MainWindow::UnaryOperationPressed);
    connect(ui->but_percent, &QPushButton::clicked, this, &MainWindow::UnaryOperationPressed);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::DigitButtonPressed() {
    QObject *buttonObject = sender();
    QPushButton *button = qobject_cast<QPushButton *>(buttonObject);

    if (button) {
        bool ok;
        int digitValue = button->text().toInt(&ok);

        if (ok) {
            calc.Digit(digitValue);
            ui->screen->setText(calc.GetDisplayText());
        }
    }
}

void MainWindow::OperationButtonPressed() {
    QObject *buttonObject = sender();
    QPushButton *button = qobject_cast<QPushButton *>(buttonObject);

    if (button) {
        QString opText = button->text();
        Calculator::CalculatorOperations op = Calculator::CalculatorOperations::EMPTY;

        if (opText == "+") {
            op = Calculator::CalculatorOperations::ADDITION;
        } else if (opText == "-") {
            op = Calculator::CalculatorOperations::SUBSTRACTION;
        } else if (opText == "*") {
            op = Calculator::CalculatorOperations::MULTIPLAY;
        } else if (opText == "/") {
            op = Calculator::CalculatorOperations::DIVISION;
        }
        calc.Operation(op);
    }
}

void MainWindow::UnaryOperationPressed() {
    QObject *buttonObject = sender();
    QPushButton *button = qobject_cast<QPushButton *>(buttonObject);

    if (button) {
        QString operationSymbol;

        QString buttonName = button->objectName();

        if (buttonName == "but_sqrt") {
            operationSymbol = "sqrt";
        } else if (buttonName == "but_x2") {
            operationSymbol = "x^2";
        } else if (buttonName == "but_percent") {
            operationSymbol = "%";
        }

        if (!operationSymbol.isEmpty()) {
            if (calc.ApplyUnaryOperation(operationSymbol) != 0) {
                ui->screen->setText("Error");
            } else {
                ui->screen->setText(calc.GetDisplayText());
            }
        }
    }
}
