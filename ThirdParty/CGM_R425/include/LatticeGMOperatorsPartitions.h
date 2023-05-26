#ifndef LatticeGMOperatorsPartitions_H
#define LatticeGMOperatorsPartitions_H

#include "CATCGMScaleCategoryDef.h"

#include "ExportedByLatticeGMOperators.h"

#include "CATSysErrorDef.h"
#include "CATCGMScaleCategoryDef.h"

#include "CATVRepType.h"

#include "CATSetOfInt.h"

#include <list>

#include "CATIPolyMesh.h"
#include "LatticeFrameFields.h"
#include "LatticeGMOperators.h"

class LatticeNBModel;
class CATBody;
class CATFace;
class CATGeoFactory;
class CATPolyBody;
class CATMathTransformation;
class CATTopData;
class CATVolume;
class CATWire;
class CATCGMProgressBar;

namespace lattice
{
    namespace gm
    {

      namespace pb
      {
      using namespace lattice::poly;

        /**
        * @brief See lattice::poly::CreateMesh
        */
        ExportedByLatticeGMOperators HRESULT CreateBody(
          CATCGMScaleCategory iScale, const LatticeNBModel& iLattice,
          CATBody& iBody, CATVolume* iVolumeToLattice,
          CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev,
          CATGeoFactory* iGeoFactory, CATBody*& oBody, CATTopData *ipTopData = 0,
          unsigned int iNbConnectedComponents = 1, unsigned int iNbThreads = 0,
          CATCGMProgressBar * iProgressLatticeNB = nullptr);

        /**
        * @brief See lattice::poly::CreateTrimmedMesh
        */
        ExportedByLatticeGMOperators HRESULT CreateTrimmedBody(
          CATCGMScaleCategory iScale, const LatticeNBModel& iLattice,
          CATBody& iBody, CATVolume* iVolumeToLattice,
          CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev,
          CATGeoFactory* iGeoFactory, CATBody*& oBody, CATTopData *ipTopData = 0,
          unsigned int iNbConnectedComponents = 1, unsigned int iNbThreads = 0,
          CATCGMProgressBar * iProgressLatticeNB = nullptr);

        /**
        * @brief Alternative of lattice::gm::pb::CreateTrimmedBody
        * with one lattice and several volumes
        */
        ExportedByLatticeGMOperators HRESULT CreateTrimmedBody(
          CATCGMScaleCategory iScale, const LatticeNBModel& iLattice,
          CATBody& iBody, CATListPV& iVolumesToLattice,
          CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev,
          CATGeoFactory* iGeoFactory, CATBody*& oBody, CATTopData *ipTopData = 0,
          unsigned int iNbConnectedComponents = 1, unsigned int iNbThreads = 0);

        /**
        * @brief Alternative of lattice::gm::pb::CreateTrimmedBody
        * with several lattices and volumes, one lattice per
        * volume. Lists of lattices and volumes are synchronized:
        * lattice i will be used for volume i.
        */
        ExportedByLatticeGMOperators HRESULT CreateTrimmedBody(
          CATCGMScaleCategory iScale, CATListPV& iLattices,
          CATBody& iBody, CATListPV& iVolumesToLattice,
          CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev,
          CATGeoFactory* iGeoFactory, CATBody*& oBody, CATTopData *ipTopData = 0,
          unsigned int iNbConnectedComponents = 1, unsigned int iNbThreads = 0);

        /**
        * @brief See lattice::poly::CreateUnionedMesh
        */
        ExportedByLatticeGMOperators HRESULT CreateUnionedBody(
          CATCGMScaleCategory iScale, const LatticeNBModel& iLattice,
          CATBody& iBody, CATVolume* iVolumeToLattice,
          CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev,
          CATGeoFactory* iGeoFactory, CATBody*& oBody, CATTopData *ipTopData = 0,
          unsigned int iNbConnectedComponents = 1, unsigned int iNbThreads = 0,
          CATCGMProgressBar * iProgressLatticeNB = nullptr);

        /**
        * @brief Alternative to lattice::gm::pb::CreateUnionedBody
        * with one lattice and several volumes
        */
        ExportedByLatticeGMOperators HRESULT CreateUnionedBody(
          CATCGMScaleCategory iScale, const LatticeNBModel& iLattice,
          CATBody& iBody, CATListPV& iVolumesToLattice,
          CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev,
          CATGeoFactory* iGeoFactory, CATBody*& oBody, CATTopData *ipTopData = 0,
          unsigned int iNbConnectedComponents = 1, unsigned int iNbThreads = 0);

