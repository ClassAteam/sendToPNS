#include <QtNetwork/QUdpSocket>

#include "displ410.h"
#include "defineMat.h"
//=============================
RK_STATUS             toRK_STATUS;
BSAP_DATA             toBSAP_DATA;
//SVS_FULL
BlockOpetatingTime    toBlockOpetatingTime;
COURSE_DATA           toCOURSE_DATA;
AHRS_DATA             toAHRS_DATA;
AHRS_STATUS           toAHRS_STATUS;
SNS_DATA              toSNS_DATA;
//
//------------CO-2010
//
SOOutSelfContrStruct SOOutSelfContr; // PackId = 0; Результаты самодиагностики
SOOutModeStruct SOOutMode; // PackId = 1; Режим работы
//
//------------ARK
//
ARC40OutModeStruct ARC40OutMode; // PackId = 0; Режим работы АРК40
ARC40OutCourseStruct ARC40OutCourse; // PackId = 1; Курсовой угол

ARC40InModeStruct ARC40InMode; // PackId = 0; Режим работы АРК40
//
//------------RSBN
//
RSBNOutChKKStruct RSBNOutChKK; // PackId = 0; Режимы+ЧКК
RSBNOutDfStruct RSBNOutDf; // PackId = 1; Дальность Df
RSBNOutAfStruct RSBNOutAf; // PackId = 2; Азимут Af
RSBNOutEkfStruct RSBNOutEkf; // PackId = 3; Отклонение от линии посадки по курсу
RSBNOutEgfStruct RSBNOutEgf; // PackId = 4; Отклонение от линии посадки по глиссаде
RSBNOutCondWordStruct RSBNOutCondWord; // PackId = 5; Служебное слово

RSBNInContrWordStruct RSBNInContrWord; // PackId = 0; Слово управления
//
//------------BKS
//
BKSOutBKSCondStruct BKSOutBKSCond; // PackId = 0; Слово состояния БКС
BKSOutPrimaDMVFaultStruct BKSOutPrimaDMV1Fault; // PackId = 1; Слово расшифровки неисправностей Прима ДМВ1
BKSOutPrimaDMVFaultStruct BKSOutPrimaDMV2Fault; // PackId = 2; Слово расшифровки неисправностей Прима ДМВ2
BKSOutPrimaKVFaultStruct BKSOutPrimaKVFault; // PackId = 3; Слово расшифровки неисправностей Прима КВ
BKSOutCIMSAFaultStruct BKSOutCIMSAFault; // PackId = 4; Слово расшифровки неисправностей ЦИМС-А
BKSOutPrimaDMVCond1Struct BKSOutPrimaDMV1Cond1; // PackId = 5; Слово состояния 1 радиостанции Прима ДМВ1
BKSOutPrimaDMVCond1Struct BKSOutPrimaDMV2Cond1; // PackId = 6; Слово состояния 1 радиостанции Прима ДМВ2
BKSOutPrimaDMVCond2Struct BKSOutPrimaDMV1Cond2; // PackId = 7; Слово состояния 2 радиостанции Прима ДМВ1
BKSOutPrimaDMVCond2Struct BKSOutPrimaDMV2Cond2; // PackId = 8; Слово состояния 2 радиостанции Прима ДМВ2
BKSOutPrimaDMVCond3Struct BKSOutPrimaDMV1Cond3; // PackId = 9; Слово состояния 3 радиостанции Прима ДМВ1
BKSOutPrimaDMVCond3Struct BKSOutPrimaDMV2Cond3; // PackId = 10; Слово состояния 3 радиостанции Прима ДМВ2
BKSOutPrimaKVCond1Struct BKSOutPrimaKVCond1; // PackId = 11; Слово состояния 1 радиостанции Прима КВ
BKSOutPrimaKVCond2Struct BKSOutPrimaKVCond2; // PackId = 12; Слово состояния 2 радиостанции Прима КВ
BKSOutPrimaKVCond3Struct BKSOutPrimaKVCond3; // PackId = 13; Слово состояния 3 радиостанции Прима КВ
BKSOutAnsw1DMVStruct BKSOutAnsw1DMV; // PackId = 14; Слово ответа 1 на запрос канала ПСБК УКВ рс
BKSOutAnsw1KVStruct BKSOutAnsw1KV; // PackId = 15; Слово ответа 1 на запрос канала ПСБК КВ рс
BKSOutAnsw2DMVStruct BKSOutAnsw2DMV; // PackId = 16; Слово ответа 2 на запрос канала ПСБК УКВ рс
BKSOutAnsw2KVStruct BKSOutAnsw2KV; // PackId = 17; Слово ответа 2 на запрос канала ПСБК КВ рс
BKSOutAnswPozStruct BKSOutAnswPoz; // PackId = 18; Слово ответа на запрос позывного канала ПСБК
//
//------------KRA
//
KRAOutAltBinStruct    KRAOutAltBin; // PackId = 0; Радиовысотомер (двочиный)
KRAOutAltBinDecStruct KRAOutAltBinDec; // PackId = 1; Радиовысотомер (двоично-десятичный)
//
//------------BSOI
//
 BSOIOutIntStruct BSOIOutTempAirHeater; // PackId = 0; Температура воздуха отопления, градус Цельсия
 BSOIOutIntStruct BSOIOutTempAirCabine; // PackId = 1; Температура воздуха в пассажирской кабине, градус Цельсия
 BSOIOutIntStruct BSOIOutULeft; // PackId = 2; Напряжение генератора левого, вольт
 BSOIOutIntStruct BSOIOutIGenLeftEng; // PackId = 3; Ток генератора левого двигателя, ампер
 BSOIOutIntStruct BSOIOutURight; // PackId = 4; Напряжение генератора правого, вольт
 BSOIOutIntStruct BSOIOutIGenRightEng; // PackId = 5; Ток генератора правого двигателя, ампер
 BSOIOutIntStruct BSOIOutUEmerg1; // PackId = 6; Напряжение аварийной шины 1, вольт
 BSOIOutIntStruct BSOIOutUEmerg2; // PackId = 7; Напряжение аварийной шины 2, вольт
 BSOIOutIntStruct BSOIOutUBat1; // PackId = 8; Напряжение аккумуляторной батареи 1, вольт
 BSOIOutIntStruct BSOIOutIBat1; // PackId = 9; Ток аккумуляторной батареи 1, ампер
 BSOIOutIntStruct BSOIOutUBat2; // PackId = 10; Напряжение аккумуляторной батареи 2, вольт
 BSOIOutIntStruct BSOIOutIBat2; // PackId = 11; Ток аккумуляторной батареи 2, ампер
 BSOIOutIntStruct BSOIOutU23Gen36V1; // PackId = 12; Напряжение между фазами 2-3 генератора 36 вольт №1, вольт
 BSOIOutIntStruct BSOIOutU13Gen36V1; // PackId = 13; Напряжение между фазами 1-3 генератора 36 вольт №1, вольт
 BSOIOutIntStruct BSOIOutU12Gen36V1; // PackId = 14; Напряжение между фазами 1-2 генератора 36 вольт №1, вольт
 BSOIOutIntStruct BSOIOutU23Gen36V2; // PackId = 15; Напряжение между фазами 2-3 генератора 36 вольт №2, вольт
 BSOIOutIntStruct BSOIOutU13Gen36V2; // PackId = 16; Напряжение между фазами 1-3 генератора 36 вольт №2, вольт
 BSOIOutIntStruct BSOIOutU12Gen36V2; // PackId = 17; Напряжение между фазами 1-2 генератора 36 вольт №2, вольт
 BSOIOutIntStruct BSOIOutUAGen115V1; // PackId = 18; Напряжение фазы A генератора 115 вольт №1, вольт
 BSOIOutIntStruct BSOIOutUBGen115V1; // PackId = 19; Напряжение фазы B генератора 115 вольт №1, вольт
 BSOIOutIntStruct BSOIOutUCGen115V1; // PackId = 20; Напряжение фазы C генератора 115 вольт №1, вольт
 BSOIOutIntStruct BSOIOutUAGen115V2; // PackId = 21; Напряжение фазы A генератора 115 вольт №2, вольт
 BSOIOutIntStruct BSOIOutUBGen115V2; // PackId = 22; Напряжение фазы B генератора 115 вольт №2, вольт
 BSOIOutIntStruct BSOIOutUCGen115V2; // PackId = 23; Напряжение фазы C генератора 115 вольт №2, вольт
 BSOIOutIntStruct BSOIOutLevFuelLeftTanks; // PackId = 24; Уровень топлива в левой системе топливных баков, кг
 BSOIOutIntStruct BSOIOutLevFuelRightTanks; // PackId = 25; Уровень топлива в правой системе топливных баков, кг
 BSOIOutIntStruct BSOIOutLevFuelLeftTermTanks; // PackId = 26; Уровень топлива в концевом топливном баке слева, кг
 BSOIOutIntStruct BSOIOutLevFuelRightTermTanks; // PackId = 27; Уровень топлива в концевом топливном баке справа, кг
 BSOIOutFloatStruct BSOIOutPFuelLeft; // PackId = 28; Давление топлива левой системы, МПа
 BSOIOutFloatStruct BSOIOutPOilLeft; // PackId = 29; Давление масла левой системы, МПа
 BSOIOutIntStruct BSOIOutTOilLeft; // PackId = 30; Температура масла левой системы, градус Цельсия
 BSOIOutFloatStruct BSOIOutPFuelRight; // PackId = 31; Давление топлива правой системы, МПа
 BSOIOutFloatStruct BSOIOutPOilRight; // PackId = 32; Давление масла правой системы, МПа
 BSOIOutIntStruct BSOIOutTOilRight; // PackId = 33; Температура масла правой системы, градус Цельсия
 BSOIOutIntStruct BSOIOutConsFuelLeft; // PackId = 34; Расход топлива левого двигателя, кг/ч
 BSOIOutIntStruct BSOIOutConsFuelRight; // PackId = 35; Расход топлива правого двигателя, кг/ч
 BSOIOutFloatStruct BSOIOutPGydroMain; // PackId = 36; Давление гидравлической жидкости в основном контуре постоянного давления, МПа
 BSOIOutFloatStruct BSOIOutPGydroBrake; // PackId = 37; Давление гидравлической жидкости в контуре тормозов, МПа
 BSOIOutFloatStruct BSOIOutElevatorAngle; // PackId = 40; Угол отклонения руля высоты, [-30..14], градусы (вверх - минус, вниз - плюс)
 BSOIOutFloatStruct BSOIOutAileronAngle; // PackId = 41; Угол отклонения элеронов, [-27..14], градусы (вверх - минус, вниз - плюс)
 BSOIOutFloatStruct BSOIOutRudderAngle; // PackId = 42; Угол отклонения руля направления, [-17..17], градусы (направо - минус, налево - плюс)
 BSOIOutFloatStruct BSOIOutTrimmerRudder; // PackId = 43; Угол отклонения триммера руля направления, [-10..10], градусы (направо - минус, налево - плюс)
 BSOIOutIntStruct BSOIOutRUDLeft; // PackId = 44; Положение РУД левого двигателя, %
 BSOIOutIntStruct BSOIOutRUDRight; // PackId = 45; Положение РУД правого двигателя, %
 BSOIOutIntStruct BSOIOutTorqLeft; // PackId = 46; Крутящий момент левого двигателя, %
 BSOIOutIntStruct BSOIOutTorqRight; // PackId = 47; Крутящий момент правого двигателя, %
 BSOIOutFloatStruct BSOIOutPGydroParkBrake; // PackId = 48; Давление в контуре стояночного тормоза, МПа
 BSOIOutFloatStruct BSOIOutPGydroBrakeLeft; // PackId = 49; Давление в левой гидравлической системе тормозов, МПа
 BSOIOutFloatStruct BSOIOutPGydroBrakeRight; // PackId = 50; Давление в правой гидравлической системе тормозов, МПа
 BSOIOutIntStruct BSOIOutNLeft; // PackId = 51; Обороты воздушного винта левого двигателя, об/мин
 BSOIOutIntStruct BSOIOutNRight; // PackId = 52; Обороты воздушного винта правого двигателя, об/мин
 BSOIOutIntStruct BSOIOutNGasGenLeft; // PackId = 53; Обороты газогенератора левого двигателя, %
 BSOIOutIntStruct BSOIOutNGasGenRight; // PackId = 54; Обороты газогенератора правого двигателя, %
 BSOIOutIntStruct BSOIOutTTurbLeft; // PackId = 55; Температура между турбиной газогенератора и турбиной воздушного винта левого двигателя, градус
 BSOIOutIntStruct BSOIOutTTurbRight; // PackId = 56; Температура между турбиной газогенератора и турбиной воздушного винта правого двигателя, градус
 BSOIOutIntStruct BSOIOutUoporPot; // PackId = 57; Опорное напряжение для датчиков на основе потенциометров и термосопротивлений, вольт
 BSOIOutIntStruct BSOIOutUoporFuelLeftTanks; // PackId = 58; Опорное напряжение для датчика уровня топлива в левой системе топливных баков, вольт
 BSOIOutIntStruct BSOIOutUoporFuelRightTanks; // PackId = 59; Опорное напряжение для датчика уровня топлива в правой системе топливных баков, вольт
 BSOIOutIntStruct BSOIOutUoporFuelLeftTerm; // PackId = 60; Опорное напряжение для датчика уровня топлива в левом концевом баке, вольт
 BSOIOutIntStruct BSOIOutUoporFuelRightTerm; // PackId = 61; Опорное напряжение для датчика уровня топлива в правом концевом баке, вольт
 BSOIOutIntStruct BSOIOutUoporPFuelLeft; // PackId = 62; Опорное напряжение для датчика давления топлива левой группы, вольт
 BSOIOutIntStruct BSOIOutUoporPOilLeft; // PackId = 63; Опорное напряжение для датчика давления масла левой группы, вольт
 BSOIOutIntStruct BSOIOutUoporPFuelRight; // PackId = 64; Опорное напряжение для датчика давления топлива правой группы, вольт
 BSOIOutIntStruct BSOIOutUoporPOilRight; // PackId = 65; Опорное напряжение для датчика давления масла правой группы, вольт
 BSOIOutIntStruct BSOIOutUoporPGydroMain; // PackId = 66; Опорное напряжение для датчика давления гидравлической жидкости в основном контуре, вольт
 BSOIOutIntStruct BSOIOutUoporPGydroBreak; // PackId = 67; Опорное напряжение для датчика давления гидравлической жидкости в контуре тормозов, вольт
 BSOIOutIntStruct BSOIOutTorqLeft_; // PackId = 85; Крутящий момент левого двигателя, %
 BSOIOutIntStruct BSOIOutTorqRight_; // PackId = 86; Крутящий момент правого двигателя, %
 BSOIOutFloatStruct BSOIOutAttackAngle1; // PackId = 68; Угол атаки 1, [-30..30], градусы
 BSOIOutFloatStruct BSOIOutAttackAngle2; // PackId = 75; Угол атаки 2, [-30..30], градусы
 BSOIOutFloatStruct BSOIOutPBFireExt; // PackId = 76; Давление огнетушителя багажного отсека [0..1.6], МПа
 BSOIOutFloatStruct BSOIOutTrimmerElev; // PackId = 77; Триммер руля высоты [-10..10], градусы
 BSOIOutFloatStruct BSOIOutTrimmerAiler; // PackId = 78; Триммер элеронов [-10..10], градусы
 BSOIOutIntStruct BSOIOutNGasGenLeftU; // PackId = 81; Обороты газогенератора левого двигателя (постоянное напряжение), %
 BSOIOutIntStruct BSOIOutNGasGenRightU; // PackId = 82; Обороты газогенератора правого двигателя (постоянное напряжение), %
 BSOIOutIntStruct BSOIOutFuelLevAddTank; // PackId = 83; Уровень топлива в дополнительном топливном баке, л
 BSOIOutRK1Struct BSOIOutRK1; // PackId = 69; Дискретные сигналы 1
 BSOIOutRK2Struct BSOIOutRK2; // PackId = 70; Дискретные сигналы 2
 BSOIOutRK3Struct BSOIOutRK3; // PackId = 71; Дискретные сигналы 3
 BSOIOutRK4Struct BSOIOutRK4; // PackId = 72; Дискретные сигналы 4
 BSOIOutRK5Struct BSOIOutRK5; // PackId = 73; Дискретные сигналы 5
 BSOIOutRK6Struct BSOIOutRK6; // PackId = 74; Дискретные сигналы 6
 BSOIOutRK7Struct BSOIOutRK7; // PackId = 79; Дискретные сигналы 7
 BSOIOutRK8Struct BSOIOutRK8; // PackId = 84; Дискретные сигналы 8
 BSOIOutCWStruct BSOIOutCW; // PackId = 80; Слово состояния БСОИ
