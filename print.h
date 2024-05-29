#ifndef PRINT_H
#define PRINT_H

#include <QTimer>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include<QWidget>
#include<QApplication>
#include <Windows.h>
#include<qprocess.h>



class print
{
public:
    print();
    void checkForNewDocxFiles();
    void firstTimeScan();

    QString directoryPath = "D:/WeChat_Download/WeChat Files/wxid_148j1nkqg8ek22/FileStorage/File/2024-05";
};

#endif // PRINT_H
