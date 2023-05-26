#ifndef CATPolyMeshNormalFlipChecker_H
#define CATPolyMeshNormalFlipChecker_H

#include "PolyVizUtils.h"

class CATIPolyMesh;
class CATPolyMeshEVizUVFace;
class CATMathDirectionf;



class ExportedByPolyVizUtils CATPolyMeshNormalFlipChecker
{

public:
  CATPolyMeshNormalFlipChecker(const CATMathDirectionf& iSight);

  virtual ~CATPolyMeshNormalFlipChecker();

  
  // main method
  int AreVertexNormalsFlipping(const CATIPolyMesh& iMesh);

private:

  // is there a flip?
  int _bIsNormalFlipping;

  // observer direction
  const CATMathDirectionf & _Sight;
};


#endif



