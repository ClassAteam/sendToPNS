// ????? ????????? ??? ????????, ?????,
// ?????????? ? ???????? ??????????? ???????? L-410 ???-?20
#ifndef _STRUCT_PRIB_H // #endif
#define _STRUCT_PRIB_H


#pragma pack(push, 1)

//-----------------------------------------------
// ????????? ?????
struct SHSOUND_OUT
{
 bool   Close_cockpit;   // ?????????? ???????????   
 int    Identifier;     // ?????? 999111
 
 bool   Priz_Kasanie1;  // ??????? ??????? ??? ???.  (??? ????????)
 bool   Priz_Kasanie2;  // ??????? ??????? ??? ????. (??? ????????)
 bool   Priz_Kasanie3;  // ??????? ??????? ??? ???.  (??? ????????)

 bool   Priz_Kasanie1_earth;  // ??????? ??????? ???. ????? (??? ????????)
 bool   Priz_Kasanie2_earth;  // ??????? ??????? ????. ????? (??? ????????)
 bool   Priz_Kasanie3_earth;  // ??????? ??????? ???. ????? (??? ????????)

 bool   Priz_no_shassi; // ??????? ??????? ?? ???????

 bool   Priz_wing1;     // ??????? ????? ???. ??????
 bool   Priz_wing2;     // ??????? ????? ????. ??????
 bool   Priz_hvost;     // ??????? ????? ???????

 bool   Priz_pneum1;    // ??????? ??????? ????? ???.
 bool   Priz_pneum2;    // ??????? ??????? ????? ????.
 bool   Priz_pneum3;    // ??????? ??????? ????? ???.

 bool   Priz_Gt1;       // ??????? ????????????? ??????? ???. ????.
 bool   Priz_Gt2;       // ??????? ????????????? ??????? ????. ????.

 bool   Priz_nasos;     // ??????? ?????? ?????????? ??????
 bool   Priz_rap;       // ??????? ?????? ???

 bool   Priz_Shassi1;   // ??????? ???????/?????? ???. ?????
 bool   Priz_Shassi2;   // ??????? ???????/?????? ????. ?????
 bool   Priz_Shassi3;   // ??????? ???????/?????? ???. ?????

 bool   Priz_Lock_beg1; // ??????? ????? ?????? ???. ?????
 bool   Priz_Lock_beg2; // ??????? ????? ?????? ????. ?????
 bool   Priz_Lock_beg3; // ??????? ????? ?????? ???. ?????

 bool   Priz_Lock_end1; // ??????? ????? ?????? ???. ?????
 bool   Priz_Lock_end2; // ??????? ????? ?????? ????. ?????
 bool   Priz_Lock_end3; // ??????? ????? ?????? ???. ?????

 bool   Priz_Siren1;    // ??????? ?????? 1
 bool   Priz_Siren2;    // ??????? ?????? 2
 bool   Priz_Siren3;    // ??????? ?????? 3

 double Oborot1;        // ??????? ?????? ????????? (0+110%)
 double Oborot2;        // ??????? ??????? ????????? (0+110%)

 double Step_vint1;     // ??? ????? ???. (-25+80)
 double Step_vint2;     // ??? ????? ????. (-25+80)

 double Gt1;            // ??????? ?????? ??????? Gt ???. (0+350 ??/???)
 double Gt2;            // ??????? ?????? ??????? Gt ????. (0+350 ??/???)

 double Oborot_vint1;   // ??????? ????? ???. (0+2100)
 double Oborot_vint2;   // ??????? ????? ????. (0+2100)

 double Vprib;          // ???????? ????????? (0+450 ??/???) (?? ??????? ?? ??????? ????????? ??????!!!)
 double H;              // ?????? (0+9500 ?)

 bool Plug1;            // ????? ???.
 bool Plug2;            // ????? ????.

 bool Plug1_second;     // ????? ???. (2 ??????? ????????)
 bool Plug2_second;     // ????? ????.(2 ??????? ????????)

 bool Pompage1;         // ?????? ???.
 bool Pompage2;         // ?????? ????.

 bool Preobr_36v;       //  ??????????????? 36 ?
 bool Preobr_115v;      //  ??????????????? 115 ?
 bool Accumulator;      //  ??????????? ??????
};

//-----------------------------------------------
// ????????? ??????????
struct SHRADIO_OUT2
{
 bool  Priz_CIMS;               // ??????? ?????? ????

