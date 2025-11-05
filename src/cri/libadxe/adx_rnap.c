#include <cri_adxt.h>

typedef void* NGCRNA; // not sure about the handle name here

void ADXRNA_SetOutVol(ADXRNA rna, Sint32 vol)
{
    NGCRNA_SetOutVol(rna, vol); 
}

void ADXRNA_SetPlaySw(ADXRNA rna, Sint32 sw)
{
    NGCRNA_SetPlaySw(rna, sw); 
}

void ADXRNA_SetTransSw(ADXRNA rna, Sint32 sw)
{
    NGCRNA_SetTransSw(rna, sw);
}

void ADXRNA_Destroy(ADXRNA rna)
{
    NGCRNA_SetPlaySw(rna, 0);
    NGCRNA_SetTransSw(rna, 0);
    
    NGCRNA_Destroy(rna);
}

NGCRNA NGCRNA_Create(SJ *sj, Sint32 maxnch); // TODO: remove this function declaration
ADXRNA ADXRNA_Create(SJ *sj, Sint32 maxnch)
{
    return NGCRNA_Create(sj, maxnch);
}
