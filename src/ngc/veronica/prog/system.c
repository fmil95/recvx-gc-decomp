#include "structs.h"

SYS_WORK* sys;

int bhCalcVtxBuffer();
void bhChangeHWSetting();
void bhInitSystem();
void bhInitRoomChangeSystem();
void bhSysCallInit();
void bhSysCallDiscChange();
void bhSysCallSoundMuseum();
void bhSysCallWarning();
void bhSysCallIpl();
void bhSysCallFirstmovie();
void bhSysCallTitle();
void bhSysCallOpening();
void bhFirstGameStart();
void bhSysCallPad();
void bhSysCallGame();
void bhCheckSubTask();
void bhSysCallEvent();
void bhSysCallMap();
void bhSysCallItemselect();
void bhSysCallDoordemo();
void bhSysCallMovie();
void bhSysCallEnding();
void bhSysCallGameover();
void bhSysCallTypewriter();
void bhSysCallOption();
void bhSysCallCompEvent();
void bhSysCallMonitor();
void bhSysCallSndMonitor();
void bhSysCallScreenSaver();
void bhReturnTitle();
void bhExitGame();
void bhSetEventTimer(int mode);
void EasyDispMessage(float PosY, unsigned int MessageNo);

int bhCalcVtxBuffer()
{ 
    return 0;
}

// bhChangeHWSetting

// bhInitSystem
// bhInitRoomChangeSystem

void bhSysCallInit() 
{ 
    bhInitSystem(); 

    sys->tk_flg = 0x300002; 
} 

// SYS_WORK struct mismatch is preventing this one from getting to 100%
void bhSysCallDiscChange()
{ 
    njFogDisable(); 
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);  

    if (Adv_ChangeDiscScreen() != 0) 
    { 
        njWaitVSync(); 
        
        njSetPaletteMode(2); 
        
        sys->tk_flg = sys->dcg_tkbak; 
        sys->ts_flg = sys->dcg_tsbak; 
    }
} 

void bhSysCallSoundMuseum() 
{ 
    njFogDisable();
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);
    
    if (Adv_SoundMuseum() != 0) 
    { 
        sys->tk_flg = 0x300008;
    }
} 

void bhSysCallWarning()
{ 
    njFogDisable(); 
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
    
    if (Adv_FirstWarningMessage() != 0)
    { 
        sys->tk_flg = 0x300004; 
    }
} 

// bhSysCallIpl
// bhSysCallFirstmovie
// bhSysCallTitle
// bhSysCallOpening
// bhFirstGameStart
// bhSysCallPad
// bhSysCallGame
// bhCheckSubTask
// bhSysCallEvent
// bhSysCallMap
// bhSysCallItemselect
// bhSysCallDoordemo
// bhSysCallMovie
// bhSysCallEnding
// bhSysCallGameover
// bhSysCallTypewriter
// bhSysCallOption
// bhSysCallCompEvent
// bhSysCallMonitor
// bhSysCallSndMonitor
// bhSysCallScreenSaver
// bhReturnTitle
// bhExitGame

void bhSetEventTimer(int mode)
{ 
    sys->evt_tmd = mode + 1; 
    
    switch (mode) 
    { 
    case 0:
        bhStFlg(sys->ev_flg, 0x45); 
        
        sys->evt_tim = 2700; 
        
        sys->evt_tdg = 900; 
        break; 
    case 1:
        bhStFlg(sys->ev_flg, 0x43); 
        
        sys->evt_tim = 18000; 
        
        sys->evt_tdg = 3600; 
        break; 
    case 2:
        bhStFlg(sys->ev_flg, 0x46); 
        
        sys->evt_tim = 18000; 
        
        sys->evt_tdg = 3600; 
        
        sys->evt_fcd = 900; 
        sys->evt_fcdct = 0; 
        break;
    }
} 

// EasyDispMessage
