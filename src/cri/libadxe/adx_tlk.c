#include <cri_adxt.h>

// ADXT_Pause

Sint32 ADXT_GetErrCode(ADXT adxt)
{
    if (adxt == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"placeholder");

        return ADXT_ERR_SHRTBUF;
    }

    return adxt->ercode;
}

// fn_80243EC4

void ADXT_SetAutoRcvr(ADXT adxt, Sint32 rmode)
{
    adxt->autorcvr = rmode;
}

void ADXT_SetReloadSct(ADXT adxt, Sint32 minsct)
{
    if (adxt == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"placeholder");
        return;
    }

    adxt->minsct = minsct;
}

void ADXT_SetSvrFreq(ADXT adxt, Sint32 freq)
{
    if (adxt == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"placeholder");
        return;
    }
    
    adxt->svrfreq = freq;
}

Sint32 ADXT_GetOutVol(ADXT adxt) 
{
    if (adxt == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"placeholder");

        return ADXT_ERR_OK;
    }

    return adxt->outvol;
}

Sint16 ADXSJD_GetDefOutVol(ADXSJD sjd); // TODO: remove this function declaration
void ADXT_SetOutVol(ADXT adxt, Sint32 vol)
{
    if (adxt == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"placeholder");
        return;
    }

    adxt->outvol = vol;

    ADXRNA_SetOutVol(adxt->rna, adxt->outvol + ADXSJD_GetDefOutVol(adxt->sjd));
}

Sint32 ADXT_GetOutPan(ADXT adxt, Sint32 ch) 
{
    if (adxt == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"placeholder");

        return ADXT_ERR_OK;
    }

    return adxt->outpan[ch];
}

// ADXT_SetOutPan
// fn_80244180
// fn_802441D8
// fn_80244230
// ADXT_GetTime

Sint32 ADXT_GetStat(ADXT adxt)
{
    if (adxt == NULL) 
    {
        ADXERR_CallErrFunc1((const Sint8*)"placeholder");

        return ADXT_ERR_SHRTBUF;
    }

    return adxt->stat;
}

// ADXT_Stop
// fn_802448B8
// fn_80244AA4
// ADXT_Destroy
// ADXT_Create
