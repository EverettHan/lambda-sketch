//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
//
// CATFrFNetMesh :
// Achieve the mesh step for the loft :
// It includes three steps :
//    - Trim (reordering, trim and extrapolation)
//    - Homogenization of the bases and of the guides
//    - Adaptation of the bases on the guides.
//
//==========================================================================
// Nov,     2005 : ANR : Ajout d'une option de decoupe pour l'offsetabilite des SDS
// April,   2005 : ANR/FZA : Creation      (D'apres  CATLoftMesh )     
//==========================================================================

#ifndef CATFrFNetMesh_H  
#define CATFrFNetMesh_H

#include "CATFrFNetSurface.h" 

#include "CATLISTV_CATMathPoint.h"
#include "CATDataType.h"
#include "CATBoolean.h"
#include "CATDataType.h"


class CATFrFCompositeCurve;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATFrFNetSupport;
class CATMathDirection;
class CATMathSetOfPoints;

//--------------------------------------------------------------------------
class  ExportedByCATFrFNetSurface CATFrFNetMesh
{
public :

  virtual ~CATFrFNetMesh();

  virtual void Run()=0; 

  virtual CATFrFCompositeCurve* GetResultingGuideCCV(const CATLONG32 iNumGuide)=0;
  virtual CATFrFCompositeCurve* GetResultingBaseCCV (const CATLONG32 iNumBase)=0;

  virtual CATFrFCompositeCurve** GetResultingGuideCCVs()=0;
  virtual CATFrFCompositeCurve** GetResultingBaseCCVs()=0;

  virtual CATFrFCompositeCurve** GetTrimmedGuideCCVs()=0;
  virtual CATFrFCompositeCurve** GetTrimmedBaseCCVs()=0;

  virtual CATLONG32 GetOrderGuide (const CATLONG32 iOrder)=0;
  virtual CATLONG32 GetOrderBase  (const CATLONG32 iOrder)=0;

  virtual CATLONG32 GetNewINumDomGuide()=0;
  virtual CATLONG32 GetNewINumDomBase()=0;

  virtual CATLONG32 GetNbOfGuides()=0;
  virtual CATLONG32 GetNbOfBases()=0;

  virtual double* GetGlobalGuideMinDistParams()=0;
  virtual double* GetGlobalBaseMinDistParams()=0;

  virtual CATLONG32 GetLimitationGuide()=0; //(FZA) pour les cas fermés
  virtual CATLONG32 GetLimitationBase()=0; //(FZA) pour les cas fermés

  virtual void SetViewingDirection(CATMathDirection& dir)=0;
  virtual void SetNormalDirection(CATMathDirection& dir)=0;

  virtual void SetGuideSupports(CATFrFNetSupport* iGuideSupport)=0;
  virtual void SetBaseSupports (CATFrFNetSupport* iBaseSupport)=0;

  virtual void SetTrimValues (const CATLONG32 iGuideTrim,
    const CATLONG32 iBaseTrim) = 0;

  virtual CATGeoFactory* GetGeoFactory()=0;
  virtual CATSoftwareConfiguration * GetConfig()=0;
  /* coverage
  virtual CATLONG32 GetOrderOfContinuityGuide (CATLONG32 iOrder)=0;
  virtual CATLONG32 GetOrderOfContinuityBase  (CATLONG32 iOrder)=0;
  */
  virtual void GetPointsNotSatisfyingCont(CATLONG32           &oNbreOnGuides, 
                                          CATLONG32           &oNbreOnBases,
                                          CATMathSetOfPoints *&oSetOfPoint, 
                                          CATLONG32          *&oSetOfOrder, 
                                          double             *&oDefaultOfContinuity,
                                          CATLONG32          **oIndexOfGuideProfile)=0;
  /* coverage
  virtual CATBoolean GeomConstAlongGuidesIsNecessary()=0;
  virtual CATBoolean GeomConstAlongBasesIsNecessary()=0;
  */
  virtual void GetMaxDeformation(double &oMaxErrorOnGuides, double &oMaxErrorOnProfiles)=0;

  virtual void SetStopAtUncompatibility ()=0;

  virtual void SetCutting(CATBoolean IsNeed)=0 ;

  virtual void ImposedGuideCouplingsPoints(const CATLISTV(CATMathPoint) &iCouplingsPoints, int iDim=2) = 0 ;

  virtual void SetCouplingsType (const CATLONG32 iType ) =0;

  virtual void ImposedCubicDegree () =0;

  virtual void ImposedGuideMaxArcs(int iNbMaxFacesGuide) =0;
  virtual void ImposedProfileMaxArcs(int iNbMaxFacesProfile) =0;

  virtual void SetParamGuideType(const CATLONG32 iGuidesParamType) = 0;
  virtual void SetParamBaseType (const CATLONG32 iBasesParamType)  = 0;

  //Ajout par anr : Pour l'Offsetabilite des surfaces de subdivisons :
  virtual void SetCuttingOption_ForSDSOffset (CATBoolean iOption = TRUE)  = 0;

  //Ajout par anr : Pour PCurve : on reparametrise tout le temps ... :
  virtual void SetParametrization_ForPCurves (CATBoolean iOption = TRUE)  = 0;
 

  // On fait que le Trim et on calcule le nb Max d'arc
  virtual void SetSubdivisionOption(CATBoolean iOption=FALSE, CATBoolean iLODMode = TRUE, CATBoolean iNetsubdivMode = FALSE)=0;
  virtual void GetNbMaxFaces (int &oNbFacesGuide, int &oNbFacesProfile) = 0;
  virtual void GetNbMinFaces (int &oNbFacesGuide, int &oNbFacesProfile) = 0;

};
#endif









