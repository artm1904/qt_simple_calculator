#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
};

#endif  // MAINWINDOW_H
