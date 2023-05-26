#ifndef CAT2DIndication_h
#define CAT2DIndication_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATVisFoundation.h"
#include "CATBaseUnknown.h"

#include "CATMathPoint2D.h"

class CATMathPoint2Df;

/**
 * Class to create a a 2D indication reference.
 * <b>Role</b>: This class stores in its public data member <tt>point</tt> the location
 * where the user has clicked in a viewer.
 * This information is decoded and used by manipulators and indicators.
 */
class ExportedByCATVisFoundation CAT2DIndication : public CATBaseUnknown
{
  CATDeclareClass;

public:

  /** Constructor of an empty 2D indication. */
  CAT2DIndication();

  /**
   * Constructs the 2D indication.
   * @param iLocation
   * The location where the user has clicked (expressed in window coordinate system).
   */
  CAT2DIndication(const CATMathPoint2D  & iLocation);

  /**
   * Constructs the 2D indication.
   * @param iLocation
   * The location where the user has clicked (expressed in window coordinate system).
   */
  CAT2DIndication(const CATMathPoint2Df & iLocation);

  /** Copy constructor. */
  CAT2DIndication(const CAT2DIndication & i2DIndication);

  /** Assignement operator. */
  CAT2DIndication & operator=(const CAT2DIndication & i2DIndication);

/** @nodoc */
  CATMathPoint2D point;
};

#endif
