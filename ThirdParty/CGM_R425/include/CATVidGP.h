// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidGP.h
// Header definition of CATVidGP
//
//===================================================================
//
//  Oct 2005  Creation: Code generated by the CAA wizard  jov
//===================================================================
#ifndef CATVidGP_H
#define CATVidGP_H

#include <VisuDialog.h>
#include "CATVidMouseEventArgs.h"
#include <CATVidWidget.h>

#include <CATMathPointf.h>
#include <CATBoolean.h>
#include <CAT3DManipulator.h>
#include <CATVidMinMax.h>
#include <list.h>
#include <CATMathVector2Df.h>
#include <CATApplication.h>

class CAT4x4Matrix;
class CATGraphicAttributeSet;
class CATVidColor;
class CATMathTransformation;
class CAT3DCustomRep;
class CATGraphicMaterial;
class CATDeviceEvent;
class CATSYPProperties;
class CATRepWeakRef;
class CATVid3DManipulator;
class CATDrawRender;
class CATVidRGBA;

/**
* Base graphic primitive widgets. The classes inheriting it are the final node of the widget tree.
* They don't have a model/view representation, they are a representation.
* @ingroup VIDGP
*/
class ExportedByVisuDialog CATVidGP : public CATVidWidget
{
  CATDeclareClass;
public:
  /** Constructor. */
  CATVidGP();
  /**
  * Constructor.
  * @param i_useManipulatorFlag determine if the CATVidGP is connected
  * to a manipulator or not. If it is TRUE, the property PickFlag
  * must be 1 (default).
  * @see CATVidWidget#CATVidWidget
  * @see #SetPickFlag
  */
  CATVidGP(CATCommand *i_pParent, const CATString & i_pIdentifier, CATBoolean i_useManipulatorFlag);
  /**
  * Enables or not the manipulation of the GP
  */
  void SetUseManipulatorFlag(CATBoolean i_useManipulatorFlag);
  /**
  * @return the flag that indicates if the GP can be manipulated
  */
  CATBoolean GetUseManipulatorFlag() const;
  /**
  * Sets the flag that indicates if the GP can be picked
  */
  void SetPickFlag(CATBoolean i_pickFlag);
  /**
  * @return the flag that indicates if the GP can be picked
  */
  CATBoolean GetPickFlag() const;
  /**
  * Desaturation of the gp, i.e. if it should be drawed in black and white.
  * Default : FALSE.
  * @param i_desaturatedFlag
  *        Legal values :
  *        TRUE if desaturated
  *        FALSE otherwise.
  */
  void SetDesaturatedFlag(CATBoolean i_desaturatedFlag);
  /**
  * @see SetDesaturatedFlag
  */
  INLINE CATBoolean GetDesaturatedFlag() const
  {
    return _desaturatedFlag;
  }


  void SetGiveFocusOnDragFlag(CATBoolean i_giveFocusOnDragFlag);
  CATBoolean GetGiveFocusOnDragFlag()const;

  void SetGiveFocusOnHoldDragFlag(CATBoolean i_giveFocusOnHoldDragFlag);
  CATBoolean GetGiveFocusOnHoldDragFlag()const;

  CATBoolean GetGiveFocusOnDragState()const;

  void SetAcceptFocusOnDropFlag(CATBoolean i_acceptFocusOnDropFlag);
  CATBoolean GetAcceptFocusOnDropFlag()const;

  //---------------------------------------------------------------------------
  // GetManipulatorResultPoint : Return the position of the manipulator
  //---------------------------------------------------------------------------
  // public
  //---------------------------------------------------------------------------
  const CATMathPoint &GetManipulatorResultPoint() const;
  //---------------------------------------------------------------------------
  // GetTransformationMatrix : Get the transformation matrix of the last 
  //                           manipulation
  //---------------------------------------------------------------------------
  // public
  //---------------------------------------------------------------------------
  const CAT4x4Matrix& GetTransformationMatrix() const;
  //---------------------------------------------------------------------------
  // GetUseState : return the use state of the GP : 
  //               0 : not used
  //               1 : pressed
  //---------------------------------------------------------------------------
  // public
  //---------------------------------------------------------------------------
  unsigned int GetUseState() const;
  unsigned int GetState() const { return GetUseState(); };

