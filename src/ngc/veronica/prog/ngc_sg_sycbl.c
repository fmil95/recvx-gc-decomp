
// TODO: move this enum somewhere else
typedef enum SYE_CBL_TAG {
	SYE_CBL_NTSC = 0,
	SYE_CBL_VGA = 1,
	SYE_CBL_PAL = 2,
	SYE_CBL_MAX
} SYE_CBL;

SYE_CBL syCblCheck( void )
{ 
    return SYE_CBL_NTSC;
}
