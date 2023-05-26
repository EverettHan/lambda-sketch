// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBody2DRepImporter.h
//
//===================================================================
// September 2015  Creation: JXO
//===================================================================
#ifndef CATPolyBody2DRepImporter_H
#define CATPolyBody2DRepImporter_H

#include "PolyVizAdapters.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CAT2DArcCircleRep;
class CAT2DArcEllipseRep;
class CAT2DCustomRep;
class CAT2DLineRep;
class CAT2DPointRep;
class CAT2DPolygonRep;
class CAT2DRep;

class CATGraphicPrimitive;

class CATPolyBody;
class CATPolyCell;
class CATPolyBodyRepDiagnosis;
class CATPolyBodyVisLayer;


/**
This is a builder of CATPolyBody-2DRep importer. A CATPolyBody-Rep importer provides a CATPolyBody view of 
one of the supported 2D reps.

The supported reps are the followings:
<ul>
  <li> CAT2DArcCircleRep </li>
  <li> CAT2DArcEllipseRep </li>
  <li> CAT2DCustomRep </li>
  <li> CAT2DLineRep </li>
  <li> CAT2DPointRep </li>
  <li> CAT2DPolygonRep </li>
</ul>

This importer also supports a CAT2DRep if it is any of the above rep but it does not support groups of reps 
as in a CAT2DBagRep.

This importer does not deal directly with the viz (or GP) primitives (only reps!); 

The importer makes new CATPolyCell's that encapsulate the GP primitives (from the reps) and adds them to 
the CATPolyBody.

Note that buffer data are duplicated inside new PolyVertices, PolyCurves, PolySurfaces.

*/
class ExportedByPolyVizAdapters CATPolyBody2DRepImporter
{

public:

  /**
   * Default constructor.
   * @param scale
   *        Used for dynamic GPs
   */
  CATPolyBody2DRepImporter(double scale = 1.);

  /**
   * Destructor.
   */
  ~CATPolyBody2DRepImporter ();

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
    /** Vertices. */                         eVertex    = 0x01,
    /** Face-edges and wire-edges. */        eEdge      = 0x02,
    /** Faces. */                            eFace      = 0x04,
    /** Wire-edges (exclude face-edges). */  eWireEdge  = 0x08 
  };

public:

/** @name Generic Reps
    @{ */

  /**
   * Constructs a CATPolyBody from a CAT2DRep given it is one of the supported rep.
   * The rep cannot be a bag rep (container of other reps.)
   * @param iRep
   *   The input CAT2DRep.
   * @param oPolyBody
   *   The output CATPolyBody.  This object must be released by the caller.
   * @param oDiagnosis
   *   The output diagnosis logging all errors found during construction of the CATPolyBody. 
   *   This object must be deleted by the caller.
   * @param iCellTypes
   *   A filter specifying the cells to process for construction of the CATPolyBody.  By default, all 
   *   the cells will be processed.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on success without errors logged onto the diagnosis.
   *   <li> <code> S_FALSE </code> when a CATPolyBody is constructed with errors logged onto the diagnosis.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Run (CAT2DRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from a CATRep given it is one of the supported rep.
   * The rep cannot be a bag rep (container of other reps.)
   * @param iRep
   *   The input CATRep.
   * @param oPolyBody
   *   The output CATPolyBody.  This object must be released by the caller.
   * @param oDiagnosis
   *   The output diagnosis logging all errors found during construction of the CATPolyBody. 
   *   This object must be deleted by the caller.
   * @param ioVisLayer
   *   An optional layer of graphic attributes (may be null.)
   * @param iCellTypes
   *   A filter specifying the cells to process for construction of the CATPolyBody.  By default, all 
   *   the cells will be processed.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on success without errors logged onto the diagnosis.
   *   <li> <code> S_FALSE </code> when a CATPolyBody is constructed with errors logged onto the diagnosis.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Run (CAT2DRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis, CATPolyBodyVisLayer* ioVisLayer,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from one of the graphic primitive of a CATRep.
   * @param iRep
   *   The input CAT2DRep.
   * @param iGraphicPrimitive
   *   A graphic primitive from the CATRep.
   * @param oPolyBody
   *   The output CATPolyBody.  This object must be released by the caller.
   * @param oCell
   *   The output CATPolyCell added to the CATPolyBody.
   * @param oDiagnosis
   *   The output diagnosis logging all errors found during construction of the CATPolyBody. 
   *   This object must be deleted by the caller.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on success without errors logged onto the diagnosis.
   *   <li> <code> S_FALSE </code> when a CATPolyBody is constructed with errors logged onto the diagnosis.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Run (CAT2DRep& iRep, CATGraphicPrimitive& iGraphicPrimitive,
               CATPolyBody*& oPolyBody, CATPolyCell*& oCell, CATPolyBodyRepDiagnosis*& oDiagnosis);

/** @} */