  /**
  * @deprecated, use @ref GetConsumeDragOnHoldFlag instead
  */
  CATBoolean GetNoScrollOnDownHoldTouchFlag() const;
  /**
  * @deprecated, use @ref SetConsumeDragOnHoldFlag instead
  */
  void SetNoScrollOnDownHoldTouchFlag(CATBoolean i_noScrollOnDownHoldTouchFlag);

  /**
  * @name Notifications
  */
  /*@{*/
  /**
  * @return the GPPressed notification
  */
  CATNotification *GetGPPressNotification() const;
  /**
  * @return the GPDoubleClick notification
  */
  CATNotification *GetGPDoubleClickNotification() const;
  /**
  * @return the GPRightClick
  */
  CATNotification *GetGPRightClickNotification() const;
  /**
  * @return the the GPEndContext notification
  */
  CATNotification *GetGPEndContextNotification() const;
  /**
  * @return the GPDrag notification
  */
  CATNotification *GetGPDragNotification() const;
  /**
  * @return the GPMoveOver notification
  */
  CATNotification *GetGPMoveOverNotification() const;
  /**
  * @return the GPLeave notification
  */
  CATNotification *GetGPLeaveNotification() const;
  /**
  * @return the GPEntry notification
  */
  CATNotification *GetGPEntryNotification() const;
  /**
  * @return the GPRelease notification
  */
  CATNotification *GetGPReleaseNotification() const;
  /**
  * @return the GPMultiplePress notification
  */
  CATNotification *GetGPMultiplePressNotification() const;
  const char* GetGPPreDropNotification() const;
  const char* GetGPBeginPreDropNotification() const;
  const char* GetGPEndPreDropNotification() const;
  const char* GetGPDropNotification() const;

  /*@}*/

  /** @name Propagating Events
  * The propagating events dispatched by @ref CATVidGP instances.
  */
  /**@{*/

