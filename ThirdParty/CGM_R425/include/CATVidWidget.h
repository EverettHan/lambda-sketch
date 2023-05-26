// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidWidget.h
// Header definition of CATVidWidget
//
//===================================================================
//
//  Oct 2005  Creation: jov
//===================================================================
#ifndef CATVidWidget_H
#define CATVidWidget_H

#include <VisuDialog.h>
#include <CATCommand.h>
#include <CATUnicodeString.h>
#include <CATMathPoint2Df.h>
#include <CATMathInline.h>
#include <CATVidEnum.h>
#include <CATVidInformation.h>
#include <CATVidColor.h>
#include <CATSysMacros.h>
#include <CATVidCursor.h>
#include <CATVidPalette.h>
#include <CATBaseUnknown_WR.h>

//-----------------------------------------------------------------------
class CATDialog;
class CAT4x4Matrix;
class CATVizViewer;
class CAT3DViewpoint;
class l_CATVidWidget;
class CATSYPMappingTablePointerToPointer;
class CATSYPProperties;
class CATVidInteractionRecorderData;
class CATVidInteractionReplayerData;
class CATSYPEventHandler;
class CATSYPEvent;
class CATSYPEventArgs;
class CATSYPEventFactory;
class CATVidDnDTransferHandler;
class CATMathDirectionf;

class l_CATVidWidget;
class CATVidWidget;
typedef l_CATVidWidget* (* CreateLetterFunc)(CATVidWidget&);
//-----------------------------------------------------------------------
/**
 * @ingroup VIDCore
 */
/**
 * Base class for widgets.
 * Destroy a CATVidWidget by calling RequestDelayedDestruction.
 * Listen CATVID_WIDGET_DESTRUCTION_REQUESTED if you need to be 
 * advised of the destruction of a widget, or use a CATBaseUnknown_WR.
 */
class ExportedByVisuDialog CATVidWidget: public CATCommand
{
  CATDeclareClass;
  /**
   * Declare a Callback when the dimension of the widget has changed
   */
  CATDeclareCBEvent(CATVID_DIMENSION_MODIFIED);
  /**
   * Declare a Callback sent whenever RequestDelayedDestruction 
   * is called on the widget.
   */
  CATDeclareCBEvent(CATVID_WIDGET_DESTRUCTION_REQUESTED);

  /**
   * This class allows to prevent a widget instance to send event during its lifetime.
   * {
   *   CATVidWidget::DispatchEventLocker locker(myWidget);
   *   myWidget->DoSomething(); // will not trigger any event from this instance.
   * }
   * myWidget->DoSomething(); // will trigger events from this instance.
   */
  class ExportedByVisuDialog DispatchEventLocker
  {
  public:
    DispatchEventLocker(CATVidWidget *i_pLetterWidget);
    ~DispatchEventLocker();
  private:
    void* operator new(size_t size); // restrict dynamic allocation
    DispatchEventLocker(const DispatchEventLocker& );
    DispatchEventLocker &operator=(const DispatchEventLocker &);
    CATBaseUnknown_WR _widgetWR;
  };

public:

  /**
   * This call allows to impose the dimension of a widget to its hierarchy.
   * It will first set the i_dimension as the ResquestedMinimumDimension of the widget, 
   * top reset them to the previous one. If there is no compacity mechanisms in the hierarchy, 
   * the dimension of the containers will be updated without modifying their minimum dimension.
   */
  static void TryToForceDimensionOnHierarchy(CATVidWidget* i_pWidget, const CATMathPoint2Df& i_dimension);
  /** @name Propagating Events
   * The propagating events dispatched by @ref CATVidWidget instances.
   */
  /**@{*/

  /** Get the @c MinimumDimensionChanged event.
   *
   * The @c MinimumDimensionChanged event is emitted by CATVidWidget 
   * after the minimum dimension has changed.
   * 
   * @par EventProperties
   *   - Name: @c "MinimumDimensionChanged"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATSYPEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on the 
   * returned pointer. 
   */
  static CATSYPEvent * MinimumDimensionChanged();

  /**
   * Get the @c MouseEnter event.
   *
   * The @c MouseEnter event is emitted when the mouse enters a
   * manipulable @ref CATVidGP (i.e. @ref
   * CATVidGP#GetUseManipulatorFlag is true) that is this widget or
   * one of its descendants. The event is not dispatched if the mouse
   * moves from one of its descendant to an other one.
   *
   * This event is emitted after @ref CATVidGP#Entry.
   *
   * This event is always dispatched after the @ref #MouseLeave events
   * for the same mouse move.
   * 
   * It does not propagate but due to its specification it may be
   * dispatched on several widgets that are in the parenthood of the
   * entered @ref CATVidGP and that have not yet been entered. When
   * multiple widgets are called for the same move, the widgets are
   * called in root to leaf order.
   *
   * The parenthood is frozen before first @ref #MouseLeave is
   * dispatched, and as consequence before @ref CATVidGP#Entry is
   * emitted, so changes to the widget tree in the handlers of those
   * events don't impact the called widgets for this event.
   *
   * Contrary to @ref CATVidGP#Entry this event is dispatched when the
   * manipulable @ref CATVidGP is disabled (i.e. @ref
   * CATVidWidget#GetEnableState is false).
   *
   * As for @ref CATVidGP#Entry, this event is not dispatched when the
   * left mouse button of the mouse is pressed due to the capture of
   * the mouse by the pressed manipulator. When the left mouse button
   * is released @ref #MouseLeave and @ref #MouseEnter events are
   * dispatched according to the manipulable @ref CATVidGP under the
   * mouse.
   *
   * @par EventProperties
   *   - Name: @c "MouseEnter"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidMouseEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   *
   * @see #GetMouseHoveringState
   */
  static CATSYPEvent * MouseEnter();

