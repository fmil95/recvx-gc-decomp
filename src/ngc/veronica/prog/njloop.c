#include "ngc/veronica/prog/njloop.h"

int main(int argc, char *argv[])
{
    njUserInit(); 
    
    while (TRUE) 
    { 
        if (njUserMain() < NJD_USER_CONTINUE) 
        { 
            break;
        } 
        
        njWaitVSync();
    } 
    
    njUserExit(); 
} 
