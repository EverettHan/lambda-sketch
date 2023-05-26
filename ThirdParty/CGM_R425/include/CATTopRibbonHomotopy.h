#ifndef CATNewRibbonHomotopy_H
#define CATNewRibbonHomotopy_H

// COPYRIGHT DASSAULT SYSTEMES  2002
// creation FCH

#include "BODYNOPE.h"

#include "CATTopOperator.h"
#include "CATMathPoint.h"
#include "CATCompositeLaw.h"
#include "CATConnectTool.h"
#include "CATTopRibMacroTool.h"

class CATBody;
class CATCurve;
class CATEdge;
class CATPlane;
class CATBlendParams;
class CATLISTP(CATDynFilletRibbon);
class CATEdgeRibbon;
class CATDynEdgeFilletRibbon;
class CATDynFilletRadius;

// Decoupe une super arete selon la convexite

class ExportedByBODYNOPE CATTopRibbonHomotopy : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopRibbonHomotopy);
public:
   CATTopRibbonHomotopy(CATGeoFactory* iFactory, CATTopData* iTopData);

  virtual ~CATTopRibbonHomotopy();
   
  virtual int Run() = 0;

  virtual CATCurve* GetCurve()= 0;

  virtual CATBoolean GetNormal(CATMathVector  & oNormal) = 0 ;

  virtual CATBody  * GetResult() = 0;

  virtual CATLONG32 GetDiagnostic() = 0;

  virtual void SetRibbonParams(CATBlendParams &iRibbonParams) = 0;

  virtual CATBody * GetCrescentBody() = 0;
  
  //---------------------------------------------------------------------------
  // CreateCircularBody
  // Crée un body "circulaire" de centre iCentre et de rayon iRadius
  // posé sur le plan iPlane.
  // La donnée iTopData est optionnelle et NULL par défaut.
  //---------------------------------------------------------------------------
  CATBody* CreateCircularBody (CATMathPoint   & iCentre,
    CATPlane      * iPlane,
    double          iRadius,
    CATTopData    * iTopData = NULL);



  static CATConnectTool* GetToolFromSpecs(CATSoftwareConfiguration* iConfig,
    CATBody * iCreationBody, 
    CATBody * iInitialBody,
    CATLISTP(CATDynFilletRibbon) & iFilletSpecs,
    CATEdge *iEdge);
  
  static HRESULT GetRadiusAtPoint(CATSoftwareConfiguration* iConfig,
    CATBody * iCreationBody, 
    CATBody * iInitialBody,
    CATLISTP(CATDynFilletRibbon) & iFilletSpecs,
    CATDynFilletRadius *&ioRadius);

  static CATEdgeRibbon *GetEdgeRibbonFromSpecs (CATSoftwareConfiguration* iConfig,
    CATBody * iResult, 
    CATBody * iSpecsBody,
    CATEdge *iEdge, 
    CATLISTP(CATDynFilletRibbon) &iEdgeFilletsSpecs,
    CATLISTP(CATDynFilletRibbon) *iEdgeFilletsNotToLookAt,
    CATBoolean &iTestWithoutParting, 
    CATDynEdgeFilletRibbon *&oFoundSpec,                                                         
    CATListPV &oRadiusAlloues,
    CATBoolean &oVariable);

};

#endif
