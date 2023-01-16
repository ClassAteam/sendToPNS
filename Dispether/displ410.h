#ifndef DISPL410_H
#define DISPL410_H

#include <QObject>
#include <QTimer>
#include <QSettings>
#include <QDir>
#include <QVector>
#include "utilTimeClassQt.h"
#include "threadToIVO.h"
#include "UdpRecvSendQT/udprecv.h"
#include "UdpRecvSendQT/udpsend.h"
#include "HeaderExtern/Protokol_L410_PNS_v70.h"
//---------------------------------------------------------
class DispL410 : public QObject
{
    Q_OBJECT
public:
    explicit DispL410(QObject *parent = nullptr);
    ~DispL410();
    unsigned long  timeFromStart=0;//(ms)
    //ThreadToIVO *threadToIVO    ;
    void ReadIni(void);
    void copyName_Int(QString & NN, QString strN,int i);
    void Manager();
    //---struct for net
    UdpSend* SendIVO   ;
    UdpRecv* RecvIVO;

    UdpRecv* RecvPNS;
//    UdpRecv* RecvCABIN ;

    UdpSend* SendPNS_1                ;

    UdpSend* SendPNS_2                ;

    UdpSend* SendPNS_3                ;

    //param for net
//    QVector<uint8_t> DevId;
//    QVector<uint8_t> PackId;
//    QVector<int> SizeRecvBuf;
//    QVector<QHostAddress>adrToFrom;
//    int cointHost{0};//всего хостов
    //----timer for send
    TimeClass* pFrameTimeAlarm ;
   // TimeClass* pFrameToIVO;
//    void WriteFromCabina()   ;
//    void WriteToCabina()     ;
//   // void WriteToIBKO()       ;
//    void WriteFromIBKO()     ;
//    void WriteFromIvo()      ;
//    void WriteToTvo();
//    void WriteToRMI();
//    void PrepareVisualSendBlock(int curr_counter);
//uint8_t CompAnt_rez{0};
      int cointFromNet[100] {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//счетчик пакетов, пришедших из сети //индекс =0 АРК //  =1 РСБН
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                            };
      int cointUpdateRecv[100] {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//счетчик опрошенных нами пакетов //индекс =0 АРК //  =1 РСБН
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                             0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                            };


private:

    int coint_2 {0};
    int coint_5 {0};
    int coint_10{0};
    int coint_50{0};

    void WriteToPNS();

void SendDataToPNS_From_CO_2010(void);

void SendDataToPNS_From_ARK(void);

void SendDataToPNS_From_RSBN(void);

void SendDataToPNS_From_BKS(void);

void SendDataToPNS_From_KRA(void);

void SendDataToPNS_From_BSOI(void);

void UpdateSendBSOIData(void* , int);

    void WriteFromPNS();

    //QTime*        tm ;
signals:

};

#endif // DISPL410_H

//extern class DispL410* disp;
