//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
//
// CATFrFNetMF :
// Interface class of the Moving Frame using in the Net.
//
//==========================================================================
//
//==========================================================================
// April,   2005 : ANR/FZA : Creation         (D'apres  CATNetMF ) 
//==========================================================================

#ifndef CATFrFNetMF_H  
#define CATFrFNetMF_H

#include "CATFrFNetSurface.h"
#include "CATFrFMovingFrame.h"

class CATMathDirection;
class CATGeoFactory;
class CATFrFCompositeCurve;
class CATFrFCCvParam;
//--------------------------------------------------------------------------
class  ExportedByCATFrFNetSurface CATFrFNetMF
{
public :
  virtual ~CATFrFNetMF ();

  virtual void Run ()=0; 

  virtual void SetViewingDirection (const CATMathDirection& iDirection)=0;
  virtual void SetNormalDirection  (const CATMathDirection& iDirection)=0;
 
  virtual double GetParam (const CATFrFCCvParam & iCCvParam)=0;
  virtual CATFrFMovingFrame * GetResult()=0;
};

ExportedByCATFrFNetSurface
CATFrFNetMF * CATFrFCreateNetMF (CATGeoFactory        * iFactory,
                                 CATLONG32                   iNbOfGuides,
                                 CATFrFCompositeCurve** iGuideCCVs,
                                 CATLONG32                   iNumdomGuide,
                                 CATMovingFrameType     iMvFOption);
#endif









