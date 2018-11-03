#include "helloqtwin.h"
#include <QApplication>
#include <string>

#include "opencv2/opencv.hpp"

static std::string kImagePath = "/Users/colin/workSpace/realzhangm/cv_test/t4.jpg";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    HelloQtWin w;
//    w.show();
    using namespace cv;
    Mat image = imread(kImagePath.c_str());
    imshow("输出", image);

    return a.exec();
}