 bool  Priz_Rab_UKV1;           // ??????? ?????? ???1
 bool  Priz_Rab_UKV2;           // ??????? ?????? ???2
 bool  Priz_Rab_KV;             // ??????? ?????? ??

 bool  Priz_Active_UKV1_pilot1; // ??????? ???????? ???1 (1 ?????)
 bool  Priz_Active_UKV2_pilot1; // ??????? ???????? ???2 (1 ?????)
 bool  Priz_Active_KV_pilot1;   // ??????? ???????? ??   (1 ?????)

 bool  Priz_Active_UKV1_pilot2; // ??????? ???????? ???1 (2 ?????)
 bool  Priz_Active_UKV2_pilot2; // ??????? ???????? ???2 (2 ?????)
 bool  Priz_Active_KV_pilot2;   // ??????? ???????? ??   (2 ?????)

 bool  Priz_UKV1_DOP_pilot1;    // ??????? ??????????????? ????????????? ???1 (1 ?????)
 bool  Priz_UKV2_DOP_pilot1;    // ??????? ??????????????? ????????????? ???2 (1 ?????)
 bool  Priz_KV_DOP_pilot1;      // ??????? ??????????????? ????????????? ??   (1 ?????)

 bool  Priz_UKV1_DOP_pilot2;    // ??????? ??????????????? ????????????? ???1 (2 ?????)
 bool  Priz_UKV2_DOP_pilot2;    // ??????? ??????????????? ????????????? ???2 (2 ?????)
 bool  Priz_KV_DOP_pilot2;      // ??????? ??????????????? ????????????? ??   (2 ?????)

 bool  Priz_noise_UKV1;         // ??????? "?????????? ????" ???1 (??????) (????????? ??? =1)
 bool  Priz_noise_UKV2;         // ??????? "?????????? ????" ???2 (??????) (????????? ??? =1)
 bool  Priz_noise_KV;           // ??????? "?????????? ????" ??   (??????) (????????? ??? =1)

 bool  Priz_SPU_pilot1;         // ??????? ???  (1 ?????) ?? ????????
 bool  Priz_Radio_pilot1;       // ??????? ?????(1 ?????) ?? ????????

 bool  Priz_SPU_pilot2;         // ??????? ???  (2 ?????) ?? ????????
 bool  Priz_Radio_pilot2;       // ??????? ?????(2 ?????) ?? ????????

 bool  Marker_FAR;              // ?????? ???????
 bool  Marker_MIDDLE;           // ?????? ???????
 bool  Marker_NEAR;             // ?????? ???????

 bool  Danger_H;                // ??????? ??????

 int   Priz_ARK;                // ????? ??? ??????
				// 0 = ?? ??????
				// 1 =  1 ???????? ???(?) ?????? ????
				// 2 =  1 ???????? ???(?) ?????? ????
				// 3 =  1 ???????? ???(?) ??? ????
				// 4 =  1 ???????? ???(?) ??? ????
				// 5 =  2 ???????? ???(?) ?????? ????
				// 6 =  2 ???????? ???(?) ?????? ????
				// 7 =  2 ???????? ???(?) ??? ????
				// 8 =  2 ???????? ???(?) ??? ????
				// 9 =  3 ???????? ???(?) ?????? ????
				// 10 = 3 ???????? ???(?) ?????? ????
				// 11 = 3 ???????? ???(?) ??? ????
				// 12 = 3 ???????? ???(?) ??? ????
 
 int   Priz_RSBN;               // ????? ???? ??????
				// 0 = ?? ??????
  				// 1 =  1 ???????? ??????? ?????? ????
				// 2 =  1 ???????? ??????? ??? ????
				// 3 =  2 ???????? ??????? ?????? ????
				// 4 =  2 ???????? ??????? ??? ????
				// 5 =  3 ???????? ??????? ?????? ????
				// 6 =  3 ???????? ??????? ??? ????
				// 7 =  ????? ????????? (?? ???? ?????????? ?????????)

