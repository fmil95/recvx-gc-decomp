#include <cri_xpt.h>

Sint32 adxcrs_lvl;
Sint32 adxcrs_msk;

void ADXCRS_Init(void) 
{
    adxcrs_lvl = 0;
}

void ADXCRS_Lock(void)
{
    SVM_Lock();
}

void ADXCRS_Unlock(void) 
{
    SVM_Unlock();
}
