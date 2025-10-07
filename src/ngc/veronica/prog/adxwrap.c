#include "structs.h"

void InitAdx();
void ExitAdx();
void DeletePartition(unsigned int PartitionId);
int CreatePartitionEx(AFS_PATINFO* ap);
void DeletePartitionEx(AFS_PATINFO* ap);
int SearchAdxFSlot();
int OpenAfsInsideFile(unsigned int PartitionId, unsigned int FileId);
int OpenAfsIsoFile(char* FileName);
int GetAfsInsideFileSize(int SlotNo);
void RequestReadAfsInsideFile(int SlotNo, unsigned char* Address);
int CheckReadEndAfsInsideFile(int SlotNo);
void CloseAfsInsideFile(int SlotNo);
void StopAfsInsideFile(int SlotNo);
void RegistAdxStreamEx(int MaxStream, int DummyStream, ADX_WORK* pAdx);
void FreeAdxStream();
void SleepAdxStream();
void WakeupAdxStream(ADX_WORK* pAdx);
void PlayAdxEx(unsigned int SlotNo, unsigned int PartitionId, unsigned int FileId, int Flag);
void PlayAdx(unsigned int SlotNo, unsigned int PartitionId, unsigned int FileId);
void StopAdx(unsigned int SlotNo);
void PauseAdx(unsigned int SlotNo);
void ContinueAdx(unsigned int SlotNo);
int GetAdxStatus(unsigned int SlotNo);
void SetVolumeAdx(unsigned int SlotNo, int Volume);
void SetVolumeAdxEx(unsigned int SlotNo, float Volume, float MaxVolume);
void SetVolumeAdx2(unsigned int SlotNo, float Volume);
void SetPanAdx2(unsigned int SlotNo, int Channel, float Pan); // second parameter is not present on the debugging symbols
void SetPanAdx(unsigned int SlotNo, int Channel, int Pan);
int GetAdxPlayTime(unsigned int SlotNo);
void RequestAdxFadeFunction2(int SlotNo, int Func, int Timer, int FirstVolume);
void RequestAdxFadeFunction(int SlotNo, int Func, int Timer);
void RequestAdxFadeFunctionEx(int SlotNo, int StartVol, int LastVol, int Frame);
int ExecAdxFadeManager();

char last_rdx_files[256];
char last_adx_files[256];
char last_file_id;
char adx_status;
int RDX_SIZE;
unsigned int RDX_CHECK_SAM;
int RDX_TOP;
unsigned int READ_RDX_NO;
char cf_area[5628];
ADXT_SPRM cf_prm = { "\\cf_rom.txt", cf_area, 5092, 0, 0, 0, 0 };
short AdxVolTbl[128] = { 0, -2, -4, -6, -8, -10, -12, -14, -16, -18, -20, -22, -24, -26, -28, -30, -32, -34, -36, -38, -40, -42, -44, -46, -48, -50, -52, -54, -56, -58, -60, -62, -64, -70, -76, -82, -88, -94, -100, -106, -112, -118, -124, -130, -136, -142, -148, -154, -160, -166, -172, -178, -184, -190, -196, -202, -208, -214, -220, -226, -232, -238, -244, -250, -256, -264, -272, -280, -288, -296, -304, -312, -320, -328, -336, -344, -352, -360, -368, -376, -384, -392, -400, -408, -416, -424, -432, -440, -448, -456, -464, -472, -480, -488, -496, -504, -512, -528, -544, -560, -576, -592, -608, -624, -640, -656, -672, -688, -704, -720, -736, -752, -768, -784, -800, -816, -832, -848, -864, -880, -896, -912, -928, -944, -960, -976, -992, -999 };
int AdxStreamSleepFlag;
int MaxAdxStreamCnt;
ADXT_INFO AdxTInfo[4];
ADXF_INFO AdxFInfo[8];
AFS_INFO AfsInfo[16];
unsigned char RDX_FILE_PARTISION[880];
int rdx_image_data_max = 205;
char* rdx_files[205];
int ADX_STREAM_BUFF_OFFSET[2] = { 0, 307456 }; 
char ADX_STREAM_BUFFER[471040];

// InitAdx

void ExitAdx()
{ 
    ADXT_Finish();
}

void DeletePartition(unsigned int PartitionId)
{
    if (AfsInfo[PartitionId].Flag != 0)
    {
        syFree(AfsInfo[PartitionId].pInfoPart);
        
        AfsInfo[PartitionId].Flag = 0;
    }
}

// CreatePartitionEx 

void DeletePartitionEx(AFS_PATINFO* ap)
{
    for ( ; ; ap++) 
    {
        if (ap->AfsFileName == NULL)
        {
            break;
        }
        
        AfsInfo[ap->PartitionId].Flag = 0; 
    } 
} 

