#include "structs.h"

/*void CallPlayerDeadVoice(int PlayerNo);
void CallSystemVoice(int VoiceNo);
float GetSamurai(int Time);
void InitAdvSystem();
void ResetAdvSystem();*/
void MountAdvAfs();
/*unsigned char* AdvGetResourcePtr(unsigned char* bp, unsigned int ResId);
void AdvSetSoundMode();
void AdvCheckSoftReset(int Flag);
void AdvPushRoomTexture();
void AdvPopRoomTexture();
void AdvPushPaletteData();
void AdvPopPaletteData();
void RequestAdvInsideFileEx(int InsideFileId, int MemoryBlockNo);
void RequestAdvInsideFile(int InsideFileId);
void FreeAdvMemoryEx(int MemoryBlockNo);
void AllFreeAdvMemory();
int CheckReadEndAdvInsideFile();
void CheckReadEndAdvInsideFile2Ex(int NextMode, int Flag);
void CheckReadEndAdvInsideFile2(int NextMode);
void RequestAdvFade(int FadeType, float FadeSpeed);
int CheckAdvFade();
void AdvDrawFadePolygon(int Type, float Rate, unsigned int BaseColor);
void ExecuteAdvFadeEx(int Type);
void ExecuteAdvFade();*/
void StopAdvScreenSaver(int Flag);
/*void ExecuteAdvScreenSaver();
void CheckAdvScreenSaverStopKey(int PortId);
unsigned int AdvGetOkButton();
unsigned int AdvGetCancelButton();
void SetPvrInfo(_anon20* np, _anon16* ip, unsigned char* pp);
int TransPvpData(unsigned char* pp, int Mode);
void AdvTransShadowPalette();
void AdvEasyDrawWindow(_anon32* tlp, _anon32* brp, unsigned int WindowColor, unsigned int BackColor);
void AdvEasyDrawTexture(int TexNo, unsigned int BaseColor, _anon0* qp, float PosZ, int TransFlag);
void AdvEasyDrawTextureS(int TexNo, unsigned int BaseColor, _anon0* qp, float PosZ, int TransFlag, unsigned int ShadowAlpha);
void SetQuadPos(float StartX, float StartY, float SizeX, float SizeY, _anon0* qp);
void SetQuadUv2Ex(float u, float v, float SizeX, float SizeY, unsigned int ListNo, unsigned int TexNo, _anon0* qp);
void SetQuadUv2(float u, float v, float SizeX, float SizeY, unsigned int TexNo, _anon0* qp);
void AdvDwawOnePictureEx(int TexNo, unsigned int BaseColor);
void AdvDwawOnePicture(int TexNo);
void AdvEasySetupTextureBasic(unsigned char* xp, int ListNo, int TexNo);
void AdvEasySetupTextureEx(int ListNo);
void AdvEasySetupTexture();
void AdvEasySetTextureList(int ListNo);
void AdvEasyTransTextureBasic(int ListNo, int TexNum, int Flag);
void AdvEasyTransTextureEx(int ListNo);
void AdvEasyTransTexture();
void AdvEasyReleaseTextureEx(int ListNo);
void AdvEasyReleaseTexture();
void AdvEasyReleaseAllTexture();
int AdvGetCurrentPort();
int CheckConnectVmDrive(int SlotNo);
int FindFirstVmDrive();*/
float AdvEasyDispMessage(float PosX, float PosY, unsigned int MessageNo);
/*float AutoSaveLoadEasyDispMessage(float PosX, float PosY, unsigned char* ucpMsbTop, unsigned int MessageNo);
int DispVmWarningMessage(int MsgId);
void DefaultSetOption();
int Adv_FirstWarningMessage();
int Adv_CapcomLogo();
void ResetFlushPlate();
void FlushPlate();
void DisplayTitleBg();
void DisplayPressStartPlate(float FadeRate);
void DisplayGameModePlate(int Cursor, int CursorMax, float FadeRate, int Flag);
void DisplayNewGamePlate(int Cursor, float FadeRate, int Flag);
void DisplayExtraGamePlate(int Cursor, float FadeRate, int Flag);
void FadeInPlate(int NextMode);
void FadeOutPlate();
void TitleCall(int PortId, int ReturnCode);
int CheckButton(int Level, int Flag, int MaxFlag);
int CheckStartButton();
int Adv_BioCvTitle();
void ResetOptionMenuParam(int Mode);
void DisplayOptionScrollPlate(float PosX, float PosY);
void DisplayOptionBg(int Level, int Flag);
int DisplayOptionPlateLevel0(int PortId, int Flag);
int DisplayOptionPlateLevel1(int PortId, int Flag);
int DisplayOptionPlateLevel2(int PortId, int Flag);
int DisplayOptionPlateLevel3(int PortId, int Flag);
int DisplayOptionPlate(int PortId, int Level, int Flag);
int Adv_GameOptionScreen();
int Adv_ChangeDiscScreen();
int Adv_SoundMuseum();*/

