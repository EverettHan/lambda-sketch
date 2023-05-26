#ifndef CATManipulatorMouseBehavior_H
#define CATManipulatorMouseBehavior_H

// COPYRIGHT DASSAULT SYSTEMES 2011

#include "CATVisFoundation.h"
#include "CATBaseUnknown.h"
class CATManipulator;
//class VisMultitouchDeviceEvent;

class ExportedByCATVisFoundation CATManipulatorMouseBehavior : public CATBaseUnknown
{
public:

  CATDeclareClass;

  CATManipulatorMouseBehavior();
  
  virtual ~CATManipulatorMouseBehavior();
  /** @nodoc */
  void SetAllowResetOnLostCapture(int iFlag); 
/** @nodoc */
  int GetAllowResetOnLostCapture() const;

  /** @nodoc */
  void SetAllowToManipulateMouseWheel(int iFlag); 
/** @nodoc */
  int GetAllowToManipulateMouseWheel() const;

    /** @nodoc */
  void SetActivateOnMiddleClickMode(int iFlag); // 
/** @nodoc */
  int GetActivateOnMiddleClickMode() const;
  /** @nodoc */
  // the pointed manipulator can or cannot be endactivated when the mouse leaves the viewer
  void SetEndPreactivateOnLeaveMode(int iFlag);
  /** @nodoc */
  int GetEndPreactivateOnLeaveMode() const;

  /** @nodoc */
  // the pointed manipulator can or cannot forward DnD events to its underlying viewer (in case of VID CtlViewer)
  void SetDnDOnContentMode(int iFlag);
  /** @nodoc */
  int GetDnDOnContentMode() const;

  /** @nodoc */
  // the pointed manipulator can or cannot forward DnD events to its underlying viewer (in case of VID CtlViewer)
  void SetContextOnContentMode(int iFlag);
  /** @nodoc */
  int GetContextOnContentMode() const;
  
private:

  int _AllowToManipulateMouseWheel;
  int _AllowActivateOnMiddleClickMode;
  int _EndPreactivateOnLeaveMode;
  int _AllowDnDOnContent;
  int _AllowContextOnContent;
  int _AllowResetOnLostCapture;
};


#endif