int SearchAdxFSlot() 
{
    unsigned int i;
    
    for (i = 0; i < 8; i++) 
    { 
        if (AdxFInfo[i].Flag == 0)
        { 
            return i; 
        }
    } 
    
    return -1; 
} 

int OpenAfsInsideFile(unsigned int PartitionId, unsigned int FileId)
{
    unsigned int SlotNo; 
    
    SlotNo = SearchAdxFSlot();
    
    AdxFInfo[SlotNo].Handle = ADXF_OpenAfs(PartitionId, FileId);
    
    if (AdxFInfo[SlotNo].Handle == NULL) 
    {
        return -1;
    }
    
    AdxFInfo[SlotNo].Mode = -1;
    
    AdxFInfo[SlotNo].Flag = 1;
    
    return SlotNo;
}

// OpenAfsIsoFile

int GetAfsInsideFileSize(int SlotNo)
{
    if (AdxFInfo[SlotNo].Flag != 0) 
    {
        return ADXF_GetFsizeByte(AdxFInfo[SlotNo].Handle);
    }
    
    return 0;
}

void RequestReadAfsInsideFile(int SlotNo, unsigned char* Address)
{
    if (AdxFInfo[SlotNo].Flag != 0) 
    {
        GetAfsInsideFileSize(SlotNo);

        fn_80191C1C(SlotNo, Address);
        
        ADXF_ReadNw32(AdxFInfo[SlotNo].Handle, ADXF_GetFsizeSct(AdxFInfo[SlotNo].Handle), Address);
        
        AdxFInfo[SlotNo].Mode = 0;
    }
}

int CheckReadEndAfsInsideFile(int SlotNo)
{
    if ((AdxFInfo[SlotNo].Flag != 0) && (ADXF_GetStat(AdxFInfo[SlotNo].Handle) == 3)) 
    {
        if (AdxFInfo[SlotNo].Mode == 0) 
        {
            CloseAfsInsideFile(SlotNo);
        }
        
        return 1;
    }
    
    return 0;
}

void CloseAfsInsideFile(int SlotNo)
{
    if (AdxFInfo[SlotNo].Flag != 0)
    {
        ADXF_Close(AdxFInfo[SlotNo].Handle);
        
        AdxFInfo[SlotNo].Flag = 0;
    }
}

void StopAfsInsideFile(int SlotNo) 
{
    if (AdxFInfo[SlotNo].Flag != 0) 
    {
        ADXF_Stop(AdxFInfo[SlotNo].Handle);
        
        CloseAfsInsideFile(SlotNo);
    }
}

// RegistAdxStreamEx 

void FreeAdxStream()
{
    int i;
    
    for (i = MaxAdxStreamCnt - 1; i >= 0; i--) 
    {
        if (AdxStreamSleepFlag == 0) 
        {
            ADXT_SetOutVol(AdxTInfo[i].Handle, -999);
            
            ADXT_Stop(AdxTInfo[i].Handle);
            
            ADXT_Destroy(AdxTInfo[i].Handle);
        }
    } 
    
    MaxAdxStreamCnt = 0;
}

void SleepAdxStream()
{
    int i;
    
    if (AdxStreamSleepFlag == 0) 
    {
        for (i = 0; i < MaxAdxStreamCnt; i++) 
        {
            ADXT_SetOutVol(AdxTInfo[i].Handle, -999);
            
            ADXT_Stop(AdxTInfo[i].Handle);
            
            ADXT_Destroy(AdxTInfo[i].Handle);
        }
        
        AdxStreamSleepFlag = 1;
    }
}

void WakeupAdxStream(ADX_WORK* pAdx)
{
    int i;
    ADXT_INFO* tp;

    if (AdxStreamSleepFlag != 0) 
    {
        for (i = 0; i < MaxAdxStreamCnt; i++, pAdx++) 
        {
            AdxTInfo[i].Handle = ADXT_Create(pAdx->MaxChannel, AdxTInfo[i].pAdxTWork, AdxTInfo[i].WorkSize);
            
            if (pAdx->RecoverType != -1) 
            {
                ADXT_SetAutoRcvr(AdxTInfo[i].Handle, pAdx->RecoverType);
            }
            
            if (pAdx->ReloadSector >= 0) 
            {
                ADXT_SetReloadSct(AdxTInfo[i].Handle, pAdx->ReloadSector);
            }
            
            AdxTInfo[i].FadeFunc = 0;
            
            AdxTInfo[i].Flag = 0;
        }
        
        AdxStreamSleepFlag = 0;
    }
}

// PlayAdxEx

