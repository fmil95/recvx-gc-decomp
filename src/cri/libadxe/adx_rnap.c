#include <cri_adxt.h>

void ADXRNA_SetOutVol(ADXRNA rna, Sint32 vol)
{
    NGCRNA_SetOutVol(rna, vol); // not sure about the function name here
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