        /**
        * @brief Alternative to lattice::gm::pb::CreateUnionedBody
        * with several lattices and volumes, one lattice per
        * volume. Lists of lattices and volumes are synchronized:
        * lattice i will be used for volume i.
        */
        ExportedByLatticeGMOperators HRESULT CreateUnionedBody(
          CATCGMScaleCategory iScale, CATListPV& iLattices,
          CATBody& iBody, CATListPV& iVolumesToLattice,
          CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev,
          CATGeoFactory* iGeoFactory, CATBody*& oBody, CATTopData *ipTopData = 0,
          unsigned int iNbConnectedComponents = 1, unsigned int iNbThreads = 0);

        /**
        * @brief
        */
        ExportedByLatticeGMOperators HRESULT CreateUnionedBodyStitching(
          CATCGMScaleCategory iScale, const LatticeNBModel& iLattice,
          CATBody& iBody, CATVolume& iVolumeToLattice,
          CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev,
          CATGeoFactory* iGeoFactory, CATBody*& oBody,
          CATTopData* iTopData = 0, unsigned int iNbThreads = 0, const lattice::gm::EStitchingMode iStitchingMode = lattice::gm::EStitchingMode::Normal,
          CATCGMProgressBar * iProgressLatticeNB = nullptr);

        /**
        * @brief Generates an conformal lattice (oLattice) from a surface geometry given by iBody, consisting of bars with given average bar length iBarLength and a radius iBarRadius.
        */
        ExportedByLatticeGMOperators HRESULT CreateConformalLatticeFromBody(
          CATCGMScaleCategory iScale,
          CATBody& iBody, CATVolume& iVolumeToLattice,
          CATGeoFactory* iGeoFactory, CATTopData* iTopData,
           const double iBarLength, const double iBarRadius, LatticeNBModel*& oLattice);

        /**
        * @brief Interface for creating a conformal lattice (with average length iBarLength and radius iBarRadius) inside a cavity defined by iContactFaces,
        * inside a body iUnionBody. Lattice will be stitched to the original body generating a new body (oBody).
        * Notice that this operator works only for a closed cavity (defined by the ContactFaces) inside a CATBody (UnionBody) where the complement of ContactFaces is not empty.
        */
        ExportedByLatticeGMOperators HRESULT CreateUnionedBodyStitchingConformal(
          CATCGMScaleCategory iScale,
          CATBody& iUnionBody, CATVolume& iVolume,
          CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev,
          CATGeoFactory* iGeoFactory, CATBody*& oBody,
          const double iBarLength, const double iBarRadius,
          CATTopData* iTopData = 0, unsigned int iNbThreads = 0);

        /**
        * @brief Interface to obtaint the ist of faces from a iBody, that are in clash with a given Lattice (iLattice).
        */
        ExportedByLatticeGMOperators HRESULT GetListOfFacesInClash(
          CATGeoFactory * iFactory, CATTopData * iTopData,
          CATCGMScaleCategory iScale, const LatticeNBModel& iLattice,
          CATBody& iBody, CATVolume& iVolume, std::list<CATFace*>& ioClashFaces);

        /**
        * @brief Interface to obtain the list of faces from several volumes in a iBody, that are in clash with a given Lattice (iLattice).
        */
        ExportedByLatticeGMOperators HRESULT GetListOfFacesInClash(
          CATGeoFactory * iFactory, CATTopData * iTopData,
          CATCGMScaleCategory iScale, const LatticeNBModel& iLattice,
          CATBody& iBody, CATListPV& iVolumes, std::list<CATFace*>& ioClashFaces);

        /**
        * @brief Interface to obtain the list of faces from several
        * volumes in a iBody, that are in clash with a given Lattice
        * (in iLattices). Lists of lattices and volumes are synchronized:
        * lattice i will be used for volume i.
        */
        ExportedByLatticeGMOperators HRESULT GetListOfFacesInClash(
          CATGeoFactory * iFactory, CATTopData * iTopData,
          CATCGMScaleCategory iScale, CATListPV& iLattices,
          CATBody& iBody, CATListPV& iVolumes, std::list<CATFace*>& ioClashFaces);

