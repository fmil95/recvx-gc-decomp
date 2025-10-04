#include "structs.h"

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
// ExitPlayLogSystem 
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
// ExitPlayLogSystem 
// ReadPlayLog 
// WritePlayLog 
