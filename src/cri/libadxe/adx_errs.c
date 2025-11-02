#include <cri_xpt.h>

Sint8 adxerr_msg[256] = { 0 }; 
void (*adxerr_func)(void *obj, const Sint8 *msg);
void *adxerr_obj;

// ADXERR_ItoA
// ADXERR_ItoA2
// ADXERR_CallErrFunc2
// ADXERR_CallErrFunc1

void ADXERR_EntryErrFunc(void (*func)(), void *obj)
{
    adxerr_func = func; 
    adxerr_obj = obj;

    SVM_SetCbErr(func, obj);
}

// ADXERR_Finish
// ADXERR_Init