//-------------------
SVS_DATA_FULL    toSVS_Data  ;
CTRL_DATA_FULL   toSVS_Ctrl  ;



//---------------------------
// int portRK_STATUS           = 10134   ;   //10gh 100ms
// int portBSAP_DATA           = 10601   ;   //25gh 40ms
// //int port//SVS_FULL          = 10208   ; //10gh 100ms
// int portBlockOpetatingTime  = 10011   ;   //1gh 1000ms
// int portCOURSE_DATA         = 10   ;      //10gh 100ms
// int portAHRS_DATA           = 10201;      //25gh 40ms
// int portAHRS_STATUS         = 10223;      //25gh 40ms
// int portSNS_DATA            = 10200;      //5gh  200ms
// int portBSOI                = 10130;      //50gh 20ms
 int rk_status_in	        =10134	;//10  Гц   Приём данных от РК
 int bsap_data_in	        =10601	;//25  Гц   Приём данных от БСАП
 int svs_data_full_in	    =10208	;//10  Гц   Приём управляющих данных СВС
 int operating_time_in	    =10011	;//1   Гц   Приём времени наработки
 int magnetometer_data_in	=10203	;//10  Гц   Приём данных от ММК
 int ahrs_data_in	        =10201	;//25  Гц   Приём даных от БКВ
 int sns_data_in	        =10200	;//5   Гц   Приём данных от СНС

int arinc_rpkb_in	        =10130	;//50  Гц   Приём данных в ИБКО (ARINC-429)
int arinc_rpkb_out	        =10310	;//50  Гц   Выдача  данных из ИБКО  (ARINC-429)

 int cv_vim95_data_in	    =10801	;//50  Гц   Приём данных VIM-95 (ЦВ ИСУ)
 int cv_dme_data_in	        =10802	;//50  Гц   Приём данных DME (ЦВ ИСУ)
 int cv_svs1_data_in	    =10803	;//50  Гц   Приём данных СВС1 (ЦВ ИСУ)
 int cv_svs2_data_in	    =10804	;//50  Гц   Приём данных СВС2 (ЦВ ИСУ)
 int cv_np101_data_in	    =10808	;//50  Гц   Приём данных НП-101 (ЦВ ИСУ)
//------------------------
int portSVS_ctrl            =10304  ;//10  Гц    Приём ctrl данных СВС
int portAHRS_STATUS         = 10223;      //25gh 40ms
//int portSendStat= 10223;
//int portSendBKV= 10201;

bool bZn0, bZn1,bZn2,bZn3,bZn4,bZn5,bZn6,bZn7,bZn8,bZn9,bZn10,
bZn11,bZn12,bZn13,bZn14,bZn15,bZn16,bZn17,bZn18,bZn19,bZn20,
bZn21,bZn22,bZn23,bZn24,bZn25,bZn26,bZn27,bZn28,bZn29,bZn30,
bZn31,bZn32,bZn33,bZn34,bZn35,bZn36,bZn37;


float ControlMinMaxF(float arg,bool & bZn,float  D ,float min,float  max);
//-------
uint8_t CompAnt_rez{0};
//--------------------------------------------------

DispL410::DispL410(QObject *parent) : QObject(parent)
{
   // tm   = new QTime(1,1,1,1);
    //tm->setTimerType(Qt::PreciseTimer);

   // ReadIni();

//    RecvIVO    =new UdpRecv(sizeof(sIVO_BACK), portFrom[netIVO],adrToFrom[netIVO] );
//    RecvCABIN  =new UdpRecv(sizeof(sCAB_OUT), portFrom[netCABIN],adrToFrom[netCABIN] );"255.255.255.255"
   // RecvPNS    =new UdpRecv(sizeof(AHRS_STATUS), portRecvBKV,QHostAddress("127.0.0.1"));


//     SendIVO    =new UdpSend(sizeof(sIVO)   , portTo[netIVO]  ,adrToFrom[netIVO] );

    //     SendIVO    = new UdpSend(QHostAddress("192.168.1.142")); // было
//     RecvIVO    = new UdpSend(QHostAddress(sizeof(sIVO_BACK), portFrom[netIVO],"192.168.1.142")); // было

//    SendCABIN  =new UdpSend(sizeof(sCAB)   , portTo[netCABIN],adrToFrom[netCABIN] );
//    SendRMI    =new UdpSend(sizeof(sRMI)   , portTo[netRMI],adrToFrom[netRMI] );
//
//------------ПНС
//
      SendPNS_1 = new UdpSend(QHostAddress("192.168.1.142"));

      SendPNS_2 = new UdpSend(QHostAddress("192.168.1.144"));
//-------
      uint8_t DevId_ARK=2;
      uint8_t DevId_RSBN=3;
      uint8_t PackId_ARK=0;
      uint8_t PackId_RSBN=0;

      QVector<uint8_t> DevIdRecv;
      QVector<uint8_t> PackIdRecv;
      QVector<int> SizeDatagramRecv;//

      DevIdRecv.push_back(DevId_ARK);
      DevIdRecv.push_back(DevId_RSBN);
      PackIdRecv.push_back(PackId_ARK);
      PackIdRecv.push_back(PackId_RSBN);
      SizeDatagramRecv.push_back(sizeof(ARC40InModeStruct));
      SizeDatagramRecv.push_back(sizeof(RSBNInContrWordStruct));


     // RecvPNS = new UdpRecv(sizeof(ARC40InModeStruct), arinc_rpkb_out, QHostAddress::Any);//Broadcast
      RecvPNS = new UdpRecv(DevIdRecv,PackIdRecv ,SizeDatagramRecv ,arinc_rpkb_out , QHostAddress::Any);


   // SendPNS    =new UdpSend(sizeof(AHRS_DATA ), portSendBKV ,QHostAddress("192.168.1.142"));
   // SendStatus    =new UdpSend(sizeof(AHRS_STATUS ), portSendStat ,QHostAddress("192.168.1.142"));
    pFrameTimeAlarm        = new TimeClass("ToDisp     ",200);//for control
   //pFrameToIVO          = new TimeClass("ToDisp     ",200);//for control
}
//---------------------------------------------------------------------------

DispL410::~DispL410()
{
    delete pFrameTimeAlarm;

    delete SendPNS_1;
    delete SendPNS_2;
//    delete SendPNS_3        ;

    delete RecvPNS;

//    delete SendIVO ; // было
//    delete RecvIVO ; // было
}

//void DispL410::ReadIni(void)
//{
//    //path to ini
//   #define STR_IN    64
//   QString strTemp;//("Кириллица");//
//   QString stringI{QDir::currentPath()};
//   const QString stringINI{ stringI + "/SettingsNet.ini"};//{QCoreApplication::applicationDirPath() + "/geocoord.ini"};
//   QSettings settings( stringINI, QSettings::IniFormat );
//   //-------------------------------------------
//   int countN=0;
//   while(1)
//   {
//       QString p;
//       p.setNum(countN);//itoa (i, p, 10);
//       QString grup = "Network_" + p ;//settings.endGroup();
//       settings.beginGroup(grup );
//       strTemp = settings.value("Name","No").toString();
//       if(strTemp =="No")
//       {
//           settings.endGroup();
//           break;
//       }
//       else
//       {
//           int temp= settings.value("portRecv","-1").toInt();
//           if(temp<1023 || temp>65335)
//                portFrom.push_back(-1);
//           else
//                portFrom.push_back(temp);
//           //int y=portFrom[0];
//             temp= settings.value("portSend","-1").toInt();
//             if(temp<1023 || temp>65335)
//                  portTo.push_back(-1);
//             else
//                  portTo.push_back(temp);

//           QString tempAdr = settings.value("SendIP","255.255.255.255").toString();
//           adrToFrom.push_back(QHostAddress(tempAdr));
//       }
//       settings.endGroup();
//       countN++;
//   }//while(1)
//   cointHost=countN;
//}//void DispL410::ReadIni(void)

    //memcpy(ibko,&AVN->IBKO , sizeof(SHMAIN_STRUCT_IN));
    //memcpy(ibko,&AVN->IBKO , sizeof(SHMAIN_STRUCT_IN));
//




//memcpy(rmi,&AVN->COM , sizeof(SHCOMMON_STRUCT));

//SendRK_STATUS
//SendBSAP_DATA
////SendSVS_FULL
//SendBlockOpetatingTime
//SendCOURSE_DATA
//SendAHRS_DATA
//SendAHRS_STATUS
//SendSNS_DATA
//Send_2RK_STATUS
//Send_2BSAP_DATA
////Send_2SVS_FULL
//Send_2BlockOpetatingTime
//Send_2COURSE_DATA
//Send_2AHRS_DATA
//Send_2AHRS_STATUS
//Send_2SNS_DATA
//---------------------------------------------------------------------------

