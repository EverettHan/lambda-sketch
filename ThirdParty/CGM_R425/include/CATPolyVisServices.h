// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisServices.h
//
//===================================================================
// September 2012  Creation: NDO
//===================================================================
#ifndef CATPolyVisServices_H
#define CATPolyVisServices_H

#include "CATErrorDef.h"
#include "PolyVizAdapters.h"

/** @file 
 * Global services about polyhedral objects used to retrieve their associated visualization attributes.
 *
 * @see CATPolyServices.h
 * @see CATPolyBodyServices.h
 */

class CATIPolyCurve;
class CATIPolySurface;

class CATPolyBody;
class CATPolyFace;
class CATPolyEdge;
class CATRep;
class CAT3DBoundingGP;
class CAT3DEdgeGP;
class CATViz3DFace;
class CATGraphicPrimitive;
class CATVizPrimitive;


/** @name Queries
    @{ */

/**
 * Returns a CATRep that is associated to the CATPolyBody.
 * @param iPolyBody
 *   The input CATPolyBody.
 * @param oRep
 *   A pointer to a CATRep. 
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a CATRep is returned.
 *   <tt>S_FALSE</tt> if there is no CATRep associated to the CATPolyBody.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByPolyVizAdapters HRESULT CATPolyGetRep (const CATPolyBody& iPolyBody, CATRep*& oRep);


/**
 * Returns the type of the CATRep that is associated to the CATPolyBody.
 * @param iPolyBody
 *   The input CATPolyBody.
 * @param oRepType
 *   The type of the rep that is associated to the CATPolyBody. 
 *   See CATPolyRepType::RepType.
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a CATRep is associated to the CATPolyBody and its type is returned.
 *   <tt>S_FALSE</tt> if there is no CATRep associated to the CATPolyBody and no type is returned.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByPolyVizAdapters HRESULT CATPolyGetRepType (const CATPolyBody& iPolyBody, int& oRepType);


/**
 * Returns the graphic primitive associated to a CATPolyFace.
 * @param iPolyFace
 *   The input CATPolyFace.
 * @param oGP
 *   The graphic primitive. 
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a graphic primitive is returned.
 *   <tt>S_FALSE</tt> if there is no graphic primitive.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByPolyVizAdapters HRESULT CATPolyGetGraphicPrimitive (const CATPolyFace& iPolyFace, CATGraphicPrimitive*& oGP);


/**
 * Returns the graphic primitive associated to a CATIPolySurface.
 * @param iPolySurface
 *   The input CATIPolySurface.
 * @param oGP
 *   The graphic primitive. 
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a graphic primitive is returned.
 *   <tt>S_FALSE</tt> if there is no graphic primitive.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByPolyVizAdapters HRESULT CATPolyGetGraphicPrimitive (const CATIPolySurface& iPolySurface, CATGraphicPrimitive*& oGP);


/**
 * Returns the bounding graphic primitive associated to a CATPolyFace.
 * @param iPolyFace
 *   The input CATPolyFace.
 * @param oGP
 *   The graphic primitive. 
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a graphic primitive is returned.
 *   <tt>S_FALSE</tt> if there is no graphic primitive.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByPolyVizAdapters HRESULT CATPolyGetBoundingGP (const CATPolyFace& iPolyFace, CAT3DBoundingGP*& oGP);


/**
 * Returns the bounding graphic primitive associated to a CATIPolySurface.
 * @param iPolySurface
 *   The input CATIPolySurface.
 * @param oGP
 *   The graphic primitive. 
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a graphic primitive is returned.
 *   <tt>S_FALSE</tt> if there is no graphic primitive.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByPolyVizAdapters HRESULT CATPolyGetBoundingGP (const CATIPolySurface& iPolySurface, CAT3DBoundingGP*& oGP);


/**
 * Returns the CATViz3DFace associated to a CATPolyFace.
 * @param iPolyFace
 *   The input CATPolyFace.
 * @param oVisFace
 *   The CATViz3DFace. 
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a CATViz3DFace is returned.
 *   <tt>S_FALSE</tt> if there is no CATViz3DFace.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByPolyVizAdapters HRESULT CATPolyGetVisFace (const CATPolyFace& iPolyFace, CATViz3DFace*& oVF);


/**
 * Returns the CATViz3DFace associated to a CATIPolySurface.
 * @param iPolySurface
 *   The input CATIPolySurface.
 * @param oVisFace
 *   The CATViz3DFace. 
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a CATViz3DFace is returned.
 *   <tt>S_FALSE</tt> if there is no CATViz3DFace.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByPolyVizAdapters HRESULT CATPolyGetVisFace (const CATIPolySurface& iPolySurface, CATViz3DFace*& oVF);


/**
 * Returns the graphic primitive associated to a CATPolyEdge.
 * @param iPolyEdge
 *   The input CATPolyEdge.
 * @param oGP
 *   The graphic primitive. 
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a graphic primitive is returned.
 *   <tt>S_FALSE</tt> if there is no graphic primitive.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByPolyVizAdapters HRESULT CATPolyGetGraphicPrimitive (const CATPolyEdge& iPolyEdge, CATGraphicPrimitive*& oGP);


/**
 * Returns the graphic primitive associated to a CATIPolyCurve.
 * @param iPolyCurve
 *   The input CATIPolyCurve.
 * @param oGP
 *   The graphic primitive. 
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a graphic primitive is returned.
 *   <tt>S_FALSE</tt> if there is no graphic primitive.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByPolyVizAdapters HRESULT CATPolyGetGraphicPrimitive (const CATIPolyCurve& iPolyCurve, CATGraphicPrimitive*& oGP);


/**
 * Returns the CAT3DEdgeGP associated to a CATPolyEdge.
 * @param iPolyEdge
 *   The input CATPolyEdge.
 * @param oGP
 *   The CAT3DEdgeGP. 
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a CAT3DEdgeGP is returned.
 *   <tt>S_FALSE</tt> if there is no CAT3DEdgeGP.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByPolyVizAdapters HRESULT CATPolyGetEdgeGP (const CATPolyEdge& iPolyEdge, CAT3DEdgeGP*& oGP);


/**
 * Returns the CAT3DEdgeGP associated to a CATIPolyCurve.
 * @param iPolyCurve
 *   The input CATIPolyCurve.
 * @param oGP
 *   The CAT3DEdgeGP. 
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a CAT3DEdgeGP is returned.
 *   <tt>S_FALSE</tt> if there is no CAT3DEdgeGP.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByPolyVizAdapters HRESULT CATPolyGetEdgeGP (const CATIPolyCurve& iPolyEdge, CAT3DEdgeGP*& oGP);


/**
 * Returns the CATVizPrimitive associated to a CATPolyEdge.
 * @param iPolyEdge
 *   The input CATPolyEdge.
 * @param oVP
 *   The CATVizPrimitive. 
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a CATVizPrimitive is returned.
 *   <tt>S_FALSE</tt> if there is no CATVizPrimitive.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByPolyVizAdapters HRESULT CATPolyGetVisPrimitive (const CATPolyEdge& iPolyEdge, CATVizPrimitive*& oVP);


/**
 * Returns the CATVizPrimitive associated to a CATIPolyCurve.
 * @param iPolyCurve
 *   The input CATIPolyCurve.
 * @param oVP
 *   The CATVizPrimitive. 
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a CATVizPrimitive is returned.
 *   <tt>S_FALSE</tt> if there is no CATVizPrimitive.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByPolyVizAdapters HRESULT CATPolyGetVisPrimitive (const CATIPolyCurve& iPolyCurve, CATVizPrimitive*& oVP);

/** @} */

#endif // !CATPolyVisServices_H
