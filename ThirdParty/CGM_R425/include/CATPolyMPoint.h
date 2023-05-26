// COPYRIGHT Dassault Systemes 2003, all rights reserved.
//===================================================================
//
// CATPolyMPoint.h
// Header definition of CATPolyMPoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  sep 2003 Creation: dhp
//===================================================================

#ifndef CATPolyMPoint_h
#define CATPolyMPoint_h

#include "CATIAV5Level.h"
#ifdef CATIAV5R15

#include "CATPolyMPointTopo.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)
#include "CATPolyMCrv.h"
#include "CATMathPoint.h"

class CATCGMOutput;
class CATMathPoint2D;


/**
* Class representing a point on a mesh.
* @see CATPolyMeshPoint
*/
class ExportedByCATPolyMCrv CATPolyMPoint : public CATPolyMPointTopo
{

public:
  
  /**
  * Default constructor.
  */
  CATPolyMPoint();

  /**
  * Copy constructor.
  * @param rhs
  *   The object to copy.
  */
  CATPolyMPoint( const CATPolyMPoint& iPoint );
  
  /**
  * Destructor.
  */
  ~CATPolyMPoint();

  /**
  * Assignment operator.
  * @param rhs
  *   The object to copy.
  * @return
  *   The object resulting from the assignment.
  */
  CATPolyMPoint& operator = ( const CATPolyMPoint& rhs );

  CATBoolean TopologyEqual (const CATPolyMPoint & rhs) const;
  
  /**
  * Equality operator.
  * @param rhs
  *   The object to compare to this object.
  * @return
  *   TRUE if the mesh points are the same and FALSE otherwise.
  */
  int operator == (const CATPolyMPoint& rhs) const;
  
  /**
  * Inequality operator.
  * @param rhs
  *   The object to compare to this object.
  * @return
  *   TRUE if the mesh points are different and FALSE otherwise.
  */
  int operator != (const CATPolyMPoint& rhs) const;
    
  /**
  * Returns the position of the mesh point.
  * @return
  *   The position of the mesh point.
  */
  inline void GetPosition (CATMathPoint& oPosition) const;
  
  /**
  * Returns the 2D position of the mesh point given a direction.
  * @return
  *   The position of the mesh point.
  */
  void GetPosition2D (const int iDirection, CATMathPoint2D& oPosition) const;
  
  /**
  * Sets the position of the mesh point.
  * @param iPosition
  *   The new position of the mesh point.
  */
  inline void SetPosition (const CATMathPoint& iPosition);
  
  /**
  * For debugging purposes.  Prints the curve definition in the console window.
  */
  void Print (CATCGMOutput & out) const;
  
protected :
      
  CATMathPoint _position;

};


inline void CATPolyMPoint::SetPosition (const CATMathPoint& iPosition)
{
  _position = iPosition;
}


inline void CATPolyMPoint::GetPosition (CATMathPoint& oPosition) const
{
  oPosition = _position;
}


#endif
#endif