void PlayAdx(unsigned int SlotNo, unsigned int PartitionId, unsigned int FileId)
{ 
    PlayAdxEx(SlotNo, PartitionId, FileId, 0);
}

void StopAdx(unsigned int SlotNo)
{
    if (AdxTInfo[SlotNo].Flag != 0) 
    {
        ADXT_Stop(AdxTInfo[SlotNo].Handle);
    }
    
    AdxTInfo[SlotNo].Flag = 0;
}

void PauseAdx(unsigned int SlotNo)
{
    ADXT_Pause(AdxTInfo[SlotNo].Handle, 1);
}

void ContinueAdx(unsigned int SlotNo)
{
    ADXT_Pause(AdxTInfo[SlotNo].Handle, 0);
}

int GetAdxStatus(unsigned int SlotNo)
{
    ADXT_GetStat(AdxTInfo[SlotNo].Handle);
}

void SetVolumeAdx(unsigned int SlotNo, int Volume)
{
    SetVolumeAdx2(SlotNo, Volume);
}

void SetVolumeAdxEx(unsigned int SlotNo, float Volume, float MaxVolume)
{
    if (MaxVolume < -20.0f) 
    {
        MaxVolume += 20.0f;
    }
    else 
    {
        MaxVolume = 0;
    }

    AdxTInfo[SlotNo].LimitMaxVol = MaxVolume;
    
    SetVolumeAdx2(SlotNo, Volume);
}

void SetVolumeAdx2(unsigned int SlotNo, float Volume)
{
    int temp; // not from the debugging symbols
    
    if (AdxTInfo[SlotNo].Handle->used != 0) 
    {
        temp = AdxVolTbl[(int)-Volume];
        
        if (SlotNo == 0) 
        {
            temp -= 25;
            
            if (temp > 0) 
            {
                temp = 0;
            }
            
            if (temp < -960)
            {
                temp = -960;
            }
        }
        
        ADXT_SetOutVol(AdxTInfo[SlotNo].Handle, temp);
    }
    
    AdxTInfo[SlotNo].Volume = Volume;
}

void SetPanAdx2(unsigned int SlotNo, int Channel, float Pan) 
{
    AdxTInfo[SlotNo].Pan = Pan;
}

void SetPanAdx(unsigned int SlotNo, int Channel, int Pan) 
{ 
    SetPanAdx2(SlotNo, Channel, Pan);
}

int GetAdxPlayTime(unsigned int SlotNo)
{
    int SampleCount;
    int SamplingRate;
    
    ADXT_GetTime(AdxTInfo[SlotNo].Handle, &SampleCount, &SamplingRate);
    
    return ((double)SampleCount / SamplingRate) * 100.0f;
}

void RequestAdxFadeFunction2(int SlotNo, int Func, int Timer, int FirstVolume)
{
    float Cnt; 
    ADXT_INFO* tp; 
    
    tp = &AdxTInfo[SlotNo];
    
    tp->FadeCntMax = ((Timer / 100) * 30) + (((Timer % 100) * 6) / 10);
    
    tp->FadeCntMax /= 2;
    
    if (tp->FadeCntMax == 0) 
    {
        tp->FadeCntMax = 1;
    }
    
    if (FirstVolume != 1) 
    {
        tp->Volume = FirstVolume;
    }
    
    switch (Func) 
    {                               
    case 1:
        tp->VolLast = tp->LimitMaxVol;
        break;
    case 2:
        tp->VolLast = -127.0f;
        break;
    }
    
    Cnt = tp->Volume - tp->VolLast;
    
    if (tp->FadeCntMax != 0) 
    {
        tp->VolSpeed = Cnt / tp->FadeCntMax;
    }
    else
    {
        tp->VolSpeed = 0;
    }
    
    tp->VolSave = tp->Volume;
    
    tp->FadeFunc = Func;
}

void RequestAdxFadeFunction(int SlotNo, int Func, int Timer)
{ 
    RequestAdxFadeFunction2(SlotNo, Func, Timer, 1);
}

void RequestAdxFadeFunctionEx(int SlotNo, int StartVol, int LastVol, int Frame)
{
    ADXT_INFO* tp; 
    
    tp = &AdxTInfo[SlotNo];
    
    if (StartVol == -1)
    {
        StartVol = tp->Volume;
    }
    
    tp->Volume = StartVol;
    tp->VolLast = LastVol;
    
    tp->FadeCntMax = Frame;
    
    if (Frame != 0) 
    {
        tp->VolSpeed = -((tp->VolLast - tp->Volume) / tp->FadeCntMax);
    }
    
    tp->FadeFunc = 1;
}

// ExecAdxFadeManager
