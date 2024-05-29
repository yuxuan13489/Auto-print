#include "widget.h"
#include"print.h"
#include <QApplication>
#include <QWidget>
#include <QTimer>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include<QWidget>
#include <Windows.h>
#include<qprocess.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();



    return a.exec();
}