  /**
   * Get the @c MouseLeave event.
   *
   * The @c MouseLeave event is emitted when the mouse leaves a
   * manipulable @ref CATVidGP (i.e. @ref
   * CATVidGP#GetUseManipulatorFlag is true) that is this widget or
   * one of its descendants. The event is not dispatched if the mouse
   * moves from one of its descendant to an other one.
   * 
   * This event is emitted after @ref CATVidGP#Leave but before @ref
   * CATVidGP#Entry if one is expected for the same mouse move.
   *
   * This event is always dispatched before the @ref #MouseEnter
   * events for the same mouse move.
   * 
   * It does not propagate but due to its specification it may be
   * dispatched on several widgets that are in the parenthood of the
   * left @ref CATVidGP and that have not yet been left. When
   * multiple widgets are called for the same move, the widgets are
   * called in leaf to root order.
   *
   * The parenthood is frozen before first @ref #MouseLeave is
   * dispatched, and as consequence after @ref CATVidGP#Leave is
   * emitted, so changes to the widget tree in the handlers of @ref
   * CATVidGP#Leave impact the called widgets for this event but
   * changes in handler of @ref #MouseLeave have no impact.
   *
   * Contrary to @ref CATVidGP#Leave this event is dispatched when the
   * manipulable @ref CATVidGP is disabled (i.e. @ref
   * CATVidWidget#GetEnableState is false).
   *
   * As for @ref CATVidGP#Leave, this event is not dispatched when the
   * left mouse button of the mouse is pressed due to the capture of
   * the mouse by the pressed manipulator. When the left mouse button
   * is released @ref #MouseLeave and @ref #MouseEnter events are
   * dispatched according to the manipulable @ref CATVidGP under the
   * mouse.
   *
   * @par EventProperties
   *   - Name: @c "MouseLeave"
   *   - Type of propagation: @c NoPropagation
   *   - Type of argument: @ref CATVidMouseEventArgs
   *
   * @return the event instance. @c AddRef has NOT been called on
   * the returned pointer.
   *
   * @see #GetMouseHoveringState
   */
  static CATSYPEvent * MouseLeave();
  /*@}*/ 

public:
  /**
   * Destroys the widget.
   * @see CATCommand#RequestDelayedDestruction
   */
  virtual void RequestDelayedDestruction();
  /**
   * @see CATBaseUnknown#Release 
   */
  virtual ULONG __stdcall Release();
  /**
   * Set the dimension of the widget requested by the customer. 
   * Conditionned by the computed minimum dimension.
   * The dimension of a widget are computed by layout, and thus, should
   * never be called directly. Call SetRequestedMinimumDimension to ensure 
   * the widget to take a minimum place on screen.
   * @param i_dimension the wished dimension
   */
  void SetDimension( const CATMathPoint2Df &i_dimension );
  /**
   * @return  the effective dimension, and update it if necessary 
   * by updating computed minimum dimension. Thus, it is a NON const method.
   */
  const CATMathPoint2Df& GetDimension();
  /**
   * Call internally SetRequestedMinimumDimension. This method is not well 
   * named, as it doesn't represent a property with its assiociated method 
   * GetMinimumDimension. SetMinimumDimension set a requested minimum 
   * dimension. GetMinimumDimension returns the union of the requested minimum
   * dimension and the computed minimum dimension.
   * In Stylesheets, you won't be able to call SetMinimumDimension (this property
   * is Read-Only), use RequestedMinimumDimension instead.
   * @param i_dimension the requested minimum dimension.
   * @see SetRequestedMinimumDimension
   * @see GetComputedMinimumDimension
   */
  void SetMinimumDimension(const CATMathPoint2Df& i_dimension);
  /**
   * Sets the requested minimum dimension. This ensure that the widget will have
   * at least  these dimension. But the real minimum dimension will be the union
   * between the requested and the computed ones. 
   * @param i_dimension the requested minimum dimensions.
   * @see GetComputedMinimumDimension
   */
  void SetRequestedMinimumDimension(const CATMathPoint2Df& i_dimension);
  /** 
   * @return the requested minimum dimension. Call GetMiniumDimension to recover
   * the effective minimum dimension.
   */
  const CATMathPoint2Df& GetRequestedMinimumDimension() const;
  /**
   * @return the union of the requested minimum dimension and the computed
   * minimum dimension. If the computed minimum dimension are not up to date, 
   * it will involve their computation. Thus, the function is not const.
   */
  const CATMathPoint2Df& GetMinimumDimension();
  /**
   * Sets the visibility flag of a widget. An unvisible widget will participate
   * to the layout depending on the LayoutWhenUnvisibleFlag property. 
   * A widget can have its visible flag to TRUE but not being visible on screen,
   * if one of its parent is not visible. To have the information about visibility
   * state of a widget, call GetVisibleState.
   * @see SetLayoutWhenUnvisibleFlag
   * @see GetConnectedFlag().
   */
  void SetVisibleFlag( CATBoolean i_visibleFlag);
  /**
   * @return the visible flag of a widget.
   */
  CATBoolean GetVisibleFlag() const;
  /**
   * @return the visible state of a widget, that is, TRUE if all its parents and 
   * himself are visible
   */
  CATBoolean GetVisibleState() const;

