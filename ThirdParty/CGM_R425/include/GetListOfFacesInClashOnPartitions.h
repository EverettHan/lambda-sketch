#ifndef GetListOfFacesInClashOnPartitions_H
#define GetListOfFacesInClashOnPartitions_H

#include "ExportedByLatticeGMOperators.h"

#include "CATSysErrorDef.h"
#include "CATCGMScaleCategoryDef.h"

#include "CATVRepType.h"

#include "CATSetOfInt.h"

#include <list>

#include "CATIPolyMesh.h"
#include "LatticeFrameFields.h"

class LatticeNBModel;
class CATBody;
class CATFace;
class CATGeoFactory;
class CATPolyBody;
class CATMathTransformation;
class CATTopData;
class CATVolume;

class CATWire;

namespace lattice
{
  namespace gm
  {
    namespace pb
    {
      /**
      * @brief Wrapper of lattice::gm::GetListOfFacesInClashOnPartitions to process
      * a partitioned body. Will return the list of faces in class from the specified
      * volume with the bar graph.
      */
      HRESULT GetListOfFacesInClashOnPartitions(
        CATGeoFactory * iFactory, CATTopData * iTopData, 
        CATCGMScaleCategory iScale, const LatticeNBModel& iLattice, 
        CATBody& iBody, CATVolume& iVolume, std::list<CATFace*>& ioClashFaces);
    }
  }
}

#endif
