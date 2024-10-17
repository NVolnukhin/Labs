#include "mainwindow.h"
#include "qt_scene_drawer.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUI();
    facade = new Facade();
    _pixmap.setBoundingRect(QRect(QPoint(INT_ZERO, INT_ZERO), QPoint(ui->lbl_graphicsView->width(), ui->lbl_graphicsView->height())));
    drawer = QtSceneDrawer(_pixmap);
}


MainWindow::~MainWindow() {
    delete facade;
    delete ui;
}


void MainWindow::setUI() {
    connectUI();
    setLineEditSettings();
}


void MainWindow::setLineEditSettings() {
    ui->leMoveX->setMaxLength(MAX_LEN);
    ui->leMoveY->setMaxLength(MAX_LEN);
    ui->leMoveZ->setMaxLength(MAX_LEN);
    ui->leRotateX->setMaxLength(MAX_LEN);
    ui->leRotateY->setMaxLength(MAX_LEN);
    ui->leRotateZ->setMaxLength(MAX_LEN);
    ui->leRangeFrom->setMaxLength(MAX_LEN);
    ui->leRangeTo->setMaxLength(MAX_LEN);
    ui->leStepX->setMaxLength(MAX_LEN);
    ui->leStepY->setMaxLength(MAX_LEN);
}


void MainWindow::showWarning() {
    QMessageBox::warning(this, "Warning", "Input Normaliztion Parameters before loading file");
}

void MainWindow::showScaleWarning() {
    QMessageBox::warning(this, "Warning", "After every scaling current value will be set to 100%.\n"
                                           "If you wnat to downscale, enter value between 0 and 100%.\n"
                                           "If you wnat to upscale, enter value more then 100%.");
}


void MainWindow::connectUI() {
    connect(ui->btn_open_file, &QPushButton::clicked, this, &MainWindow::onOpenFileClicked);
    connect(ui->btn_apply, &QPushButton::clicked, this, &MainWindow::onApplyClicked);
}


void MainWindow::clearGraph() {
    ui->lbl_graphicsView->setVisible(false);
}


void MainWindow::setDefaultValues() {
    ui->leRotateX->setText(ZERO);
    ui->leRotateY->setText(ZERO);
    ui->leRotateZ->setText(ZERO);
    ui->leMoveX->setText(ZERO);
    ui->leMoveY->setText(ZERO);
    ui->leMoveZ->setText(ZERO);
    ui->leScale->setText(DEFAULT_SCALE);
}


void MainWindow::onApplyClicked() {
    bool okX, okY, okZ = true;
    FacadeOperationResult res;

    if (!facade->isSceneIsLoaded()) {
        QMessageBox::critical(this, "Error", "File is not loaded");
        return;
    }

    ////------------------------- ROTATING -------------------------
    res = facade->rotateScene(ui->leRotateX->text().toFloat(&okX), ui->leRotateY->text().toFloat(&okY), ui->leRotateZ->text().toFloat(&okZ));

    if (!okX || !okY || !okZ) {
        std::string error = "Enter good floats in Rotating Parameters";
        const char* err = error.c_str();
        QMessageBox::critical(this, "Error", err);
        return;
    }

    if (!res.isSuccess()) {
        std::string error = res.getErrorMessage();
        const char* err = error.c_str();
        QMessageBox::critical(this, "Error", err);
        return;
    }


    ////------------------------- MOVING -------------------------
    res = facade->moveScene(ui->leMoveX->text().toFloat(&okX), ui->leMoveY->text().toFloat(&okY), ui->leMoveZ->text().toFloat(&okZ));

    if (!okX || !okY || !okZ) {
        std::string error = "Enter good floats in Moving Parameters";
        const char* err = error.c_str();
        QMessageBox::critical(this, "Error", err);
        return;
    }

    if (!res.isSuccess()) {
        std::string error = res.getErrorMessage();
        const char* err = error.c_str();
        QMessageBox::critical(this, "Error", err);
        return;
    }


    ////------------------------- SCALING -------------------------

    res = facade->scaleScene(ui->leScale->text().toFloat(&okX), ui->leScale->text().toFloat(), ui->leScale->text().toFloat());

    if (!okX) {
        QMessageBox::critical(this, "Error", "Enter good float in Scaling Parameters");
        return;
    }

    if (!res.isSuccess()) {
        std::string error = res.getErrorMessage();
        const char* err = error.c_str();
        QMessageBox::critical(this, "Error", err);
        return;
    }


    ////------------------------- DRAWING -------------------------
    try {
        drawer.drawScene(facade->getScene());
        ui->lbl_graphicsView->setPicture(_pixmap);
        ui->lbl_graphicsView->setVisible(true);
    } catch (const char* err) {
        QMessageBox::critical(this, "Error", err);
    }
}


void MainWindow::onOpenFileClicked() {
    clearGraph();
    showWarning();
    setDefaultValues();

    bool okRangeFrom, okRangeTo, okStepX, okStepY = true;
    QString path = (QFileDialog::getOpenFileName(this, tr("Open File"), "/Users/nikitavolnuhin/Downloads", "*.csv"));
    std::string stdPath = path.toStdString();
    NormalizationParameters params = NormalizationParameters(ui->leRangeTo->text().toFloat(&okRangeTo), ui->leRangeFrom->text().toFloat(&okRangeFrom), ui->leStepX->text().toFloat(&okStepX), ui->leStepY->text().toFloat(&okStepY));

    if (!okRangeFrom) {
        QMessageBox::critical(this, "Error", "Normaliztion params error: Incorrect range 'From'");
        facade->clearScene();
        return;
    }

    if (!okRangeTo) {
        QMessageBox::critical(this, "Error", "Normaliztion params error: Incorrect range 'To'");
        facade->clearScene();
        return;
    }

    if (params.getMax() <= params.getMin()) {
        QMessageBox::critical(this, "Error", "Normaliztion params error: 'From' should be less then 'To'");
        facade->clearScene();
        return;
    }

    if (!okStepX) {
        QMessageBox::critical(this, "Error", "Normaliztion params error: Incorrect 'Step by X'");
        facade->clearScene();
        return;
    }

    if (!okStepY) {
        QMessageBox::critical(this, "Error", "Normaliztion params error: Incorrect 'Step by Y'");
        facade->clearScene();
        return;
    }

    if (!path.isEmpty()) {
        try {
            FacadeOperationResult result = facade->loadScene(stdPath, params);
            if (!result.isSuccess()) {
                std::string error = result.getErrorMessage();
                const char* err = error.c_str();
                QMessageBox::critical(this, "Error", err);
                return;
            }
        } catch (const char* err) {
            QMessageBox::critical(this, "Error", err);
        }

        onApplyClicked();
        showScaleWarning();

    } else {
        clearGraph();
        QMessageBox::critical(this, "Error", "Bad way to file");
        facade->clearScene();
        return;
    }
}
