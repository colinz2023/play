#ifndef HELLOQTWIN_H
#define HELLOQTWIN_H

#include <QMainWindow>

namespace Ui {
class HelloQtWin;
}

class HelloQtWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit HelloQtWin(QWidget *parent = nullptr);
    ~HelloQtWin();

private:
    Ui::HelloQtWin *ui;
};

#endif // HELLOQTWIN_H
