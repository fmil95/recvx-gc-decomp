#include "structs.h"

int PatId[4] = { -1, -1, -1, -1 };
AFS_PATINFO SoundAfsPatDef[8] =
{
    { "BGM?.AFS"    , 0, 128, NULL },
    { "VOICE?.AFS"  , 1, 768, NULL },
    { "MULTSPQ?.AFS", 2, 512, NULL },
    { "ADV.AFS"     , 3, 128, NULL },
    { "ITEM?.AFS"   , 4, 512, NULL },
    { "MRY.AFS"     , 5, 160, NULL },
    { "SYSTEM.AFS"  , 6, 256, NULL },
    { NULL          , 0, 0  , NULL }
};
ADX_WORK AdxDef[2] = { { 2, 48000, 2, -1 }, { 1, 48000, 2, -1 } };
int PlayerFootStepSwitch[3];
int SystemSeSlotSwitch;
int WeaponSeSlotSwitch;
int EnemyBackGroundSeFlag;
char MoviePlayTrayOpenFlag;
int CurrentBgmNo = -1;
int CurrentBgSeNo[2];
int RoomSoundCaseNo;
short DefBg[3];
short DefObj[5];
short DefEvt[5];
short DefEne[6];
int SoundInitLevel;
int SdReadMode;
int SpqFileReadRequestFlag;
int TransSoundPackDataFlag;
int ReadFileRequestFlag;
int FileReadStatus;
int KeyReadSwitch;
SYS_WORK* sys;
unsigned int DiscOpenTrayFlag;
unsigned int StatusUpdateCounter;
SYS_BT_SYSTEMID BootDiscSystemId;
HWS_WORK* hws;
SND_CMD SoundCommand;
MOV_INFO MovieInfo;
unsigned char* pConfigWork;
unsigned short* pSpqList;
unsigned char* pSoundAfs;
char SpqFileName[32];
int EventVibrationMode;
CAM_WORK cam;
NJS_POINT3 CameraPos;
NJS_POINT3 PlayerPos;
unsigned int AdxPlayFlag[2];
BH_PWORK* plp;
unsigned char* DestReadPtr;
int GenAdxfSlot;
int OpenDriveTrayFlag;
unsigned char MovieTypeDef[22] = { 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x80, 0x42, 0x82, 0x00, 0x80, 0x00, 0x82 };
short MovieVolDef[22] = { 0 }; 
MOV_DEF MovieDef[4] = { { 320, 240, 0, 0, 640, 448, 1 }, { 320, 176, 0, 64, 640, 320, 1 }, { 320, 352, 0, 64, 640, 320, 1 }, { 0, 0, 0, 0, 0, 0, 1 } };
RMI_WORK rmi;
PAD_WRK Pad[4];
int CurrentPortId;
PDS_VIBPARAM_EX VibP[32];
char VibFlag[5] = { 0x01, 0x08, 0x80, 0x09, 0x81 };
int SystemAdjustFlag;

int lbl_804E9764;