void  DispL410::Manager()
{
    //====control time
    pFrameTimeAlarm->StartFrame();
    timeFromStart+=(unsigned long)(pFrameTimeAlarm->_FrameOne*1000.0);//(ms)

//====================UpdateSendData
//    int rk_status_in	        =10134	;//10  Гц   Приём данных от РК
//    int bsap_data_in	        =10601	;//25  Гц   Приём данных от БСАП
//    int svs_data_full_in	    =10208	;//10  Гц   Приём управляющих данных СВС
//    int operating_time_in	    =10011	;//1   Гц   Приём времени наработки
//    int magnetometer_data_in	=10203	;//10  Гц   Приём данных от ММК
//    int ahrs_data_in	        =10201	;//25  Гц   Приём даных от БКВ
//    int sns_data_in	        =10200	;//5   Гц   Приём данных от СНС
//    int arinc_rpkb_in	        =10130	;//50  Гц   Приём данных ARINC-429
//    int cv_vim95_data_in	    =10801	;//50  Гц   Приём данных VIM-95 (ЦВ ИСУ)
//    int cv_dme_data_in	    =10802	;//50  Гц   Приём данных DME (ЦВ ИСУ)
//    int cv_svs1_data_in	    =10803	;//50  Гц   Приём данных СВС1 (ЦВ ИСУ)
//    int cv_svs2_data_in	    =10804	;//50  Гц   Приём данных СВС2 (ЦВ ИСУ)
//    int cv_np101_data_in	    =10808	;//50  Гц   Приём данных НП-101 (ЦВ ИСУ)

//    int svs_ctrl_in	        =10304  ;//10  Гц    Приём ctrl данных СВС


//    disp->WriteToTvo();
//    disp->SendIVO->UpdateSendData(&sIVO);

//    disp->WriteToRMI();
//    disp->SendRMI->UpdateSendData(&sRMI);

//    disp->WriteToCabina();
//    disp->SendCABIN->UpdateSendData(&sCAB);
//
//------------IVO
//

//    SendIVO->UpdateSendData(&toRK_STATUS,sizeof(toRK_STATUS)  , port_IVO_in);  // было

//    RecvIVO->UpdateReceivingData(&toRK_STATUS); // было

    WriteToPNS();

    SendDataToPNS_From_CO_2010();

    SendDataToPNS_From_ARK();

    SendDataToPNS_From_RSBN();

    SendDataToPNS_From_BKS();

    SendDataToPNS_From_KRA();

    SendDataToPNS_From_BSOI();

    //10gh 100ms
    if(coint_5<5)
          coint_5++;
    else
    {
        coint_5=0;
        SendPNS_1->UpdateSendData(&toRK_STATUS,sizeof(toRK_STATUS)  , rk_status_in);
        SendPNS_2->UpdateSendData(&toRK_STATUS,sizeof(toRK_STATUS)  , rk_status_in);
//        disp->SendRK_STATUS->UpdateSendData(&toRK_STATUS); //
//        disp->Send_2RK_STATUS->UpdateSendData(&toRK_STATUS);


        SendPNS_1->UpdateSendData(&toSVS_Data, sizeof(toSVS_Data) , svs_data_full_in);
        SendPNS_2->UpdateSendData(&toSVS_Data, sizeof(toSVS_Data) , svs_data_full_in);
        SendPNS_1->UpdateSendData(&toSVS_Ctrl, sizeof(toSVS_Ctrl) , portSVS_ctrl);
        SendPNS_2->UpdateSendData(&toSVS_Ctrl, sizeof(toSVS_Ctrl) , portSVS_ctrl);
        //disp->SendSVS_FULL->UpdateSendData(&to);
        //disp->Send_2SVS_FULL->UpdateSendData(&to);

//        SendPNS_1->UpdateSendData(&toCOURSE_DATA, sizeof(toCOURSE_DATA) , svs_data_full_in);
//        SendPNS_2->UpdateSendData(&toCOURSE_DATA, sizeof(toCOURSE_DATA) , svs_data_full_in);
//        disp->SendCOURSE_DATA->UpdateSendData(&toCOURSE_DATA);
//        disp->Send_2COURSE_DATA->UpdateSendData(&toCOURSE_DATA);
    }

    //25gh 40ms
    if(coint_2<2)
          coint_2++;
    else
    {
        coint_2=0;
        SendPNS_1->UpdateSendData(&toBSAP_DATA, sizeof(toBSAP_DATA) , bsap_data_in);
        SendPNS_2->UpdateSendData(&toBSAP_DATA, sizeof(toBSAP_DATA) , bsap_data_in);
//        disp->SendBSAP_DATA->UpdateSendData(&toBSAP_DATA);
//        disp->Send_2BSAP_DATA->UpdateSendData(&toBSAP_DATA);

        SendPNS_1->UpdateSendData(&toAHRS_DATA, sizeof(toAHRS_DATA) , ahrs_data_in);
        SendPNS_2->UpdateSendData(&toAHRS_DATA, sizeof(toAHRS_DATA) , ahrs_data_in);
        SendPNS_1->UpdateSendData(&toAHRS_STATUS, sizeof(toAHRS_STATUS) , portAHRS_STATUS);
        SendPNS_2->UpdateSendData(&toAHRS_STATUS, sizeof(toAHRS_STATUS) , portAHRS_STATUS);
        //disp->SendAHRS_DATA->UpdateSendData(&toAHRS_DATA);
        //disp->SendAHRS_STATUS->UpdateSendData(&toAHRS_STATUS);
        //disp->Send_2AHRS_DATA->UpdateSendData(&toAHRS_DATA);
        //disp->Send_2AHRS_STATUS->UpdateSendData(&toAHRS_STATUS);
    }

    //1gh 1000ms
    if(coint_50<50)
          coint_50++;
    else
    {
        coint_50=0;
        toBlockOpetatingTime.operatingTime++;
        SendPNS_1->UpdateSendData(&toBlockOpetatingTime, sizeof(toBlockOpetatingTime) , operating_time_in);
        SendPNS_2->UpdateSendData(&toBlockOpetatingTime, sizeof(toBlockOpetatingTime) , operating_time_in);
        //disp->SendBlockOpetatingTime->UpdateSendData(&toBlockOpetatingTime);
        //disp->Send_2BlockOpetatingTime->UpdateSendData(&toBlockOpetatingTime);

    }


    //5gh  200ms
    if(coint_10<10)
          coint_10++;
    else
    {
        coint_10=0;
        SendPNS_1->UpdateSendData(&toSNS_DATA, sizeof(toSNS_DATA) , sns_data_in);
        SendPNS_2->UpdateSendData(&toSNS_DATA, sizeof(toSNS_DATA) , sns_data_in);
        //disp->SendSNS_DATA->UpdateSendData(&toSNS_DATA);
        //disp->Send_2SNS_DATA->UpdateSendData(&toSNS_DATA);
    }
//
//------------50 Hz 20 ms
//
//m_2:
    //disp->SendKRAOutAltBin->UpdateSendData(&KRAOutAltBin);
//    SendPNS_1->UpdateSendData(&KRAOutAltBinDec, sizeof(KRAOutAltBinDecStruct) , arinc_rpkb_in);
//    SendPNS_2->UpdateSendData(&KRAOutAltBinDec, sizeof(KRAOutAltBinDecStruct) , arinc_rpkb_in);
   // disp->SendKRAOutAltBinDec->UpdateSendData(&KRAOutAltBinDec);
}
//---------------------------------------------------------------------------

void DispL410:: WriteToPNS()
{

    //-----  1 RK_STATUS             toRK_STATUS;
    /*
     * Состояние выходных разовых команд
     * Младший бит - первая разовая команда
     * Используются:
     * для ПНС: первые 11 бит
     * для МФИ: первые 4 бита
     */
     toRK_STATUS.out_status=0x07ff;//uint32_t

    /*
     * Состояние входных разовых команд
     * Младший бит - первая разовая команда
     * Старший бит (32й) -  разовая команда снятия питания с блока
     * Используются:
     * для ПНС: первые 20 бит
     * для МФИ: первые 8 бит
     */
   toRK_STATUS.in_status=0x000fffff; //uint32_t
   toRK_STATUS.in_valid=1; // 0 - не исправны, 1 — исправныu   int8_t
   toRK_STATUS.out_valid=1; // 0 - не исправны, 1 - исправныu   int8_t

    //-----  2     BSAP_DATA   toBSAP_DATA.;
//   struct BSAP_DATA {
//       float    dlt_pitch; // Управляющий сигнал флайтдиректора по тангажу, [-15..15], градусы
//       float    dlt_roll; // Управляющий сигнал флайтдиректора по крену, [-15..15], градусы
//       uint16_t heading; // ЗК (пульт задачи курса), [0..359], градусы
//       uint16_t crs; // ЗПУ (пульт задачи курса), [0..359], градусы
//       uint8_t  ap_clutch; // Автопилот включен и управляет сервоприводами (1 - вкл, 0 - выкл)
//       uint8_t  ap_valid; // Автопилот исправен (1 - вкл и исправен, 0 - не исправен)
//       uint8_t  alt; // Включен режим ALT (1 - вкл, 0 - выкл)
//       uint8_t  alt_arm; // Предварительный режим ALT (1 - активирован, 0 - не активирован)
//       uint8_t  hdg; // Включен режим HDG (1 - вкл, 0 - выкл)
//       uint8_t  nav; // Включен режим NAV (1 - вкл, 0 - выкл)
//       uint8_t  nav_arm; // Предварительный режим NAV (1 - активирован, 0 - не активирован)
//       uint8_t  apr; // Включен режим APR (1 - вкл, 0 - выкл)
//       uint8_t  apr_arm; // Предварительный режим APR (1 - активирован, 0 - не активирован)
//       uint8_t  gs; // Удержание глиссады (1 - вкл, 0 - выкл)
//       uint8_t  bc; // Включен режим BC (1 - вкл, 0 - выкл)
//       uint8_t  ias; // Включен режим IAS (1 - вкл, 0 - выкл)
//       uint8_t  ga; // Включен режим GA (1 - вкл, 0 - выкл)
//       uint8_t  yd; // Включен демпфер рысканья (1 - вкл, 0 - выкл)
//       uint8_t  hb; // Включен режим HALF BANK (1 - вкл, 0 - выкл)
//       uint8_t  fd; // Включен режим FD (1 - вкл, 0 - выкл)
//       uint8_t  mode; // Выбранный режим на пульте задачи курса (0 - маршрут, 1 — РСБН/VOR)
//       uint8_t  cws; // Включен совмещенный режим (1 - включен, 0 - выключен)

//       BSAP_DATA() {
//           memset(this, 0, sizeof(*this));
//       }
//   } __attribute__((packed));
   toBSAP_DATA.dlt_pitch=10.0f; // Управляющий сигнал флайтдиректора по тангажу, [-15..15], градусы
   toBSAP_DATA.dlt_roll =12.0f; // Управляющий сигнал флайтдиректора по крену, [-15..15], градусы
   toBSAP_DATA.heading  =234; // ЗК (пульт задачи курса), [0..359], градусы
   toBSAP_DATA.crs      =123; // ЗПУ (пульт задачи курса), [0..359], градусы
   toBSAP_DATA.ap_clutch=0; // Автопилот включен и управляет сервоприводами (1 - вкл, 0 - выкл)
   toBSAP_DATA.ap_valid =0; // Автопилот исправен (1 - вкл и исправен, 0 - не исправен)
   toBSAP_DATA.alt      =0; // Включен режим ALT (1 - вкл, 0 - выкл)
   toBSAP_DATA.alt_arm  =0; // Предварительный режим ALT (1 - активирован, 0 - не активирован)
   toBSAP_DATA.hdg      =0; // Включен режим HDG (1 - вкл, 0 - выкл)
   toBSAP_DATA.nav      =0; // Включен режим NAV (1 - вкл, 0 - выкл)
   toBSAP_DATA.nav_arm  =0; // Предварительный режим NAV (1 - активирован, 0 - не активирован)
   toBSAP_DATA.apr      =0; // Включен режим APR (1 - вкл, 0 - выкл)
   toBSAP_DATA.apr_arm  =0; // Предварительный режим APR (1 - активирован, 0 - не активирован)
   toBSAP_DATA.gs       =0; // Удержание глиссады (1 - вкл, 0 - выкл)
   toBSAP_DATA.bc       =0; // Включен режим BC (1 - вкл, 0 - выкл)
   toBSAP_DATA.ias      =0; // Включен режим IAS (1 - вкл, 0 - выкл)
   toBSAP_DATA.ga       =0; // Включен режим GA (1 - вкл, 0 - выкл)
   toBSAP_DATA.yd       =0; // Включен демпфер рысканья (1 - вкл, 0 - выкл)
   toBSAP_DATA.hb       =0; // Включен режим HALF BANK (1 - вкл, 0 - выкл)
   toBSAP_DATA.fd       =0; // Включен режим FD (1 - вкл, 0 - выкл)
   toBSAP_DATA.mode     =0; // Выбранный режим на пульте задачи курса (0 - маршрут, 1 — РСБН/VOR)
   toBSAP_DATA.cws      =0; // Включен совмещенный режим (1 - включен, 0 - выключен)
    //-----  3        //SVS_FULL


    //-----  4     BlockOpetatingTime    toBlockOpetatingTime;
//  struct BlockOpetatingTime {
//       char blockName[10]; //!< имя блока, например "MFI1"
//       uint32_t operatingTime; //!< время наработки в секундах
//   } __attribute__((packed));
   strcat(toBlockOpetatingTime.blockName , "PNS");
   //toBlockOpetatingTime.operatingTime=55555;



    //-----  5    COURSE_DATA           toCOURSE_DATA.;
//   enum class CourseRegime   {
//       courseFromDmk, // курс, крен, тангаж от ММК
//       vectorsFromDmk, // векторы магнитного поля X, Y, Z от ММК
//       courseFromBkv, // курсы, посчитанные БКВ
//       courseFromBkvWithSns // курсы, посчитанные БКВ, с учетом поправки от СНС
//   };


//   /**
//    * @brief Данные от БКВ+ММК
//    */
//   struct COURSE_DATA {
//       float value1; // зависит от режима
//       float value2; // зависит от режима
//       float value3; // зависит от режима

//       CourseRegime regime; // режим расчета курса

//       /*
//        * Статус данных:
//        * 1 - достоверны
//        * 0 - не достоверны
//        */
//       uint8_t status;

//       COURSE_DATA() :
//       gyroCourse(0),
//       magneticCourseZero(0),
//       magneticCourse(0),
//       regime(CourseRegime::courseFromDmk),
//       status(0) {}
//   } __attribute__((packed));
   //toCOURSE_DATA.regime        =CourseRegime::courseFromDmk;
   toCOURSE_DATA.regime ={CourseRegime::courseFromDmk};
   toCOURSE_DATA.status=1;
   toCOURSE_DATA.value1        =85; // зависит от режима
   toCOURSE_DATA.value2        =25; // зависит от режима
   toCOURSE_DATA.value3        =35;

    //------------------ 6 toAHRS_DATA
    //    float Ax;                            // ускорение, g
    //    float Ay;                            // ускорение, g
    //    float Az;                            // ускорение, g
    //    float Wx;                 // угловая скорость, рад/c
    //    float Wy;                 // угловая скорость, рад/c
    //    float Wz;                 // угловая скорость, рад/c
    //    float roll;                 // угол крена БКВ, град
    //    float pitch;               // угол тангажа БКВ, град
    //    unsigned char status;  //Статус БКВ: 0-не раб. 1-раб


        toAHRS_DATA.Ax      = ControlMinMaxF(toAHRS_DATA.Ax   , bZn0,0.01f ,0.0f  ,10.0f  );                // ускорение, g
        toAHRS_DATA.Ay      = ControlMinMaxF(toAHRS_DATA.Ay   , bZn1,0.005f ,0.0f  ,10.0f  );                // ускорение, g
        toAHRS_DATA.Az      = ControlMinMaxF(toAHRS_DATA.Az   , bZn2,0.02f ,0.0f  ,10.0f  );                // ускорение, g
        toAHRS_DATA.Wx      = ControlMinMaxF(toAHRS_DATA.Wx   , bZn3,0.004f ,0.0f  ,5.0  );     // угловая скорость, рад/c
        toAHRS_DATA.Wy      = ControlMinMaxF(toAHRS_DATA.Wy   , bZn4,0.01f ,0.0f  ,5.0  );     // угловая скорость, рад/c
        toAHRS_DATA.Wz      = ControlMinMaxF(toAHRS_DATA.Wz   , bZn5,0.002f ,0.0f  ,5.0   );     // угловая скорость, рад/c
        toAHRS_DATA.roll    = ControlMinMaxF(toAHRS_DATA.roll , bZn6,0.01f , 0.0f ,30.0  );       // угол крена БКВ, град
        toAHRS_DATA.pitch   = ControlMinMaxF(toAHRS_DATA.pitch, bZn7,0.005f , 0.0f , 20.0 );      // угол тангажа БКВ, град

        toAHRS_DATA.status =1 ;  //Статус БКВ: 0-не раб. 1-раб


     //----6A--toAHRS_STATUS---------------------------------------------------------------

        toAHRS_STATUS.delta_pitch   = ControlMinMaxF( toAHRS_STATUS.delta_pitch  , bZn8,0.01f ,0.0f  ,10.0f  ); // смещения тангажа, градусы
        toAHRS_STATUS.delta_roll    = ControlMinMaxF( toAHRS_STATUS.delta_pitch  , bZn9,0.01f ,0.0f  ,20.0f  ); // смещения крена, градусы

        static int sh=0;
        if(sh < 50)
        {
            sh++;
            toAHRS_STATUS.snsStatus =0; // данные от СНС, 1 - приходят, 0 - давно не было или не валидны
            toAHRS_STATUS.courseStatus=1; // Определение курсового угла по данным СНС: 1 - завершено; 0 – не завершено
            toAHRS_STATUS.ready=0; // выставка, 2 - БКВ готова, 1 - идет выставка, 0 - выставки не было
            toAHRS_STATUS.snsCorrection=1; // коррекция по СНС, 1 - выполняется, 0 - не выполняется
        }
        else if(sh < 100)
        {
            sh++;
            toAHRS_STATUS.snsStatus =1; // данные от СНС, 1 - приходят, 0 - давно не было или не валидны
            toAHRS_STATUS.courseStatus=0; // Определение курсового угла по данным СНС: 1 - завершено; 0 – не завершено
            toAHRS_STATUS.ready=1; // выставка, 2 - БКВ готова, 1 - идет выставка, 0 - выставки не было
            toAHRS_STATUS.snsCorrection=0; // коррекция по СНС, 1 - выполняется, 0 - не выполняется
        }
        else
           sh=0;
        toAHRS_STATUS.timeToReady+=pFrameTimeAlarm->_FrameOne*0.001; // время до окончания выставки в секундах (если идет выставка)
        toAHRS_STATUS.totalTime+=pFrameTimeAlarm->_FrameOne*0.001; // общее время, на которое запущена выставка в секундах

        //-----  7      SNS_DATA              toSNS_DATA.;
//        struct SNS_DATA {
//            unsigned int time; // время в секундах
//            float splitSeconds; // доли секунд
//            unsigned int date; // дата ddmmyy
//            double lat; // широта в радианах
//            double lon; // долгота в радианах
//            float speed; // скорость в км/ч
//            float course; // курс в градусах
//            float height; // высота антенны над уровнем моря (геоидом), м

//            /*
//             * Статус решения:
//             * 1 - данные достоверны
//             * 0 - не достоверны
//             */
//            unsigned char status;

//            /*
//             * Используемая спутниковая система:
//             * 0 - GNSS
//             * 1 - GPS
//             * 2 - GLONASS
//             */
//            unsigned char satellite_sys;

//            /*
//             * Используемая система координат:
//             * 0 - WGS-84
//             * 1 - PZ-90
//             * 2 - SK-42
//             * 3 - SK-95
//             * 4 - PZ-90.02
//             */
//            unsigned char coordinate_sys;

//            /*
//             * Значение фильтра:
//             * 0  - фильтр выключен
//             * 10 - фильтр решение без использования Stop - фильтра
//             * 20 - фильтр решение с применением Stop – фильтра, но без COG фильтра
//             * 30 - фильтр решение с применением Stop и COG фильтров
//             */
//            unsigned char filter;

//            SNS_DATA() {
//                memset(this, 0, sizeof(SNS_DATA));
//            }
//        } __attribute__((packed));


            toSNS_DATA.time             =500; // время в секундах
            toSNS_DATA.splitSeconds     =100; // доли секунд
            toSNS_DATA.date             =301022; // дата ddmmyy
            toSNS_DATA.lat              =56.65; // широта в радианах
            toSNS_DATA.lon              =78.87; // долгота в радианах
            toSNS_DATA.speed            =444.0f; // скорость в км/ч
            toSNS_DATA.course           =222.0; // курс в градусах
            toSNS_DATA.height           =111.0f; // высота антенны над уровнем моря (геоидом), м

            toSNS_DATA.status           =1;
            toSNS_DATA.satellite_sys    =1;

            /*
             * Используемая система координат:
             * 0 - WGS-84
             * 1 - PZ-90
             * 2 - SK-42
             * 3 - SK-95
             * 4 - PZ-90.02
             */
            toSNS_DATA.coordinate_sys   =0;

            /*
             * Значение фильтра:
             * 0  - фильтр выключен
             * 10 - фильтр решение без использования Stop - фильтра
             * 20 - фильтр решение с применением Stop – фильтра, но без COG фильтра
             * 30 - фильтр решение с применением Stop и COG фильтров
             */
            toSNS_DATA.filter           =0;

            //-------------10




        //--------------11
        //------------------------------Диспетчер → СВС-----SVS_DATA_FULL--CTRL_DATA_FULL----------------------

                                   //Отправка                   //Прием
                                   //svs_data_full_out          //svs_data_full_in
                                   //10121                      //10208
          //Название               //svs_ctrl_out               //svs_ctrl_in
          //Номер                  //10116                      //10304
          //Программа              //au_dispetcher              //wise_svs
          //--------------------------------------------------------------------------

          // Данные от датчика СВС

//          struct SVS_DATA_FULL {
//              float v_prib; // приборная скорость, км/ч
//              float v_ist; // Истинная (воздушная) скорость, км/ч
//              float h_baro; // Абсолютная барометрическая высота, м
//              float h_qfe; // Относительная барометрическая высота (коррекция по QFE), м
//              float h_qnh; // Относительная барометрическая высота (коррекция по QNH), м
//              float vy; // вертикальная скорость, м/с
//              float P; // Статическое давление воздуха, мм.рт.ст.
//              float q; // Скоростной напор, Па

//              /*
//               * Статус данных:
//               * 1 - достоверны
//               * 0 - не достоверны
//               */
//              uint8_t status;
//          } __attribute__((packed));

//          //
//          // Управляющие данные для СВС
//          //
//              struct CTRL_DATA_FULL {
//                  float temp; // температура окружающего воздуха
//                  float P_qfe; // Давление (коррекция) QFE, мм.рт.ст.
//                  float P_qnh; // Давление (коррекция) QNH, мм.рт.ст.

//                  struct Valid {
//                      uint8_t temp; // Валидность температуры
//                      uint8_t P_qfe; // Валидность давления qfe
//                      uint8_t P_qnh; // Валидность давления qnh
//                  } valid;
//              } __attribute__((packed));
//          //--------------------------------------------------------------------------

//    SVS_DATA_FULL    toSVS_Data.  ;
//    CTRL_DATA_FULL   toSVS_Ctrl.  ;


                        toSVS_Data.v_prib = 111.0f; // приборная скорость, км/ч
                        toSVS_Data.v_ist  = 133.0f; // Истинная (воздушная) скорость, км/ч
                        toSVS_Data.h_baro = 555.5f; // Абсолютная барометрическая высота, м
                        toSVS_Data.h_qfe  = 666.6f; // Относительная барометрическая высота (коррекция по QFE), м
                        toSVS_Data.h_qnh  = 777.7f; // Относительная барометрическая высота (коррекция по QNH), м
                        toSVS_Data.vy     = 13.0f; // вертикальная скорость, м/с
                        toSVS_Data.P      = 777.7f; // Статическое давление воздуха, мм.рт.ст.
                        toSVS_Data.q      = 1001.1; // Скоростной напор, Па

                        /*
                         * Статус данных:
                         * 1 - достоверны
                         * 0 - не достоверны
                         */
                        toSVS_Data.status=1;

                    //
                    // Управляющие данные для СВС
                    //
                            toSVS_Ctrl.temp   = 22.2f; // температура окружающего воздуха
                            toSVS_Ctrl.P_qfe  = 666.6f; // Давление (коррекция) QFE, мм.рт.ст.
                            toSVS_Ctrl.P_qnh  = 688.8f; // Давление (коррекция) QNH, мм.рт.ст.

                            toSVS_Ctrl.valid.temp  = 1 ; // Валидность температуры
                            toSVS_Ctrl.valid.P_qfe = 1 ; // Валидность давления qfe
                            toSVS_Ctrl.valid.P_qnh = 1 ; // Валидность давления qnh


}//void DispL410::  WriteToPNS()
//---------------------------------------------------------------------------

