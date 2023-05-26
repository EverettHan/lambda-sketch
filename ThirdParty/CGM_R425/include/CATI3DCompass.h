#ifndef CATI3DCompass_h
#define CATI3DCompass_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"
#include "CAT3DCompassTypedefs.h"
#include "CATMathAxis.h"
#include "CATEventSubscriberTypedefs.h"

class CATCallbackManager;
class CATMathTransformation;
class CATPathElement;
class CATMathPlane;

extern ExportedByCATAfrSelection IID IID_CATI3DCompass;

/**
 * Interface to access and manipulate the compass through software coding.
 * <br><b>Role</b>: The compass object implements the CATI3DCompass interface.
 * To retrieve a pointer to the compass object that implements CATI3DCompass
 * use @href CATFrmEditor#GetCompass method.
 */

class ExportedByCATAfrSelection CATI3DCompass : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  /**
   * Retrieve the state of the compass.
   * @param CompassState
   * The compass state can either be:
   *   <dl>
   *   <dt><tt>CatCompass</tt><dd> if the compass is docked on top right
   *     screen corner and manipulates viewpoint.
   *   <dt><tt>CatGlider</tt><dd> if the compass is located in the 3D scene and
   *     manipulates objects.
   *   </dl>
   * @return
   *   S_OK if operation is successful
   *   <br> E_FAIL if compass representation is destroyed or being destroyed
   */
  virtual HRESULT GetState(CATCompassState * oCompassState) = 0;

  /**
   * Sets the state of the compass.
   * @param iCompassState
   * The state to set.
   *  <br>
   *  <b>Legal values</b> It can be set to either :
   *  <dl>
   *  <dt><tt>CatCompass</tt><dd> to dock the compass on top right screen corner.
   *  <dt><tt>CatGlider</tt><dd> to position the compass in the 3D scene.
   *  Compass is positioned at the origin of the absolute axis system,
   *  while its orientation is kept.
   *  </dl>
   * @return
   *   S_OK if operation is successful
   *   <br> E_FAIL if compass representation is destroyed or being destroyed
   */
  virtual HRESULT SetState(const CATCompassState * iCompassState) = 0;

  /**
   * Retreive the position and orientation of the compass.
   * @param oAxis
   * The returned compass position and orientation in the absolute
   * coordinates systems.
   * @return
   *   S_OK if operation is successful
   *   <br> E_FAIL if compass representation is destroyed or being destroyed
   */
  virtual HRESULT GetPosition(CATMathAxis * oAxis) = 0;

  /**
   * Sets the position and orientation of the compass.
   * @param iAxis
   * New position and orientation of the compass in the absolute
   * coordinates system. If compass is docked in the top right corner
   * of the screen (i.e. GetState returns CatCompass), only the orientation
   * is taken into acount and the @href CATMathAxis origin is ignored.
   * @return
   *   S_OK if operation is successful
   *   <br> E_FAIL if compass representation is destroyed or being destroyed
   */
  virtual HRESULT SetPosition(const CATMathAxis * iAxis) = 0;

  /**
   * Shows the compass on the screen.
   * @return
   *   S_OK if operation is successful
   *   <br> S_FALSE if compass was already visible
   *   <br> E_FAIL if compass representation is destroyed or being destroyed
   */
  virtual HRESULT Show() = 0;

  /**
   * Hides the compass from the screen.
   *   S_OK if operation is successful
   *   <br> S_FALSE if compass was already hidden
   *   <br> E_FAIL if compass representation is destroyed or being destroyed
   */
  virtual HRESULT Hide() = 0;

  /**
   * Retrieve the compass visibility.
   * @param oVisible
   *   Paremeter is set to TRUE if compass is visible, FALSE otherwise
   * @return
   *   S_OK if operation is successful
   *   <br> E_FAIL if compass representation is destroyed or being destroyed
   */
  virtual HRESULT GetVisibility(int * oVisible) = 0;


  /**
   * Look management.
   * @param iLook
   *   iLook=CatNoManipulation : compass is not linked to any object.
   *   <br>iLook=CatObjectManipulation : compass is linked to one or more objects.
   *   <br>iLook=CatViewpointManipulation : compass is on top right screen.
   *   <br>iLook=CatStrainedManipulation : user is pressing the shift key.
   * @return
   *   S_OK if operation is successful
   */
  virtual HRESULT SetLook(const CATCompassLook * iLook) = 0;
  /** @nodoc */
  virtual HRESULT GetLook(CATCompassLook * oLook) = 0;

  /**
   * Retreives the compass event publisher.
   * @param oCompassEventPublisher
   * The event publisher used by the compass to publish events.
   * For usage of event publisher see  @href CATEventSubscriber#AddCallback
   * @return
   *   S_OK if operation is successful
   */
  virtual HRESULT GetEventPublisher(CATBaseUnknown ** oCompassEventPublisher) = 0;

  /**
   * Retrieves the event emitted when user start dragging the compass.
   * <br><b>Role</b>: This event is emitted at the first mouse interaction
   * after clicking one of the compass handle. Subscribe to this event to
   * react on compass start of manipulation by the user.
   * This event is not emitted when select command is running.
   * @param oBeginMoveEvent
   *   A pointer to the published event. See @href CATEventSubscriber#AddCallback
   * @return
   *   S_OK if operation is successful
   */
  virtual HRESULT GetBeginMoveEvent(CATCallbackEvent * oBeginMoveEvent) = 0;

  /**
   * Retrieves the event emitted when user is dragging the compass.
   * <br><b>Role</b>: This event is emitted at the second and every following
   * mouse interaction when user is dragging one of the compass handle. Subscribe
   * to this event to react on compass direct manipulation by the user.
   * This event is not emitted when select command is running.
   * @param oBeginMoveEvent
   *   A pointer to the published event. See @href CATEventSubscriber#AddCallback
   * @return
   *   S_OK if operation is successful
   */
  virtual HRESULT GetMoveEvent(CATCallbackEvent * oMoveEvent) = 0;

  /**
   * Retrieves the event emitted when user finish dragging the compass.
   * <br><b>Role</b>: This event is emitted when the mouse button is released after
   * dragging one of the compass handle. Subscribe to this event to react compass end
   * of manipulation by the user.
   * This event is not emitted when select command is running.
   * @param oBeginMoveEvent
   *   A pointer to the published event. See @href CATEventSubscriber#AddCallback
   * @return
   *   S_OK if operation is successful
   */
  virtual HRESULT GetEndMoveEvent(CATCallbackEvent * oEndMoveEvent) = 0;

  /**
   * Retrieves the current compass transformation.
   * <br><b>Role</b>: This method should be called in the callback method of the BeginMove, Move
   * or EndMove event to know the current transformation that is being applied to the compass.
   * The current transformation is computed between the current position (when Move event is sent)
   * and the initial position (when BeginMove event is sent). The returned value can be modified
   * to override the standard behaviour of the compass, thus permitting to take into account an
   * applicative displacement constraint.
   * @param oTransformation
   *   The current compass transformation.
   * @return
   *   S_OK if operation is successful
   */
  virtual HRESULT GetCurrentTransformation(CATMathTransformation ** oTransformation) = 0;

  /**
   * @nodoc
   * GetShiftModifierState : idem
   */
  virtual HRESULT GetShiftModifierState(int * oShiftOn) = 0; // 1 : Shift on - 0 : Shift off

  /**
   * @nodoc
   * Control key is to be used for object duplication
   */
  virtual HRESULT GetControlModifierState(int * oControlOn) = 0;

  /**
   * @nodoc
   * GetTransformationType : to be used to know which part of the compass
   * has been grabbed
   */
  virtual HRESULT GetTransformationType(CATCompassTransformationType * oTransfoType) = 0;

  /**
   * Retrieves the event emitted when compass starts being moved to another location.
   * <br><b>Role</b>: This event is emitted at the first mouse interaction
   * when user is moving the compass to another location by dragging its center.
   * This event is not emitted when select command is running.
   * @param oBeginDragPreviewEvent
   *   A pointer to the published event. See @href CATEventSubscriber#AddCallback
   * @return
   *   S_OK if operation is successful
   */
  virtual HRESULT GetBeginDragPreviewEvent(CATCallbackEvent * oBeginDragPreviewEvent) = 0;

  /**
   * Retrieves the event emitted when compass is being moved to another location.
   * <br><b>Role</b>: This event is emitted at the second and every following
   * mouse interaction when user is moving the compass to another location by dragging
   * its center.
   * This event is not emitted when select command is running.
   * @param oDragPreviewEvent
   *   A pointer to the published event. See @href CATEventSubscriber#AddCallback
   * @return
   *   S_OK if operation is successful
   */
  virtual HRESULT GetDragPreviewEvent(CATCallbackEvent * oDragPreviewEvent) = 0;

  /**
   * Retrieves the event emitted when compass ends being moved to another location.
   * <br><b>Role</b>: This event is emitted when the mouse button is released after
   * dragging the compass to another location by using its center.
   * @param oEndDragPreviewEvent
   *   A pointer to the published event. See @href CATEventSubscriber#AddCallback
   * @return
   *   S_OK if operation is successful
   */
  virtual HRESULT GetEndDragPreviewEvent(CATCallbackEvent * oEndDragPreviewEvent) = 0;

  /**
   * Retreive compass preview informations.
   * <br><b>Role</b>: This method should be called in the callback method of the
   * BeginDragPreview, DragPreview and EndDragPreview events to retrieve the current
   * preview position of the compass and, if any, the current model object under the mouse.
   * The preview position of the compass can be modified thus allowing application to
   * implement such behaviour as compass snapping to the object that is under the mouse.
   * @param oElementUnder
   *   A pointer to a @href CATPathElement representing the model objects under the mouse
   * @param oPreviewPosition
   *   A pointer to the current preview position
   * @return
   *   S_OK if operation is successful
   */
  virtual HRESULT GetDragPreviewPosition(CATPathElement ** oElementUnder,
                                         CATMathAxis ** oPreviewPosition) = 0;

  /**
   * @nodoc
   * Main plane management
   * Event sent each time position, orientation or privileged plane are modified.
   */
  virtual HRESULT GetMainPlaneModifiedEvent(CATCallbackEvent * oMainPlaneModifiedEvent) = 0;
  /** @nodoc */
  virtual HRESULT GetMainPlane(CATMathPlane * oCATMathPlane) = 0;
  /** @nodoc */
  virtual HRESULT SetMainPlane(int * iMainPlaneIndex) = 0; // 0:XY, 1:YZ, 2:ZX
  /** @nodoc */
  virtual HRESULT ShowMainPlane() = 0;  // NOT IMPLEMENTED
  /** @nodoc */
  virtual HRESULT HideMainPlane() = 0;  // NOT IMPLEMENTED

  /**
   * Retreives the privileged plane modification event.
   * @param oPrivilegedPlaneModifiedEvent
   * The oProvilegedPlaneModifiedEvent is emitted each time the privileged
   * plane definition changes. This might happen through code or user interaction.
   * @return
   *   S_OK if operation is successful
   *   <br> E_FAIL if compass representation is destroyed or being destroyed
   */
  virtual HRESULT GetPrivilegedPlaneModifiedEvent(CATCallbackEvent * oPrivilegedPlaneModifiedEvent) = 0;

  /**
   * Retreives the privileged plane definition.
   * @param oPrivilegedPlane
   * The oPrivileged plane value is equal to either
   *  <dl>
   *  <dt><tt>1</tt><dd> if the privileged plane is defined as (X,Y) or (U,V)
   *  <dt><tt>2</tt><dd> if the privileged plane is defined as (Y,Z) or (V,W)
   *  <dt><tt>3</tt><dd> if the privileged plane is defined as (Z,X) or (W,U)
   *  </dl>
   * <br> To get the privileged plane coordinates use the
   *   @href CATI3DCompass#GetPosition method.
   * @return
   *   S_OK if operation is successful
   *   <br> E_FAIL if compass representation is destroyed or being destroyed
   */
  virtual HRESULT GetPrivilegedPlane(int * oPrivilegedPlane) = 0;

  /**
   * Sets the privileged plane definition.
   * @param iPrivilegedPlane
   * The privileged plane to set.
   *  <br>
   *  <b>Legal values</b> It can be set to either :
   *  <dl>
   *  <dt><tt>1</tt><dd> to define the privileged plane as (X,Y) or (U,V)
   *  <dt><tt>2</tt><dd> to define the privileged plane as (Y,Z) or (V,W)
   *  <dt><tt>3</tt><dd> to define the privileged plane as (Z,X) or (W,U)
   *  </dl>
   * <br> To set the privileged plane coordinates use the
   *  @href CATI3DCompass#SetPosition method.
   * @return
   *   S_OK if operation is successful
   *   <br> E_INVALIDARG if argument is NULL or pointing to an illegal value
   *   <br> E_FAIL if compass representation is destroyed or being destroyed
   */
  virtual HRESULT SetPrivilegedPlane(int * iPrivilegedPlane) = 0;

  /**
   * Retreives the current scale factor.
   * @param oScaleFactor
   * The current scale factor.
   * @return
   *   S_OK if operation is successful
   *   <br> E_INVALIDARG if argument is NULL
   *   <br> E_FAIL if compass representation is destroyed or being destroyed
   */
  virtual HRESULT GetScaleFactor(float * oScaleFactor) = 0;

  /**
   * Sets the current scale factor.
   * @param iScaleFactor
   * The scale factor to set.
   * @return
   *   S_OK if operation is successful
   *   <br> E_INVALIDARG if argument is NULL or pointing to an illegal value
   *   <br> E_FAIL if compass representation is destroyed or being destroyed
   */
  virtual HRESULT SetScaleFactor(float * iScaleFactor) = 0;

  /**
   * Retreives the position of compass in the viewer.
   * @param oCorner
   * The oCorner value is equal to either
   *  <dl>
   *  <dt><tt>1</tt><dd> if the position of compass is defined as Top-Left
   *  <dt><tt>2</tt><dd> if the position of compass is defined as Top-Right
   *  <dt><tt>3</tt><dd> if the position of compass is defined as Bottom-Left
   *  <dt><tt>4</tt><dd> if the position of compass is defined as Bottom-Right
   *  </dl>
   * @return
   *   S_OK if operation is successful
   *   <br> E_INVALIDARG if argument is NULL
   *   <br> E_FAIL if compass representation is destroyed or being destroyed
   */
  virtual HRESULT GetCorner(int * oCorner) = 0;

  /**
   * @nodoc : deprecated R216 SetDefaultPosition
   * All applications should have the same default corner
   * Defines the position of compass in the viewer.
   * @param iCorner
   * The corner to set.
   *  <br>
   *  <b>Legal values</b> It can be set to either :
   *  <dl>
   *  <dt><tt>1</tt><dd> to define the position of compass as Top-Left
   *  <dt><tt>2</tt><dd> to define the position of compass as Top-Right
   *  <dt><tt>3</tt><dd> to define the position of compass as Bottom-Left
   *  <dt><tt>4</tt><dd> to define the position of compass as Bottom-Right
   *  </dl>
   * @return
   *   S_OK if operation is successful
   *   <br> E_INVALIDARG if argument is NULL or pointing to an illegal value
   *   <br> E_FAIL if compass representation is destroyed or being destroyed
   */
  virtual HRESULT SetCorner(int * iCorner) = 0;

  /**
   * Defines the default position of compass in the viewer.
   * @return
   *   S_OK if operation is successful
   *   <br> E_FAIL if compass representation is destroyed or being destroyed
   */
  virtual HRESULT SetDefaultPosition() = 0;

  /**
   * Retrieves the compass auto snap state.
   * @param oEnabled
   *   Parameter is set to TRUE if compass is in auto snap mode, FALSE otherwise
   * @return
   *   S_OK if operation is successful
   */
  virtual HRESULT GetAutoSnapState(int * oEnabled) = 0;

  /**
   * Sets the auto snap state of the compass. Compass is automatically snapped onto the selected object while this mode is activated.
   * @param iState
   *  <br>
   *  <b>Legal values</b> It can be set to either :
   *  <dl>
   *  <dt><tt>TRUE</tt><dd> to activate the auto snap mode.
   *  <dt><tt>FALSE</tt><dd> to deactivate the auto snap mode.
   *  </dl>
   * @return
   *   S_OK if operation is successful
   */
  virtual HRESULT SetAutoSnapState(int * iState) = 0;

  /**
   * @nodoc
   * Edit panel management
   * Launch edit panel
   */
  virtual HRESULT Edit() = 0;

  /**
   * @nodoc
   * To be warned when compass editor is launched
   */
  virtual HRESULT GetEditOpenEvent(CATCallbackEvent * oEditOpenEvent) = 0;

  /**
   * @nodoc
   * To be warned when compass editor is closed
   */
  virtual HRESULT GetEditCloseEvent(CATCallbackEvent * oEditCloseEvent) = 0;

  /**
   * @nodoc
   * Most view plane mode management
   */
  virtual HRESULT SetMostViewPlaneState(int * Enabled) = 0; // 1 : enabled, 0 : disabled

  /** @nodoc */
  virtual HRESULT GetMostViewPlaneState(int * State) = 0; // 1 : enabled, 0 : disabled

  /** @nodoc */
  virtual HRESULT GetMostViewPlaneStateModifiedEvent(
    CATCallbackEvent * MostViewPlaneStateModifiedEvent) = 0;

  /** @nodoc */
  virtual HRESULT GetLockOrientationState(int * oEnabled) = 0;
  /** @nodoc */
  virtual HRESULT SetLockOrientationState(int * iState) = 0;

  /** @nodoc */
  virtual HRESULT GetScreenPlaneState(int * oEnabled) = 0;
  /** @nodoc */
  virtual HRESULT SetScreenPlaneState(int * iState) = 0;

  /** @nodoc */
  virtual HRESULT GetLocalAxisState(int * oEnabled) = 0;
  /** @nodoc */
  virtual HRESULT SetLocalAxisState(int * iState) = 0;

  /** @nodoc */
  virtual HRESULT GetDetectMoreState(int * oEnabled) = 0;
  /** @nodoc */
  virtual HRESULT SetDetectMoreState(int * iState) = 0;
};

CATDeclareHandler(CATI3DCompass, CATBaseUnknown);

#endif
