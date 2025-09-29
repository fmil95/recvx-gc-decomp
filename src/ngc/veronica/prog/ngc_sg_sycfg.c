// TODO: move this define somewhere else 
#define NULL 0

// sbss
int SoundMode;

// TODO: replace current function signatures for the Katana originals

int syCfgExit() 
{

}

int syCfgGetSoundMode(int* pnMode)
{ 
    switch (fn_801966A8()) 
    {                              
    case 0:
        SoundMode = 1;
        break;
    case 1:
        SoundMode = 0;
        break;
    }

    if (pnMode != NULL) 
    {
        *pnMode = SoundMode; 
    }
    
    return 0;
}

int syCfgInit()
{
    syCfgGetSoundMode(&SoundMode);
}

int syCfgSetSoundMode(int nMode)
{ 
    switch (nMode) 
    {                          
    case 1:
        fn_80196728(0);
        
        fn_80220548(0);
        break;
    case 0:
        fn_80196728(1);
        
        fn_80220548(1);
        break;
    }
    
    syCfgGetSoundMode(&SoundMode); 
    
    return 0; 
}
