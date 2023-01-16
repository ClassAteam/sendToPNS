// ==========================================
// ===== data structures for T01 L410   =====
// ==========================================
#define T_410_MAX_PO_NEAREST_COUNTER 8
#define T_410_MAX_PO_SCAN_FULL_COUNTER 64

struct descr_sm2_410_begin
  {unsigned short first;                   // 0       // == 0x00FF ?????????????
   unsigned short length;				   // 1 
   unsigned long  time_send;			   // 2 
   unsigned long  time_received;		   // 3 
   unsigned long  counter;				   // 4 
   };									 
struct descr_sm2_410_head
  {
	  unsigned short head_10;             // 0              // ID = 0x0010
      unsigned short priznak;             // 1              // =0 - day; =1 - night; =2 - dust 1; =3 - dust 2; =4 - dust 3;
      unsigned short year_time;           // 2              // =0 - summer; =1 - winter;
      unsigned short base_number;         // 3              // =0 - AER1(Balasev); =1 - AER2(Rtihevo); =2 - AER3(Borisoglebsk);      //1
      float sky_down;				      // 4       
      float sky_up;					      // 5       
      float distance;				      // 6       
      float runway_height;                // 7           // runway height above sea level FROM NAVIGATION
      float runway_ik_rads;               // 8           // �� main runway RADIANS
      float longitude;                    // 9           // ������� DEGREES
      float lattitude;                    // 10          // ������  DEGREES
      float wind_speed;                   // 11          // m/Sec
      float wind_ik;                      // 12          // RAD
      short cloud_difficulty;		      // 13      
      short back_runway_flag;             // 14                                                                        //2
      float layer_up_2;                   // 15         //   water snow on runway
      float layer_down_2;                 // 16         // down: fires visibility coeff
      float layer_complex;                // 17         // complexity: fires size coeff;
      float wind_speed_m_sec;		      // 18      
      float win_ik_radians;			      // 19      
      float weight;                       // 20                                                                         //3
      unsigned short stop_flag;           // 21                                                                          //4
      unsigned short channel_mask;        // 22  0 ������ (0x0001) - ���������� ������ ������
      unsigned short shutdown_flag;        // 23  ����������
      unsigned short res[7];              // 24-30
    };

