#ifndef VolumetricSweepConvertProfileData_H
#define VolumetricSweepConvertProfileData_H

// COPYRIGHT DASSAULT SYSTEMES 2014

#include "CATCGMVolumetricSweepCmp.h" // NLD260917 #include "AdvVolSweep.h"
#include "CATListOfDouble.h"
#include "CATLISTV_CATMathPoint2D.h"
#include "CATTolerance.h"

class CATMathPoint;
class CATMathVector;
class CATMathPlane;
class CATBody;
class VswpAxisymBodyDef;

// Convert to a smooth profile using filleting radii.

ExportedByCATCGMVolumetricSweepCmp void
VolumetricSweepConvertProfileData(
                  CATLISTV(CATMathPoint2D) const & iToolProfilePoints,
                  CATListOfDouble                & iToolProfileRadii,
                //CATMathVector            const & iToolAxisDirection,
                //CATMathPoint             const & iToolAxisOrigin,
                  double                           iTolerance,
                  const CATTolerance             & iTolObj,
                  VswpAxisymBodyDef             *& oAxisymBodyDef
                  );

// Convert to a smooth profile using filleting radii.

ExportedByCATCGMVolumetricSweepCmp void
VolumetricSweepConvertProfileData(
                  CATBody                       *  pProfileWireBody,
                  CATMathPlane const             & iRefProfilePlane,
                  CATMathPlane const             & iRefTargetPlane,
                  double                           iTolerance,
                  const CATTolerance             & iTolObj,
                  VswpAxisymBodyDef             *& oAxisymBodyDef
                  );

#if defined(CATIAR418) && !defined(CATIAR419)
// REMOVE THIS INTERFACE ONCE THIS CODE reaches CGMPRJ
ExportedByCATCGMVolumetricSweepCmp void
VolumetricSweepConvertProfileData(
                  CATLISTV(CATMathPoint2D) const & iToolProfilePoints,
                  CATListOfDouble                & iToolProfileRadii,
                //CATMathVector            const & iToolAxisDirection,
                //CATMathPoint             const & iToolAxisOrigin,
                  double                           iTolerance,
                  VswpAxisymBodyDef             *& oAxisymBodyDef
                  );
#endif

// Convert to a piecewise linear profile using only profile points.

ExportedByCATCGMVolumetricSweepCmp void
VolumetricSweepConvertProfileData(
                  CATLISTV(CATMathPoint2D) const & iToolProfilePoints,
                //CATMathVector            const & iToolAxisDirection,
                //CATMathPoint             const & iToolAxisOrigin,
                  double                           iTolerance,
                  const CATTolerance             & iTolObj,
                  VswpAxisymBodyDef              *& oAxisymBodyDef
                  );

#if defined(CATIAR418) && !defined(CATIAR419)
// REMOVE THIS INTERFACE ONCE THIS CODE reaches CGMPRJ
ExportedByCATCGMVolumetricSweepCmp void
VolumetricSweepConvertProfileData(
                  CATLISTV(CATMathPoint2D) const & iToolProfilePoints,
                //CATMathVector            const & iToolAxisDirection,
                //CATMathPoint             const & iToolAxisOrigin,
                  double                           iTolerance,
                  VswpAxisymBodyDef             *& oAxisymBodyDef
                  );
#endif

// Given the profile of an axisymmetric body which may contain linear
// profile segments with rounded corners, find the sequence of sharp 
// corners and filleting radii.

ExportedByCATCGMVolumetricSweepCmp void
VolumetricSweepConvertProfileData(
                        VswpAxisymBodyDef    const & iAxisymBodyDef,
                        double               const   iTolerance,
                  const CATTolerance               & iTolObj,
                        CATMathPoint               & oToolAxisOrigin,
                        CATMathVector              & oToolAxisDirection,
                        CATLISTV( CATMathPoint2D ) & oToolProfilePoints,
                        CATListOfDouble            & oToolProfileRadii
                  );

#if defined(CATIAR418) && !defined(CATIAR419)
// REMOVE THIS INTERFACE ONCE THIS CODE reaches CGMPRJ
ExportedByCATCGMVolumetricSweepCmp void
VolumetricSweepConvertProfileData(
                        VswpAxisymBodyDef    const & iAxisymBodyDef,
                        CATMathPoint               & oToolAxisOrigin,
                        CATMathVector              & oToolAxisDirection,
                        CATLISTV( CATMathPoint2D ) & oToolProfilePoints,
                        CATListOfDouble            & oToolProfileRadii,
                        double               const   iTolerance
                  );
#endif

#endif
