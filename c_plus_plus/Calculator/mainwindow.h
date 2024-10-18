#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "simple_calculator.h"
#include "facade.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onPushButtonSqrtClicked();
    void onPushButtonCClicked();
    void onPushButtonBracketOpenClicked();
    void onPushButtonBracketCloseClicked();
    void onPushButtonDelClicked();
    void onPushButtonInverseClicked();
    void onPushButton7Clicked();
    void onPushButton8Clicked();
    void onPushButton9Clicked();
    void onPushButtonDivClicked();
    void onPushButtonSinClicked();
    void onPushButton4Clicked();
    void onPushButton5Clicked();
    void onPushButton6Clicked();
    void onPushButtonMulClicked();
    void onPushButtonCosClicked();
    void onPushButton1Clicked();
    void onPushButton2Clicked();
    void onPushButton3Clicked();
    void onPushButtonMinusClicked();
    void onPushButtonTgClicked();
    void onPushButton0Clicked();
    void onPushButtonDotClicked();
    void onPushButtonPlusClicked();
    void onPushButtonCtgClicked();
    void onPushButtonPowClicked();
    void onPushButtonCalculateClicked();

    void resetResultOnDisplay();

private:
    bool resultOnDisplay = false;
    Ui::MainWindow *ui;
    Facade<SimpleCalculator> facade;

    void connectUI();
};
#endif // MAINWINDOW_H