        /**
        * @brief See lattice::poly::CreateTrimmedBarGraph
        */
        ExportedByLatticeGMOperators HRESULT CreateTrimmedBarGraph(
          const LatticeNBModel& iLattice,
          CATBody& iShell, CATVolume& iVolume,
          LatticeNBModel*& oTrimmedLattice, CATTopData& ipTopData);

        /**
        * @brief See lattice::poly::CreateTrimmedBarGraph. Alternative
        * with a list of volumes.
        */
        ExportedByLatticeGMOperators HRESULT CreateTrimmedBarGraph(
          const LatticeNBModel& iLattice,
          CATBody& iShell, CATListPV& iVolumes,
          LatticeNBModel*& oTrimmedLattice, CATTopData& ipTopData);

        /**
        * @brief See lattice::poly::CreateTrimmedBarGraph. Alternative
        * with two synchronized lists of lattices and volumes. The out
        * list of Lattice results (oTrimmedLattices) should be given
        * empty.
        */
        ExportedByLatticeGMOperators HRESULT CreateTrimmedBarGraph(
          CATListPV& iLattices,
          CATBody& iShell, CATListPV& iVolumes,
          CATListPV& oTrimmedLattices, CATTopData& ipTopData);

        /**
        * @brief See lattice::poly::ClampBarGraphAgainstCavity
        */
        ExportedByLatticeGMOperators HRESULT ClampBarGraphAgainstCavity(
          const LatticeNBModel& iLattice, CATBody& iBody, CATVolume& iVolume,
          LatticeNBModel*& oClampedLattice, CATTopData* ipTopData = nullptr);

        /**
        * @brief See lattice::poly::ClampBarGraphAgainstCavity.
        * Alternative with a list of volumes.
        */
        ExportedByLatticeGMOperators HRESULT ClampBarGraphAgainstCavity(
          const LatticeNBModel& iLattice, CATBody& iBody, CATListPV& iVolumes,
          LatticeNBModel*& oClampedLattice, CATTopData* ipTopData = nullptr);

        /**
        * @brief See lattice::poly::ClampBarGraphAgainstCavity.
        * Alternative with two synchronized lists of lattices and
        * volumes. The out list of Lattice results (oClampedLattices)
        * should be given empty.
        */
        ExportedByLatticeGMOperators HRESULT ClampBarGraphAgainstCavity(
          CATListPV& iLattices, CATBody& iBody, CATListPV& iVolumes,
          CATListPV& oClampedLattices, CATTopData* ipTopData = nullptr);

        /**
        * @brief See lattice::poly::RemoveSingleBeamsBarGraph
        */
        ExportedByLatticeGMOperators HRESULT RemoveSingleBeamsBarGraph(
          const LatticeNBModel& iLattice, CATBody &iBody, CATVolume& iVolume,
          LatticeNBModel*& oCleanLattice, CATTopData& iTopData);

        /**
        * @brief See lattice::poly::RemoveNodesOfDegreeTwo
        */
        ExportedByLatticeGMOperators HRESULT RemoveNodesOfDegreeTwo(
          const LatticeNBModel& iLattice, CATBody* iBody, CATVolume& iVolume,
          LatticeNBModel*& oCleanLattice, CATTopData& iTopData);

        /**
        * @brief See lattice::poly::RetrieveContactNodesAndBeams
        */
        ExportedByLatticeGMOperators HRESULT RetrieveContactNodesAndBeams(
          const LatticeNBModel& iLattice, CATBody& iBody, CATVolume& iVolume,
          CATSetOfInt& oContactNodes, CATSetOfInt& oContactBeams, CATTopData& iTopData);

        /**
        * @brief Alternative with a list of Volumes. See lattice::poly::RetrieveContactNodesAndBeams
        */
        ExportedByLatticeGMOperators HRESULT RetrieveContactNodesAndBeams(
          const LatticeNBModel& iLattice, CATBody& iBody, CATListPV& iVolumes,
          CATSetOfInt& oContactNodes, CATSetOfInt& oContactBeams, CATTopData& iTopData);

        /**
        * @brief See lattice::poly::ExportINP
        */
        ExportedByLatticeGMOperators HRESULT ExportINP(
          const LatticeNBModel& iLattice, CATBody& iBody, CATVolume& iVolume,
          const char* iFilePath, CATTopData& iTopData);

      }
    }
}

#endif