struct descr_sm2_410_dynamic
{
		unsigned short head_12;       // 0       ID = 0x0012
		unsigned short mode;          // 1      
		float DRV;					  // 2      /rul H
		float DEL_LEFT;				  // 3      /eler L
		float DEL_RIGHT;			  // 4      /eler R
		float DRN;					  // 5      /rul napravlen
		float WING_FLAPS_ANGLE;		  // 6      /zakrilki
		float SPOILER_ANGLE;		  // 7      /interseptor
		float SCHT_ANGLE_LF;		  // 8      /shitok avtomat kren �����
		float FINW;					  // 9      /angle nos koleso
		float AL_RUD_LEFT;			  // 10     
		float AL_RUD_RIGHT;			  // 11     
		float AL_RUB_LEFT;			  // 12     //rihag upravl vint left
		float AL_RUB_RIGHT;			  // 13     //rihag upravl vint r
		float AL_STOP_LEFT;			  // 14     //angle upravl stop-kran l
		float AL_STOP_RIGHT;		  // 15     //angle upravl stop-kran r
		float ELEVATOR_TRIM_ANGLE;	  // 16     //trimer rul H
		float AILERON_TRIM_ANGLE;	  // 17     //trimer eleron
		float RUDDER_TRIM_ANGLE;	  // 18     //trimer rul napravlen
		float LEFT_SHASSI_STATE;     // 19      // ��������� ����� ������ �����
		float RIGHT_SHASSI_STATE;    // 20      // ��������� ������ ������ �����
		float BRAKE_PRESSURE_LEFT;	  // 21     //davlen tormoz l
		float BRAKE_PRESSURE_RIGHT;	  // 22     //davlen tormoz r
		float NGG_LEFT;				  // 23     //oborot gazogen l ( %)
		float NGG_RIGHT;			  // 24     //oborot gazogen r (%)
		float NBB_LEFT;				  // 25     //oborot vinta l (ob/min)
		float NBB_RIGHT;			  // 26     //oborot vinta r (ob/min)
		float MKR_LEFT;				  // 27     //krut moment left Dvig(%)
		float MKR_RIGHT;			  // 28     //krut moment r Dvig(%)
		float PBB_LEFT;				  // 29     //tiaga left (kg)
		float PBB_RIGHT;              // 30     //tiaga r (kg)            //
		float FIBB_LEFT;			  // 31     //angle lopast left vint (grad)
		float FIBB_RIGHT;			  // 32     //angle lopast r vint (grad)
		float TGZ_LEFT;				  // 33     //T gaz l (C)
		float TGZ_RIGHT;			  // 34     //T gaz r (C)
		float FUEL_PRESSURE_LEFT;	  // 35     
		float FUEL_PRESSURE_RIGHT;	  // 36     
		float OIL_PRESSURE_LEFT;	  // 37     
		float OIL_PRESSURE_RIGHT;	  // 38     
		float OIL_TEMPERATURE_LEFT;	  // 39     
		float OIL_TEMPERATURE_RIGHT;  // 40     
		float WING_TANK_FUEL_LEFT;    // 41     //topliv0 in Left wing (kg)
		float WING_TANK_FUEL_RIGHT;   // 42     //topliv0 in R wing (kg)
		float MAC;                    // 43     //massa LA(kg)
		float XT;                     // 44     //centrovka(%)
	    float SCHT_ANGLE_RT;		  // 8      /shitok avtomat kren ������
	    float NOSE_SHASSI_STATE;		  // 8      /shitok avtomat kren ������
//-------								        
	    float res[3];                 // 45-49
	    float res_U[24];               // 50-73
};
///////////////////////////////////////////////////////////////////////////////////
     //------------���������� ������� �������-------------------------------
	 //res_U[0]=U_CONTROL_STICK; // ����������� �������
	 //res_U[1]=U_STEERING_WHEEL; // �������
	 //res_U[2]=U_PEDAL; // ������
	 //res_U[3]=U_PILOT_BRAKE_PEDAL_LEFT; //����� �������� ������ ������
	 //res_U[4]=U_PILOT_BRAKE_PEDAL_RIGHT; //������ �������� ������ ������
	 //res_U[5]=U_CO_PILOT_BRAKE_PEDAL_LEFT; //����� �������� ������� ������
	 //res_U[6]=U_CO_PILOT_BRAKE_PEDAL_RIGHT; //������ �������� ������� ������
	 //res_U[7]=U_ELEVATOR_TRIM_HAND_WHEEL; // ������� ���� ������
	 //res_U[8]=U_NOSE_LANDING_GEAR_STEERING_WHEEL; //�������� �������� ������
	 //res_U[9]=U_EMERGENCY_HYDRAULIC_PUMP_LEVER; //������ �����
	 // //--------����������� �����----------------------------------------
	 //res_U[10]=U_THROTTLE_CONTROL_LEVER_LEFT; //��� �����
	 //res_U[11]=U_THROTTLE_CONTROL_LEVER_RIGHT; //��� ������
	 //res_U[12]=U_PROPELLER_CONTROL_LEVER_LEFT; //��� �����
	 //res_U[13]=U_PROPELLER_CONTROL_LEVER_RIGHT; //��� ������
	 //res_U[14]=U_EMERGENCY_THROTTLE_LEVER_LEFT; //����-���� �����
	 //res_U[15]=U_EMERGENCY_THROTTLE_LEVER_RIGHT; //����-���� ������
	 // //--------�����������----------------------------------------------
	 //res_U[16]=U_FORCE_PEDAL; //����������� �������
	 //res_U[17]=U_FORCE_CONTROL_STICK; //����������� ����������� �������
	 //res_U[18]=U_FORCE_STEERING_WHEEL; //����������� ��������
  //   res_U[19]=U_FORCE_ELEVATOR_TRIM; //������� ���� ������
