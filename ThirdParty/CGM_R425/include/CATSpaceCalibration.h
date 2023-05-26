#ifndef CATSpaceCalibration_H
#define CATSpaceCalibration_H

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATVisFoundation.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATNotification.h"
#include "CATCallbackManager.h"
#include "CATLISTV_Clean.h"

#define	CATLISTV_Append
#define	CATLISTV_Locate
#define CATLISTV_RemovePosition

#include  "CATLISTV_Declare.h"
CATLISTV_DECLARE(CATSpaceDriverFunction)

#define NBUTTONS 32 // Also defined in Visualization\VE0BASE.m CATSpaceThread.h 

class CATResourceLock;
class CATVizViewer;
class CATSpaceListenerBase;


class CATSpaceDriverFunction
{
public:
  CATSpaceDriverFunction(const int function,
                         const int fctID,
                         const CATUnicodeString &fctTitle) :
    _function(function),
    _fctID(fctID),
    _fctTitle(fctTitle)
  {};

  virtual ~CATSpaceDriverFunction() {};

  void GetData(int *pFunction, int *pFctID,
               CATUnicodeString &fctTitle)
  {
    if (pFunction) *pFunction = _function;
    if (pFctID) *pFctID = _fctID;
    fctTitle = _fctTitle;
  };

  void SetData(const int function, const int fctID,
               const CATUnicodeString &fctTitle)
  {
    _function = function;
    _fctID = fctID;
    _fctTitle = fctTitle;
  };

  int GetID(void) {return _fctID;};

  void GetTitle(CATUnicodeString &fctTitle) {fctTitle = _fctTitle;};

  int operator == ( const CATSpaceDriverFunction &driverFct) const
  {
    return (_function == driverFct._function);
  };

  int operator != ( const CATSpaceDriverFunction &driverFct) const
  {
    return (_function != driverFct._function);
  };
private:
  int _function;
  int _fctID;
  CATUnicodeString _fctTitle;
};


class ExportedByCATVisFoundation CATSpaceSyncNotification : public CATNotification
{
  CATDeclareClass;

public :
  CATSpaceSyncNotification(void);
  virtual ~CATSpaceSyncNotification(void);

  int button;

  // Not implemented
  CATSpaceSyncNotification(const CATSpaceSyncNotification &);
  CATSpaceSyncNotification & operator= (const CATSpaceSyncNotification &);
};


class ExportedByCATVisFoundation CATSpaceCalibration
{

public:
  static CATSpaceCalibration *GetInstance();
  void Release();

  static int IsInstantiated(void);

  void SetListenerBase(CATSpaceListenerBase *pListenerBase);

  int InitBase(void);
  int GetInitBase();
  void GetTitle(int button, CATUnicodeString &title);

  CATDeclareCBEvent(SYNC_VALUE_EVENT);
  CATDeclareCBEvent(SYNC_BUTTON_EVENT);
  CATDeclareCBEvent(SYNC_FUNCTION_LIST_EVENT);

  CATCallbackManager *GetCallbackManager(void) {return _pCallbackMgr;};

  virtual int Calibrate(const double raw_data[], double mat[]);
  void OnButton(int button, CATVizViewer *pViewer = 0);
  void OnButtonBase(int button, CATVizViewer *pViewer = 0);

  void SetSpaceDeviceID(int devID, int devOrientation = 0);
  int  GetSpaceDeviceID(int *pOrientation = NULL);
 
  CATBoolean GetRotationOff(void);
  void       SetRotationOff(CATBoolean value);
  CATBoolean GetTranslationOff(void);
  void       SetTranslationOff(CATBoolean value);
  CATBoolean GetDominant(void);
  void       SetDominant(CATBoolean value);

  int  GetFunctionCount(void);
  void SetFunctionCount(int count);
  void AddFunction(int function, int fctID, CATUnicodeString &fctTitle);
  void GetFunctionData(int fct, int *pFctID, CATUnicodeString &oTitle);
  int  GetFunctionTitle(int fctID, CATUnicodeString &fctTitle); 

  int  GetButtonAssignment(int button);
  void SetButtonAssignment(int button, int function);

  void GetDriverButtonAssignment(int button);
  void SetDriverButtonAssignment(int button, int fctID);
  void SetDriverButtonRestoreDefault(int button);

  void SetDriverButtonText(int button, CATUnicodeString &cmdTitle);
  void SetDriverInfoLineText(CATUnicodeString &infoLine);

  float GetSyncSensitivity(void);
  void  SetSyncSensitivity(float value);

  float GetSensitivity(void);
  void  SetSensitivity(float value);

private :
  CATSpaceCalibration();
  virtual ~CATSpaceCalibration();

  int RemapButton(int button);
  int ToggleViewMode(CATVizViewer *pViewer);
  int ToggleNavigationStyle(CATVizViewer *pViewer);

  static CATSpaceCalibration *_instance;
  static CATResourceLock     *_instanceLock;
  int                         _held;

  CATSpaceListenerBase *_pListenerBase;

  CATCallbackManager *_pCallbackMgr;
  CATSpaceSyncNotification *_pSpaceSyncNotif;

  int        _devID;
  int        _devOrientation;
  CATBoolean _TranslationOff;
  CATBoolean _RotationOff;
  CATBoolean _Dominant;
  float      _Sensitivity;
  float      _SyncSensitivity;

  int _driverFctCount;
  CATLISTV(CATSpaceDriverFunction) _driverFctList;

  int _driverBtnAssignments[NBUTTONS];

  int _initbase;
};


#endif
