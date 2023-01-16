// "STRUCT_CMF_410" - memory name
//17.09.2018

#pragma pack(push, 1)

typedef struct
{
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
//------------������ ����������----------------------------------------
//
double DRV;				        //  elevator, grad
//double CONTROL_STICK_POSITION;  //  ����������� �������, ��

double DEL_LEFT;			  // aileron left, grad
double DEL_RIGHT;			  // aileron right, grad
//double STEERING_WHEEL_ANGLE;  // ���� �������� ��������, ����

double DRN;				      //  rudder, grad
//double PEDAL_LEFT_POSITION;   // ��������� �������, ��

//double LEFT_PULT_TOE_ANGLE_LEFT;     // ���� �������� ��������� ��������, ����
//double LEFT_PULT_TOE_PRESSURE_LEFT;  // �������� �� ��������� ��������, ��/��2

//double LEFT_PULT_TOE_ANGLE_RIGHT;
//double LEFT_PULT_TOE_PRESSURE_RIGHT;

//double RIGHT_PULT_TOE_ANGLE_LEFT;
//double RIGHT_PULT_TOE_PRESSURE_LEFT;

//double RIGHT_PULT_TOE_ANGLE_RIGHT;
//double RIGHT_PULT_TOE_PRESSURE_RIGHT;

double WING_FLAPS_ANGLE;	//  zakrilki
double SPOILER_ANGLE;		//  interseptor
double SCHT_ANGLE;			//  shitok avtomat kren

//double NOSE_LANDING_GEAR_STEERING_WHEEL_ANGLE;
double FI_NOSE_WHEEL;             //  angle nos koleso

//double EMERGENCY_HYDRAULIC_PUMP_LEVER_ANGLE;
//
//------------
double AL_RUD_LEFT;
double AL_RUD_RIGHT;

double AL_RUB_LEFT;			     //rihag upravl vint left
double AL_RUB_RIGHT;			     //rihag upravl vint r

double AL_STOP_LEFT;			     //angle upravl stop-kran l
double AL_STOP_RIGHT;		     //angle upravl stop-kran r

bool PR_FUEL_FIRE_COCK_OFF_LEFT;

bool PR_FUEL_FIRE_COCK_OFF_RIGHT;
//
//------------������� ��-----------------------------------------------
//
//double ELEVATOR_TRIM_HAND_WHEEL_ANGLE;

double ELEVATOR_TRIM_ANGLE;	     //trimer rul H

//double D_ELEVATOR_TRIM;
//
//------------
double AILERON_TRIM_ANGLE;	     //trimer eleron

double RUDDER_TRIM_ANGLE;	     //trimer rul napravlen
//
//------------����������� ��-------------------------------------------
//
//double CONTROL_STICK_FORCE_ZAD;
//double ELEVATOR_FORCE_POSITION;
//double D_ELEVATOR_FORCE;
//double CONTROL_STICK_FORCE;
//
//------------����������� ��-------------------------------------------
//
//double FORCE_STEERING_WHEEL_ZAD;
//double AILERON_FORCE_POSITION;
//double D_AILERON_FORCE;
//double STEERING_WHEEL_FORCE;
//
//------------����������� ��-------------------------------------------
//
//double FORCE_PEDAL_ZAD;
//double RUDDER_FORCE_POSITION;
//double D_RUDDER_FORCE;
//double PEDAL_FORCE;
//-------
double GENERATOR_RPM_LEFT;        //oborot/min elektro-gen l
double GENERATOR_RPM_RIGHT;       //oborot/min elektro-gen r

double BRAKE_PRESSURE_LEFT;	     //davlen tormoz l
double BRAKE_PRESSURE_RIGHT;	     //davlen tormoz r
//
//------------
//double COCKPIT_TEMPERATURE;   // 0+40 grad C  ����������� ������
//double CHANNEL_TEMPERATURE;    // 20+120 grad C  ����������� ������
//
//------------
//bool ENGINE_STARTED_LEFT; // Priznak raboti dvigatelya (1=yes)
//bool ENGINE_STARTED_RIGHT; // Priznak raboti dvigatelya (1=yes)

double ENGINE_NGG_LEFT; // 0+110%
double ENGINE_NGG_RIGHT; // 0+110%

//double ENGINE_NGG_ZAD_LEFT; // 0+110%
//double ENGINE_NGG_ZAD_RIGHT; // 0+110%

//double ENGINE_NE_LEFT; // ���
//double ENGINE_NE_RIGHT; // ���

//double ENGINE_GT_LEFT;
//double ENGINE_GT_RIGHT;

double ENGINE_TGZ_LEFT;         // 0+900 ���� C
double ENGINE_TGZ_RIGHT;         // 0+900 ���� C

//double ENGINE_MKR_LEFT; // �������� ������ H*m
//double ENGINE_MKR_RIGHT; // �������� ������ H*m

double ENGINE_MKR_PERCENT_LEFT; // 0+120% Mk �������� ������
double ENGINE_MKR_PERCENT_RIGHT; // 0+120% Mk �������� ������
//
//------------����-----------------------------------------------------
//
double ENGINE_NBB_LEFT;    // 0+2400 �������/���
double ENGINE_NBB_RIGHT;    // 0+2400 �������/���

//double ENGINE_NBB_ZAD_LEFT;    // 0+2400 �������/���
//double ENGINE_NBB_ZAD_RIGHT;    // 0+2400 �������/���

double ENGINE_FIBB_LEFT;    // -25+80 ���� ��������� ��������
double ENGINE_FIBB_RIGHT;   // -25+80 ���� ��������� ��������

//double ENGINE_MKRBB_LEFT; // �������� ������ ����� H*m
//double ENGINE_MKRBB_RIGHT; // �������� ������ ����� H*m

//double ENGINE_MKRBB_PERCENT_LEFT; // 0+120% Mk �������� ������ �����
//double ENGINE_MKRBB_PERCENT_RIGHT; // 0+120% Mk �������� ������ �����

//double ENGINE_NEBB_LEFT; // ���
//double ENGINE_NEBB_RIGHT; // ���

double ENGINE_PBB_LEFT;    // ���� ����� ������ ��
double ENGINE_PBB_RIGHT;   // ���� ����� ������� ��

//double ENGINE_PREACT_LEFT;    // ���� ����� ������ ��
//double ENGINE_PREACT_RIGHT;   // ���� ����� ������� ��
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
//double WING_TIP_TANK_FUEL_WEIGHT_LEFT; // 0+200 ��  ����� �������
//double WING_TIP_TANK_FUEL_WEIGHT_RIGHT; // 0+200 ��  ����� �������

double WING_TANK_FUEL_WEIGHT_SUM_LEFT;       // 0+525 kg ����� �������
double WING_TANK_FUEL_WEIGHT_SUM_RIGHT;       // 0+525 kg ����� �������

//double WING_TANK_FUEL_WEIGHT_SUMMARY;       // 0+525 kg ����� �������
//
//------------
//double TEMP_AIR_CELS;
//-------
//double M;

//double V;
//double VXY;

//double VPR;   // 0+600 km/h
double VPR_RMI;   // 0+600 km/h

//double VIST;   // 0+600 km/h
//-------
//double H;  // -500+10000 m ������
//double RMI_AGLH;  //  ����������� 0+900 �

//double VKYG_PR; //  -30+30 �/� ������������ ��������
//-------
double ALF;
//double AL;
double BTF;
//
//-------
double NX;
double NY;
double NZ;

//double AX;
//double AY;
//double AZ;
//
//-------
//double VKXT;
//double VKYT;
//double VKZT;
//--
//double VKX;
//double VKY;
//double VKZ;
//--
//double WX;
//double WY;
//double WZ;
//--
//double VX;
//double VY;
//double VZ;
//
//-------
//double OMXT;
//double OMYT;
//double OMZT;
//--
//double OMX;
//double OMY;
//double OMZ;
//--
double TGTR;
double KRTR;
double PSITR;
//--
double TGR;
double KRR;
double PSIR;
//--
//double TG; // -90+90 ���� ������
//double KR; // -180+180 ���� ����
//double PSI; // -180+180 ����  ����
//double PSI_PR; // 0+360 ����  ����
//
//------------
//double Vxg_DISS;   // VXG_D
//double VKYG;
//double Vzg_DISS;
//
//------------IVO------------------------------------------------------
//
//double Vxg_IVO;    // VXG_A
double VKYG_IVO;
//double Vzg_IVO;

double XG_IVO;
double YG_IVO;
double ZG_IVO;

double CMFfromNAV_VAX;
double CMFfromNAV_VAZ;
double CMFfromNAV_LATGG;
double CMFfromNAV_LONG;
double CMFfromNAV_IKG_START;
double CMFfromNAV_HA_START;    //������ ��. �����
double CMFfromNAV_IK_GRAD; // �������� ���� � ����.

bool   PR_OUTER_BEACON_IVO; //�������
bool   PR_MEDIUM_BEACON_IVO; //�������
bool   PR_INNER_BEACON_IVO; //�������
//
//------------INO------------------------------------------------------
//
//double Vxg_INO;    //VXG_G
//double VKYG_INO;
//double Vzg_INO;

//double XG_INO;
//double YG_INO;
//double ZG_INO;
//-------
double PSI_AIRFIELD_IK_GRAD;
//-------
double INO_HM;
//-------
double MAC;           //����� ��  ��

double XT_PERCENT;    //���������, %
//double XT;            //���������, �
//double DXT;
//-------���� ��� ���--------------------------------------------------
bool PR_POSITION_LIGHTS;

bool PR_SEARCHLIGHTS_LANDING;

bool PR_SEARCHLIGHTS_TAXIING;
//-------
int FLIGHT_CYCLE_COUNT;

//double FLIGHT_CYCLE_TIME;

//int CYCLE_TIME;

//int CYCLE_ETALON;
//
//------------
bool PR_TOUCH_DOWN_NOSE;
bool PR_TOUCH_DOWN_LEFT;
bool PR_TOUCH_DOWN_RIGHT;

bool PR_TOUCH_DOWN_GROUND_RUNWAY_NOSE;
bool PR_TOUCH_DOWN_GROUND_RUNWAY_LEFT;
bool PR_TOUCH_DOWN_GROUND_RUNWAY_RIGHT;

bool PR_FUSELAGE_LANDING;//������� ����� ������������� DIN

bool PR_TOUCH_DOWN_WING_LEFT;
bool PR_TOUCH_DOWN_WING_RIGHT;

bool PR_TAIL_LANDING;

bool PR_TIRE_BURST_NOSE;
bool PR_TIRE_BURST_LEFT;
bool PR_TIRE_BURST_RIGHT;

bool PR_ENGINE_FUEL_BURN_LEFT;
bool PR_ENGINE_FUEL_BURN_RIGHT;

bool PR_SHASSI_ACTUATION_NOSE;     //������ - 1
bool PR_SHASSI_ACTUATION_LEFT;     //������ - 1
bool PR_SHASSI_ACTUATION_RIGHT;    //������ - 1

bool PR_SHASSI_LOCK_OFF_NOSE;     // ����� ��������� ���������
bool PR_SHASSI_LOCK_OFF_LEFT;
bool PR_SHASSI_LOCK_OFF_RIGHT;

bool PR_SHASSI_LOCK_ON_NOSE;      // ����� ����������� ���������
bool PR_SHASSI_LOCK_ON_LEFT;
bool PR_SHASSI_LOCK_ON_RIGHT;
//-------
double STRUT_POSITION_NOSE;

double STRUT_POSITION_LEFT;

double STRUT_POSITION_RIGHT;
//-------
} SHCMF_410;

#pragma pack(pop)

