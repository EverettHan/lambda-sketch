#ifndef VisStylusDevice_H
#define VisStylusDevice_H

#include "CATVisFoundation.h"
#include "CATDevice.h"
#include "CATMathTransformation.h"
#include "CATViewerUtility.h"
#include "CATPickPathList.h"
#include "CATPickPath.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"
#include "VisStylusDeviceEvent.h"
class CATVizViewer;
class CATViewerEvent;
class CATNotification;
class VisStylusVIDEvent;
class IVIStylusDevice;


/**
 * VisStylusDevice
 */
class ExportedByCATVisFoundation VisStylusDevice: public CATDevice
{
  CATDeclareClass;

public:

  /**
   * Constructor
   */
  VisStylusDevice(CATVizViewer* iVizViewer
                  , CATViewerEvent* iViewerEvt // CATDevice constructor will set _CurrentEvent to the given event
    );

  /**
   * Destructor
   */
  virtual ~VisStylusDevice();

  /**
   * Overrides CATDevice#InterpretDeviceEvent
   */
  virtual int InterpretDeviceEvent(CATNotification* event, CATSubscriberData data);

  /**
   * Overrides CATDevice#InitPickPathList
   */
  void InitPickPathList();

  /**
   * Overrides CATDevice#MoveToNextPickPath
   */
  int MoveToNextPickPath();

  /**
   * Called by the application during a CATViewerEvent::GetPickPathUnder, 
   * it forces the pick
   */
  void DoPick();

  /**
   * Set the style of the stylus to use for picking
   */
  void SetStylusPickingStyle(CATPickingStyle iStylusPickingStyle);

  /**
   * Get the stylus picking style
   */
  CATPickingStyle GetStylusPickingStyle();

  /**
  * Set the direction of the stylus referential to use for picking
  */
  void SetStylusPickingDirection(const CATMathVector& iStylusPickingDirection);

  /**
  * Get the stylus picking direction
  */
  const CATMathVector& GetStylusPickingDirection();

  /**
  * Set the origin of the stylus to use for picking
  */
  void SetStylusPickingOrigin(const CATMathPoint& iStylusPickingOrigin);

  /**
  * Get the stylus picking origin
  */
  const CATMathPoint&  GetStylusPickingOrigin();

  /**
  * Set the radius of the stylus to use for picking
  */
  void SetStylusPickingRadius(double iStylusPickingRadius);

  /**
  * Get the stylus picking radius
  */
  double GetStylusPickingRadius();

  /**
  * Set the stylus VID picking option.
  * > -1 to pick all reps
  * >  0 to pick all reps except VID
  * >  1 to pick only VID reps
  */
  void SetStylusVIDPicking(int iVIDPicking);

  /**
  * Get the stylus VID picking option (see method above for the return int description.)
  */
  int GetStylusVIDPicking();

  /**
   * Set the style of the stylus to use for picking
   */
  void SetStylusPose(CATMathTransformation const& iPose);

  /**
   * Set the style of the stylus to use for picking
   */
  void SetStylusButtonState(VisStylusButtonStatus iButtonState);

  /**
  * Enable/Disable picking : by default, VisStylusDevice::Pick(..., CATPickPathList& oPickPathList) launches a Pick on its viewer to get the [out] pickpathlist.
  * If disabled, the [out] pickpatlist is the one set by SetPickPathList method below.
  */
  void EnablePicking();
  void DisablePicking();

  /**
  * Sets the pickpathlist, that is used when picking is disabled (see methods above).
  */
  void SetPickPathList(const CATPickPathList& iPickPathList);

  /**
   * Set the style of the stylus to use for picking
   */
  void SetStylusEventPPXMode(bool iIsPPXMode);

  // Device IV
  IVIStylusDevice* GetIVStylusDevice();

  // Device Editors
  int AddDeviceEditor(CATBaseUnknown* ipEditor);
  int RemoveDeviceEditor(CATBaseUnknown * ipEditor);

private:

  // copy constructor
  VisStylusDevice(const VisStylusDevice&);

  // assignment operator
  VisStylusDevice& operator=(const VisStylusDevice&);

private:
  friend class IVStylusDevice;

  // Device IV
  void SetIVStylusDevice(IVIStylusDevice* ipIStylusDevice);

  // Overrides IVIStylusDevice#Leave
  void Leave(); // Leave

  // Overrides IVIStylusDevice#PreActivation
  void PreActivation(bool iISPickRequested); // Preactivation with or without pick
  void PreActivation(CATManipulator* ipPointedManip, CATPickPathList& iPickPathList, CATPickPath& iPickPath); // Preactivation with pick result provided

  // Overrides IVIStylusDevice#ActivationAndBeginManipulation
  void ActivationAndBeginManipulation(); // ActivationAndBeginManipulation with pick
  void ActivationAndBeginManipulation(CATManipulator* ipPointedManip, CATPickPathList& iPickPathList, CATPickPath& iPickPath); // ActivationAndBeginManipulation with pick result provided

  // Overrides IVIStylusDevice#Manipulation
  void Manipulation(); // Manipulation

  // Overrides IVIStylusDevice#EndManipulation
  void EndManipulation(); // EndManipulation with pick
  void EndManipulation(CATManipulator* ipPointedManip, CATPickPathList& iPickPathList, CATPickPath& iPickPath); // EndManipulation with pick result provided

  // Send events for VID event
  void PreActivation(VisStylusVIDEvent* ipStylusEvt, unsigned int iButtonState);
  void ActivationAndBeginManipulation(VisStylusVIDEvent* ipStylusEvt);
  void EndManipulation(VisStylusVIDEvent* ipStylusEvt);
  void SendPreActivation(CATManipulator* ipPreviousPointedManip, CATPickPath& iPreviousPickPath);
  void SendActivationAndBeginManipulation();
  void SendEndManipulationPreActivation(CATManipulator* ipPreviousPointedManip, CATPickPath& iPreviousPickPath);

  // choose manipulator under stylus
  void ChoosePointedManip(VisStylusVIDEvent* ipStylusEvt);
  void ChoosePointedManip();
  void ChoosePointedManip(CATManipulator* ipPointedManip, CATPickPathList& iPickPathList, CATPickPath& iPickPath);

  // launch a pick
  void Pick(const CATMathTransformation& iStylusPos, CATMathVector const& iPickStylusDirection, const CATMathPoint& iPickStylusOrigin, double iPickStylusRadius, CATPickingStyle iPickStyle, CATPickPathList& oPickPathList);

  // all pathes selected by the device before election
  CATPickPathList _PickPathList;

  // pick path of the selection/manipulated manipulator
  CATPickPath _PickPath;

  // pick path under stylus
  CATPickPath _PickPathUnder;

  // stylus picking mode 
  CATPickingStyle _PickStylusStyle; // CATPicking or CATPickingClosed

  // stylus picking direction 
  CATMathVector _PickStylusDirection;

  // stylus picking origin 
  CATMathPoint _PickStylusOrigin;

  // stylus picking radius 
  double _PickStylusRadius;

  // picking
  bool _IsPickingEnabled;

  // PPX mode
  bool m_IsPPXMode;

  // VID Picking 
  //> -1 to pick all reps
  //>  0 to pick all reps except VID
  //>  1 to pick only VID reps
  int _VIDPicking;

  // stylus pose
  CATMathTransformation m_Pose;

  // stylus pose
  VisStylusButtonStatus m_ButtonState;

  // gesture recognition
  IVIStylusDevice* m_pIStylusDevice;
};

#endif
