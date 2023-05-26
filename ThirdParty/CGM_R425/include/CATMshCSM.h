#ifndef CATMshCSM_h
#define CATMshCSM_h

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATMshCSM :
// CSM surface meshing component
//
//=============================================================================

#include "CATMshCSMExport.h"

#include "CATMshCSMCommon.h"
#include "CATBody.h"
#include "CATEdgeCurve.h"

#include <map>

class CATBody;
class CATIMshMesh;

/**
 * The CSM mesher object. This mesher is able to mesh CATBody and CATIMshMesh inputs.
 * @ingroup CSM
 */
class ExportedByCATMshCSM CATMshCSM : public CATMshCSMCommon
{

public:

  /**
   * Constructeur
   */
  CATMshCSM();

  /**
   * Destructeur
   */
  virtual ~CATMshCSM();

  /**
* Sets the support to be meshed - case of a discrete CAD
* @return
*   An HRESULT.
*   <br><b>Legal values</b>:
*   <dl><dt>S_OK</dt><dd>The Compute is OK.
*   <dt>E_FAIL</dt><dd>The Compute failed.
*   </dl>
*/
  virtual HRESULT SetSupport(CATIMshMesh *iMesh);


  /**
  * Sets the support to be meshed - case of a CATBody
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetSupport(CATBody *iBody);

  /**
  * Sets the support to be meshed - case of a CATBody
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetSupport(int iBodyCount, CATBody **iBodies);
  

  /**
  * Set a TopoID to a given CATFace.
  * @param iFace (in)
  *   The working CATFace
  * @param iTopoID (in)
  *   The associated topoID.
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetTopologicalID(CATFace *iFace, int iTopoID);

  /**
  * Set a TopoID to a given CATFace.
  * @param iEdge (in)
  *   The working CATEdge
  * @param iTopoID (in)
  *   The associated topoID.
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetTopologicalID(CATEdge *iEdge, int iTopoID);

  /**
  * Set a TopoID to a given CATVertex.
  * @param iVertex (in)
  *   The working CATVertex
  * @param iTopoID (in)
  *   The associated topoID.
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetTopologicalID(CATVertex *iVertex, int iTopoID);


  /**
  * Set a GeometricalID to a given CATFace.
  * @param iFace (in)
  *   The working CATFace
  * @param iGeomID (in)
  *   The associated geometrical ID.
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetGeometricID(CATFace *iFace, int iGeomID);

  /**
  * Set a GeometricalID to a given CATEdgeCurve.
  * @param iCurve (in)
  *   The working CATEdgeCurve
  * @param iGeomID (in)
  *   The associated geometrical ID.
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetGeometricID(CATEdgeCurve *iCurve, int iGeomID);

  /**
  * Set a GeometricalID to a given CATVertex.
  * @param iVertex (in)
  *   The working CATVertex
  * @param iGeomID (in)
  *   The associated GeometricalID.
  * @return
  *   An HRESULT.
  *   <br><b>Legal values</b>:
  *   <dl><dt>S_OK</dt><dd>The Compute is OK.
  *   <dt>E_FAIL</dt><dd>The Compute failed.
  *   </dl>
  */
  virtual HRESULT SetGeometricID(CATVertex *iVertex, int iGeomID);


  /**
  * Generate the mesh
  */
  HRESULT Mesh();
  
  HRESULT GetTopologicalID(CATFace* iFace, int &oTopoID);
  HRESULT GetTopologicalID(CATEdge* iEdge, int &oTopoID);
  HRESULT GetTopologicalID(CATVertex* iVertex, int &oTopoID);

  HRESULT GetGeometricID(CATFace* iFace, int &oGeomID);
  HRESULT GetGeometricID(CATEdgeCurve* iCurve, int &oGeomID);
  HRESULT GetGeometricID(CATVertex* iVertex, int &oGeomID);

private:

  HRESULT InitializeMesher();

	/* Input geometry */
	int _BodyCount;
	CATBody **_Bodies;

  std::map<CATFace*, int> _FaceTopoIDs;
  std::map<CATEdge*, int> _EdgeTopoIDs;
  std::map<CATVertex*, int> _VertexTopoIDs;

  std::map<CATFace*, int> _FaceGeomIDs;
  std::map<CATEdgeCurve*, int> _CurveGeomIDs;
  std::map<CATVertex*, int> _VertexGeomIDs;

};

#endif