  /**
   * @return the visible state of a widget stopping at a parent Widget, that is, 
   * TRUE if all its parents up to the ipStoppingWidget and himself are visible
   */
  CATBoolean GetVisibleInWidgetState(CATVidWidget * ipStoppingWidget) const;
  /**
   * @return the viewer currently embedding the widget.
   */
  CATVizViewer* GetViewer() const;
  /**
   * Gets the relative position of the widget, in pixel. To recover the absolute position
   * of a widget, call GetRelativeToAbsoluteMatrix.
   * @param o_x the x position from left side of parent widget.
   * @param o_y the y position from top side of parent widget.
   */
  void GetPosition (float&  o_x, float& o_y) const;
  /**
   * Recursive call that computes transformation matrix from 
   * absolute to relative position.
   * @param the matrix to compute.
   */
  void GetAbsoluteToRelativeMatrix(CAT4x4Matrix& ioMatrix, const CATVidWidget* const i_FatherWidgetToStopTo=NULL) const;
  /**
   * Recursive call that computes transformation matrix from 
   * relative to absolute position.
   * @param the matrix to compute.
   */
  void GetRelativeToAbsoluteMatrix(CAT4x4Matrix& ioMatrix, const CATVidWidget* const i_FatherWidgetToStopTo=NULL) const;
	/**
   * Retrieves the transformation matrix relative to the viewer associated to the widget.
   * @param the matrix to compute.
   */
  void GetRelativeToAssociatedViewerMatrix(CAT4x4Matrix& ioMatrix) const;
	/**
   * Retrieves the transformation matrix used to position the viewer associated to the widget.
   * @param the matrix to compute.
   */
  void GetAssociatedViewerMatrix(CAT4x4Matrix& ioMatrix) const;
  /**
   * Allows to layout the  widget when unvisible. If this flag is 
   * TRUE (default), the father container will take into account the dimensions
   * of the widget in its layout computations. Otherwise, it will considered as
   * not present in the layout.
   * @param i_layoutWhenUnvisibleFlag is a boolean. Default value is TRUE.
   */
  void SetLayoutWhenUnvisibleFlag( CATBoolean i_layoutWhenUnvisibleFlag);
  /**
   * @return a flag indocating if the widget must be layouted when invisible.
   */
  CATBoolean GetLayoutWhenUnvisibleFlag() const;

    /**
   * Allows to layout the  widget when rotated. If this flag is 
   * TRUE (default), the father container will take into account the dimensions
   * of the widget after rotation in its layout computations. Otherwise, it will considered as
   * not rotated in the layout.
   * @param i_postTransformLayout is a boolean. Default value is TRUE.
   */
  void SetPostTransformLayoutFlag( CATBoolean i_postTransformLayoutFlag);
  
  /**
  * @return a flag indicating if the widget must be layouted after rotation.
  * by default the flag is set to FALSE.
  */
  CATBoolean GetPostTransformLayoutFlag() const;

