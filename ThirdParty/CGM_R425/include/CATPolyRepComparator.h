// COPYRIGHT DASSAULT SYSTEMES 2020, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyRepComparator.h
//
//===================================================================
// January 2020  Creation JXO
//===================================================================
#ifndef CATPolyRepComparator_H
#define CATPolyRepComparator_H

#include "PolyVisuBoolOper.h"

// System
#include "CATErrorDef.h"

class CATRep;
class CATCGMOutput;
class CATMathBox;
class CATTolerance;

namespace {
class CATPolyBodyIteratorBaseComparator;
}

enum RepComparatorMode : unsigned int {
  REP_COMPARATOR_CGMID                = 0x01,
  REP_COMPARATOR_BOUNDING_BOX         = 0x02,
  REP_COMPARATOR_NB_FACET             = 0x04,
  REP_COMPARATOR_NB_SURFACE_VERTEX    = 0x08,
  REP_COMPARATOR_AREA                 = 0x10,
  REP_COMPARATOR_DISTANCE             = 0x20
};

/**
 * Comparator between two CATRep's.
 */
class ExportedByPolyVisuBoolOper CATPolyRepComparator
{
private:
  CATCGMOutput& out;
  CATTolerance const* const tolerance;
  double const tolerancePercent;
  double const tolerancePercentForBBox;
  unsigned int const mode;

public:
  /**
   * @param out_
   *   The CATCGMOutput
   * @param mode
   *   Define the list of the comparison operators
   * @param tolerancePercent_
   *   Use to make a comparison between several values (bounding box size, nb facet, nb vertex...)
   *   Default value is 10%
   * @param tolerance_
   *   The geometric modeler tolerance, used by the deviation (distance) operator
   */
  CATPolyRepComparator (CATCGMOutput& out_, unsigned int const mode_, double const tolerancePercent_ = 0.1, double const tolerancePercentForBBox_ = 0.1 , CATTolerance const* const tolerance_ = 0);
  /**
   * Destructor
   */
  ~CATPolyRepComparator () {}

  /**
   * Compares two CATRep's.
   * @return
   *   E_INVALIDARG if one rep is not a CAT3DRep, or if the CATTolerance is not set with a REP_COMPARATOR_DISTANCE mode
   *   S_FALSE if the reps are not similar or if a comparator fails
   *   S_OK otherwise
   */
  HRESULT Compare (CATRep& iRep, CATRep& iRepModel);
};

#endif // !CATPolyRepComparator_H
