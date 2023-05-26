//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
//
// CATFrFConvertCCVToNurbsCCV :
// conversion d un CATCompositeCurve contenant des CATCurve de 
// type quelconque en une CCV contenant des CATNurbsCurves
//==========================================================================
// April,   2005 : ANR/FZA : Creation   (D'apres CATConvertCCVToNurbsCCV)
//==========================================================================

#ifndef CATFrFConvertCCVToNurbsCCV_H
#define CATFrFConvertCCVToNurbsCCV_H
#include "CATFrFNetSurface.h"
#include "CATDataType.h"

class CATFrFCompositeCurve;
class CATGeoFactory;
class CATSoftwareConfiguration;
//----------------------------------------------------------------------
class ExportedByCATFrFNetSurface CATFrFConvertCCVToNurbsCCV
{
public :
  
  CATFrFConvertCCVToNurbsCCV (CATGeoFactory            * iFactory,
                              CATSoftwareConfiguration * iConfig,
                              CATFrFCompositeCurve     * iCCV,
                              const CATLONG32            iminimumDegree = 0);

  ~CATFrFConvertCCVToNurbsCCV();
  
  CATFrFCompositeCurve* GetResult();
  
  CATLONG32 Is2D();
  
private :

  CATFrFCompositeCurve * _ResultingCCV;
  CATLONG32              _Is2D;
};
#endif
