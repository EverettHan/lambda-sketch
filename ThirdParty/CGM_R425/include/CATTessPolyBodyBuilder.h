// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessPolyBodyBuilder
//
//===================================================================
//
// Aug 2009 : NDO : Creation
// Mar 2023 : F1Z : Remove cellType since it is not used.
//                  Migration to new adapter impl.
//                  Add volume mode.
//===================================================================
#ifndef CATTessPolyBodyBuilder_H
#define CATTessPolyBodyBuilder_H

#include "TessBodyAdapters.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATTopDefine.h"  // CATOrientation
#include "CATMapOfPtrToInt.h"
#include "CATMathStreamDef.h"

class CATBody;

class CATWire;
class CATDomain;

class CATVolume;
class CATFace;
class CATEdge;
class CATVertex;

class CATPGMTessBody;

class CATPolyBody;
class CATPolyCell;
class CATPolyFace;
class CATPolyEdge;
class CATPolyVertex;
class CATIPolyPoint;
class CATIPolySurfaceVertexCellConstLayer;
class CATTessPolyBodyDiagnosis;

class CATMapOfCellToPolyCell;

class CATUnicodeString;
class CATMathStream;


#ifndef _STATIC_SOURCE

// TO MOVE SOMEWHERE ELSE.
class CATIPolyBodyUnstreamer;

// TO MOVE SOMEWHERE ELSE.
/**
 * Creates an instance of CATIPolyBodyUnstreamer.
 *
 * @param iStreamerVersion
 *   The version of the unstreamer to construct.
 * @param oUnstreamer
 *   The returned instance of CATIPolyBodyUnstreamer.  The returned instance must be deleted.
 * @return
 * <ul>
 *   <li> <code> S_OK </code> if a valid instance is returned.
 *   <li> <code> S_FALSE </code> if a valid instance cannot be returned.
 *   <li> <code> E_FAIL </code> or any other error if an error occurs.
 * </ul>
 */
extern "C" ExportedByTessBodyAdapters HRESULT CATCreatePolyBodyUnstreamer (CATIPolyBodyUnstreamer*& oUnstreamer);

/**
 * Creates an instance of a CATMathStream on which a CATPolyBody can be streamed.
 * This method creates an instance of a CATCGMStream.
 */
extern "C" ExportedByTessBodyAdapters CATMathStream* CATCreateCGMStreamForPolyBody (const CATUnicodeString& iFileName, const CATCGMStreamType iAccessMode);

#endif

/**
This polyhedral adapter constructs a CATPolyBody from a CATBody.

The supported entities (<code>CATCell</code>'s) are:
<ul>
  <li> <code> CATFace </code>
  <li> <code> CATEdge </code>
  <li> <code> CATVertex </code>
</ul>

The CATBody objects must remain valid during the whole lifecycle of the CATPolyBody.
*/
class ExportedByTessBodyAdapters CATTessPolyBodyBuilder
{

public:

  /**
   * Constructor.
   * @param iTessBody
   *   A CATPGMTessBody that provides the tessellation data under the form of CATIPolySurface, 
   *   CATIPolyCurve, CATIPolyPoint.
   */
  CATTessPolyBodyBuilder (CATPGMTessBody& iTessBody);

  ~CATTessPolyBodyBuilder ();

public:

  /**
   * Parameter controlling which topological entities are added to the CATPolyBody.
   * To add CATPolyFace's, CATPolyEdge's or CATPolyVertex's to the CATPolyBody, use 
   * respectively, eFace, eEdge or eVertex.  You may use a combination by means of the
   * logical "or" ("|").  Note that CATPolyVertex's must be created to define CATPolyEdge's. 
   * However, if CATPolyVertex's are excluded and CATPolyEdge's are included, then isolated 
   * vertices will not be added to the CATPolyBody but those at the extremities of the 
   * edges will.  If CATPolyEdge's are included but not CATPolyFace's, then edges adjacent to
   * faces will be added as wires but not as boundaries of faces.  Also, CATPolyFace's can
   * be included without their adjacent edges.
   */

  enum CellTypes
  {
    eVertex    = 0x01,
    eEdge      = 0x02,
    eFace      = 0x04
  };

public:

  void SetWithPolyVolume(bool withPolyVolume = true);