 float Vol_UKV1_pilot1;         // ????????? ???1 (1 ?????) (0+100%)
 float Vol_UKV2_pilot1;         // ????????? ???2 (1 ?????) (0+100%)
 float Vol_KV_pilot1;           // ????????? ??   (1 ?????) (0+100%)
 float Vol_UKV1_DOP_pilot1;     // ????????? ??????????????? ????????????? ???1 (1 ?????) (0+100%)
 float Vol_UKV2_DOP_pilot1;     // ????????? ??????????????? ????????????? ???2 (1 ?????) (0+100%)
 float Vol_KV_DOP_pilot1;       // ????????? ??????????????? ????????????? ??   (1 ?????) (0+100%)
 float Vol_SPU_pilot1;          // ????????? ??? (1 ?????) (0+100%)
 float Vol_ARK_pilot1;          // ????????? ??? (1 ?????) (0+100%)
 float Vol_RNU1_pilot1;         // ????????? ????????????? ??????????????????? ???-?? ?1 (1 ?????) (0+100%)
 float Vol_RNU2_pilot1;         // ????????? ????????????? ??????????????????? ???-?? ?2 (1 ?????) (0+100%)
 float Vol_RNU3_pilot1;         // ????????? ????????????? ??????????????????? ???-?? ?3 (1 ?????) (0+100%)

 float Vol_UKV1_pilot2;         // ????????? ???1 (2 ?????) (0+100%)
 float Vol_UKV2_pilot2;         // ????????? ???2 (2 ?????) (0+100%)
 float Vol_KV_pilot2;           // ????????? ??   (2 ?????) (0+100%)
 float Vol_UKV1_DOP_pilot2;     // ????????? ??????????????? ????????????? ???1 (2 ?????) (0+100%)
 float Vol_UKV2_DOP_pilot2;     // ????????? ??????????????? ????????????? ???2 (2 ?????) (0+100%)
 float Vol_KV_DOP_pilot2;       // ????????? ??????????????? ????????????? ??   (2 ?????) (0+100%)
 float Vol_SPU_pilot2;          // ????????? ??? (2 ?????) (0+100%)
 float Vol_ARK_pilot2;          // ????????? ??? (2 ?????) (0+100%)
 float Vol_RNU1_pilot2;         // ????????? ????????????? ??????????????????? ???-?? ?1 (2 ?????) (0+100%)
 float Vol_RNU2_pilot2;         // ????????? ????????????? ??????????????????? ???-?? ?2 (2 ?????) (0+100%)
 float Vol_RNU3_pilot2;         // ????????? ????????????? ??????????????????? ???-?? ?3 (2 ?????) (0+100%)

 float Freq_UKV1;               // ??????? ???1 (???) (??????)
 float Freq_UKV2;               // ??????? ???2 (???) (??????)
 float Freq_KV;                 // ??????? ??   (???) (??????)

 float ukv1_Freq[3];            // ??????? ???1 (???) ([0] - ???????, [1] - ???????, [2] - ????????????)
 float ukv2_Freq[3];            // ??????? ???2 (???) ([0] - ???????, [1] - ???????, [2] - ????????????)
 float kv_Freq[3];              // ??????? ??   (???) ([0] - ???????, [1] - ???????, [2] - ????????????)

 float ukv1_Daln[3];            // ????????? ????????. ?? ???1 (??) ([0] - ???????, [1] - ???????, [2] - ????????????)
 float ukv2_Daln[3];            // ????????? ????????. ?? ???2 (??) ([0] - ???????, [1] - ???????, [2] - ????????????)
 float kv_Daln[3];              // ????????? ????????. ?? ??   (??) ([0] - ???????, [1] - ???????, [2] - ????????????)

 int gromk[2];			// ????????? ????????? ????? [2] - 0 ????? / 1 ?????? //????????: 0=?? / 1=?? / 2=??? / 3=???1 / 4=???2 / 5=???3

 bool Priz_ton1000;             // ??????? ?????????? ??????? 1000 ??
 float CUS_ARK;                 // ??????????? ???????? ????????? ??? (0.0+1.0)
};

//-----------------------------------------------
// ????????? ??? ???????? ???????????
struct SHSPEECH_OUT
{
 bool VoiceInfo[100]; // ????????? ???????? ??????????? (1 = ????????? ??????)
 bool Power_speech;   // ????????? ???????? ??????????? (???????)
 bool Button_RI1;     // ?????? ?? (1 = ??????) 1 ?????
 bool Button_RI2;     // ?????? ?? (1 = ??????) 2 ?????
 bool List1;          // ????????? ????????????? ?????? 1 ?????
 bool List2;          // ????????? ????????????? ?????? 2 ?????
 double Volume1;      // ????????? ???????? 1 ????? (0+100%)
 double Volume2;      // ????????? ???????? 2 ????? (0+100%)
};