// bhReleaseFreeMemory
// ExitApplication
// QuickGetDiscTrayStatus 
// InitFirstSofdec 
// GetBootDiscId 
// InitSofdecSystem 
// ExitSofdecSystem 
// InitSoundProgram 
// ExitSoundProgram 
// MountSoundAfs 
void UnmountSoundAfs();
// ExecSoundSynchProgram 
// InitGameSoundSystem 
// SearchAfsInsideFileId 
// StopThePsgSound 
// CheckSpecialBank 
// LoadSoundPackFile 
// ExecTransSoundData 
// RequestRoomSoundBank 
// RequestArmsSoundBank 
// RequestDoorSoundBank 
// RequestPlayerVoiceSoundBank
// CheckTransEndSoundBank 
// SetRoomSoundCaseNo 
// GetRoomSoundCaseNo 
// CustomMidiSlotDef 
// ResetRoomSoundEnvParam 
// wadGetAngle 
// CheckCollision4Sound 
// Get3DSoundParameter 
// SetupSeGenericParm 
// Set3dSoundFlag 
// Reset3dSoundFlag 
// SetUserSoundVolume 
// SetUserSoundPan 
// PlayGameSe4Event 
// CallSystemSeBasic 
// CallSystemSeEx 
// CallSystemSe 
// StopSystemSe 
// SetSyukanModeSoundParam 
// CallPlayerVoice 
// GetPlayerActionSeSlotNo 
// CallPlayerFootStepSeEx 
// CallPlayerFootStepSe 
// CallPlayerActionSe
// CallPlayerWeaponSeEx 
// CallYakkyouSe 
// CallBackGroundSeEx 
// CallBackGroundSe 
// CallBackGroundSe2 
// StopBackGroundSeEx 
// StopBackGroundSe2 
// CallDoorSe 
// RequestEnemySeBasic
// RequestEnemySe 
// RequestEnemySeEx 
// ChechPlayEnemySe 
// AllStopEnemySe 
// CallEnemySe 
// StopEnemySe 
// CallNativeEventSe 
// StopNativeEventSe 
// RequestObjectSeEx 
// RegistObjectSe 
// FreeObjectSe 
// PlayBgmEx2 
// PlayBgmEx 
// PlayBgm 
// PlayBgm2 
// StopBgm 
// StopBgm2 
// PlayVoiceEx2 
// PlayVoiceEx 
// PlayVoice 
// ContinuePlayVoice 
// StopVoice 
// CheckPlayEndAdx 
// GetTimeAdx 
// SetRoomSoundFxLevel 
// SetRoomSoundFxLevelEx 
// SearchPlayingEnemySe 
// SearchFreeEnemySeSlot 
// CheckPlaySameSe 
// CallEnemySeMain 
// RegistEnemySlot 
// ResetEnemySeInfo 
// ExecEnemySeManager 
// SearchPlayingObjectSeEx 
// SearchPlayingObjectSe 
// SearchFreeObjectSeSlot 
// CallObjectSe2 
// RegistObjectSlot 
// ResetObjectSeInfo 
// ExecObjectSeManager 
// RequestSoundFade 
// RequestAllStopSoundEx
// ResetSoundComInfo 
// Com_ExecRoomFadeIn 
// Com_ExecRoomFadeOut 
// Com_ExecCallBgm_And_BgSe 
// Com_StartInitScript 
// Com_FinishInitScript 
// ExecuteSoundCommand 
// SendSoundCommand 
// ExecSoundSystemMonitor 
// RequestReadIsoFile 
// RequestReadInsideFile 
// GetIsoFileSize 
// GetInsideFileSize 
// GetReadFileStatus 
// fn_80157200 
void ExecFileManager();
// PlayStartMovieEx 
// PlayStopMovieEx
// PlayStopMovie 
// CheckPlayEndMovie 
// GetTimeMoive 
// WaitPrePlayMovie 
// PlayMovieMain
// SetEventVibrationMode
// StartVibrationBasic 
// StartVibrationEx 
// StopVibrationBasic 
// StopVibrationEx 
// SetAdjustDisplay 
void RequestAdjustDisplay(int AdjustX, int AdjustY);
void ExecAdjustDisplay();
void InitPlayLogSystem();
void ExitPlayLogSystem();
// ReadPlayLog 
// WritePlayLog 

// bhReleaseFreeMemory

void ExitApplication()
{ 
    fn_8017C30C(-1); // PS2 calls njUserExit() here, but seems like this is some other function instead
}

void QuickGetDiscTrayStatus() 
{ 
    StatusUpdateCounter = 1; 
    
    njWaitVSync(); 
    
    if (DiscOpenTrayFlag == -1)
    { 
        ExitApplication(DiscOpenTrayFlag); 
    }
} 

void InitFirstSofdec()
{
    mwPlyPreInitSofdec();
}

int GetBootDiscId()
{
    syBtGetBootSystemID(&BootDiscSystemId);
    
    switch (BootDiscSystemId.nNo) 
    {              
    case 1:
        return 0;
    case 2:
        return 1;
    default:
        return -1;
    }
}

// InitSofdecSystem 

void ExitSofdecSystem()
{
    if (MoviePlayTrayOpenFlag == 0) 
    {
        ExitMwSystem();
    }
}

void InitSoundProgram()
{
    int i;

    switch (GetBootDiscId()) 
    {                         
    case 0:
        sys->ss_flg &= ~0x1;
        break;
    case 1:
        sys->ss_flg |= 0x1;
        break;
    }
    
    lbl_804E9764 = 0;
    
    syCfgInit(NULL);
    
    SoundInitLevel = 2;
    
    for (i = 0; i < 8; i++) 
    {
        RegistMidiSlot(i);
    } 
    
    for (i = 0; i < 20; i++)
    {
        RegistSeSlot(i);
    } 
    
    SetFxProgram(0, 0);
    
    InitSofdecSystem(0);
    
    MovieInfo.ExecMovieSystemFlag = 0;
    
    SoundInitLevel = 3;
    
    RegistAdxStreamEx(2, 4, AdxDef);
    
    if (MountSoundAfs() != 0) 
    {
        ExitApplication();
    }
    
    SoundInitLevel = 4;
    
    InitReadKeyEx(1);
    
    SetRepeatKeyTimer(5, 2);
    
    InitVibrationUnit();
    InitPlayLogSystem();
    
    RequestAdjustDisplay(0, 0);
    
    ResetRoomSoundEnvParam();
    ResetSoundComInfo();
    
    memset(&SoundCommand, 0, sizeof(SND_CMD));
    
    InitAdvSystem();
    
    SoundInitLevel = -1;
}

