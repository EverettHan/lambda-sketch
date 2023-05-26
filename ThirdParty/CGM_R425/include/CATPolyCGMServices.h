// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCGMServices.h
//
//===================================================================
//
// March 2011  Creation: NDO
//===================================================================
#ifndef CATPolyCGMServices_H
#define CATPolyCGMServices_H

#include "CATErrorDef.h"
#include "TessBodyAdapters.h"

/** @file 
 * Global services about polyhedral objects used to retrieve their associated CGM attributes.
 *
 * @see CATPolyServices.h
 */

class CATPolyBody;
class CATIPolyObject;
class CATIPolyPoint;
class CATIPolyCurve;
class CATIPolySurface;

class CATCell;
class CATVertex;
class CATEdge;
class CATFace;
class CATPGMTessBody;

class CATUnicodeString;

/** @name Queries
    @{ */

/**
 * Returns a CATPGMTessBody that is associated to the CATPolyBody.
 * @param iPolyBody
 *   The input CATPolyBody.
 * @param oTessBody
 *   A pointer to a CATPGMTessBody. 
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a CATPGMTessBody is returned.
 *   <tt>S_FALSE</tt> if there is no CATPGMTessBody associated to the CATPolyBody.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByTessBodyAdapters HRESULT CATPolyGetTessBody (const CATPolyBody& iPolyBody, CATPGMTessBody*& oTessBody);


/**
 * Returns a CATCell that is associated to the object.
 * @param iPolyObject
 *   A polyhedral object.
 * @param oCell
 *   A pointer to a CATCell.  (No AddRef () called on the returned pointer.)
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a CATCell is returned.
 *   <tt>S_FALSE</tt> if there is no CATCell.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByTessBodyAdapters HRESULT CATPolyGetCell (const CATIPolyObject& iPolyObject, CATCell*& oCell);

/**
 * Returns a CATVertex that is associated to the object.
 * @param iPolyPoint
 *   A polyhedral point.
 * @param oVertex
 *   A pointer to a CATVertex.  (No AddRef () called on the returned pointer.)
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a CATVertex is returned.
 *   <tt>S_FALSE</tt> if there is no CATCell.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByTessBodyAdapters HRESULT CATPolyGetVertex (const CATIPolyPoint& iPolyPoint, CATVertex*& oVertex);

/**
 * Returns a CATEdge that is associated to the object.
 * @param iPolyCurve
 *   A polyhedral curve.
 * @param oEdge
 *   A pointer to a CATEdge.  (No AddRef () called on the returned pointer.)
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a CATEdge is returned.
 *   <tt>S_FALSE</tt> if there is no CATCell.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByTessBodyAdapters HRESULT CATPolyGetEdge (const CATIPolyCurve& iPolyCurve, CATEdge*& oEdge);

/**
 * Returns a CATFace that is associated to the object.
 * @param iPolySurface
 *   A polyhedral surface.
 * @param oFace
 *   A pointer to a CATFace.  (No AddRef () called on the returned pointer.)
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a CATFace is returned.
 *   <tt>S_FALSE</tt> if there is no CATCell.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 */
ExportedByTessBodyAdapters HRESULT CATPolyGetFace (const CATIPolySurface& iPolySurface, CATFace*& oFace);

/** @} */


/** @name Streaming Services
    @{ */

/**
 * Streams a CATPGMTessBody to a file (NCGM file.)
 * @param iFileName
 *   The file name where the data are saved.
 * @param iTessBody
 *   The input CATPGMTessBody.
 * @return
 * <ul>
 *   <li> <code> S_OK </code> if the entity has been successfully unstreamed.
 *   <li> <code> S_FALSE </code> if the entity cannot be unstreamed.
 *   <li> <code> E_FAIL </code> or any other error if an error occurs.
 * </ul>
 */
ExportedByTessBodyAdapters HRESULT CATPolyStreamTessBody (const CATUnicodeString& iFileName, const CATPGMTessBody& iTessBody);


/**
 * Unstreams a CATPGMTessBody from a file (NCGM file.)
 * @param iFileName
 *   The file name where the data are read from.
 * @param oTessBody
 *   The instance of the CATPGMTessBody constructed during unstreaming.
 *   This instance must be released.
 * @return
 * <ul>
 *   <li> <code> S_OK </code> if the entity has been successfully unstreamed.
 *   <li> <code> S_FALSE </code> if the entity cannot be unstreamed.
 *   <li> <code> E_FAIL </code> or any other error if an error occurs.
 * </ul>
 */
ExportedByTessBodyAdapters HRESULT CATPolyUnstreamTessBody (const CATUnicodeString& iFileName, CATPGMTessBody*& oTessBody);

/** @} */

#endif // !CATPolyCGMServices_H
