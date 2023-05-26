//===================================================================
// COPYRIGHT Dassault Systemes 2020/05/14
//===================================================================
// Header definition of class IVStylusDeviceEditor
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2020/05/14 Creation
//===================================================================
#ifndef IVStylusDeviceEditor_H
#define IVStylusDeviceEditor_H

#include "IVInterfaces.h"
#include "IVExtIStylusDeviceEditor.h"
#include "IVDeviceAtomicType.h"
#include "IVGestureRecognizer.h"
#include <vector>
#include <utility>

class IVIStylusDevice;
class CATManipulator;
class CATNotification;
class IVButtonGesture;
class IVTrackedElementGesture;
class IVDragGesture;
class IVAnalogGesture;
//class IVSpatialCutGesture;
class IVISUIEntity_var;
class IVGesture;

//------------------------------------------------------------------------------

class ExportedByIVInterfaces IVStylusDeviceEditor : public IVExtIStylusDeviceEditor
{

  CATDeclareClass;

public :

  /** Create a device editor that will modify the interactions.
   *  To be activated, the DeviceEditor has to be declared to the viewer.
   */
  IVStylusDeviceEditor(IVIStylusDevice * iIpDevice);

  /** Destruction of the stylus editor.
   */
  ~IVStylusDeviceEditor();
   
  /*
   * GetActionsForInteraction returns a function called action that will be executed
   *  when a given interaction is detected
   */
  virtual std::vector<std::pair<IVStylusDeviceAction, const IVGesture*>> GetActionsForInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator);

  /*
   * Move Over Gesture as gesture to recognize
   */
  void AddMoveOverGestureRecognizer(IVISUIEntity_var& iHandEntity);
  void RemoveMoveOverGestureRecognizer(IVISUIEntity_var& iHandEntity);
  void AddMoveOverGestureRecognizer(IVAtomicID iTrackedDeviceID, IVAtomicID iTrackedElementID = -1);
  void RemoveMoveOverGestureRecognizer(IVAtomicID iTrackedDeviceID, IVAtomicID iTrackedElementID = -1);

  /*
   * Button Gesture as gesture to recognize
   */
  void AddButtonGestureRecognizer(IVAtomicID iButtonID);
  void RemoveButtonGestureRecognizer(IVAtomicID iButtonID);

  /*
   * Drag Gesture as gesture to recognize
   */
  void AddDragGestureRecognizer(IVISUIEntity_var& iHandEntity, IVAtomicID iButtonID);
  void AddDragGestureRecognizer(IVAtomicID iButtonID, IVAtomicID iTrackedDeviceID, IVAtomicID iTrackedElementID = -1);
  void RemoveDragGestureRecognizer(IVISUIEntity_var& iHandEntity, IVAtomicID iButtonID);
  void RemoveDragGestureRecognizer(IVAtomicID iButtonID, IVAtomicID iTrackedDeviceID, IVAtomicID iTrackedElementID = -1);

  /*
   * Analog Gesture as gesture to recognize
   */
  void AddAnalogGestureRecognizer(IVAtomicID iAnalogAtomicID);
  void RemoveAnalogGestureRecognizer(IVAtomicID iAnalogAtomicID);

  /*
   * Analog Pad Gesture as gesture to recognize
   */
  void AddAnalogPadGestureRecognizer(IVAtomicID ixAnalogAtomicID, IVAtomicID iyAnalogAtomicID);
  void RemoveAnalogPadGestureRecognizer(IVAtomicID ixAnalogAtomicID, IVAtomicID iyAnalogAtomicID);

  /*
   * Cut Gesture as gesture to recognize
   */
   //void AddCutGestureRecognizer(IVISUIEntity_var& iHandEntity, IVAtomicID iTriggerButtonID);
   //void RemoveCutGestureRecognizer(IVISUIEntity_var& iHandEntity, IVAtomicID iTriggerButtonID);

protected :

  friend class CATNRStylusDeviceSmartMenuEditor;

  virtual IVStylusDeviceAction GetActionForInteraction(CATNotification* ipEvent, CATManipulator* ipPointedManipulator, CATManipulator* ipPlugedManipulator, const IVGesture* iGesture);

  virtual IVStylusDeviceAction GetActionForMoveOverInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator, const IVTrackedElementGesture* iGesture);

  virtual IVStylusDeviceAction GetActionForButtonPossibleInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator, const IVButtonGesture* iGesture);
  virtual IVStylusDeviceAction GetActionForButtonBeganInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator, const IVButtonGesture* iGesture);
  virtual IVStylusDeviceAction GetActionForButtonChangedInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator, const IVButtonGesture* iGesture);
  virtual IVStylusDeviceAction GetActionForButtonEndedInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator, const IVButtonGesture* iGesture);
  const IVButtonGesture* GetButtonGesture() const { return _pButtonGesture;};

  virtual IVStylusDeviceAction GetActionForDragPossibleInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator, const IVDragGesture* iGesture);
  virtual IVStylusDeviceAction GetActionForDragBeganInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator, const IVDragGesture* iGesture);
  virtual IVStylusDeviceAction GetActionForDragChangedInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator, const IVDragGesture* iGesture);
  virtual IVStylusDeviceAction GetActionForDragEndedInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator, const IVDragGesture* iGesture);
  const IVDragGesture* GetDragGesture() const { return _pDragGesture; };

  virtual IVStylusDeviceAction GetActionForAnalogPossibleInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator, const IVAnalogGesture* iGesture);
  virtual IVStylusDeviceAction GetActionForAnalogBeganInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator, const IVAnalogGesture* iGesture);
  virtual IVStylusDeviceAction GetActionForAnalogChangedInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator, const IVAnalogGesture* iGesture);
  virtual IVStylusDeviceAction GetActionForAnalogEndedInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator, const IVAnalogGesture* iGesture);
  const IVAnalogGesture* GetAnalogGesture() const { return _pAnalogGesture; };

  //virtual IVStylusDeviceAction GetActionForCutPossibleInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator);
  //virtual IVStylusDeviceAction GetActionForCutBeganInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator);
  //virtual IVStylusDeviceAction GetActionForCutChangedInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator);
  //virtual IVStylusDeviceAction GetActionForCutEndedInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator);
  //const IVSpatialCutGesture* GetCutGesture() const { return _pCutGesture; };

private :

  IVButtonGesture* _pButtonGesture;
  IVDragGesture* _pDragGesture;
  IVAnalogGesture* _pAnalogGesture;
  IVTrackedElementGesture* _pTrackedElementGesture;
  
  //IVSpatialCutGesture* _pCutGesture;

};

//-----------------------------------------------------------------------

#endif
