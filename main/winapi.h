#ifndef WINAPI_H
#define WINAPI_H
#include <QDebug>
#include <stdio.h>
#include <Packet32.h>
#include <WS2tcpip.h>
#include <iphlpapi.h>

//void initsocket();
PIP_ADAPTER_INFO getAllAdapterInfo();
QString LanScan(UINT srcIp,UINT uIp);
void constructARP(char* mymac,char *srcmac,char *dstmac,char *srcip,char *dstip,char *buffer);

#endif // WINAPI_H
