﻿#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QTcpSocket>
typedef struct info{
    int a;
    char name[50];
}Info;
class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT //添加这个宏是为了实现信号和槽的通信
public:
    TcpClientSocket(QObject *parent = 0);
protected slots:
    void receivedata();//处理readyRead信号读取数据
    void slotclientdisconnected();//客户端断开连接触发disconnected信号，这个槽函数用来处理这个信号

signals:
    void updateserver(char *, int);//用来告诉tcpserver需要跟新界面的显示
    void clientdisconnected(int); //告诉server有客户端断开连接
};

#endif // TCPCLIENTSOCKET_H