  /**
  * Get the @c Entry event.
  *
  * The @c Entry event is dispatched on the GP when the mouse enters
  * over the GP.
  *
  * This event is issued from the @ref CATManipulator event @ref
  * CATManipulator#GetCATPreactivate.
  *
  * @par EventProperties
  *   - Name: @c "Entry"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidMouseEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *Entry();

  /**
  * Get the @c Leave event.
  *
  * The @c Leave event is dispatched on the GP when the mouse leaves
  * the GP.
  *
  * This event is issued from the @ref CATManipulator event @ref
  * CATManipulator#GetCATEndPreactivate.
  *
  * @par EventProperties
  *   - Name: @c "Leave"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidMouseEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *Leave();

  /**
  * Get the @c Press event.
  *
  * The @c Press event is dispatched on the GP when the user press
  * the left button of the mouse over a GP. Note that pressing twice
  * the button may generate a @ref #DoubleClick event instead if the
  * second press is quick enough.
  *
  * This event is issued from the @ref CATManipulator event @ref
  * CATManipulator#GetCATActivate.
  *
  * @par EventProperties
  *   - Name: @c "Press"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidMouseEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *Press();

  /**
  * Get the @c Drag event.
  *
  * The @c Drag event is dispatched on the GP when the left button is
  * pressed and the mouse is dragged.
  *
  * This event is issued from the @ref CATManipulator event @ref
  * CATManipulator#GetCATManipulate.
  *
  * @par EventProperties
  *   - Name: @c "Drag"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidMouseEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *Drag();

  /**
  * Get the @c ReleaseEvt event.
  *
  * The @c ReleaseEvt event is dispatched on the GP when the left
  * button of the mouse is released.
  *
  * This event is issued from the @ref CATManipulator event @ref
  * CATManipulator#GetCATEndManipulate.
  *
  * @par Event Name Specificity
  * The function name is @c ReleaseEvt but the name seen by
  * introspection (i.e. returned by @ref
  * CATSYPEventDescriptor#GetName) and the debug name of the returned
  * event (i.e. returned by @ref CATSYPEvent#GetName) is @c
  * "Release".
  *
  * @par
  * This bypass was necessary since this event existed before the
  * creation of @ref CATSYPEvent events. As a consequence this was
  * not an issue when it was introduced to give it the name of an
  * existing function. Since the introspection name is used in @c
  * .sypstyle files it can't be changed easily. And the debug name
  * returned by @ref CATSYPEvent#GetName is used by @ref
  * CATSYPEventCompatHandler and can't also be changed.
  *
  * @par EventProperties
  *   - Name: @c "Release". Note that it is different than the
  *     function name since @c Release is already a member function
  *     of @ref CATBaseUnknown class. See above.
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidMouseEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *ReleaseEvt();

  /**
  * Get the @c DoubleClick event.
  *
  * The @c DoubleClick event is dispatched on the GP when the user
  * double-click with the left button of the mouse on a GP.
  *
  * This event is issued from the @ref CATManipulator event @ref
  * CATManipulator#GetCATEdit.
  *
  * @par EventProperties
  *   - Name: @c "DoubleClick"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidMouseEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *DoubleClick();

  /**
  * Get the @c DoubleRelease event.
  *
  * The @c DoubleRelease event is dispatched on the GP when the user
  * release the left button of the mouse on a GP after a
  * double-click.
  *
  * This event is issued from the @ref CATManipulator event @ref
  * CATManipulator#GetCATEndEdit.
  *
  * @par EventProperties
  *   - Name: @c "DoubleRelease"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidMouseEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *DoubleRelease();

  /**
  * Get the @c MoveOver event.
  *
  * The @c MoveOver event is dispatched on the GP when the mouse
  * pointer moves over a GP if the left mouse button is not clicked.
  *
  * This event is issued from the @ref CATManipulator event @ref
  * CATManipulator#GetCATMove.
  *
  * @par EventProperties
  *   - Name: @c "MoveOver"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidMouseEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *MoveOver();

  /**
  * Get the @c Wheel event.
  *
  * The @c Wheel event is dispatched on the GP when the mouse
  * pointer use its wheel over a GP. The left button can be pressed or not.
  *
  * This event is issued from the @ref CATManipulator event @ref
  * CATManipulator#GetCATMove.
  *
  * @par EventProperties
  *   - Name: @c "Wheel"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidMouseEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *Wheel();
  /**
  * Get the @c RightClick event.
  *
  * The @c RightClick event is dispatched on the GP when the right
  * mouse button is pressed over a GP.
  *
  * This event is issued from the @ref CATManipulator event @ref
  * CATManipulator#GetCATContext.
  *
  * @par EventProperties
  *   - Name: @c "RightClick"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidMouseEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *RightClick();

  /**
  * Get the @c EndContext event.
  *
  * The @c EndContext event is dispatched on the GP when the dialog
  * contextual menu displayed on the @ref #RightClick event is
  * closed.
  *
  * This event is issued from the @ref CATManipulator event @ref
  * CATManipulator#GetCATEndContext.
  *
  * @par EventProperties
  *   - Name: @c "EndContext"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATSYPEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *EndContext();

  /**
  * Get the @c MultiplePress event.
  *
  * The @c MultiplePress event is dispatched on the GP when the left
  * mouse button is kept pressed on a GP. This event is emitted every
  * 100ms by a timer.
  *
  * @par EventProperties
  *   - Name: @c "MultiplePress"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATSYPEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *MultiplePress();

  /**
  * Get the @c BeginPreDrop event.
  *
  * The @c BeginPreDrop event is dispatched on the GP when the GP
  * receives the @ref CATManipulator#GetCATBeginPreDrop notification
  * from the manipulator.
  *
  * This event is issued from the @ref CATManipulator event @ref
  * CATManipulator#GetCATBeginPreDrop.
  *
  * @par EventProperties
  *   - Name: @c "BeginPreDrop"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidDnDEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *BeginPreDrop();

  /**
  * Get the @c EndPreDrop event.
  *
  * The @c EndPreDrop event is dispatched on the GP when the GP
  * receives the @ref CATManipulator#GetCATEndPreDrop notification
  * from the manipulator.
  *
  * This event is issued from the @ref CATManipulator event @ref
  * CATManipulator#GetCATEndPreDrop.
  *
  * @par EventProperties
  *   - Name: @c "EndPreDrop"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidDnDEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *EndPreDrop();

  /**
  * Get the @c PreDrop event.
  *
  * The @c PreDrop event is dispatched on the GP when the GP
  * receives the @ref CATManipulator#GetCATPreDrop notification
  * from the manipulator.
  *
  * This event is issued from the @ref CATManipulator event @ref
  * CATManipulator#GetCATPreDrop.
  *
  * @par EventProperties
  *   - Name: @c "PreDrop"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidDnDEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *PreDrop();

  /**
  * Get the @c Drop event.
  *
  * The @c Drop event is dispatched on the GP when the GP
  * receives the @ref CATManipulator#GetCATDrop notification
  * from the manipulator.
  *
  * This event is issued from the @ref CATManipulator event @ref
  * CATManipulator#GetCATDrop.
  *
  * @par EventProperties
  *   - Name: @c "Drop"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidDnDEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *Drop();

  /**
  * Get the @c VisibilityAtReplay event.
  *
  * The @c VisibilityAtReplay event is dispatched on the GP during an
  * interaction replay if the GP visiblity (@ref
  * CATVidWidget#GetVisibleState) is different during replay than
  * during capture. It gives a chance to one of the parent of the GP
  * to make it visible or invisible before making the replay fail.
  *
  * After dispatching this event, if it has been consumed, the replay
  * infrastructure will try again to test the visiblity of the GP
  * before failing the test.
  *
  * <b>You must consume this event if you made the GP visible</b>;
  * the second test of visiblity won't be made if you change the
  * visibility without consuming this event.
  *
  * You must use @ref
  * CATVidVisibilityAtReplayArgs#GetExpectedVisibleState to know
  * which visible state was expected for @ref
  * CATVidVisibilityAtReplayArgs#GetOrigin. You can't assume that
  * origin current visible state is the complement of expected one
  * since other event handlers may have already modified it.
  *
  * @par EventProperties
  *   - Name: @c "VisibilityAtReplay"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidVisibilityAtReplayArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *VisibilityAtReplay();

  /**
  * Get the @c Hold event.
  *
  * The @c Hold event is dispatched on the GP when the left
  * mouse button of finger is kept pressed on a GP. This event is emitted once
  * after 200ms.
  *
  * @par EventProperties
  *   - Name: @c "Hold"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidMouseEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *Hold();

  /**
  * Get the @c LongHold event.
  *
  * The @c LongHold event is dispatched on the GP when the left
  * mouse button of finger is kept pressed on a GP. This event is emitted once
  * after 1s.
  *
  * @par EventProperties
  *   - Name: @c "LongHold"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidMouseEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *LongHold();

  /**
  * Get the @c Flick event.
  *
  * The @c Flick event is dispatched on the GP when the GP
  * interpreted a @ref VisFlickTouchGesture from the notification
  * received from the manipulator.
  *
  * @par EventProperties
  *   - Name: @c "Flick"
  *   - Type of propagation: @c OriginToRoot
  *   - Type of argument: @ref CATVidFlickEventArgs
  *
  * @return the event instance. @c AddRef has NOT been called on
  * the returned pointer.
  */
  static CATSYPEvent *Flick();
  /**@}*/