void ExitSoundProgram() 
{ 
    switch (SoundInitLevel)
    {       
    case -1:
        ExitPlayLogSystem(); 
        ExitVibrationUnit(); 
    case 4:
        UnmountSoundAfs(); 
        
        FreeAdxStream(); 
        
        ExitAdx(); 
    case 3:
        ExitSofdecSystem(); 
    case 2:
        ExitSoundDriver(); 
    case 1:
        syCfgExit(); 
    }
} 

void* syMalloc(unsigned int nbytes); // TODO: remove this function declaration     
// MountSoundAfs

void UnmountSoundAfs()
{ 
    if (PatId[0] != -1) 
    { 
        DeletePartitionEx(SoundAfsPatDef); 
        
        syFree(pSoundAfs); 
        
        PatId[0] = PatId[1] = PatId[2] = PatId[3] = -1; 
    }
} 

// ExecSoundSynchProgram
// InitGameSoundSystem
// SearchAfsInsideFileId 
// StopThePsgSound 
// CheckSpecialBank 
// LoadSoundPackFile 
// ExecTransSoundData 
// RequestRoomSoundBank 
// RequestArmsSoundBank 
// RequestDoorSoundBank 
// RequestPlayerVoiceSoundBank
// CheckTransEndSoundBank 
// SetRoomSoundCaseNo 
// GetRoomSoundCaseNo 
// CustomMidiSlotDef 
// ResetRoomSoundEnvParam 
// wadGetAngle 
// CheckCollision4Sound 
// Get3DSoundParameter 
// SetupSeGenericParm 
// Set3dSoundFlag 
// Reset3dSoundFlag 
// SetUserSoundVolume 
// SetUserSoundPan 
// PlayGameSe4Event 
// CallSystemSeBasic 
// CallSystemSeEx 
// CallSystemSe 
// StopSystemSe 
// SetSyukanModeSoundParam 
// CallPlayerVoice 
// GetPlayerActionSeSlotNo 
// CallPlayerFootStepSeEx 
// CallPlayerFootStepSe 
// CallPlayerActionSe
// CallPlayerWeaponSeEx 
// CallYakkyouSe 
// CallBackGroundSeEx 
// CallBackGroundSe 
// CallBackGroundSe2 
// StopBackGroundSeEx 
// StopBackGroundSe2 
// CallDoorSe 
// RequestEnemySeBasic
// RequestEnemySe 
// RequestEnemySeEx 
// ChechPlayEnemySe 
// AllStopEnemySe 
// CallEnemySe 
// StopEnemySe 
// CallNativeEventSe 
// StopNativeEventSe 
// RequestObjectSeEx 
// RegistObjectSe 
// FreeObjectSe 
// PlayBgmEx2 
// PlayBgmEx 
// PlayBgm 
// PlayBgm2 
// StopBgm 
// StopBgm2 
// PlayVoiceEx2 
// PlayVoiceEx 
// PlayVoice 
// ContinuePlayVoice 
// StopVoice 
// CheckPlayEndAdx 
// GetTimeAdx 
// SetRoomSoundFxLevel 
// SetRoomSoundFxLevelEx 
// SearchPlayingEnemySe 
// SearchFreeEnemySeSlot 
// CheckPlaySameSe 
// CallEnemySeMain 
// RegistEnemySlot 
// ResetEnemySeInfo 
// ExecEnemySeManager 
// SearchPlayingObjectSeEx 
// SearchPlayingObjectSe 
// SearchFreeObjectSeSlot 
// CallObjectSe2 
// RegistObjectSlot 
// ResetObjectSeInfo 
// ExecObjectSeManager 
// RequestSoundFade 
// RequestAllStopSoundEx
// ResetSoundComInfo 
// Com_ExecRoomFadeIn 
// Com_ExecRoomFadeOut 

void Com_ExecCallBgm_And_BgSe()
{

}

// Com_StartInitScript 

void Com_FinishInitScript() 
{

}

// ExecuteSoundCommand 

