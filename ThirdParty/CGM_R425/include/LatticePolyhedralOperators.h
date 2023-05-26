#ifndef LatticePolyhedralOperators_H
#define LatticePolyhedralOperators_H

#include "ExportedByLatticePolyOperators.h"
#include "CATVRepType.h"

#include "CATSysErrorDef.h"
#include "CATCGMScaleCategoryDef.h"

#include "CATPolyBody.h"
#include "CATMathTransformation.h"

#include "CATSetOfInt.h"

#include <list>

class LatticeNBModel;
class CATIPolyMesh;
class CATMapOfPtrToPtr;
class CATCGMProgressBar;

enum class clampModeOption {
  BARGRAPHONLYMODE,
  FULLVOLUMEMODE
};

namespace lattice
{
  namespace poly
  {
    /**
    * @brief CreateMesh
    *
    * @param iScale
    * @param iLattice
    * @param iSmoothingMode
    * @param iSmoothingAmpl
    * @param iChordalDev
    * @param oMesh
    *
    */
    ExportedByLatticePolyOperators HRESULT CreateMesh(CATCGMScaleCategory iScale, const LatticeNBModel& iLattice, CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev, CATIPolyMesh*& oMesh, unsigned int iNbConnectedComponents = 1, unsigned int iNbThreads = 0, CATCGMProgressBar * iProgressLatticeNB = nullptr);

    /**
    * @brief CreateTrimmedMesh
    *
    * @param iScale
    * @param iLattice
    * @param iShell
    * @param iSmoothingMode
    * @param iSmoothingAmpl
    * @param iChordalDev
    * @param oMesh
    *
    */
    ExportedByLatticePolyOperators HRESULT CreateTrimmedMesh(CATCGMScaleCategory iScale, const LatticeNBModel& iLattice, const CATIPolyMesh& iShell, CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev, CATIPolyMesh*& oMesh, bool iTrimBarGraph = false, unsigned int iNbConnectedComponents = 1, unsigned int iNbThreads = 0, CATCGMProgressBar * iProgressLatticeNB = nullptr);

    /**
    * @brief CreateUnionedMesh
    *
    * @param iScale
    * @param iLattice
    * @param iUnionMesh
    * @param iSmoothingMode
    * @param iSmoothingAmpl
    * @param iChordalDev
    * @param oMesh
    *
    */
    ExportedByLatticePolyOperators HRESULT CreateUnionedMesh(CATCGMScaleCategory iScale, const LatticeNBModel& iLattice, const CATIPolyMesh& iUnionMesh, CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev, CATIPolyMesh*& oMesh, bool iTrimBarGraph = false, unsigned int iNbConnectedComponents = 1, unsigned int iNbThreads = 0, CATCGMProgressBar * iProgressLatticeNB = nullptr);

    /**
    * @brief
    */
    ExportedByLatticePolyOperators HRESULT CreateUnionedSurfacicMesh(CATCGMScaleCategory iScale, const LatticeNBModel& iLattice, const CATIPolyMesh& iUnionMesh, CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev, int iNbOfBorders, double iMaxVoxelSize, double &oVoxelSize, CATIPolyMesh*& oMesh, unsigned int iNbThreads = 0, CATCGMProgressBar * iProgressLatticeNB = nullptr);

    /**
    * @brief CreateUnionedLatticeStitchingPolybody
    *
    * @param iScale
    * @param iLattice
    * @param iUnionBody
    * @param iUnionBodyPosition
    * @param iSmoothingMode
    * @param iSmoothingAmpl
    * @param iChordalDev
    * @param oBody
    * @param oDebugBodyNoInfluencedFaces
    * @param oDebugMesh
    * @param iCheckPolyBody
    *
    */
    ExportedByLatticePolyOperators HRESULT CreateUnionedLatticeStitchingPolybody(CATCGMScaleCategory iScale, const LatticeNBModel& iLattice, const CATPolyBody& iUnionBody, const CATMathTransformation* iUnionBodyPosition, CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev, CATPolyBody*& oBody, CATMapOfPtrToPtr* oMapInputToOutputCells, CATPolyBody*& oDebugBodyNoInfluencedFaces, CATIPolyMesh*& oDebugMesh, bool iCheckPolyBody = false, unsigned int iNbThreads = 0);

    /**
    * @brief CreateFromMesh
    *
    * @param iScale
    * @param iMesh
    * @param oLattice
    *
    */
    ExportedByLatticePolyOperators HRESULT CreateFromMesh(CATCGMScaleCategory iScale, const CATIPolyMesh& iMesh, LatticeNBModel& oLattice);

    /**
    * @brief
    *
    */
    ExportedByLatticePolyOperators HRESULT CreateFoamFromMesh(const CATIPolyMesh& iMesh, unsigned int iTesselation, unsigned int iDistribution, unsigned int iNbPoints, double iRadius, LatticeNBModel*& oLattice);

