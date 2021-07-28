#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpSocket>
#include<QtNetwork>
#include<QString>
#include<QDebug>
#include<QFile>
#include<QStringList>
#include<QFileDialog>
#include<QBuffer>
#include<QImage>
#include<QImageReader>
#include<QPixmap>
#include<QLabel>
#include<QIcon>
#include<QStyle>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void connect_msg();
    void disconnect_msg();
    void recv_msg();

    void on_up_pressed();
    void on_up_released();

    void on_donw_pressed();
    void on_donw_released();

    void on_left_pressed();
    void on_left_released();

    void on_right_pressed();
    void on_right_released();


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *soket;
    QTcpSocket *soket1;
    QString ip;
    char buf[240000];
    int port1,port2;
    QStringList filename;
    unsigned long int sum=0;
};

#endif // WIDGET_H
