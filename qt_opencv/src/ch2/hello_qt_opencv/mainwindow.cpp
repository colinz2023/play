#include "mainwindow.h"
#include "QMessageBox"
#include "ui_mainwindow.h"

#include "QFileDialog"
#include "QDir"
#include "QSettings"

#include "opencv2/opencv.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadSettings();
//    if (ui->inputLineEdit->text().size() == 0)
//        ui->inputLineEdit->setText("图片路径...");
//    if (ui->outputLineEdit->text().size() == 0)
//        ui->outputLineEdit->setText("输出到...");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputPushButton_clicked()
{
    QString fileName = \
    QFileDialog::getOpenFileName(this,
                                "Open Input Image",
                                QDir::currentPath(),
                                "Images (*.jpg *.png *.bmp)");

    if (QFile::exists(fileName)) {
        ui->inputLineEdit->setText(fileName);
    }
}

void MainWindow::on_outputPushButton_clicked()
{
    QString fileName = \
    QFileDialog::getSaveFileName(this,
                                 "Select Output Image",
                                 QDir::currentPath(),
                                 "*.jpg;;*.png;;*.bmp");
    if (!fileName.isEmpty()) {
        ui->outputLineEdit->setText(fileName);

        cv::Mat inpImg, outImg;
        inpImg = cv::imread(ui->inputLineEdit->text().toStdString());
        if (ui->medianBlurRadioButton->isChecked()) {
            cv::medianBlur(inpImg, outImg, 5);
        } else if(ui->gaussianBlurRadioButton->isChecked()) {
            cv::GaussianBlur(inpImg, outImg, cv::Size(5, 5), 1.25);
        }
        imwrite(fileName.toStdString(), outImg);

        if (ui->displayImageCheckBox->isChecked()) {
            imshow("Output Image", outImg);
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int result = \
    QMessageBox::warning(this,
                         "退出",
                         "确认退出程序?",
                         QMessageBox::Yes, QMessageBox::No);
    if (result == QMessageBox::Yes) {
        saveSettings();
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::loadSettings()
{
    QSettings settings("Packt", "Hello_OpenCV_Qt", this);
    ui->inputLineEdit->setText(settings.value("inputLineEdit", "").toString());
    ui->outputLineEdit->setText(settings.value("outputLineEdit", "").toString());
    ui->medianBlurRadioButton->setChecked(settings.value("medianBlurRadioButton", true).toBool());
    ui->gaussianBlurRadioButton->setChecked(settings.value("gaussianBlurRadioButton", false).toBool());
    ui->displayImageCheckBox->setChecked(settings.value("displayImageCheckBox", false).toBool());
}

//保存在哪里？Who knows?
void MainWindow::saveSettings()
{
    QSettings settings("Packt", "hell_qt_opencv", this);
    settings.setValue("inputLineEdit", ui->inputLineEdit->text());
    settings.setValue("outputLineEdit", ui->outputLineEdit->text());
    settings.setValue("medianBlurRadioButton", ui->medianBlurRadioButton->isChecked());
    settings.setValue("gaussianBlurRadioButton", ui->gaussianBlurRadioButton->isChecked());
    settings.setValue("displayImageCheckBox", ui->displayImageCheckBox->isChecked());
}

