#include "mainwindow.h"
#include "command_factory.h"
#include "ui_mainwindow.h"

#include <iostream>

#include <facade.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::connectUI() {
    connect(ui->pushButton0, &QPushButton::clicked, this, &MainWindow::onPushButton0Clicked);
    connect(ui->pushButton1, &QPushButton::clicked, this, &MainWindow::onPushButton1Clicked);
    connect(ui->pushButton2, &QPushButton::clicked, this, &MainWindow::onPushButton2Clicked);
    connect(ui->pushButton3, &QPushButton::clicked, this, &MainWindow::onPushButton3Clicked);
    connect(ui->pushButton4, &QPushButton::clicked, this, &MainWindow::onPushButton4Clicked);
    connect(ui->pushButton5, &QPushButton::clicked, this, &MainWindow::onPushButton5Clicked);
    connect(ui->pushButton6, &QPushButton::clicked, this, &MainWindow::onPushButton6Clicked);
    connect(ui->pushButton7, &QPushButton::clicked, this, &MainWindow::onPushButton7Clicked);
    connect(ui->pushButton8, &QPushButton::clicked, this, &MainWindow::onPushButton8Clicked);
    connect(ui->pushButton9, &QPushButton::clicked, this, &MainWindow::onPushButton9Clicked);

    connect(ui->pushButtonBracketOpen, &QPushButton::clicked, this, &MainWindow::onPushButtonBracketOpenClicked);
    connect(ui->pushButtonBracketClose, &QPushButton::clicked, this, &MainWindow::onPushButtonBracketCloseClicked);

    connect(ui->pushButtonDot, &QPushButton::clicked, this, &MainWindow::onPushButtonDotClicked);

    connect(ui->pushButtonSin, &QPushButton::clicked, this, &MainWindow::onPushButtonSinClicked);
    connect(ui->pushButtonCos, &QPushButton::clicked, this, &MainWindow::onPushButtonCosClicked);
    connect(ui->pushButtonTg, &QPushButton::clicked, this, &MainWindow::onPushButtonTgClicked);
    connect(ui->pushButtonCtg, &QPushButton::clicked, this, &MainWindow::onPushButtonCtgClicked);
    connect(ui->pushButtonInverse, &QPushButton::clicked, this, &MainWindow::onPushButtonInverseClicked);
    connect(ui->pushButtonSqrt, &QPushButton::clicked, this, &MainWindow::onPushButtonSqrtClicked);

    connect(ui->pushButtonDiv, &QPushButton::clicked, this, &MainWindow::onPushButtonDivClicked);
    connect(ui->pushButtonMul, &QPushButton::clicked, this, &MainWindow::onPushButtonMulClicked);
    connect(ui->pushButtonMinus, &QPushButton::clicked, this, &MainWindow::onPushButtonMinusClicked);
    connect(ui->pushButtonPlus, &QPushButton::clicked, this, &MainWindow::onPushButtonPlusClicked);
    connect(ui->pushButtonPow, &QPushButton::clicked, this, &MainWindow::onPushButtonPowClicked);

    connect(ui->pushButtonC, &QPushButton::clicked, this, &MainWindow::onPushButtonCClicked);
    connect(ui->pushButtonDel, &QPushButton::clicked, this, &MainWindow::onPushButtonDelClicked);

    connect(ui->pushButtonCalculate, &QPushButton::clicked, this, &MainWindow::onPushButtonCalculateClicked);
}


void MainWindow::onPushButton0Clicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('0'));
    resetResultOnDisplay();
}


void MainWindow::onPushButton1Clicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('1'));
    resetResultOnDisplay();
}


void MainWindow::onPushButton2Clicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('2'));
    resetResultOnDisplay();
}


void MainWindow::onPushButton3Clicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('3'));
    resetResultOnDisplay();
}


void MainWindow::onPushButton4Clicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('4'));
    resetResultOnDisplay();
}


void MainWindow::onPushButton5Clicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('5'));
    resetResultOnDisplay();
}


void MainWindow::onPushButton6Clicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('6'));
    resetResultOnDisplay();
}


void MainWindow::onPushButton7Clicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('7'));
    resetResultOnDisplay();
}


void MainWindow::onPushButton8Clicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('8'));
    resetResultOnDisplay();
}


void MainWindow::onPushButton9Clicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('9'));
    resetResultOnDisplay();
}


void MainWindow::onPushButtonBracketOpenClicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('('));
    resetResultOnDisplay();
}


void MainWindow::onPushButtonBracketCloseClicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append(')'));
    resetResultOnDisplay();
}


void MainWindow::onPushButtonSqrtClicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append("sqrt("));
    resetResultOnDisplay();
}


void MainWindow::onPushButtonCClicked() {
    ui->lineEditEx->setText("");
    resetResultOnDisplay();
}


void MainWindow::onPushButtonDelClicked() {
    if (resultOnDisplay) {
        ui->lineEditEx->setText("");
        return;
    }

    QString currentInput = ui->lineEditEx->text();
    if (currentInput.size() == 1) {
        ui->lineEditEx->setText("");
    } else {
        ui->lineEditEx->setText(currentInput.mid(0, currentInput.size() - 1));
    }
}


void MainWindow::onPushButtonInverseClicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append("^(-1)"));
    resetResultOnDisplay();
}


void MainWindow::onPushButtonDivClicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('/'));
    resetResultOnDisplay();
}


void MainWindow::onPushButtonSinClicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append("sin("));
    resetResultOnDisplay();
}


void MainWindow::onPushButtonMulClicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('*'));
    resetResultOnDisplay();
}


void MainWindow::onPushButtonCosClicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append("cos("));
    resetResultOnDisplay();
}


void MainWindow::onPushButtonMinusClicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('-'));
    resetResultOnDisplay();
}


void MainWindow::onPushButtonTgClicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append("tg("));
    resetResultOnDisplay();
}


void MainWindow::onPushButtonDotClicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('.'));
    resetResultOnDisplay();
}


void MainWindow::onPushButtonPlusClicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append('+'));
    resetResultOnDisplay();
}


void MainWindow::onPushButtonCtgClicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append("ctg("));
    resetResultOnDisplay();
}


void MainWindow::onPushButtonPowClicked() {
    ui->lineEditEx->setText(ui->lineEditEx->text().append("^"));
    resetResultOnDisplay();
}


void MainWindow::onPushButtonCalculateClicked() {  //Cmd
    auto expr = ui->lineEditEx->text().toStdString();
    auto cmd = CommandFactory<SimpleCalculator>::createCalculateCommand(expr);
    facade.executeCommand(cmd);
    ui->lineEditEx->setText(QString::fromStdString(facade.getResult().getAns()));
    resultOnDisplay = true;
}


void MainWindow::resetResultOnDisplay() {
    resultOnDisplay = false;
}