// VoiceInfo[xx]
// [0] - ????? ?????? ?????????
// [1] - ????? ??????? ?????????
// [2] - ????? ????????? ??????
// [3] - ???? ????? ??????????
// [4] - ?????????? ??????????
// [5] - ???????? ??????????
// [6] - ????? ???? ???????????. ???? ?? ???
// [7] - ?????? ???????
// [8] - ??????????? ?????. ?????? ???
// [9] - ??????????? ?1 ????????
// [10] - ??????????? ?2 ????????
// [11] - ???????? ????
// [12] - ???????? ????? ?????? ????, ?????? ??????? ?????? 
// [13] - ???????? ????? ??????? ????, ?????? ??????? ???????
// [14] - ???????? ??????? ?????? ????
// [15] - ???????? ??????? ??????? ????
// [16] - ??????????? ?????? ????????????, ?????? ??????? ?????? 
// [17] - ??????????? ??????? ????????????, ?????? ??????? ???????
// [18] - ???????? ????? ?????? ??????
// [19] - ???????? ????? ??????? ??????
// [20] - ??????????? ????? ?????? ????????? ??????????
// [21] - ??????????? ????? ??????? ????????? ??????????
// [22] - ????????? ????? ?? ????????
// [23] - ????????? ?????? ?? ???????? 
// [24] - ????????? ?????
// [25] - ????? ?? ???????
// [26] - ???????????????? ??????? (????? ?????????? 28 ????? ??????)
// [27] - ???????????????? ??????? (????? ?????????? 28 ????? ???????)
// [28] - ???? ?????
// [29] - ???????????????? ??????? (????? ?????????? 115 ????? ??????)
// [30] - ???????????????? ??????? (????? ?????????? 115 ????? ???????)
// [31] - ????? ???? ???
// [32] - ????? ???? ???
// [33] - ????? ??? 3
// [34] - ????? ??? 3
// [35] - ???????????
// [36] - ???????? ???????
// [37] - ????? ???????
// [38] - ????? ???????
// [39] - ?????? ??????? ??????
// [40] - ?????? ??????? ???????
// [41] - ?????? ??????? ??????
// [42] - ?????? ??????? ???????
// [43] - ?????? ??????? ????? ??????
// [44] - ?????? ??????? ????? ???????
// [45] - ????????? ??????? ? ????? ????
// [46] - ????????? ??????? ? ?????? ????
// [47] - ????? ??????? ???? ???????????
// [48] - ????????? ??????? ??????
// [49] - ????? ??? ????? ??????
// [50] - ????? ??? ????? ???????
// [51] - ????? ??? 1
// [52] - ????? ??? 2
// [53] - ????? ??? 1
// [54] - ????? ??? 2
// [55] - ?????? ???????
// [56] - ?????? ???????
// [57] - ?????? ???????? ??????
// [58] - ????? ????????? ?? ???????????
// [59] - ?????? ????????? ?? ???????????
 

//-----------------------------------------------
// ????????? ???????? LUN 1348 (????? ?????????)
typedef struct
{
 double fOborot;       // ??/ ???
}SHLUN1348_Left_OUT; 

//-----------------------------------------------
// ????????? ???????? LUN 1348 (?????? ?????????)
typedef struct
{
 double fOborot;       // ??/ ???
}SHLUN1348_Right_OUT;

//-----------------------------------------------
// ????????? ????????? ??????? LUN-1539-02.8 (????? ?????????)
typedef struct
{
 bool   blenker;     // ??????? ?????? 0=yes
 double fMk;         // 0+120% Mk ???????? ??????
}SHLUN1539_Left_OUT; 

//-----------------------------------------------
// ????????? ????????? ??????? LUN-1539-02.8 (?????? ?????????)
typedef struct
{
 bool   blenker;     // ??????? ?????? 0=yes
 double fMk;         // 0+120% Mk ???????? ??????
}SHLUN1539_Right_OUT; 

//-----------------------------------------------
// ????????? ????????? ????? LUN-1694-8
typedef struct
{
 bool bLamp[6]; //????? ?????
 // 0 - ??????? ?????, 1- ??????? ?????, 2- ??????? ?????? (????? ??????)
 // 3 - ??????? ?????, 4- ??????? ?????, 5- ??????? ?????? (????? ????????)
}SHLUN1694_OUT;   

