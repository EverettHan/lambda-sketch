// COPYRIGHT DASSAULT SYSTEMES 2017

#ifndef IVIStylusDevice_H
#define IVIStylusDevice_H

#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATEventSubscriberTypedefs.h"

class CATManipulator;
class CATNotification;
class CATPickPathList;
class CATPickPath;


extern ExportedByCATVisItf IID IID_IVIStylusDevice;

/**
* Interface to extend the VisStylusDevice without IVInterfaces prereq
*/

class ExportedByCATVisItf IVIStylusDevice : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  // Overrides CATDevice#InterpretDeviceEvent
  virtual int InterpretDeviceEvent(CATNotification * ipEvent, CATSubscriberData iData, CATManipulator * iPointedManipulator, CATManipulator * iPlugedManipulator) = 0;

  // Behavior step
  virtual int InterpretBehaviorStep() = 0;

  // Overrides CATDevice#Leave
  virtual int Leave() = 0; // Leave

  // Overrides CATDevice#PreActivation
  virtual int PreActivation(bool iISPickRequested) = 0; // Preactivation with or without pick
  virtual int PreActivation(CATManipulator* ipPointedManip, CATPickPathList& iPickPathList, CATPickPath& iPickPath) = 0; // Preactivation with pick result provided

  // Overrides CATDevice#ActivationAndBeginManipulation
  virtual int ActivationAndBeginManipulation() = 0; // ActivationAndBeginManipulation with pick
  virtual int ActivationAndBeginManipulation(CATManipulator* ipPointedManip, CATPickPathList& iPickPathList, CATPickPath& iPickPath) = 0; // ActivationAndBeginManipulation with pick result provided

  // Overrides CATDevice#Manipulation
  virtual int Manipulation() = 0; // Manipulation

  // Overrides CATDevice#EndManipulation
  virtual int EndManipulation() = 0; // EndManipulation with pick
  virtual int EndManipulation(CATManipulator* ipPointedManip, CATPickPathList& iPickPathList, CATPickPath& iPickPath) = 0; // EndManipulation with pick result provided

  // Device Editors
  virtual int AddDeviceEditor(CATBaseUnknown * ipEditor) = 0;
  virtual int RemoveDeviceEditor(CATBaseUnknown * ipEditor) = 0;

  // Gesture Recognizers
  virtual HRESULT AddGestureRecognizer(CATBaseUnknown* ipGestureRecognizer) = 0;
  virtual HRESULT RemoveGestureRecognizer(CATBaseUnknown* ipGestureRecognizer) = 0;
  virtual int GetGestureRecognizerCount() = 0;
  virtual CATBaseUnknown* GetGestureRecognizer(int iIndex) = 0;
};

CATDeclareHandler(IVIStylusDevice, CATBaseUnknown);

#endif

