#ifndef CATI3DCompassPilot_h
#define CATI3DCompassPilot_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"
#include "CATEventSubscriberTypedefs.h"
#include "CATBoolean.h"
#include "CAT3DCompassTypedefs.h"
#include "CATListOfCATString.h"

class CATMathTransformation;
class CATMathAxis;
extern ExportedByCATAfrSelection IID IID_CATI3DCompassPilot;

class ExportedByCATAfrSelection CATI3DCompassPilot : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual HRESULT GetCompassModifiedEvent (CATCallbackEvent * CompassModifiedEvent) = 0;
  virtual HRESULT GetCompassDestroyedEvent (CATCallbackEvent * CompassDestroyedEvent) = 0;
  virtual HRESULT Move(CATMathTransformation * Transfo) = 0; 
  virtual HRESULT GetManipulatedElementCount(int * oCount) = 0;
  virtual HRESULT GetShiftStateForBoxOrCompass(int * ShiftState) = 0;
  virtual HRESULT GetCompassSwapAxisEvent(CATCallbackEvent * CompassSwapAxisEvent) = 0;

  virtual HRESULT BeginMoveManipulation(CATMathTransformation * Transfo) = 0; 
  virtual HRESULT MoveManipulation(CATMathTransformation * Transfo) = 0; 
  virtual HRESULT EndMoveManipulation(CATMathTransformation * Transfo) = 0; 

  // Close the Robot edition dialog
  virtual HRESULT SetCompassPanelClosed() = 0;

  // Enable or disable the Robot edition dialog.
  // Depending on this option, a double-click on the Robot will edit the Robot or not.
  // By default the edition is available in all products except in 3D Live.
  // Returns the previous state so that the caller can restore it later.
  // iPanelAvailability = 1 --> enable, iPanelAvailability = 0 --> disable
  virtual int SetCompassPanelAvailability (int iPanelAvailability) = 0;

  // Enable or disable the Robot contextual menu.
  // Depending on this option, a contextual menu will be available on the Robot or not.
  // By default the menu is available in all products except in 3D Live.
  // Returns the previous state so that the caller can restore it later.
  // iCtxMenuAvailability = 1 --> enable, iCtxMenuAvailability = 0 --> disable
  virtual int SetCompassCtxMenuAvailability (int iCtxMenuAvailability) = 0;

  // In select command, by default, manipulators are set on a element
  // each time this element is selected. For multi-selection performance
  // improvement this can be disabled by allowing "late" manipulation.
  // In this case manipulators are set on the selected element only if
  // the compass is in the 3D view or manipulation bounding box is on.
  virtual HRESULT AllowLateManipulation(int * iAllowed) = 0;
  virtual HRESULT GetLateManipulationState(int * oAllowed) = 0; 

  // Returns the type of the device that is used to move
  // the compass
  // 0 : positional device (mouse)
  // 1 : incremental device (space mouse, space ball)
  virtual HRESULT GetDeviceType(int * oDeviceType) = 0;

  // Set the manipulation mode while manipulating compass with a VR device (space mouse, space ball)
  // 0 : compass is manipulated in screen axis system (default)
  // 1 : compass is manipulated in given RefAxis system : Z Up, Y Left (Identity if null)
  virtual HRESULT SetDeviceManipulationMode(int iManipulationMode, CATMathAxis * iRefAxis) = 0;

  /**
   * Retrieve the event emitted when compass steps are changed
   */
  virtual HRESULT GetCompassStepModificationEvent(CATCallbackEvent* oCompassStepModification) = 0;

  enum ParameterType { UTranslation, VTranslation, WTranslation,
                       URotation,    VRotation,    WRotation    };

  /**
   * PLEASE DO NOT USE THIS METHOD. IT IS TO THE EXCLUSIVE USAGE OF THE CATCOMPASSPANEL.
   * Method used by the CATCompassPanel to set the step parameters on the compass.
   * Any value set using this method won't be reflected in the compass edition panel.
   */
  virtual HRESULT SetStepValue(const ParameterType& iParam, 
                               const double& iValue         ) = 0;

  /**
   * Get the compass step value
   */
  virtual HRESULT GetStepValue(const ParameterType& iParam, double & oValue) = 0;

  virtual HRESULT SetPanelUpdatedWithCompass(CATBoolean iUpdateCompassPanel) = 0;
  virtual HRESULT GetPanelUpdatedWithCompass(CATBoolean & oUpdateCompassPanel) = 0;

  virtual HRESULT PreHighlightAxis(const ParameterType & iParam) = 0;

  /**
   * Performs same action on compass as the View | Reset compass command
   */
  virtual HRESULT CompassReset() = 0;

  /**
   * Partial hide/show of compass.
   */
  virtual HRESULT Hide(CATCompassTransformationType iElement) = 0;
  virtual HRESULT Show(CATCompassTransformationType iElement) = 0;
  virtual HRESULT GetVisibility(CATCompassTransformationType iElement, CATBoolean & oVisible) = 0;

  /**
   * Display the compass with a minimized/maximized view.
   * Set iValue to TRUE to minize the compass, the iValue to FALSE to maximize compass.
   */
  virtual HRESULT MinimizeView(CATBoolean iValue) = 0;

  /**
   * Returns TRUE if compass is minized, FALSE otherwise
   */
  virtual HRESULT IsViewMinimized(CATBoolean & oValue) = 0;

  /**
   * Display the visual feedback during translation or rotation.
   * Set iValue to TRUE to show visual feedback, iValue to FALSE to hide it.
   */
  virtual HRESULT ShowFeedback(CATBoolean iValue) = 0;

  /**
   * Returns TRUE if annotations are shown, FALSE otherwise
   * Default value is TRUE.
   */
  virtual HRESULT IsFeedbackVisible(CATBoolean & oValue) = 0;

  /**
   * Get / Set the compass contextual menu.
   * The string list reflects the compass contextual menu content. Modify the list
   * to modify the compass contextual menu. Any change is permanent until the
   * next change.
   *
   * Default list content is : 
   * [LockCurrentOrientation], [ScreenPlane], [UseLocalAxis], [DisplayAxisLabel], [Separator],
   * [SwapXY], [SwapYZ], [SwapZX], [MostViewPlane], [Separator],
   * [AutoSnap], [Separator], [Edit]
   *
   * String enclosed with [ ] means special identifier
   * String without [ ] means a command header ID.
   * [Separator] means a separator.
   */
  virtual HRESULT GetContextualMenu(CATListOfCATString & oList) = 0;
  virtual HRESULT SetContextualMenu(const CATListOfCATString & iList) = 0;

  /**
   * Set FALSE to provide another way for select command integration:
   * - Disable CATISelectMove3D/CATIEditMove2D integration in SelectCommand
   * - Enable emiting CATI3DCompass events in select command
   * This call won't have any effect until select command is started again.
   */
  virtual HRESULT SetSelectCommandIntegration(CATBoolean iValue) = 0;

  /**
   * Returns TRUE if compass uses select command integration (default).
   * False otherwise.
   */
  virtual HRESULT GetSelectCommandIntegration(CATBoolean & oValue) = 0;

  /**
   * Get / Set compass ShortHelp
   */
  virtual HRESULT SetShortHelp(CATCompassTransformationType iElement, const CATUnicodeString & iMessage) = 0;
  virtual HRESULT GetShortHelp(CATCompassTransformationType iElement, CATUnicodeString & oMessage) = 0;

  /**
   * Get / Set commpass sensitivity
   */
  virtual HRESULT SetSensitivity(CATCompassTransformationType iElement, CATBoolean iEnabled) = 0;
  virtual HRESULT GetSensitivity(CATCompassTransformationType iElement, CATBoolean & oEnabled) = 0;

  /**
   * Get scale handle activation status
   * Return answer as bit field, meaning value: 0: inactive, 1: active
   * Bit 0 : X scale handle
   * Bit 1 : Y scale handle
   * Bit 2 : Z scale handle
   */
  virtual HRESULT GetScaleManipulatorState(int & oActivated) = 0;
};

CATDeclareHandler(CATI3DCompassPilot, CATBaseUnknown);

#endif
