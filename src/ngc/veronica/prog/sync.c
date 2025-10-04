#include "structs.h"

SYS_WORK* sys;
int OpenDriveTrayFlag;
// TODO: import structs for the two variables below
//ROM_WORK* rom; 
//CAM_WORK cam;
unsigned char BackColorFlag;
int pd_port;
unsigned int palbuf[4096];
unsigned char Pause_Flag;
int SoftResetFlag;

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

// bhControlVSync
// bhControlEOR
// bhCheckPadPort

void bhCheckSoftReset()
{
    if (((!(sys->ss_flg & 0x20000)) && ((sys->tk_flg & 0x3F)) || (!(sys->ss_flg & 0x20000)) && ((sys->ss_flg & 0x400000))) && (SoftResetFlag == 1))
    {
        SoftResetFlag = 0;
    }
}
