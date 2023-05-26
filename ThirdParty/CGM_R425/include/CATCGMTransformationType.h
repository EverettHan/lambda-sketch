/* -*-C++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003
//=============================================================================
// CATCGMTransformationType :
//=============================================================================
//=============================================================================
// Oct 03  Creation                          OAU
//=============================================================================
#ifndef CATCGMTransformationType_H
#define CATCGMTransformationType_H


typedef enum
{
  CATMT2D_NoType = 0,
  CATMT2D_AngleType = 1,
  CATMT2D_TargetCurveType = 2,
  CATMT2D_CATLawType = 3
} CATCGMTranfo2DType;


typedef enum
{
  Undefined = 0,
  Direct = 1,
  Reverse = 2
} CATCGMTransfo2DApplyMode;


#endif

