#include "ngc/veronica/prog/ngc_NaMem.h"

void njMemCopy(void *dst, const void *src, Sint32 num) {
  char *cpSrc;
  char *cpDst;

  cpSrc = (char *)src;
  cpDst = (char *)dst;

  for (; num != 0; num--) {
    *cpDst++ = *cpSrc++;
  }
}

void njMemCopy4(void *dst, const void *src, Sint32 num) {
  int *lpSrc;
  int *lpDst;

  lpSrc = (int *)src;
  lpDst = (int *)dst;

  for (; num != 0; num--) {
    *lpDst++ = *lpSrc++;
  }
}

void njMemCopy2(void *dst, const void *src, Sint32 num) {
  short *lpSrc;
  short *lpDst;

  lpSrc = (short *)src;
  lpDst = (short *)dst;

  for (; num != 0; num--) {
    *lpDst++ = *lpSrc++;
  }
}
