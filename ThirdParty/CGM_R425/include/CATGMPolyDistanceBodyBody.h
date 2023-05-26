//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2015
//
// CATGMPolyDistanceBodyBody interface
//
// DESCRIPTION :
//
//    Interface to the approximate Measure Between solver for two
//    CATBody's with polyhedral data.
//
//=============================================================================
//
// History
//
// December 2015  XXC : Creation
//
//=============================================================================

#ifndef CATGMPolyDistanceBodyBody_H
#define CATGMPolyDistanceBodyBody_H

#include "GMPolyBasicOper.h" // ExportedBy
#include "CATCGMOperator.h" // Derivation
#include "CATDistanceBodyBodyDef.h"

#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATDataType.h"
#include "CATCGMVirtual.h"
#include "CATListOfCATCells.h"
#include "ListPOfCATBody.h"

class CATSoftwareConfiguration;
class CATGeoFactory;
class CATMathTransformation;
class CATBody;
class CATCell;
class CATCGMODTScaleManager;

/**
 * Class defining an operator that computes various distance measure
 * between two CATBody's containing polyhedral data. A
 * <tt>CATGMPolyDistanceBodyBody</tt> operator is created with the
 * <tt>CATCreateGMPolyDistanceBodyBodyOp</tt> global functions.
 */
