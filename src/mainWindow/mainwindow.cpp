
#include "mainwindow.h"

#include "ui_mainwindow.h"

Calculator calc;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    calc.Reset();

    connect(ui->but_0, &QPushButton::clicked, this, &MainWindow::digitButtonPressed);
    connect(ui->but_1, &QPushButton::clicked, this, &MainWindow::digitButtonPressed);
    connect(ui->but_2, &QPushButton::clicked, this, &MainWindow::digitButtonPressed);
    connect(ui->but_3, &QPushButton::clicked, this, &MainWindow::digitButtonPressed);
    connect(ui->but_4, &QPushButton::clicked, this, &MainWindow::digitButtonPressed);
    connect(ui->but_5, &QPushButton::clicked, this, &MainWindow::digitButtonPressed);
    connect(ui->but_6, &QPushButton::clicked, this, &MainWindow::digitButtonPressed);
    connect(ui->but_7, &QPushButton::clicked, this, &MainWindow::digitButtonPressed);
    connect(ui->but_8, &QPushButton::clicked, this, &MainWindow::digitButtonPressed);
    connect(ui->but_9, &QPushButton::clicked, this, &MainWindow::digitButtonPressed);

    connect(ui->but_a, &QPushButton::clicked, this, &MainWindow::operationButtonPressed);
    connect(ui->but_s, &QPushButton::clicked, this, &MainWindow::operationButtonPressed);
    connect(ui->but_m, &QPushButton::clicked, this, &MainWindow::operationButtonPressed);
    connect(ui->but_d, &QPushButton::clicked, this, &MainWindow::operationButtonPressed);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digitButtonPressed() {
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

void MainWindow::operationButtonPressed() {
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

void MainWindow::on_but_c_clicked() {
    calc.Reset();
    ui->screen->setText(calc.GetDisplayText());
}

void MainWindow::on_but_e_clicked() {
    calc.Calculate();
    ui->screen->setText(calc.GetDisplayText());
}
