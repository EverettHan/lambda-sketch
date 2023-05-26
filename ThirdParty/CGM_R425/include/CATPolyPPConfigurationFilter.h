// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPConfigurationFilter.h
//
//===================================================================
//
// Usage notes: Abstract filter that restrain the scope of valid
// configurations in the nD Path Planning solver. Implementations must
// implement the Filter method.
//
//===================================================================
//
// 2014-11-14 XXC: Creation
// 2015-12-07 JXO: Documentation
//===================================================================

#ifndef CATPolyPPConfigurationFilter_HH
#define CATPolyPPConfigurationFilter_HH

#include "PolyPathPlanning.h"

class CATMathTransformation;
class CATPolyPPPosition;

// Math
#include "CATBoolean.h"

/** Class defining the abstract Configuration Filter interface. Allows
 *  to restrain the scope of valid configurations in the nD Path
 *  Planning solver in addition to the limits defined in the
 *  configuration space.
 */
class ExportedByPolyPathPlanning CATPolyPPConfigurationFilter
{
 public:
  /**
   * Should return
   * TRUE if the position is to be kept
   * FALSE if the position is to be filtered OUT.
   */
  virtual CATBoolean Filter(const CATMathTransformation & iPosition) = 0;
  /** Virtual destructor */
  virtual ~CATPolyPPConfigurationFilter();

  virtual CATPolyPPConfigurationFilter* Clone() const = 0;

  virtual void SetGuidingSegment( const int iSegment );

  enum FilterTypeEnum
  {
    Box,
    Pipe,
    Shape,
    Unknown
  };

  /**
   * must be overide on child class (and add type into FilterTypeEnum)
   **/
  virtual FilterTypeEnum GetType() const;

protected:
  CATPolyPPConfigurationFilter();

};

#endif
