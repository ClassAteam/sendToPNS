//------------------------------------------------------------------------------
 #define   NUMVPP_READ      10   //����� ��� (� ����. � ������.)
 #define   NUMSTART_READ    5    //�����.����� �� ����� ��� (� ����. � ������.)
 #define   NUMRNT_READ      100  //max num -  ����� ��������� (���� ���� ����) ������� //����� ADM-RSBN �������  //����� VOR �������
 #define   NUMTRAS_READ     5    //����� [TRAS_0]- [TRASSA_4] ��� ������ ���, ���, ���
 #define   NUMRNT           NUMRNT_READ+NUMVPP_READ*4 //����� ������� ������ ���� :  ��������� (���� ���� ����) ������� //���� ADM-RSBN //���� VOR
//----------------------------------------------------
#pragma pack(push, 1)
//#ifdef _NavMap_h
struct SHGEOPOINT{
		double LatGeo_g;    //���. ����������
		double Lat_r;
		double Lon_g;
		double Lon_r;
		double YrovenMest; //���. ������� �����

};
struct SHRECTPOINT{         //���. �������.����������  ���.�������� ����� ������
		double XZa	[2];     // (����� ��� ������� ������)
		double XZk	[2];
		double  Y_AK; //  �����. Y (������) ���. �������� ����� ������
};

//struct SHANGLEDALN{
//		double Az_Tek_r;
//		double Az_Tek_g;
//		double AnglNakl_r;
//		double AnglNakl_g;
//		double D_Tek;
//		double Dn_Tek;
//};
struct SHSP{
	   //	char name[64];
		//SHGEOPOINT  posNul; //�����.����� � ���
		SHRECTPOINT NulKRM;    //�����.����� � �������.��, ������������ ���������� ������ - ����� ��� ������� �����
		SHRECTPOINT NulGRM;
		double TopXA;
		double BottomXA;
		double PolySektorJob;
		double PolySektorLimTop;
		double PolySektorLimBottom;
		double DalnLim;
		float  Freq;
		bool   enabl;
		//bool   enablDn;
		bool   enablHg;
		int    morse[3];
 };
//struct SHGRM{
//	   //	char name[64];
//		SHGEOPOINT  posNul; //�����.����� � ���
//		SHRECTPOINT Nul;    //�����.����� � �������.��, ������������ ���������� ������ - ����� ��� ������� �����
// };


struct SHPRS{
//	RADIOPOINT::RADIOPOINT(){Lat_g=0.0,Lon_g=0.0, Lat_r=0.0, Az_r=0.0,  D=0.0};
		//string nameAer;
		char name[64];
		SHGEOPOINT  posNul; //�����.����� � ���
		SHRECTPOINT Nul;    //�����.����� � �������.��, ������������ ���������� ������ - ����� ��� ������� �����
		double DalnLim;
	   //	unsigned int tip; //prs=0, adm = 1  vor/dme=2   vor=3
		unsigned int KanNavig;
		unsigned int KanPos;
//		unsigned int Freq_MHg_KHg;
//		unsigned int Freq_Hg;
		float  Freq;
		bool   enabl;
		bool   enablDn;
		bool   enablHg;
		int    morse[2];
};
struct SHADM{
//	RADIOPOINT::RADIOPOINT(){Lat_g=0.0,Lon_g=0.0, Lat_r=0.0, Az_r=0.0,  D=0.0};
		//string nameAer;
		char name[64];
		SHGEOPOINT  posNul; //�����.����� � ���
		SHRECTPOINT Nul;    //�����.����� � �������.��, ������������ ���������� ������ - ����� ��� ������� �����
		double DalnLim;
		unsigned int tip; //0-VOR_DME      1-VOR        2 DME
		unsigned int KanNavig;
		unsigned int KanPosForvard;
		unsigned int KanPosBack;
		unsigned int Freq_MHg_KHg;
		unsigned int Freq_Hg;
		bool   enabl;
		bool   enablDn;
		bool   enablHg;
		int    morse[2];
};
struct SHVOR{
//	RADIOPOINT::RADIOPOINT(){Lat_g=0.0,Lon_g=0.0, Lat_r=0.0, Az_r=0.0,  D=0.0};
		//string nameAer;
		char name[64];
		SHGEOPOINT  posNul; //�����.����� � ���
		SHRECTPOINT Nul;    //�����.����� � �������.��, ������������ ���������� ������ - ����� ��� ������� �����
//		double XZa	[2];
//		double XZk	[2];
//		double  Y_AK;
		//SHANGLEDALN posAzD;
		//double Habs_Nul;
		unsigned int tip; // 0-VOR_DME      1-VOR        2 DME
		unsigned int KanNavig;
		unsigned int KanPos;
		unsigned int Freq_MHg_KHg;
		unsigned int Freq_Hg;
		bool   enabl;
		bool   enablDn;
		bool   enablHg;
		int    morse[2];
};