/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBasicOper CATGMPolyDistanceBodyBody : public CATCGMOperator // NOt ready for CATGMPolyGeoOperator because no extension
{
  CATCGMVirtualDeclareClass(CATGMPolyDistanceBodyBody);

 protected:
  /**	@nodoc */
  CATGMPolyDistanceBodyBody(CATGeoFactory &iFactory);

 public:
  /**	@nodoc */
  virtual ~CATGMPolyDistanceBodyBody();

  //------------------------------------------------------------------------------------------------
  // CAA Methods 
  //------------------------------------------------------------------------------------------------

  /** 
   * Returns the distance between two bodies.
   * @return 
   * The distance. 
   */
  virtual double GetDistance() = 0;
	
  /** 
   * Returns the <tt>CATMathPoint</tt> positions representing the locations of closest approach on each body.
   * @param oPoint1
   * The closest point on the first body.
   * @param oPoint2
   * The closest point on the second body.
   */
  virtual void GetPoints(CATMathPoint &oPoint1, CATMathPoint &oPoint2) = 0;

  /**
   * Returns the <tt>CATPoint</tt> objects representing the locations of closest approach on each body.
   * The points, once returned, are owned by the caller.
   * @param oPoint1
   * The closest point on the first body.
   * @param oPoint2
   * The closest point on the second body.
   */	
  virtual void GetPoints(CATPoint *&oPoint1, CATPoint *&oPoint2) = 0;

  /** 
   * Returns the <tt>CATCell<tt> objects on which the closest point for each body is found.
   * @param oCell1
   * The support cell on the first body.
   * @param oCell2
   * The support cell on the second body.
   */	
  virtual void GetSupportCells(CATCell *&oCell1, CATCell *&oCell2) = 0;

  /** 
   * Set Reference Point 
   * The reference point is used to specify the nearest solution when there are multiple solutions. 
   * If not set, position (0,0,0) will be used instead.
   * @param iRefPoint
   * The reference point.
   */	
  virtual void SetReferencePoint(const CATMathPoint & iRefPoint) = 0; 

  /** 
   * Returns the reference point. 
   * @param oRefPoint
   * The reference point.
   */	
  virtual void GetReferencePoint(CATMathPoint & oRefPoint) = 0; 

  /** 
   * Set Reference Direction
   * The reference direction is used to specify the direction to use in minimal distance type and directional distance mode.
   * If not set, direction (0,0,1) will be used instead.
   * @param iRefDirection
   * The reference direction.
   */
  virtual void SetReferenceDirection(const CATMathVector & iRefDirection) = 0;

  /** 
   * Returns the reference direction. 
   * @param oRefDirection
   * The reference direction.
   */	
  virtual void GetReferenceDirection(CATMathVector & oRefDirection) = 0;

  /** @nodoc
   * Replaces a previous body with a new body for another computation.
   * If a result with the previous body has been computed, then it is deleted.
   * The new results will be available after running the operator.
   * @param iBodyToReplace
   * The pointer to the body to be replaced in the definition of the operator.
   * @param iNewBody1 / iNewBody2
   * The pointer to the body replacing <tt>iBodyToReplace</tt> in this operator.
   */
  virtual void ResetBody1(CATBody * iNewBody1) = 0;
  virtual void ResetBody2(CATBody * iNewBody2) = 0;

  /** 
   * Defines an upper bound of the distance between the two bodies. 
   * If known, this can be used to optimize the performance of the computation.
   * @param iDistanceMax
   * The value of the upper bound.
   */
  virtual void SetDistanceMax(double iDistanceMax) = 0;


  //------------------------------------------------------------------------------------------------
  // Non-CAA Settings
  //------------------------------------------------------------------------------------------------


  /** @nodoc 
   * Defines an upper bound of distance between the two bodies.
   * @param iDistanceUpperBound
   * The value of the distance known to be an upper bound of the distance between the 
   * two bodies. This can optimize the performance of the computation.We keep this existing method.
   * This Method is called by SetDistanceMax() internally.
   */
  virtual void SetDistanceUpperBound(double iDistanceUpperBound) = 0;

  /** @nodoc 
   * Sets the target cells.
   * @param iCellsOnBody1
   * Target Cells on First Body 
   * @param iCellsOnBody2
   * Target Cells on Second Body 
   * If target cells are set, only those cells will be used for computation of distance 
   */	
  virtual void SetTargetCells(ListPOfCATCell & iCellsOnBody1, ListPOfCATCell & iCellsOnBody2) = 0; 
  
  /** @nodoc 
   * Sets the type of distance as Maximum, Minimum or Deviation		
   */
  virtual void SetDistanceType(CATDistanceBodyBodyType iType) = 0;

  
  /** @nodoc 
   * Sets the mode of distance as Directional, Perpendicular or General 
   */
  virtual void SetDistanceMode(CATDistanceBodyBodyMode iMode) = 0;


  /** Activates signed distance.
  *
  * This is valid only in "General" mode, "Minimum Distance" Type
  *
  * If one body is inside another body, then normally (i.e. by default, i.e. when signed 
  * distance is deactivated), a zero distance would be returned, and amongst the support 
  * cells returned, one of them will be the "containing" CATVolume.
  *
  * However, when signed distance is activated, then in this case, a negative distance 
  * will be returned. The magnitude of the distance will be equal to the minimum distance 
  * between the "inside" body and the shell of the "outer" body. The support cells returned
  * would as usual be those that contain the nearest points. CATVolume will not be returned
  * as a support cell.
  *
  * Activation of signed distance has no effect when both bodies are outside each other.
  *
  * @param iActivateSignedDistance
  * If this is passed as TRUE, then signed distance will be activated.
  * If this is passed as FALSE, then signed distance will be de-activated.
  * By default, signed distance is de-activated.
  */
  virtual void ActivateSignedDistance(CATBoolean iActivateSignedDistance) = 0;


  /** Pilots the behavior of the distance computation in case of Points Versus Volumes.
  *
  * If this check is de-activated (default value) :
  *         returns a positive distance anyway
  * Else if SignedDistance is de-activated (default value) : 
  *         returns a positive distance if the point is ouside the volume
  *         returns null distance if the point is inside the volume
  * Else if SignedDistance is activated (calling ActivateSignedDistance(TRUE))
  *         returns a positive distance if the point is ouside the volume
  *         returns a negative distance if the point is inside the volume
  */
  virtual void ActivateVolumeContainmentCheck(CATBoolean iActivateVolumeContainmentCheck) = 0;


  /** Multi-Run Management
  */
  virtual void ActivateMultipleUse(CATBoolean iActivateMultipleUse) = 0;


  /** Accuracy management
  * Pilots the accuracy of the computed distance and the nature of the returned CATPoint(s)
  * Basic mode    : the distance is computed on the tessellation of exact bodies depending on the SAG (3D accuracy) 
  *                 and all the returned CATPoint(s) are cartesian (in 3DSpace, without any link to the CATCells)
  * Advanced mode : basic mode as init, then the points are reported on the cell geometries, in order to refine the distance
  *                 and return smart CATPoints as CATPointOnCurve, CATPointOnSurface, CATGeoPolyPointOnCurve, CATGeoPolyPointOnSurface
  *                 in this mode, CartesianPoint(s) are limited to the vertex case.
  * Default mode is Advanced
  */
  virtual void SetAccuracyMode(CATBoolean iAdvancedMode=TRUE)=0;


  //------------------------------------------------------------------------------------------------
  // Non-CAA Get Methods 
  //------------------------------------------------------------------------------------------------

  /** @nodoc 
  * Returns the type of distance.
  * @return 
  * Type of Distance as Maximum, Minimum or Deviation		
  */
  virtual CATDistanceBodyBodyType GetDistanceType() = 0;

  /** @nodoc 
  * Returns the mode of distance.
  * @return 
  * Mode of distance as Directional, Perpendicular or General		
  */
  virtual CATDistanceBodyBodyMode GetDistanceMode() = 0;

  /** 
  * @nodoc
  * Returns the Software configuration to be taken 
  * into acccount by <tt>this</tt> operator.
  * @return
  * The Software configuration.
  */
  virtual CATSoftwareConfiguration* GetSoftwareConfiguration() const = 0;


  //------------------------------------------------------------------------------------------------
  // CGMReplay methods
  //------------------------------------------------------------------------------------------------

  /** @nodoc @nocgmitf */
  virtual void SetCGMODTScaleManager(CATCGMODTScaleManager * iScaleManager) = 0;
};

