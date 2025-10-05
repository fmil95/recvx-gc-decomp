#include <sg_xpt.h>
#include <ninjadef.h>
#include <ninjastr.h>
#include <ninjacnk.h>
#include <sg_pad.h>
#include <sg_sybt.h>
#include <sg_pdvib.h>
#include <sg_mwply.h>

typedef struct RMI_WORK
{
    // total size: 0x54
    unsigned char* put_ptr;      // offset 0x0, size 0x4
    unsigned char* get_ptr;      // offset 0x4, size 0x4
    int putsize;                 // offset 0x8, size 0x4
    int getsize;                 // offset 0xC, size 0x4
    int readrest;                // offset 0x10, size 0x4
    int writerest;               // offset 0x14, size 0x4
    int count;                   // offset 0x18, size 0x4
    int proceed;                 // offset 0x1C, size 0x4
    unsigned int button_old;     // offset 0x20, size 0x4
    unsigned char cdata[32];     // offset 0x24, size 0x20
    int iMovieState;             // offset 0x44, size 0x4
    int iMovieFrame;             // offset 0x48, size 0x4
    unsigned int uiContFlag;     // offset 0x4C, size 0x4
    unsigned int MVCancelButton; // offset 0x50, size 0x4
} RMI_WORK;

typedef struct MOV_INFO
{
	unsigned char* mmp;        // offset 0x0, size 0x4
    float Vol;                 // offset 0x4, size 0x4
    float VolSpeed;            // offset 0x8, size 0x4
    float Fade;                // offset 0xC, size 0x4
    float FadeSpeed;           // offset 0x10, size 0x4
    short FrameCnt;            // offset 0x14, size 0x2
    char ExecMovieSystemFlag;  // offset 0x16, size 0x1
    char MovieCancelFlag;      // offset 0x17, size 0x1
    char MovieFadeFlag;        // offset 0x18, size 0x1
    char MovieFadeMode;        // offset 0x19, size 0x1
    char MovieSystemLastError; // offset 0x1A, size 0x1
} MOV_INFO;

typedef struct PDS_VIBPARAM_EX
{
	// total size: 0x4
    unsigned char flag; // offset 0x0, size 0x1
    char power;         // offset 0x1, size 0x1
    unsigned char freq; // offset 0x2, size 0x1
    unsigned char inc;  // offset 0x3, size 0x1
} PDS_VIBPARAM_EX;

typedef struct BUTTON_INFO
{
	// total size: 0x8
    int Type;            // offset 0x0, size 0x4
    unsigned int Button; // offset 0x4, size 0x4
} BUTTON_INFO;

typedef struct REPEAT_INFO
{
	// total size: 0xC
    unsigned int WaitFlag; // offset 0x0, size 0x4
    unsigned int WaitCnt;  // offset 0x4, size 0x4
    unsigned int Key;      // offset 0x8, size 0x4
} REPEAT_INFO;

typedef struct PAD_WRK
{
	// total size: 0x3C
    int PerType;         // offset 0x0, size 0x4
    int OldPerType;      // offset 0x4, size 0x4
    int PerTypeEx;       // offset 0x8, size 0x4
    unsigned int Flag;   // offset 0xC, size 0x4
    int SoftReset;       // offset 0x10, size 0x4
    unsigned int on;     // offset 0x14, size 0x4
    unsigned int press;  // offset 0x18, size 0x4
    unsigned int Rept;   // offset 0x1C, size 0x4
    unsigned int on2;    // offset 0x20, size 0x4
    unsigned int on2old; // offset 0x24, size 0x4
    unsigned int press2; // offset 0x28, size 0x4
    unsigned short l;    // offset 0x2C, size 0x2
    unsigned short r;    // offset 0x2E, size 0x2
    short x1;            // offset 0x30, size 0x2
    short y1;            // offset 0x32, size 0x2
    short x2;            // offset 0x34, size 0x2
    short y2;            // offset 0x36, size 0x2
    short Calibrate;     // offset 0x38, size 0x2
} PAD_WRK;

// the structs below need polishing

typedef struct NO_NAME_1
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
} NO_NAME_1;

typedef struct NO_NAME_2
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	NJS_CNK_OBJECT* objP;
	NJS_TEXLIST* texP;
	NO_NAME_1* owP;
} NO_NAME_2;

typedef struct NO_NAME_3
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	NJS_MDATA2* md2P;
	unsigned short* atrP;
} NO_NAME_3;