int AdvFirstInitFlag;
int PatId[4];
ADV_WORK AdvWork;
SYS_WORK* sys;
NJS_TEXMEMLIST tbuf[256];
ROM_WORK* rom;
unsigned int palbuf[4096];
PAD_WRK Pad[4];
ADV_VM_MSG AdvVmMsgDef[21] = {{-1.0f, 32.0f, 23, 21, 1}, {-1.0f, 176.0f, 25, -1, 0}, {-1.0f, 32.0f, 33, 21, 1}, {-1.0f, 208.0f, 30, 22, 1}, {-1.0f, 224.0f, 27, 22, 1}, {-1.0f, 32.0f, 24, 22, 1}, {-1.0f, 416.0f, 28, -1, 0}, {-1.0f, 32.0f, 24, 21, 1}, {-1.0f, 224.0f, 31, 22, 1}, {-1.0f, 224.0f, 32, 22, 1}, {-1.0f, 32.0f, 23, 22, 1}, {-1.0f, 32.0f, 33, 20, 1}, {-1.0f, 32.0f, 33, 22, 1}, {-1.0f, 32.0f, 34, 20, 1}, {-1.0f, 32.0f, 35, 20, 1}, {-1.0f, 32.0f, 36, 20, 1}, {-1.0f, 32.0f, 37, 20, 1}, {-1.0f, 32.0f, 38, 20, 1}, {-1.0f, 32.0f, 39, 20, 1}, {-1.0f, 32.0f, 40, 20, 1}, {-1.0f, 32.0f, 41, 20, 1}};

void CallPlayerDeadVoice(int PlayerNo)
{ 
    PlayBgmEx2(PatId[3], PlayerNo + 8, 1, -45);
}

void CallSystemVoice(int VoiceNo) 
{ 
    PlayVoiceEx2(PatId[3], VoiceNo + 16, NULL, 1, 0, 0);
}

float GetSamurai(int Time)
{ 
    return 1.0f / (((Time / 100) * 30) + (((Time % 100) * 6) / 10));
} 

// this function gives away that the ADV_WORK struct is 12 bytes larger than on PS2
void InitAdvSystem()
{ 
    ADV_WORK* ap;

    ap = &AdvWork;

    if (AdvFirstInitFlag == 0) 
    { 
        memset(&AdvWork, 0, sizeof(ADV_WORK) + 12); 
        
        ap->PatId = -1; 
        
        ap->Active = 0; 
        
        AdvFirstInitFlag = 1; 
    } 
    
    MountAdvAfs(); 
} 