/**
 * Creates an operator to compute the distance between body1 and body2.
 * Both bodies must belong to the same factory.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the <tt>CATTopData</tt> defining the software configuration and the journal.  
 * @param iBody1
 * The pointer to the first body.
 * @param iBody2
 * The pointer to the second body.
 * @return
 * The pointer to the created operator.
 */
ExportedByGMPolyBasicOper CATGMPolyDistanceBodyBody * CATCreateGMPolyDistanceBodyBodyOp(CATGeoFactory            * iFactory,
                                                                                        CATSoftwareConfiguration * iConfig,
                                                                                        CATBody                  * iBody1,
                                                                                        CATBody                  * iBody2);

/**  
 * Creates an operator to compute the distance between two groups of cells.
 * <li><b>Notes:</b>
 * <ul>
 *     <li> All the cells must belong to the same factory.
 *     <li> The cells within a group may or may not be topologically connected.
 *     <li> The cells within a group may or may not belong to the same body.
 * </ul>
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the <tt>CATTopData</tt> defining the software configuration and the journal.  
 * @param iCellsList1
 * The list of cells forming the first group.
 * @param iCellsList2
 * The list of cells forming the second group.
 * @return
 * The pointer to the created operator.
 */
ExportedByGMPolyBasicOper CATGMPolyDistanceBodyBody * CATCreateGMPolyDistanceBodyBodyOp(CATGeoFactory            * iFactory,
                                                                                        CATSoftwareConfiguration * iConfig,
                                                                                        ListPOfCATCell           & iCellsList1,
                                                                                        ListPOfCATCell           & iCellsList2);

/**  
 * Creates an operator to compute the distance between two bodies or groups of cells.
 * <li><b>Notes:</b>
 * <ul>
 *     <li> All the cells must belong to the same factory.
 *     <li> The cells within a group may or may not be topologically connected.
 *     <li> The cells within a group may or may not belong to the same body.
 * </ul>
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iData
 * The pointer to the <tt>CATTopData</tt> defining the software configuration and the journal.  
 * @param iBody1
 * The pointer to the first body.
 * @param iBody2
 * The pointer to the second body.
 * @param iCellsList1
 * The list of cells forming the first group.
 * @param iCellsList2
 * The list of cells forming the second group.
 * @return
 * The pointer to the created operator.
 */
ExportedByGMPolyBasicOper CATGMPolyDistanceBodyBody * CATCreateGMPolyDistanceBodyBodyOp(CATGeoFactory            * iFactory,
                                                                                        CATSoftwareConfiguration * iConfig,
                                                                                        CATBody                  * iBody1,
                                                                                        CATBody                  * iBody2,
                                                                                        ListPOfCATCell           & iCellsList1,
                                                                                        ListPOfCATCell           & iCellsList2);
#endif
