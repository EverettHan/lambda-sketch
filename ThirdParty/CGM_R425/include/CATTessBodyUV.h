// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessBodyUV
//
//===================================================================
//
// July 2010  Creation: NDO
//===================================================================
#ifndef CATTessBodyUV_h
#define CATTessBodyUV_h

#include "TessBodyAdapters.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATTessParamToken.h"
#include "CATPGMTessBody.h"
#include "CATAssert.h"

class CATTessParam;
class CATSoftwareConfiguration;
class CATBody;
class CATDomain;
class CATVolume;
class CATFace;
class CATEdge;
class CATVertex;

class CATIPolySurface;
class CATIPolyCurve;
class CATIPolyPoint;

class CATTessCurveDiscretizer;
class CATTessSurfaceDiscretizer;
class CATTessSurfaceRegularizer;

class CATMapOfPtrToPtr;


/**
* Class that constructs CATIPolySurface, CATIPolyCurve and CATIPolyPoint instances with the tessellated data 
* computed from a CATBody.  
*
* In this custom implementation to provide input data for dynamic tessellation (UV), the data are computed by global 
* tessellation.
* 
* New CATIPolySurface, CATIPolyCurve or CATIPolyPoint instances may be created each time a method is called for 
* a CATFace, CATEdge or CATVertex respectively.  While these instances may be different, they will refer to
* the same tessellation data for a given CATCell.
*
* All instances returned by the methods are ref-counted and must be released by the caller.
*/
class ExportedByTessBodyAdapters CATTessBodyUV : public CATPGMTessBody
{

public:

  /**
   * Constructor.
   * Construct a tessellated body from a CATBody and the tessellation paramters.
   * @param iBody
   *   The input CATBody to tessellate.
   * @param iParam
   *   The tessellation parameters (sag, step, angle...)
   * @param iConfiguration
   *   The input software configuration.  Different versions of the tessellation operator may be applied depending on the 
   *   value of the input software configuration.
   */
  CATTessBodyUV (CATBody& iBody, const CATTessParam& iParam, CATSoftwareConfiguration* iConfiguration,
                 CATTessCurveDiscretizer* iCurveDiscretizer = 0,
                 CATTessSurfaceDiscretizer* iSurfaceDiscretizer = 0,
                 CATTessSurfaceRegularizer* iSurfaceRegularizer = 0);

  ~CATTessBodyUV ();

public:

  /**
   * Returns a reference to the CATBody that is tessellated.
   * @return
   *   The CATBody that is tessellated.
   */
  inline const CATBody& GetBody () const;

  /**
   * Returns a reference to the CATBody that is tessellated.
   * @return
   *   The CATBody that is tessellated.
   */
  inline CATBody& GetBody ();

  /**
   * Returns the target sag of the tessellation data.  This is the sag that was defined in the input parameters.
   * @return 
   *   The sag of the tessellation data.
   */
  inline double GetSag () const;

public:

  /**
   * Returns the tessellation ID associated to a CATCell.
   * @param iCell
   *   The input CATCell.
   * @param oTessID
   *   The output CATCGMTessID.
   * @return
   *   <ul>
   *     <li> S_OK if the CATCGMTessID has been set.
   *     <li> E_FAIL or any other error when a failure occurs and the CATCGMTessID has not been set.
   *   </ul>
   */
  inline HRESULT GetTessID (CATCell &iCell, CATCGMTessID &oTessID);
	inline HRESULT GetTessellateID (CATCell &iCell, CATCGMTessellateID* &oTessID);

public:

  HRESULT GetPolySurface (CATFace& iFace, CATIPolySurface*& oPolySurface, CATOrientation * oOriPolySurfaceVsFace=0);

  HRESULT GetPolySurface (CATFace &iFace, CATIPolySurface *&oPolySurface,
                          CATMapOfEdgeToPolySurfaceVertexLine* ioEdgeMapToPolyCurve,
                          CATMapOfVertexToPolySurfaceVertex* ioVertexMapToPolyPoint, 
													CATOrientation * oOriPolySurfaceVsFace=0);

  HRESULT GetPolyCurve (CATEdge& iEdge, CATIPolyCurve*& oPolyCurve, CATOrientation * oOriPolyCurveVsEdge=0);

  HRESULT GetPolyCurve (CATEdge &iEdge, CATIPolyCurve *&oPolyCurve,
                        CATMapOfVertexToPolyCurveVertex* ioVertexMapToPolyPoint, 
												CATOrientation * oOriPolyCurveVsEdge=0);

  HRESULT GetPolyPoint (CATVertex& iVertex, CATIPolyPoint*& oPolyPoint);

public:

  /**
   * @nodoc
   */
  inline const CATTessParam& GetTessParam () const;

  /**
   * @nodoc
   */
  inline const CATTessParamToken& GetTessToken () const;

  /**
   * @nodoc
   */
  HRESULT GetPolyCurve (CATFace& iFace, CATEdge& iEdge, CATIPolyCurve*& oPolyCurve);

  /**
   * @nodoc
   */
  HRESULT GetPolyPoint (CATFace& iFace, CATVertex& iVertex, CATIPolyPoint*& oPolyPoint);

  /**
   * @nodoc
   */
  HRESULT GetPolySurfaceVertexLine (CATFace& iFace, CATEdge& iEdge, CATIPolySurface& iPolySurface, 
                                    CATIPolySurfaceVertexLine*& oPolySurfaceVertexLine);

  /**
   * @nodoc
   */
  HRESULT GetPolySurfaceVertex (CATFace& iFace, CATVertex& iVertex, CATIPolySurface& iPolySurface, 
                                CATIPolySurfaceVertex*& oPolySurfaceVertex);

private:

  CATPGMTessBody* _TessBody;

  CATMapOfPtrToPtr* _MapFace2VertexMap;
  CATMapOfPtrToPtr* _MapVertex2MeshVertices;

};

inline CATBody& CATTessBodyUV::GetBody ()
{
  CATAssert (_TessBody);
  return _TessBody->GetBody ();
}

inline const CATBody& CATTessBodyUV::GetBody () const
{
  CATAssert (_TessBody);
  return _TessBody->GetBody ();
}

inline double CATTessBodyUV::GetSag () const
{
  CATAssert (_TessBody);
  return _TessBody->GetSag ();
}

inline HRESULT CATTessBodyUV::GetTessID(CATCell &iCell, CATCGMTessID &oTessID)
{
  return S_OK;
}

inline HRESULT CATTessBodyUV::GetTessellateID (CATCell &iCell, CATCGMTessellateID* &oTessID)
{
	oTessID = 0;
  return E_FAIL;
}

inline const CATTessParam& CATTessBodyUV::GetTessParam () const
{
  CATAssert (_TessBody);
  return _TessBody->GetTessParam ();
}

inline const CATTessParamToken& CATTessBodyUV::GetTessToken () const
{
  CATAssert (_TessBody);
  return _TessBody->GetTessToken ();
}

#endif