void ResetAdvSystem()
{ 
	ADV_WORK* ap; 
    int i;

    ap = (ADV_WORK*)&AdvWork; 

    if (ap->Active != 0) 
    {
        ExitApplication();
    }
    
    ap->Active = 1; 
    
    njSetBackColor(0x00000000, 0x00000000, 0x00000000);  
    
    njFogDisable(); 
    
    for (i = 0; i < 8; i++) 
    { 
        ap->ptr[i] = NULL; 
    } 
    
    for (i = 0; i < 2; i++) 
    { 
        ap->SetTexture[i] = 0; 
    } 
    
    for (i = 0; i < 7; i++) 
    { 
        ap->KeyCommandCount[i] = 0; 
    } 
  
    ap->NextReturnCode = 0; 
    
    ap->Count = 0; 
    
    ap->OptIndex = 0; 
    
    ap->ErrorId = 0; 
    ap->ErrorMsgFlushCount = 0; 
    
    ap->ExtraFlag = 0; 
    
    ap->Mode2 = 0; 
    ap->NextMode = 0; 
    
    ap->DepthLevel = 0; 
    
    ap->GenFlag = 0; 
    
    ap->OptFadeType = 0; 
    
    ap->PalNo = 0; 
    ap->PalFlag = 1; 
    
    ap->TexFlag = 0; 
    
    ap->SrFlag = 0; 
    
    ap->SoundMode = -1; 
    
    ap->OptSaveFlag = 0; 
    
    ap->vMode = 0; 
    
    ap->DriveNo = 0;  
    
    ap->VmOpMode = ap->OldVmOpMode = 0; 

    StopAdvScreenSaver(1); 
} 

void MountAdvAfs() 
{ 
    ADV_WORK* temp; // not from the debugging symbols

    temp = (ADV_WORK*)&AdvWork;
    
    temp->PatId = PatId[3]; 
}

unsigned char* AdvGetResourcePtr(unsigned char* bp, unsigned int ResId) 
{ 
    return &bp[((int*)bp)[ResId]]; 
}

void AdvSetSoundMode() 
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 
    
    if (ap->SoundMode >= 0) 
    { 
        syCfgSetSoundMode(ap->SoundMode); 
        
        ap->SoundMode = -1; 
    }
} 

void AdvCheckSoftReset(int Flag)
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 
    
    if ((ap->SrFlag == 0) && (!(sys->ss_flg & 0x20000)) && (CheckSoftResetKeyFlag(-1) != 0)) 
    {
        if (Flag == 0) 
        { 
            ap->Mode = -1;
        }
        else 
        { 
            ap->Mode2 = -1; 
        } 
        
        AdvSetSoundMode(); 
    } 
} 

void AdvPushRoomTexture() 
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 
    
    ap->TexFlag = 0; 
    
    if (rom->mdl.texP != NULL)
    { 
        ap->SysMemPtr = sys->memp; 
        
        fn_8016D5DC(); 
        
        ap->TexFlag = 1; 
    }
} 

void AdvPopRoomTexture()
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 

    if ((ap->TexFlag != 0) && (rom->mdl.texP != NULL)) 
    { 
        bhCopyMainmem2Texmem(rom->mdl.texP); 
        
        sys->memp = ap->SysMemPtr; 
    }
    
    ap->TexFlag = 0; 
} 

void AdvPushPaletteData() 
{ 
    ADV_WORK* temp; // not from the debugging symbols

    temp = (ADV_WORK*)&AdvWork;
    
    njMemCopy2(&palbuf[1536], palbuf, 1024); 
    
    temp->PalMode = njGetPaletteMode(); 
}

void AdvPopPaletteData() 
{ 
    ADV_WORK* temp; // not from the debugging symbols

    temp = (ADV_WORK*)&AdvWork;
    
    njSetPaletteMode(temp->PalMode); 
    
    njMemCopy2(palbuf, &palbuf[1536], 1024); 
    
    sys->gm_flg |= 0x4; 
    
    if ((sys->st_flg & 0x2)) 
    { 
        njFogEnable(); 
    } 
    
    sys->gm_flg |= 0x8000; 
} 

unsigned char* bhGetFreeMemory(int size, int param); // TODO: remove this function declaration
void RequestAdvInsideFileEx(int InsideFileId, int MemoryBlockNo)
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 

    ap->ptr[MemoryBlockNo] = bhGetFreeMemory(GetInsideFileSize(ap->PatId, InsideFileId), 32); 
    
    RequestReadInsideFile(ap->PatId, InsideFileId, ap->ptr[MemoryBlockNo]); 
} 

void RequestAdvInsideFile(int InsideFileId) 
{ 
    RequestAdvInsideFileEx(InsideFileId, 0);
}