  /**
  * @deprecated use @ref CATVidGP::ReleaseEvt instead
  */
  static CATSYPEvent *TouchRelease();

  /**
  * @deprecated use @ref CATVidGP::Drag instead
  * @note
  * For now we use a parallel event TouchMove which mimics the Drag event in touch scenario.
  * we need it because the scrollable does not handle consumed drag, and we are not able to scroll
  * over buttons or to scroll when a scrollable is put in an other scrollable.
  * In order to remove it, we need an enhancement of vid events infrastructure.
  */
  static CATSYPEvent *TouchMove();

  /**
  * @copydoc CATVidWidget#Update
  */
  virtual void Update();
  /**
  * @copydoc CATVidWidget#TunnelInformation
  */
  virtual void TunnelInformation(const CATVidInformation& i_information);
  //---------------------------------------------------------------------------
  // SetDragLimits : Set absolute 2D square limit to manipulation. min values 
  //                   are top and left margins, max values are bottom and 
  //                   right margin
  //---------------------------------------------------------------------------
  // public
  //---------------------------------------------------------------------------
  /** @param i_squareLimits in density pixels (dp) */
  void SetDragLimits(const CATVidMinMax & i_squareLimits);
  /** @return density pixels (dp) */
  const CATVidMinMax &GetDragLimits() const;