/////////////////////////////////////////////////////////////////////////////////
struct descr_sm2_410_time
  {unsigned short head_14;             // 0      // ID = 0x0014
   unsigned short res1;      		   // 1 
   unsigned char day;                  // 2      // 1...
   unsigned char mon;                  // 3      // 1...
   unsigned char year;                 // 4      // from 1900
   unsigned char hour;                 // 5      // 0
   unsigned char min;                  // 6      // 0
   unsigned char recalc_flag;          // 7      // != 0: recalculate time of day
   unsigned short skin_type;		   // 8 
   };								    
									  

   // --- switches COMMON ---
//       0  //sw1                                      // - begin conditions 
//       1                                             // - fires RD         
//       2                                             //        "on sides"  
//       3                                             //        "on center" 
//       4                                             //        "forward"   
//       5                                             //        "backward"  
//       6                                             //        "thunder"   
//       7                                             //        "impulse"   
//       8                                             //  bright  "20%"     
//       9                                             //          "30%"     
//      10                                             //          "50%"     
//      11                                             //          "75%"     
//      12                                             //          "90%"     
//      13                                             //         "100%"     
//      14                                             //  land deny         
//      15                                             //  land permission   
//      0  // sw2                                      //      
//      1                                              //   
//      2                                              //  
//      3                                              // 
//      4                                              // 
//      5                                              // 
//      6                                              //
//      7                                              //
//      8                                              //  
//      9                                              //snow         
//     10                                              //rain  
//     11                                              //rain reset([10]=1 or [9]=1)
//     12                                              //large fires
//     13                                              //small fires
//     14                                              //reserved
//     15                                              //projectors on runway
//  go[0]//sw3 bool PR_FUEL_FIRE_COCK_OFF_LEFT;        // ����.���� ���.
//  go[1]      bool PR_FUEL_FIRE_COCK_OFF_RIGHT;       //����.���� ����.
//  go[2]      bool PR_TOUCH_DOWN_NOSE;                //�����.��� ������ �� �����
//  go[3]      bool PR_TOUCH_DOWN_LEFT;                //�����.������ ������ �� �����
//  go[4]      bool PR_TOUCH_DOWN_RIGHT;               //�����.����. ������ �� �����
//  go[5]      bool PR_TOUCH_DOWN_GROUND_RUNWAY_NOSE;  //�����.��� ������ ����� 
//  go[6]      bool PR_TOUCH_DOWN_GROUND_RUNWAY_LEFT;  //�����.������ ������ �����
//  go[7]      bool PR_TOUCH_DOWN_GROUND_RUNWAY_RIGHT; //�����.����. ������ �����
//  go[8]      bool PR_FUSELAGE_LANDING;               //������� �� �������
//  go[9]      bool PR_TOUCH_DOWN_WING_LEFT;           //�����. ����� ���.
//  go[10]     bool PR_TOUCH_DOWN_WING_RIGHT;          //�����. ����� ����.
//  go[11]     bool PR_TAIL_LANDING;                   //�����. �����
//  go[12]     bool PR_TIRE_BURST_NOSE;                //������ ��� ������
//  go[13]     bool PR_TIRE_BURST_LEFT;                //������ ��� ������
//  go[14]     bool PR_TIRE_BURST_RIGHT;               //������ ���� ������
//  go[15]     bool PR_ENGINE_FUEL_BURN_LEFT;          //������� ������� ������� � ����� ����.
//  go[0]//sw4 bool PR_ENGINE_FUEL_BURN_RIGHT;         //������� ������� ������� � ������ ����.
//  go[1]      bool PR_SHASSI_ACTUATION_NOSE;          //������� �������� �������\������ �������� �����
//  go[2]      bool PR_SHASSI_ACTUATION_LEFT;          //������� �������� �������\������ ��� �����
//  go[3]      bool PR_SHASSI_ACTUATION_RIGHT;         //������� �������� �������\������ ���� �����
//  go[4]      bool PR_SHASSI_LOCK_OFF_NOSE;           //������� ������������ ����� ��������� ���������  �������� �����
//  go[5]      bool PR_SHASSI_LOCK_OFF_LEFT;           //������� ������������ ����� ��������� ���������  ��� �����
//  go[6]      bool PR_SHASSI_LOCK_OFF_RIGHT;          //������� ������������ ����� ��������� ��������� ����  �����
//  go[7]      bool PR_SHASSI_LOCK_ON_NOSE;            //������� ������������ ����� ����������� ���������  �������� �����
//  go[8]      bool PR_SHASSI_LOCK_ON_LEFT;			   //������� ������������ ����� ����������� ���������  ��� �����
//  go[9]      bool PR_SHASSI_LOCK_ON_RIGHT;		   //������� ������������ ����� ����������� ��������� ����  �����
//  go[10]             
//  go[11]             
//  go[12]             
//  go[13]             
//  go[14]             
//  go[15]                                                                              
//  go[0] //sw5    bool Otkaz[100];        ������ :    0 = ������� ����� ���.                        
//  go[1]              								   1 = ������� ��������� ���.
//  go[2]              								   2 = �����. ����� ���.
//  go[3]              								   3 = ��������� �������� ���.
//  go[4]              								   4 = �������� ����� ���.
//  go[5]              								   5 = ����������� ����� ���.
//  go[6]              								   6 = ������������ ���.
//  go[7]              								   7 = �������� ������� ���.
//  go[8]              								   8 = ������ ������� ���.
//  go[9]              								   9 = ��� ���.
//  go[10]             								   10 = ���� ���.
//  go[11]             								   11 = ����. ����. �����
//  go[12]             								   12 = ������� ����� ����.
//  go[13]             								   13 = ������� ��������� ����.
//  go[14]             								   14 = �����. ����� ����.
//  go[15]             								   15 = ��������� �������� ����.
//  go[0] //sw6										   16 = �������� ����� ����.
//  go[1] 											   17 = ����������� ����� ����.
//  go[2] 											   18 = ������������ ����.
//  go[3] 											   19 = �������� ������� ����.
//  go[4] 											   20 = ������ ������� ����.
//  go[5] 											   21 = ��� ����.
//  go[6] 											   22 = ���� ����.
//  go[7] 											   23 = ��������� �� ���.
//  go[8] 											   24 = ��������� �� ����.
//  go[9] 											   25 = ���
//  go[10]											   26 = ��
//  go[11]											   27 = ���
//  go[12]											   28 = ��-50
//  go[13]											   29 = ��� ����.
//  go[14]											   30 = ��� ����.
//  go[15]											   31 = ��� I
//  go[0]//sw7 										   32 = ��� I
//  go[1] 											   33 = ���� ����. ����
//  go[2] 											   34 = ���� ����. L
//  go[3] 											   35 = ���� ����. R
//  go[4] 											   36 = ��������
//  go[5] 											   37 = ���� �. ����. ����
//  go[6] 											   38 = ���� �. ����. L
//  go[7] 											   39 = ���� �. ����. R
//  go[8] 											   40 = �����
//  go[9] 											   41 = ����� ���.
//  go[10]											   42 = ����� ����.
//  go[11]											   43 = ����� �����.
//  go[12]											   44 = �����������
//  go[13]											   45 = ����������� ��������
//  go[14]											   46 = ����� ��������
//  go[15]											   47 = �������� ��� ����
//  go[0]//sw8 										   48 = ������ ���� (���� ������������� ���.)
//  go[1] 											   49 = ������ 0.2� ������. (���� ������������� ���.)
//  go[2] 											   50 = ������ 1.5� ������. (���� ������������� ���.)
//  go[3] 											   51 = ������ 5� ������. (���� ������������� ���.)
//  go[4] 											   52 = ������ 0.2� �����. (���� ������������� ���.)
//  go[5] 											   53 = ������ 1.5� �����. (���� ������������� ���.)
//  go[6] 											   54 = ������ 5� �����. (���� ������������� ���.)
//  go[7] 											   55 = ���� ���� (���� ������������� ���.)
//  go[8] 											   56 = ���� 0.2� ���. (���� ������������� ���.)
//  go[9] 											   57 = ���� 1.5� ���. (���� ������������� ���.)
//  go[10]											   58 = ���� 5� ���. (���� ������������� ���.)
//  go[11]											   59 = ���� 0.2� ����. (���� ������������� ���.)
//  go[12]											   60 = ���� 1.5� ����. (���� ������������� ���.)
//  go[13]											   61 = ���� 5� ����. (���� ������������� ���.)
//  go[14]											   62 = ������ ���� (���� ������������� ����.)
//  go[15]											   63 = ������ 0.2� ������. (���� ������������� ����.)
//  go[0]//sw9 										   64 = ������ 1.5� ������. (���� ������������� ����.)
//  go[1] 											   65 = ������ 5� ������. (���� ������������� ����.)
//  go[2] 											   66 = ������ 0.2� �����. (���� ������������� ����.)
//  go[3] 											   67 = ������ 1.5� �����. (���� ������������� ����.)
//  go[4] 											   68 = ������ 5� �����. (���� ������������� ����.)
//  go[5] 											   69 = ���� ���� (���� ������������� ����.)
//  go[6] 											   70 = ���� 0.2� ���. (���� ������������� ����.)
//  go[7] 											   71 = ���� 1.5� ���. (���� ������������� ����.)
//  go[8] 											   72 = ���� 5� ���. (���� ������������� ����.)
//  go[9] 											   73 = ���� 0.2� ����. (���� ������������� ����.)
//  go[10]											   74 = ���� 1.5� ����. (���� ������������� ����.)
//  go[11]											   75 = ���� 5� ����. (���� ������������� ����.)
//  go[12]											   76 = �� ��
//  go[13]											   77 = ���������
//  go[14]											   78 = ������������
//  go[15]											   79 = ��������������� 36�
//  go[0]//sw10 									   80 = ��������������� 115�
//  go[1]         
//  go[2] 			
//  go[3] 			
//  go[4] 			
//  go[5] 			
//  go[6] 			
//  go[7] 			
//  go[8] 			
//  go[9] 			                                   
//  go[10]			                                  //������� ������� �������� ������� 	
//  go[11]			                                  //������� ������� �������� �������	 	
//  go[12]			                                  //������� ������� �������� �������	 
//  go[13]			                                  //������� ���� ������� ����		 
//  go[14]			                                  //������� ���� ������� ����		 
//  go[15]											  //�������  ���� 	����	
//  go[0]//sw11 		 bool  Avaria[19];             // 0 - ��� ���
//  go[1] 											   // 1 - ��� �����
//  go[2] 											   // 2 - ������� ������.
//  go[3] 											   // 3 - ���� ������
//  go[4] 											   // 4 - ���� �������
//  go[5] 											   // 5 - ������� ���
//  go[6] 											   // 6 - �����. ������
//  go[7] 											   // 7 - ������. ���
//  go[8] 											   // 8 - ������
//  go[9] 											   // 9 - ������� ��������
//  go[10]											   // 10 - ������� ����. � �����
//  go[11]											   // 11 - ������� ����. � ����.
//  go[12]											   // 12 - G > 5700 ��
//  go[13]											   // 13 - ��� ���.
//  go[14]											   // 14 - ��� ����.
//  go[15]											   // 15 - ���� ���.
//  go[0]//sw12 									   // 16 - ���� ����.
//  go[1] 											   // 17 - ����
//  go[2] 											   // 18 - �����.
//  go[3] 		
//  go[4] 
//  go[5] 
//  go[6] 
//  go[7] 
//  go[8] 
//  go[9] 
//  go[10]
//  go[11]
//  go[12]
//  go[13]
//  go[14]
//  go[15]

