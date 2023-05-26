#ifndef CATExtrapolWireToShellBoundary_h
#define CATExtrapolWireToShellBoundary_h
//==========================================================================
// Interface class to extrapolate a wire body lying on a shell 
// to the boundary of the shell at both ends of the wire.
// Restrictions:
// The wire body and the shell body must each contain only one domain.
//==========================================================================
// 07/05/2020 G5S Created by extracting code from CATHybProjectWireOnShell.
// 20/05/2020 G5S Add the ExportedByPBELight so this can be used for ODTs.
//==========================================================================

//#include "ExportedByCATTopologicalObjects.h"
#include "CATTopOperator.h"
#include "CATDynExtrapolationToolsDef.h"
#include "ExportedByPBELight.h"

// class ExportedByCATTopologicalObjects CATExtrapolWireToShellBoundary : public CATTopOperator
class CATExtrapolWireToShellBoundary : public CATTopOperator
{
public:
  // Set tolerance for internal use. Probably only needed to maintain existing behaviour of
  // callers.
  // By default, tolerance = Factory resolution.
  virtual void SetToleranceForLayDown(double iTol) = 0;

  // Tells us whether extrapolation was done.  It's not done if the wire already reaches the 
  // boundary at both ends of if it's closed.
  virtual CATBoolean GetExtrapolationDone() = 0;

  virtual ~CATExtrapolWireToShellBoundary();

protected:
  CATExtrapolWireToShellBoundary(CATGeoFactory * iGeoFactory, CATTopData * iData, CATExtTopOperator* iExtensible);
  
};

// Create function.
// iExtrapolationMode = DYN_NO_EXTRAPOLATION, DYN_TANGENT_DIRECTION or DYN_CURVATURE_EXTRAPOLATION.
ExportedByPBELight CATExtrapolWireToShellBoundary * CATCreateExtrapolWireToShellBoundary(CATGeoFactory * iFactory,
  CATTopData * iTopData,
  CATBody    * iWireBody,
  CATBody    * iShellBody,
  CATDynExtrapolationMode  iExtrapolationMode);
#endif
