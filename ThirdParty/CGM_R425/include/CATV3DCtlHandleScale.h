//===================================================================
// COPYRIGHT Dassault Systeme 2012/09/20
//===================================================================
// CATV3DCtlHandleScale.h
// Header definition of class CATV3DCtlHandleScale
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/09/20 Creation: Code generated by the 3DS wizard MF6
//===================================================================

#ifndef CATV3DCtlHandleScale_H
#define CATV3DCtlHandleScale_H

#include <VisuImmersive3D.h>
#include <CATV3DCtlHandle.h>

//-----------------------------------------------------------------------------
/**
 * This widget provides a standard styled direction Scale manipulator.
 *
 * @par Role
 * A direction Scale handle is used to scale object along a direction.
 * It send a Scale event when manipulated and automaticaly handle his 
 * position when draging.
 * <br>
 *
 * @par Handle Position
 * Orient Handle using axis defined in @c CATV3DLay3D.Constraints
 * @see CATV3DLay3DConstraints#SetAxis
 * @see CATV3DTopWidget#SetLay3DConstraints
 *
 * @par Scale direction
 * The Scale direction is always along the first direction of the constraining axis.
 * @see CATV3DLay3DConstraints#SetAxis
 *
 * @par Templates
 * Available template names : Default
 *
 * @par Creation
 * @code
 * CATV3DCtlHandleScale* pHandle = CATV3DCtlHandleScale::CreateHandleScale();
 * @endcode
 * @ingroup V3DControls
 */
class ExportedByVisuImmersive3D CATV3DCtlHandleScale : public CATV3DCtlHandle
{
  CATDeclareClass;
public:
  /** Constructor*/
  CATV3DCtlHandleScale ();
  /** Destructor*/
  virtual ~CATV3DCtlHandleScale ();

  /**
   * Constructs a CATV3DCtlHandleScale with standard style.
   */
  static CATV3DCtlHandleScale * CreateHandleScale(CATViewpoint* i_pViewpoint=NULL);
  
  /**
   * Constructs multiple CATV3DCtlHandleScale with standard style.
   */
  static void CreateHandlesScale(CATViewpoint* i_pViewpoint, const CATSYPDynArray<CATV3DLay3DConstraints>& i_lConstraints, CATSYPDynArray<CATV3DCtlHandleScale*>& oHandles);

  /**
   * Get the @c Scale event.
   *
   * The @c Scale event is dispatched on the HandleScale when receiving
   * a drag event.
   *
   * This event is issued from the @ref Drag event @ref
   * CATV3DGraphicPrimitive#Drag.
   *
   * @par EventProperties
   *   - Name: @c "Scale"
   *   - Type of propagation: @c OriginToRoot
   *   - Type of argument: @ref CATV3DScaleEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   */
  static CATSYPEvent * Scale();

  /**
   * sets the manipulator position to a new position from the initial position position with an amplitude ImposDist.
   * @param iImposDist
   * The distance to force translation.
   */
  void SetAbsDistance(const float &iImposDist);
  /**
   * @return the imposed distance from initial position.
   * @see SetAbsDistance
   */
  float GetAbsDistance() const;

  /**
   * Handle drag event of manipulator view. Should be private.
   */
  virtual void HandleDrag(CATBaseUnknown * i_pSender, CATV3DManipulationEventArgs * i_pArgs);

  /**
   * Handle BeginDrag event of manipulator view. Should be private.
   */
  virtual void HandleBeginDrag(CATBaseUnknown * i_pSender, CATV3DMouseEventArgs * i_pArgs);

  /**
   * Handle EndDrag event of manipulator view. Should be private.
   */
  virtual void HandleEndDrag(CATBaseUnknown * i_pSender, CATV3DMouseEventArgs * i_pArgs);

    /**
  * Handle mouse cursor on entry event of manipulator.
  */
  virtual void HandleEntry(CATBaseUnknown * i_pSender, CATV3DMouseEventArgs * i_pArgs);

  /**
  * Handle mouse cursor on leave event of manipulator.
  */
  virtual void HandleLeave(CATBaseUnknown * i_pSender, CATV3DMouseEventArgs * i_pArgs);
  virtual void HandleMoveOver(CATBaseUnknown * i_pSender, CATV3DMouseEventArgs * i_pArgs);  
  virtual void HandlePress(CATBaseUnknown * i_pSender, CATV3DMouseEventArgs * i_pArgs);      
  virtual void HandleRelease(CATBaseUnknown * i_pSender, CATV3DMouseEventArgs * i_pArgs);  
  virtual void HandleDoubleClick(CATBaseUnknown * i_pSender, CATV3DMouseEventArgs * i_pArgs); 
  virtual void HandleDoubleRelease(CATBaseUnknown * i_pSender, CATV3DMouseEventArgs * i_pArgs);   
  virtual void HandleRightClick(CATBaseUnknown * i_pSender, CATV3DMouseEventArgs * i_pArgs); 
  virtual void HandleEndRightClick(CATBaseUnknown * i_pSender, CATV3DMouseEventArgs * i_pArgs); 
  virtual void HandleMultiplePress(CATBaseUnknown * i_pSender, CATV3DMouseEventArgs * i_pArgs);

  /**
   * @copydoc l_CATV3DCtl#TemplateDataUpdated
   *
   * Here are the mandatory "syp:named" objects :
   * @li GPManip [CATV3DGraphicPrimitive]
   */
  void TemplateDataUpdated();

  /**
   * @depracated Use the AutoPositionUpdateFlag instead.
   * This method does nothing and is only kept not to break ODTs.
   */
  void SetFollowPositionFlag(const CATBoolean& iFollowFlag);
  /**
   * @depracated Use the AutoPositionUpdateFlag instead.
   * This method does nothing and is only kept not to break ODTs.
   * @see #SetFollowPositionFlag
   */
  CATBoolean GetFollowPositionFlag() const;

private:
  void RunAnimation();

  void Set4ArrowsCursor(CATBaseUnknown * i_pSender, CATV3DMouseEventArgs * i_pArgs);
  void ResetCursor(CATBaseUnknown * i_pSender, CATV3DMouseEventArgs * i_pArgs);

  CATV3DCtlHandleScale (CATV3DCtlHandleScale &);
  CATV3DCtlHandleScale& operator=(CATV3DCtlHandleScale&);
};

#endif
