#include "udprecv.h"
//#include <QSharedMemory>
#include <QtNetwork/QUdpSocket>
//#include <QNetworkProxy>
//#include <QTextCodec>
//UdpRecv::UdpRecv(int size,int portIN, QHostAddress host )
//UdpRecv:: UdpRecv(uint8_t DevId_0, uint8_t PackId_0,int size_0,uint8_t DevId_1, uint8_t PackId_1,int size_1, int portIN, QHostAddress host)
//UdpRecv:: UdpRecv(uint8_t DevId_0, uint8_t PackId_0,int size_0,uint8_t DevId_1, uint8_t PackId_1,int size_1, int portIN, QHostAddress host)
UdpRecv::UdpRecv(QVector<uint8_t> & DevId,QVector<uint8_t> & PackId ,QVector<int> & SizeDatagram, int portIN, QHostAddress host)
{
#ifdef  CONTROL_TIME
    m_tim = new TimeClass("FromIVO    ",200);//for control
#endif//CONTROL_TIME  // TimeClass*  m_timRecv;
    NumDatagram=SizeDatagram.size();
    if(NumDatagram >0 && NumDatagram<10000)
    {
         m_pUdpRecv = new QUdpSocket();
         //m_pUdpRecv->setProxy(QNetworkProxy::NoProxy);
         SizeDatagramRecv =SizeDatagram;
         DevIdRecv  = DevId;
         PackIdRecv = PackId;

         QByteArray baDatagram;
         int i=0;
         while(i<NumDatagram)
         {
            baDatagram.resize(SizeDatagram[i]);
            baDatagramArray.push_back(baDatagram);
            countRecv.push_back(0);
            i++;
         }
         baDatagramRead.resize(MAX_BUF);
         port = portIN;
         adr = host ;
         bBind = m_pUdpRecv->bind(adr, port);
         connect(m_pUdpRecv, SIGNAL(readyRead()),this , SLOT(slotReceivingData()));
    }
    else
        StateRecv=-1;
}//

UdpRecv::~UdpRecv()
{
   delete  m_pUdpRecv;
#ifdef  CONTROL_TIME
   delete  m_tim ;//for control
#endif//CONTROL_TIME  // Ti
}

void UdpRecv::slotReceivingData()
{
//#ifdef  CONTROL_TIME
//    m_tim ->StartFrame();//for control
//#endif//CONTROL_TIME  // TimeClass*  m_timRecv;

    do {
        //countRecvOne++;//была выборка
        int sizeRec= m_pUdpRecv->pendingDatagramSize() ;
        bool bEs=false;
        foreach( int value, SizeDatagramRecv )
        {
           if(value == sizeRec)
           {
              bEs=true;
              break;
           }
        }
        //if(sizeRec == baDatagramArray[0].size()  || sizeRec == baDatagramArray[1].size())
        if(bEs)
        {
            m_pUdpRecv->readDatagram(baDatagramRead.data(), sizeRec, &adr);
            int i=0;
            while(i<NumDatagram)
            {

               if(DevIdRecv[i]==baDatagramRead[0] && PackIdRecv[i]==baDatagramRead[1] && sizeRec==baDatagramArray[i].size())
               {
                     memcpy(baDatagramArray[i].data(), baDatagramRead.data(), sizeRec);//
                     countRecv[i]++;
                     break;
               }
               i++;
            }

        }

    } while(m_pUdpRecv->hasPendingDatagrams());
}
void UdpRecv::UpdateReceivingData(void* dataDest, int Index , int & countR )
{
    if(StateRecv>0 )
    {
          memcpy( dataDest, baDatagramArray[Index].data(), baDatagramArray[Index].size() );
          countR= countRecv[Index];

    }
}
