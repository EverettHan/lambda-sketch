#ifndef CreateUnionedBodyStitchingOnPartitions_H
#define CreateUnionedBodyStitchingOnPartitions_H

#include "ExportedByLatticeGMOperators.h"

#include "CATSysErrorDef.h"
#include "CATCGMScaleCategoryDef.h"

#include "CATVRepType.h"

#include "CATSetOfInt.h"

#include <list>

#include "CATIPolyMesh.h"
#include "LatticeGMOperators.h"
#include "LatticeFrameFields.h"

class LatticeNBModel;
class CATBody;
class CATFace;
class CATGeoFactory;
class CATPolyBody;
class CATMathTransformation;
class CATTopData;
class CATVolume;
class CATCGMProgressBar;
class CATWire;

namespace lattice
{
  namespace gm
  {
    namespace pb
    {
      /**
      * @brief Wrapper of lattice::gm::CreateUnionedBodyStitching to process
      * a partitioned body and process the arguments of lattice::gm::CreateUnionedBodyStitching
      * (which doesn't support partitioned body) based on the specified volume to
      * lattice.
      *
      * These wrappers are part of a contengency plan to satisfy lattice designer time
      * constraints. They will be deprecated as soon as CATTopOperators in GMScalarFieldsOperators
      * are ready to be used.
      *
      * What is done:
      * 1. Check there is only one neighbor volume to iVolume.
      * 2. Make a body out of that neighbor volume, and a body with volumes of initial body not in contact with iVolume.
      * 3. Process the body built from volumes in contact with iVolume with old API.
      * 4. Boolean union with body made of volumes not in contact with iVolume.
      * 5. Journal should report in order: creation of new face from all faces in cavity volume and
      *    deletion of 'outer' face (no other volume on the other side).
      *
      * Things worth to add:
      * - Support more than one volume sharing faces with iVolume
      *   (carefull, for specific configurations some partition can't be preserved).
      * - Instead of Boolean Union we should check if faces shared with other volumes
      *    are intact and if they are we should do CATIPGMTopToolsCreateDomains instead of boolean op.
      */
      HRESULT CreateUnionedBodyStitchingOnPartitions(
        CATCGMScaleCategory iScale, const LatticeNBModel& iLattice,
        CATBody& iBody, CATVolume& iVolumeToLattice,
        CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev,
        CATGeoFactory* iGeoFactory, CATBody*& oBody,
        CATTopData* iTopData = 0, unsigned int iNbThreads = 0, const lattice::gm::EStitchingMode iStichingMode = lattice::gm::EStitchingMode::Normal,
        CATCGMProgressBar * iPprogressLatticeNB = nullptr);
    }
  }
}

#endif
