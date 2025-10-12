#include "structs.h"

int OpenDriveTrayFlag;
ROM_WORK* rom;
CAM_WORK cam;
unsigned char BackColorFlag;
int pd_port;
unsigned int palbuf[4096];
unsigned char Pause_Flag;
int SoftResetFlag;

// TODO: import this variable from its original file
SYS_WORK* sys;

void bhInitVSync();
void bhClearVSync();
void bhControlVSync();
void bhControlEOR();
void bhCheckPadPort();
void bhCheckSoftReset();

void bhInitVSync()
{
    njSetVSyncFunction(bhControlVSync);
    njSetEORFunction(bhControlEOR);
}

void bhClearVSync()
{
    njSetVSyncFunction(NULL);
    njSetEORFunction(NULL);
}

void bhControlVSync()
{
    sys->vsyc_flg++;
    sys->vsyc_ct++;
    
    if (sys->vsyc_ct >= 60) 
    {
        sys->vsyc_ct = 0;
        
        sys->gframe = sys->gfrm_ct;
        
        sys->gfrm_ct = 0;
    }
    
    if ((sys->tk_flg & 0x80))
    {
        if (((sys->gm_flg & 0x80000000)) && (sys->time < 216000000))
        {
            sys->time++;
        }
        
        if (bhCkFlg(sys->ev_flg, 3) != 0) 
        {
            if (sys->stv_tm < 216000000)
            {
                sys->stv_tm++;
            }
        }
        
        if (((sys->sp_flg & 0x200)) && (sys->evt_tim != 0)) 
        {
            if (fn_80183950() != 0) 
            {
                sys->evt_tim--;
            }
            
            switch (sys->evt_tmd) 
            {                  
            case 1:
                if (bhCkFlg(sys->ev_flg, 69) == 0)
                {
                    sys->evt_tmd = 0;
                    sys->evt_tim = 0;
                }
                
                break;
            case 2:
                if (bhCkFlg(sys->ev_flg, 67) == 0)
                {
                    sys->evt_tmd = 0;
                    sys->evt_tim = 0;
                }
                
                break;
            case 3:
                if (bhCkFlg(sys->ev_flg, 70) == 0) 
                {
                    sys->evt_tmd = 0;
                    sys->evt_tim = 0;
                }
                
                break;
            }
        }
    }
}

// bhControlEOR

void bhCheckPadPort()
{
    pd_port = 0;
}

void bhCheckSoftReset()
{
    if (((!(sys->ss_flg & 0x20000)) && ((sys->tk_flg & 0x3F)) || (!(sys->ss_flg & 0x20000)) && ((sys->ss_flg & 0x400000))) && (SoftResetFlag == 1))
    {
        SoftResetFlag = 0;
    }
}