void DispL410::SendDataToPNS_From_CO_2010(void)
{
//
//------------CO-2010
//
//
//------------PackId = 0; Результаты самодиагностики (Слово состояния)
//
    SOOutSelfContr.DevId = 0;

    SOOutSelfContr.PackId = 0;
//-------
    SOOutSelfContr.IsprSO2010 = 0; // Неисправность блока СО-2010 (0 - исправен, 1 - неисправен)
//-------
    SOOutSelfContr.StatusAFS837 = 0; // Отказ АФС частоты 837.5/740 МГц (0 - исправна, 1 - неисправна)

    SOOutSelfContr.StatusAFS1030 = 0; // Отказ АФС частоты 1030/1090 МГц (0 - исправна, 1 - неисправна)
//-------
    SOOutSelfContr.NoInfPNS12L1 = 0; // Отсутствие информации от ПНС1,2 линия 1 (0 - активен, 1 - неактивен (все слова отсутствуют))

    SOOutSelfContr.IncomplPNS12L1 = 0; // Неполная информация от ПНС1,2 линия 1 (0 - поступают все слова, 1 - часть слов отсутствует)
//-------
    SOOutSelfContr.NoInfPNS3L2 = 1; // Отсутствие информации от ПНС3 линия 2 (0 - активен, 1 - неактивен (все слова отсутствуют))

    SOOutSelfContr.IncomplPNS3L2 = 1; // Неполная информация от ПНС3 линия 2 (0 - поступают все слова, 1 - часть слов отсутствует)
//-------
    SOOutSelfContr.IncomplPNS12L3 = 0; // Неполная информация от ПНС1,2 линия 3 (0 - поступают все слова, 1 - часть слов отсутствует)

    SOOutSelfContr.NoInfPNS12L3 = 0; // Отсутствие информации от ПНС1,2 линия 3 (0 - активен, 1 - неактивен (все слова отсутствуют))
//-------
    SOOutSelfContr.NoInfPNS3L4 = 1; // Отсутствие информации от ПНС3 линия 4 (0 - активен, 1 - неактивен (все слова отсутствуют))

    SOOutSelfContr.IncomplPNS3L4 = 1; // Неполная информация от ПНС3 линия 4 (0 - поступают все слова, 1 - часть слов отсутствует)
//-------
    SOOutSelfContr.IncorrAddrIKAO = 0; // Некорректный адрес ИКАО (0 - корректный, 1 - некорректный)
//-------
    SOOutSelfContr.Matrix = 0; // Матрица состояния: 0 - нормальная работа, 1 - нет вычисленных данных, 2 - функциональный тест, 3 - предупреждение об отказе
//-------
    SOOutSelfContr.Reserv = 2; // Резерв
//-------
    SendPNS_1->UpdateSendData(&SOOutSelfContr, sizeof(SOOutSelfContrStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&SOOutSelfContr, sizeof(SOOutSelfContrStruct) , arinc_rpkb_in);
//
//------------PackId = 1; Режим работы (Слово режимов)
//
    SOOutMode.DevId = 0;

    SOOutMode.PackId = 1;
//-------
    SOOutMode.Ready = 1; // Работа/Готов: 0 - режим ACS или УВД; 1 - Готов

    SOOutMode.Earth = 0; // Воздух/Земля: 0 - воздух; 1 - земля
//-------
    SOOutMode.AZNVStat = 0; // Статус АЗН-В: 0 - действует; 1 - неисправно или неактивно
//-------
    SOOutMode.ExpSquitOff = 0; // Отключение расширенного сквиттера: 0 - выдача разрешена; 1 - выдача запрещена
//-------
    SOOutMode.AFSContr = 1; // Контроль АФС: 0 - АФС не контролируется; 1 - АФС контролируется
//-------
    SOOutMode.NACv = 2; // Код NACv
//-------
    SOOutMode.SPIOn = 1; // Включение SPI: 0 - SPI не включен; 1 - SPI включен
//-------
    SOOutMode.Mode = 0; // Режим работы: 0 - УВД или Готов; 1 - ACS
//-------
    SOOutMode.Emerg = 0; // Состояние аварии: 0 -отсутствует; 1 - присутствует
//-------
    SOOutMode.Matrix = 0;
//-------
    SOOutMode.Reserv = 4; // Резерв
//-------
    SendPNS_1->UpdateSendData(&SOOutMode, sizeof(SOOutModeStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&SOOutMode, sizeof(SOOutModeStruct) , arinc_rpkb_in);
//-------
}
//---------------------------------------------------------------------------

void DispL410::SendDataToPNS_From_ARK(void)
{
//
//------------ARK-40
//
//
//------------PackId = 0; Режим работы АРК-40
//
    ARC40OutMode.DevId = 2;

    ARC40OutMode.PackId = 0;
//-------
    ARC40OutMode.CompAnt = 0; // 0 - Компас, 1 - Антенна

    ARC40OutMode.TlphTlg = 0; // 0 - Телефон, 1 - Телеграф
//-------
    ARC40OutMode.Res1 = 1; // Резерв
//-------
    ARC40OutMode.Matrix = 0; // 0 - Нормальное функицонирование, 1 - Зафиксирована и отрабатывается информация последнего входного слова, 2 - Режим АРК: контроль
//-------
    ARC40OutMode.Res2 = 3; // Резерв
//-------
    ARC40OutMode.Freq = 325.7; // Float // Частота, кГц
//-------
    SendPNS_1->UpdateSendData(&ARC40OutMode, sizeof(ARC40OutModeStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&ARC40OutMode, sizeof(ARC40OutModeStruct) , arinc_rpkb_in);
//
//------------PackId = 1; Курсовой угол
//
    ARC40OutCourse.DevId = 2;

    ARC40OutCourse.PackId = 1;
//-------
    ARC40OutCourse.CourseAngle = 69.5; // Float // Курсовой угол, град. +- 180 градусов
//-------
    ARC40OutCourse.Matrix = 3; // 0 - Предупреждение об отказе, 1 - Нет вычислительных данных (режим Антенна, отсутствие радиостанции), 2 - Функциональный контроль, 3 - Нормальное функционировние
//-------
    ARC40OutCourse.Reserv = 6; // Резерв
//-------
    SendPNS_1->UpdateSendData(&ARC40OutCourse, sizeof(ARC40OutCourseStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&ARC40OutCourse, sizeof(ARC40OutCourseStruct) , arinc_rpkb_in);
//
//------------PackId = 0; Режим работы АРК40
//
    int ind=0;
    RecvPNS->UpdateReceivingData(&ARC40InMode,ind,cointFromNet[ind]);
    cointUpdateRecv[ind]++;
    ind=1;
    RecvPNS->UpdateReceivingData(&RSBNInContrWord,ind,cointFromNet[ind]);
    cointUpdateRecv[ind]++;
//-------

//    if(ARC40InMode.DevId == 48)
//    {
    CompAnt_rez = ARC40InMode.CompAnt;

//    rez = ARC40InMode.TlphTlg;

//    rez = ARC40InMode.Matrix;

//    rez =  ARC40InMode.Freq;
//    }

/*    ARC40InModeStruct ARC40InMode;

    struct ARC40InModeStruct {
        uint8_t DevId; // Идентификатор устройства
        uint8_t PackId; // Идентификатор пакета
        uint8_t CompAnt : 1; // 0 - Компас, 1 - Антенна
        uint8_t TlphTlg : 1; // 0 - Телефон, 1 - Телеграф
        uint8_t Matrix : 2; // 0 - Нормальное функицонирование, 1 - Зафиксирована и отрабатывается информация последнего входного слова, 2 - Режим АРК: контроль
        uint8_t Reserv : 4; // Резерв
        float Freq; // Частота, кГц
*/
//-------
//-------
}
//---------------------------------------------------------------------------

void DispL410::SendDataToPNS_From_RSBN(void)
{
//
//------------RSBN
//
//
//------------PackId = 0; Режимы + ЧКК
//
    RSBNOutChKK.DevId = 3;

    RSBNOutChKK.PackId = 0;
//-------
/*  Битовое поле матрицы состояния режимов работы
    * 11 “Не используется”
    * 10 “Функциональный тест”
    * 01 “Нет вычисленных данных”
    * 00 “Нормальная работа”
*/
    RSBNOutChKK.Mode.CondMatrixMode = 0; // Битовое поле матрицы состояния режимов работы

    RSBNOutChKK.Mode.AutoMode = 1; // Режим "Автомат" (всегда 1)

    RSBNOutChKK.Mode.LandingMode = 0; // Режим "Посадка" (0 - режим "Навигация", 1 - режим "Посадка")

    RSBNOutChKK.Mode.IdentMode = 1; // Режим "Опознование" (0 - выключен, 1 - включен)

    RSBNOutChKK.Mode.RadioSilenceMode = 1; // Режим "Запрет излучения" (0 - отсутствие запрета излучения, 1 - запрет излучения)

    RSBNOutChKK.Mode.BeaconType = 0; // Направленный маяк РСБН (0 - всенапраяленный маяк, 1 - напрадвенный маяк))

    RSBNOutChKK.Mode.Reserv = 1; // Резерв
//-------
    RSBNOutChKK.ChKK = 29; // Номер ЧКК
//-------
    SendPNS_1->UpdateSendData(&RSBNOutChKK, sizeof(RSBNOutChKKStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&RSBNOutChKK, sizeof(RSBNOutChKKStruct) , arinc_rpkb_in);
//
//------------PackId = 1; Дальность Df
//
    RSBNOutDf.DevId = 3;

    RSBNOutDf.PackId = 1;
//-------
    RSBNOutDf.Df = 25.5; // Float // Дальность Df, 0-500 км
//-------
/*  Битовое поле матрицы состояния дальности
    * 11 “Нормальная работа”
    * 10 “Функциональный тест”
    * 01 “Нет вычисленных данных”
    * 00 “Отказ”
*/
    RSBNOutDf.CondMatrixDf = 3; // Битовое поле матрицы состояния Df
//-------
    RSBNOutDf.SignalDfLost = 1; // Признак режима памяти Df при потере радиосигнала
//-------
    RSBNOutDf.Reserv = 5; // Резерв
//-------
    SendPNS_1->UpdateSendData(&RSBNOutDf, sizeof(RSBNOutDfStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&RSBNOutDf, sizeof(RSBNOutDfStruct) , arinc_rpkb_in);
//
//------------PackId = 2; Азимут Af
//
    RSBNOutAf.DevId = 3;

    RSBNOutAf.PackId = 2;
//-------
    RSBNOutAf.Af = 178.5; // Float // Азимут Af (+- 180 градусов)
//-------
/*  Битовое поле матрицы состояния азимута
    * 11 “Нормальная работа”
    * 10 “Функциональный тест”
    * 01 “Нет вычисленных данных”
    * 00 “Отказ”
 */
    RSBNOutAf.CondMatrixAf = 3; // Битовое поле матрицы состояния Af
//-------
    RSBNOutAf.SignalAfLost = 1; // Признак режима памяти Af
//-------
    RSBNOutAf.Reserv = 5; // Резерв
//-------
    SendPNS_1->UpdateSendData(&RSBNOutAf, sizeof(RSBNOutAfStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&RSBNOutAf, sizeof(RSBNOutAfStruct) , arinc_rpkb_in);
//
//------------PackId = 3; Отклонение от линии посадки по курсу
//
    RSBNOutEkf.DevId = 3;

    RSBNOutEkf.PackId = 3;
//-------
    RSBNOutEkf.Ekf = 50.8; // Float // Отклонение от линии посадки по курсу (%КРС)
//-------
/*  Битовое поле корректности данных отклонения от линии посадки
    * 11 “Нормальная работа”
    * 10 “Функциональный тест”
    * 01 “Нет вычисленных данных”
    * 00 “Отказ”
*/
    RSBNOutEkf.CondMatrixEkf = 3; // Битовое поле матрицы состояния Ekf
//-------
    RSBNOutEkf.Reserv = 6; // Резерв
//-------
    SendPNS_1->UpdateSendData(&RSBNOutEkf, sizeof(RSBNOutEkfStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&RSBNOutEkf, sizeof(RSBNOutEkfStruct) , arinc_rpkb_in);
//
//------------PackId = 4; Отклонение от линии посадки по глиссаде
//
    RSBNOutEgf.DevId = 3;

    RSBNOutEgf.PackId = 4;
//-------
    RSBNOutEgf.Egf = 0.5; //20.5; // Float // Отклонение от линии посадки по глиссаде (%КРС)
//-------
/*  Битовое поле корректности данных отклонения от линии посадки
    * 11 “Нормальная работа”
    * 10 “Функциональный тест”
    * 01 “Нет вычисленных данных”
    * 00 “Отказ”
 */
    RSBNOutEgf.CondMatrixEgf = 3; // Битовое поле матрицы состояния Egf
//-------
    RSBNOutEgf.Reserv = 6; // Резерв
//-------
    SendPNS_1->UpdateSendData(&RSBNOutEgf, sizeof(RSBNOutEgfStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&RSBNOutEgf, sizeof(RSBNOutEgfStruct) , arinc_rpkb_in);
//
//------------PackId = 5; Служебное слово
//
    RSBNOutCondWord.DevId = 3;

    RSBNOutCondWord.PackId = 5;
//-------
    RSBNOutCondWord.BNPFault = 0; // Отказ БНП
//-------
    RSBNOutCondWord.Cntr1Fault = 0; // Отсутствует управление по входу 1

    RSBNOutCondWord.Cntr2Fault = 0; // Отсутствует управление по входу 2
//-------
    RSBNOutCondWord.AFSFault = 0; // Отказ АФС
//-------
    RSBNOutCondWord.RSBNFault = 0; // Отказ РСБН
//-------
/*  Битовое поле корректности данных слова состояния
    * 00 “Нормальная работа”
    * 01 “Нет вычисленных данных”
    * 10 “Функциональный тест”
*/
    RSBNOutCondWord.CondMatrixCondWord = 0; // Битовое поле матрицы состояния слова состояния
//-------
    RSBNOutCondWord.Reserv = 1;
//-------
    SendPNS_1->UpdateSendData(&RSBNOutCondWord, sizeof(RSBNOutCondWordStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&RSBNOutCondWord, sizeof(RSBNOutCondWordStruct) , arinc_rpkb_in);
//-------
}
//---------------------------------------------------------------------------

void DispL410::SendDataToPNS_From_BKS(void)
{
//m_4:
//
//------------BKS
//
//
//------------PackId = 0; Слово состояния БКС
//
    BKSOutBKSCond.DevId = 4;

    BKSOutBKSCond.PackId = 0;
//-------
    BKSOutBKSCond.ExchSync = 4; // Синхронизация обмена (круговой счетчик))
//-------
    BKSOutBKSCond.KSSCond = 2; // Состояние КСС
//-------
    BKSOutBKSCond.CIMSAStat = 1; // Исправность ЦИМС-А  1-Исправно / 0-Неисправно
//-------
    BKSOutBKSCond.PrimaDMV1Stat = 1; // Исправность Прима ДМВ 1 1-Исправно / 0-Неисправно

    BKSOutBKSCond.PrimaDMV2Stat = 1; // Исправность Прима ДМВ 2 1-Исправно / 0-Неисправно

    BKSOutBKSCond.PrimaKVStat = 1; // Исправность Прима КВ 1-Исправно / 0-Неисправно
//-------
    BKSOutBKSCond.B850KR1Stat = 1; // Исправность Б8-50КР 1 1-Исправно / 0-Неисправно

    BKSOutBKSCond.B850KR2Stat = 1; // Исправность Б8-50КР 2 1-Исправно / 0-Неисправно

    BKSOutBKSCond.B7V35AStat = 1; // Исправность Б7В-35А 1-Исправно / 0-Неисправно
//-------
    BKSOutBKSCond.UNCh2x10Stat = 1; // Исправность УНЧ 2х10 1-Исправно / 0-Неисправно

    BKSOutBKSCond.UNCh2x3Stat = 1; // Исправность УНЧ 2х3 1-Исправно / 0-Неисправно
//-------
    BKSOutBKSCond.Reserv = 1; // Резерв
//-------
    SendPNS_1->UpdateSendData(&BKSOutBKSCond, sizeof(BKSOutBKSCondStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&BKSOutBKSCond, sizeof(BKSOutBKSCondStruct) , arinc_rpkb_in);



/*    BKSOutPrimaDMVFaultStruct BKSOutPrimaDMV1Fault; // PackId = 1; Слово расшифровки неисправностей Прима ДМВ1
    BKSOutPrimaDMVFaultStruct BKSOutPrimaDMV2Fault; // PackId = 2; Слово расшифровки неисправностей Прима ДМВ2
    BKSOutPrimaKVFaultStruct BKSOutPrimaKVFault; // PackId = 3; Слово расшифровки неисправностей Прима КВ
    BKSOutCIMSAFaultStruct BKSOutCIMSAFault; // PackId = 4; Слово расшифровки неисправностей ЦИМС-А
*/
//
//------------PackId = 5; Слово состояния 1 радиостанции Прима ДМВ1
//
    BKSOutPrimaDMV1Cond1.DevId = 4;

    BKSOutPrimaDMV1Cond1.PackId = 5;
//-------
    BKSOutPrimaDMV1Cond1.NumCh = 6; // Номер канала
//-------
    BKSOutPrimaDMV1Cond1.PSh = 1; // ПШ 0-Выкл / 1-Вкл.

    BKSOutPrimaDMV1Cond1.PPRCH = 1; // ФРЧ/ППРЧ 0-ФРЧ / 1-ППРЧ

    BKSOutPrimaDMV1Cond1.Modul = 3; // Модуляция 0-АМУ / 1-АМШ / 2-ЧМ / 3-АМ

    BKSOutPrimaDMV1Cond1.RRCH = 0; // РРЧ 0-высокая / 1-пониженная

    BKSOutPrimaDMV1Cond1.AP = 1; // АП 0-выкл / 1-вкл

    BKSOutPrimaDMV1Cond1.Ctr = 1; //Контроль 0-выкл / 1-вкл

    BKSOutPrimaDMV1Cond1.Pow = 2; // Мощность 0-0 / 1-25% / 2-50% / 3-100%

    BKSOutPrimaDMV1Cond1.NU = 1; // Признак НУ 0-выкл / 1-вкл
//-------
    BKSOutPrimaDMV1Cond1.ChooseByComm = 1; // Выбрано командиром 0-не выбрана / 1-выбрана

    BKSOutPrimaDMV1Cond1.ChooseBy2Pilot = 0; // Выбрано 2 членом экипажа 0-не выбрана / 1-выбрана
//-------
    BKSOutPrimaDMV1Cond1.Reserv = 3; // Резерв
//-------
    SendPNS_1->UpdateSendData(&BKSOutPrimaDMV1Cond1, sizeof(BKSOutPrimaDMVCond1Struct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&BKSOutPrimaDMV1Cond1, sizeof(BKSOutPrimaDMVCond1Struct) , arinc_rpkb_in);

/*    BKSOutPrimaDMVCond1Struct BKSOutPrimaDMV2Cond1; // PackId = 6; Слово состояния 1 радиостанции Прима ДМВ2
*/
//
//------------PackId = 7; Слово состояния 2 радиостанции Прима ДМВ1
//
    BKSOutPrimaDMV1Cond2.DevId = 4;

    BKSOutPrimaDMV1Cond2.PackId = 7;
//-------
    BKSOutPrimaDMV1Cond2.kHz1 = 1;

    BKSOutPrimaDMV1Cond2.kHz10 = 5;

    BKSOutPrimaDMV1Cond2.kHz100 = 6;
//-------
    BKSOutPrimaDMV1Cond2.MHz1 = 0;

    BKSOutPrimaDMV1Cond2.MHz10 = 0;

    BKSOutPrimaDMV1Cond2.MHz100 = 0;
//-------
    BKSOutPrimaDMV1Cond2.Reserv = 2;
//-------
    SendPNS_1->UpdateSendData(&BKSOutPrimaDMV1Cond2, sizeof(BKSOutPrimaDMVCond2Struct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&BKSOutPrimaDMV1Cond2, sizeof(BKSOutPrimaDMVCond2Struct) , arinc_rpkb_in);


/*    BKSOutPrimaDMVCond2Struct BKSOutPrimaDMV2Cond2; // PackId = 8; Слово состояния 2 радиостанции Прима ДМВ2
*/
//
//------------PackId = 9; Слово состояния 3 радиостанции Прима ДМВ1
//
    BKSOutPrimaDMV1Cond3.DevId = 4;

    BKSOutPrimaDMV1Cond3.PackId = 9;
//-------
    BKSOutPrimaDMV1Cond3.TLF = 1; // Прием ТЛФ 0-нет приема / 1-идет прием
//-------
    BKSOutPrimaDMV1Cond3.Izl = 1; // Излучение 0-нет ПРД / 1-идет ПРД
//-------
    BKSOutPrimaDMV1Cond3.SA = 1; // СА Резерв
//-------
    BKSOutPrimaDMV1Cond3.AP = 1; // Прием АП 0-нет приема / 1-идет прием
//-------
    BKSOutPrimaDMV1Cond3.Reserv = 4; // Резерв
//-------
    SendPNS_1->UpdateSendData(&BKSOutPrimaDMV1Cond3, sizeof(BKSOutPrimaDMVCond3Struct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&BKSOutPrimaDMV1Cond3, sizeof(BKSOutPrimaDMVCond3Struct) , arinc_rpkb_in);

/*  BKSOutPrimaDMVCond3Struct BKSOutPrimaDMV2Cond3; // PackId = 10; Слово состояния 3 радиостанции Прима ДМВ2
    BKSOutPrimaKVCond1Struct BKSOutPrimaKVCond1; // PackId = 11; Слово состояния 1 радиостанции Прима КВ
    BKSOutPrimaKVCond2Struct BKSOutPrimaKVCond2; // PackId = 12; Слово состояния 2 радиостанции Прима КВ
    BKSOutPrimaKVCond3Struct BKSOutPrimaKVCond3; // PackId = 13; Слово состояния 3 радиостанции Прима КВ
*/
//
//------------PackId = 14; Слово ответа 1 на запрос канала ПСБК УКВ рс
//
    BKSOutAnsw1DMV.DevId = 4;

    BKSOutAnsw1DMV.PackId = 14;
//-------
    BKSOutAnsw1DMV.ChNum = 6; // Номер канала (1-40)

    BKSOutAnsw1DMV.UKV = 1; // УКВ

    BKSOutAnsw1DMV.PPRCH = 0; // 0-ФРЧ / 1-ППРЧ

    BKSOutAnsw1DMV.Modul = 3; // 0-АМУ / 1-АМШ / 2-ЧМ / 3-АМ

    BKSOutAnsw1DMV.Reserv = 3; // Резерв
//-------
    SendPNS_1->UpdateSendData(&BKSOutAnsw1DMV, sizeof(BKSOutAnsw1DMVStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&BKSOutAnsw1DMV, sizeof(BKSOutAnsw1DMVStruct) , arinc_rpkb_in);

/*
    BKSOutAnsw1KVStruct BKSOutAnsw1KV; // PackId = 15; Слово ответа 1 на запрос канала ПСБК КВ рс
    BKSOutAnsw2DMVStruct BKSOutAnsw2DMV; // PackId = 16; Слово ответа 2 на запрос канала ПСБК УКВ рс
    BKSOutAnsw2KVStruct BKSOutAnsw2KV; // PackId = 17; Слово ответа 2 на запрос канала ПСБК КВ рс
    BKSOutAnswPozStruct BKSOutAnswPoz; // PackId = 18; Слово ответа на запрос позывного канала ПСБК
*/
//-------
}

void DispL410::SendDataToPNS_From_KRA(void)
{
//
//------------KRA
//
    KRAOutAltBin.DevId = 5;

    KRAOutAltBin.PackId = 0;

    KRAOutAltBin.AltBin = 498.5 / 0.305; // Float // Радиовысотомер (двоичный), футы

    KRAOutAltBin.SSM = 3; // Матрица состояния: 0-предупреждение об отказе, 1-нет вычисленных данных, 2-функциональный тест, 3-нормальная работа
//-------
    SendPNS_1->UpdateSendData(&KRAOutAltBin, sizeof(KRAOutAltBinStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&KRAOutAltBin, sizeof(KRAOutAltBinStruct) , arinc_rpkb_in);
//-------
}
//---------------------------------------------------------------------------

void DispL410::SendDataToPNS_From_BSOI(void)
{
//
//------------BSOI
//
//
//------------PackId = 0; Температура воздуха отопления, градус Цельсия
//
    BSOIOutTempAirHeater.DevId = 6;

    BSOIOutTempAirHeater.PackId = 0;

    BSOIOutTempAirHeater.Data = 66;  // Int

    BSOIOutTempAirHeater.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutTempAirHeater,0);
//
//------------PackId = 1; Температура воздуха в пассажирской кабине, градус Цельсия
//
    BSOIOutTempAirCabine.DevId = 6;

    BSOIOutTempAirCabine.PackId = 1;

    BSOIOutTempAirCabine.Data = 44; // Int

    BSOIOutTempAirCabine.Matrix=0;
//-------
    UpdateSendBSOIData(&BSOIOutTempAirCabine,0);
//
//------------PackId = 2; Напряжение генератора левого, Вольт
//
    BSOIOutULeft.DevId = 6;

    BSOIOutULeft.PackId = 2;

    BSOIOutULeft.Data = 34;  // Int

    BSOIOutULeft.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutULeft,0);
//
//------------PackId = 3; Ток генератора левого двигателя, Ампер
//
    BSOIOutIGenLeftEng.DevId = 6;

    BSOIOutIGenLeftEng.PackId = 3;

    BSOIOutIGenLeftEng.Data = 100; // Int

    BSOIOutIGenLeftEng.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutIGenLeftEng,0);
//
//------------PackId = 4; Напряжение генератора правого, Вольт
//
    BSOIOutURight.DevId = 6;

    BSOIOutURight.PackId = 4;

    BSOIOutURight.Data = 27; // Int

    BSOIOutURight.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutURight,0);
//
//------------PackId = 5; Ток генератора правого двигателя, Ампер
//
    BSOIOutIGenRightEng.DevId = 6;

    BSOIOutIGenRightEng.PackId = 5;

    BSOIOutIGenRightEng.Data = 120; // Int

    BSOIOutIGenRightEng.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutIGenRightEng,0);
//
//------------PackId = 6; Напряжение аварийной шины 1, Вольт
//
    BSOIOutUEmerg1.DevId = 6;

    BSOIOutUEmerg1.PackId = 6;

    BSOIOutUEmerg1.Data = 28; // Int

    BSOIOutUEmerg1.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutUEmerg1,0);
//
//------------PackId = 7; Напряжение аварийной шины 2, Вольт
//
    BSOIOutUEmerg2.DevId = 6;

    BSOIOutUEmerg2.PackId = 7;

    BSOIOutUEmerg2.Data = 29; // Int

    BSOIOutUEmerg2.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutUEmerg2,0);
//
//------------PackId = 8; Напряжение аккумуляторной батареи 1, Вольт
//
    BSOIOutUBat1.DevId = 6;

    BSOIOutUBat1.PackId = 8;

    BSOIOutUBat1.Data = 26; // Int

    BSOIOutUBat1.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutUBat1,0);
//
//------------PackId = 9; Ток аккумуляторной батареи 1, Ампер
//
    BSOIOutIBat1.DevId = 6;

    BSOIOutIBat1.PackId = 9;

    BSOIOutIBat1.Data = 30; // Int

    BSOIOutIBat1.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutIBat1,0);
//
//------------PackId = 10; Напряжение аккумуляторной батареи 2, Вольт
//
    BSOIOutUBat2.DevId = 6;

    BSOIOutUBat2.PackId = 10;

    BSOIOutUBat2.Data = 28; // Int

    BSOIOutUBat2.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutUBat2,0);
//
//------------PackId = 11; Ток аккумуляторной батареи 2, Ампер
//
    BSOIOutIBat2.DevId = 6;

    BSOIOutIBat2.PackId = 11;

    BSOIOutIBat2.Data = 50; // Int

    BSOIOutIBat2.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutIBat2,0);
//
//------------PackId = 12; Напряжение между фазами 2-3 генератора 36 вольт №1, Вольт
//
    BSOIOutU23Gen36V1.DevId = 6;

    BSOIOutU23Gen36V1.PackId = 12;

    BSOIOutU23Gen36V1.Data = 35;  // Int

    BSOIOutU23Gen36V1.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutU23Gen36V1,0);
//
//------------PackId = 13; Напряжение между фазами 1-3 генератора 36 вольт №1, Вольт
//
    BSOIOutU13Gen36V1.DevId = 6;

    BSOIOutU13Gen36V1.PackId = 13;

    BSOIOutU13Gen36V1.Data = 36;  // Int

    BSOIOutU13Gen36V1.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutU13Gen36V1,0);
//
//------------PackId = 14; Напряжение между фазами 1-2 генератора 36 вольт №1, Вольт
//
    BSOIOutU12Gen36V1.DevId = 6;

    BSOIOutU12Gen36V1.PackId = 14;

    BSOIOutU12Gen36V1.Data = 37;  // Int

    BSOIOutU12Gen36V1.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutU12Gen36V1,0);
//
//------------PackId = 15; Напряжение между фазами 2-3 генератора 36 вольт №2, Вольт
//
    BSOIOutU23Gen36V2.DevId = 6;

    BSOIOutU23Gen36V2.PackId = 15;

    BSOIOutU23Gen36V2.Data = 32;  // Int

    BSOIOutU23Gen36V2.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutU23Gen36V2,0);
//
//------------PackId = 16; Напряжение между фазами 1-3 генератора 36 вольт №2, Вольт
//
    BSOIOutU13Gen36V2.DevId = 6;

    BSOIOutU13Gen36V2.PackId = 16;

    BSOIOutU13Gen36V2.Data = 33;  // Int

    BSOIOutU13Gen36V2.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutU13Gen36V2,0);
//
//------------PackId = 17; Напряжение между фазами 1-2 генератора 36 вольт №2, Вольт
//
    BSOIOutU12Gen36V2.DevId = 6;

    BSOIOutU12Gen36V2.PackId = 17;

    BSOIOutU12Gen36V2.Data = 34;  // Int

    BSOIOutU12Gen36V2.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutU12Gen36V2,0);
