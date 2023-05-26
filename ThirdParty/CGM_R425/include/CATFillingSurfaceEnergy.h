// COPYRIGHT DASSAULT SYSTEMES 1997

//===================================================================
//===================================================================
//
// CATFillingSurfaceEnergy
// Class for operator of Energy on surfaces
//
//===================================================================

//===================================================================
// May 00    Creation                         J.Chauvet
//===================================================================
//===================================================================

#ifndef CATFillingSurfaceEnergy_H
#define CATFillingSurfaceEnergy_H

#include "GeoPlate.h"

#include "CATSurParam.h"
#include "CATMathDef.h"
#include "CATMathLimits.h"

class CATSurface;


class ExportedByGeoPlate CATFillingSurfaceEnergy
{
 private:
  double _energy;
  double _tolerance;  
  CATSurParam _start, _end; 
  const CATSurface * _surf;

 public:
//
//- Constructor
//
  CATFillingSurfaceEnergy(const CATSurface * Surf,
               const CATSurParam & SP1, const CATSurParam & SP2,
               const double tol=1.e-12);



//
//- Methods
//
  double GetEnergy();
  void Run();  
};
#endif
