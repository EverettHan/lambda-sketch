#ifdef CATFrfUnused

//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================

// CATFrFNetMeshSubdivision :
// Achieve the mesh step for the net :
// It includes three steps :
//    - Trim (reordering, trim and extrapolation)
//    - Homogenization of the bases and of the guides
//    - Adaptation of the bases on the guides.
//
//====================================================================
//
//==================================================================== 
// 24/10/05 : MMO : je coupe car pas utilise pour le moment
// April 2005   : ANR/FZA  Creation     (D'apres  CATFrFNetMesh )
//==================================================================== 
#ifndef CATFrFNetMeshSubdivision_H  
#define CATFrFNetMeshSubdivision_H

#include "CATFrFNetSurface.h"
#include "CATSkillValue.h"
#include "CATBoolean.h"
#include "CATDataType.h"
 
class CATFrFCompositeCurve;
class CATGeoFactory;
class CATSoftwareConfiguration;
//class CATFrFNetSupport;
//class CATMathDirection;
//class CATMathSetOfPoints;

//--------------------------------------------------------------------------
class CATFrFNetMeshSubdivision
{
  public :
    
    virtual ~CATFrFNetMeshSubdivision();
    virtual void Run()=0;
    
    virtual void SetGuidesParam(const CATLONG32 iGuidesParametrization)=0;
    virtual void SetBasesParam (const CATLONG32 iBasesParametrization)=0;

    virtual CATFrFCompositeCurve* GetResultingGuideCCV(const CATLONG32 iNumGuide)=0;
    virtual CATFrFCompositeCurve* GetResultingBaseCCV (const CATLONG32 iNumBase)=0;

    virtual CATFrFCompositeCurve** GetResultingGuideCCVs()=0;
    virtual CATFrFCompositeCurve** GetResultingBaseCCVs()=0;

    virtual CATLONG32 GetOrderGuide (const CATLONG32 iOrder)=0;
    virtual CATLONG32 GetOrderBase  (const CATLONG32 iOrder)=0;

    virtual CATLONG32 GetNbOfGuides()=0;
    virtual CATLONG32 GetNbOfBases()=0;

    virtual double* GetGlobalGuideMinDistParams()=0;
    virtual double* GetGlobalBaseMinDistParams()=0;

    virtual CATGeoFactory* GetGeoFactory()=0;
    virtual CATSoftwareConfiguration * GetConfig()=0;

    virtual CATLONG32 GetNewINumDomGuide()=0;
    virtual CATLONG32 GetNewINumDomBase()=0;

    virtual CATFrFCompositeCurve** GetTrimmedGuideCCVs()=0;
    virtual CATFrFCompositeCurve** GetTrimmedBaseCCVs()=0;

    virtual void GetMaxDeformation (double &oMaxErrorOnGuides, 
                                    double &oMaxErrorOnProfiles)=0;

    virtual CATLONG32 GetLimitationGuide()=0; //(FZA) pour les cas fermés
    virtual CATLONG32 GetLimitationBase()=0; //(FZA) pour les cas fermés

    virtual void SetTrimValues (const CATLONG32 iGuideTrim,
                                const CATLONG32 iBaseTrim)=0;

    virtual void SetDominantGuide (const CATLONG32 iDomGuide)=0; // (FZA) pour le test A ENLEVER APRES
    virtual void SetDominantBase (const CATLONG32 iDomBase)=0; // (FZA) pour le test A ENLEVER APRES

  protected:

                 CATFrFNetMeshSubdivision() {}


};

// CATCreateFrFNetMeshSubdivision :
// global function that creates a CATFrFNetMesh object.
// It treated every cases (i.e cases of CATCreateFrFNetMesh, of CATCreateFrFNetMonoGuideMesh
// and of CATCreateFrFNetMonoBaseMesh)
//
ExportedByCATFrFNetSurface
CATFrFNetMeshSubdivision* CATFrFCreateNetMeshSubdivision(CATGeoFactory            * ifactory,
                                                         CATSoftwareConfiguration * iConfig,
                                                         CATLONG32                  inbOfGuides,
                                                         CATFrFCompositeCurve    ** iguideCCVs, 
                                                         CATLONG32                  inbOfBases,
                                                         CATFrFCompositeCurve    ** ibaseCCVs,  
                                                         CATSkillValue              iMode=BASIC);

ExportedByCATFrFNetSurface
void Remove(CATFrFNetMeshSubdivision *&iLoftMesh);


#endif

#endif
