#ifndef CATIMshVertexLocationPriv_h
#define CATIMshVertexLocationPriv_h

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATIMshVertexLocationPriv :
// Parametric coordinates of a Mesh vertex
//
//=============================================================================
// February 2022  Creation                          Fabien Noblet (FNT1)
//=============================================================================

#include "ExportedByCATMshMesherCore.h"

#include "CATIMshVertexLocation.h"
#include "CATIMshMesh.h"


class ExportedByCATMshMesherCore CATIMshVertexLocationPriv : public CATIMshVertexLocation
{

public:

  /**
  * Set the underlying geometric ID of the geometry on which lies this vertex location
  * @param oGeomID
  *   The geometric ID of the underlying geometry entity.
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetSupport(int iGeomID) = 0;

  /**
  * Set the uv coordinates corresponding to this location
  * @param oUV
  *   The uv coordinates
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetParametric2DCoordinates(double iUV[2]) = 0;

  /**
   * Get the corresponding t coordinates
   */
  virtual HRESULT SetParametric1DCoordinates(double iT) = 0;

  /**
  * To be called for exact locations
  */
  virtual void Exact() = 0;

  /**
  * Set the index of the element in the discrete parameterisation on which belongs the vertex
  * @param oElem
  *   The index of the input mesh element on which lies the vertex.
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetSourceElement(CATMshElementIndex &iElem) = 0;

  /**
  * Set the segment of input wire discrete parametrisation on which the location lies
  * @param oFirst
  *   The index of the first extremity of the segment on which lies the vertex in this discrete parametrisation
  * @param oLast
  *   The index of the second extremity of the segment on which lies the vertex in this discrete parametrisation
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetSourceEdge(CATMshVertexIndex &iV0, CATMshVertexIndex &iV1) = 0;

};

#endif
