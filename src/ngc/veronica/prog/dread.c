#include "structs.h"

// bhReadPlayerData
// bhReadWeaponData

unsigned char* bhKeepObjWork(ML_WORK* mp, unsigned char* sp)
{
    unsigned char* owp; 

    owp = (unsigned char*)(((int)sp + 31) & ~0x1F);
    
    mp->owP = (O_WORK*)owp;
    
    memset(owp, 0, mp->obj_num << 6);
    
    owp += mp->obj_num << 6;
    
    return owp;
}