struct descr_sm2_410_switches
  {unsigned short head_20;        // 0                       // ID = 0x0020
   unsigned short res;			  // 1 
   unsigned short sw1;			  // 2 
   unsigned short sw2;			  // 3 
   unsigned short sw3;			  // 4 
   unsigned short sw4;			  // 5 
   unsigned short sw5;			  // 6 
   unsigned short sw6;			  // 7 
   unsigned short sw7;			  // 8 
   unsigned short sw8;			  // 9 
   unsigned short sw9;			  // 10
   unsigned short sw10;			  // 11
   unsigned short sw11;			  // 12
   unsigned short sw12;			  // 13
   };

struct descr_sm2_410_la
  {unsigned short head_30;      // 0                       // ID = 0x0030
   unsigned short res;		    // 1                         
   float Xla[3];                // 2 3 4                   // coords        M  !!! Y:above sea level      !!!
   float Ala[3];                // 5 6 7                   // angles        RAD!!! without LA_ABOVE_PLACE !!!
   float dXla[3];               // 8 9 10                  // coords      M/Sec
   float dAla[3];               // 11 12 13                // angles      PAD/Sec
   float Vprib;                 // 14                      //�������� ���������  ��\�
   float Alfa;                  // 15                      //���� �����         grad
   float Beta;                  // 16                      //���� ����������    grad
   float Nx;                    // 17                      //���������� 
   float Ny; 					// 18
   float Nz;                    // 19       
   double lat;                   // 20                      //�����. ������       grad
   double lon;                   // 21                      //�����. �������      grad
   float  IK_rad;                // 22                      //IK rad
   float res1[3];               // 23-25
   };							
								
