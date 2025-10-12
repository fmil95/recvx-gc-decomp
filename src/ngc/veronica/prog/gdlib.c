#include "structs.h"

// this file differs drastically from PS2, it does not call any functions from sg_gd.h and even calls some CRI ADX ones  

unsigned int LfInitLib(int arg0);
void CallbackGdErrorFunc(int param, int err);
unsigned int InitGdSystem();
unsigned int InitGdSystemEx(unsigned int MaxDirNum);
void ExitGdSystem();
int GetFileSize(char* FileName);
int ReadFileEx(char* FileName, void* ReadAddress);
unsigned int CheckOpenTray();

//unsigned int MaxDirectoryEntry = 512;
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

unsigned short MaxDirectoryEntry[1]; // find out actual size

unsigned int LfInitLib(int arg0) 
{
    if (arg0 < 0)
    {
        return 65535;
    }

    if (arg0 >= 3) 
    {
        return 65535;
    }

    return MaxDirectoryEntry[arg0];
} 

void CallbackGdErrorFunc(int param, int err) // first parameter is not present on the debugging symbols
{
    LfInitLib(0);
}

unsigned int InitGdSystem() 
{ 
    LfInitLib(1);
}

unsigned int InitGdSystemEx(unsigned int MaxDirNum)
{
    int i;

    for (i = 0; i < 3; i++) 
    {
        MaxDirectoryEntry[i] = 65535;
    } 
    
    return 0;
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
