
#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    calc.Reset();

    // Группируем кнопки с цифрами и подключаем их в цикле
    const QList<QPushButton *> digitButtons = {ui->but_0, ui->but_1, ui->but_2, ui->but_3,
                                               ui->but_4, ui->but_5, ui->but_6, ui->but_7,
                                               ui->but_8, ui->but_9};

    // Группируем кнопки бинарных операций
    const QList<QPushButton *> operationButtons = {ui->but_a, ui->but_s, ui->but_m, ui->but_d};

    // Группируем кнопки унарных операций
    const QList<QPushButton *> unaryOperationButtons = {ui->but_sqrt, ui->but_x2, ui->but_percent};

    for (QPushButton *button : digitButtons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::DigitButtonPressed);
    }

    for (QPushButton *button : operationButtons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::OperationButtonPressed);
    }

    for (QPushButton *button : unaryOperationButtons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::UnaryOperationPressed);
    }

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

        if (calc.GetOperations()->contains(opText)) {
            calc.Operation(calc.GetOperations()->value(opText));
        }
        ui->screen->setText(calc.GetDisplayText());
    }
}

void MainWindow::UnaryOperationPressed() {
    QObject *buttonObject = sender();
    QPushButton *button = qobject_cast<QPushButton *>(buttonObject);

    if (button) {
        QString operationSymbol = m_unaryOperations.value(button->objectName());
        QString buttonName = button->objectName();

        if (!operationSymbol.isEmpty()) {
            if (calc.ApplyUnaryOperation(operationSymbol) != 0) {
                ui->screen->setText("Error");
            } else {
                ui->screen->setText(calc.GetDisplayText());
            }
        }
    }
}
