#include "structs.h"

typedef void(*fn)();

BH_PWORK ene[128];
BH_PWORK ply;
BH_PWORK* plp = &ply;
NJS_TEXMEMLIST tbuf[256];
NJS_VIEW view;
HWS_WORK hwsp;
HWS_WORK* hws = &hwsp;
SYS_WORK sysp;
SYS_WORK* sys = &sysp;
char BIO_CURRENT[64];
float BHD_ASPECT_X = 1.174f;
float BHD_ASPECT_Y = 1.0f;
NJS_MATRIX crmat;
NJS_MATRIX* cmat = &crmat;
float mbuf[128][16];
fn bhSysTaskJumpTab[23] /*= {
    bhSysCallInit,
    bhSysCallWarning,
    bhSysCallIpl,
    bhSysCallFirstmovie,
    bhSysCallTitle,
    bhSysCallOpening,
    bhSysCallPad,
    bhSysCallGame,
    bhSysCallEvent, 
    bhSysCallItemselect, 
    bhSysCallMap,
    bhSysCallDoordemo,
    bhSysCallMovie,
    bhSysCallEnding,
    bhSysCallGameover,
    bhSysCallTypewriter,
    bhSysCallOption,
    bhSysCallCompEvent,
    bhSysCallDiscChange,
    bhSysCallSoundMuseum,
    bhSysCallMonitor,
    bhSysCallSndMonitor,
    bhSysCallScreenSaver
}*/;
int pd_port = -1;
unsigned char* Ps2_PXLCONV;
unsigned char* freemem;
unsigned char* fsize;
unsigned char* keepmem;
unsigned char* njpmemp;
unsigned char* vebmemp;
unsigned char* vwbmemp;
unsigned int Ps2_sys_cnt;
//_anon18 cam;
//_anon27 eff[512];
ROM_WORK romp;
ROM_WORK* rom = &romp;

// 100% matching!
void* syMalloc(unsigned int nbytes); // TODO: remove this function declaration   
void njUserInit(void)
{ 
    switch (syCblCheck())
    {              
    case 1:
        hws->mode = 0x31; 
        
        hws->frame = 0; 
        
        hws->count = 2; 
        break; 
    case 2:
        hws->mode = 0x60076; 
        
        hws->frame = 0; 
        
        hws->count = 1; 
        break; 
    default:
        hws->mode = 0x34; 
        
        hws->frame = 0; 
        
        hws->count = 1; 
    }
    
    hws->vtx_opq_a = 0xFFF70000; 
    hws->vtx_opq_b = 32768; 
    
    hws->vtx_trs_a = 327680; 
    hws->vtx_trs_b = 32768; 
    
    hws->vtx_punch = 32512; 
    
    hws->vtx_total = bhCalcVtxBuffer(327680, 32768, 0xFFF70000); 
    
    InitFirstSofdec(); 
    
    njSetBorderColor(0x00000000);
    
    sbInitSystem(hws->mode, hws->frame, hws->count); 
    
    pdSetMode(0); 
    
    npSetMemory((unsigned char*)sys, sizeof(SYS_WORK), 0); 
    
    sys->ss_flg = 0x30000; 
   
    freemem = syMalloc(12845056); 
    
    njpmemp = freemem + (12255232 - hws->vtx_total); 
    
    Ps2_PXLCONV = njpmemp + 4294639616;
    
    vwbmemp = freemem + (12517376 - hws->vtx_total); 
    vebmemp = freemem + (12845056 - hws->vtx_total); 
    
    njInitTextureBuffer((signed char*)vwbmemp, 327680);
    
    njSetVertexBuffer((unsigned int*)vebmemp, hws->vtx_total); 

    njInitVertexBuffer(hws->vtx_opq_a, hws->vtx_opq_b, hws->vtx_trs_a, hws->vtx_trs_b, hws->vtx_punch);
    njInit3D((NJS_VERTEX_BUF*)vwbmemp, 8192); 
    njInitMatrix((NJS_MATRIX*)&mbuf, 128, 0);
    njInitPrint(NULL, 0, 0); 
    
    njPolygonCullingMode(0);
    
    njTextureShadingMode(2);
    
    njInitView(&view);
    
    njSetView(&view); 
    
    njGetMatrix(&crmat); 
    
    npPlusInit(); 
    
    njInitTexture((NJS_TEXMEMLIST*)&tbuf, 256); 
    
    njSetPaletteMode(2); 
    
    njPrintSize(13); 
    
    njSetAspect(BHD_ASPECT_X, BHD_ASPECT_Y); 
    
    njClipZ(-2.0f, -20000.0f); 
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000); 
    
    sys->ss_flg = 0;
    sys->tk_flg = 0x1; 

    BupInit(); 
  
    InitSoundProgram(0);
    
    Init_Expand(); 
}

// 100% matching!
Sint32 njUserMain(void) 
{ 
    int i; 

    Ps2_sys_cnt++; 
  
    for (i = 0; i < 23; i++) 
    { 
        if (((sys->tk_flg & (1 << i))) && (!(sys->ts_flg & (1 << i)))) 
        { 
            bhSysTaskJumpTab[i](); 
        } 
    } 
    
    PS2_jikken(); 
    
    bhCheckSoftReset(); 
    
    return 0; 
} 

// 100% matching!
void njUserExit(void)
{ 
    ExitSoundProgram();
    
    BupExit(); 
    
    njExitTexture();
    njExitPrint(); 
    
    sbExitSystem(); 
    
    syBtExit(); 
} 