  /**
  * Returns TRUE if the GP is under a drag interaction, FALSE otherwise.
  */
  CATBoolean GetDraggedState() const { return _draggedState; };

  virtual void* SendCommandSpecificObject(const char* i_pObjectClassNeeded, CATNotification * i_pNotification);

  /** @copydoc CATVidWidget#PreInteractionRecord */
  virtual int PreInteractionRecord(CATVidInteractionRecorderData &i_recorder);
  /** @copydoc CATVidWidget#PostInteractionRecord */
  virtual void PostInteractionRecord(CATVidInteractionRecorderData &i_recorder, const CATSYPProperties &i_delayedRecordingData);
  /** @copydoc CATVidWidget#InteractionReplay */
  virtual void InteractionReplay(CATVidInteractionReplayerData &i_replayer);
  /**
  * Sets a flag indicating that the manipulator of the GP is standalone, that is it can be activated and manipulated in the same time that another one.
  * In this mode the DoubleClick and DoubleRelease events will not be sent when 2 manipulators are activated.
  * This mode is ignored in record mode.
  */
  void SetStandaloneManipulatorFlag(int i_standaloneManipulatorFlag);
  /** @return the StandaloneManipulatorFlag */
  int GetStandaloneManipulatorFlag() const;
  /**
  * @return a rgba color from a CATVidColor. The CATVidColor is contextual to the widget branch it is related.
  */
  void GetColorRGBA(const CATVidColor& i_color, CATVidRGBA& o_rgba) const;

  static int GetTouchReleaseFlag() { return _touchReleaseFlag; };

protected:
  /** Constructor. */
  CATVidGP(CreateLetterFunc i_pCreateLetterFunc);
  /**
  * Constructor.
  * @param i_useManipulatorFlag determine if the CATVidGP is connected
  * to a manipulator or not. If it is TRUE, the property PickFlag
  * must be 1 (default).
  * @see CATVidWidget#CATVidWidget
  * @see #SetPickFlag
  */
  CATVidGP(CATCommand *i_pParent, const CATString & i_pIdentifier, CATBoolean i_useManipulatorFlag, CreateLetterFunc i_pCreateLetterFunc);
  /** Destructor */
  virtual ~CATVidGP();
  //---------------------------------------------------------------------------
  // GetColorInitFlag : Get the flag indicating if main window colors are initialized
  //---------------------------------------------------------------------------
  // protected
  //---------------------------------------------------------------------------
  CATBoolean GetColorInitFlag() const;
  //---------------------------------------------------------------------------
  // BuildRep : Build the representation of the GP
  //---------------------------------------------------------------------------
  virtual HRESULT BuildRep();
  virtual HRESULT BuildMaterial();
  /** @copydoc CATVidWidget#UpdateComputedMinimumDimension */
  virtual void UpdateComputedMinimumDimension();


  HRESULT GetMainColors(unsigned char& o_r, unsigned char& o_g, unsigned char& o_b, unsigned char& o_foregroundR, unsigned char& o_foregroundG, unsigned char& o_foregroundB);

  void SetGasColor(CATGraphicAttributeSet& o_gas, const CATVidColor& i_color);
private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidGP(const CATVidGP &);
  CATVidGP& operator=(const CATVidGP&);

  void AssignMaterialToRep();
  CATBoolean GetDeactivateManipulator();

  void OnEntry();
  void OnLeave();
  void OnPress(CATBoolean i_NoTimer = FALSE);
  void BeginDrag();
  /** @param i_transformation in device-independant pixels (dp) */
  void OnDrag(const CATMathTransformation &i_transformation);
  void MouseRelease();
  void OnDoubleClick();
  void OnDoubleRelease();
  void OnMoveOver();
  int OnWheel();
  void OnRightClick();
  void OnEndContext();
  void OnMultiplePress();
  void OnHold();
  void OnLongHold();