    /**
    * @brief Trims the input lattice bar graph inside a body resulting from the closing of an open cavity.
    *
    * @param iLattice Input lattice model
    * @param iShell The body representing the *closed* cavity
    * @param iTShell
    * @param iOpenFaces A list of pointers to the faces that result from the closing of the cavity
    * @param oTrimmedLattice Output lattice model
    */
    ExportedByLatticePolyOperators HRESULT CreateTrimmedBarGraph(const LatticeNBModel& iLattice, const CATPolyBody &iShell, const CATMathTransformation* iTShell, const std::list<CATPolyFace*>& iOpenFaces, LatticeNBModel*& oTrimmedLattice, bool iInvertTrim = false, clampModeOption iClampMode = clampModeOption::FULLVOLUMEMODE);


    /**
    * DEPRECATED, use ClampBarGraphAgainstCavity instead
    * @brief  Clamps the beams inside a polybody. The beams that cross the volume are shortened so as to be inside of it without altering the geometry of the lattice inside the cavity.
    *
    * @param iLattice Input lattice model. The model has to be trimmed using CreateTrimmedBarGraph.
    * @param iCavity The body representing the *closed* cavity.
    * @param iVolumeOuterFaces The faces of the *volume* that do *not* belong to the cavity
    * @param iTVolume

    * @param oClampedLattice Output lattice model
    */
    ExportedByLatticePolyOperators HRESULT ClampBarGraphInVolume(const LatticeNBModel& iLattice, const CATPolyBody &iCavity, const CATMathTransformation* iTCavity, const std::list<CATPolyFace*>& iVolumeOuterFaces, CATMathTransformation* iTVolume, LatticeNBModel*& oClampedLattice);

    /**
    * @brief Clamps the beams against a cavity. The beams that cross the cavity are shortened so as to be as close to it as possible.
    *
    * @param iLattice Input lattice model. The model has to be trimmed using CreateTrimmedBarGraph.
    * @param iCavity The body representing the *closed* cavity.
    *
    * @param oClampedLattice Output lattice model
    *
    * @param iClampMode used for switching clash operator mode
    */
    ExportedByLatticePolyOperators HRESULT ClampBarGraphAgainstCavity(const LatticeNBModel& iLattice, const CATPolyBody &iCavity, const CATMathTransformation* iTCavity, CATCGMScaleCategory iScale, LatticeNBModel*& oClampedLattice);
    ExportedByLatticePolyOperators HRESULT ClampBarGraphAgainstCavity(const LatticeNBModel& iLattice, const CATPolyBody &iCavity, const CATMathTransformation* iTCavity, LatticeNBModel*& oClampedLattice, clampModeOption iClampMode = clampModeOption::FULLVOLUMEMODE);

    /**
    * @brief Removes isolated beams from a lattice bar graph, i.e. the beams that are connected to 0 or 1 adjacent beams. The isolated beams that intersect the faces of the cavity are kept, since they will be useful for the VRep union.
    *
    * @param iLattice Input lattice model
    * @param iCavityFaces The faces of the *open* cavity (part of the volume).
    * @param iTCavityFaces
    * @param oCleanLattice Output lattice model
    */
    ExportedByLatticePolyOperators HRESULT RemoveSingleBeamsBarGraph(const LatticeNBModel& iLattice, const std::list<CATPolyFace*>& iCavityFaces, const CATMathTransformation* iTCavityFaces, LatticeNBModel*& oCleanLattice);

    /**
    * @brief Removes nodes of adjacency 2 unless they intersect the input volume
    *
    * @param iLattice Input lattice model
    * @param iBody The input volume
    * @param iTBody
    * @param oCleanLattice Output lattice model
    */
    ExportedByLatticePolyOperators HRESULT RemoveNodesOfDegreeTwo(const LatticeNBModel& iLattice, const CATPolyBody* iBody, const CATMathTransformation* iTBody, LatticeNBModel*& oCleanLattice);

    /**
    * @brief Returns an estimate of the volume of the lattice.
    * You should only use this if you want a fast estimate. Computing the volume of the resulting mesh is mush more reliable, though costlier.
    *
    * @param iLattice Input lattice model
    * @return the estimate of the volume. Typically within a 20% range of the volume of the generated mesh.
    */
    ExportedByLatticePolyOperators double GetVolumeEstimate(const LatticeNBModel& iLattice);

    /**
    * @brief Retrieves the nodes and the beams in contact with the input body
    *
    * @param iLattice Input Lattice model
    * @param iBody Input polybody
    * @param iTBody
    * @param oContactNodes Lists of indices of contact nodes
    * @param oContactBeams Lists of indices of contact beams
    */
    ExportedByLatticePolyOperators HRESULT RetrieveContactNodesAndBeams( const LatticeNBModel& iLattice, const CATPolyBody& iBody, const CATMathTransformation* iTBody, CATSetOfInt& oContactNodes, CATSetOfInt& oContactBeams );

    /**
    * @brief Exports an object of type LatticeNBModel to an abacus simulation input file. Flags the beams ans nodes that intersect a body. Graph simplification/trimming/clamping should all be carried out prior to calling ExportINP. See also lattice::ExportINP and lattice::gm::ExportINP.
    *
    * @param iLattice Input lattice model
    * @param iBody Body the lattice structure is attached to
    * @param iTBody Body position
    * @param iFilePath Output file path
    */
    ExportedByLatticePolyOperators HRESULT ExportINP(const LatticeNBModel& iLattice, const CATPolyBody& iBody, const CATMathTransformation* iTBody, const char* iFilePath);
  }
}

#endif
