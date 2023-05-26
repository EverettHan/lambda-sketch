//===================================================================
// COPYRIGHT Dassault Systemes 2020/05/14
//===================================================================
// Header definition of class IVStylusDeviceRadialMenuEditor
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2020/05/14 Creation
//===================================================================
#ifndef IVStylusDeviceRadialMenuEditor_H
#define IVStylusDeviceRadialMenuEditor_H

#include "IVInterfaces.h"
#include "IVStylusDeviceEditor.h"
#include "IVDeviceAtomicType.h"
#include "CATLISTV_CATMathVector.h"
#include "CATMathVector.h"

class IVIStylusDevice;
class CATManipulator;
class CATNotification;
class IVISUIEntity_var;
class IVSpatialMultiDirectionalGesture;
class IVMultiDirectionalGestureRecognizer;


//------------------------------------------------------------------------------

class ExportedByIVInterfaces IVStylusDeviceRadialMenuEditor : public IVStylusDeviceEditor
{
  CATDeclareClass;

public :

  /** Create a device editor that will modify the interactions.
   *  To be activated, the DeviceEditor has to be declared to the viewer.
   */
  IVStylusDeviceRadialMenuEditor(IVIStylusDevice * iIpDevice);

  /** Destruction of the stylus editor.
   */
   ~IVStylusDeviceRadialMenuEditor();
   
  /*
   * GetActionForInteraction returns a function called action that will be executed
   *  when a given interaction is detected
   */
  virtual std::vector<std::pair<IVStylusDeviceAction, const IVGesture* >> GetActionsForInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator);

  /*
   * GetPriority returns a priority for the editor
   */
  virtual IVIStylusDeviceEditor::EditorPriority& GetPriority() { return _priority; };

  /*
   * MultiDirectional Gesture as gesture to recognize
   */
  void AddMultiDirectionalGestureRecognizer(IVISUIEntity_var& iHandEntity, IVAtomicID iButtonID);
  void RemoveMultiDirectionalGestureRecognizer(IVISUIEntity_var& iHandEntity, IVAtomicID iButtonID);
  void SetMultiDirectionalGestureRecognizerAsDragBegan();

  void AddDirection(CATMathVector & iVector);
  void RemoveDirection(CATMathVector & iVector);
  void RemoveAllDirections();
  void SetPlane(const CATMathVector & iPlaneNormal);
  void SetDetectionRadius(const double iRadius);
  void SetDetectionThreshold(const double iThreshold);
  void SetDetectionSpeed(const double iSpeed);
  void SetProjectionMax(const double iProjection);

protected :

  virtual IVStylusDeviceAction GetActionForMultiDirectionalPossibleInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator);
  virtual IVStylusDeviceAction GetActionForMultiDirectionalBeganInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator);
  virtual IVStylusDeviceAction GetActionForMultiDirectionalChangedInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator);
  virtual IVStylusDeviceAction GetActionForMultiDirectionalEndedInteraction(CATNotification * ipEvent, CATManipulator * ipPointedManipulator, CATManipulator * ipPlugedManipulator);
  IVSpatialMultiDirectionalGesture* GetMultiDirectionalGesture() { return _pMultiDirectionalGesture; };

private :
  
  //  
  IVIStylusDeviceEditor::EditorPriority _priority;

  IVSpatialMultiDirectionalGesture* _pMultiDirectionalGesture;

  IVMultiDirectionalGestureRecognizer* _pMultiDirectionalGestureRecognizer;

  CATLISTV(CATMathVector) _directionList;
  CATMathVector _plane;
  double _radius;
  double _threshold;
  double _speed;
  double _projection;
};

//-----------------------------------------------------------------------

#endif
