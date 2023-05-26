// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyRepAdapter.h
//
//===================================================================
// March 2009  Creation: NDO
//===================================================================
#ifndef CATPolyBodyRepAdapter_H
#define CATPolyBodyRepAdapter_H

#include "PolyVizAdapters.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATIAV5Level.h"

class CAT3DCurvedPipeRep;
class CAT3DCurveRep;
class CAT3DCustomRep;
class CAT3DCylinderRep;
class CAT3DLineRep;
class CAT3DPlanRep;
class CAT3DPointRep;
class CATMonoWireRep;
class CATSurfacicRep;
class CATRep;
class CATVizMonoWireRep;
class CATVizUV3DRep;
class CATVizVertexBufferRep;
class CAT3DCanonicalRep;

class VisPrimitiveGroupRep;

class CATGraphicPrimitive;
class CATVizPrimitive;

class CATPolyBody;
class CATPolyCell;
class CATPolyBodyRepDiagnosis;
class CATPolyBodyVisLayer;
class CATPolyUVRefiner;


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
extern "C" ExportedByPolyVizAdapters HRESULT CATCreatePolyBodyUnstreamer (CATIPolyBodyUnstreamer*& oUnstreamer);


/**
This is a builder of CATPolyBody-Rep adapters. A CATPolyBody-Rep adapter provides a CATPolyBody view of 
one of the supported reps.

The supported reps are the followings:
<ul>
  <li> CAT3DCurvedPipeRep
  <li> CAT3DCurveRep
  <li> CAT3DCustomRep
  <li> CAT3DCylinderRep
  <li> CAT3DLineRep
  <li> CAT3DPlanRep
  <li> CAT3DPointRep
  <li> CATMonoWireRep
  <li> CATSurfacicRep
  <li> CATVizMonoWireRep 
  <li> CATVizUV3DRep
  <li> CATVizVertexBufferRep
  <li> CAT3DCanonicalRep
</ul>

It also works for VisPrimitiveGroupRep but with some limitations as these reps are just defined for visualization purposes 
with no inherent model. (A VisPrimitiveGroupRep is an adapter for visualization.)

The viz reps are automatically refined when applicable (refinable viz reps, UV reps.)

This adapter also supports a CATRep if it is any of the above rep but it does not support groups of reps 
as in a CAT3DBagRep.

This adapter does not deal directly with the viz (or GP) primitives (only reps!); 
For viz primitives, please refer to CATPolyBodyVizAdapter or CATPolyBodyEVizAdapter.
For GP primitives, please refer to CATPolyBodyGPAdapter.

The adapter makes new CATPolyCell's that encapsulate the GP primitives (from the reps) and adds them to 
the CATPolyBody.

Construction of the CATPolyCell's is CPU and memory efficient.  There is no duplication of the visu data.
Working layers (cache) are transparently instanciated when the CATPolyCell data are accessed (for instance
through layers or iterators.)  These working layers are deleted from memory when the data are no longer 
accessed and the layers are released.

The visu objects must remain valid during the whole lifecycle of the CATPolyBody and any of its entities.
*/
class ExportedByPolyVizAdapters CATPolyBodyRepAdapter
{

public:

  /**
   * Default constructor.  Mode of refinement is ADAPTIVE (non-uniform).
   * By default, a refinable viz rep (UV Rep) will be refined adaptively according to its recorded sag value.
   * Any other rep cannot be refined.
   */
  CATPolyBodyRepAdapter (CATPolyUVRefiner* iUVRefiner = 0);

  /**
   * Constructor.  Mode of refinement is UNIFORM.
   * This constructor changes the mode from adaptive to uniform refinement for refinable viz rep (UV Rep).
   * @param iRefinementLevel
   *   This parameter defines the uniform refinement level.
   */
  CATPolyBodyRepAdapter (const unsigned int iUniformRefinementLevel);

  ~CATPolyBodyRepAdapter ();

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
    /** Wire-edges (exclude face-edges). */  eWireEdge  = 0x08,
    /** Face-edges (exclude wire-edges). */  eFaceEdge  = 0x10
  };

