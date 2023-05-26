#ifndef CATCDSGMUtilities_H
#define CATCDSGMUtilities_H

#include "StreamGM.h"
#include "CATBoolean.h"

class CATMathPlane;
class CATMathTransformation;

class ExportedByStreamGM CATCDSGMUtilities
{
public:
  // calcule la nouvelle matrice de transfo dans le nouveau repère associé au sketch
  static CATBoolean ComputeTransfoOnSketchBasis(CATMathPlane const& iSketch, CATMathTransformation const& iTransfo, CATMathTransformation& oTransfo);
  static CATBoolean Compute3dTransfoFromTransfoOnSketch(CATMathPlane const& iSketch, CATMathTransformation const& iTransfo, CATMathTransformation& oTransfo);

};

#endif

