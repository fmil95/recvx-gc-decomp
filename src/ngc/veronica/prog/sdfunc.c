#include "structs.h"

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
MOV_INFO MovieInfo;
int EventVibrationMode;
BH_PWORK* plp;
unsigned char* DestReadPtr;
int GenAdxfSlot;
int OpenDriveTrayFlag;
RMI_WORK rmi;
PAD_WRK Pad[4];
int CurrentPortId;
PDS_VIBPARAM_EX VibP[32];
char VibFlag[5] = { 0x01, 0x08, 0x80, 0x09, 0x81 };
int SystemAdjustFlag;

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
// UnmountSoundAfs
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
// ExecFileManager 
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
// RequestAdjustDisplay 
// ExecAdjustDisplay 
// InitPlayLogSystem 
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

// InitSoundProgram 

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

// MountSoundAfs 
// UnmountSoundAfs
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
