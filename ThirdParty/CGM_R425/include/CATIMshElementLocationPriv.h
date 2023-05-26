#ifndef CATIMshElementLocationPriv_h
#define CATIMshElementLocationPriv_h

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATIMshElementLocationPriv :
// Parametric coordinates of the vertices of a mesh element
//
//=============================================================================
// April 2022  Creation                          Fabien Noblet (FNT1)
//=============================================================================

#include "ExportedByCATMshMesherCore.h"

#include "CATIMshMesh.h"
#include "CATIMshElementLocation.h"

class ExportedByCATMshMesherCore CATIMshElementLocationPriv : public CATIMshElementLocation
{

public:

  /**
  * Set the underlying geometric ID of the surface on which lies the mesh element
  * @param iGeomID
  *   The geometric ID of the underlying surface.
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetSupport(int iGeomID) = 0;

  /**
  * To be called if the element location is available
  */
  virtual void Available() = 0;

  /**
  * Set the uv coordinates of the element's vertices
  * @param oUVs
  *   An array of size 2 * iSize, containing the UV coordinates of the element's vertices.
  * @param iSize
  *   The number of element's vertices.
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetVerticesParametric2DCoordinates(double *iUVs, int iSize) = 0;

};

#endif