  /**
   * Sets the flag modifying the enable state of the widget.
   * A widget can have its enable flag to TRUE but not being enabled on screen,
   * if one of its parent is not enabled. To have the information about enability (?)
   * state of a widget, call GetEnableState.
   * @param i_enableFlag the enable flag to set on the widget.
   */
  void SetEnableFlag(CATBoolean i_enableFlag);
  /**
   * @return the enable flag of a widget.
   */
  CATBoolean GetEnableFlag() const;
  /**
   * @return the enable state of a widget that is, TRUE if all its parents and 
   * himself are enabled
   */
  CATBoolean GetEnableState() const;
  /**
   * Recover a physical color from a role. 
   * @param i_role the logical role from which the color is retrieved.
   * @param o_physicalColor the color to retrieve.
   * @see CATVidPalette
   */
  int GetPhysicalColorFromRole(CATVidPalette::ColorRole i_role, CATVidRGB& o_physicalColor) const;
  /**
   * Determines usage or not of the default keyboard manipulation of the widget
   * e.g : space for CtlButton, arrows for scrollable...
   * @param i_keyboardManipulationFlag a boolean controlling the property.
   */
  void SetKeyboardManipulationFlag( CATBoolean i_keyboardManipulationFlag);
  /**
   * @return if the widget can be manipulated by keyboard.
   * This flag deal with keyboard focus.
   */
  CATBoolean GetKeyboardManipulationFlag() const;
  /**
   * Virtual method that dispatch an information to all the widget tree.
   * Internal function, do not call it directly.
   * @param i_information an enum value representing 
   * the type of information to dispatch.
   * @see CATVidContainer#GetBroadcastToChildFlag
   */
  virtual void TunnelInformation(const CATVidInformation& i_information);
  /**
   * Updates the widget. Will launch an update of all deprecated 
   * state of the widget tree. Can be computed minimum dimension update, layout
   * update, appearence update. This function is overloaded especially 
   * by layouts and graphic representations (CATVidGP).<br>
   * Internal function, do not call it directly.
   */
  virtual void Update();
  /**
   * Returns the father widget of the widget. That is the container that 
   * contains it. In VID, all the created widgets below to a container 
   * (CATVidCtl or CATVidLayCollection). By calling CATVidCtl::SetEmbeddedWidget
   * or CATVidLayCollection::SetConstraints on a layout, the container assign 
   * himself as father of the widget. This has not to be the CATCommand father, 
   * as the notifications tree is fully different of the widget tree in VID.
   * @return the father widget of the widget. 
   */
  CATVidWidget* GetFatherWidget() const;
  /**
   * Points out if the widget need broacast informations about position, as 
   * CATVidClippingUse, CATVidConnectionChange and CATVidFatherPositionChange.
   * If it is not set, the widget will not recieve these informations, that can
   * be costfull to broadcast continously. If a widget declare this flag, all its
   * widget tree (from itself to the top) will be informed of this need, so if one
   * of this paramters is modified on one of its father widgets, the corresponding 
   * information will be broadcated.
   * @param i_embedExternalDialogFlag the flag indicating if informations 
   * must be broadcated.
   */
  void SetEmbedExternalDialogFlag(CATBoolean i_embedExternalDialogFlag);
  /**
   * @return the flag indicating if informations about position, as 
   * CATVidClippingUse, CATVidConnectionChange and CATVidFatherPositionChange
   * must be broadcated to the widget.
   */
  CATBoolean GetEmbedExternalDialogFlag() const;