//
//------------PackId = 18; Напряжение фазы A генератора 115 вольт №1, Вольт
//
    BSOIOutUAGen115V1.DevId = 6;

    BSOIOutUAGen115V1.PackId = 18;

    BSOIOutUAGen115V1.Data = 112;  // Int

    BSOIOutUAGen115V1.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutUAGen115V1,0);
//
//------------PackId = 19; Напряжение фазы B генератора 115 вольт №1, Вольт
//
    BSOIOutUBGen115V1.DevId = 6;

    BSOIOutUBGen115V1.PackId = 19;

    BSOIOutUBGen115V1.Data = 113;  // Int

    BSOIOutUBGen115V1.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutUBGen115V1,0);
//
//------------PackId = 20; Напряжение фазы C генератора 115 вольт №1, Вольт
//
    BSOIOutUCGen115V1.DevId = 6;

    BSOIOutUCGen115V1.PackId = 20;

    BSOIOutUCGen115V1.Data = 114;  // Int

    BSOIOutUCGen115V1.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutUCGen115V1,0);
//
//------------PackId = 21; Напряжение фазы A генератора 115 вольт №2, Вольт
//
    BSOIOutUAGen115V2.DevId = 6;

    BSOIOutUAGen115V2.PackId = 21;

    BSOIOutUAGen115V2.Data = 115;  // Int

    BSOIOutUAGen115V2.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutUAGen115V2,0);