void FreeAdvMemoryEx(int MemoryBlockNo)
{ 
    ADV_WORK* temp; // not from the debugging symbols

    temp = (ADV_WORK*)&AdvWork; 

    if (temp->ptr[MemoryBlockNo] != NULL) 
    { 
        bhReleaseFreeMemory(temp->ptr[MemoryBlockNo]); 
        
        temp->ptr[MemoryBlockNo] = NULL; 
    } 
} 

void AllFreeAdvMemory()
{ 
    int i;

    for (i = 7; i >= 0; i--) 
    { 
        FreeAdvMemoryEx(i); 
    } 
} 

int CheckReadEndAdvInsideFile()
{ 
    int ReturnCode;

    ReturnCode = GetReadFileStatus(); 
    
    if (ReturnCode == -1) 
    { 
        AllFreeAdvMemory(); 
    }
    
    return ReturnCode; 
} 

void CheckReadEndAdvInsideFile2Ex(int NextMode, int Flag) 
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 

    switch (CheckReadEndAdvInsideFile()) 
    {               
    case -1:
        if (Flag == 0) 
        { 
            ap->Mode = -1;
        }
        else
        { 
            ap->Mode2 = -1;
        }
        
        break; 
    case 0:
        if (Flag == 0) 
        { 
            ap->Mode = NextMode;
        } 
        else
        { 
            ap->Mode2 = NextMode; 
        }
        
        break;
    case 1:
        break;
    } 
}

void CheckReadEndAdvInsideFile2(int NextMode)
{ 
    CheckReadEndAdvInsideFile2Ex(NextMode, 0);
}

void RequestAdvFade(int FadeType, float FadeSpeed) 
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 
    
    ap->FadeType = FadeType; 
    
    ap->FadeSpeed = FadeSpeed; 
    
    switch (FadeType) 
    {              
    case 1:
        ap->FadeType = 0; 
        break; 
    case 2:
        ap->FadeRate = 1.0f;
        break;
    case 3:
        ap->FadeRate = 0; 
        break;
    }
}

int CheckAdvFade() 
{ 
    ADV_WORK* temp; // not from the debugging symbols

    temp = (ADV_WORK*)&AdvWork; 
    
    return temp->FadeType;
}

void AdvDrawFadePolygon(int Type, float Rate, unsigned int BaseColor)
{ 
	NJS_POLYGON_VTX poly[4];
    float PosZ[4] = { 
        0.98f,
        0.90f,
        1.99f,
        1.98f
    };
    
    BaseColor |= ((unsigned int)(255.0f * Rate) & 0xFF) << 24;
    
    poly[0].x = -2.0f; 
    poly[0].y = -2.0f; 
    
    poly[1].x = -2.0f; 
    poly[1].y = 482.0f; 
    
    poly[2].x = 642.0f; 
    poly[2].y = -2.0f; 
    
    poly[3].x = 642.0f; 
    poly[3].y = 482.0f; 
    
    poly[0].z = poly[1].z = poly[2].z = poly[3].z = PosZ[Type]; 
    
    poly[0].col = poly[1].col = poly[2].col = poly[3].col = BaseColor; 
    
    njDrawPolygon(poly, 4, 1); 
} 

void ExecuteAdvFadeEx(int Type)
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 

    switch (ap->FadeType) 
    { 
    case 2:
        ap->FadeRate -= ap->FadeSpeed; 
        
        if (ap->FadeRate <= 0) 
        { 
            ap->FadeRate = 0; 
            
            ap->FadeType = 0; 
        } 
        
        AdvDrawFadePolygon(Type, ap->FadeRate, 0); 
        break; 
    case 3:
        ap->FadeRate += ap->FadeSpeed; 
        
        if (ap->FadeRate >= 1.0f)
        { 
            ap->FadeRate = 1.0f; 
            
            ap->FadeType = 0; 
        }
        
        AdvDrawFadePolygon(Type, ap->FadeRate, 0); 
        break;
    }
} 

void ExecuteAdvFade() 
{
    ExecuteAdvFadeEx(0);
}

void StopAdvScreenSaver(int Flag)
{
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 
    
    ap->SaverTimer = 9000.0f;
    
    ap->SaverCommand = 0; 
    
    if (Flag != 0) 
    { 
        ap->SaverRate = 0;
    } 
}

