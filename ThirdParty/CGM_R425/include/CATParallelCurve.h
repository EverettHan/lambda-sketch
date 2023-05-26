// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATParallelCurve:
// Interface class of the Parallel Curve Operator.
//
//=============================================================================
//
// Usage notes:
// This class can be used as is for simple Parallel Curve or derived
// in order to implement specific algorithm or capabilities.
//
//=============================================================================
// July 1998     Creation                   J. Bouix
//=============================================================================
// HISTORIQUE DES MODFICATIONS
// 3/11/98  jbx  La methode SetLimits
//
#ifndef CATParallelCurve_H
#define CATParallelCurve_H

#include "FrFOpeCrv.h"
#include "CATTopDef.h"
#include "CATCrvLimits.h"
#include "CATCGMVirtual.h"

class CATSurLimits;
class CATGeoFactory;
class CATCurve;
class CATSurface;
class CATGeometry;
class CATLaw;
class CATFrFCompositeCurveMapping;

//-----------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATParallelCurve  : public CATCGMVirtual
{
  public :
    CATParallelCurve(CATGeoFactory    * iFactory,
                     const CATGeometry   * iRef,
                     CATOrientation     iRefOrient,
                     const CATSurface * iSupport,
                     CATOrientation     iSupOrient,
                     double             iOffset,
                     CATSurLimits     * iSupLimits = NULL);

   ~CATParallelCurve();
   void Run();
   CATCurve * GetResult() const ;
   
   void SetLimits(const CATCrvLimits & iCrvLim);

   void SetLaw(CATLaw * iLaw, CATFrFCompositeCurveMapping * iMapping,
              int iIndexCrv);
  
  protected :
   
    const CATGeometry           * _Ref;
    const CATSurface            * _Support;
    CATSurLimits                * _SupportLimits;
    CATCurve                    * _ResultCurve;
    CATGeoFactory               * _Factory;
    CATOrientation                _SupportOrientation;
    CATOrientation                _RefOrientation;
    double                        _Offset;
    CATCrvLimits                  _CrvLim; 

    CATLaw                      * _Law;
    CATFrFCompositeCurveMapping * _Mapping;
    int                           _IndexCrv;
};
#endif