  /**
   * Implementation of CATISYPResource, that deals with internationalization.
   * @see CATISYPResource#GetResourceFilename.
   */
  virtual char* GetResourceFilename(int i_depth) const;
  /**
   * Implementation of CATISYPResource, that deals with internationalization.
   * @see CATISYPResource#GetResourceID
   */
  CATString& GetResourceID();
  /**
   * @return the VID record level. internal use only.
   */
  unsigned int GetVidRecordLevel();
  /**
   * @return the internal component l_CATVidWidget.
   */
  INLINE l_CATVidWidget& GetVidLetter() const;
  /** @ingroup groupVidRecord
   * Get the father for the interactions recording protocol.
   * See @ref CATVidInteractionRecorderData documentation for details
   * about this protocol.
   * @note
   * This function is virtual, the default implementation simply
   * delegates this call to @ref #GetFatherWidget.<br/>
   * If a sub-class overrides this function it does not have to
   * call this default implementation.
   * @warning
   * If a sub-class overrides this function, it should clearly
   * document this behavior in the class documentation.
   * @return the father widget. Note that @ref CATBaseUnknown#AddRef
   * has not been called on the return value consequently it must not
   * be released by the caller.
   * @see CATVidInteractionRecorderData
   */
  virtual CATVidWidget *GetRecordingFather();
  /** @ingroup groupVidRecord
   * Check if this component is the responsible widget for the recording
   * of an interaction.
   *
   * This component will be considered to be the responsible widget for
   * the interaction if it calls either @ref CATVidInteractionRecorderData#RecordInteraction 
   * or @ref CATVidInteractionRecorderData#DelayRecordInteraction on
   * @a i_recorder object.
   *
   * See details about the interaction recording algorithm in the 
   * documentation of the class CATVidInteractionRecorderData.
   *
   * @note
   * The default implementation is not empty and may be called by the
   * children class to support default behaviors (for example default
   * keyboard handling).
   *
   * @param i_recorder the recorder. Call either @c RecordInteraction or
   * @c DelayRecordInteraction if this widget is the responsible one.
   * @see CATVidInteractionRecorderData
   */
  virtual int PreInteractionRecord(CATVidInteractionRecorderData &i_recorder);
  /** @ingroup groupVidRecord
   * Do the actual recording after it has been delayed.
   *
   * This method will be called only if this component was called on 
   * @ref #PreInteractionRecord and called @ref CATVidInteractionRecorderData#DelayRecordInteraction
   * on the provided recorder.
   *
   * See details about the interaction recording algorithm in the 
   * documentation of the class CATVidInteractionRecorderData.
   *
   * @note
   * The default implementation is not empty and may be called by the
   * children class to support default behaviors (for example default
   * keyboard handling).
   *
   * @param i_recorder the recorder. You must call @c RecordInteraction on it.
   * Not calling @c RecordInteraction in this function will make the recording
   * of the interaction fail.
   * @param i_delayedRecordingData the data given to @c DelayRecordInteraction
   * when it was called.
   * @see CATVidInteractionRecorderData
   */
  virtual void PostInteractionRecord(CATVidInteractionRecorderData &i_recorder, const CATSYPProperties &i_delayedRecordingData);
  /** @ingroup groupVidRecord
   * Replay an interaction.
   *
   * See details about the interaction replaying algorithm in the
   * documentation of the class CATVidInteractionReplayerData.
   *
   * @note
   * The default implementation is not empty and may be called by the
   * children class to support default behaviors (for example default
   * keyboard handling) for kind of interactions that are not recorded
   * explicitely by this class.<br/>
   * Note that to make the difference between interactions recorded by
   * a child class and interactions recorded by this class during a 
   * replay, the children class should always create a namespace with
   * their name in the interaction data. That way they only have to
   * check that their namespace exists to know if the interaction is
   * for the parent class or for them.
   *
   * @note
   * Note that the code may call @ref CATVidInteractionReplayerData#FatalReplayFailure
   * before returning when the failure is not a internal one. For
   * example if a widget is disabled during the replay but was enabled 
   * during the record, the error should be handled by calling 
   * @c FatalReplayFailure (without using a @ref FAILURE). But if an
   * internal pointer that should never be @c NULL is @c NULL during
   * the replay when @c CHECK_POINTER_RET(ptr); should be used since
   * this is an internal error. In any case exiting before calling
   * @ref CATVidInteractionReplayerData#ReplaySuccess will raise a
   * replay internal error.
   *
   * @param i_replayer the replayer.
   *
   * @see CATVidInteractionReplayerData
   */
  virtual void InteractionReplay(CATVidInteractionReplayerData &i_replayer);
  /**
   * Removes from father, and clean callbacks.
   */
  void RemoveFromFather();
  /** @ingroup groupVidEvents
   * Add a handler for a given event.
   *
   * The handlers will be called in the order of their registration.
   *
   * If this function is called during the dispatch of an event, the
   * registered event handler won't be called for this dispatch but
   * will only be called for next dispatches.
   *
   * It is possible to call mutliple times this function with the same
   * event and the same handler instance. In that case there will be
   * multiple registrations; no checks are made for duplication (the
   * caller will have to call @ref #RemoveHandler multiple times).
   *
   * @par Method of an object
   * You may use @ref #AddCATSYPWRefMethEventHandler to add a handler
   * that calls a method of an object. For example:
   * @code
   * #include <CATSYPCheck.h>
   * #include <CATSYPWRefMethEventHandler.h>
   *
   * class CallbackObject : public CATBaseUnknown
   * {
   *   CATDeclareClass;
   * public:
   *   CallbackObject();
   *   ~CallbackObject();
   *   void Callback(CATBaseUnknown *i_pSender, MyEventArgs *i_pArgs);
   * };
   * CATImplementClass(CallbackObject, Implementation, CATBaseUnknown, CATNull);
   *
   * void MyClass::Init()
   * {
   *   ...
   *   MyWidget * const pWidget = ...;
   *   CallbackObject * const pCallbackObj = ...;
   *   // note: MyWidget::Evt event uses arguments of type MyEventArgs
   *   CHECK_TRUE(AddCATSYPWRefMethEventHandler(pWidget,
   *                                            MyWidget::Evt(), 
   *                                            pCallbackObj,
   *                                            &CallbackObject::Callback));
   *   ...
   * }
   * @endcode
   *
   * @param i_pEvent the event that we are interested in. Note that @c
   * AddRef will be called on the event. Can't be @c NULL.
   *
   * @param i_pHandler the handler to call. Can't be @c NULL. 
   * @c AddRef will be called on this pointer. Note that the type of 
   * @c CATSYPEventArgs supported by this handler will be compared to
   * the type of arguments of the event. It must be a super-type of
   * the one of the event.
   *
   * @param i_handleConsumedEvents @c !=0 if the handler should be
   * called for consumed events.
   *
   * @return @c !=0 if succeeded, @c 0 if failed to add handler due to
   * invalid input or internal error (in that case a @ref FAILURE has
   * been raised).
   *
   * @see #AddCATSYPStaticEventHandler
   * @see #AddCATSYPWRefMethEventHandler
   * @see #RemoveHandler 
   * @see #Dispatch
   */
  int AddHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents = 0);

  /** @ingroup groupVidEvents
   * Remove an handler for an event.
   *
   * If this function is called during the dispatch of an event, the
   * unregistered event handler will be called for this dispatch but
   * will not be called for next dispatches.
   *
   * If the same handler has been added multiple times, this function
   * removes the first found registration (starting the look up from
   * the most ancient registration).
   *
   * @param i_pEvent the event. Can't be @c NULL.
   *
   * @param i_pHandler the handler. Can't be @c NULL.
   *
   * @return @c !=0 if succeeded, @c 0 if failed to remove handler due
   * to invalid input or internal error (in that case a @ref FAILURE has
   * been raised) or if the handler was never registered for the given
   * event (in that case NO @ref FAILURE is raised, it is valid to do
   * so; this is important for auto-remove handlers).
   *
   * @see #AddHandler
   */
  int RemoveHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler);

  /** @ingroup groupVidEvents
   * Add an handler for a given event and a given class.
   *
   * The handlers will be called in the order of their
   * registration. The class handlers will be called before any
   * instance handler (i.e. handlers registered using @ref
   * #AddHandler). The handlers for a given class will be called
   * before the handlers of its parent class (for example if @c
   * CATVidCtlB inherits from @c CATVidCtlA, then when an event
   * reaches an instance of @c CATVidCtlB handlers registered for @c
   * CATVidCtlB will be called before handlers registered for @c
   * CATVidCtlA).
   *
   * If this function is called during the dispatch of an event, the
   * registered event handler won't be called for this dispatch but
   * will only be called for next dispatches.
   *
   * It is possible to call mutliple times this function with the same
   * event, the same handler instance and the same class. In that case
   * there will be multiple registrations; no checks are made for
   * duplication (the caller will have to call @ref #RemoveHandler
   * multiple times).
   *
   * @param i_pClass the class. Can't be @c NULL.
   *
   * @param i_pEvent the event that we are interested in. Note that @c
   * AddRef will be called on the event. Can't be @c NULL.
   *
   * @param i_pHandler the handler to call. Can't be @c NULL. 
   * @c AddRef will be called on this pointer. Note that the type of 
   * @c CATSYPEventArgs supported by this handler will be compared to
   * the type of arguments of the event. It must be a super-type of
   * the one of the event.
   *
   * @param i_handleConsumedEvents @c !=0 if the handler should be
   * called for consumed events.
   *
   * @return @c !=0 if succeeded, @c 0 if failed to add handler due to
   * invalid input or internal error (in that case a @ref FAILURE has
   * been raised).
   *
   * @see #AddSCATSYPStaticEventHandler
   * @see #AddSCATSYPSenderMethEventHandler
   * @see #RemoveClassHandler
   * @see #Dispatch
   */
  static int AddClassHandler(CATMetaClass *i_pClass, CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents = 0);

  /** @ingroup groupVidEvents
   * Remove an handler for an event and a given class.
   *
   * If this function is called during the dispatch of an event, the
   * unregistered event handler will be called for this dispatch but
   * will not be called for next dispatches.
   *
   * If the same handler has been added multiple times, this function
   * removes the first found registration (starting the look up from
   * the most ancient registration).
   *
   * @param i_pClass the class. Can't be @c NULL.
   *
   * @param i_pEvent the event. Can't be @c NULL.
   *
   * @param i_pHandler the handler. Can't be @c NULL.
   *
   * @return @c !=0 if succeeded, @c 0 if failed to remove handler due
   * to invalid input or internal error (in that case a @ref FAILURE has
   * been raised) or if the handler was never registered for the given
   * event (in that case NO @ref FAILURE is raised, it is valid to do
   * so; this is important for auto-remove handlers).
   *
   * @see #AddClassHandler
   */
  static int RemoveClassHandler(CATMetaClass *i_pClass, CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler);

  /** @ingroup groupVidEvents
   * Dispatch the event.
   *
   * The event will be dispatched in the tree of widgets depending on
   * the porpagation mode of the event (@ref
   * CATSYPEvent#GetPropagation).<br/>
   * When the propagation is @ref CATSYPEvent#OriginToRoot or @ref
   * CATSYPEvent#RootToOrigin, the path is built using @ref
   * CATVidWidget#GetFatherWidget (when the propagation is @ref
   * CATSYPEvent#NoPropagation, the path will only contain the
   * origin).
   *
   * The list of handlers that will be called will be frozen before
   * the first handler is called; as a consequence, changes in the
   * tree hierarchy or in the handlers for the event at each node
   * won't have any effect on the dispatch of this event (but will
   * have effect on next dispatches, even on dispatches that may be
   * triggered by handlers of this event).
   *
   * This call is synchronous; it is blocking until the dispatch is
   * ended.
   *
   * The dispatch is reentrant; it is safe to call @c Dispatch while
   * being called on a handler by another call to @c Dispatch. The
   * first @c Dispatch will simply be paused until the new @c Dispatch
   * has ended (@c Dispatch is synchronous) and then it will be
   * resumed an continue as expected.
   *
   * The event arguments instance will be passed to each handler; it
   * may be used to pass informations between handlers and/or to give
   * a result to the dispatch. Since the call of @c Dispatch is
   * synchronous, the caller may look at the state of the arguments
   * after the dispatch (for example after the dispatch the caller can
   * check if the event has been consumed).
   *
   * The origin on the event argument (@ref CATSYPEventArgs#GetOrigin)
   * must be either @c NULL or equal to this widget. If @c NULL, it
   * will be positioned by this function to this widget.
   *
   * During the propagation on each widget the handlers are called in
   * the following order:
   *   - first class handlers (@ref #AddClassHandler) are called.
   *   - then instance handlers (@ref #AddHandler) are called.
   *
   * Instance handlers are called in the order of their
   * registration.<br/>
   * Class handlers are called in this order:
   *   - first the class handlers of the class of the widget are 
   *     called in the order of their registration
   *   - then the class handlers of the parent class of the widget
   *     are called in the order of their registration
   *   - ...
   *
   * When a hanlder consume the event (@ref CATSYPEventArgs#Consume),
   * the handlers that should have been called after it and that are
   * not registered to be called for consumed events are not
   * called.<br/>
   * This include the handlers on the same widget. For example if two
   * handlers have been registered (with @c i_handleConsumedEvents=0)
   * on a widget for the same event and the first one consume the
   * event, the second one (in the order of registration) won't be
   * called.
   *
   * @par Sample
   * Assuming the event @c MyEvt of widget @c MyWidget uses arguments
   * of type @ref CATSYPEventArgs:
   * @code
   * CATVidWidget * const pOrigin = ...;
   *
   * // instantiate the arguments of the event
   * CATSYPEventArgs * const pEventArgs = 
   *   new CATSYPEventArgs(MyWidget::MyEvt());
   *
   * // dispatch the event
   * CHECK_TRUE(pOrigin->Dispatch(pEventArgs));
   *
   * // check if the event has been consumed
   * if (! pEventArgs->IsConsumed()) {
   *   ...
   * }
   *
   * // release the arguments
   * pEventArgs->Release();
   * @endcode
   * 
   * @param i_pArgs the arguments of the event to dispatch (the
   * dispatched event is retrieved using @ref
   * CATSYPEventArgs#GetEvent). @ref CATSYPEventArgs#GetOrigin must be
   * either this object or @c NULL.
   *
   * @return @c !=0 if the dispatch succeeded, @c 0 if failed.
   *
   * @see #AddHandler
   * @see #AddClassHandler
   */
  int Dispatch(CATSYPEventArgs *i_pArgs);

  /** @ingroup groupVidEvents
   * Get the event factory to use to build widgets' events.
   *
   * This function should be used through the @ref
   * CATImplementSYPEvent macro.
   *
   * @return the event factory. Never @c NULL.
   *
   * @see CATImplementSYPEvent
   */
  static CATSYPEventFactory *GetEventFactory();

  /** 
   * @return the transfer handler associated with each CID widget used in DnD.
   */
  virtual CATVidDnDTransferHandler* GetTransferHandler()const{return NULL;}

  /**
   * Introspectable property set to @c 1 when mouse if hovering a
   * manipulable @ref CATVidGP (i.e.\ @ref
   * CATVidGP#GetUseManipulatorFlag is true) that is this widget or
   * one of its descendants.
   *
   * It is based on @ref #MouseEnter and @ref #MouseLeave events and
   * will be modified when these events are thrown. It can be use in
   * templates with binding.
   *
   * @return @c 1 if the mouse is hovering a manipulable @ref CATVidGP
   * that is this widget or one of its descendants, else @c 0.
   *
   * @see #MouseEnter
   * @see #MouseLeave
   */
  int GetMouseHoveringState();

  /**
   * Sets the rotation angle that will be applied on the widget, after its layouting.
   * Warning, this method does not work with all VID components (e.g the text editor or
   * the scrollable area are not compatible with a rotation).
   * By default, the RotationInDegree property is equal to 0.
   */
  void SetRotationInDegree(int i_rotationInDegree);

  /**
   * @return the rotation angle applied on the widget, after its layouting 
   */
  int GetRotationInDegree() const;

  /*void SetRotationAxis(const CATMathDirectionf& i_rotationAxis);
  const CATMathDirectionf& GetRotationAxis() const;*/

  /** @nodoc toRemove after migration of CATBioSysEditorUI. */
  CATBaseUnknown* GetParent () const {return GetFatherWidget();}
  /** @nodoc*/
  virtual CATDialog* GetMotifDialog();
  
  /**
   * Sets an introspectable property by preventing the dispatch of SYPEvents.
   * Usefull when customer doesn't want to be called on its callback by setting a property itself by code.
   * @param i_propertyName the name of the introspectable property
   * @param i_spPropertyValue  the boxed value to set (see Boxing in introspection infrastructure)
   */
  void SetPropertyWithoutSendingEvents(const CATUnicodeString &i_propertyName, const CATBaseUnknown_var &i_spPropertyValue);
