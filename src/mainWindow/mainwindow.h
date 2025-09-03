#pragma once

#include <QMainWindow>
#include <QMap>

#include "../calculator/calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   private slots:
    void DigitButtonPressed();
    void OperationButtonPressed();
    void UnaryOperationPressed();

   private:
    Ui::MainWindow *ui;
    Calculator calc;
    const QMap<QString, QString> m_unaryOperations = {
        {"but_sqrt", "sqrt"}, {"but_x2", "x^2"}, {"but_percent", "%"}};
};

