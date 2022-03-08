#include "winapi.h"


#pragma comment (lib,"ws2_32.lib")
#pragma comment (lib,"iphlpapi.lib")
#pragma comment(lib, "packet.lib")

typedef struct _et_header    //以太网头部
{
    unsigned char   eh_dst[6];
    unsigned char   eh_src[6];
    unsigned short  eh_type;
}ET_HEADER;

typedef struct _arp_header   //ARP头部
{
    unsigned short  arp_hdr;
    unsigned short  arp_pro;
    unsigned char   arp_hln;
    unsigned char   arp_pln;
    unsigned short  arp_opt;
    unsigned char   arp_sha[6];
    unsigned char   arp_spa[4];
    unsigned char   arp_tha[6];
    unsigned char   arp_tpa[4];
}ARP_HEADER;

QString LanScan(UINT srcIp,UINT uIp){

    ULONG c[2] = {0},len=6;//接收
    char mac[20]="NULL";
    HRESULT result = SendARP(htonl(uIp),htonl(srcIp),c,&len);
    if(result == NO_ERROR){
        BYTE *g = (BYTE *)&c;
        in_addr target_addr;

        target_addr.S_un.S_addr=htonl((uIp));

        if (len){
            qDebug("host %s living, max address:", inet_ntoa(target_addr));
            for (int i = 0; i < (int) len; i++)
            {
                    if (i == (len - 1))
                    {
                            sprintf(mac+i*3,"%.2X", (int) g[i]);
                    }
                    else
                    {
                            sprintf(mac+i*3,"%.2X-", (int) g[i]);
                    }
            }
        }
        qDebug("%s",mac);
    }
    return mac;

}

void initsocket(){
    WSADATA data;
    WORD wVersion = MAKEWORD(2,2);
    WSAStartup(wVersion,&data);
}

PIP_ADAPTER_INFO getAllAdapterInfo(){
    PIP_ADAPTER_INFO pAdapterInfo=NULL;
    ULONG ulLen=0;
    ::GetAdaptersInfo(pAdapterInfo,&ulLen);
    pAdapterInfo=(PIP_ADAPTER_INFO)::GlobalAlloc(GPTR,ulLen);
    ::GetAdaptersInfo(pAdapterInfo,&ulLen);
    PIP_ADAPTER_INFO cur =pAdapterInfo;
    PIP_ADAPTER_INFO newcur=(PIP_ADAPTER_INFO)::GlobalAlloc(GPTR,1);
    pAdapterInfo=newcur;
    while(cur){
        switch (cur->Type) {
        case MIB_IF_TYPE_OTHER:break;
        case MIB_IF_TYPE_TOKENRING:break;
        case MIB_IF_TYPE_FDDI:break;
        case MIB_IF_TYPE_PPP:break;
        case MIB_IF_TYPE_LOOPBACK:break;
        case MIB_IF_TYPE_SLIP:break;
        case MIB_IF_TYPE_ETHERNET:
        default://无线网卡,Unknown type
            IP_ADDR_STRING *pIpAddrString =&(cur->IpAddressList);
            if(strcmp(pIpAddrString->IpAddress.String,"0.0.0.0")==0) break;
            newcur->Next=cur;
            newcur=newcur->Next;
            qDebug() << "IP:" << pIpAddrString->IpAddress.String <<"submask:" <<pIpAddrString->IpMask.String<<endl;
        }
        cur=cur->Next;
    }
    newcur->Next=NULL;
    return pAdapterInfo->Next;
}

void StrToMac(char *str,unsigned char *mac){
    char *str1;
    int i;
    int low,high;
    char temp;

    for(i=0;i<6;i++){
        str1=str+1;
        switch(*str){
            case 'a':high=10;break;
            case 'b':high=11;break;
            case 'c':high=12;break;
            case 'd':high=13;break;
            case 'e':high=14;break;
            case 'f':high=15;break;
            default:
                temp=*str;
                high=atoi(&temp);
        }
        switch(*str1){
            case 'a':low=10;break;
            case 'b':low=11;break;
            case 'c':low=12;break;
            case 'd':low=13;break;
            case 'e':low=14;break;
            case 'f':low=15;break;
            default:
                temp=*str1;
                low=atoi(&temp);
        }
        mac[i]=high*16+low;
        //qDebug()<<high<<":"<<low<<"="<<(int)mac[i];
        str+=3;
        }
}


void constructARP(char *srcmac,char *dstmac,char *srcip,char *dstip,char *buffer){
    unsigned char s_mac[20]={0};
    unsigned char d_mac[20]={0};
    unsigned char s_ip[4]={0};
    unsigned char d_ip[4]={0};
    StrToMac(srcmac,s_mac);
    StrToMac(dstmac,d_mac);
    inet_pton(AF_INET, srcip, &s_ip);
    inet_pton(AF_INET, dstip, &d_ip);


    ET_HEADER et_header;
    et_header.eh_type=htons(0x0806);
    memcpy(et_header.eh_src,s_mac,6);
    memcpy(et_header.eh_dst,d_mac,6);


    ARP_HEADER arp_header;
    arp_header.arp_hdr=htons(0x0001);  //硬件地址类型以太网地址
    arp_header.arp_pro=htons(0x0800);  //协议地址类型为IP协议
    arp_header.arp_hln=6;              //硬件地址长度为6
    arp_header.arp_pln=4;              //协议地址长度为4
    arp_header.arp_opt=htons(0x0002);  //标识为ARP应答
    memcpy(arp_header.arp_sha,s_mac,6);//srcmac
    memcpy(arp_header.arp_tha,d_mac,6);//dstmac
    memcpy(arp_header.arp_spa,s_ip,4);
    memcpy(arp_header.arp_tpa,d_ip,4);

    memcpy(buffer,&et_header,sizeof(ET_HEADER));
    memcpy(buffer+sizeof(ET_HEADER),&arp_header,sizeof(ARP_HEADER));

}



