/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
// Class CATSmoothPlaneDirCurve
//-----------------------------------------------------------------------------
// June 2005  Creation                                  CWM
// 
//=============================================================================
//
// Usage notes:
//
//=============================================================================
#ifndef CATSmoothPlaneDirCurve_h
#define CATSmoothPlaneDirCurve_h

//#include "CATCGMVirtual.h"
#include "CATConnectSmooth.h"
#include "FrFOpeCrv.h"
#include "CATMathSetOfPointsND.h"
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATMathFunctionX;
class CATCurve;

class ExportedByFrFOpeCrv CATSmoothPlaneDirCurve : public CATConnectSmooth
{
public:
   //---------------------------------------------------------------------------
  // Object Management
  //---------------------------------------------------------------------------
  CATSmoothPlaneDirCurve( CATGeoFactory               * iFactory, 
                          CATSoftwareConfiguration    * iConfig);
  ~CATSmoothPlaneDirCurve();

  virtual int                Run(); 

  virtual CATConnectSmooth * Clone();

private:
          void               InitTab();

private:
  // Input data.
        CATCurve         ** _TabCurve; // Courbes lissees 
  const CATMathFunctionX ** _TabX,     //Equations pour chacune des courbes entre 2 points exacts
                         ** _TabY,
                         ** _TabZ;
        CATMathFunctionX ** _CompoX,
                         ** _CompoY,
                         ** _CompoZ;
        CATMathFunctionX ** _ScaledCompoX,
                         ** _ScaledCompoY,
                         ** _ScaledCompoZ;
        CATMathFunctionX ** _TabLinear; 
        CATMathFunctionX  * _ScalingFunction;
};

// N.B Ici extern "C" est je pense indispensable car il existe un chargement dynamique de cette
//     fonction, dont il importe donc de conserver le nommage (sans "Mangling")
//     NLD021020
extern "C" ExportedByFrFOpeCrv CATSmoothPlaneDirCurve * CATCreateSmoothPlaneDirCurve(CATGeoFactory               * iFactory, 
                                                                                     CATSoftwareConfiguration    * iConfig);


#endif
