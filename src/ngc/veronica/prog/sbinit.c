// TODO: move all this stuff below somewhere else
typedef unsigned char     Uint8;
typedef unsigned int   Uint32;

#define NULL 0

#define set_imask(mask)             _builtin_set_imask(mask)

#define P1AREA   0x80000000

#define WORK_END (((Uint32) _BSG_END) & 0xe0000000 | 0x0d000000)

#define HEAP_AREA ((void*) ((((Uint32) _BSG_END | P1AREA) & 0xffffffe0) + 0x20))
#define HEAP_SIZE (WORK_END - (Uint32) HEAP_AREA)

#define PDD_PLOGIC_ACTIVE    0 
#define PDD_PLOGIC_NEGATIVE  1 

// sbss
Uint8* _BSG_END; // TODO: define the actual sbss segment in splits.txt

// TODO: replace current function signatures for the Katana originals
void sbInitSystem(int mode, int frame, int count);
void sbExitSystem(void);

unsigned int InitGdSystemEx(unsigned int MaxDirNum); // TODO: remove this function declaration after decompiling gdlib.c
void sbInitSystem(int mode, int frame, int count)
{
    set_imask(15); 
    
    syHwInit();
    syMallocInit(HEAP_AREA, HEAP_SIZE);
    
    njSetTextureMemorySize(1310720); 
    
    njInitSystem(mode, frame, count); 
    
    syHwInit2(); 
    
    pdInitPeripheral(PDD_PLOGIC_ACTIVE, NULL, NULL); 
    
    syRtcInit(); 

    set_imask(0); 
    
    if (InitGdSystemEx(256) != 0) 
    { 
        sbExitSystem(); 
        
        syBtExit(); 
    }
}

void sbExitSystem(void)
{ 
    ExitGdSystem(); 
    
    syRtcFinish(); 
    
    pdExitPeripheral(); 
    
    njExitSystem(); 
    
    syMallocFinish(); 
    syHwFinish(); 
    
    set_imask(15); 
} 
