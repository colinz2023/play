#include 中去掉 -I啊。
echo "INCLUDEPATH +=" `pkg-config --cflags opencv` > opencv.pri
echo "DEPENDPATH +=" `pkg-config --cflags opencv` >> opencv.pri
echo "LIBS +=" `pkg-config --libs opencv` >> opencv.pri