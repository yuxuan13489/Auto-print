#include "widget.h"
#include "./ui_widget.h"
#include"print.h"
#include<QIcon>
#include<QFileDialog>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("自动打印程序--by yuxxuan");
    this->setWindowIcon(QIcon(ICON_PATH));



    connect(ui->pushButton,&QPushButton::clicked,[=](){
        m_p->directoryPath = QFileDialog::getExistingDirectory(nullptr, "Select Directory", "", QFileDialog::ShowDirsOnly);
        this->m_p->firstTimeScan();

        //QFile file("C:/Users/Li Yuxuan/Desktop/path.txt");
        // file.open(QIODevice::WriteOnly | QIODevice::Text);
        // // 创建一个文本流
        // QTextStream out(&file);

        // // 将文本写入文件
        // out.setCodec("UTF-8");
        // out << "123";

        // // 关闭文件
        // file.close();

    });

    this->m_p=new print;
    this->m_p->firstTimeScan();
    this->timer.start(CHECK_SPEED);
    QObject::connect(&timer, &QTimer::timeout,[=](){
        this->m_p->checkForNewDocxFiles();
    });




}

Widget::~Widget()
{
    delete ui;
}


