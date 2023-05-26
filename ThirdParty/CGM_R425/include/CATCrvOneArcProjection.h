// COPYRIGHT DASSAULT SYSTEMES 1998 
//==========================================================================
//
// CATCrvOneArcProjection:
// Interface class of the Curve Projection giving a one arc PNurbs.
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
//   /08/98 DHN Creation                                                 DHN
// 30/10/03 ndn Ajout SetSoftwareConfig()
// 26/06/15 NLD Remise a niveau
//              - Suppression de SetSoftwareConfig()
//                (configuration desormais passee au constructeur via le createur)
//========================================================================== 
//
#ifndef CATCrvOneArcProjection_H
#define CATCrvOneArcProjection_H
//
#include "PowerFrFOperators.h"
#include "CreateCrvOneArcProjection.h"
#include "CATCGMVirtual.h"

class CATPNurbs;
class CATNurbsCurve;
class CATSoftwareConfiguration;

//
//-----------------------------------------------------------------------------
class ExportedByPowerFrFOperators CATCrvOneArcProjection : public CATCGMVirtual
{
  public :

    virtual               ~CATCrvOneArcProjection  ()                                              {};
    virtual void           SetTolerance            (const double                    & iToler    ) = 0;
    virtual void           SetMaxDegree            (const CATLONG32                 & iMaxDegree) = 0;
//  virtual void           SetSoftwareConfig       (      CATSoftwareConfiguration *  iConfig   ) = 0;
   //
   // It is possible to get Nurbs Curves (3D) as a result. In
   // this case the dimension has to be equal to 3. The default
   // value is 2 (the result is a PNurbs).
   //
    virtual void           SetDimension            (const CATLONG32                 & iDimension) = 0;


    virtual void           Run                     ()                                             = 0;

    virtual CATPNurbs    * GetProjectedArc         (const CATLONG32                 & iArcNumber) = 0;
    virtual CATNurbsCurve* GetProjected3DArc       (const CATLONG32                 & iArcNumber) = 0;
    virtual CATLONG32      GetNumberOfProjectedArcs()                                             = 0;
   virtual double          GetMaxDeviation         (const CATLONG32                 & iArcNumber) = 0;

};
#endif
