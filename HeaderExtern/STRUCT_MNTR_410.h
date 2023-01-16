// "STRUCT_MNTR_410" - memory name
//04.06.2018

#pragma pack(push, 1)

typedef struct
{
//
//------------������� �������------------------------------------------
//
double AERODROM_ALTITUDE[3];

double AERODROM_TEMP_CELS[3];

double AERODROM_TEMP_KELVIN[3];

double AERODROM_PRES_HG[3];

double AERODROM_PRES_PA[3];

double AERODROM_AIRDENSITY[3];
//-------
double SEA_LEVEL_TEMP_CELS;

double SEA_LEVEL_TEMP_KELVIN;

double SEA_LEVEL_PRES_PA;

double SEA_LEVEL_PRES_HG;

double SEA_LEVEL_AIRDENSITY;
//-------
double GRVT;

double AIR_TEMP_KELVIN;

double AIR_TEMP_CELS;

double AIR_PRES_PA;

double AIR_PRES_HG;

double AIR_PRES_KGS_CM2;

double BARO_ALTITUDE;

double AIR_VISCOUS;

double AIR_AIRDENSITY;

double SOUND_VELOSITY;

double BRAKED_FLOW_TEMP_KELVIN;
//
//------------���������� ������� �������-------------------------------
//
double U_CONTROL_STICK; // ����������� �������

double U_STEERING_WHEEL; // �������

double U_PEDAL; // ������

double U_PILOT_BRAKE_PEDAL_LEFT; //����� �������� ������ ������
double U_PILOT_BRAKE_PEDAL_RIGHT; //������ �������� ������ ������

double U_CO_PILOT_BRAKE_PEDAL_LEFT; //����� �������� ������� ������
double U_CO_PILOT_BRAKE_PEDAL_RIGHT; //������ �������� ������� ������

double U_ELEVATOR_TRIM_HAND_WHEEL; // ������� ���� ������

double U_NOSE_LANDING_GEAR_STEERING_WHEEL; //�������� �������� ������

double U_EMERGENCY_HYDRAULIC_PUMP_LEVER; //������ �����
//
//------------����������� �����----------------------------------------
//
double U_THROTTLE_CONTROL_LEVER_LEFT; //��� �����
double U_THROTTLE_CONTROL_LEVER_RIGHT; //��� ������

double U_PROPELLER_CONTROL_LEVER_LEFT; //��� �����
double U_PROPELLER_CONTROL_LEVER_RIGHT; //��� ������

double U_EMERGENCY_THROTTLE_LEVER_LEFT; //����-���� �����
double U_EMERGENCY_THROTTLE_LEVER_RIGHT; //����-���� ������
//
//------------�����������----------------------------------------------
//
double U_FORCE_PEDAL; //����������� �������

double U_FORCE_CONTROL_STICK; //����������� ����������� �������

double U_FORCE_STEERING_WHEEL; //����������� ��������

double U_FORCE_ELEVATOR_TRIM; //������� ���� ������
//
//------------���������� ������� �������------------------------------
//
//
//------------���������� �������� �������------------------------------
//
//
//------------������ ����������----------------------------------------
//
double DRV;				        //  elevator, grad
double CONTROL_STICK_POSITION;  //  ����������� �������, ��

double DEL_LEFT;			  // aileron left, grad
double DEL_RIGHT;			  // aileron right, grad
double STEERING_WHEEL_ANGLE;  // ���� �������� ��������, ����

double DRN;				      //  rudder, grad
double PEDAL_LEFT_POSITION;   // ��������� �������, ��

double LEFT_PULT_TOE_ANGLE_LEFT;     // ���� �������� ��������� ��������, ����
double LEFT_PULT_TOE_PRESSURE_LEFT;  // �������� �� ��������� ��������, ��/��2

double LEFT_PULT_TOE_ANGLE_RIGHT;
double LEFT_PULT_TOE_PRESSURE_RIGHT;

double RIGHT_PULT_TOE_ANGLE_LEFT;
double RIGHT_PULT_TOE_PRESSURE_LEFT;

double RIGHT_PULT_TOE_ANGLE_RIGHT;
double RIGHT_PULT_TOE_PRESSURE_RIGHT;

double  WING_FLAPS_ANGLE;	//  zakrilki
double  SPOILER_ANGLE;		//  interseptor
double  SCHT_ANGLE;			//  shitok avtomat kren

double NOSE_LANDING_GEAR_STEERING_WHEEL_ANGLE;
double FI_NOSE_WHEEL;             //  angle nos koleso

double DSHAS_NOSE;
double DSHAS_LEFT;
double DSHAS_RIGHT;

double EMERGENCY_HYDRAULIC_PUMP_LEVER_ANGLE;
//
//------------
double AL_RUD_LEFT;
double AL_RUD_RIGHT;

double AL_RUB_LEFT;			     //rihag upravl vint left
double AL_RUB_RIGHT;			     //rihag upravl vint r

double AL_STOP_LEFT;			     //angle upravl stop-kran l
double AL_STOP_RIGHT;		     //angle upravl stop-kran r
//
//------------������� ��-----------------------------------------------
//
double ELEVATOR_TRIM_HAND_WHEEL_ANGLE;

double ELEVATOR_TRIM_ANGLE;	     //trimer rul H

double D_ELEVATOR_TRIM;
//
//------------
double AILERON_TRIM_ANGLE;	     //trimer eleron

double RUDDER_TRIM_ANGLE;	     //trimer rul napravlen
//
//------------����������� ��-------------------------------------------
//
double CONTROL_STICK_FORCE_ZAD;
double ELEVATOR_FORCE_POSITION;
double D_ELEVATOR_FORCE;
double CONTROL_STICK_FORCE;
//
//------------����������� ��-------------------------------------------
//
double FORCE_STEERING_WHEEL_ZAD;
double AILERON_FORCE_POSITION;
double D_AILERON_FORCE;
double STEERING_WHEEL_FORCE;
//
//------------����������� ��-------------------------------------------
//
double FORCE_PEDAL_ZAD;
double RUDDER_FORCE_POSITION;
double D_RUDDER_FORCE;
double PEDAL_FORCE;
//-------
double GENERATOR_RPM_LEFT;        //oborot/min elektro-gen l
double GENERATOR_RPM_RIGHT;       //oborot/min elektro-gen r

double BRAKE_PRESSURE_LEFT;	     //davlen tormoz l
double BRAKE_PRESSURE_RIGHT;	     //davlen tormoz r
//
//------------
double COCKPIT_TEMPERATURE;   // 0+40 grad C  ����������� ������
double CHANNEL_TEMPERATURE;    // 20+120 grad C  ����������� ������
//
//------------
bool ENGINE_STARTED_LEFT; // Priznak raboti dvigatelya (1=yes)
bool ENGINE_STARTED_RIGHT; // Priznak raboti dvigatelya (1=yes)

double ENGINE_NGG_LEFT; // 0+110%
double ENGINE_NGG_RIGHT; // 0+110%

double ENGINE_NGG_ZAD_LEFT; // 0+110%
double ENGINE_NGG_ZAD_RIGHT; // 0+110%

double ENGINE_NE_LEFT; // ���
double ENGINE_NE_RIGHT; // ���

double ENGINE_GT_LEFT;
double ENGINE_GT_RIGHT;

double ENGINE_TGZ_LEFT;         // 0+900 ���� C
double ENGINE_TGZ_RIGHT;         // 0+900 ���� C

double ENGINE_MKR_LEFT; // �������� ������ H*m
double ENGINE_MKR_RIGHT; // �������� ������ H*m

double ENGINE_MKR_PERCENT_LEFT; // 0+120% Mk �������� ������
double ENGINE_MKR_PERCENT_RIGHT; // 0+120% Mk �������� ������
//
//------------����-----------------------------------------------------
//
double ENGINE_NBB_LEFT;    // 0+2400 �������/���
double ENGINE_NBB_RIGHT;    // 0+2400 �������/���

double ENGINE_NBB_ZAD_LEFT;    // 0+2400 �������/���
double ENGINE_NBB_ZAD_RIGHT;    // 0+2400 �������/���

double ENGINE_FIBB_LEFT;    // -25+80 ���� ��������� ��������
double ENGINE_FIBB_RIGHT;   // -25+80 ���� ��������� ��������

double ENGINE_MKRBB_LEFT; // �������� ������ ����� H*m
double ENGINE_MKRBB_RIGHT; // �������� ������ ����� H*m

double ENGINE_MKRBB_PERCENT_LEFT; // 0+120% Mk �������� ������ �����
double ENGINE_MKRBB_PERCENT_RIGHT; // 0+120% Mk �������� ������ �����

double ENGINE_NEBB_LEFT; // ���
double ENGINE_NEBB_RIGHT; // ���

double ENGINE_PBB_LEFT;    // ���� ����� ������ ��
double ENGINE_PBB_RIGHT;   // ���� ����� ������� ��

double ENGINE_PREACT_LEFT;    // ���� ����� ������ ��
double ENGINE_PREACT_RIGHT;   // ���� ����� ������� ��
//
//-------
double ENGINE_FUEL_PRESSURE_LEFT; // 0+16 ��/��2     // �������� �������
double ENGINE_FUEL_PRESSURE_RIGHT; // 0+16 ��/��2     // �������� �������

double ENGINE_OIL_PRESSURE_LEFT;  // 0+4 ��/��2      // �������� �����
double ENGINE_OIL_PRESSURE_RIGHT;  // 0+4 ��/��2      // �������� �����

double ENGINE_OIL_TEMPERATURE_LEFT; // -30+120 grad C  // ����������� �����
double ENGINE_OIL_TEMPERATURE_RIGHT; // -30+120 grad C  // ����������� �����
//
//------------
//double LAMBDA_LEFT;
//double LAMBDA_RIGHT;
//
//------------
double WING_TIP_TANK_FUEL_WEIGHT_LEFT; // 0+200 ��  ����� �������
double WING_TIP_TANK_FUEL_WEIGHT_RIGHT; // 0+200 ��  ����� �������

double WING_TANK_FUEL_WEIGHT_SUM_LEFT;       // 0+525 kg ����� �������
double WING_TANK_FUEL_WEIGHT_SUM_RIGHT;       // 0+525 kg ����� �������

double WING_TANK_FUEL_WEIGHT_SUMMARY;       // 0+525 kg ����� �������
//
//------------
double TEMP_AIR_CELS;
//-------
double M;

double V;
double VXY;

double VPR;   // 0+600 km/h
double VPR_RMI;   // 0+600 km/h

double VIST;   // 0+600 km/h
//-------
double H;  // -500+10000 m ������
double Hcm;  // -500+10000 m ������
double RMI_AGLH;  //  ����������� 0+900 �

double VKYG_PR; //  -30+30 �/� ������������ ��������
//-------
double ALF;
double AL;
double BTF;
//
//-------
double NX;
double NY;
double NZ;

double AX;
double AY;
double AZ;
//
//-------
double VKXT;
double VKYT;
double VKZT;
//--
double VKX;
double VKY;
double VKZ;
//--
double WX;
double WY;
double WZ;
//--
double VX;
double VY;
double VZ;
//
//-------
double OMXT;
double OMYT;
double OMZT;
//--
double OMX;
double OMY;
double OMZ;
//--
double TGTR;
double KRTR;
double PSITR;
//--
double TGR;
double KRR;
double PSIR;
//--
double TG; // -90+90 ���� ������
double KR; // -180+180 ���� ����
double PSI; // -180+180 ����  ����
double PSI_PR; // 0+360 ����  ����
//
//------------
double Vxg_DISS;   // VXG_D
double VKYG;
double Vzg_DISS;
//
//------------IVO------------------------------------------------------
double Vxg_IVO;    // VXG_A
double VKYG_IVO;
double Vzg_IVO;

double XG_IVO;
double YG_IVO;
double ZG_IVO;
//------------INO------------------------------------------------------
double Vxg_INO;    //VXG_G
double VKYG_INO;
double Vzg_INO;

double XG_INO;
double YG_INO;
double ZG_INO;
//-------
double PSI_AIRFIELD_IK_GRAD;
//-------
double INO_HM;
//-------
double MAC;           //����� ��  ��

double XT_PERCENT;    //���������, %
double XT;            //���������, �
double DXT;
//-------
int FLIGHT_CYCLE_COUNT;

double FLIGHT_CYCLE_TIME;

int CYCLE_TIME;

int CYCLE_ETALON;
//-------
double VALUE_1;
double VALUE_2;
double VALUE_3;
double VALUE_4;
//-------
double AL_BALL;   // -1+1 ���� ���������� (�����)
double TURN_ANGLE; // -45 + 45 ���� ��������
//
//------------���� X---------------------------------------------------
//
double CX_SEMI;
double KCX;
double DCXZ;
double CXDRV;
double CXCY1;
double CXDINT;
double CXSHAS;
double CXBET;
double CXDRN;
double CXB_LEFT;
double CXB_RIGHT;
double CXZEM;
double KCXZEM;
double CX;

double X_AERO;
//-------
double X_SHAS_NOSE;
double X_SHAS_LEFT;
double X_SHAS_RIGHT;
double X_SHAS_SUM;
//-------
double X_SU_LEFT;
double X_SU_RIGHT;

double X_SU_SUM;
//-------
double X_SUM;
//
//------------CY-------------------------------------------------------
//
double CY_SEMI;
double CYALM;
double DCYZ;
double CYDRV;
double CYDINT;
double CYB_LEFT;
double CYB_RIGHT;
double CYZEM;
double KCYZEM;
double CYALT;
double KCYWZXT;
double KCYWZM;
double CY;
double CY1_SEMI;
double CY_CON;
double CY1;

double Y_AERO;
//-------
double Y_SHAS_NOSE;
double Y_SHAS_LEFT;
double Y_SHAS_RIGHT;
double Y_SHAS_SUM;
//-------
double Y_SU_LEFT;
double Y_SU_RIGHT;

double Y_SU_SUM;
//-------
double Y_SUM;
//
//------------CZ-------------------------------------------------------
//
double CZBET;
double CZDRN;
double CZDSCHT;
double CZWY;
double CZB_LEFT;
double CZB_RIGHT;
double CZ;

double Z_AERO;
//-------
double Z_SHAS_NOSE;
double Z_SHAS_LEFT;
double Z_SHAS_RIGHT;
double Z_SHAS_SUM;
//-------
double Z_SU_LEFT;
double Z_SU_RIGHT;

double Z_SU_SUM;
//-------
double Z_SUM;
//
//------------MX-------------------------------------------------------
//
double MX_SEMI;
double MXBET;
//-------
double MXDEL_LEFT;
double MXDEL_RIGHT;
double MXDEL;
//-------
double MXDRN;
double MXDSCHT;
double MXWX;
double MXWY;
double MXB_LEFT;
double MXB_RIGHT;
double MX;
double MX_DEMP;

double MX_AERO;
double MX_AERO_DEMP;
double MX_AERO_SUM;
double MX_ZV;
//-------
double MX_SHAS_NOSE;
double MX_SHAS_LEFT;
double MX_SHAS_RIGHT;
double MX_SHAS_SUM;
//-------
double MX_ENGINE_LEFT;
double MX_ENGINE_RIGHT;

double MX_SU_SUM;
//------
double MX_CM;
//-------
double MX_SUM;
//
//------------MY-------------------------------------------------------
//
double MY_SEMI;
double MYBET;
double MYDRN;
double MYDSCHT;
double MYWY;
double MYWX;
double MYB_LEFT;
double MYB_RIGHT;
double MY;
double MY_DEMP;

double MY_AERO;
double MY_AERO_DEMP;
double MY_AERO_SUM;
double MY_ZV;
//-------
double MY_SHAS_NOSE;
double MY_SHAS_LEFT;
double MY_SHAS_RIGHT;
double MY_SHAS_SUM;
//-------
double MY_ENGINE_LEFT;
double MY_ENGINE_RIGHT;

double MY_GYRO_LEFT;
double MY_GYRO_RIGHT;

double MY_SU_LEFT;
double MY_SU_RIGHT;

double MY_SU_SUM;
//-------
double MY_SUM;
//-------
double MY_CM;
//
//------------MZ-------------------------------------------------------
//
double MZALM;
double DMZ;
double MZDRV;
double MZDINT;
double MZSHAS;
double MZBET;
double MZB_LEFT;
double MZB_RIGHT;
double MZZEM;
double KMZZEM;
double MZWZ_LEFT;
double MZWZ_RIGHT;
double MZALT_LEFT;
double MZALT_RIGHT;
double MZ;
double MZ_DEMP;

double MZ_AERO;
double MZ_AERO_DEMP;
double MZ_AERO_SUM;
double MZ_ZV;
//-------
double MZ_SHAS_NOSE;
double MZ_SHAS_LEFT;
double MZ_SHAS_RIGHT;
double MZ_SHAS_SUM;
//-------
double MZ_ENGINE_LEFT;
double MZ_ENGINE_RIGHT;

double MZ_GYRO_LEFT;
double MZ_GYRO_RIGHT;

double MZ_SU_LEFT;
double MZ_SU_RIGHT;
double MZ_SU_SUM;
//-------
double MZ_SUM;
//-------
double MZ_CM;
//
//------------���������� ������� �������-------------------------------
//
bool PR_AUTO_FEATHER_SWITCH;

bool PR_MANUAL_FEATHER_PUSH_BUTTON_LEFT;
bool PR_MANUAL_FEATHER_PUSH_BUTTON_RIGHT;

bool PR_AUTOMAT_BANK_CONTROL_SWITCH;

bool PR_SPOILER_SWITCH;

bool PR_PARKING_BRAKE_CONTROL_LEVER;

bool PR_LANDING_GEAR_ACTUATOR_ON;
bool PR_LANDING_GEAR_ACTUATOR_OFF;

bool PR_NOSE_WHEEL_STEERING_MANUAL;
bool PR_NOSE_WHEEL_STEERING_PEDAL;

bool PR_FUEL_FIRE_COCK_OFF_LEFT;
bool PR_FUEL_FIRE_COCK_OFF_RIGHT;

bool PR_WING_FLAPS_ACTUATOR_0;
bool PR_WING_FLAPS_ACTUATOR_18;
bool PR_WING_FLAPS_ACTUATOR_42;

bool PR_DRY_MOTORING_RUN_BUTTON_LEFT;
bool PR_ENGINE_STARTING_BUTTON_LEFT;

bool PR_ENGINE_STARTING_BUTTON_RIGHT;
bool PR_DRY_MOTORING_RUN_BUTTON_RIGHT;

bool PR_WATER_INJECTION_BUTTON_ON;
bool PR_WATER_INJECTION_BUTTON_OFF;

bool PR_WATER_DRAIN_SWITCH;
//
//------------��������� �������----------------------------------------
//
double EngineHourFuelConsumption_Left;      	 // ������� ������ ������� ������ ���������
double EngineHourFuelConsumption_Right;     	 // ������� ������ ������� ������� ���������

double EndTankFuelWeight_Left;                   // ����� ������� � ����� �������� ����
double EndTankFuelWeight_Right;                  // ����� ������� � ������ �������� ����

double WingFuelWeight_Left;                      // ����� ������� � ����� ��������� ����� (GTL)
double WingFuelWeight_Right;                     // ����� ������� � ������ ��������� ����� (GTP)

double SummaryTankFuelWeight_Left;
double SummaryTankFuelWeight_Right;

double SummaryTankFuelWeight;					 // ��������� ������� �������

double WingGaugeDiskRotationSpeed_Left;          // �������� �������� ����� ����������� ����� ��������� �����
double WingGaugeDiskRotationSpeed_Right;         // �������� �������� ����� ����������� ������ ��������� �����

double EndTankGaugeDiskRotationSpeed_Left;       // �������� �������� ����� ����������� ������ ��������� ����
double EndTankGaugeDiskRotationSpeed_Right;      // �������� �������� ����� ����������� ������� ��������� ����
//------------������---------------------------------------------------
bool FAULT_CloggingFilter_Left;                  //  #0     ������������ ������� ��������� ������� ����.���.
bool FAULT_CloggingFilter_Right;                 //  #1     ������������ ������� ��������� ������� ����.����.
bool FAULT_FuelPump_Left;                        //  #2     ������������ ������� ����.������� ����.���.
bool FAULT_FuelPump_Right;                       //  #3     ������������ ������� ����.������� ����.����.
bool FAULT_AutomaticPumping_Left;                //  #4     ����� �������������� ��������� �������
bool FAULT_AutomaticPumping_Right;               //  #5        ��� ���������� ������ ������� � ����� �������� ���������� �� 400 ��
bool FAULT_SignalingMinFuelAmount_Left;          //  #6     ����� ������� ����� ���.����� �������
bool FAULT_SignalingMinFuelAmount_Right;         //  #7        ��� ���������� ������ ������� ���� 108 ��
bool FAULT_FuelLeak_Left;                        //  #8     (������) ����������� ���������� ������ �� ������ ������� �����
bool FAULT_FuelLeak_Right;                       //  #9       � ����� ������� �� ��������� � ������ �������� ��������� ��������� �����������
bool FAULT_WingFuelGauge_Left;                   //  #10   (����� �����������) ���������� ��� �������
bool FAULT_WingFuelGauge_Right;                  //  #11       �������� ������������ �����
bool FAULT_EndTankFuelGauge_Left;                //  #12          � ��������� ����������
bool FAULT_EndTankFuelGauge_Right;               //  #13             ��������� �����������
bool FAULT_FuelPumpingBoard_Left;                //  #14    ����� ����� ��������� ������� ���.
bool FAULT_FuelPumpingBoard_Right;               //  #15    ����� ����� ��������� ������� ����.
//-------
//
//------------- �������� ------------------------------------------------
//
bool PR_CraneBanding;                       	 // ������� ������ ����� ����������� (KK)
//-------------
bool PR_WingTransferPumpPressure_Left;           // ������� �������� �� ������� ��������� ����.����� ���. ����������� (PPL)
bool PR_WingTransferPumpPressure_Right;          // ������� �������� �� ������� ��������� ����.����� ����. ����������� (PPP)
//-------------
bool PR_WireVoltage_1493M;                   	 // ��������
bool PR_WireVoltage_1494M;                  	 //       �������
bool PR_WireVoltage_1495M;                   	 //            ����������
bool PR_WireVoltage_1496M;                   	 //                   �� ��������
bool PR_WireVoltage_1497M;                   	 //                           (1493�...
bool PR_WireVoltage_1498M;                   	 //                               1498�)
//-------------
bool PR_WireVoltage_4107M;                   	 // ��������
bool PR_WireVoltage_4108M;                   	 //      �������
bool PR_WireVoltage_4109M;                    	 //          ����������
bool PR_WireVoltage_4110M;                   	 //                 �� ��������
bool PR_WireVoltage_4111M;                   	 //                         (4107�...
bool PR_WireVoltage_4112M;                   	 //                             4112�)
//-------------
bool PR_RelayDelay_Left_M405;                    // ������� �������� ������������ ���� M405
bool PR_RelayDelay_Right_M406;                   // ������� �������� ������������ ���� �406
//-------------
bool PR_WireVoltage_256M;                        // ������� ������� ���������� �� ������� 256�
bool PR_WireVoltage_257M;                        // ������� ������� ���������� �� ������� 257�
//-------------
bool PR_EndTankFuelPumpOperation_Left_M419;      // ������� ������ ���������� ������ ������ ��������� ����
bool PR_EndTankFuelPumpOperation_Right_M420;     // ������� ������ ���������� ������ ������� ��������� ����
//-------------
bool PR_FuelPumpPressure_Left;                   // ������� �������� ������������ ������� ������ ��������� ����
bool PR_FuelPumpPressure_Right;                  // ������� �������� ������������ ������� ������� ��������� ����
//-------------
bool PR_FuelPumpOperation_Left_M121;             // ������� ������ ���������� ������ ����� ��������� ����� (�121)
bool PR_FuelPumpOperation_Right_M122;            // ������� ������ ���������� ������ ������ ��������� ����� (�122)
bool PR_WireVoltage_1228M;                       // ������� ������� ���������� �� ������� 1228�
bool PR_WireVoltage_1230M;                       // ������� ������� ���������� �� ������� 1230�
bool PR_AZS_M131;                                // ������� ��� "��������� ����� ���."
bool PR_AZS_M132;                                // ������� ��� "��������� ����� ����."

bool PR_AZS_M135;                                // ������� ��� "����������� �������" (�135)

bool PR_AZS_M401;                                // ������� ��� "�������� ��� ���."
bool PR_AZS_M402;                                // ������� ��� "�������� ��� ����."

bool PR_Relay_M405;                              // ������� ������ ���� M405
bool PR_Relay_M406;                              // ������� ������ ���� M406
bool PR_Relay_M407;                              // ������� ������ ���� M407
bool PR_Relay_M408;                              // ������� ������ ���� M408
bool PR_Relay_M409;                              // ������� ������ ���� M409
bool PR_Relay_M410;                              // ������� ������ ���� M410

bool PR_WireVoltage_4002M;                       // ������� ������� ���������� �� ������� 4002�

bool PR_WireVoltage_739E;                        // ������� ������� ���������� �� ������� 739�
bool PR_WireVoltage_740E;                        // ������� ������� ���������� �� ������� 740�

bool PR_SwitchEndTankPumping_M403;               // ������� ����. "��������� ����. ���� ���."
bool PR_SwitchEndTankPumping_M404;               // ������� ����. "��������� ����. ���� ����."

bool PR_AZS_Board_241;                           // ������� ��� "����� ������������ ����. ���."
bool PR_AZS_Board_242;                           // ������� ��� "����� ������������ ������"
bool PR_AZS_Board_244;                           // ������� ��� "����� ������������ ����. ����."

bool PR_Board_282_1;                             // ������� ��������� ����� "�������.�������"
bool PR_Board_282_5;                             // ������� ��������� ����� "��������� ������� ���" (������)
bool PR_Board_282_6;                             // ������� ��������� ����� "��������� ������� ����" (������)
bool PR_Board_282_9;                             // ������� ��������� ����� "������ ���������" ��� (������)
bool PR_Board_282_10;                            // ������� ��������� ����� "������ ���������" ���� (������)

bool PR_Board_281_3;                             // ������� ��������� ����� "����. �������" (����. ���.)
bool PR_Board_281_4;                             // ������� ��������� ����� "���. ����� �������" (����. ���.)
bool PR_Board_281_8;                             // ������� ��������� ����� "��������� �������" (����. ���.)

bool PR_Board_284_3;                             // ������� ��������� ����� "����. �������" (����. ����.)
bool PR_Board_284_4;                             // ������� ��������� ����� "���. ����� �������" (����. ����.)
bool PR_Board_284_8;                             // ������� ��������� ����� "��������� �������" (����. ����.)
//===========================================================================================================
//������� ��� ���������
double NAV_avtVg   [2];//avtonom Vx Vz
double NAV_avtVgy     ;//avtonom Vy
double NAV_avtAngl [3];//avtonom  PSI,Kren,Tang
bool   NAV_bAvt       ; //pr avtonom

//
//-------
} SHMNTR_410;

#pragma pack(pop)