//-------------------------------------------------
// ?????? ???1,???2,Xa,Za
typedef  struct 
{ 
 int    Aero;  // 0=balashov, 1=rtischevo, 2=borisoglebsk
 double UKV1;  // MHZ
 double UKV2;  // MHZ
 double KV;    // MHZ
 double Xa;    // 
 double Za;    //   
 double ARK1_CHAN1;  // ARK1 CHANNEL1
 double ARK1_CHAN2;  // ARK1 CHANNEL2
 double KRM;         // KRM              
 int    SO_Code;     // SO-2010 CODE
}SHPANEL_UKV_OUT; 

//-------------------------------------------------
// ????????? ????????? ????-26
typedef  struct 
{ 
 float Vprib;
 float Vvert;
 float Baro_H_QFE;
 float Baro_H_QNH;
 float Baro_H_STD;
 float Kren;
 float Tangage;
 float Kurs;
 float SetKurs;
 float Number_M;
 float QFE_mmHg;
 float QFE_hPa;
 float QNH_mmHg;
 float QNH_hPa;
 float STD_mmHg;
 float STD_hPa;
	
 bool Brightness_minus;
 bool Brightness_plus;
 bool Fast_Korrection;
 bool HDG_press;
 bool BARO_press;
 int  BARO_roll;
 int  HDG_roll;
					
 bool Otkaz[5];		// 0 = otkaz Vprib 
			// 1 = otkaz kren + tangage
			// 2 = otkaz giromagnitnogo kursa
			// 3 = otkaz Vvert
			// 4 = otkaz barometr vysoty
	
 bool Irp_1;		// vkl IRP-1
 float Battery;		// zaryad ot IRP-1
 bool Power;			
}SHISRP26_OUT; 

//-------------------------------------------------
// ??? ???????? 3D- ??????
typedef  struct 
{ 
 float Oborot_left;   // ??????? ???.
 float Oborot_right;  // ??????? ????.
 float Chassis_front; // ????????? ????? ???. (0.0 = ??????, 1.0 = ????????)
 float Chassis_left;  // ????????? ????? ???. (0.0 = ??????, 1.0 = ????????)
 float Chassis_right; // ????????? ????? ????. (0.0 = ??????, 1.0 = ????????)
 float Kurs;          // ????
 float Kren;          // ????
 float Tangage;       // ??????
 float Yaw;           // ???? ????????
}SHPLANE_OUT; 
//-------------------------------------------------

struct SHPRIB_OUT
{
 bool TTablo1[10];  //  9 ?????????.          0=???????? ????
 bool TTablo2[4];   //  3 ?????????. ???????? 0=???????? ????
 bool TTablo3[4];   //  3 ?????????. ??????   0=???????? ????

 double Sharik;     //  ????????? ?????????? (?????) -1.0 + 1.0  
 
 bool  Priz_SPU_pilot1;         // ??????? ???  (1 ?????) ?? ????????
 bool  Priz_Radio_pilot1;       // ??????? ?????(1 ?????) ?? ????????

 bool  Priz_SPU_pilot2;         // ??????? ???  (2 ?????) ?? ????????
 bool  Priz_Radio_pilot2;       // ??????? ?????(2 ?????) ?? ????????   
  
 SHLUN1348_Left_OUT   LUN1348_Left;
 SHLUN1348_Right_OUT  LUN1348_Right;
 SHLUN1539_Left_OUT   LUN1539_Left;
 SHLUN1539_Right_OUT  LUN1539_Right;
 SHLUN1694_OUT        LUN1694;
 SHPANEL_UKV_OUT      PANEL_UKV;
 SHISRP26_OUT         ISRP26; 
 SHPLANE_OUT          PLANE;
};

// ??????? ????????? ??? ?????? ??????????? (?? ??????????)
//---------------------------------
struct SHCOMMON_STRUCT
{
 SHSOUND_OUT   SOUND;  // ????
 SHRADIO_OUT2  RADIO;  // ??????????
 SHSPEECH_OUT  SPEECH; // ??????? ?????????? 
 SHPRIB_OUT    PRIB;   // ???????
};
//---------------------------------

#pragma pack(pop)

#endif