  void OnPreactivateCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnEndPreactivateCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnActivateCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnEndActivateCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnBeginManipulateCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnManipulateCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnEndManipulateCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnEditCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnEndEditCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnMoveCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnContextCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnEndContextCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnBeginPreDropCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnPreDropCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnEndPreDropCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnDropCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);
  void OnWheelCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData);

  void OnEndPreactivate(CATNotification *i_pNotification, const int i_nextIsVID);

  /** Replay function for interaction replay protocol that handles the Preactivate mouse event */
  void InteractionPreactivateReplay(CATVidInteractionReplayerData &i_replayer);
  /** Replay function for interaction replay protocol that handles the EndPreactivate mouse event */
  void InteractionEndPreactivateReplay(CATVidInteractionReplayerData &i_replayer);
  /** Replay function for interaction replay protocol that handles the Activate mouse event */
  void InteractionActivateReplay(CATVidInteractionReplayerData &i_replayer);
  /** Replay function for interaction replay protocol that handles the EndActivate mouse event */
  void InteractionEndActivateReplay(CATVidInteractionReplayerData &i_replayer);
  /** Replay function for interaction replay protocol that handles the BeginManipulate mouse event */
  void InteractionBeginManipulateReplay(CATVidInteractionReplayerData &i_replayer);
  /** Replay function for interaction replay protocol that handles the Manipulate mouse event */
  void InteractionManipulateReplay(CATVidInteractionReplayerData &i_replayer);
  /** Replay function for interaction replay protocol that handles the EndManipulate mouse event */
  void InteractionEndManipulateReplay(CATVidInteractionReplayerData &i_replayer);
  /** Replay function for interaction replay protocol that handles the Edit mouse event */
  void InteractionEditReplay(CATVidInteractionReplayerData &i_replayer);
  /** Replay function for interaction replay protocol that handles the EndEdit mouse event */
  void InteractionEndEditReplay(CATVidInteractionReplayerData &i_replayer);
  /** Replay function for interaction replay protocol that handles the Move mouse event */
  void InteractionMoveReplay(CATVidInteractionReplayerData &i_replayer);
  /** Replay function for interaction replay protocol that handles the Wheel mouse event */
  void InteractionWheelReplay(CATVidInteractionReplayerData &i_replayer);
  /** Replay function for interaction replay protocol that handles the Context mouse event */
  void InteractionContextReplay(CATVidInteractionReplayerData &i_replayer);
  /** Replay function for interaction replay protocol that handles the EndContext mouse event */
  void InteractionEndContextReplay(CATVidInteractionReplayerData &i_replayer);

  /** Replay ODT & PageObject - Simulate an "Left Mouse Button Activate" mouse event  */
  void OnPuppetedLeftPress(CATBoolean i_DebugBubble = FALSE, CATBoolean i_NoTimer = FALSE);
  /** Replay ODT & PageObject - Simulate an "Release" mouse event  */
  void OnPuppetedRelease(CATBoolean i_DebugBubble = FALSE);
  /** Replay ODT & PageObject - Simulate an "MoveOver" mouse event  */
  void OnPuppetedMoveOver(CATBoolean i_DebugBubble = FALSE);
  /** Replay ODT & PageObject - Simulate an "Entry" mouse event  */
  void OnPuppetedEntry(CATBoolean i_DebugBubble = FALSE);
  /** Replay ODT & PageObject - Simulate an "Leave" mouse event  */
  void OnPuppetedLeave(CATBoolean i_DebugBubble = FALSE);
  /** Replay ODT & PageObject - Simulate an "Edit" mouse event (DoubleClick)  */
  void OnPuppetedEdit(CATBoolean i_DebugBubble = FALSE);
  /** Replay ODT & PageObject - Simulate an "Wheel" mouse event  */
  void OnPuppetedWheel(CATBoolean i_DebugBubble = FALSE);
  /** Replay ODT & PageObject - Simulate an "Right Mouse Button Activate" mouse event  */
  void OnPuppetedRightPress(CATBoolean i_DebugBubble = FALSE);
  /** Replay ODT & PageObject - Simulate an "Right Mouse Button Release" mouse event  */
  void OnPuppetedRightRelease(CATBoolean i_DebugBubble = FALSE);
  /** Replay ODT & PageObject - Simulate an "Left Mouse Button Hold Press" mouse event  */
  void OnPuppetedHoldPress(CATBoolean i_DebugBubble = FALSE);
  /** Replay ODT & PageObject - Simulate an "Left Mouse Button LongHold Press mouse event  */
  void OnPuppetedLongHoldPress(CATBoolean i_DebugBubble = FALSE);

  /**
  * Call @ref CATBubbleDebug#DrawMouseDebug to draw (if activated)
  * the bubble debug mouse position.
  *
  * The viewer used will be extracted from the @ref
  * CATVidManipulatorInteractionCapture if available.
  *
  * @note
  * Bubble debug is activated by @c CATRecordVisualDebug
  * environment variable.
  *
  * @param x the x coordinate in window space
  * @param y the y coordinate in window space
  */
  void DrawBubbleDebugMouse(int i_x, int i_y);
  /**
  * Call @ref CATBubbleDebug#DrawBubbleDebug to draw (if activated)
  * the bubble.
  *
  * The viewer used will be extracted from the @ref
  * CATVidManipulatorInteractionCapture if available.
  *
  * @note
  * Bubble debug is activated by @c CATRecordVisualDebug
  * environment variable.
  *
  * @param i_string the string to draw
  * @param i_setToLastPosition
  * @param i_duration
  * @param i_x
  * @param i_y
  */
  void DrawBubbleDebugBubble(const CATUnicodeString &i_string,
    int i_setToLastPosition = 0,
    int i_duration = 2000,
    int i_x = -1,
    int i_y = -1);

  void ConnectRepToManipulator();
  void CreateManipulator();

  /**
  * Confine the translation on a specific axis accoring to the translation limits given. Whatever the GP position (VID or 3D scene through V3D),
  * @param i_beforeTransformation Point stored before the current transformation
  * @param i_afterTransformation Theorical point that should be the new position if no limits had been set
  * @param i_referenceValue Initial position when the GP was activated
  * @param i_minFromReference First vector pointing out the maximum translation allowed starting from i_startPoint
  * @param i_maxFromReference Second vector pointing out the maximum translation allowed starting from i_startPoint
  * @param io_translationValue Translation of the current  transformation.
  */
  void ConfineTranslationToLimits(double i_beforeTransformation, double i_afterTransformation, double i_referenceValue, double i_minFromReference, double i_maxFromReference, double& io_translationValue);
  /**
  * Confine the translation accoring to the translation limits given. Whatever the GP position (VID or 3D scene through V3D),
  * the valeus are expressed in density pixels (dp).
  * @param i_beforeTransformationPoint Point stored before the current transformation
  * @param i_newPoint Theorical point that should be the new position if no limits had been set
  * @param i_startPoint Initial position when the GP was activated
  * @param i_translationLimit1 First vector pointing out the maximum translation allowed starting from i_startPoint
  * @param i_translationLimit2 Second vector pointing out the maximum translation allowed starting from i_startPoint
  * @param io_translation Translation of the current  transformation.
  */
  void ConfineTranslation(const CATMathPoint& i_beforeTransformationPoint, const CATMathPoint& i_newPoint, const CATMathPoint& i_startPoint, CATMathVector& i_translationLimit1, CATMathVector& i_translationLimit2, CATMathVector& io_translation);

  static void Timer(void *iData);
  void OnTimer();

  static void LongTimer(void *iData);
  void OnLongTimer();

  /**
  * Method called when CATVidInfo_Disable is received to
  * handle the case where the CATVidGP is disabled while pressed.
  */
  void OnDisable();

  void ComputeRefColors();

  void UpdateManipulator();

  CATBoolean GetIsInV3D();