//
//------------PackId = 22; Напряжение фазы B генератора 115 вольт №2, Вольт
//
    BSOIOutUBGen115V2.DevId = 6;

    BSOIOutUBGen115V2.PackId = 22;

    BSOIOutUBGen115V2.Data = 116;  // Int

    BSOIOutUBGen115V2.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutUBGen115V2,0);
//
//------------PackId = 23; Напряжение фазы C генератора 115 вольт №2, Вольт
//
    BSOIOutUCGen115V2.DevId = 6;

    BSOIOutUCGen115V2.PackId = 23;

    BSOIOutUCGen115V2.Data = 117;  // Int

    BSOIOutUCGen115V2.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutUCGen115V2,0);
//
//------------PackId = 24; Уровень топлива в левой системе топливных баков, кг
//
    BSOIOutLevFuelLeftTanks.DevId = 6;

    BSOIOutLevFuelLeftTanks.PackId = 24;

    BSOIOutLevFuelLeftTanks.Data = 458; // Int // литры

    BSOIOutLevFuelLeftTanks.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutLevFuelLeftTanks,0);
//
//------------PackId = 25; Уровень топлива в правой системе топливных баков, кг
//
    BSOIOutLevFuelRightTanks.DevId = 6;

    BSOIOutLevFuelRightTanks.PackId = 25;

    BSOIOutLevFuelRightTanks.Data = 475; // Int // литры

    BSOIOutLevFuelRightTanks.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutLevFuelRightTanks,0);
//
//------------PackId = 26; Уровень топлива в концевом топливном баке слева, кг
//
    BSOIOutLevFuelLeftTermTanks.DevId = 6;

    BSOIOutLevFuelLeftTermTanks.PackId = 26;

    BSOIOutLevFuelLeftTermTanks.Data = 125; // Int // литры

    BSOIOutLevFuelLeftTermTanks.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutLevFuelLeftTermTanks,0);
//
//------------PackId = 27; Уровень топлива в концевом топливном баке справа, кг
//
    BSOIOutLevFuelRightTermTanks.DevId = 6;

    BSOIOutLevFuelRightTermTanks.PackId = 27;

    BSOIOutLevFuelRightTermTanks.Data = 148; // Int // литры

    BSOIOutLevFuelRightTermTanks.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutLevFuelRightTermTanks,0);
//
//------------PackId = 28; Давление топлива левой системы, МПа
//
    BSOIOutPFuelLeft.DevId = 6;

    BSOIOutPFuelLeft.PackId = 28;

    BSOIOutPFuelLeft.Data = 0.65; // Float

    BSOIOutPFuelLeft.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutPFuelLeft,1);
//
//------------PackId = 29; Давление масла левой системы, МПа
//
    BSOIOutPOilLeft.DevId = 6;

    BSOIOutPOilLeft.PackId = 29;

    BSOIOutPOilLeft.Data = 0.32; // Float

    BSOIOutPOilLeft.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutPOilLeft,1);
//
//------------PackId = 30; Температура масла левой системы, градус Цельсия
//
    BSOIOutTOilLeft.DevId = 6;

    BSOIOutTOilLeft.PackId = 30;

    BSOIOutTOilLeft.Data = 86; // Int

    BSOIOutTOilLeft.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutTOilLeft,0);
//
//------------PackId = 31; Давление топлива правой системы, МПа
//
    BSOIOutPFuelRight.DevId = 6;

    BSOIOutPFuelRight.PackId = 31;

    BSOIOutPFuelRight.Data = 0.78; // Float

    BSOIOutPFuelRight.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutPFuelRight,1);
//
//------------PackId = 32; Давление масла правой системы, МПа
//
    BSOIOutPOilRight.DevId = 6;

    BSOIOutPOilRight.PackId = 32;

    BSOIOutPOilRight.Data = 0.28; // Float

    BSOIOutPOilRight.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutPOilRight,1);
//
//------------PackId = 33; Температура масла правой системы, градус Цельсия
//
    BSOIOutTOilRight.DevId = 6;

    BSOIOutTOilRight.PackId = 33;

    BSOIOutTOilRight.Data = 95; // Int

    BSOIOutTOilRight.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutTOilRight,0);
//
//------------PackId = 34; Расход топлива левого двигателя, кг/ч
//
    BSOIOutConsFuelLeft.DevId = 6;

    BSOIOutConsFuelLeft.PackId = 34;

    BSOIOutConsFuelLeft.Data = 205; // Int // литры / час

    BSOIOutConsFuelLeft.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutConsFuelLeft,0);
