/**
 * @level Protected
 * @usage U1
 */
/* CATV4Model.h : COPYRIGHT DASSAULT SYSTEMES 1995 */
#ifndef CodeVisuModel_h
#define CodeVisuModel_h
#include "BigLittle.h"
//----------------------------------------------------------------
//                  Code de VISU V4
//----------------------------------------------------------------

struct CodeVisu 
{
#ifndef _ENDIAN_LITTLE
  unsigned opq : 1;  // Opacite          bit  0     std=0  VP (=1) ou pas VP (=0) 
  unsigned sht : 1;  // Show Temporaire  bit  1     std=1
  unsigned dtt : 1;  // Pick Temporaire  bit  2     std=1
  unsigned tem : 1;  // Temporaire       bit  3     std=0
  unsigned sel : 1;  // highlight        bit  4     std=0
  unsigned shp : 1;  // show permanent   bit  5     std=1
  unsigned dtp : 1;  // Pick permanent   bit  6     std=1
  unsigned spl : 1;  // space/plane      bit  7     std=1
  unsigned cli : 1;  // clignotement     bit  8     std=0
  unsigned col : 7;  // couleur          bit  9-15  std=0
  unsigned grp : 2;  // groupe           bit 16-17  std=0
  unsigned aex : 5;  // thickness        bit 18-22  std=1
  unsigned atx : 5;  // texture          bit 23-27  std=0
  unsigned rsv : 2;  //  internal        bit 28-29
  unsigned sha : 1;  // show applicatif  bit 30       
  unsigned sup : 1;  // erased           bit 31
#else
  unsigned sup : 1;  // erased           bit 31
  unsigned sha : 1;  // show applicatif  bit 30       
  unsigned rsv : 2;  //  internal        bit 28-29
  unsigned atx : 5;  // texture          bit 23-27  std=0
  unsigned aex : 5;  // thickness        bit 18-22  std=1
  unsigned grp : 2;  // groupe           bit 16-17  std=0
  unsigned col : 7;  // couleur          bit  9-15  std=0
  unsigned cli : 1;  // clignotement     bit  8     std=0
  unsigned spl : 1;  // space/plane      bit  7     std=1
  unsigned dtp : 1;  // Pick permanent   bit  6     std=1
  unsigned shp : 1;  // show permanent   bit  5     std=1
  unsigned sel : 1;  // highlight        bit  4     std=0
  unsigned tem : 1;  // Temporaire       bit  3     std=0
  unsigned dtt : 1;  // Pick Temporaire  bit  2     std=1
  unsigned sht : 1;  // Show Temporaire  bit  1     std=1
  unsigned opq : 1;  // Opacite          bit  0     std=0  VP (=1) ou pas VP (=0) 
#endif
};

#endif