typedef struct NO_NAME_4
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	char flr_no;
	char flr_nob;
	unsigned char mdlver;
	unsigned char param;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	float px;
	float py;
	float pz;
	int ax;
	int ay;
	int az;
	float ar;
	float aw;
	float ah;
	float ad;
	float car;
	float cah;
	float pxb;
	float pyb;
	float pzb;
	int axb;
	int ayb;
	int azb;
	float gpx;
	float gpy;
	float gpz;
	float lox;
	float loy;
	float loz;
	float aox;
	float aoy;
	float aoz;
	float spd;
	unsigned int flg2;
	unsigned int mdflg;
	unsigned int stflg;
	unsigned int Dummy3;
	int draw_tp;
	int mdl_n;
	void* mskp;
	unsigned int Dummy[1];
	int* skp[16];
	NJS_CNK_OBJECT* mbp[16];
	NJS_TEXLIST* txp[16];
	NO_NAME_2 mdl[16];
	NO_NAME_2* mlwP;
	unsigned int mdl_no;
	int lkono;
	unsigned char* lkwkp;
	unsigned char* exp0;
	unsigned char* exp1;
	unsigned char* exp2;
	unsigned char* exp3;
	unsigned char mtxbuf[64];
	float mtx[16];
	NJS_CNK_OBJECT* obj_a;
	NJS_CNK_OBJECT* obj_b;
	float shp_ct;
	char clp_jno[8];
	int lok_jno;
	NO_NAME_3* mnwP;
	NO_NAME_3* mnwPb;
	unsigned int mtn_attr;
	unsigned int mtn_no;
	int frm_no;
	unsigned int frm_mode;
	int hokan_rate;
	unsigned int hokan_count;
	unsigned int hokan_ctbak;
	int mtn_add;
	unsigned int mtn_md;
	unsigned char* mtn_tp;
	int axp;
	int ayp;
	int azp;
	short psh_ct;
	short psh_idx;
	int idx_ct;
	int mtn_chk;
	float ofx;
	float ofy;
	float ofz;
	float sx;
	float sy;
	float sz;
	float sxb;
	float syb;
	float szb;
	float xn;
	float yn;
	float zn;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
	unsigned char* objbak;
	NJS_SPHERE cspr;
	int pn;
	NJS_POLYGON_VTX* pvp;
	NJS_TEXTURE_VTX* tvp;
	NJS_POLYGON_VTX pv[4];
	NJS_TEXTURE_VTX tv[4];
	int bl_src;
	int bl_dst;
	int ani_ct;
	int tex_id;
	int aspd;
	unsigned int gidx;
	int bank;
	char jno[16];
	char hide[4];
	void(*func)(void*);
	int idx;
	int Dummy2;
} NO_NAME_4;

typedef struct NO_NAME_5
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
} NO_NAME_5;

typedef struct NO_NAME_6
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	short flr_no;
	unsigned short mdlver;
	float px;
	float py;
	float pz;
	float sx;
	float sy;
	float sz;
	short ay;
	short ax;
} NO_NAME_6;

typedef struct NO_NAME_7
{
	short jnt_a;
	short jnt_b;
	int cap_r;
} NO_NAME_7;

