// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMPointTopo.h
// Header definition of CATPolyMPointTopo
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Apr 2005 Creation: NDO
//===================================================================
#ifndef CATPolyMPointTopo_h
#define CATPolyMPointTopo_h

#include "CATIAV5Level.h"
#ifdef CATIAV5R15

#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)
#include "CATPolyMCrv.h"
#include "CATPoly.h"

class CATCGMOutput;
class CATMathPoint2D;


/**
* Class representing a point on a mesh.
* @see CATPolyMeshPoint
*/
class ExportedByCATPolyMCrv CATPolyMPointTopo
{

public:
  
  /**
  * Default constructor.
  */
  CATPolyMPointTopo ();
  
  /**
  * Copy constructor.
  * @param rhs
  *   The object to copy.
  */
  CATPolyMPointTopo (const CATPolyMPointTopo& iPoint);
  
  /**
  * Destructor.
  */
  ~CATPolyMPointTopo ();

  /**
  * Assignment operator.
  * @param rhs
  *   The object to copy.
  * @return
  *   The object resulting from the assignment.
  */
  CATPolyMPointTopo& operator = (const CATPolyMPointTopo& rhs);

  /**
  * Equality operator.
  * @param rhs
  *   The object to compare to this object.
  * @return
  *   TRUE if the mesh points are the same and FALSE otherwise.
  */
  int operator == (const CATPolyMPointTopo& rhs) const;

  /**
  * Inequality operator.
  * @param rhs
  *   The object to compare to this object.
  * @return
  *   TRUE if the mesh points are different and FALSE otherwise.
  */
  int operator != (const CATPolyMPointTopo& rhs) const;
  
  /**
  * Sets the mesh point to lie on a vertex.
  * @param iVertex
  *   The relative index of the vertex on which the point lies.
  */
  inline void SetVertex (const int iVertex);
  
  /**
  * Sets the mesh point to lie on an edge.
  * @param iVertex0
  *   The relative index of the first vertex of the edge
  *   on which the point lies.
  * @param iVertex1
  *   The relative index of the second vertex of the edge
  *   on which the point lies.
  */  
  inline void SetBar (const int iVertex0, const int iVertex1);
  
  /**
  * Sets the mesh point to lie in a triangle.
  * @param iTriangle
  *   The triangle in which the mesh point lies.
  */
  inline void SetTriangle (const int iTriangle);
  
  /**
  * Gets the mesh point's vertex.
  * @param oVertex
  *   The relative index of the vertex on which the mesh point lies.
  * @return
  *   TRUE if the mesh point is of type <tt>eVertexPoint</tt> and
  *   FALSE otherwise.
  */
  inline HRESULT GetVertex (int & oVertex) const;
  
  /**
  * Gets the mesh point's edge.
  * @param oVertex0
  *   The relative index of the first vertex of the edge on which
  *   the mesh point lies.
  * @param oVertex1
  *   The relative index of the second vertex of the edge on which
  *   the mesh point lies.
  * @return
  *   TRUE if the mesh point is of type <tt>eEdgePoint</tt> and
  *   FALSE otherwise.
  */
  inline HRESULT GetBar (int & oVertex0, int & oVertex1) const;

  /**
  * Gets the mesh point's triangle.
  * @param oTriangle
  *   The index of the triangle on which the mesh point lies.
  * @return
  *   TRUE if the mesh point is of type <tt>eFacePoint</tt> and
  *   FALSE otherwise.
  */
  inline HRESULT GetTriangle (int & oTriangle) const;
  
  /**
  * Returns the type of the mesh point.
  * @return
  *   The type of the mesh point.
  *   See CATPoly.h.
  */
  inline int GetType (void) const;
  
  /**
  * For debugging purposes.
  */
  void Print (CATCGMOutput & out) const;
  
protected :
      
  int _type;
  int _meshElement[2];

};


inline void CATPolyMPointTopo::SetVertex (const int iVertex)
{
  _type = CATPoly::eVertex;
  _meshElement[0] = iVertex;
  _meshElement[1] = 0;
}


inline void CATPolyMPointTopo::SetBar (const int iVertex0, const int iVertex1)
{
  _type = CATPoly::eBar;
  _meshElement[0] = iVertex0;
  _meshElement[1] = iVertex1;
}


inline void CATPolyMPointTopo::SetTriangle (const int iTriangle)
{
  _type = CATPoly::eTriangle;
  _meshElement[0] = iTriangle;
  _meshElement[1] = 0;
}


inline HRESULT CATPolyMPointTopo::GetVertex (int& oVertex) const
{
  if (_type == CATPoly::eVertex)
  {
    oVertex = _meshElement[0];
    return S_OK;
  }
  return E_FAIL;
}


inline HRESULT CATPolyMPointTopo::GetBar (int& oVertex0, int& oVertex1) const
{
  if (_type == CATPoly::eBar)
  {
    oVertex0 = _meshElement[0];
    oVertex1 = _meshElement[1];
    return S_OK;
  }
  return E_FAIL;
}


inline HRESULT CATPolyMPointTopo::GetTriangle (int& oTriangle) const
{
  if (_type == CATPoly::eTriangle)
  {
    oTriangle = _meshElement[0];
    return S_OK;
  }
  return E_FAIL;
}


inline int CATPolyMPointTopo::GetType () const
{
  return _type;
}

#endif
#endif
