#ifndef LatticeOperators_H
#define LatticeOperators_H

#include "ExportedByLatticeOperators.h"

class LatticeNBModel;
class CATSetOfInt;

#include "CATErrorDef.h"
#include <iosfwd>

namespace lattice
{
    ExportedByLatticeOperators void Randomize( LatticeNBModel& oLattice );

    ExportedByLatticeOperators void Filter( LatticeNBModel& oLattice );

    ExportedByLatticeOperators void Stream( std::ostream& oStream, const LatticeNBModel& iLattice );

    ExportedByLatticeOperators void Stream( std::istream& iStream, LatticeNBModel& oLattice );
    
    ExportedByLatticeOperators void StreamO3P( std::ostream& oStream, const LatticeNBModel& iLattice );

    ExportedByLatticeOperators void StreamO3P( std::istream& iStream, LatticeNBModel& oLattice, double iScale = 1.0, double iClamp = 0.0 );

    /**
    * @brief This method is deprecated, use ExportINP(const LatticeNBModel&, const char*, CATSetOfInt*, CATSetOfInt*) instead!
    */
    ExportedByLatticeOperators HRESULT ExportINP( const LatticeNBModel& iLattice, const char* iFilePath, bool *iContactNodes, bool *iContactBeams );

    /**
    * @brief Exports an object of type LatticeNBModel to an abacus simulation input file. See also lattice::poly::ExportINP and lattice::gm::ExportINP.
    *
    * @param iLattice Input lattice model
    * @param iFilePath Output file path
    * @param iContactNodes Nodes that have been flagged as contact nodes (if any)
    * @param iContactBeams Beams that have been flagged as contact beams (if any)
    */
    ExportedByLatticeOperators HRESULT ExportINP( const LatticeNBModel& iLattice, const char* iFilePath, CATSetOfInt *iContactNodes = 0, CATSetOfInt *iContactBeams = 0 );

    /* These functions are dirty, risky and costly. Graph simplification should be carried out AS SOON AS the pattern is generated. 
       This set of functions allows for simplifying a non-connex bargraph pattern. ***Calling 'SimplifyBarGraph' only should do the job***, 
       but the subfunctions have been exposed in order to give finer control if necessary. Keep in mind some (really dirty) patterns
       cannot be simplified using these functions. */

    /**
    * @brief Attemps to simplify a lattice by merging close beams and nodes and by solving intersections between beams.
    *
    * @param iLattice Input lattice model
    * @param oLattice Simplified lattice model
    */
    ExportedByLatticeOperators HRESULT SimplifyBarGraph(const LatticeNBModel& iLattice, LatticeNBModel*& oLattice);

    /**
    * @brief Merges nodes that are closer than iEps to each other. This function should only be called if SimplifyBarGraph failed.
    *
    * @param iLattice Input lattice model
    * @param iEps Minimum distance between two nodes
    * @param oLattice Connected lattice model
    */
    ExportedByLatticeOperators HRESULT ConnectGraph(const LatticeNBModel& iLattice, double iEps, LatticeNBModel*& oLattice);

    /**
    * @brief Breaks input bar graph into elementary beams (i.e. beams which do not intersect any other beam). This function should only be called if SimplifyBarGraph failed.
    *
    * @param iLattice Input lattice model
    * @param iEps Minimum distance between two bars
    * @param oLattice A lattice without intersecting beams. The output lattice is entirely disconnected: it contains as many connected components as beams.
    */
    ExportedByLatticeOperators HRESULT ComputeBarGraphIntersections(const LatticeNBModel& iLattice, double iEps, LatticeNBModel*& oLattice);

    /**
    * @brief Merges nodes that are exactly equal. This function is much faster than ConnectGraph (O(n.log) n vs O(n^2))
    *
    * @param iLattice Input lattice model
    * @param oLattice Connected lattice model
    */
    ExportedByLatticeOperators HRESULT MergeDuplicateNodes(const LatticeNBModel& iLattice, LatticeNBModel*& oLattice);
}

#endif