private:
  void AddTimer(CATBaseUnknown_WR& i_timerGPWR, int i_duration, CATSysTimeOutCB i_callback);
  void CleanTimer(CATBaseUnknown_WR& i_timerGPWR, int i_duration, const CATUnicodeString& i_message, bool i_needToRemoveTimer);

  CATDeviceEvent *GetDeviceEvent();

  /**
  * Returns TRUE if the CATVidGP must change the mouse cursor on entry, FALSE otherwise.
  */
  CATBoolean MustChangeCursor() const;

  /**
  *  Current Transaction type of the GP
  *  3 types  : StandardTransactionType, ScrollTransactionType, DnDTransaction
  *  See CATVidMouseEventArgs for the enumeration of differents types
  */
  static CATVidInputEventArgs::TransactionType _eTypeTransaction;

  /**
  * Flag that indicates if the action was sent in touch or not on release
  */
  static int _touchReleaseFlag;

private:

  class CATVidGPManipulator
  {
  public:

    CATVidGPManipulator();
    ~CATVidGPManipulator();

  public:

    CATVid3DManipulator * _pManipulator;
    CATMathTransformation _3Dtransformation;
    CAT4x4Matrix * _pMatrixToGive; // In device independant pixels
    // In device independant pixels, it corresponds to the coordinates to give to the callees and is 
    // the distance between the pick position and the topLeft corner of the GP (bounded if _useSquareLimitFlag is true)
    CATMathPoint _pointToGive;
    // In device independant pixels, it corresponds to the coordinates of the pick position
    CATMathPoint _manipulatorResultPoint;
    // In device independant pixels, it corresponds to the coordinates of the Press position
    CATMathPoint _activatePoint;
    CATVidMinMax _translationArea; // area, in absolute base, that limits the draging capability of the GP. In device independant pixels
  };

  CATVidGPManipulator* _pGPManipulator;
  unsigned int _backgroundR : 8;
  unsigned int _backgroundG : 8;
  unsigned int _backgroundB : 8;
  unsigned int _foregroundR : 8;
  unsigned int _foregroundG : 8;
  unsigned int _foregroundB : 8;
  unsigned int _useFirstLimitFlag : 1;
  unsigned int _useSecondLimitFlag : 1;
  unsigned int _useSquareLimitFlag : 1;
  unsigned int _firstRepeat : 1;
  unsigned int _secondRepeat : 1;
  unsigned int _colorInitFlag : 1;
  unsigned int _toEndPreactivate : 1;
  unsigned int _giveFocusOnDragFlag : 1;
  unsigned int _giveFocusOnHoldDragFlag : 1;
  unsigned int _acceptFocusOnDropFlag : 1;
  unsigned int _desaturatedFlag : 1;
  unsigned int _useState : 1;
  unsigned int _draggedState : 1; // flag that indicates is the GP has been dragged
  unsigned int _hold : 1; // flag that indicates is the press on this GP is hold
  unsigned int _noScrollOnDownHoldTouchFlag : 1; // don't send TouchScroll event if GP is hold - to remove
  unsigned int _activatedGP : 1;
  /**
  * Flag that indicates if the release event is a true release (if the finger is up of if the left button of the mouse is up)
  */
  unsigned int _trueReleaseFlag : 1;
  unsigned int _koForInteractionRecordFlag : 1;

  //To force GP activation with Line/Text editor focus taking by code.
  int GetActivationStatus() const;

  //unsigned int _consumeDragOnHoldFlag:2; // the proper way would be to consume Drag event when hold

  /** the last mouse motion during a replay */
  CATMathVector _lastReplayedMove;
  /** the last mouse position in the 3D content referential */
  CATMathPoint2Df _lastAbsolutePositionIn3DContentReferential;
