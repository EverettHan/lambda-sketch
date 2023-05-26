#ifndef LatticeGMOperators_H
#define LatticeGMOperators_H

#include "CATCGMScaleCategoryDef.h"

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
class CATCGMProgressBar;
class CATWire;

namespace lattice
{
    namespace gm
    {
      enum class EStitchingMode { Normal, Strict, StrictWithEarlyCheckFaces };

      using namespace lattice::poly;

        /**
        * @brief See lattice::poly::CreateMesh
        */
        ExportedByLatticeGMOperators HRESULT CreateBody(CATCGMScaleCategory iScale, const LatticeNBModel& iLattice, CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev, CATGeoFactory* iGeoFactory, CATBody*& oBody, CATTopData *ipTopData = 0, unsigned int iNbConnectedComponents = 1, unsigned int iNbThreads = 0, CATCGMProgressBar * iProgressLatticeNB = nullptr);

        /**
        * @brief See lattice::poly::CreateTrimmedMesh
        */
        ExportedByLatticeGMOperators HRESULT CreateTrimmedBody(CATCGMScaleCategory iScale, const LatticeNBModel& iLattice, CATBody& iShell, const CATMathTransformation* iTShell, CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev, CATGeoFactory* iGeoFactory, CATBody*& oBody, CATTopData *ipTopData = 0, unsigned int iNbConnectedComponents = 1, unsigned int iNbThreads = 0, CATCGMProgressBar * iProgressLatticeNB = nullptr);

        /**
        * @brief See lattice::poly::CreateUnionedMesh
        */
        ExportedByLatticeGMOperators HRESULT CreateUnionedBody(CATCGMScaleCategory iScale, const LatticeNBModel& iLattice, CATBody& iShell, const CATMathTransformation* iTShell, CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev, CATGeoFactory* iGeoFactory, CATBody*& oBody, CATTopData *ipTopData = 0, unsigned int iNbConnectedComponents = 1, unsigned int iNbThreads = 0, CATCGMProgressBar * iProgressLatticeNB = nullptr);

        /**
        * @brief
        */
      ExportedByLatticeGMOperators HRESULT CreateUnionedBodyStitching(
        CATCGMScaleCategory iScale, const LatticeNBModel& iLattice, CATBody& iUnionBody, const CATMathTransformation* iTUnionBody,
        CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev,
        CATGeoFactory* iGeoFactory, CATBody*& oBody,
        const std::list<CATFace*> *iStitchingFaces = 0, CATTopData* iTopData = 0,
        unsigned int iNbThreads = 0, const EStitchingMode iStitchingMode = EStitchingMode::Normal, CATCGMProgressBar * iProgressLatticeNB = nullptr);

        /**
        * @brief
        */
        ExportedByLatticeGMOperators HRESULT CreateUnionedBodyStitchingWithExtendedFaces(CATCGMScaleCategory iScale, const LatticeNBModel& iLattice, CATBody& iUnionBody, const CATMathTransformation* iTUnionBody, CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev, CATGeoFactory* iGeoFactory, CATBody*& oBody, const std::list<CATFace*> *iStitchingFaces = 0, CATTopData* iTopData = 0, unsigned int iNbThreads = 0, CATCGMProgressBar * iProgressLatticeNB = nullptr);

        /**
        * @brief
        */
        ExportedByLatticeGMOperators HRESULT CreateUnionedBodyStitchingStrict(
          CATCGMScaleCategory iScale, const LatticeNBModel& iLattice, CATBody& iUnionBody, const CATMathTransformation* iTUnionBody,
          CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev,
          CATGeoFactory* iGeoFactory, CATBody*& oBody,
          const std::list<CATFace*> *iStitchingFaces = 0, CATTopData* iTopData = 0,
          unsigned int iNbThreads = 0, const EStitchingMode iStitchingMode = EStitchingMode::Normal,
          CATCGMProgressBar * iProgressLatticeNB = nullptr);

        /**
        * @brief Generates an conformal lattice (oLattice) from a surface geometry given by iBody, consisting of bars with given average bar length iBarLength and a radius iBarRadius.
        */
      ExportedByLatticeGMOperators HRESULT CreateConformalLatticeFromBody(CATCGMScaleCategory iScale, CATBody& iBody, const CATMathTransformation* iTBody, CATGeoFactory* iGeoFactory, CATTopData* iTopData, const double iBarLength, const double iBarRadius, LatticeNBModel*& oLattice,
                                                                          const int nbIterations_gauss_seidel = 0,
                                                                          const int nbIterations_jacobi = 1000,
                                                                          const double density_cutoff = 0.0);