struct descr_sm2_410_end		
  {unsigned short control;     // 0                        // = 0x8001
   unsigned short last;        // 1                        // = 0xFF00
   unsigned short res[2];	   // 2 3 
   };


// ===============================
// =====   main data block   =====
// ===============================
struct extern_sm2_410_array
  {struct descr_sm2_410_begin     begin;
   struct descr_sm2_410_head      head;
   struct descr_sm2_410_dynamic   dynamic;
   struct descr_sm2_410_time      time;
   struct descr_sm2_410_switches  switches;
   struct descr_sm2_410_la        la;
   struct descr_sm2_410_end       end;
   };






// ================================
// =====     back packet       ====
// ================================
struct descr_back_sm2_410_block
   {unsigned short first;        // == 0xFF00
    unsigned short length;       // in bytes
    float height;                // rel height above sea level ?????
    unsigned short last;         // == 0x00FF
    unsigned short cycle_counter;      // alive
    };


// ========= reference reference =========

union extern_sm2_410_pointer
  {unsigned short             *ptr_ushort;
   unsigned char              *ptr_uchar;
   struct descr_sm2_410_begin     *ptr_begin;
   struct descr_sm2_410_head      *ptr_head;
   struct descr_sm2_410_time      *ptr_time;
   struct descr_sm2_410_switches  *ptr_switches;
   struct descr_sm2_410_dynamic   *ptr_dynamic;
   struct descr_sm2_410_la        *ptr_la;
   struct descr_sm2_410_end       *ptr_end;
   struct descr_back_sm2_410_block   *ptr_back_sm2;
   };


// ========= reference reference =========

union extern_rmi_410_pointer
  {unsigned short               *ptr_ushort;
   unsigned char                *ptr_uchar;
   struct descr_rmi_410_begin   *ptr_rmi_begin;
   struct descr_rmi_410_digital *ptr_rmi_digital;
   struct descr_rmi_410_analog  *ptr_rmi_analog;
   struct descr_rmi_410_end     *ptr_rmi_end;
   struct descr_back_rmi_410_block  *ptr_rmi_back;
   };
