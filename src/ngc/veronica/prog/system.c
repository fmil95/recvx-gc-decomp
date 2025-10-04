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

// SYS_WORK struct mismatch is preventing this one from getting to 100%
void bhSysCallFirstmovie() 
{
    njFogDisable();
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);
    
    switch (Adv_BioCvTitle()) 
    {
    case 1:
        sys->ss_flg |= 0x400200;
        
        sys->pdm_keytpb = sys->keytype;
        
        sys->keytype = 0;
        
        sys->tk_flg = 0x300010;
        break;
    case 2:
        sys->ss_flg &= ~0x200;
        sys->tk_flg = 0x300010;
        break;
    case 3:
        sys->ss_flg |= 0x200;
        sys->tk_flg = 0x308040;
        
        *(int*)&sys->typ_md0 = 0;
        break;
    case 4:
        sys->tk_flg = 0x310000;
        
        *(int*)&sys->typ_md0 = 0;
        break;
    case 5:
        sys->tk_flg = 0x380000;
        break;
    case 6:
        sys->ss_flg &= ~0x200;
        sys->tk_flg = 0x300010;
        break;
    }
}

void bhSysCallTitle() 
{ 
    njFogDisable(); 
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);
    
    sys->tk_flg = 0x300020; 
} 

void bhSysCallOpening() 
{ 
    njFogDisable(); 
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
    
    bhFirstGameStart(); 
} 

// bhFirstGameStart

void bhSysCallPad() 
{ 
    if ((sys->ss_flg & 0x40000000)) 
    { 
        sys->sp_flg = ~0x0; 
        sys->ss_flg &= ~0x40000000;
    }
    
    if ((sys->sp_flg & 0x20))
    {
        bhSetPad();
    }

    if (((sys->cb_flg & 0x4)) || (((sys->tk_flg & 0x1000)) && (!(sys->ts_flg & 0x1000))))
    { 
        sys->pad_on &= 0x1FD188F; 
        sys->pad_ps &= 0x1FD188F; 
    }
} 

void bhSysCallGame()
{
    sys->pfm_cts = syTmrGetCount();
    
    sys->loop_ct = 1;
    
    if (((!(sys->st_flg & 0x1C040008)) && (!(sys->ss_flg & 0x80000000))) && (((sys->cb_flg & 0x4)) && ((sys->pad_ps & 0x10000)) && (!(sys->cb_flg & 0x10000000)))) 
    {
        sys->cb_flg |= 0x10000000;
    }
    
    bhCheckSubTask();
    
    bhMainSequence();
    
    sys->gm_flg |= 0x20000000;
    
    sys->gfrm_ct++;
}

// bhCheckSubTask
// bhSysCallEvent
// bhSysCallMap
// bhSysCallItemselect
// bhSysCallDoordemo
// bhSysCallMovie

void bhSysCallEnding() 
{ 
    ControlRanking();
}

void bhSysCallGameover()
{ 
    bhControlGameOver();
}

void bhSysCallTypewriter() 
{ 
    if ((sys->ts_flg & 0x80))
    { 
        njFogDisable(); 
    } 
    
    ControlTypewriter();
}

// bhSysCallOption

void bhSysCallCompEvent() 
{ 
    bhControlSpEvtComputer();
}

// bhSysCallMonitor
// bhSysCallSndMonitor
// bhSysCallScreenSaver

void bhReturnTitle()
{ 
    sys->ss_flg |= 0x20000; 
    
    bhExitGame(); 
    
    if (!(sys->ss_flg & 0x200000))
    { 
        sys->tk_flg = 0x300008;
    } 
    else 
    { 
        sys->ss_flg &= ~0x200000; 
        sys->tk_flg = 0x300004; 
    }
    
    sys->ts_flg = 0; 
    
    sys->ss_flg &= ~0x20000; 
    sys->ss_flg |= 0x1000; 
} 

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