  /**
   * Constructs a CATPolyBody from the tessellated CATBody: CATCGMTessBody.
   * @param oPolyBody
   *   The output CATPolyBody.  This object must be deleted by the caller.
   * @param ioMapOfCellToPolyCell
   *   A map associating the CATCell from the CATBody to a CATPolyCell from the CATPolyBody.
   * @param iCellTypes
   *   A filter specifying the cells to process for construction of the CATPolyBody.  By default, all 
   *   the cells from the CATBody are processed.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on success.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Run(CATPolyBody *& oPolyBody,
              CATMapOfCellToPolyCell * ioMapOfCellToPolyCell = 0);

    /**
     * Constructs a CATPolyBody from the tessellated CATBody: CATCGMTessBody.
     * @param oPolyBody
     *   The output CATPolyBody.  This object must be deleted by the caller.
     * @param oDiagnosis
     *   The output diagnosis logging all errors as found during construction of the CATPolyBody.
     *   This object must be deleted by the caller.
     * @param ioMapOfCellToPolyCell
     *   A map associating the CATCell from the CATBody to a CATPolyCell from the CATPolyBody.
     * @param iCellTypes
     *   A filter specifying the cells to process for construction of the CATPolyBody.  By default, all
     *   the cells from the CATBody are processed.
     * @return
     * <ul>
     *   <li> <code> S_OK </code> on success without errors logged onto the diagnosis.
     *   <li> <code> S_FALSE </code> when a CATPolyBody is constructed with errors logged onto the diagnosis.
     *   <li> <code> E_FAIL </code> or an other error code otherwise.
     * </ul>
     */
    HRESULT Run(CATPolyBody *& oPolyBody, CATTessPolyBodyDiagnosis *& oDiagnosis,
                CATMapOfCellToPolyCell * ioMapOfCellToPolyCell = 0);

private:
  class Impl;
  bool _withPolyVolume;

  CATPGMTessBody& _TessBody;

private:

  CATPGMTessBody& GetTessBody () const;

  HRESULT Process (CATBody& iBody, 
                   CATPolyBody& ioPolyBody, CATTessPolyBodyDiagnosis& iDiagnosis,
                   CATMapOfCellToPolyCell& ioMapOfCellToPolyCell,
                   int iCellTypes);

  HRESULT Process (CATDomain& iDomain, CATOrientation iOrientation,
                   CATPolyBody& ioPolyBody, CATTessPolyBodyDiagnosis& iDiagnosis,
                   CATMapOfCellToPolyCell& ioMapOfCellToPolyCell,
                   int iCellTypes);

  HRESULT Process (CATVolume& iVolume, CATOrientation iOrientation,
                   CATPolyBody& ioPolyBody, CATTessPolyBodyDiagnosis& iDiagnosis,
                   CATMapOfCellToPolyCell& ioMapOfCellToPolyCell,
                   int iCellTypes);

  HRESULT Process (CATFace& iFace, CATOrientation iOrientation,
                   CATPolyBody& ioPolyBody, CATTessPolyBodyDiagnosis& iDiagnosis,
                   CATPolyFace*& oPolyFace,
                   CATMapOfCellToPolyCell& ioMapOfCellToPolyCell,
                   int iCellTypes);

  HRESULT Process (CATEdge& iEdge, CATOrientation iOrientation,
                   CATPolyBody& ioPolyBody, CATTessPolyBodyDiagnosis& iDiagnosis,
                   CATPolyEdge*& oPolyEdge,
                   CATMapOfCellToPolyCell& ioMapOfCellToPolyCell,
                   int iCellTypes);

  HRESULT Process (CATVertex& iVertex,
                   CATPolyBody& ioPolyBody, CATTessPolyBodyDiagnosis& iDiagnosis,
                   CATPolyVertex*& oPolyVertex,
                   CATMapOfCellToPolyCell& ioMapOfCellToPolyCell,
                   int iCellTypes);
    
  HRESULT Process (CATWire& iWire, CATOrientation iOrientation,
                   CATPolyBody& ioPolyBody, CATTessPolyBodyDiagnosis& iDiagnosis,
                   CATMapOfCellToPolyCell& ioMapOfCellToPolyCell,
                   int iCellTypes);

  HRESULT ProcessEdgeVertex (CATVertex& iVertex, CATIPolyPoint& iPolyPoint,                                                    
                             CATPolyBody& ioPolyBody, CATTessPolyBodyDiagnosis& iDiagnosis,
                             CATPolyVertex*& oPolyVertex,
                             CATMapOfCellToPolyCell& ioMapOfCellToPolyCell);

};

#endif // !CATTessPolyBodyBuilder_H
