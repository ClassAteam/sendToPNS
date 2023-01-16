
//Добавить в файл про:    QT          +=  network

#ifndef UDPRECV_H
#define UDPRECV_H
#include <QObject>
#include <QHostAddress>

#define CONTROL_TIME  // #ifdef  CONTROL_TIME   #endif//CONTROL_TIME  // TimeClass*  m_timRecv;
#define MAX_BUF 2048
#ifdef  CONTROL_TIME
#include "Dispether/utilTimeClassQt.h"
#endif//CONTROL_TIME


#pragma once

class QUdpSocket;

class UdpRecv : public  QObject
{
Q_OBJECT
public:
   // UdpRecv(uint8_t DevId_0, uint8_t PackId_0,int size_0,uint8_t DevId_1, uint8_t PackId_1,int size_1, int portIN, QHostAddress host);
    UdpRecv(QVector<uint8_t> & DevId,QVector<uint8_t> & PackId ,QVector<int> & SizeDatagram, int portIN, QHostAddress host);

    ~UdpRecv();
    void UpdateReceivingData(void* dataDest, int IndexRecv , int & countRecv );
    int port{0}    ;
    //QHostAddress adr=QHostAddress::Any;
    QHostAddress adr ;
    //---------------------------
//    uint8_t DevIdRecv_0{0};
//    uint8_t DevIdRecv_1{0};
//    uint8_t PackIdRecv_0{0};
//    uint8_t PackIdRecv_1{0};
//    int sizeFromTo_0{0} ;
//    int sizeFromTo_1{0} ;
    //QByteArray baDatagram_0;
   // QByteArray baDatagram_1;

    QVector<uint8_t> DevIdRecv;
    QVector<uint8_t> PackIdRecv;
    QVector<int> SizeDatagramRecv;//
    QVector<QByteArray> baDatagramArray;
    QByteArray baDatagramRead;
    int NumDatagram{0};//число типов посылок
    QVector<int> countRecv;//счетчик приемов
    int StateRecv{1};//-1 QVector<int> & SizeDatagram=0 //
#ifdef  CONTROL_TIME
    TimeClass*  m_tim;
#endif//CONTROL_TIME


private:
    QUdpSocket* m_pUdpRecv;
    bool bBind{0};
private slots:
    void slotReceivingData();
};

#endif // UDPRECV_H


