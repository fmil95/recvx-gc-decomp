

typedef struct BUTTON_INFO
{
	// total size: 0x8
    int Type;            // offset 0x0, size 0x4
    unsigned int Button; // offset 0x4, size 0x4
} BUTTON_INFO;

typedef struct REPEAT_INFO
{
	// total size: 0xC
    unsigned int WaitFlag; // offset 0x0, size 0x4
    unsigned int WaitCnt;  // offset 0x4, size 0x4
    unsigned int Key;      // offset 0x8, size 0x4
} REPEAT_INFO;

typedef struct PAD_WRK
{
	// total size: 0x3C
    int PerType;         // offset 0x0, size 0x4
    int OldPerType;      // offset 0x4, size 0x4
    int PerTypeEx;       // offset 0x8, size 0x4
    unsigned int Flag;   // offset 0xC, size 0x4
    int SoftReset;       // offset 0x10, size 0x4
    unsigned int on;     // offset 0x14, size 0x4
    unsigned int press;  // offset 0x18, size 0x4
    unsigned int Rept;   // offset 0x1C, size 0x4
    unsigned int on2;    // offset 0x20, size 0x4
    unsigned int on2old; // offset 0x24, size 0x4
    unsigned int press2; // offset 0x28, size 0x4
    unsigned short l;    // offset 0x2C, size 0x2
    unsigned short r;    // offset 0x2E, size 0x2
    short x1;            // offset 0x30, size 0x2
    short y1;            // offset 0x32, size 0x2
    short x2;            // offset 0x34, size 0x2
    short y2;            // offset 0x36, size 0x2
    short Calibrate;     // offset 0x38, size 0x2
} PAD_WRK;