protected:
  /** Constructor. */
  CATVidWidget ();
  /**
   * Constructor.
   * This constructor is equivalent to: 
   * - CATVidWidget* myWidget = new CATVidWidget();
   * - myWidget.SetFather(i_pParent);
   * - myWidget.SetName(i_pIdentifier);
   * @param i_pParent the parent CATCommand, for notifications purpose. This param
   * can be NULL, especially in the case of introspection events use. 
   * It is absolutely not necessary, and not advised to try to have the same CATCommand
   * and widget trees. Most of the time, the i_pParent should be the CATCommand listening 
   * the notifications of the widget.
   * @param i_pIdentifier the identifier of the widget. Set the property Name.
   * @see #GetName and #SetName
   */
  CATVidWidget (CATCommand *i_pParent, const CATString & i_pIdentifier);
  /** Constructor. */
  CATVidWidget (CreateLetterFunc i_pCreateLetterFunc);
  /**
   * Constructor.
   * This constructor is equivalent to: 
   * - CATVidWidget* myWidget = new CATVidWidget();
   * - myWidget.SetFather(i_pParent);
   * - myWidget.SetName(i_pIdentifier);
   * @param i_pParent the parent CATCommand, for notifications purpose. This param
   * can be NULL, especially in the case of introspection events use. 
   * It is absolutely not necessary, and not advised to try to have the same CATCommand
   * and widget trees. Most of the time, the i_pParent should be the CATCommand listening 
   * the notifications of the widget.
   * @param i_pIdentifier the identifier of the widget. Set the property Name.
   * @see #GetName and #SetName
   */
  CATVidWidget (CATCommand *i_pParent, const CATString & i_pIdentifier, CreateLetterFunc i_pCreateLetterFunc);
  /**
   * Destructor.
   */
  virtual ~CATVidWidget ();
  /**
   * Launch a draw request, to update VID render.
   */
  void Draw();
  /**
   * Function called if a child has been deleted (CATCommand::Delete received)
   * @param the dying widget.
   */
  virtual void ChildWidgetDeleted(CATVidWidget* i_pDeletedChild){};
  /**
   * The computed minimum dimension is set after computation by 
   * the all the container class (CATVidCtl and CATVidLayCollection).
   * The effective minimum dimension is the union of the requested 
   * and computed minimum dimension.
   * @param i_computedMinimumDimension the computed minimum dimension.
   */
  virtual void SetComputedMinimumDimension(const CATMathPoint2Df& i_computedMinimumDimension);
  /**
   * Updates the computed minimum dimensions. Overloaded by containers 
   * (CATVidCtl and CATVidLayCollection).
   */
  virtual void UpdateComputedMinimumDimension();
  /**
   * This method is call before the call of the destructor of the widget
   * to clean it.
   */
  virtual void CleanBeforeDestruction();
  /** @nodoc*/
  void SendVidEvent( const CATUnicodeString& i_eventName, CATNotification* i_pNotification, const CATSYPProperties &i_dico, CATBoolean i_toDeleteFlag = FALSE);
  /** @nodoc*/
  void SendVidEvent( const CATUnicodeString& i_eventName, CATNotification* i_pNotification = NULL);
  /**
   * @return the density factor of the display of the widget.
   */
  float GetDensity() const;
  // These methods have been added to replace the use of the old method  
  // void SendVidEvent( const CATUnicodeString& i_eventName, CATNotification* i_pNotification = NULL)
  // If the CATSYPEvent or CATSYPEventArgs is known, we can directly dispatch the good event instead of performing
  // a CATSYPSendEvent that is not optimal. 
  // Do not use these methods if you already use the new event infrastructure, these methods have to be used only to 
  // replace the remaining occurrences of SendVidEvent(eventName, notification)
  // If you are using the new event infrastructure, call only Dispatch(args);
  void SendVidEvent( CATSYPEvent* i_pEvent, CATNotification* i_pNotification);
  void SendVidEvent( CATSYPEventArgs* i_pArgs, CATNotification* i_pNotification);