struct SHRECTDELTNULLPOINT{
		double Angl ;
		double DX[3] ;//x,y,z
};
struct SHSTARTPOINT{
		char name[64];
		SHGEOPOINT posNul;
		SHRECTPOINT Nul;
		double PSI_g ;
		double PSI_r ;
		//bool bBack;//=1   Back
};

 struct SHVPP{
		char name[64];
		SHGEOPOINT   posNul[2];  //�����. � ��� forvard/back ������
		SHGEOPOINT   posKTA;  //�����. � ��� KTA[
		double Lvpp;
		//SHANGLEDALN  posAzD;
		//SHRECTPOINT  posRect[2];
		//double DXk[3] ;//x,y,z//
		SHRECTDELTNULLPOINT DeltNul;
		double MKa_g[2] ;
		double IKa_g[2] ;
		double  IKa_r[2];
		double MS_g[2] ; //���������, ��� �������
		SHRECTPOINT NulMrpD[2];    //�����.����� � �������.��, ������������ ���������� ������ - ����� ��� ������� �����
		SHRECTPOINT NulMrpM[2];
		SHRECTPOINT NulMrpB[2];
		bool bBackEquipment; //1=������������������ ��������� �����
//		double XZa_mrpD_F	[2]	;//[0][1] - forvard / x,z
//		double XZa_mrpM_F	[2]	;
//		double XZa_mrpB_F	[2]	;
//		double XZa_mrpD_B	[2]	;//[0][1] - back / x,z
//		double XZa_mrpM_B	[2]	;
//		double XZa_mrpB_B	[2]	;
//		double Y_AK_F[3]; // ������� ����� [0][1][2]- forvard  daln /  sred  /  blih
//		double Y_AK_B[3];
		bool       bMRP_F[3]; //�������  mrp  [0][1][2]- forvard  daln /  sred  /  blih
		bool       bMRP_B[3]; //�������  mrp  [0][1][2]- back  daln /  sred  /  blih
//		bool       bAdm; //������� adm ������� �� ���������
//		bool       bVor; //������� vor ������� �� ���������
//		int        iPrs; //����� ��������� ������� �� ���������
		SHADM      adm;
		SHVOR      vor;
		SHPRS      prs_F[2]; ////[0][1] - forvard dprs bprs
		SHPRS      prs_B[2]; ////[0][1] - back dprs bprs /
		SHSP       sp_F;//krm +grm // ���������� krm � grm ������ ������������ ���������� �����
		SHSP       sp_B;//krm +grm // ���������� krm � grm ������ ������������ ���������� �����
		float      UKV1_Freq;
		float      UKV2_Freq;
		float      KV_Freq;
	   //	SHRNT      dprs[2];
		SHSTARTPOINT stP[NUMSTART_READ];
	   //	bool bBack;   //==0 -forvard
	   //	unsigned int indAer;  //������ ���������
};
//struct SHAER{
//		string nameAer  ;    //�������
//		double MSa_g	;    //�������
////		SHVPP  Fv  ;
////		SHVPP  Bk  ;
//	  //	bool   bBackVPPjob                      ;
//};



struct SHTEKTIMEPOINT{
		//--------------------� ������ ����
		SHGEOPOINT pos;
		SHRECTPOINT rect;
		double  MS_g;
		double  IK_r;
		double  IK_g;
		double  Tg_g;
		double  Kr_g;
		double  IKivo_r;
		double  IKivo_g;
		double  IKnulStP_r;
		double  IKnulStP_g;
		//--������� ��������� ������������ � ������ ����
		double ARK_freq;
		//int RSBN_kanN;//==num ���� �������� �� ���. �����, ������ num  // 0 - �� ��������
		//int RSBN_kanPos;//==num ���� �������� �� ���. �����, ������ num  // 0 - �� ��������

		int       iNumRSBN;//����� ���� �������������� �� ���. ����� :
		                   // ��� 1 aer: 1= ����� ��� 
					       //            2= ����� ��� ������� �����
					       //            3= ����� ��� ��������� �����
					       // ��� 2 aer: 3,4,5   //   ��� 3 aer: 6,7,8 � �.�.

		 int    iNumNastrARK;         //0 - net 1,2,3,4  - 1 aer   5,6,7,8  - 2 aer    9,10,11,12  - 3 aer
		 //bool   bRSBN_es;           //������� �� ������� � ����������� ������������ 1 -es
		 //bool   bARK_es;            //������� �� ������� � ����������� ������������ 1 -es
		//--------------------��� �����  Abase
		double  HabsStartSK;//���.������ ��������� �����
		int     Abase;//����� ��� ��������� ������ �������.��     //tek
};

//#endif
 ////////////////////////////////////
struct SHNAVMAP //
{


	//char logName[64] ;
	//char iniName[64] ;

	 //-----------------------------------------
	 //double inVgX;
	 //double inVgY;
	 //double inVgZ;

	 //double inPsi_r;
	 //double inPsi_g;
	 //double inKr_g;
	 //double inTg_g;

	//stringstream logStr;

	int NumVpp;//����� ���
	int NumStP;//�����  ��������� �����
	int NumADM;//����� ��������� +���  ADM
	int NumVOR;//����� ��������� +��� VOR
	int NumPRS;//����� ��������� +��� ��� (���� ���� ����)
   //	int NumSumRNT;//����� �������  (NumADM + NumVOR + NumPRS)
	//int     Abase;//����� ��� ��������� ������ �������.��     //tek
   //	bool    bZahod;// true - back
	double  Daer[NUMVPP_READ];                                //tek
	double  AZaer_g[NUMVPP_READ];                             //tek
	int     TekStA; //0, 1 , 2  //����� ��� �������� ��� ���  ��������� �����
	int     TekSt;//����� ���  ��������� �����
	SHVPP Vpp[NUMVPP_READ]; // 0-Balashev  1-Rtihevo  2 -Borisogleb
	SHPRS oprs_tras[NUMRNT_READ]; //��������� oprs (���� ����)
	SHADM adm_tras[NUMRNT_READ]; //��������� adm (���� ����)
	SHVOR vor_tras[NUMRNT_READ]; //��������� vor (���� ����)
	SHVOR* pVOR[NUMRNT];   //��. �� ��� ������� ������� ����
	SHADM* pADM[NUMRNT];
	SHPRS* pPRS[NUMRNT];
	SHTEKTIMEPOINT tekP;      //tek
	//SHTEKTIMEPOINT oldP;
	//bool prConnectMap;
   bool prConnectNav;
   bool bClose;//������� ���������� ����� ������� ������ �� Disp410
};
#pragma pack(pop)



//#endif