public:

/** @name Specific Reps
    @{ */

  /**
   * Constructs a CATPolyBody from a CAT2DArcCircleRep.
   * @param iRep
   *   The input CAT2DArcCircleRep.
   * @param oPolyBody
   *   The output CATPolyBody.  This object must be released by the caller.
   * @param oDiagnosis
   *   The output diagnosis logging all errors found during construction of the CATPolyBody. 
   *   This object must be deleted by the caller.
   * @param iCellTypes
   *   A filter specifying the cells to process for construction of the CATPolyBody.  By default, all 
   *   the cells will be processed.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on success without errors logged onto the diagnosis.
   *   <li> <code> S_FALSE </code> when a CATPolyBody is constructed with errors logged onto the diagnosis.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Run (CAT2DArcCircleRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from a CAT2DArcEllipseRep.
   * @param iRep
   *   The input CAT2DArcEllipseRep.
   * @param oPolyBody
   *   The output CATPolyBody.  This object must be released by the caller.
   * @param oDiagnosis
   *   The output diagnosis logging all errors found during construction of the CATPolyBody. 
   *   This object must be deleted by the caller.
   * @param iCellTypes
   *   A filter specifying the cells to process for construction of the CATPolyBody.  By default, all 
   *   the cells will be processed.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on success without errors logged onto the diagnosis.
   *   <li> <code> S_FALSE </code> when a CATPolyBody is constructed with errors logged onto the diagnosis.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Run (CAT2DArcEllipseRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from a CAT2DCustomRep.
   * @param iRep
   *   The input CAT2DCustomRep.
   * @param oPolyBody
   *   The output CATPolyBody.  This object must be released by the caller.
   * @param oDiagnosis
   *   The output diagnosis logging all errors found during construction of the CATPolyBody. 
   *   This object must be deleted by the caller.
   * @param iCellTypes
   *   A filter specifying the cells to process for construction of the CATPolyBody.  By default, all 
   *   the cells will be processed.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on success without errors logged onto the diagnosis.
   *   <li> <code> S_FALSE </code> when a CATPolyBody is constructed with errors logged onto the diagnosis.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Run (CAT2DCustomRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from a CAT2DLineRep.
   * @param iRep
   *   The input CAT2DLineRep.
   * @param oPolyBody
   *   The output CATPolyBody.  This object must be released by the caller.
   * @param oDiagnosis
   *   The output diagnosis logging all errors found during construction of the CATPolyBody. 
   *   This object must be deleted by the caller.
   * @param iCellTypes
   *   A filter specifying the cells to process for construction of the CATPolyBody.  By default, all 
   *   the cells will be processed.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on success without errors logged onto the diagnosis.
   *   <li> <code> S_FALSE </code> when a CATPolyBody is constructed with errors logged onto the diagnosis.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Run (CAT2DLineRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from a CAT2DPointRep.
   * @param iRep
   *   The input CAT2DPointRep.
   * @param oPolyBody
   *   The output CATPolyBody.  This object must be released by the caller.
   * @param oDiagnosis
   *   The output diagnosis logging all errors found during construction of the CATPolyBody. 
   *   This object must be deleted by the caller.
   * @param iCellTypes
   *   A filter specifying the cells to process for construction of the CATPolyBody.  By default, all 
   *   the cells will be processed.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on success without errors logged onto the diagnosis.
   *   <li> <code> S_FALSE </code> when a CATPolyBody is constructed with errors logged onto the diagnosis.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Run (CAT2DPointRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eVertex);

  /**
   * Constructs a CATPolyBody from a CAT2DPolygonRep.
   * @param iRep
   *   The input CAT2DPolygonRep.
   * @param oPolyBody
   *   The output CATPolyBody.  This object must be released by the caller.
   * @param oDiagnosis
   *   The output diagnosis logging all errors found during construction of the CATPolyBody. 
   *   This object must be deleted by the caller.
   * @param iCellTypes
   *   A filter specifying the cells to process for construction of the CATPolyBody.  By default, all 
   *   the cells will be processed.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on success without errors logged onto the diagnosis.
   *   <li> <code> S_FALSE </code> when a CATPolyBody is constructed with errors logged onto the diagnosis.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Run (CAT2DPolygonRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eFace | eEdge | eVertex);


/** @} */

private:
  CATPolyBodyRepDiagnosis* _Diagnosis;

  double m_scale;

};


#endif // !CATPolyBody2DRepImporter_H