private:
  CATVidWidget(const CATVidWidget& iToCopy);
  CATVidWidget& operator=(const CATVidWidget& i_original);
  void FatherWidgetDeletedCB(CATCallbackEvent, void *, CATNotification *, CATSubscriberData data, CATCallback);
  void PositionFatherWidgetDeletedCB(CATCallbackEvent, void *, CATNotification *, CATSubscriberData data, CATCallback);
  void ChildWidgetDeletedCB(CATCallbackEvent, void *, CATNotification *, CATSubscriberData data, CATCallback);

private:
  static int _s_vidRecordLevel;
  l_CATVidWidget* _pVidLetter;
private:
  friend class l_CATVidWidget;
  friend class CATVidVisitor_MiniDim;
  friend class CATVidRecorder;
  friend class CATVidLayCollection; //(unusefull)

  static CATBoolean _cursorsInitialised;

#ifndef VID_DEPRECATED
  /**
   * @name Deprecated members
   */
  /*@{*/ 
public:
  /** @deprecated do strictly nothing...*/
  void DeleteView(){};
  /** @deprecated do strictly nothing...*/
  void SetPosition(float i_x, float i_y){};
  /** @deprecated use void SetMinimumDimension( const CATMathPoint2Df &i_dimension ); instead*/
  void SetMinimumDimension(float i_x, float i_y){SetMinimumDimension(CATMathPoint2Df(i_x, i_y));};
  /** @deprecated use void SetDimension( const CATMathPoint2Df &i_dimension ); instead*/
  void SetDimension(float i_width, float i_height){CATMathPoint2Df dimension(i_width, i_height);SetDimension(dimension);}
  /** @deprecated title must be set on CATVidFraWindow top component*/
  void SetTitle(const CATString& i_title);
  /** @deprecated title must be recovered from the CATVidFraWindow top component*/
  void GetTitle(CATString& o_title) const;
  /** @deprecated use #SetVisibleFlag instead.*/
  void Connect(const CATBoolean& i_dispatchInfoFlag = TRUE);
  /** @deprecated use #SetVisibleFlag instead.*/
  void Disconnect(const CATBoolean& i_dispatchInfoFlag = TRUE);
    /** @deprecated Use GetVisibleState instead.*/
  CATBoolean GetConnectedFlag() const;
protected:
  /** @deprecated use const CATMathPoint2Df& GetMinimumDimension() instead*/
  void GetDimension( float&  o_width, float& o_height );
private:
  CATUnicodeString _title;
/*@}*/ 
#endif
};

INLINE l_CATVidWidget& CATVidWidget::GetVidLetter() const
{
  return *_pVidLetter;
}


#endif
