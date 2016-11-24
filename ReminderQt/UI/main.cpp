#include "remainderdlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RemainderDlg w;
    w.show();

    return a.exec();
}
