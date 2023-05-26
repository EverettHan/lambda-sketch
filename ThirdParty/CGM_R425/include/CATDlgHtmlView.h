#ifndef CATDlgHtmlView_H
#define CATDlgHtmlView_H

// NCT : activate CATDLGHTMLVIEW_FORBID_DEPRECATED before including CATDlgHtmlView.h to validate new architecture
//#define CATDLGHTMLVIEW_FORBID_DEPRECATED

#include "CATDlgHtml.h"

#include "CATDlgControl.h"

class CATNotification;
class l_CATDlgHtmlView;

#ifndef CATDLGHTMLVIEW_FORBID_DEPRECATED
class IDispatch;

// NCT : CWnd is useless here, but implicitely used by CATPMBHtmlView.h
class CWnd;
#endif // !CATDLGHTMLVIEW_FORBID_DEPRECATED

/**
 * This class lets encapsulate a Web Browser component
 */
class ExportedByCATDlgHtml CATDlgHtmlView : public CATDlgControl
{
	CATDeclareClass;

public:
	/**
	 * Constructor
	 * @param iParent the parent Dialog object
	 * @param iName the object name
	 * @param iStyle the object style
	 */
	CATDlgHtmlView(CATDialog * iParent, const CATString& iName, CATDlgStyle iStyle = NULL);

	/**
	 * Destructor
	 * You should not call this destructor yourself, but rather call RequestDelayedDestruction
	 */
	virtual ~CATDlgHtmlView();

#ifdef DRIVER_WINDOWS
	/**
	 * Use Edge instead of IE when available (experimental support)
	 * @return 1 on success
	 */
	int UseEdgeBrowser();
#endif

	/**
	 * Navigate to a new url
	 * @param iURL the new url
	 */
	void Navigate(const CATUnicodeString& iURL);

	/**
	 * Navigate back in the url history
	 */
	void GoBack();

	/**
	 * Navigate forward in the url history
	 */
	void GoForward();

	/**
	 * Refresh the current page
	 */
	void Refresh();

	/**
	 * Stop the current page loading
	 */
	void Stop();

	/**
	 * Get the current url location
	 * @return the url location
	 */
	CATUnicodeString GetLocationURL();

	/**
	 * Get information about the last navigation error
	 * @param oErrorCode the error code
	 * @param oUrl the url which failed to load properly
	 * @param oFrame the name of the frame where the error occured
	 */
	void GetLastNavigateError(int& oErrorCode, CATUnicodeString& oUrl, CATUnicodeString& oFrame);

	/**
	 * Set a value indicating whether any dialog boxes can be shown
	 * @param iFlag set to TRUE to forbid any dialog boxes, set to FALSE (default) to allow any dialog boxes
	 */
	void SetSilent(CATBoolean iFlag);

	/**
	 * Set a value indicating whether popup window can be shown
	 * @param iFlag set to TRUE to forbid any popup window, set to FALSE (default) to allow any popup window
	 */
	void SetNoPopup(CATBoolean iFlag);

	/**
	 * Run javascript script in web page
	 * @param iScript the script to run
	 */
	void RunScript(const CATUnicodeString& iScript);

	/**
	 * Cancel the action associated with a notification
	 * @param iNotification the notification whose action must be canceled (must be a CATDlgHtmlViewBeforeNavigateNotification / CATDlgHtmlViewCloseNotification / CATDlgHtmlViewPopupOpenNotification)
	 */
	void CancelActionForNotification(CATNotification * iNotification);

	/**
	 * Provide a CATDlgHtmlView container during a CATDlgHtmlViewPopupOpenNotification notification
	 * @param iNotification the notification for which the container is provided (must be a CATDlgHtmlViewPopupOpenNotification)
	 * @param iPopupContainer the popup container
	 */
	void SetPopupContainerForNotification(CATNotification * iNotification, CATDlgHtmlView * iPopupContainer);

	/**
	 * Get internal object
	 * @return the internal object
	 */
	virtual l_CATDialog * GetLetterObject();

	/**
	 * Reset the internal object
	 */
	virtual void ResetLetterObject();

private:
	// Forbidden constructors
	CATDlgHtmlView(CATDlgHtmlView&);
	CATDlgHtmlView& operator = (CATDlgHtmlView&);

	l_CATDlgHtmlView * _plHtmlView;

#ifndef CATDLGHTMLVIEW_FORBID_DEPRECATED

