#include "helloqtwin.h"
#include "ui_helloqtwin.h"

HelloQtWin::HelloQtWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelloQtWin)
{
    ui->setupUi(this);
}

HelloQtWin::~HelloQtWin()
{
    delete ui;
}
