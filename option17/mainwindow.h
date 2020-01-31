#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QPair>
#include <QLabel>
#include <QList>
#include <QMessageBox>
#include <QFileDialog>
#include <vector>
#include <string.h>
#include "figure.h"

#define LIMIT_OF_FIGURES 15

using namespace std;

enum {Red = 1, Orange, Yellow, Green, Blue, Purple, Black};

struct cellInfo{
    Coordinates position;
    int type = 0;
    int color = 0;
    Figure *figure;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void paintEvent(QPaintEvent *event);
private slots:
    void on_pushReadFile_clicked();

    void on_pushDrawFromUI_clicked();

    void on_figureChoice_activated(int index);

    void on_pushCancelDraw_clicked();

    void SetVisibilityOfFields(bool visible);

    void on_pushCancelAll_clicked();

    void on_pushSave_clicked();

    void on_pushOneColor_clicked();

    void on_pushSingleColor_clicked();

private:
    Ui::MainWindow *ui;
    cellInfo figures[LIMIT_OF_FIGURES];
    QLabel **labelForToolTip;
};

#endif // MAINWINDOW_H
