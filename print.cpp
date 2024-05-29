#include "print.h"

print::print() {}


void print::checkForNewDocxFiles()   {

    qDebug()<<directoryPath;

    QDir directory(directoryPath);
    QStringList filters;
    filters << "*.docx";
    directory.setNameFilters(filters);

    // 获取当前目录下所有docx文件列表
    QStringList currentFiles = directory.entryList(QDir::Files);

    // 读取上次记录的docx文件列表
    QFile lastFilesFile("last_docx_files.txt");
    QStringList lastFiles;
    if (lastFilesFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&lastFilesFile);
        while (!in.atEnd()) {
            lastFiles << in.readLine();
        }
        lastFilesFile.close();
    }

    // 比较当前文件列表和上次记录的文件列表
    for (const QString& currentFile : currentFiles) {
        // 如果当前文件不在上次记录的文件列表中，则表示新生成的文件
        if (!lastFiles.contains(currentFile)) {
            //qDebug() << "New docx file detected: " << currentFile;
            QString result=directoryPath+"/"+currentFile;
            qDebug()<<result;
            ShellExecuteW(0, L"print", reinterpret_cast<LPCWSTR>(result.utf16()), 0, 0, SW_SHOWNORMAL);
        }
    }

    // 将当前文件列表写入文件，以便下次检测使用
    if (lastFilesFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&lastFilesFile);
        for (const QString& currentFile : currentFiles) {
            out << currentFile << endl;
        }
        lastFilesFile.close();
    }
}

void print::firstTimeScan()
{
    QDir directory(directoryPath);
    QStringList filters;
    filters << "*.docx";
    directory.setNameFilters(filters);

    // 获取当前目录下所有docx文件列表
    QStringList currentFiles = directory.entryList(QDir::Files);

    // 读取上次记录的docx文件列表
    QFile lastFilesFile("last_docx_files.txt");
    QStringList lastFiles;
    if (lastFilesFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&lastFilesFile);
        while (!in.atEnd()) {
            lastFiles << in.readLine();
        }
        lastFilesFile.close();
    }

    // 比较当前文件列表和上次记录的文件列表
    for (const QString& currentFile : currentFiles) {
        // 如果当前文件不在上次记录的文件列表中，则表示新生成的文件
        if (!lastFiles.contains(currentFile)) {
            //qDebug() << "New docx file detected: " << currentFile;
            QString result=directoryPath+"/"+currentFile;


        }
    }

    // 将当前文件列表写入文件，以便下次检测使用
    if (lastFilesFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&lastFilesFile);
        for (const QString& currentFile : currentFiles) {
            out << currentFile << endl;
        }
        lastFilesFile.close();
    }
    qDebug("初始化成功！");
}
