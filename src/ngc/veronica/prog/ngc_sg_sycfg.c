#include <sg_xpt.h>

// sbss
int SoundMode; // TODO: investigate why this is only 50% matching

Sint32 syCfgExit( Void  );
Sint32 syCfgGetSoundMode( Sint32* pnMode );
Sint32 syCfgInit( Void* );
Sint32 syCfgSetSoundMode( Sint32 nMode );

Sint32 syCfgExit( Void  ) 
{

}

Sint32 syCfgGetSoundMode( Sint32* pnMode )
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

Sint32 syCfgInit( Void* )
{
    syCfgGetSoundMode(&SoundMode);
}

Sint32 syCfgSetSoundMode( Sint32 nMode )
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
