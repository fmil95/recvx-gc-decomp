#include <cri_adxt.h>

Sint32 ADXT_GetOutVol(ADXT adxt) 
{
    if (adxt == NULL) 
    {
        ADXERR_CallErrFunc1("placeholder");

        return 0;
    }

    return adxt->outvol;
}

Sint16 ADXSJD_GetDefOutVol(ADXSJD sjd); // TODO: remove this function declaration
void ADXT_SetOutVol(ADXT adxt, Sint32 vol)
{
    if (adxt == NULL) 
    {
        ADXERR_CallErrFunc1("placeholder");
        return;
    }

    adxt->outvol = vol;

    ADXRNA_SetOutVol(adxt->rna, adxt->outvol + ADXSJD_GetDefOutVol(adxt->sjd));
}
