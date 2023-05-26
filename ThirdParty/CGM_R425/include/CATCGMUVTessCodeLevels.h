#ifndef CATCGMUVTessCodeLevels_H
#define CATCGMUVTessCodeLevels_H

#include "ExportedByTessellateCommon.h"

class ExportedByTessellateCommon CATCGMUVTessCodeLevels
{
public:
  // get the CGMLevel corresponding to iTessCodeLevel
  static short GetCGMLevel(unsigned short iTessCodeLevel);

  // get the TessCodeLevel corresponding to iCGMLevel
  // to be precise: 
  //   get the largest TessCodeLevel whose CGMLevel is lesser or equal to iCGMLevel
  static unsigned short GetTessCodeLevel(short iCGMLevel);

  // get the current latest TessCodeLevel
  static unsigned short GetLatestTessCodeLevel();
};


////////////////////////////////////////////////////////////////////
// This file contains the list of TessCodeLevel definitions
// When there's a code change in UV tessellation/compression/decompression
// then add a new definition of TessCodeLevel at the end and
// version your code change with the new level.
////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
// Syntax:
// DefineFor_TessCodeLevel(TessCodeLevel, LevelName, CGMLevel)
//
// Note: First valid TessCodeLevel is 1, not 0.
//       TessCodeLevel = 0 is invalid
//////////////////////////////////////////////////////////////

///////////////////////////////////////////////////
// Sample:
//
//#define DefineFor_AllTessCodeLevels                                        \
//                                                                           \
//  /* First versions definition */                                          \
//  DefineFor_TessCodeLevel(1, First,  4628)                                 \
//                                                                           \
//  /* Define new stream versions below */                                   \
//  /* (in increasing order only)       */                                   \
//                                                                           \
//  /* Date, Trigram */                                                      \
//  /* Details of fixes/enahancements .....*/                                \
//  /* ................................ */                                   \
//  DefineFor_TessCodeLevel(2, MyFix1, 4670)                                 \
//                                                                           \
//  /* Date, Trigram */                                                      \
//  /* Details of fixes/enahancements .....*/                                \
//  /* ................................ */                                   \
//  DefineFor_TessCodeLevel(3, MyFix2, CGM_Versionning_TessCodeR23SP1)       \
//                                                                           \
//  /* Date, Trigram */                                                      \
//  /* Details of fixes/enahancements .....*/                                \
//  /* ................................ */                                   \
//  DefineFor_TessCodeLevel(4, MyFix3, CGM_Versionning_TessCodeR23SP2)
//
///////////////////////////////////////////////////



#define DefineFor_AllTessCodeLevels                                                            \
                                                                                               \
  /* Dummy level  */                                                                           \
  DefineFor_TessCodeLevel(1, Dummy,  1)                                                        \
                                                                                               \
  /* 20-July-2012: mpx */                                                                      \
  /* First version definition for R22SP4 / R23 / R214(V6R2013x) */                             \
  DefineFor_TessCodeLevel(2, First,  4628)                                                     \
                                                                                               \
  /* 8-Apr-2013: mpx */                                                                        \
  /* R23SP3 / R216(V6R2014x) */                                                                \
  /* 1. Cache bufferizing is made thread-safe using CATPolyStreamReader*/                      \
  /* 2. Added flexibility on presence of subdivision buffers for edge w*/                      \
  DefineFor_TessCodeLevel(3, R23SP3_1, CGM_Versionning_TessCodeR23SP3_1)                       \
                                                                                               \
  /* Define new stream versions below */                                                       \
  /* (in increasing order only)       */                                                       


#endif //CATCGMUVTessCodeLevels_H

