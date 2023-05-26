// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyOffsetObserver2D.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// February 2016 Creation: dps
//===================================================================
#ifndef CATPolyOffsetObserver2D_H
#define CATPolyOffsetObserver2D_H

#include "PolygonalOperators.h"       // ExportedBy
#include "CATPolyPolygonObserver2D.h" // derivation
#include "CATErrorDef.h"              // HRESULT definition (for compil under UNIX)
#include "CATBoolean.h"
#include "CATSysBoolean.h"

#include "CATListPV.h"
#include "CATCollec.h"

class CATPolyPolygon2D;
class CATPolyVertex2D;
class CATPolyBar2D;
class CATPolyFace2D;
class CATPolyLoop2D;

/**
* Observer base class for CATPolyOffset2D objects.  When events occur to an observed instance of
* a CATPolyPolygon2D object, calls to the observer signaling the events are made.  A call can be made
* before or after the event:
*   - Methods starting by PrepareTo and followed by the event name are called just before the event.
*   - Methods staring by ReactTo and followed by the event name are made just after the event.
*/
class ExportedByPolygonalOperators CATPolyOffsetObserver2D : public CATPolyPolygonObserver2D
{

public :

  CATPolyOffsetObserver2D ();
  virtual ~CATPolyOffsetObserver2D ();



public:

  /** @name Listening to Offset Events
  @{ */

  /**
  * A call made after a bar is offset.
  */
  virtual HRESULT ReactToOffsetBar (const CATPolyBar2D* iBarToOffset, const CATPolyBar2D* iOffsetBar); 

  /**
  * A call made after a vertex is offset.
  */
  virtual HRESULT ReactToOffsetVertex (const CATPolyVertex2D* iVertexToOffset, const CATPolyVertex2D* iOffsetVertex); 

  /**
  * A call made after a vertex is offset.
  */
  virtual HRESULT ReactToOffsetVertex (const CATPolyVertex2D* iVertexToOffset, const CATPolyBar2D* iOffsetBar); 

  /**
  * A call made after a vertex (between 2 successive bars) is offset into a rounded PolyLine
  * This PolyLine is described as a set of alternative CATPolyVertex2D, CATPolyBar2D, ..., CATPolyVertex2D
  * The number of elements is obviously odd, and greater or equal to 3
  * The first and last elements are obviously 2 CATPolyVertex2D objects (identical in case of closed PolyLine)
  */
  virtual HRESULT ReactToRoundOffsetVertex (const CATPolyVertex2D* iVertexToOffset, const CATPolyBar2D* iPreviousBarToOffset, const CATPolyBar2D* iNextBarToOffset, 
                                            const CATListPV &iRoundedPolyLine); 

  /**
  * A call made after a vertex (between 2 successive bars) is offset into a rounded PolyLine
  * This PolyLine is described as a set of alternative CATPolyVertex2D, CATPolyBar2D, ..., CATPolyVertex2D
  * The number of elements is obviously odd, and greater or equal to 3
  * The first and last elements are obviously 2 CATPolyVertex2D objects (identical in case of closed PolyLine)
  * iNullAngleConfiguration is an additional information allowing the caller to distinguish the limit case of convexity : 
  * when iPreviousBarToOffset and iNextBarToOffset are 2 opposite bars, iRoundedPolyLine represents an half circle.
  */
  virtual HRESULT ReactToRoundOffsetVertex (const CATPolyVertex2D* iVertexToOffset, const CATPolyBar2D* iPreviousBarToOffset, const CATPolyBar2D* iNextBarToOffset, 
                                            const CATListPV &iRoundedPolyLine, const CATBoolean &iNullAngleConfiguration); 

};

#endif
