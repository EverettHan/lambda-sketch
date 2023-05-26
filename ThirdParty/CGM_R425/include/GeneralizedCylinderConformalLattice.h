#pragma once

#ifndef GeneralizedCylinderConformalLattice_H
#define GeneralizedCylinderConformalLattice_H

#include "ExportedByLatticeGMOperators.h"

// CGM 
#include "CATGeoFactory.h"
#include "CATTopData.h"

// Lattice
#include "LatticeNBModel.h"
#include "LatticePatternNBModel.h"

// Standard lib
#include <vector>
#include <array>
#include <list>

class CATWire;
class CATBody;
class CATFace;
class CATEdge;

namespace lattice
{
  namespace gm {
    /**
    * @brief Generates a Generalized Cylinder (represented by a set of Cross Sections with their respective Guiders) from a CATFace (iSupportFace) and following a direction (iOffsetDirection) along an offset distance (iOffset)
    */    
    ExportedByLatticeGMOperators HRESULT CreateGeneralyzedCylinderFromSurface(CATGeoFactory* iFactory, CATTopData* iTopData, CATFace* iSupportFace, CATEdge* iStartSupportEdge, CATEdge* iEndSupportEdge, int iNbCrossSection, CATMathVector& iOffsetDirection, double iOffset, std::vector<std::vector<CATWire*>>& oProfiles);
    /**
    * @brief Generates a Generalized Cylinder (represented by a set of Cross Sections with their respective Guiders) between two CATFace's (iSupportFace and iGuideFace)
    */
    ExportedByLatticeGMOperators HRESULT CreateGeneralyzedCylinderBetweenSurfaces(CATGeoFactory* iFactory, CATTopData* iTopData, CATFace* iSupportFace, CATEdge* iStartSupportEdge, CATEdge* iEndSupportEdge, CATFace* iGuideFace, CATEdge* iStartGuideEdge, CATEdge* iEndGuideEdge, int& iNbCrossSection, std::vector<std::vector<CATWire*>>& oProfiles);

    ExportedByLatticeGMOperators HRESULT GetGeneralyzedCylinderDimensions(CATGeoFactory* iGeoFactory, CATTopData* iTopData, std::vector<std::vector<CATWire*>>& iCrossSections, double& oGCLength, double& oGCWidth, double& oGCHeight);

    /**
    * @brief Writes a *.GC4L file to contain a generalyzed cylinder defined by iProfiles
    */
    ExportedByLatticeGMOperators void StreamGC4L(std::ostream& oStream, const int iNbCrossSection, const int iNbSlicesPerCrossSection, CATGeoFactory* iFactory, CATTopData* iTopData, std::list<CATWire*>& iProfiles);
    /**
    * @brief Retrieves a list of CATWire* from a GC4L file containing a generalyzed cylinder
    */
    ExportedByLatticeGMOperators void StreamGC4L(std::istream& iStream, int& oNbCrossSection, int& oNbGuidersPerCrossSection, CATGeoFactory* iFactory, CATTopData* iTopData, std::list<CATWire*>& oProfiles);
    /**
    * @brief Retrieves a vector of cross sections containing CATWire* from a GC4L file containing a generalyzed cylinder
    */
    ExportedByLatticeGMOperators void StreamGC4L(std::istream& iStream, int& oNbCrossSection, CATGeoFactory* iFactory, CATTopData* iTopData, std::vector<std::vector<CATWire*>>& oProfiles);
    /**
    * @brief Deforms a lattice (iLattice) to adapt its shape to a cylindrical like shape defined by its cross sections (iProfiles). Each cross section is defined by iNbSlicesPerCrossSection slices (CATWires). Result bargraph is stored in oLattice.
    */
    ExportedByLatticeGMOperators HRESULT CreateConformalLatticeFromGeneralizedCylinder(const LatticeNBModel& iLattice, const int idimX, const int idimY, const int idimZ, CATGeoFactory* iGeoFactory, CATTopData* iTopData, std::list<CATWire*>& iProfiles, const int iNbSlicesPerCrossSection, LatticeNBModel*& oLattice);
    /**
    * @brief Deforms a lattice (iLattice) to adapt its shape to a cylindrical like shape defined by its cross sections (iProfiles). Each cross section is defined by slices (CATWires). Result bargraph is stored in oLattice.
    */
    ExportedByLatticeGMOperators HRESULT CreateConformalLatticeFromGeneralizedCylinder(const LatticeNBModel& iLattice, const int idimX, const int idimY, const int idimZ, CATGeoFactory* iGeoFactory, CATTopData* iTopData, std::vector<std::vector<CATWire*>>& iProfiles, LatticeNBModel*& oLattice);
    /**
    * @brief Creates a pattern (ipattern) based lattice (oLattice) adapted to a cylindrical like shape defined by its cross sections (iProfiles). Each cross section is defined by slices (CATWires). Result bargraph is stored in oLattice.
    */
    ExportedByLatticeGMOperators HRESULT CreateConformalLatticeFromGeneralizedCylinderAndPattern(const LatticeNBModel& iPattern, const int idimX, const int idimY, const int idimZ, CATGeoFactory* iGeoFactory, CATTopData* iTopData, std::vector<std::vector<CATWire*>>& iProfiles, LatticeNBModel*& oLattice);

    ExportedByLatticeGMOperators HRESULT CreateConformalLatticeFromGeneralizedCylinderAndPattern(const LatticeNBModel& iPattern, const double iBarRadius, const int idimX, const int idimY, const int idimZ, CATGeoFactory* iGeoFactory, CATTopData* iTopData, std::vector<std::vector<CATWire*>>& iProfiles, LatticeNBModel*& oLattice);
        
  }
}

#endif