//
//------------PackId = 35; Расход топлива правого двигателя, кг/ч
//
    BSOIOutConsFuelRight.DevId = 6;

    BSOIOutConsFuelRight.PackId = 35;

    BSOIOutConsFuelRight.Data = 185; // Int // литры / час

    BSOIOutConsFuelRight.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutConsFuelRight,0);
//
//------------PackId = 36; Давление гидравлической жидкости в основном контуре постоянного давления, МПа
//
    BSOIOutPGydroMain.DevId = 6;

    BSOIOutPGydroMain.PackId = 36;

    BSOIOutPGydroMain.Data = 14.5; // Float

    BSOIOutPGydroMain.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutPGydroMain,1);
//
//------------PackId = 37; Давление гидравлической жидкости в контуре тормозов, МПа
//
    BSOIOutPGydroBrake.DevId = 6;

    BSOIOutPGydroBrake.PackId = 37;

    BSOIOutPGydroBrake.Data = 12.6; // Float

    BSOIOutPGydroBrake.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutPGydroBrake,1);
//
//------------PackId = 40; Угол отклонения руля высоты, [-30..14], градусы (вверх - минус, вниз - плюс)
//
    BSOIOutElevatorAngle.DevId = 6;

    BSOIOutElevatorAngle.PackId = 40;

    BSOIOutElevatorAngle.Data = 10.5; // Float

    BSOIOutElevatorAngle.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutElevatorAngle,1);
//
//------------PackId = 41; Угол отклонения элеронов, [-27..14], градусы (вверх - минус, вниз - плюс)
//
    BSOIOutAileronAngle.DevId = 6;

    BSOIOutAileronAngle.PackId = 41;

    BSOIOutAileronAngle.Data = 5.8; // Float

    BSOIOutAileronAngle.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutAileronAngle,1);
//
//------------PackId = 42; Угол отклонения руля направления, [-17..17], градусы (направо - минус, налево - плюс)
//
    BSOIOutRudderAngle.DevId = 6;

    BSOIOutRudderAngle.PackId = 42;

    BSOIOutRudderAngle.Data = 12.4; // Float

    BSOIOutRudderAngle.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutRudderAngle,1);
//
//------------PackId = 43; Угол отклонения триммера руля направления, [-10..10], градусы (направо - минус, налево - плюс)
//
    BSOIOutTrimmerRudder.DevId = 6;

    BSOIOutTrimmerRudder.PackId = 43;

    BSOIOutTrimmerRudder.Data = -4.6; // Float

    BSOIOutTrimmerRudder.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutTrimmerRudder,1);
//
//------------PackId = 44; Положение РУД левого двигателя, %
//
    BSOIOutRUDLeft.DevId = 6;

    BSOIOutRUDLeft.PackId = 44;

    BSOIOutRUDLeft.Data = 25; // Int

    BSOIOutRUDLeft.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutRUDLeft,0);
//
//------------PackId = 45; Положение РУД правого двигателя, %
//
    BSOIOutRUDRight.DevId = 6;

    BSOIOutRUDRight.PackId = 45;

    BSOIOutRUDRight.Data = 36; // Int

    BSOIOutRUDRight.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutRUDRight,0);
//
//------------PackId = 46; Крутящий момент левого двигателя, %
//
    BSOIOutTorqLeft.DevId = 6;

    BSOIOutTorqLeft.PackId = 46;

    BSOIOutTorqLeft.Data = 68; // Int

    BSOIOutTorqLeft.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutTorqLeft,0);
//
//------------PackId = 47; Крутящий момент правого двигателя, %
//
    BSOIOutTorqRight.DevId = 6;

    BSOIOutTorqRight.PackId = 47;

    BSOIOutTorqRight.Data = 78; // Int

    BSOIOutTorqRight.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutTorqRight,0);
//
//------------PackId = 48; Давление в контуре стояночного тормоза, МПа
//
    BSOIOutPGydroParkBrake.DevId = 6;

    BSOIOutPGydroParkBrake.PackId = 48;

    BSOIOutPGydroParkBrake.Data = 4.6; // Float

    BSOIOutPGydroParkBrake.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutPGydroParkBrake,1);
//
//------------PackId = 49; Давление в левой гидравлической системе тормозов, МПа
//
    BSOIOutPGydroBrakeLeft.DevId = 6;

    BSOIOutPGydroBrakeLeft.PackId = 49;

    BSOIOutPGydroBrakeLeft.Data = 3.8; // Float

    BSOIOutPGydroBrakeLeft.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutPGydroBrakeLeft,1);
//
//------------PackId = 50; Давление в правой гидравлической системе тормозов, МПа
//
    BSOIOutPGydroBrakeRight.DevId = 6;

    BSOIOutPGydroBrakeRight.PackId = 50;

    BSOIOutPGydroBrakeRight.Data = 4.7; // Float

    BSOIOutPGydroBrakeRight.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutPGydroBrakeRight,1);
//
//------------PackId = 51; Обороты воздушного винта левого двигателя, об/мин
//
    BSOIOutNLeft.DevId = 6;

    BSOIOutNLeft.PackId = 51;

    BSOIOutNLeft.Data = 1550; // Int

    BSOIOutNLeft.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutNLeft,0);
//
//------------PackId = 52; Обороты воздушного винта правого двигателя, об/мин
//
    BSOIOutNRight.DevId = 6;

    BSOIOutNRight.PackId = 52;

    BSOIOutNRight.Data = 1780; // Int

    BSOIOutNRight.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutNRight,0);
//
//------------PackId = 53; Обороты газогенератора левого двигателя, %
//
    BSOIOutNGasGenLeft.DevId = 6;

    BSOIOutNGasGenLeft.PackId = 53;

    BSOIOutNGasGenLeft.Data = 89; // Int

    BSOIOutNGasGenLeft.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutNGasGenLeft,0);
//
//------------PackId = 54; Обороты газогенератора правого двигателя, %
//
    BSOIOutNGasGenRight.DevId = 6;

    BSOIOutNGasGenRight.PackId = 54;

    BSOIOutNGasGenRight.Data = 93; // Int

    BSOIOutNGasGenRight.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutNGasGenRight,0);
//
//------------PackId = 55; Температура между турбиной газогенератора и турбиной воздушного винта левого двигателя, градус
//
    BSOIOutTTurbLeft.DevId = 6;

    BSOIOutTTurbLeft.PackId = 55;

    BSOIOutTTurbLeft.Data = 567; // Int

    BSOIOutTTurbLeft.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutTTurbLeft,0);
//
//------------PackId = 56; Температура между турбиной газогенератора и турбиной воздушного винта правого двигателя, градус
//
    BSOIOutTTurbRight.DevId = 6;

    BSOIOutTTurbRight.PackId = 56;

    BSOIOutTTurbRight.Data = 678; // Int

    BSOIOutTTurbRight.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutTTurbRight,0);
//
//    BSOIOutIntStruct BSOIOutUoporPot; // PackId = 57; Опорное напряжение для датчиков на основе потенциометров и термосопротивлений, вольт
//    BSOIOutIntStruct BSOIOutUoporFuelLeftTanks; // PackId = 58; Опорное напряжение для датчика уровня топлива в левой системе топливных баков, вольт
//    BSOIOutIntStruct BSOIOutUoporFuelRightTanks; // PackId = 59; Опорное напряжение для датчика уровня топлива в правой системе топливных баков, вольт
//    BSOIOutIntStruct BSOIOutUoporFuelLeftTerm; // PackId = 60; Опорное напряжение для датчика уровня топлива в левом концевом баке, вольт
//    BSOIOutIntStruct BSOIOutUoporFuelRightTerm; // PackId = 61; Опорное напряжение для датчика уровня топлива в правом концевом баке, вольт
//    BSOIOutIntStruct BSOIOutUoporPFuelLeft; // PackId = 62; Опорное напряжение для датчика давления топлива левой группы, вольт
//    BSOIOutIntStruct BSOIOutUoporPOilLeft; // PackId = 63; Опорное напряжение для датчика давления масла левой группы, вольт
//    BSOIOutIntStruct BSOIOutUoporPFuelRight; // PackId = 64; Опорное напряжение для датчика давления топлива правой группы, вольт
//    BSOIOutIntStruct BSOIOutUoporPOilRight; // PackId = 65; Опорное напряжение для датчика давления масла правой группы, вольт
//    BSOIOutIntStruct BSOIOutUoporPGydroMain; // PackId = 66; Опорное напряжение для датчика давления гидравлической жидкости в основном контуре, вольт
//    BSOIOutIntStruct BSOIOutUoporPGydroBreak; // PackId = 67; Опорное напряжение для датчика давления гидравлической жидкости в контуре тормозов, вольт
//
//------------PackId = 85; Крутящий момент левого двигателя, %
//
    BSOIOutTorqLeft_.DevId = 6;

    BSOIOutTorqLeft_.PackId = 85;

    BSOIOutTorqLeft_.Data = 54; // Int

    BSOIOutTorqLeft_.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutTorqLeft_,0);
//
//------------PackId = 86; Крутящий момент правого двигателя, %
//
    BSOIOutTorqRight_.DevId = 6;

    BSOIOutTorqRight_.PackId = 86;

    BSOIOutTorqRight_.Data = 69; // Int

    BSOIOutTorqRight_.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutTorqRight_,0);
//
//------------PackId = 68; Угол атаки 1, [-30..30], градусы
//
    BSOIOutAttackAngle1.DevId = 6;

    BSOIOutAttackAngle1.PackId = 68;

    BSOIOutAttackAngle1.Data = 10.6; // Float

    BSOIOutAttackAngle1.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutAttackAngle1,1);
//
//------------PackId = 75; Угол атаки 2, [-30..30], градусы
//
    BSOIOutAttackAngle2.DevId = 6;

    BSOIOutAttackAngle2.PackId = 75;

    BSOIOutAttackAngle2.Data = 10.6; // Float

    BSOIOutAttackAngle2.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutAttackAngle2,1);
//
//------------PackId = 76; Давление огнетушителя багажного отсека [0..1.6], МПа
//
    BSOIOutPBFireExt.DevId = 6;

    BSOIOutPBFireExt.PackId = 76;

    BSOIOutPBFireExt.Data = 1.2; // Float

    BSOIOutPBFireExt.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutPBFireExt,1);
//
//------------PackId = 77; Триммер руля высоты [-10..10], градусы
//
    BSOIOutTrimmerElev.DevId = 6;

    BSOIOutTrimmerElev.PackId = 77;

    BSOIOutTrimmerElev.Data = 5.6; // Float

    BSOIOutTrimmerElev.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutTrimmerElev,1);
//
//------------PackId = 78; Триммер элеронов [-10..10], градусы
//
    BSOIOutTrimmerAiler.DevId = 6;

    BSOIOutTrimmerAiler.PackId = 78;

    BSOIOutTrimmerAiler.Data = -8.4; // Float

    BSOIOutTrimmerAiler.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutTrimmerAiler,1);
//
//------------PackId = 81; Обороты газогенератора левого двигателя (постоянное напряжение), %
//
    BSOIOutNGasGenLeftU.DevId = 6;

    BSOIOutNGasGenLeftU.PackId = 81;

    BSOIOutNGasGenLeftU.Data = 60; // Int

    BSOIOutNGasGenLeftU.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutNGasGenLeftU,0);
//
//------------PackId = 82; Обороты газогенератора правого двигателя (постоянное напряжение), %
//
    BSOIOutNGasGenRightU.DevId = 6;

    BSOIOutNGasGenRightU.PackId = 82;

    BSOIOutNGasGenRightU.Data = 80; // Int

    BSOIOutNGasGenRightU.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutNGasGenRightU,0);
//
//------------PackId = 83; Уровень топлива в дополнительном топливном баке, л
//
    BSOIOutFuelLevAddTank.DevId = 6;

    BSOIOutFuelLevAddTank.PackId = 83;

    BSOIOutFuelLevAddTank.Data = 59; // Int

    BSOIOutFuelLevAddTank.Matrix = 0;
//-------
    UpdateSendBSOIData(&BSOIOutFuelLevAddTank,0);
//
//------------PackId = 69; Дискретные сигналы 1 (Структура РК1)
//
    BSOIOutRK1.DevId = 6;

    BSOIOutRK1.PackId = 69;
//-------
    BSOIOutRK1.GearOnGround = 1;
//-------
    BSOIOutRK1.US2B = 1; // Наличие напряжение на шине S2B

    BSOIOutRK1.US3B = 1; // Наличие напряжение на шине S3B

    BSOIOutRK1.US1B = 1; // Наличие напряжение на шине S1B
//-------
    BSOIOutRK1._U28V1 = 1; // Отсутствие выходного напряжения преобразователя 26V №1

    BSOIOutRK1._U28V2 = 1; // Отсутствие выходного напряжения преобразователя 26V №2
//-------
    BSOIOutRK1._U36V1 = 1; // Отсутствие выходного напряжения преобразователя 36V №1

    BSOIOutRK1._U36V2 = 1; // Отсутствие выходного напряжения преобразователя 36V №2
//-------
    BSOIOutRK1.Bell = 0; // Вызов экипажа
//-------
    BSOIOutRK1.FireLeftEng = 1; // Пожар левого двигателя

    BSOIOutRK1.FireRightEng = 1; // Пожар правого двигателя

    BSOIOutRK1.FireFrontBaggage = 1; // Пожар переднего багажного отсека
//-------
    BSOIOutRK1.Interceptor = 1; // Выпущены интерцепторы
//-------
    BSOIOutRK1.Matrix = 0;