typedef struct BH_PWORK
{
	// total size: 0x580
    unsigned int flg; // offset 0x0, size 0x4
    unsigned short id; // offset 0x4, size 0x2
    unsigned short type; // offset 0x6, size 0x2
    char flr_no; // offset 0x8, size 0x1
    char flr_nob; // offset 0x9, size 0x1
    unsigned char mdlver; // offset 0xA, size 0x1
    unsigned char param; // offset 0xB, size 0x1
    unsigned char mode0; // offset 0xC, size 0x1
    unsigned char mode1; // offset 0xD, size 0x1
    unsigned char mode2; // offset 0xE, size 0x1
    unsigned char mode3; // offset 0xF, size 0x1
    float px; // offset 0x10, size 0x4
    float py; // offset 0x14, size 0x4
    float pz; // offset 0x18, size 0x4
    int ax; // offset 0x1C, size 0x4
    int ay; // offset 0x20, size 0x4
    int az; // offset 0x24, size 0x4
    float ar; // offset 0x28, size 0x4
    float aw; // offset 0x2C, size 0x4
    float ah; // offset 0x30, size 0x4
    float ad; // offset 0x34, size 0x4
    float car; // offset 0x38, size 0x4
    float cah; // offset 0x3C, size 0x4
    float pxb; // offset 0x40, size 0x4
    float pyb; // offset 0x44, size 0x4
    float pzb; // offset 0x48, size 0x4
    int axb; // offset 0x4C, size 0x4
    int ayb; // offset 0x50, size 0x4
    int azb; // offset 0x54, size 0x4
    float gpx; // offset 0x58, size 0x4
    float gpy; // offset 0x5C, size 0x4
    float gpz; // offset 0x60, size 0x4
    float lox; // offset 0x64, size 0x4
    float loy; // offset 0x68, size 0x4
    float loz; // offset 0x6C, size 0x4
    float aox; // offset 0x70, size 0x4
    float aoy; // offset 0x74, size 0x4
    float aoz; // offset 0x78, size 0x4
    float spd; // offset 0x7C, size 0x4
    unsigned int flg2; // offset 0x80, size 0x4
    unsigned int mdflg; // offset 0x84, size 0x4
    unsigned int stflg; // offset 0x88, size 0x4
    unsigned int Dummy3; // offset 0x8C, size 0x4
    int draw_tp; // offset 0x90, size 0x4
    int mdl_n; // offset 0x94, size 0x4
    void * mskp; // offset 0x98, size 0x4
    unsigned int Dummy[1]; // offset 0x9C, size 0x4
    int * skp[16]; // offset 0xA0, size 0x40
    NJS_CNK_OBJECT * mbp[16]; // offset 0xE0, size 0x40
	NJS_TEXLIST* txp[16]; // offset 0x120, size 0x40
	NO_NAME_2 mdl[16]; // offset 0x160, size 0x180
	NO_NAME_2* mlwP; // offset 0x2E0, size 0x4
	unsigned int mdl_no; // offset 0x2E4, size 0x4
    int lkono; // offset 0x2E8, size 0x4
    unsigned char * lkwkp; // offset 0x2EC, size 0x4
    unsigned char * exp0; // offset 0x2F0, size 0x4
    unsigned char * exp1; // offset 0x2F4, size 0x4
    unsigned char * exp2; // offset 0x2F8, size 0x4
    unsigned char * exp3; // offset 0x2FC, size 0x4
    unsigned char mtxbuf[64]; // offset 0x300, size 0x40
    float (* mtx)[16]; // offset 0x340, size 0x4
    NJS_CNK_OBJECT * obj_a; // offset 0x344, size 0x4
    NJS_CNK_OBJECT * obj_b; // offset 0x348, size 0x4
    float shp_ct; // offset 0x34C, size 0x4
    char clp_jno[8]; // offset 0x350, size 0x8
    int lok_jno; // offset 0x358, size 0x4
	NO_NAME_3* mnwP; // offset 0x35C, size 0x4
	NO_NAME_3* mnwPb; // offset 0x360, size 0x4
	unsigned int mtn_attr; // offset 0x364, size 0x4
    unsigned int mtn_no; // offset 0x368, size 0x4
    int frm_no; // offset 0x36C, size 0x4
    unsigned int frm_mode; // offset 0x370, size 0x4
    int hokan_rate; // offset 0x374, size 0x4
    unsigned int hokan_count; // offset 0x378, size 0x4
    unsigned int hokan_ctbak; // offset 0x37C, size 0x4
    int mtn_add; // offset 0x380, size 0x4
    unsigned int mtn_md; // offset 0x384, size 0x4
    unsigned char * mtn_tp; // offset 0x388, size 0x4
    int axp; // offset 0x38C, size 0x4
    int ayp; // offset 0x390, size 0x4
    int azp; // offset 0x394, size 0x4
    short psh_ct; // offset 0x398, size 0x2
    short psh_idx; // offset 0x39A, size 0x2
    int idx_ct; // offset 0x39C, size 0x4
    int mtn_chk; // offset 0x3A0, size 0x4
    float ofx; // offset 0x3A4, size 0x4
    float ofy; // offset 0x3A8, size 0x4
    float ofz; // offset 0x3AC, size 0x4
    float sx; // offset 0x3B0, size 0x4
    float sy; // offset 0x3B4, size 0x4
    float sz; // offset 0x3B8, size 0x4
    float sxb; // offset 0x3BC, size 0x4
    float syb; // offset 0x3C0, size 0x4
    float szb; // offset 0x3C4, size 0x4
    float xn; // offset 0x3C8, size 0x4
    float yn; // offset 0x3CC, size 0x4
    float zn; // offset 0x3D0, size 0x4
    int ct0; // offset 0x3D4, size 0x4
    int ct1; // offset 0x3D8, size 0x4
    int ct2; // offset 0x3DC, size 0x4
    int ct3; // offset 0x3E0, size 0x4
    int wpnr_no; // offset 0x3E4, size 0x4
    int wpnl_no; // offset 0x3E8, size 0x4
    unsigned int at_flg; // offset 0x3EC, size 0x4
	NJS_CAPSULE watr; // offset 0x3F0, size 0x1C
	NO_NAME_7* cpcl; // offset 0x40C, size 0x4
	short wax; // offset 0x410, size 0x2
    short way; // offset 0x412, size 0x2
    short waz; // offset 0x414, size 0x2
    short waxp; // offset 0x416, size 0x2
    short wayp; // offset 0x418, size 0x2
    short wazp; // offset 0x41A, size 0x2
    int hp; // offset 0x41C, size 0x4
    int dam[64]; // offset 0x420, size 0x100
    int djnt_no; // offset 0x520, size 0x4
    int cpcl_no; // offset 0x524, size 0x4
    int dax; // offset 0x528, size 0x4
    int day; // offset 0x52C, size 0x4
    float dpx; // offset 0x530, size 0x4
    float dpy; // offset 0x534, size 0x4
    float dpz; // offset 0x538, size 0x4
    float dvx; // offset 0x53C, size 0x4
    float dvy; // offset 0x540, size 0x4
    float dvz; // offset 0x544, size 0x4
    int flr_snd; // offset 0x548, size 0x4
    int ko_num; // offset 0x54C, size 0x4
    int footeff; // offset 0x550, size 0x4
    int src_no; // offset 0x554, size 0x4
    unsigned char * kdnp; // offset 0x558, size 0x4
    int kdnidx; // offset 0x55C, size 0x4
    void * dan_ap; // offset 0x560, size 0x4
    unsigned int comb_flg; // offset 0x564, size 0x4
    unsigned int comb_wep; // offset 0x568, size 0x4
    int comb_pnt; // offset 0x56C, size 0x4
    int comb_timeout; // offset 0x570, size 0x4
    int total_dam; // offset 0x574, size 0x4
    unsigned int Dummy2[2]; // offset 0x578, size 0x8
} BH_PWORK;

typedef struct NO_NAME_8
{
	unsigned int flg;
	unsigned int type;
	int aspd;
	int lkflg;
	int lkno;
	int lkono;
	int lsrc;
	float px;
	float py;
	float pz;
	float lx;
	float ly;
	float lz;
	float vx;
	float vy;
	float vz;
	float spc;
	float dif;
	float amb;
	float r;
	float g;
	float b;
	float nr;
	float fr;
	int iang;
	int oang;
	int ax;
	int ay;
	int az;
	unsigned int mode;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
	float wpx;
	float wpy;
	float wpz;
	float wvx;
	float wvy;
	float wvz;
	float wspc;
	float wdif;
	float wamb;
	float wr;
	float wg;
	float wb;
	float wnr;
	float wfr;
	int wiang;
	int woang;
	int wax;
	int way;
	int waz;
	unsigned char* lkwkp;
	unsigned char* exp;
	NJS_LIGHT_PTR* light;
} NO_NAME_8;

typedef struct NO_NAME_9
{
	NJS_POINT3 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
} NO_NAME_9;

typedef struct NO_NAME_10
{
	unsigned char flg;
	unsigned char type;
	unsigned char id;
	char flr_no;
	unsigned int attr;
	float px;
	float py;
	float pz;
	float w;
	float h;
	float d;
	unsigned char prm0;
	unsigned char prm1;
	unsigned char prm2;
	unsigned char prm3;
} NO_NAME_10; 

typedef struct DOOR_WORK
{
	unsigned int flg;
	char stg_no;
	char rom_no;
	unsigned char pos_no;
	unsigned char dor_tp;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
} DOOR_WORK;

