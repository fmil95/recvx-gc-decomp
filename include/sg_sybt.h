/********************************************************************
 *  Shinobi Library
 *  Copyright (c) 1998-1999 SEGA
 *
 *  Library : BootRom Service & System ID Data Check Library
 *  Module  : Library Interface Header
 *  File    : sg_sybt.h
 *  Date    : 1999-01-21
 *  Version : 1.01
 *
 ********************************************************************/

#ifndef _SG_SYBT_H_
#define _SG_SYBT_H_

/********************************************************************/
/*  CN[ht@C                                            */
/*   inlcude files                                                  */
/********************************************************************/
#include    <sg_xpt.h>                      /*                      */
#include    <shinobi.h>                     /*                      */

/********************************************************************/
/*  čč`                                                        */
/*  constants                                                       */
/********************************************************************/
#define SYD_BT_OK                (1)          /*                    */
#define SYD_BT_NG                (0)          /*                    */

/********************************************************************/
/*  ^č`                                                          */
/*  structure/union/enum                                            */
/********************************************************************/
struct tag_SYS_BT_SYSTEMID{                   /*                    */
    Sint32 nNo ;                              /*                    */
    Sint32 nAll ;                             /*                    */
    Sint8  szProduct[16];                     /*                    */
} ;                                           /*                    */
typedef struct tag_SYS_BT_SYSTEMID SYS_BT_SYSTEMID ;

/********************************************************************/
/*  Öč`                                                        */
/*  functions                                                       */
/********************************************************************/
#ifdef __cplusplus
extern "C"{                                 /* for C++ Interface    */
#endif  /* __cplusplus */

extern Void   syBtExit     ( Void );
extern Sint32 syBtCheckDisc( Void );

extern Sint32 syBtGetBootSystemID   ( SYS_BT_SYSTEMID* ) ;
extern Sint32 syBtGetCurrentSystemID( SYS_BT_SYSTEMID* ) ;

#ifdef __cplusplus
}                                           /* for C++ Interface    */
#endif /* __cplusplus  */
#endif /* _SG_SYBT_H_ */
/****************************************** End of sg_sycfg.h *******/
