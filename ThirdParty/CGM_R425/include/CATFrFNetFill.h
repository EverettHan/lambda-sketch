//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
//
// CATFrFNetFill :
// Interface class of the Fill Surface Operator.
//
// Achieve the fill step for the net :
// It consists in computing intermediate bases by mixing each couple
// of bases.
//
//==========================================================================
//
//==========================================================================
// April 2005   : ANR/FZA  Creation                 (D'apres  CATLoftFill)     
//==========================================================================
#ifndef CATFrFNetFill_H  
#define CATFrFNetFill_H

#include "CATFrFNetSurface.h"

#include "CATDataType.h"
#include "CATBoolean.h"

class CATFrFCompositeCurve;
class CATSurface;
class CATMathDirection;
class CATFrFNetSupport;

class CATFrFNurbsBipar;
//--------------------------------------------------------------------------
class  ExportedByCATFrFNetSurface CATFrFNetFill
{
public :
  
  virtual ~CATFrFNetFill();
  
  virtual void Run()=0; 
  
  virtual CATSurface* GetResultingSurface (CATLONG32 iU, 
                                           CATLONG32 iV)=0;


  virtual CATFrFNurbsBipar* GetBipar ()=0;
  

  virtual CATLONG32 GetNbOfSurfacesAlongU()=0;
  virtual CATLONG32 GetNbOfSurfacesAlongV()=0;


  virtual void SetViewingDirection (CATMathDirection& iDir)=0;
  virtual void SetNormalDirection  (CATMathDirection& iDir)=0;
  
  //  0 for the loft surfaces
  //  1 for the profiled surfaces
  virtual void SetSurfMode (CATLONG32 iSurfMode)=0;
  virtual void SetC2Choice (CATLONG32 iC2Choice)=0;
  
/* pour coverage 
  virtual void SetLocalC2DeformationWeights (double* LeftWeights,
                                             double* RightWeights)=0;
  
  virtual void SetGlobalC2ContinuityCoefficients (double globalLeastSquareCoef,
                                                  double globalElasticityCoef,
                                                  double globalStiffnessCoef)=0; 
*/
  
  virtual void SetGuideParametrization (CATFrFCompositeCurve * iGuideParam) = 0;
  virtual void SetBaseParametrization  (CATFrFCompositeCurve * iBaseParam ) = 0;
  
  virtual void SetGuideSupports (CATFrFCompositeCurve ** iSupportGuides, 
                                 CATFrFNetSupport      * iGuideSupportOrders)=0;
  virtual void SetBaseSupports  (CATFrFCompositeCurve ** ISupportBases,
                                 CATFrFNetSupport      * iBaseSupportOrders )=0;
  
  // Seulement avec constraintes Externes
  // et l'erreur Max, plus tard on fera pour chaque bord et l'endroit ...
  virtual void GetPrecisionWithData (double &oGapG0, 
                                     double &oGapG1, 
                                     double &oGapG2)=0;
  
  virtual void SetCutting(CATBoolean IsNeed)=0 ;
  
  virtual void SetTrimValues (CATLONG32 iGuideTrim,
                              CATLONG32 iBaseTrim) = 0;

  virtual void SetLimitation (CATLONG32 iClosedGuide,
                              CATLONG32 iClosedBase) = 0; //(FZA) pour les cas fermés
};
#endif
