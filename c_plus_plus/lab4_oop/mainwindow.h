#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "facade.h"
#include "qt_scene_drawer.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QPicture>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    #define INT_ZERO 0
    #define MAX_LEN 10
    #define ZERO "0"
    #define DEFAULT_SCALE "100"

    void setUI();
    void connectUI();
    void setLineEditSettings();
    void clearGraph();
    void showWarning();
    void showScaleWarning();
    void setDefaultValues();
    void onOpenFileClicked();
    void onApplyClicked();


    Ui::MainWindow *ui;
    Facade* facade;
    QPicture _pixmap = QPicture();
    QtSceneDrawer drawer;
};
#endif // MAINWINDOW_H
