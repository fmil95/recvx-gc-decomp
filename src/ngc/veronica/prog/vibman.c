#include "structs.h"

void InitVibrationUnit();
void ExitVibrationUnit();
void SetUseVibrationUnit(int Flag);
int GetUseVibrationUnit();
int CheckVibrationUnit(unsigned int PortId);
int StartVibration(unsigned int PortId, PDS_VIBPARAM* vpp);
int StopVibration(unsigned int PortId);

char PortIdTbl[/*4*/] = { 2, 8, 14, 20, 0, 0, 0, 0 };
int EnadleVibrationFlag;
unsigned int VibStopTime;

void InitVibrationUnit()
{ 
    int i;

    VibStopTime = 20;

    for (i = 0; i < 4; i++) 
    { 
        if (CheckVibrationUnit(PortIdTbl[i]) == 1) 
        { 
            pdVibMxSetStopTime(PortIdTbl[i], VibStopTime); 
        } 
    } 

    EnadleVibrationFlag = 0; 
} 

void ExitVibrationUnit()
{ 
    int i;

    for (i = 0; i < 4; i++) 
    { 
        if (CheckVibrationUnit(PortIdTbl[i]) == 1) 
        { 
            StopVibration(PortIdTbl[i]); 
        }
    } 
} 

void SetUseVibrationUnit(int Flag)
{
    EnadleVibrationFlag = Flag;
}

int GetUseVibrationUnit()
{
    return EnadleVibrationFlag; 
} 

int CheckVibrationUnit(unsigned int PortId)
{
    return pdVibMxIsReady(PortId); 
}

int StartVibration(unsigned int PortId, PDS_VIBPARAM* vpp) 
{ 
    if (EnadleVibrationFlag == 0) 
    { 
        return 0; 
    }

    if ((PortId % 6) != 2) 
    { 
        return -3; 
    }

    if (CheckVibrationUnit(PortId) != 1)
    { 
        return -2; 
    }

    vpp->unit = 1; 
    
    pdVibMxStart(PortId, vpp); 
} 

int StopVibration(unsigned int PortId)
{
    if (EnadleVibrationFlag == 0)
    { 
        return 0; 
    }
    
    if ((PortId % 6) != 2) 
    { 
        return -3;
    }

    if (CheckVibrationUnit(PortId) != 1) 
    {
        return -2;
    }
    
    return pdVibMxStop(PortId);
}