public:

/** @name Generic Reps
    @{ */

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
  HRESULT Run (CATRep& iRep, 
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
  HRESULT Run (CATRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis, CATPolyBodyVisLayer* ioVisLayer,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from one of the graphic primitive of a CATRep.
   * @param iRep
   *   The input CATRep.
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
  HRESULT Run (CATRep& iRep, CATGraphicPrimitive& iGraphicPrimitive,
               CATPolyBody*& oPolyBody, CATPolyCell*& oCell, CATPolyBodyRepDiagnosis*& oDiagnosis);

  /**
   * Do not use.
   */
  HRESULT Run (CATRep& iRep, CATGraphicPrimitive& iGraphicPrimitive,
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis);

  /**
   * Constructs a CATPolyBody from one of the vis primitive of a CATRep.
   * @param iRep
   *   The input CATRep.
   * @param iVisPrimitive
   *   A vis primitive from the CATRep.
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
  HRESULT Run (CATRep& iRep, CATVizPrimitive& iVisPrimitive,
               CATPolyBody*& oPolyBody, CATPolyCell*& oCell, CATPolyBodyRepDiagnosis*& oDiagnosis);

  /**
   * Do not use.
   */
  HRESULT Run (CATRep& iRep, CATVizPrimitive& iVisPrimitive,
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis);

  /**
   * Avoid calling this method; call instead one of the two methods just above.
   *
   * Constructs a CATPolyBody from a CATRep given it is one of the supported rep.
   * The rep cannot be a bag rep (container of other reps.)
   * @param iRep
   *   The input CATRep.
   * @param ioPolyBody
   *   The output CATPolyBody that will be populated with the data from the CATRep.
   * @param iCellTypes
   *   A filter specifying the cells to process for construction of the CATPolyBody.  By default, all 
   *   the cells will be processed.
   * @return
   * <ul>
   *   <li> <code> S_OK </code> on success.
   *   <li> <code> E_FAIL </code> or an other error code otherwise.
   * </ul>
   */
  HRESULT Run (CATRep& iRep, 
               CATPolyBody& ioPolyBody,
               int iCellTypes = eFace | eEdge | eVertex);

/** @} */

public:

/** @name Specific Reps
    @{ */

  /**
   * Constructs a CATPolyBody from a CATVizUV3DRep.
   * @param iRep
   *   The input CATRep.
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
  HRESULT Run (CATVizUV3DRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Avoid calling this method; call instead the method just above.
   */
  HRESULT Run (CATVizUV3DRep& iRep, 
               CATPolyBody& ioPolyBody,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from a CATVizVertexBufferRep.
   * @param iRep
   *   The input CATRep.
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
  HRESULT Run (CATVizVertexBufferRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Avoid calling this method; call instead the method just above.
   */
  HRESULT Run (CATVizVertexBufferRep& iRep, 
               CATPolyBody& ioPolyBody,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from a CATVizMonoWireRep.
   * @param iRep
   *   The input CATRep.
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
  HRESULT Run (CATVizMonoWireRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eEdge | eVertex);

  /**
   * Avoid calling this method; call instead the method just above.
   */
  HRESULT Run (CATVizMonoWireRep& iRep, 
               CATPolyBody& ioPolyBody,
               int iCellTypes = eEdge | eVertex);

/** @} */

public:

/** @name Specific Reps
    @{ */

  /**
   * Constructs a CATPolyBody from a CATSurfacicRep.
   * @param iRep
   *   The input CATRep.
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
  HRESULT Run (CATSurfacicRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from one of the graphic primitive of a CATSurfacicRep.
   * @param iRep
   *   The input CATRep.
   * @param iGraphicPrimitive
   *   A graphic primitive from the CATSurfacicRep.
   * @param oPolyBody
   *   The output CATPolyBody.  This object must be released by the caller.
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
  HRESULT Run (CATSurfacicRep& iRep, CATGraphicPrimitive& iGraphicPrimitive,
               CATPolyBody*& oPolyBody, CATPolyCell*& oCell, CATPolyBodyRepDiagnosis*& oDiagnosis);

  /**
   * Avoid calling this method; call instead the method just above.
   */
  HRESULT Run (CATSurfacicRep& iRep, 
               CATPolyBody& ioPolyBody,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from a CAT3DCylinderRep.
   * @param iRep
   *   The input CATRep.
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
  HRESULT Run (CAT3DCylinderRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   */
  HRESULT Run (CAT3DCylinderRep& iRep, 
               CATPolyBody& ioPolyBody,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from a CAT3DCurvedPipeRep.
   * @param iRep
   *   The input CATRep.
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
  HRESULT Run (CAT3DCurvedPipeRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Avoid calling this method; call instead the method just above.
   */
  HRESULT Run (CAT3DCurvedPipeRep& iRep, 
               CATPolyBody& ioPolyBody,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from a CAT3DCustomRep.
   * @param iRep
   *   The input CATRep.
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
  HRESULT Run (CAT3DCustomRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Avoid calling this method; call instead the method just above.
   */
  HRESULT Run (CAT3DCustomRep& iRep, 
               CATPolyBody& ioPolyBody,
               int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from a CAT3DCurveRep.
   * @param iRep
   *   The input CATRep.
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
  HRESULT Run (CAT3DCurveRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eEdge | eVertex);
/**
 * Avoid calling this method; call instead the method just above.
 */
  HRESULT Run(CAT3DCurveRep& iRep,
              CATPolyBody& ioPolyBody,
              int iCellTypes = eFace);

  /**
   * Constructs a CATPolyBody from a CATMonoWireRep.
   * @param iRep
   *   The input CATRep.
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
  HRESULT Run (CATMonoWireRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eEdge | eVertex);

  /**
   * Avoid calling this method; call instead the method just above.
   */
  HRESULT Run (CATMonoWireRep& iRep, 
               CATPolyBody& ioPolyBody,
               int iCellTypes = eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from a CAT3DPointRep.
   * @param iRep
   *   The input CATRep.
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
  HRESULT Run (CAT3DPointRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eVertex);

  /**
   * Avoid calling this method; call instead the method just above.
   */
  HRESULT Run (CAT3DPointRep& iRep, 
               CATPolyBody& ioPolyBody,
               int iCellTypes = eVertex);

  /**
   * Constructs a CATPolyBody from a CAT3DLineRep.
   * @param iRep
   *   The input CATRep.
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
  HRESULT Run (CAT3DLineRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eEdge | eVertex);

  /**
   * Avoid calling this method; call instead the method just above.
   */
  HRESULT Run (CAT3DLineRep& iRep, 
               CATPolyBody& ioPolyBody,
               int iCellTypes = eEdge | eVertex);

  /**
   * Constructs a CATPolyBody from a CAT3DPlanRep.
   * @param iRep
   *   The input CATRep.
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
  HRESULT Run (CAT3DPlanRep& iRep, 
               CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
               int iCellTypes = eFace);

  /**
   * Avoid calling this method; call instead the method just above.
   */
  HRESULT Run (CAT3DPlanRep& iRep, 
               CATPolyBody& ioPolyBody,
               int iCellTypes = eFace);

#ifdef CATIAR424
  /**
   * Constructs a CATPolyBody from a CAT3DCanonicalRep.
   * @param iRep
   *   The input CATRep.
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
  HRESULT Run(CAT3DCanonicalRep & iRep,
      CATPolyBody*& oPolyBody, CATPolyBodyRepDiagnosis*& oDiagnosis,
      int iCellTypes = eFace | eEdge | eVertex);

  /**
   * Avoid calling this method; call instead the method just above.
   */
  HRESULT Run(CAT3DCanonicalRep& iRep,
    CATPolyBody& ioPolyBody,
    int iCellTypes = eFace);

#endif

/** @} */

private:

  CATPolyUVRefiner* _UVRefiner;

  CATPolyBodyRepDiagnosis* _Diagnosis;

};


#endif // !CATPolyBodyRepAdapter_H
