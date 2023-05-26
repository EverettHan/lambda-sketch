#ifndef CNext_H
#define CNext_H

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATInteractiveApplication.h"

#include "CATAfrFoundation.h"
#include "CATApplicationFrame.h"
#include "CATMsgCatalog.h"
#include "CATListOfCATString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATBoolean.h"
#include "CATEventSubscriberTypedefs.h"

class CATCommandHeader;
class CATLicenseManagerInit;
class CATNotification;
class CATCommand;

/**
* Class to define a new product line.
*/
class ExportedByCATAfrFoundation CNext : public CATInteractiveApplication
{
  CATDeclareClass;
  
public:
  /** 
   * Constructs a new product line.
   * @param iApplicationName
   * Name of the new product line
   */
  CNext(CATString iApplicationName = "CATIA");

  virtual ~CNext();
  
#ifdef _WINDOWS_SOURCE
//  suffixe "2" : pour eviter "surcharge" des methodes de CATBaseUnknown 
  /** @nodoc */
  STDMETHODIMP_(ULONG) AddRef2();
  /** @nodoc */
  STDMETHODIMP_(ULONG) Release2();
#endif
  /** @nodoc */
  void BeginApplication();
    /** @nodoc */
  int  EndApplication();
    /** @nodoc */
  void SetVisibility(int);
    /** @nodoc */
  int  GetVisibility();
    /** @nodoc */
  void StartCommand(CATCommandHeader * command,
		    const CATUnicodeString & documents);

    /** @nodoc */
  CATString GetApplicationName ();  

//DBI-->
#ifdef  _WINDOWS_SOURCE
    /** @nodoc */
  CATBoolean	IsOleServer () const;
#endif//_WINDOWS_SOURCE
//<--DBI

  /* Begin JDU */
#ifdef _WINDOWS_SOURCE
	/** @nodoc
	 * Override CATApplication default implementation of this method
	 * to provide a root application object and make the application VBA compatible.
	 */
	virtual HRESULT GetVBAApplicationObject(
			IDispatch*& oAppObject,
			CATUnicodeString& oAppName,
			CATUnicodeString& oTypelibName);
#endif // _WINDOWS_SOURCE

	/** @nodoc
	 * Position the return code which will be returned by EndApplication.
	 * This is useful when CNext -batch -macro is launched and the
	 * launched macro fails.
	 */
	void setReturnCode(int iReturnCode);
/* End JDU */

  /** @nodoc */
  void CATPLMInitSessionCmdConnectOkNotifCB(CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);


protected:

	/** @nodoc
	 * Name of the application. Also the name of its resource file.
	 */
  CATString _applicationName;


private:
  
	/** @nodoc
	 * These OnIdle callbacks are related to -workbench and -e options
	 * OnIdleNewCB runs the FileNew or FileOpen if requested
   *   (this must be done at first).
	 * OnIdleAppCB loads the requested App,
	 * OnIdleCB runs the commands.
	 */
  static void OnIdleNewCB(CATCommand * ToClient, int, CATCommand *);
  void OnIdleNew();
  static void OnIdleAppCB (CATCommand * ToClient, int, CATCommand *);
  void OnIdleApp ();
  static void OnIdleCmdCB(CATCommand * ToClient, int, CATCommand *);
  void OnIdleCmd();

  static CATBoolean _firstSSO;

  void OnErrorCB(CATCallbackEvent, void *, CATNotification *,
		 CATSubscriberData, CATCallback);
  void ErrorPanelCB(CATCommand *, CATNotification *, CATCommandClientData);
  
  CATNotifPropagationMode AnalyseNotification(CATCommand *, CATNotification *);
  int  IsOption(const char * arg, const char * option = NULL);
  void ReadArgs(const CATString & command,
		int & counter,
		int argc,
		CATListOfCATUnicodeString argv);
  
  int _Visibility; // booleen (utile sur windows only)

//DBI-->
#ifdef  _WINDOWS_SOURCE
  // TRUE si CNext est lance avec l'option /embedding
  CATBoolean   _OleServer;
#endif//_WINDOWS_SOURCE
//<--DBI

  CATListOfCATString        _commands;
  CATListOfCATUnicodeString _args;
  CATListOfCATUnicodeString _workbenches;
  CATUnicodeString _3DXMLToOpen;
  
  CATLicenseManagerInit * _lminit;
/* Begin JDU */
  int _returnCode;
/* End JDU */

  CATString _wb, _app;

  CATBoolean _batchMode;
  CATBoolean _AfrTestMode;

#ifdef _WINDOWS_SOURCE
  int _Count;
  int _TimerOn;      // booleen
  void OnTimer();
  static void TimerCallBack();
#endif
};

#endif
