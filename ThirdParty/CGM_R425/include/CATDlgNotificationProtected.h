#ifndef CATDLGNOTIFICATIONPROCTECTED
#define CATDLGNOTIFICATIONPROCTECTED

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "DI0PANV2.h"
#include "CATDlgUtility.h"
#include "CATNotification.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"

#include "CATDlgHtmlViewNotifications.h"

class ExportedByDI0PANV2 CATDiaDeactivateNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDiaDeactivateNotification object.
 */
    CATDiaDeactivateNotification();

    virtual ~CATDiaDeactivateNotification();

};

class ExportedByDI0PANV2 CATDiaActivateNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDiaActivateNotification object.
 */
    CATDiaActivateNotification();

    virtual ~CATDiaActivateNotification();

};

class ExportedByDI0PANV2 CATDlgKeyboardCtrlFNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgKeyboardCtrlFNotification object.
 */
    CATDlgKeyboardCtrlFNotification();

    virtual ~CATDlgKeyboardCtrlFNotification();

};

class ExportedByDI0PANV2 CATDlgKeyboardCtrlGNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgKeyboardCtrlGNotification object.
 */
    CATDlgKeyboardCtrlGNotification();

    virtual ~CATDlgKeyboardCtrlGNotification();

};

class ExportedByDI0PANV2 CATDlgKeyboardCtrlHNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgKeyboardCtrlHNotification object.
 */
    CATDlgKeyboardCtrlHNotification();

    virtual ~CATDlgKeyboardCtrlHNotification();

};

class ExportedByDI0PANV2 CATDlgKeyboardCtrlYNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgKeyboardCtrlYNotification object.
 */
    CATDlgKeyboardCtrlYNotification();

    virtual ~CATDlgKeyboardCtrlYNotification();

};

class ExportedByDI0PANV2 CATDlgKeyboardCtrlZNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgKeyboardCtrlZNotification object.
 */
    CATDlgKeyboardCtrlZNotification();

    virtual ~CATDlgKeyboardCtrlZNotification();

};

class ExportedByDI0PANV2 CATDlgKeyboardEarlyNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgKeyboardEarlyNotification object. 
 */   
    CATDlgKeyboardEarlyNotification();

    virtual ~CATDlgKeyboardEarlyNotification();

};

/** 
 * Class to notify the application that the configuration of the toolbars belonging to a CATDlgDocument window
 * has changed.
 * <b>Role</b>:
 * This event notification is sent by the @href CATDlgDocument whenever a toolbar belonging directly or 
 * indirectly to the CATDlgDocument is created, deleted, shown, hidden, docked or undocked or when the CATDlgDocument is resised.
 */
class ExportedByDI0PANV2 CATDlgDocToolbarConfigChangedNotification : public CATNotification
{

 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgDocToolbarConfigChangedNotification object. 
 */   
    CATDlgDocToolbarConfigChangedNotification();

    virtual ~CATDlgDocToolbarConfigChangedNotification();

};

/** 
 * Class to notify the application that cursor definiton at the level of a "Dialog" object has changed.
 *
 * <b>Role</b>:
 * This event notification is sent by a @href CATDialog object whenever the definition of the cursor linked 
 * to this objects has changed.
 */
class ExportedByDI0PANV2 CATDlgCursorDefinitionChangedNotification : public CATNotification
{
 CATDeclareClass;
 public:

/**
 * Constructs a CATDlgCursorDefinitionChangedNotification object. 
 */   
    CATDlgCursorDefinitionChangedNotification();

    virtual ~CATDlgCursorDefinitionChangedNotification();
};

class ExportedByDI0PANV2 CATDlgDragGiveFeedbackNotification : public CATNotification
{
 CATDeclareClass;
 public:
    CATDlgDragGiveFeedbackNotification();
    virtual ~CATDlgDragGiveFeedbackNotification();
 public:
    POINTL     _cursorPosition;
    DROPEFFECT _currentEffect;
    long       _retCode;
};

class ExportedByDI0PANV2  CATDlgQueryContinueDragNotification : public CATNotification
{
 CATDeclareClass;
 public:
    CATDlgQueryContinueDragNotification();
    virtual ~CATDlgQueryContinueDragNotification();
 public:
    DWORD _dragKeyModifier;
};

class ExportedByDI0PANV2 CATDlgCreateNewTabGroupCapabilityChangedNotification : public CATNotification
{
 CATDeclareClass;
 public:
    CATDlgCreateNewTabGroupCapabilityChangedNotification();
    virtual ~CATDlgCreateNewTabGroupCapabilityChangedNotification();
};

/** 
 * Class to notify a Dialog object onw that the object title has been updated
 *
 * Actually, under Windows and when Tabbed MDI is activated (default as of R2014), this event notification is sent by a CATDlgDialog with CATDlgWndChildMDI style when the corresponding
 * tab (and so its tile) is edited by user action.
 */

class ExportedByDI0PANV2 CATDlgTitleChangedNotification : public CATNotification
{
 CATDeclareClass;
 public:
    CATDlgTitleChangedNotification();
    virtual ~CATDlgTitleChangedNotification();
};

// Feb 2016 - could/should be private. For record/replay only
class ExportedByDI0PANV2 CATDlgDocClientAreaSizeNotification : public CATNotification
{
 CATDeclareClass;
 public:
    CATDlgDocClientAreaSizeNotification();
    virtual ~CATDlgDocClientAreaSizeNotification();
};

// Feb 2016 - could/should be private. For record/replay only
class ExportedByDI0PANV2 CATDlgActivateNotification : public CATNotification
{
 CATDeclareClass;
 public:
    CATDlgActivateNotification();
    virtual ~CATDlgActivateNotification();
};

// Feb 2017
 
class ExportedByDI0PANV2 CATCustomDialogBoxCheckerNotification : public CATNotification
{
  CATDeclareClass;
public:
  CATCustomDialogBoxCheckerNotification();
  virtual ~CATCustomDialogBoxCheckerNotification();
  inline void SetCaptureFile(const CATUnicodeString& iCaptureFile) {_captureFile = iCaptureFile;}
  inline const CATUnicodeString& GetCaptureFile() { return _captureFile;}
  inline void SetReplayFile(const CATUnicodeString& iReplayFile) {_replayFile = iReplayFile;}
  inline const CATUnicodeString& GetReplayFile() { return _replayFile;}
  inline void SetUpdateMode(CATBoolean iUpdateMode){ _updateMode=iUpdateMode;}
  inline CATBoolean GetUpdateMode() { return _updateMode;}
  inline void SetComparisonReturnCode(unsigned char iComparisonReturnCode){ _comparisonReturnCode=iComparisonReturnCode;}
  inline unsigned char GetComparisonReturnCode() { return _comparisonReturnCode;}

private:
  CATCustomDialogBoxCheckerNotification(const CATCustomDialogBoxCheckerNotification &iObjectToCopy);

  CATUnicodeString _captureFile;
  CATUnicodeString _replayFile;
  CATBoolean _updateMode;
  unsigned char _comparisonReturnCode; // 0 => OK.
};

// Mar 2017
 
class ExportedByDI0PANV2 CATDlgListDropNotification : public CATNotification
{
  CATDeclareClass;
public:
  CATDlgListDropNotification();
  virtual ~CATDlgListDropNotification();
  inline void SetDropIndex(const int iIndex) {_index = iIndex;}
  inline int GetDropIndex() { return _index;} // -1 if problem

private:
  CATDlgListDropNotification(const CATDlgListDropNotification &iObjectToCopy);
  int _index;
};
#endif
