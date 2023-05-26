#ifndef ClampBarGraphAgainstCavityOnPartitions_H
#define ClampBarGraphAgainstCavityOnPartitions_H

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
      * @brief Wrapper of lattice::gm::ClampBarGraphAgainstCavity to process
      * a partitioned body. Will return the list of faces in class from the specified
      * volume with the bar graph.
      */
      HRESULT ClampBarGraphAgainstCavityOnPartitions(
        const LatticeNBModel& iLattice, CATBody& iBody, CATVolume& iVolume, 
        LatticeNBModel*& oClampedLattice, CATTopData& iTopData);
    }
  }
}

#endif