//-------
    SendPNS_1->UpdateSendData(&BSOIOutRK1, sizeof(BSOIOutRK1Struct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&BSOIOutRK1, sizeof(BSOIOutRK1Struct) , arinc_rpkb_in);
//
//------------PackId = 70; Дискретные сигналы 2 (Структура РК2)
//
    BSOIOutRK2.DevId = 6;

    BSOIOutRK2.PackId = 70;
//-------
    BSOIOutRK2.Flaps0 = 0; // Закрылки положение 0

    BSOIOutRK2.Flaps18 = 1; // Закрылки положение 18

    BSOIOutRK2.Flaps42 = 0; // Закрылки положение 42

    BSOIOutRK2.FlapsTo18 = 1; // Выпусти закрылки положение 18
//-------
    BSOIOutRK2.ReadyAUK = 1; // Готовность АУК

    BSOIOutRK2.AUKShield = 1; // Выпущен щит АУК
//-------
    BSOIOutRK2.PFuelLeftLow = 1; // Давление топлива в левом двигателе низкое

    BSOIOutRK2.PFuelRightLow = 1; // Давление топлива в правом двигателе низкое
//-------
    BSOIOutRK2.LevFuelLeftLow = 1; // Низкий уровень топлива левой системы топливных баков

    BSOIOutRK2.LevFuelRightLow = 1; // Низкий уровень топлива правой системы топливных баков
//-------
    BSOIOutRK2.FuelCircle = 1; // Включено кольцевание топлива
//-------
    BSOIOutRK2.FuelPumpLeftTermTank = 1; // Включена перекачка топлива из левого концевого бака

    BSOIOutRK2.FuelPumpRightTermTank = 1; // Включена перекачка топлива из правого концевого бака
//-------
    BSOIOutRK2.FuelPumpLeftTank = 1; // Включи перекачку топлива в левую систему топливных баков

    BSOIOutRK2.FuelPumpRightTank = 1; // Включи перекачку топлива в правую систему топливных баков
//-------
    BSOIOutRK2.ByPassFuelFilterLeft = 1; // Открытие обходного предохранительного клапана топливного фильтра левой системы
//-------
    BSOIOutRK2.Matrix = 0;
//-------
    SendPNS_1->UpdateSendData(&BSOIOutRK2, sizeof(BSOIOutRK2Struct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&BSOIOutRK2, sizeof(BSOIOutRK2Struct) , arinc_rpkb_in);
//
//------------PackId = 71; Дискретные сигналы 3 (Структура РК3)
//
    BSOIOutRK3.DevId = 6;

    BSOIOutRK3.PackId = 71;
//-------
    BSOIOutRK3.ByPassFuelFilterRight = 1; // Открытие обходного предохранительного клапана топливного фильтра правой системы
//-------
    BSOIOutRK3.TPumpBackLeft90 = 1; // Температура жидкости в обратном контуре насосов левой системы превышает 90 градусов

    BSOIOutRK3.TPumpBackRight90 = 1; // Температура жидкости в обратном контуре насосов правой системы превышает 90 градусов
//-------
    BSOIOutRK3.Icing = 1; // Обледенение
//-------
    BSOIOutRK3.OpenSepIceLeft = 1; // Открыты левые створки сепараторов льда

    BSOIOutRK3.OpenSepIceRight = 1; // Открыты правые створки сепараторов льда
//-------
    BSOIOutRK3.HeatPSN = 1; // Включен обогрев ПСН

    BSOIOutRK3.HeatPSD1 = 1; // Включен обогрев приемника статического давления I

    BSOIOutRK3.HeatPSD2 = 1; // Включен обогрев приемника статического давления II

    BSOIOutRK3.HeatPPD1 = 1; // Включен обогрев приемника полного давления I

    BSOIOutRK3.HeatPPD2 = 1; // Включен обогрев приемника полного давления II
//-------
    BSOIOutRK3.HeatGlassLeft = 1; // Включен обогрев стекол слева

    BSOIOutRK3.HeatGlassRight = 1; // Включен обогрев стекол справа
//-------
    BSOIOutRK3.FaultDeIcePropLeft = 1; // Отказ ПОС левого воздушного винта

    BSOIOutRK3.FaultDeIcePropRight = 1; // Отказ ПОС правого воздушного винта
//-------
    BSOIOutRK3.LeftGearOn = 1; // Левое шасси выпущено
//-------
    BSOIOutRK3.Matrix = 0;
//-------
    SendPNS_1->UpdateSendData(&BSOIOutRK3, sizeof(BSOIOutRK3Struct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&BSOIOutRK3, sizeof(BSOIOutRK3Struct) , arinc_rpkb_in);
//
//------------PackId = 72; Дискретные сигналы 4 (Структура РК4)
//
    BSOIOutRK4.DevId = 6;

    BSOIOutRK4.PackId = 72;
//-------
    BSOIOutRK4.FrontGearOn = 1; // Переднее шасси выпущено

    BSOIOutRK4.RightGearOn = 1; // Правое шасси выпущено
//-------
    BSOIOutRK4.PropRestLeft = 1; // Упор винта левый

    BSOIOutRK4.PropRestRight = 1; // Упор винта правый
//-------
    BSOIOutRK4.GearOn = 1; // Выпусти шасси
//-------
    BSOIOutRK4.ABSGearLeft = 1; // Срабатывание антиблокировочной системы левого шасси

    BSOIOutRK4.ABSGearRight = 1; // Срабатывание антиблокировочной системы правого шасси
//-------
    BSOIOutRK4.Stall = 1; // Сваливание
//-------
    BSOIOutRK4.AddVanePumpLeftOn = 1; // Включен вспомогательный флюгерный насос левого двигателя

    BSOIOutRK4.AddVanePumpRightOn = 1; // Включен вспомогательный флюгерный насос правого двигателя
//-------
    BSOIOutRK4.AutoVaneLeft = 1; // Автоматическое флюгирование левого двигателя

    BSOIOutRK4.AutoVaneRight = 1; // Автоматическое флюгирование правого двигателя
//-------
    BSOIOutRK4.DiapBLeft = 1; // Диапазон B левого двигателя

    BSOIOutRK4.DiapBRight = 1; // Диапазон B правого двигателя
//-------
    BSOIOutRK4.Matrix = 0;
//-------
    SendPNS_1->UpdateSendData(&BSOIOutRK4, sizeof(BSOIOutRK4Struct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&BSOIOutRK4, sizeof(BSOIOutRK4Struct) , arinc_rpkb_in);
//
//------------PackId = 73; Дискретные сигналы 5 (Структура РК5)
//
    BSOIOutRK5.DevId = 6;

    BSOIOutRK5.PackId = 73;
//-------
    BSOIOutRK5.ECULeft = 1; // Готовность ЭБО левого двигателя

    BSOIOutRK5.ECURight = 1; // Готовность ЭБО правого двигателя
//-------
    BSOIOutRK5._UACLeft = 1; // Отсутствие выходного напряжения генератора переменного тока левого

    BSOIOutRK5._UACRight = 1; // Отсутствие выходного напряжения генератора переменного тока правого
//-------
    BSOIOutRK5._UDCLeft = 1; // Отсутствие выходного напряжения генератора постоянного тока левого

    BSOIOutRK5._UDCRight = 1; // Отсутствие выходного напряжения генератора постоянного тока правого
//-------
    BSOIOutRK5.EngineEmergLeft = 1; // Включена система управления аварийным режимом левого двигателя при помощи рычагов управления стоп-кранами

    BSOIOutRK5.EngineEmergRight = 1; // Включена система управления аварийным режимом правого двигателя при помощи рычагов управления стоп-кранами
//-------
    BSOIOutRK5.POilLowLeft = 1; // Низкое давление масла в левом двигателе

    BSOIOutRK5.POilLowRight = 1; // Низкое давление масла в правом двигателе
//-------
    BSOIOutRK5.ChipInOilLeft = 1; // Наличие стружки в левом маслобаке

    BSOIOutRK5.ChipInOilRight = 1; // Наличие стружки в правом маслобаке
//-------
    BSOIOutRK5.EngineStart = 1; // Запуск двигателей
//-------
    BSOIOutRK5.EngineParamsExceedLeft = 1; // Превышение параметров левого двигателя

    BSOIOutRK5.EngineParamsExceedRight = 1; // Превышение параметров правого двигателя
//-------
    BSOIOutRK5.OilBypassOpenRight = 1; // Открыт предохранительный клапан масляной системы правого двигателя
//-------
    BSOIOutRK5.Matrix = 0;
//-------
    SendPNS_1->UpdateSendData(&BSOIOutRK5, sizeof(BSOIOutRK5Struct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&BSOIOutRK5, sizeof(BSOIOutRK5Struct) , arinc_rpkb_in);
//
//------------PackId = 74; Дискретные сигналы 6 (Структура РК6)
//
    BSOIOutRK6.DevId = 6;

    BSOIOutRK6.PackId = 74;
//-------
    BSOIOutRK6.OilBypassOpenLeft = 1; // Открыт предохранительный клапан масляной системы левого двигателя
//-------
    BSOIOutRK6.TaxiLightOn = 1; // Включены рулежные фары

    BSOIOutRK6.LandingLightOn = 1; // Включены посадочные фары
//-------
    BSOIOutRK6.HandContrFrontWheel = 1; // Задействовано ручное управление передним колесом

    BSOIOutRK6.FootContrFrontWheel = 1; // Задействовано ножное управление передним колесом
//-------
    BSOIOutRK6.BattFault = 1; // Отказ аккумулятора
//-------
    BSOIOutRK6.Batt1Overheat = 1; // Перегрев аккумулятора №1

    BSOIOutRK6.Batt2Overheat = 1; // Перегрев аккумулятора №2
//-------
    BSOIOutRK6.DoorOpen = 1; // Дверь открыта
//-------
    BSOIOutRK6.GroundPower = 1; // Аэродромное питание
//-------
    BSOIOutRK6.TestPanelButt = 1; // Нажата кнопка тестирования табло сигнализации
//-------
    BSOIOutRK6.GearL = 1; // Левое шасси в процессе выпуска/уборки

    BSOIOutRK6.GearF = 1; // Правое шасси в процессе выпуска/уборки

    BSOIOutRK6.GearR = 1; // Правое шасси в процессе выпуска/уборки
//-------
    BSOIOutRK6.Matrix = 0;
//-------
    SendPNS_1->UpdateSendData(&BSOIOutRK6, sizeof(BSOIOutRK6Struct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&BSOIOutRK6, sizeof(BSOIOutRK6Struct) , arinc_rpkb_in);
//
//------------PackId = 79; Дискретные сигналы 7 (Структура РК7)
//
    BSOIOutRK7.DevId = 6;

    BSOIOutRK7.PackId = 79;
//-------
    BSOIOutRK7.DeIceA = 1; // Работа противообледенительной системы А

    BSOIOutRK7.DeIceB = 1; // Работа противообледенительной системы B

    BSOIOutRK7.DeIceC = 1; // Работа противообледенительной системы C
//-------
    BSOIOutRK7.OGOGood = 1; // Исправность ответчика ГО

    BSOIOutRK7.OGOFault = 0; // Отказ ответчика ГО
//-------
    BSOIOutRK7.OilLevMinL = 1; // Уровень масла левого минимальный

    BSOIOutRK7.OilLevMinR = 1; // Уровень масла правого минимальный
//-------
    BSOIOutRK7.MaxTempEngL = 1; // Максимальная температура левого двигателя

    BSOIOutRK7.MaxTempEngR = 1; // Максимальная температура правого двигателя
//-------
    BSOIOutRK7.RegOn = 1; // Регистратор включен
//-------
    BSOIOutRK7.TangentaOn = 1; // Нажатие тангенты радиосвязи
//-------
    BSOIOutRK7.ESGO115 = 1; // Наличие 115 вольт 400Гц ЕСГО
//-------
    BSOIOutRK7.FireTestOn = 1; // Нажата кнопка тестирования датчиков пожара
//-------
    BSOIOutRK7.ESGOResInd = 1; // Индикатор запасной ЕСГО
//-------
    BSOIOutRK7.FuelAddTankMin = 1; // Минимальный уровень топлива в дополнительном баке
//-------
    BSOIOutRK7.FuelPumpAddTankOn = 1; // Включен насос топлива в дополнительном баке
//-------
    BSOIOutRK7.Matrix = 0;
//-------
    BSOIOutRK7.Reserv = 14; // Резерв
//-------
    SendPNS_1->UpdateSendData(&BSOIOutRK7, sizeof(BSOIOutRK7Struct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&BSOIOutRK7, sizeof(BSOIOutRK7Struct) , arinc_rpkb_in);
//
//------------PackId = 84; Дискретные сигналы 8 (Структура РК8)
//
    BSOIOutRK8.DevId = 6;

    BSOIOutRK8.PackId = 84;
//-------
    BSOIOutRK8.SNOCOpen = 0; // Открытие створки СНОЦ/ВЕЕР 1

    BSOIOutRK8.SNOCClose = 1; // Закрытие створки СНОЦ/ВЕЕР 2
//-------
    BSOIOutRK8.UltraOpen = 0; // Открытие створки Ultra-Cam 1

    BSOIOutRK8.UltraClose = 1; // Закрытие створки Ultra-Cam 2
//-------
    BSOIOutRK8.Matrix = 0;
//-------
    BSOIOutRK8.Reserv = 10; // Резерв
//-------
    SendPNS_1->UpdateSendData(&BSOIOutRK8, sizeof(BSOIOutRK8Struct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&BSOIOutRK8, sizeof(BSOIOutRK8Struct) , arinc_rpkb_in);
//m_1:
//
//------------PackId = 80; Слово состояния БСОИ (Слово состояния БСОИ)
//
    BSOIOutCW.DevId = 6;

    BSOIOutCW.PackId = 80;
//-------
    BSOIOutCW.FaultBSOI = 0; // Отказ БСОИ

    BSOIOutCW.FaultUU = 0; // Отказ УУ

    BSOIOutCW.FaultDPK = 0; // Отказ ДПК

    BSOIOutCW.FaultRK = 0; // Отказ РК

    BSOIOutCW.FaultMAC2 = 0; // Отказ МАК2

    BSOIOutCW.FaultMAC1 = 0; // Отказ МАК1

    BSOIOutCW.Matrix = 0;
//-------
    SendPNS_1->UpdateSendData(&BSOIOutCW, sizeof(BSOIOutCWStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(&BSOIOutCW, sizeof(BSOIOutCWStruct) , arinc_rpkb_in);
//-------
}
//---------------------------------------------------------------------------

void DispL410::UpdateSendBSOIData(void* dataDest, int StructType)
{
    switch(StructType)
    {
    case 0:
    SendPNS_1->UpdateSendData(dataDest, sizeof(BSOIOutIntStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(dataDest, sizeof(BSOIOutIntStruct) , arinc_rpkb_in);
    break;
    case 1:
    SendPNS_1->UpdateSendData(dataDest, sizeof(BSOIOutFloatStruct) , arinc_rpkb_in);

    SendPNS_2->UpdateSendData(dataDest, sizeof(BSOIOutFloatStruct) , arinc_rpkb_in);
    break;
    }
//-------
}
//---------------------------------------------------------------------------




void DispL410:: WriteFromPNS()
{


}// void DispL410:: WriteFromPNS()



float ControlMinMaxF(float arg,bool & bZn,float  D ,float min,float  max)
{
    float rez=0.0;
    if(bZn)
    {
        arg+=D;
        if(arg<max)
        {
            rez=arg;
        }
        else
        {
            rez=max;
            bZn=0;
        }

    }
    else
    {
        arg-=D;
        if(arg>min)
            rez=arg;
        else
        {
            rez=min;
            bZn=1;
        }
    }

    return rez;
}



