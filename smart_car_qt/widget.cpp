#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    setMinimumSize(640,480);
    ip="192.168.1.1";
    port1=6666;
    port2=8888;
    ui->setupUi(this);

    ui->label_2->setMinimumSize(480,320);
    ui->label_2->setScaledContents(true);
    ui->label_2->setStyleSheet("background-color:black");
    soket=new QTcpSocket;
    soket->connectToHost(ip,port1);

    QIcon icon;
    icon.addFile(tr(":/up.png"));
    ui->up->setIcon(icon);

    QIcon icon1;
    icon1.addFile(tr(":/down.png"));
    ui->donw->setIcon(icon1);

    QIcon icon2;
    icon2.addFile(tr(":/left.png"));
    ui->left->setIcon(icon2);

    QIcon icon3;
    icon3.addFile(tr(":/right.png"));
    ui->right->setIcon(icon3);

    QIcon icon4;
    icon4.addFile(tr(":/123.jpg"));
    ui->stop->setIcon(icon4);

    soket1=new QTcpSocket;
    soket1->connectToHost(ip,port2);
    connect(soket,SIGNAL(connected()),this,SLOT(connect_msg()));
    connect(soket1,SIGNAL(connected()),this,SLOT(connect_msg()));
    connect(soket,SIGNAL(disconnected()),this,SLOT(disconnect_msg()));
    connect(soket1,SIGNAL(disconnected()),this,SLOT(disconnect_msg()));
    connect(soket1,SIGNAL(readyRead()),this,SLOT(recv_msg()),Qt::DirectConnection);
}

void Widget::connect_msg()
{
    qDebug()<<"connect success";
}
void Widget::disconnect_msg()
{
    qDebug()<<"disconnect";
}
void Widget::recv_msg()    //接收视频信息
    int pic_len=0;
    pic_len = soket1->read(buf+sum,320*240);
    sum+=pic_len;


    if(sum >=76800)
    {
         soket1->write("1",1);
         qDebug() << "aaaa" <<endl;
         QPixmap pixmap;
         pixmap.loadFromData((uchar*)buf,76800,"JPEG");
         ui->label_2->setPixmap(pixmap);
         memset(buf,0,240000);
         sum=0;
    }

}
Widget::~Widget()
{
    delete ui;
}

void Widget::on_up_pressed()
{
    if(soket->isValid())
    {
    soket->write("up");
    soket->flush();
    }
}

void Widget::on_up_released()
{
    if(soket->isValid())
    {
    soket->write("stop");
    soket->flush();
    }
}

void Widget::on_donw_pressed()
{
    if(soket->isValid())
    {
    soket->write("down");
    soket->flush();
    }
}

void Widget::on_donw_released()
{
    if(soket->isValid())
    {
    soket->write("stop");
    soket->flush();
    }
}

void Widget::on_left_pressed()      //小车左转信号
{
    soket->write("left");
    soket->flush();
}

void Widget::on_left_released()     //释放小车左转信号
{
    if(soket->isValid())
    {
    soket->write("stop");
    soket->flush();
    }
}

void Widget::on_right_pressed()     //小车右转信号
{
    soket->write("right");
    soket->flush();
}

void Widget::on_right_released()    //释放小车右转信号
{
    if(soket->isValid())
    {
    soket->write("stop");
    soket->flush();
    }
}


void Widget::on_pushButton_clicked() // 视频显示窗口打开
{
    ui->label_2->show();
}

void Widget::on_pushButton_2_clicked()  // 视频显示窗口关闭
{
    ui->label_2->hide();
}


