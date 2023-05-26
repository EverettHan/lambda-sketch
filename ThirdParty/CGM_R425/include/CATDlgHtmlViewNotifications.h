#ifndef CATDlgHtmlViewNotifications_H
#define CATDlgHtmlViewNotifications_H

#include "DI0PANV2.h"

//#include "CATDlgUtility.h"

#include "CATNotification.h"

#include "CATBoolean.h"
#include "CATUnicodeString.h"

class CATDlgHtmlView;

/**
 * This notification is sent when a navigation operation begins
 */
class ExportedByDI0PANV2 CATDlgHtmlViewDownloadBeginNotification : public CATNotification
{
	CATDeclareClass;

public:
	/**
	 * Constructor
	 */
	CATDlgHtmlViewDownloadBeginNotification();

	/**
	 * Destructor
	 */
	virtual ~CATDlgHtmlViewDownloadBeginNotification();
};

/**
 * This notification is sent when a navigation operation finishes, is halted or fails
 */
class ExportedByDI0PANV2 CATDlgHtmlViewDownloadCompleteNotification : public CATNotification
{
	CATDeclareClass;

public:
	/**
	 * Constructor
	 */
	CATDlgHtmlViewDownloadCompleteNotification();

	/**
	 * Destructor
	 */
	virtual ~CATDlgHtmlViewDownloadCompleteNotification();
};

/**
 * This notification is sent before a navigation occurs.
 */
class ExportedByDI0PANV2 CATDlgHtmlViewBeforeNavigateNotification : public CATNotification
{
	CATDeclareClass;

public:
	/**
	 * Constructor
	 * @param iUrl the url where navigation will occur
	 */
	CATDlgHtmlViewBeforeNavigateNotification(const CATUnicodeString& iUrl);

	/**
	 * Destructor
	 */
	virtual ~CATDlgHtmlViewBeforeNavigateNotification();

	/**
	 * Get the loaded url
	 * @return the loaded url
	 */
	const CATUnicodeString& GetUrl();

private:
	CATUnicodeString _url;
};

/**
 * This notification is sent when a navigation to a link is completed on a window element or a frameSet element.
 */
class ExportedByDI0PANV2 CATDlgHtmlViewNavigationCompleteNotification : public CATNotification
{
	CATDeclareClass;

public:
	/**
	 * Constructor
	 * @param iUrl the url that what navigated to
	 */
	CATDlgHtmlViewNavigationCompleteNotification(const CATUnicodeString& iUrl);

	/**
	 * Destructor
	 */
	virtual ~CATDlgHtmlViewNavigationCompleteNotification();

	/**
	 * Get the loaded url
	 * @return the loaded url
	 */
	const CATUnicodeString& GetUrl();

private:
	CATUnicodeString _url;

public:
	/**
	 * @deprecated
	 * You should create a CATDlgHtmlViewNavigationCompleteNotification using CATDlgHtmlViewNavigationCompleteNotification(const CATUnicodeString&)
	 *
	 * Constructor
	 */
	CATDlgHtmlViewNavigationCompleteNotification();

	/**
	 * @deprecated
	 * You should use GetUrl() method to access the url
	 */
	CATUnicodeString loadedURL ; // url that was loaded
};

/**
 * This notification is sent when a navigation window is being close.
 */
class ExportedByDI0PANV2 CATDlgHtmlViewCloseNotification : public CATNotification
{
	CATDeclareClass;

public:
	/**
	 * Constructor
	 */
	CATDlgHtmlViewCloseNotification();

	/**
	 * Destructor
	 */
	virtual ~CATDlgHtmlViewCloseNotification();
};

/**
 * This notification is sent when a navigation to a hyperlink fails.
 */
class ExportedByDI0PANV2 CATDlgHtmlViewNavigationErrorNotification : public CATNotification
{
	CATDeclareClass;

public:
	/**
	 * Constructor
	 */
	CATDlgHtmlViewNavigationErrorNotification();

	/**
	 * Destructor
	 */
	virtual ~CATDlgHtmlViewNavigationErrorNotification();
};

/**
 * This notification is sent when the enable state of a command has changed.
 */
class ExportedByDI0PANV2 CATDlgHtmlViewStateChangeNotification : public CATNotification
{
	CATDeclareClass;

public:
	/**
	 * Constructor
	 * @param iID the command identifier
	 * @param iState the command state
	 */
	CATDlgHtmlViewStateChangeNotification(CATLONG32 iID, CATBoolean iState);

	/**
	 * Destructor
	 */
	virtual ~CATDlgHtmlViewStateChangeNotification();

	/**
	 * Get the command identifier
	 * @return the command identifier
	 */
	CATLONG32 GetCommandId();

	/**
	 * Get the command state
	 * @return the command state
	 */
	CATBoolean GetCommandState();

private:
	CATLONG32 _commandId;
	CATBoolean _commandState;

public:
	/**
	 * @deprecated
	 * You should create a CATDlgHtmlViewStateChangeNotification using CATDlgHtmlViewStateChangeNotification(CATLONG32, CATBoolean)
	 *
	 * Constructor
	 */
	CATDlgHtmlViewStateChangeNotification();

	/**
	 * @deprecated
	 * You should use GetCommandId() method to access the command identifier
	 */
	long _command;

	/**
	 * @deprecated
	 * You should use GetCommandState() method to access the command state
	 */
	CATBoolean _state;
};

/**
 * This notification is sent when a web page requests a popup to be opened.
 */
class ExportedByDI0PANV2 CATDlgHtmlViewPopupOpenNotification : public CATNotification
{
	CATDeclareClass;

public:
	/**
	 * Constructor
	 * @param iContextUrl the url of the page which opens the popup
	 * @param iPopupUrl the url of the popup being opened
	 */
	CATDlgHtmlViewPopupOpenNotification(const CATUnicodeString& iContextUrl, const CATUnicodeString& iPopupUrl);

	/**
	 * Destructor
	 */
	virtual ~CATDlgHtmlViewPopupOpenNotification();

	/**
	 * Get the url context
	 * @return the url context
	 */
	const CATUnicodeString& GetContextUrl();

	/**
	 * Get the popup url
	 * @return the popup url
	 */
	const CATUnicodeString& GetPopupUrl();

private:
	CATUnicodeString _contextUrl;
	CATUnicodeString _popupUrl;

public:
	/**
	 * @deprecated
	 * You should use SetPopupContainer to assign the popup container
	 */
	IDispatch ** _appToUse;
};

/**
 * Class to notify the application that a JS notification has been received
 */
class ExportedByDI0PANV2 CATDlgHtmlViewJavaScriptNotification : public CATNotification
{
	CATDeclareClass;

public:
	/**
	 * Constructor
	 * @param iNotifURL the url associated to the javascript notification
	 * @param iNotifData the data associated to javascript notification
	 * @param iNotifDataLength the data length
	 */
	CATDlgHtmlViewJavaScriptNotification(const CATUnicodeString& iNotifURL, const char * iNotifData, int iNotifDataLength);

	/**
	 * Destructor
	 */
	virtual ~CATDlgHtmlViewJavaScriptNotification();

	/**
	 * Get the javascript notification url
	 * @return the url
	 */
	const CATUnicodeString& GetUrl();

	/**
	 * Get the javascript notification data
	 * @return the data (NULL terminated, you must not destroy it nor modify it)
	 */
	const char * GetData();

	/**
	 * Get the javascript notification data length
	 * @return the data length
	 */
	int GetDataLength();

private:
	CATUnicodeString _url;
	char * _data;
	int _dataLength;
};

#endif