void ExecuteAdvScreenSaver()
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork; 
    
    if (ap->SaverCommand == 0) 
    { 
        ap->SaverTimer -= 1.0f; 
        
        if (ap->SaverTimer < 0) 
        { 
            ap->SaverCommand = 1; 
            
            ap->SaverRate = 0;
        }
    }
    
    if (ap->SaverCommand == 1) 
    { 
        ap->SaverRate += 0.01f;
        
        if (ap->SaverRate >= 0.5f)
        { 
            ap->SaverRate = 0.5f;
        }
    } 
    else 
    { 
        ap->SaverRate -= 0.05f; 
        
        if (ap->SaverRate <= 0) 
        { 
            ap->SaverRate = 0; 
        }
    }
    
    AdvDrawFadePolygon(2, ap->SaverRate, 0xF);
} 

void CheckAdvScreenSaverStopKey(int PortId)
{ 
    if ((Pad[PortId].on != 0) || ((Pad[PortId].x1 != 0) || (Pad[PortId].y1 != 0))) 
    { 
        StopAdvScreenSaver(0); 
    }
} 

unsigned int AdvGetOkButton()
{ 
    return 128; 
}

unsigned int AdvGetCancelButton() 
{ 
    unsigned int ButtonDef[3] = {32, 128, 64}; 
    
    return ButtonDef[sys->keytype]; 
} 

// SetPvrInfo
// TransPvpData

void AdvTransShadowPalette() 
{ 
    unsigned int* lp;
    unsigned int* p;
    int i;

    lp = p = (unsigned int*)bhGetFreeMemory(64, 32);       
    
    *lp++ = 0xFFFFFF; 
    
    for (i = 0; i < 15; i++) 
    { 
        *lp++ = 0xFF000000; 
    } 
    
    njSetPaletteData(16, 16, p);
    
    bhReleaseFreeMemory(p); 
} 

/* a lot more of functions should be here */

int DispVmWarningMessage(int MsgId)
{ 
    ADV_WORK* ap; 
    ADV_VM_MSG* mp; 

    ap = (ADV_WORK*)&AdvWork;

    mp = &AdvVmMsgDef[MsgId]; 
    
    if ((mp->MsgType != 0) && ((Pad[ap->PortId].press & 0x800))) 
    { 
        ap->Mode = ap->Mode2 = ap->NextMode; 
        
        return 1;
    } 
    
    AdvEasyDispMessage(mp->Sx, mp->Sy, mp->StartMsgNo); 
    
    if (mp->NaviMsgNo >= 0) 
    { 
        AdvEasyDispMessage(-1.0f, 400.0f, mp->NaviMsgNo); 
    }

    return 0; 
} 

void DefaultSetOption()
{ 
    ADV_WORK* temp; // not from the debugging symbols

    temp = (ADV_WORK*)&AdvWork;
    
    sys->keytype = 0; 
    
    RequestAdjustDisplay(0, 0); 
    
    sys->vibration = (CheckVibrationUnit((temp->PortId * 6) + 2) == 0) ? 0 : 1; 
    
    SetUseVibrationUnit(sys->vibration); 
}

void FlushPlate() 
{ 
    ADV_WORK* ap; 

    ap = (ADV_WORK*)&AdvWork;

    ap->FlushCount2 += ap->FlushSpeed2; 
    
    if (ap->FlushSpeed2 < 0) 
    { 
        if (ap->FlushCount2 <= -64.0f)
        { 
            ap->FlushCount2 = -64.0f; 
            ap->FlushSpeed2 = 2.0f;
        }
    } 
    else if (ap->FlushCount2 >= 0) 
    { 
        ap->FlushCount2 = 0;
        ap->FlushSpeed2 = -2.0f; 
    }

    ap->FontBaseColor = (unsigned int)ap->FlushCount2 + 255; 
    
    ap->FontBaseColor |= ((unsigned int)ap->FlushCount2 + 255) << 16;
    ap->FontBaseColor |= ((unsigned int)ap->FlushCount2 + 255) << 8;
} 