void SendSoundCommand(unsigned int CommandNo)
{
    if (SoundCommand.MaxCommand != 2) 
    {
        SoundCommand.ComTbl[SoundCommand.MaxCommand] = CommandNo;
        
        SoundCommand.MaxCommand++;
        
        ExecuteSoundCommand();
    }
}

// TODO: need to define this file's sdata to match this function
int GetAdxStatus(unsigned int SlotNo); // TODO: remove these two function declarations
void StopAdx(unsigned int SlotNo);
void ExecSoundSystemMonitor()
{
    int i;
    
    CameraPos.x = cam.wpx;
    CameraPos.y = cam.wpy;
    CameraPos.z = cam.wpz;
    
    PlayerPos.x = plp->px;
    PlayerPos.y = plp->py;
    PlayerPos.z = plp->pz;
    
    for (i = 0; i < 2; i++)
    {
        if ((AdxPlayFlag[i] != 0) && ((GetAdxStatus(i) == 5) || (GetAdxStatus(i) == 0)))
        {
            StopAdx(i);
                
            AdxPlayFlag[i] = 0;
        }
    } 
    
    ExecEnemySeManager();
    ExecObjectSeManager();
}

int RequestReadIsoFile(char* FileName, void* DestPtr)
{
    if (ReadFileRequestFlag != 0) 
    {
        return -1;
    }
    
    if ((GenAdxfSlot = OpenAfsIsoFile(FileName)) < 0) 
    {
        return -1;
    }
    
    RequestReadAfsInsideFile(GenAdxfSlot, DestPtr);
    
    DestReadPtr = DestPtr;

    ReadFileRequestFlag = 1;

    FileReadStatus = 1;

    return 0;
}

int RequestReadInsideFile(unsigned int PartitionId, unsigned int FileId, void* DestPtr)
{
    if (ReadFileRequestFlag != 0) 
    {
        return -1;
    }
    
    if ((GenAdxfSlot = OpenAfsInsideFile(PartitionId, FileId)) < 0) 
    {
        return -1;
    }
    
    RequestReadAfsInsideFile(GenAdxfSlot, DestPtr);
    
    DestReadPtr = DestPtr;
    
    ReadFileRequestFlag = 1;
    
    FileReadStatus = 1;
    
    return 0;
}

int fn_8015713C()
{
    if (ReadFileRequestFlag == 0) 
    {
        return -1;
    }
    
    CloseAfsInsideFile(GenAdxfSlot);
    
    ReadFileRequestFlag = 0;
    
    FileReadStatus = 2;
    
    return 0;
}

int GetIsoFileSize(char* FileName)
{
    GetFileSize(FileName);
}

int GetInsideFileSize(unsigned int PartitionId, unsigned int FileId)
{
    int SlotNo;
    int FileSize;
    
    SlotNo = OpenAfsInsideFile(PartitionId, FileId);
    
    if (SlotNo < 0)
    {
        return 0;
    }
    
    FileSize = GetAfsInsideFileSize(SlotNo);

    CloseAfsInsideFile(SlotNo);
    
    return FileSize;
}

int GetReadFileStatus() 
{ 
    return FileReadStatus; 
}

void ExecFileManager()
{
    OpenDriveTrayFlag = CheckOpenTray();
    
    if (ReadFileRequestFlag != 0)
    {
        if (OpenDriveTrayFlag != 0)
        {
            StopAfsInsideFile(GenAdxfSlot);
            
            ReadFileRequestFlag = 0;
            
            FileReadStatus = -1;
        }
        else if ((FileReadStatus == 1) && (CheckReadEndAfsInsideFile(GenAdxfSlot) != 0)) 
        {
            ReadFileRequestFlag = 0;
            
            FileReadStatus = 0;
        }
    }
}

// PlayStartMovieEx

void PlayStopMovieEx(int Mode)
{
    if (MovieInfo.ExecMovieSystemFlag != 0) 
    {
        if (Mode == 0) 
        {
            StopMw();
            
            bhReleaseFreeMemory(MovieInfo.mmp);
            
            WakeupAdxStream(AdxDef);
        }
        
        MovieInfo.ExecMovieSystemFlag = 0;
        
        if ((sys->cb_flg & 0x2)) 
        {
            sys->cb_flg &= ~0x2;
        }
    }
}

void PlayStopMovie()
{
    PlayStopMovieEx(0);
}

int CheckPlayEndMovie()
{
    return MovieInfo.ExecMovieSystemFlag;
}

int GetTimeMoive()
{
    if (MovieInfo.ExecMovieSystemFlag != 0)
    {
        return GetMwPlayTimeEx();
    }
    
    return 0;
}