// similar but not quite like NJS_CAPSULE
typedef struct CONICAL_FRUSTUM
{
	NJS_POINT3 c1;
	NJS_POINT3 c2;
	float r1;
	float r2;
} CONICAL_FRUSTUM;

// TODO: the struct has one more field at the start than its PS2 counterpart, find where it gets used and remove the placeholder pad 
typedef struct SYS_WORK
{
	// total size: 0x2ACF0
    unsigned int ssd_ver; // offset 0x0, size 0x4
    unsigned int ssd_flg; // offset 0x4, size 0x4
    unsigned int ssd_reserve; // offset 0x8, size 0x4
    char keytype; // offset 0xC, size 0x1
    char adjust_x; // offset 0xD, size 0x1
    char adjust_y; // offset 0xE, size 0x1
    char vibration; // offset 0xF, size 0x1
    int pad;
    int best_tm[8]; // offset 0x10, size 0x20
    unsigned int sys_partid; // offset 0x30, size 0x4
    unsigned int itm_partid; // offset 0x34, size 0x4
    unsigned int fil_partid; // offset 0x38, size 0x4
    unsigned int dor_partid; // offset 0x3C, size 0x4
    unsigned int ss_flg; // offset 0x40, size 0x4
    int pdm_no; // offset 0x44, size 0x4
    unsigned int typ_flg; // offset 0x48, size 0x4
    unsigned short typ_md0; // offset 0x4C, size 0x2
    unsigned short typ_md1; // offset 0x4E, size 0x2
    void * typ_exp; // offset 0x50, size 0x4
    unsigned int tk_flg; // offset 0x54, size 0x4
    unsigned int ts_flg; // offset 0x58, size 0x4
    unsigned int gm_flg; // offset 0x5C, size 0x4
    unsigned int st_flg; // offset 0x60, size 0x4
    unsigned int cb_flg; // offset 0x64, size 0x4
    unsigned int rm_flg; // offset 0x68, size 0x4
    unsigned int pt_flg; // offset 0x6C, size 0x4
    unsigned int sp_flg; // offset 0x70, size 0x4
    unsigned int ef_flg; // offset 0x74, size 0x4
    unsigned int error; // offset 0x78, size 0x4
    unsigned int version; // offset 0x7C, size 0x4
    int save_ct; // offset 0x80, size 0x4
    char ply_id; // offset 0x84, size 0x1
    char stg_no; // offset 0x85, size 0x1
    char rom_no; // offset 0x86, size 0x1
    char rcase; // offset 0x87, size 0x1
    char pos_no; // offset 0x88, size 0x1
    char cut_no; // offset 0x89, size 0x1
    char flr_no; // offset 0x8A, size 0x1
    char reserve0; // offset 0x8B, size 0x1
    int gm_mode; // offset 0x8C, size 0x4
    unsigned int ev_flg[32]; // offset 0x90, size 0x80
    unsigned int it_flg[16]; // offset 0x110, size 0x40
    unsigned int ic_flg[16]; // offset 0x150, size 0x40
    unsigned int ed_flg[32]; // offset 0x190, size 0x80
    unsigned int ky_flg[16]; // offset 0x210, size 0x40
    unsigned int mp_flg[8]; // offset 0x250, size 0x20
    unsigned int itm[384]; // offset 0x270, size 0x600
    unsigned int ply_stflg[4]; // offset 0x870, size 0x10
	NJS_POINT3 ply_pos; // offset 0x880, size 0xC
	int ply_ang; // offset 0x88C, size 0x4
    char ply_wno[4]; // offset 0x890, size 0x4
    short ply_hp[4]; // offset 0x894, size 0x8
    unsigned char evt_posno[4]; // offset 0x89C, size 0x4
    int time; // offset 0x8A0, size 0x4
    int stv_tm; // offset 0x8A4, size 0x4
    short spray_ct; // offset 0x8A8, size 0x2
    short retry_ct; // offset 0x8AA, size 0x2
    short clear_ct; // offset 0x8AC, size 0x2
    short reserve1; // offset 0x8AE, size 0x2
    unsigned int save_end; // offset 0x8B0, size 0x4
    char stg_nob; // offset 0x8B4, size 0x1
    char rom_nob; // offset 0x8B5, size 0x1
    char pos_nob; // offset 0x8B6, size 0x1
    char rcase_b; // offset 0x8B7, size 0x1
    unsigned int en_flg[4]; // offset 0x8B8, size 0x10
	NJS_TEXLIST* et_lp[16][16][100]; // offset 0x8C8, size 0x19000
	NJS_TEXLIST* ot_lp[1300]; // offset 0x198C8, size 0x1450
	NJS_TEXLIST* it_lp[200]; // offset 0x1AD18, size 0x320
	int eft_n; // offset 0x1B038, size 0x4
	NJS_TEXLIST* eft_lp[8]; // offset 0x1B03C, size 0x20
	int loop_ct; // offset 0x1B05C, size 0x4
    int loop_now; // offset 0x1B060, size 0x4
    int cng_pid; // offset 0x1B064, size 0x4
	const PDS_PERIPHERAL* p1per; // offset 0x1B068, size 0x4
	PDS_PERIPHERAL* p2per; // offset 0x1B06C, size 0x4
	PDS_PERIPHERAL* kbper; // offset 0x1B070, size 0x4
	PDS_PERIPHERAL* msper; // offset 0x1B074, size 0x4
	PDS_PERIPHERAL ms_per; // offset 0x1B078, size 0x34
	int pad_port; // offset 0x1B0AC, size 0x4
    unsigned int pad_on; // offset 0x1B0B0, size 0x4
    unsigned int pad_oncpy; // offset 0x1B0B4, size 0x4
    unsigned int pad_ps; // offset 0x1B0B8, size 0x4
    unsigned int pad_rs; // offset 0x1B0BC, size 0x4
    unsigned int pad_old; // offset 0x1B0C0, size 0x4
    unsigned int pad_onb; // offset 0x1B0C4, size 0x4
    unsigned int pad_psb; // offset 0x1B0C8, size 0x4
    unsigned int pad_oldb; // offset 0x1B0CC, size 0x4
    short pad_ax; // offset 0x1B0D0, size 0x2
    short pad_ay; // offset 0x1B0D2, size 0x2
    short pad_dx; // offset 0x1B0D4, size 0x2
    short pad_dy; // offset 0x1B0D6, size 0x2
    unsigned short pad_ar; // offset 0x1B0D8, size 0x2
    unsigned short pad_al; // offset 0x1B0DA, size 0x2
    int fixcno; // offset 0x1B0DC, size 0x4
    int fixkno; // offset 0x1B0E0, size 0x4
    unsigned int exm_attr; // offset 0x1B0E4, size 0x4
    short evc_no; // offset 0x1B0E8, size 0x2
    short evc_kn; // offset 0x1B0EA, size 0x2
    short evc_ono; // offset 0x1B0EC, size 0x2
    short evc_okn; // offset 0x1B0EE, size 0x2
    int evc_sc; // offset 0x1B0F0, size 0x4
    unsigned char mn_mode0; // offset 0x1B0F4, size 0x1
    unsigned char mn_mode1; // offset 0x1B0F5, size 0x1
    unsigned char mn_mode2; // offset 0x1B0F6, size 0x1
    unsigned char mn_mode3; // offset 0x1B0F7, size 0x1
    unsigned char mn_md0; // offset 0x1B0F8, size 0x1
    unsigned char mn_md1; // offset 0x1B0F9, size 0x1
    unsigned char mn_md2; // offset 0x1B0FA, size 0x1
    unsigned char mn_md3; // offset 0x1B0FB, size 0x1
    int mn_setct; // offset 0x1B0FC, size 0x4
    unsigned int mn_stack[8]; // offset 0x1B100, size 0x20
    unsigned int sdm_flg; // offset 0x1B120, size 0x4
    unsigned int sdm_mode; // offset 0x1B124, size 0x4
    unsigned char * ltc_bp; // offset 0x1B128, size 0x4
    unsigned int ltc_tsbak; // offset 0x1B12C, size 0x4
    int ewk_n; // offset 0x1B130, size 0x4
    unsigned int enow; // offset 0x1B134, size 0x4
    unsigned int onow; // offset 0x1B138, size 0x4
    unsigned int efnow; // offset 0x1B13C, size 0x4
    int vsyc_ct; // offset 0x1B140, size 0x4
    int vsyc_flg; // offset 0x1B144, size 0x4
    int fog_ct; // offset 0x1B148, size 0x4
    int bcl_ct; // offset 0x1B14C, size 0x4
    int gfrm_ct; // offset 0x1B150, size 0x4
    int gframe; // offset 0x1B154, size 0x4
    int eor_ct; // offset 0x1B158, size 0x4
    unsigned int pfm_cts; // offset 0x1B15C, size 0x4
    int evt_tmd; // offset 0x1B160, size 0x4
    int evt_tim; // offset 0x1B164, size 0x4
    int evt_tdg; // offset 0x1B168, size 0x4
    int evt_fcd; // offset 0x1B16C, size 0x4
    unsigned int evt_fcdct; // offset 0x1B170, size 0x4
    unsigned int fsize; // offset 0x1B174, size 0x4
    unsigned int rdtsz; // offset 0x1B178, size 0x4
    unsigned char * memp; // offset 0x1B17C, size 0x4
    unsigned char * mempb; // offset 0x1B180, size 0x4
    unsigned char * endp; // offset 0x1B184, size 0x4
    unsigned char * rdtp; // offset 0x1B188, size 0x4
    unsigned char * plmdlp; // offset 0x1B18C, size 0x4
    unsigned char * lmmdlp; // offset 0x1B190, size 0x4
    unsigned char * wrmdlp; // offset 0x1B194, size 0x4
    unsigned char * wlmdlp; // offset 0x1B198, size 0x4
    unsigned char * plmthp; // offset 0x1B19C, size 0x4
    unsigned char * plbmtp; // offset 0x1B1A0, size 0x4
    unsigned char * plwmtp; // offset 0x1B1A4, size 0x4
    unsigned char * plzmtp; // offset 0x1B1A8, size 0x4
    unsigned char * plemtp; // offset 0x1B1AC, size 0x4
    unsigned char * plexwp; // offset 0x1B1B0, size 0x4
    unsigned char * plhdwp; // offset 0x1B1B4, size 0x4
    unsigned char * pletcp; // offset 0x1B1B8, size 0x4
    unsigned char * subtxp; // offset 0x1B1BC, size 0x4
    unsigned char * doordp; // offset 0x1B1C0, size 0x4
    unsigned char * sbs_sp; // offset 0x1B1C4, size 0x4
	NO_NAME_4* obwp; // offset 0x1B1C8, size 0x4
	NO_NAME_4* itwp; // offset 0x1B1CC, size 0x4
	NO_NAME_3* emtp[128]; // offset 0x1B1D0, size 0x200
	NO_NAME_3* rmthp; // offset 0x1B3D0, size 0x4
	unsigned char * mspp; // offset 0x1B3D4, size 0x4
    unsigned char * lspp; // offset 0x1B3D8, size 0x4
    unsigned int * mes_ip; // offset 0x1B3DC, size 0x4
    unsigned int * mes_sp; // offset 0x1B3E0, size 0x4
    void * mes_tp; // offset 0x1B3E4, size 0x4
    short txr_n; // offset 0x1B3E8, size 0x2
    short txr_ct; // offset 0x1B3EA, size 0x2
	NJS_TEXLIST* txlp[256]; // offset 0x1B3EC, size 0x400
	unsigned char * txdp[256]; // offset 0x1B7EC, size 0x400
    short txloff[256]; // offset 0x1BBEC, size 0x200
    short txb_ct; // offset 0x1BDEC, size 0x2
    short txb_n; // offset 0x1BDEE, size 0x2
    short txb[256]; // offset 0x1BDF0, size 0x200
	NJS_TEXLIST* txblp[256]; // offset 0x1BFF0, size 0x400
	NO_NAME_5 txbp[256]; // offset 0x1C3F0, size 0x1400
	unsigned char* ef_psp; // offset 0x1D7F0, size 0x4
	NJS_TEXNAME ef_tex[450]; // offset 0x1D7F4, size 0x1518
	NJS_TEXLIST ef_tlist; // offset 0x1ED0C, size 0x8
	NO_NAME_6 ef; // offset 0x1ED14, size 0x28
	short efid[256]; // offset 0x1ED3C, size 0x200
	NO_NAME_2 efm[450]; // offset 0x1EF3C, size 0x2A30
	int ef_ct; // offset 0x2196C, size 0x4
    int ef_ctb; // offset 0x21970, size 0x4
    int ef_extn; // offset 0x21974, size 0x4
    int ef_tn[450]; // offset 0x21978, size 0x708
    unsigned char ef_pbkb[450]; // offset 0x22080, size 0x1C2
    int ef_pbnk; // offset 0x22244, size 0x4
    int ef_slow; // offset 0x22248, size 0x4
    int ef_ctrn; // offset 0x2224C, size 0x4
    int yk_ct; // offset 0x22250, size 0x4
    int mg_ct; // offset 0x22254, size 0x4
    int bl_ct; // offset 0x22258, size 0x4
    int windr; // offset 0x2225C, size 0x4
    float winds; // offset 0x22260, size 0x4
    int windrb; // offset 0x22264, size 0x4
    float windsb; // offset 0x22268, size 0x4
    unsigned int thunder; // offset 0x2226C, size 0x4
    float gas_py; // offset 0x22270, size 0x4
    int en_objn; // offset 0x22274, size 0x4
    BH_PWORK * en_obj[16]; // offset 0x22278, size 0x40
    int ef_poln; // offset 0x222B8, size 0x4
    int ef_mdfn; // offset 0x222BC, size 0x4
    int ef_linn; // offset 0x222C0, size 0x4
    int ef_ntxn; // offset 0x222C4, size 0x4
    int ef_trsn; // offset 0x222C8, size 0x4
    int ef_pncn; // offset 0x222CC, size 0x4
    int ef_opqn; // offset 0x222D0, size 0x4
    int ef_thln; // offset 0x222D4, size 0x4
    int ef_ntx2dn; // offset 0x222D8, size 0x4
    int ef_trs2dn; // offset 0x222DC, size 0x4
    int ef_pnc2dn; // offset 0x222E0, size 0x4
    int ef_fncn; // offset 0x222E4, size 0x4
	NO_NAME_4* ef_pol[512]; // offset 0x222E8, size 0x800
	NO_NAME_4* ef_mdf[128]; // offset 0x22AE8, size 0x200
	NO_NAME_4* ef_lin[512]; // offset 0x22CE8, size 0x800
	NO_NAME_4* ef_ntx[512]; // offset 0x234E8, size 0x800
	NO_NAME_4* ef_trs[512]; // offset 0x23CE8, size 0x800
	NO_NAME_4* ef_pnc[512]; // offset 0x244E8, size 0x800
	NO_NAME_4* ef_opq[512]; // offset 0x24CE8, size 0x800
	NO_NAME_4* ef_thl[512]; // offset 0x254E8, size 0x800
	NO_NAME_4* ef_ntx2d[128]; // offset 0x25CE8, size 0x200
	NO_NAME_4* ef_trs2d[128]; // offset 0x25EE8, size 0x200
	NO_NAME_4* ef_pnc2d[128]; // offset 0x260E8, size 0x200
	NO_NAME_4* ef_fnc[512]; // offset 0x262E8, size 0x800
	int ob_nlgn; // offset 0x26AE8, size 0x4
    int ob_hlgn; // offset 0x26AEC, size 0x4
    int ob_spcn; // offset 0x26AF0, size 0x4
	NO_NAME_4* ob_nlg[32]; // offset 0x26AF4, size 0x80
	NO_NAME_4* ob_hlg[32]; // offset 0x26B74, size 0x80
	NO_NAME_4* ob_spc[32]; // offset 0x26BF4, size 0x80
	unsigned int ren_gid; // offset 0x26C74, size 0x4
	NJS_TEXINFO ren_info; // offset 0x26C78, size 0x2C
	NJS_TEXNAME ren_tex[1]; // offset 0x26CA4, size 0xC
	NJS_TEXLIST ren_tlist; // offset 0x26CB0, size 0x8
	NJS_TEXTUREH_VTX rpb[256]; // offset 0x26CB8, size 0x1C00
	int ren_n; // offset 0x288B8, size 0x4
    int ren_idx[4]; // offset 0x288BC, size 0x10
    int wt_nbpt; // offset 0x288CC, size 0x4
    float wt_px; // offset 0x288D0, size 0x4
    float wt_pz; // offset 0x288D4, size 0x4
    int wt_xp; // offset 0x288D8, size 0x4
    int wt_zp; // offset 0x288DC, size 0x4
    int wt_minx; // offset 0x288E0, size 0x4
    int wt_minz; // offset 0x288E4, size 0x4
    int wt_maxx; // offset 0x288E8, size 0x4
    int wt_maxz; // offset 0x288EC, size 0x4
    unsigned char * wt_wvp; // offset 0x288F0, size 0x4
	NJS_PLANE mr_pl; // offset 0x288F4, size 0x18
	unsigned char * zan_memp; // offset 0x2890C, size 0x4
    unsigned char * zanp; // offset 0x28910, size 0x4
	NO_NAME_8* lgtp; // offset 0x28914, size 0x4
	float lg_vx; // offset 0x28918, size 0x4
    float lg_vy; // offset 0x2891C, size 0x4
    float lg_vz; // offset 0x28920, size 0x4
    float lg_r; // offset 0x28924, size 0x4
    float lg_g; // offset 0x28928, size 0x4
    float lg_b; // offset 0x2892C, size 0x4
    int lg_pnt; // offset 0x28930, size 0x4
	NO_NAME_9 lg_ptb[4]; // offset 0x28934, size 0x80
	int mes_idx; // offset 0x289B4, size 0x4
    unsigned int * mes_dp; // offset 0x289B8, size 0x4
    int mes_ct; // offset 0x289BC, size 0x4
    int mes_tim; // offset 0x289C0, size 0x4
    int mes_fls; // offset 0x289C4, size 0x4
    int mes_sel; // offset 0x289C8, size 0x4
    int mes_seln; // offset 0x289CC, size 0x4
	NJS_POINT2 mes_sps[16]; // offset 0x289D0, size 0x80
	int rt_sp; // offset 0x28A50, size 0x4
    unsigned char * rt_wp; // offset 0x28A54, size 0x4
    unsigned char * rt_dp; // offset 0x28A58, size 0x4
    unsigned char * rt_nw; // offset 0x28A5C, size 0x4
    unsigned char * rt_nx; // offset 0x28A60, size 0x4
    float * rt_ln; // offset 0x28A64, size 0x4
    BH_PWORK * plp; // offset 0x28A68, size 0x4
	NO_NAME_10* pl_htp; // offset 0x28A6C, size 0x4
	int costume; // offset 0x28A70, size 0x4
	NJS_POINT3 hd_pos; // offset 0x28A74, size 0xC
	NJS_POINT3 apos; // offset 0x28A80, size 0xC
	NO_NAME_10* ahtp; // offset 0x28A8C, size 0x4
	int mwal_n; // offset 0x28A90, size 0x4
    int metc_n; // offset 0x28A94, size 0x4
    int mflr_n; // offset 0x28A98, size 0x4
	NO_NAME_10 mwalp[64]; // offset 0x28A9C, size 0x900
	NO_NAME_10 metcp[64]; // offset 0x2939C, size 0x900
	NO_NAME_10 mflrp[64]; // offset 0x29C9C, size 0x900
	int dla_n; // offset 0x2A59C, size 0x4
	NO_NAME_10* htp; // offset 0x2A5A0, size 0x4
	int psh_snd; // offset 0x2A5A4, size 0x4
    int fog_cngct; // offset 0x2A5A8, size 0x4
    unsigned int fog_col; // offset 0x2A5AC, size 0x4
    float fog_nr; // offset 0x2A5B0, size 0x4
    float fog_fr; // offset 0x2A5B4, size 0x4
    float fade_ct; // offset 0x2A5B8, size 0x4
    float fade_hkn; // offset 0x2A5BC, size 0x4
    float fade_ao; // offset 0x2A5C0, size 0x4
    float fade_an; // offset 0x2A5C4, size 0x4
    float fade_ap; // offset 0x2A5C8, size 0x4
    float fade_ro; // offset 0x2A5CC, size 0x4
    float fade_rn; // offset 0x2A5D0, size 0x4
    float fade_rp; // offset 0x2A5D4, size 0x4
    float fade_go; // offset 0x2A5D8, size 0x4
    float fade_gn; // offset 0x2A5DC, size 0x4
    float fade_gp; // offset 0x2A5E0, size 0x4
    float fade_bo; // offset 0x2A5E4, size 0x4
    float fade_bn; // offset 0x2A5E8, size 0x4
    float fade_bp; // offset 0x2A5EC, size 0x4
    unsigned int fade_pbk; // offset 0x2A5F0, size 0x4
    unsigned short ssv_md0; // offset 0x2A5F4, size 0x2
    unsigned short ssv_md1; // offset 0x2A5F6, size 0x2
    int ssv_tim; // offset 0x2A5F8, size 0x4
    float ssv_ct; // offset 0x2A5FC, size 0x4
    float ssv_hkn; // offset 0x2A600, size 0x4
    float ssv_ao; // offset 0x2A604, size 0x4
    float ssv_an; // offset 0x2A608, size 0x4
    float ssv_ap; // offset 0x2A60C, size 0x4
    short fil_no; // offset 0x2A610, size 0x2
    short fil_rt; // offset 0x2A612, size 0x2
    float rvf_sc; // offset 0x2A614, size 0x4
    float rvf_sn; // offset 0x2A618, size 0x4
    unsigned int rvfc[4]; // offset 0x2A61C, size 0x10
    float cine_an; // offset 0x2A62C, size 0x4
    float cine_ap; // offset 0x2A630, size 0x4
    unsigned int sco_flg; // offset 0x2A634, size 0x4
    float amb_r[4]; // offset 0x2A638, size 0x10
    float amb_g[4]; // offset 0x2A648, size 0x10
    float amb_b[4]; // offset 0x2A658, size 0x10
    int sb_id; // offset 0x2A668, size 0x4
    int sb_cmd; // offset 0x2A66C, size 0x4
    int sb_rdid; // offset 0x2A670, size 0x4
    int sb_rdsz; // offset 0x2A674, size 0x4
    void * sb_rdp; // offset 0x2A678, size 0x4
    void * sb_mlb; // offset 0x2A67C, size 0x4
    void * sb_ppp; // offset 0x2A680, size 0x4
	NJS_TEXLIST* sb_tlist; // offset 0x2A684, size 0x4
	int ddmd; // offset 0x2A688, size 0x4
	DOOR_WORK door; // offset 0x2A68C, size 0x1C
	int mpmd; // offset 0x2A6A8, size 0x4
    int mp_prm[4]; // offset 0x2A6AC, size 0x10
    unsigned short gov_md0; // offset 0x2A6BC, size 0x2
    unsigned short gov_md1; // offset 0x2A6BE, size 0x2
    int gov_ct; // offset 0x2A6C0, size 0x4
    void * gov_exp; // offset 0x2A6C4, size 0x4
    unsigned int com_flg; // offset 0x2A6C8, size 0x4
    unsigned short com_md0; // offset 0x2A6CC, size 0x2
    unsigned short com_md1; // offset 0x2A6CE, size 0x2
    unsigned int com_num; // offset 0x2A6D0, size 0x4
    void * com_exp; // offset 0x2A6D4, size 0x4
    short ond_tnm; // offset 0x2A6D8, size 0x2
    short ond_ud; // offset 0x2A6DA, size 0x2
    char ond_cx; // offset 0x2A6DC, size 0x1
    char ond_n[3]; // offset 0x2A6DD, size 0x3
    unsigned char ufo_md; // offset 0x2A6E0, size 0x1
    unsigned char ufo_flg; // offset 0x2A6E1, size 0x1
    short ufo_oidx; // offset 0x2A6E2, size 0x2
	NJS_POINT3 ufo_pos; // offset 0x2A6E4, size 0xC
	unsigned int opt_flg; // offset 0x2A6F0, size 0x4
    unsigned short opt_md0; // offset 0x2A6F4, size 0x2
    unsigned short opt_md1; // offset 0x2A6F6, size 0x2
    void * opt_exp; // offset 0x2A6F8, size 0x4
    unsigned int etc_idx; // offset 0x2A6FC, size 0x4
    unsigned int flr_idx; // offset 0x2A700, size 0x4
    int mvi_no; // offset 0x2A704, size 0x4
    int mvi_tp; // offset 0x2A708, size 0x4
    unsigned short mvi_md; // offset 0x2A70C, size 0x2
    unsigned short mvi_flg; // offset 0x2A70E, size 0x2
    unsigned int mvi_tsb; // offset 0x2A710, size 0x4
    unsigned int mvi_spb; // offset 0x2A714, size 0x4
    unsigned char * mvi_memp; // offset 0x2A718, size 0x4
    unsigned int dcg_tkbak; // offset 0x2A71C, size 0x4
    unsigned int dcg_tsbak; // offset 0x2A720, size 0x4
    unsigned int pau_spbak; // offset 0x2A724, size 0x4
    unsigned int pau_pad_on; // offset 0x2A728, size 0x4
    unsigned int pau_pad_ps; // offset 0x2A72C, size 0x4
    unsigned int pau_pad_old; // offset 0x2A730, size 0x4
    unsigned char * pdm_dp; // offset 0x2A734, size 0x4
    unsigned char * pdm_pd; // offset 0x2A738, size 0x4
    int pdm_keytpb; // offset 0x2A73C, size 0x4
    int gat_ct; // offset 0x2A740, size 0x4
	CONICAL_FRUSTUM gatc[16]; // offset 0x2A744, size 0x200
	int ght_ct; // offset 0x2A944, size 0x4
    unsigned int ghtc[32]; // offset 0x2A948, size 0x80
	NJS_POINT3 ghtp[32]; // offset 0x2A9C8, size 0x180
	unsigned short db_md0; // offset 0x2AB48, size 0x2
    unsigned short db_md1; // offset 0x2AB4A, size 0x2
    char db_stgno; // offset 0x2AB4C, size 0x1
    char db_romno; // offset 0x2AB4D, size 0x1
    char db_rcase; // offset 0x2AB4E, size 0x1
    char db_muteki; // offset 0x2AB4F, size 0x1
    short db_px; // offset 0x2AB50, size 0x2
    short db_py; // offset 0x2AB52, size 0x2
    int db_mes; // offset 0x2AB54, size 0x4
    int calc_v; // offset 0x2AB58, size 0x4
    unsigned int brkfg; // offset 0x2AB5C, size 0x4
    char brkfg_typ[32]; // offset 0x2AB60, size 0x20
    short brkfg_bit[32]; // offset 0x2AB80, size 0x40
    unsigned int brkfg_tkb; // offset 0x2ABC0, size 0x4
    unsigned int brkfg_tsb; // offset 0x2ABC4, size 0x4
    int brkfg_ct; // offset 0x2ABC8, size 0x4
    unsigned int bmt_size; // offset 0x2ABCC, size 0x4
    unsigned int lmt_size; // offset 0x2ABD0, size 0x4
    unsigned int emt_size; // offset 0x2ABD4, size 0x4
    unsigned int wmt_size; // offset 0x2ABD8, size 0x4
    char mes[256]; // offset 0x2ABDC, size 0x100
    float sfx; // offset 0x2ACDC, size 0x4
    float sfy; // offset 0x2ACE0, size 0x4
    float sfxn; // offset 0x2ACE4, size 0x4
    float sfyn; // offset 0x2ACE8, size 0x4
    float sfct; // offset 0x2ACEC, size 0x4
} SYS_WORK;