	/************************************/
	/*                                  */
	/* FOLLOWING METHODS ARE DEPRECATED */
	/*                                  */
	/************************************/

public:
	/**
	 * @deprecated
	 * You should create a CATDlgHtmlView using CATDlgHtmlView(CATDialog *, const CATString&) constructor, and call Navigate(const CATUnicodeString&) afterwards
	 *
	 * Helper to create a CATDlgHtmlView and navigate to a specific url
	 * @param iParent the parent Dialog object
	 * @param iURL the url to load in the Web Browser (empty string means 'about:blank')
	 * @param pDisp
	 * @return a new CATDlgHtmlView object
	 */
	static CATDlgHtmlView * Create(CATDialog * iParent, const CATUnicodeString& iURL, IDispatch * pDisp = NULL);

	/**
	 * @deprecated
	 * You should create a CATDlgHtmlView using CATDlgHtmlView(CATDialog *, const CATString&) constructor, and call Navigate(const CATUnicodeString&) afterwards
	 *
	 * Constructor
	 * @param iParent the parent Dialog object
	 * @param iName the object name
	 * @param iURL the url to load in the Web Browser (empty string means 'about:blank')
	 * @param pDisp
	 */
	CATDlgHtmlView(CATDialog * iParent, const CATString& iName, const CATUnicodeString& iURL, IDispatch * pDisp = NULL);

	/**
	 * @deprecated
	 * No replacement, old CATDlgFrame superclass allowed DELPsyReportDlg.cpp to use these methods
	 */
	void SetGridColumnResizable(short int iColumnIndex, int iResizableFlag = 1);
	void SetGridRowResizable(short int iRowIndex, int iResizableFlag = 1);

	/**
	 * @deprecated
	 * No replacement, "Home" has no sense when embedded into application
	 *
	 * Navigate to home page ('about:blank' when home page is meaningless)
	 */
	void GoHome();

	/**
	 * @deprecated
	 * No replacement, default web browser shortcuts shouldn't be deactivated
	 *
	 * Set a value indicating whether accelerators may be overriden by application
	 * @param iFlag set to TRUE (default) to activate default Web Browser shortcuts, set to FALSE to allow application shortcuts
	 */
	void OverrideAccelerators(CATBoolean iFlag);

	/**
	 * @deprecated
	 * No replacement, seems to be unused now
	 *
	 * Forces the redraw of the web browser window
	 * This is used to by pass window refresh issues with popup windows
	 */
	void RedrawBrowser();

	/**
	 * @deprecated
	 * You should use CATDlgHtmlViewNavigationCompleteNotification::ClassName() to be notified when url loading is complete
	 *
	 * Get the notification sent when url loading is complete
	 * @return the notification
	 */
	CATNotification * GetDownloadCompleteNotification() const;

	/**
	 * @deprecated
	 * You should use CATDlgHtmlViewNavigationErrorNotification::ClassName() to be notified when an error occurs during url loading
	 *
	 * Get the notification sent when an error occurs during url loading
	 * @return the notification
	 */
	CATNotification * GetNavigationErrorNotification() const;

#ifdef DRIVER_WINDOWS
	/**
	 * @deprecated
	 * RunScript and CATDlgHtmlViewJavaScriptNotification should be sufficient to avoid using this method
	 *
	 * @warning - WINDOWS ONLY - you should avoid using this method
	 *
	 * Get the active document automation object, if any
	 * @return the document automation object
	 */
	LPDISPATCH GetDocument();

	/**
	 * @deprecated
	 * RunScript and CATDlgHtmlViewJavaScriptNotification should be sufficient to avoid using this method
	 *
	 * @warning - WINDOWS ONLY - you should avoid using this method
	 *
	 * Get the application automation object if accessible
	 * @return the application automation object
	 */
	LPDISPATCH GetWebApplication();
#endif

protected:
	/**
	 * @deprecated
	 * You should create a CATDlgHtmlView using CATDlgHtmlView(CATDialog *, const CATString&) constructor, and call Navigate(const CATUnicodeString&) afterwards
	 *
	 * @param iParent the parent Dialog object
	 * @param iURL the url to load in the Web Browser (empty string means 'about:blank')
	 * @param pDisp
	 */
	CATDlgHtmlView(CATDialog * iParent, const CATUnicodeString& iURL, IDispatch * pDisp);

#endif // !CATDLGHTMLVIEW_FORBID_DEPRECATED
};

#endif
