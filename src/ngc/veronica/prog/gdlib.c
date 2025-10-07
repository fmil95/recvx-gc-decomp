#include "structs.h"

void LfInitLib();
void CallbackGdErrorFunc(int param, int err);
unsigned int InitGdSystem();
unsigned int InitGdSystemEx(unsigned int MaxDirNum);
void ExitGdSystem();
int GetFileSize(char* FileName);
int ReadFileEx(char* FileName, void* ReadAddress);
unsigned int CheckOpenTray();

unsigned int MaxDirectoryEntry = 512;
unsigned int DiscOpenTrayFlag;
unsigned int NewDiscCheckSw;
unsigned int GdErrorFlag;
LFOPEN_INFO LfOpenInfo[14];
GDFS_DIRREC GdDirRec;
unsigned char* pDirTbl;
unsigned char* pDirWork;
unsigned int RequestMultiReadFlag;
unsigned int RequestReadBufferFlag;
unsigned int RequestReadFlag;
GDFS CurrentGdFs;
GDFS CurrentGdFsBuf;
unsigned int StatusUpdateCounter;
GDFS LfGdFs;

void LfInitLib() 
{
    unsigned int i;
    
    for (i = 0; i < 14; i++) 
    { 
        LfOpenInfo[i].Flag = 0; 
    } 
} 

void CallbackGdErrorFunc(int param, int err) // first parameter is not present on the debugging symbols
{
    if ((err == -23) || (err == -33)) 
    { 
        GdErrorFlag = 1; 
    }
}

unsigned int InitGdSystem() 
{ 
    LfInitLib(1);
}

unsigned int InitGdSystemEx(unsigned int MaxDirNum)
{
    MaxDirectoryEntry = MaxDirNum; 
}

void ExitGdSystem() 
{ 

} 

// GetFileSize
// ReadFileEx

unsigned int CheckOpenTray()
{ 
    DiscOpenTrayFlag = 0;
    
    return 0; 
} 