protected:
  ::list <CATGraphicMaterial> _materialList;

  //-----------------------------------------------------------------------------
  // Friend class
  //-----------------------------------------------------------------------------
private:
  friend class l_CATVidGP;
  friend class l_CATVidGPTexturedWidget;
  friend class l_CATVidGPLine;
  friend class l_CATVidGPNinePatchSquare;
  friend class l_CATVidGPPolygon;
  friend class l_CATVidGPRuler;
  friend class l_CATVidGPSmartSquare;
  friend class l_CATVidGPSquare;
  friend class l_CATVidGPTriangle;
  friend class l_CATVidCtlViewer;
  friend class CATVidVisitor_BufferedDraw;
  friend class CATVidVisitor_Pick;
  friend class l_CATVidEditorBase;
  friend class CATVidFraActivator;

	//For ODT (Simulate the GP drag)
	friend class CATVidTstUtilities;
	//For ODT
  friend class CATVidGPTST;

  //For PageObject (Simulate Press, Release, MoveOver etc...) 
  friend class CATVidGPAutomation;

  //++DEPRECATED
public:
  const char *GetGPPressNotificationName() const;
  //--DEPRECATED
  friend class CATVidDynamicGP_BufferedDraw;
  friend class MainManipCommand;
};

//-----------------------------------------------------------------------
#endif
