#include "structs.h"

unsigned int ulNaFogState;
float* fpNaFogTblTop;

float lbl_80488154[3];
float lbl_804ED280;

void	njFogEnable()
{ 
    ulNaFogState = 1; 

    if (lbl_80488154[2] > lbl_804ED280)
    {
        fn_801CC6D4();
    }
} 

void	njFogDisable()
{ 
    ulNaFogState = 0; 

    fn_801CC67C();
} 

void	njSetFogTable(NJS_FOG_TABLE fog)
{
    fpNaFogTblTop = fog; 
} 

// njGenerateFogTable3
// njCalcFogPower
// njCalcFogPowerEx
// njSetFogColor