        /**
        * @brief Interface for creating a conformal lattice (with average length iBarLength and radius iBarRadius) inside a cavity defined by iContactFaces, inside a body iUnionBody. Lattice will be stitched to the original body generating a new body (oBody).
        * Notice that this operator works only for a closed cavity (defined by the ContactFaces) inside a CATBody (UnionBody) where the complement of ContactFaces is not empty.
        */
        ExportedByLatticeGMOperators HRESULT CreateUnionedBodyStitchingConformal(
          CATCGMScaleCategory iScale, CATBody& iUnionBody, const CATMathTransformation* iTUnionBody,
          CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl,
          const double iChordalDev, CATGeoFactory* iGeoFactory, CATBody*& oBody,
          const std::list<CATFace*>& iContactFaces,
          const double iBarLength, const double iBarRadius,
          CATTopData* iTopData = 0, unsigned int iNbThreads = 0);

        /**
        * @brief Interface to obtaint the ist of faces from a iBody, that are in clash with a given Lattice (iLattice).
        */
        ExportedByLatticeGMOperators HRESULT GetListOfFacesInClash(
          CATGeoFactory * iFactory, CATTopData * iTopData, CATCGMScaleCategory iScale, const LatticeNBModel& iLattice, CATBody& iBody, const CATMathTransformation* iTBody, std::list<CATFace*>& ioClashFaces);

        /**
        * @brief
        */
        ExportedByLatticeGMOperators HRESULT CreateUnionedBodyStitchingFromScalarField(CATCGMScaleCategory iScale, const LatticeNBModel& iLattice, CATBody& iUnionBody, const CATMathTransformation* iTUnionBody, CATVRepType::SmoothingMode iSmoothingMode, float iSmoothingAmpl, const double iChordalDev, CATGeoFactory* iGeoFactory, CATBody*& oBody, const std::list<CATFace*>* iStitchingFaces, CATTopData* iTopData, unsigned int iNbThreads);

        /**
        * @brief See lattice::poly::CreateTrimmedBarGraph
        */
        ExportedByLatticeGMOperators HRESULT CreateTrimmedBarGraph(
          const LatticeNBModel& iLattice,
          CATBody& iShell, const CATMathTransformation* iTShell,
          const std::list<CATFace*>& iOpenFaces, LatticeNBModel*& oTrimmedLattice, CATTopData* ipTopData = nullptr);

        /**
        * @brief DEPRECATED, use ClampBarGraphAgainstCavity instead - See lattice::poly::ClampBarGraphInVolume
        */
        ExportedByLatticeGMOperators HRESULT ClampBarGraphInVolume(
          const LatticeNBModel& iLattice,
          CATBody& iCavity, const CATMathTransformation* iTCavity,
          CATBody &iVolume, const std::list<CATFace*>& iVolumeOuterFaces, CATMathTransformation* iTVolume,
          LatticeNBModel*& oClampedLattice);

        /**
        * @brief See lattice::poly::ClampBarGraphAgainstCavity
        */
        ExportedByLatticeGMOperators HRESULT ClampBarGraphAgainstCavity(
          const LatticeNBModel& iLattice,
          CATBody& iCavity, const CATMathTransformation* iTCavity,
          LatticeNBModel*& oClampedLattice, CATTopData* ipTopData = nullptr);

        /**
        * @brief See lattice::poly::RemoveSingleBeamsBarGraph
        */
        ExportedByLatticeGMOperators HRESULT RemoveSingleBeamsBarGraph(
          const LatticeNBModel& iLattice,
          CATBody &iVolume, const std::list<CATFace*>& iCavityFaces, const CATMathTransformation* iTCavityFaces,
          LatticeNBModel*& oCleanLattice);

        /**
        * @brief See lattice::poly::RemoveNodesOfDegreeTwo
        */
        ExportedByLatticeGMOperators HRESULT RemoveNodesOfDegreeTwo(
          const LatticeNBModel& iLattice,
          CATBody* iBody, const CATMathTransformation* iTBody,
          LatticeNBModel*& oCleanLattice);

        /**
        * @brief See lattice::poly::RetrieveContactNodesAndBeams
        */
        ExportedByLatticeGMOperators HRESULT RetrieveContactNodesAndBeams(
          const LatticeNBModel& iLattice,
          CATBody& iBody, const CATMathTransformation* iTBody,
          CATSetOfInt& oContactNodes, CATSetOfInt& oContactBeams );

        /**
        * @brief See lattice::poly::ExportINP
        */
        ExportedByLatticeGMOperators HRESULT ExportINP(
          const LatticeNBModel& iLattice,
          CATBody& iBody, const CATMathTransformation* iTBody,
          const char* iFilePath);
    }
}

#endif