int WaitPrePlayMovie()
{
    if (MovieInfo.ExecMovieSystemFlag != 0)
    {
        if (OpenDriveTrayFlag != 0) 
        {
            PlayStopMovieEx(1);
            
            return 3;
        }
        
        if (CheckSoftResetKeyFlag(-1) != 0)
        {
            PlayStopMovie();
            
            return 3;
        }
        
        if ((MovieInfo.MovieCancelFlag != 0) && ((Pad[CurrentPortId].press & 0x800))) 
        {
            PlayStopMovie();
            
            return 2;
        }
        
        PlayMwMain();
        
        if (GetMwStatus() == MWE_PLY_STAT_PLAYING) 
        {
            RestartMw();
            
            return 0;
        }
        
        return 1;
    }
    
    return 0;
}

// SYS_WORK struct mismatch is preventing this one from getting to 100%
void bhSetScreenFade(unsigned int argb, float ct); // TODO: remove these two function declarations
void SetMwVolume(int Volume);  
int PlayMovieMain()
{
    int temp, temp2; // not from the debugging symbols

    temp = 0;
    
    if (MovieInfo.ExecMovieSystemFlag != 0) 
    {
        if (OpenDriveTrayFlag != 0) 
        {
            PlayStopMovieEx(1);
            
            return 3;
        }
        
        if (CheckSoftResetKeyFlag(-1) != 0)
        {
            PlayStopMovie();
            
            return 3;
        }
        
        mwPlyStartFrame();
        
        if (MovieInfo.MovieCancelFlag != 0)
        {
            if ((Pad[CurrentPortId].press & 0x800)) 
            {
                if (MovieInfo.MovieFadeFlag == 0) 
                {
                    PlayStopMovie();
                    
                    return 2;
                }
                
                if (MovieInfo.MovieFadeMode != 1) 
                {
                    MovieInfo.MovieFadeMode = 1;
                    
                    bhSetScreenFade(0xFF000000, MovieInfo.FrameCnt);
                }
            }
        }
        
        if (MovieInfo.MovieFadeMode != 0) 
        {
            if (!(sys->cb_flg & 0x2)) 
            {
                PlayStopMovie();
                
                return 2;
            }
            
            bhControlScreenFade();

            temp = 1;
            
            MovieInfo.Vol -= MovieInfo.VolSpeed;
            
            SetMwVolume(MovieInfo.Vol);
        }

        temp2 = PlayMwMain();

        if ((temp != 0) && (sys->fade_an > 0)) 
        {
            bhDrawScreenFade();
        }
        
        if (temp2 == 0) 
        {
            PlayStopMovie();
            
            return 1;
        }
    }
    
    return 0;
}

void SetEventVibrationMode(int Mode) 
{ 
    EventVibrationMode = Mode; 
}

void StartVibrationBasic(int PortNo, int AtrbId, int VibNo)
{
    PDS_VIBPARAM VibPrm;
    
    if ((!(sys->ss_flg & 0x400000)) && ((EventVibrationMode == 0) || (AtrbId == 2))) 
    {
        VibPrm.flag = VibFlag[VibP[VibNo].flag];
        
        *(unsigned char*)&VibPrm.power = VibP[VibNo].power;
        
        VibPrm.freq = VibP[VibNo].freq;
        
        VibPrm.inc = VibP[VibNo].inc;
        
        StartVibration((PortNo * 6) + 2, &VibPrm);
    }
}

void StartVibrationEx(int AtrbId, int VibNo) 
{ 
    StartVibrationBasic(CurrentPortId, AtrbId, VibNo);
}

void StopVibrationBasic(int PortNo) 
{ 
    StopVibration((PortNo * 6) + 2);
}

void StopVibrationEx() 
{ 
    StopVibrationBasic(CurrentPortId);
}

void SetAdjustDisplay() 
{ 
    SystemAdjustFlag = 1; 
}

void RequestAdjustDisplay(int AdjustX, int AdjustY)
{ 
    sys->adjust_x = AdjustX;
    sys->adjust_y = AdjustY; 
    
    SetAdjustDisplay(); 
}

void ExecAdjustDisplay()
{ 
    if (SystemAdjustFlag != 0) 
    { 
        njAdjustDisplay(sys->adjust_x, sys->adjust_y + 1); 
        
        SystemAdjustFlag = 0; 
    }
} 

void InitPlayLogSystem()
{

}

void ExitPlayLogSystem()
{

}

void ReadPlayLog()
{

}

void WritePlayLog()
{

}
