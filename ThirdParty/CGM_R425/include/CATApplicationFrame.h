#ifndef CATApplicationFrame_H
#define CATApplicationFrame_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

#include "CATAfrFoundation.h"
#include "CATEventSubscriber.h"
#include "CATCommand.h"
#include "CATUnicodeString.h"

class CATDialog;
class CATDlgBox;
class CATDlgWindow;
class CATDlgFrame;

class l_CATApplicationFrame;
class CATInteractiveApplication;
class CATString;
class CATUnicodeString;

/**
* Unsigned long.
*/

typedef unsigned long CATULong;

/**
* @nodoc
* Old name.
*/
#define GetApplicationFrame GetFrame

/**
* Class representing the application main window model.
* <b>Role</b>: An application frame is a specialized window which
* allows to start commands and perform standard interactions. The 
* <tt>CATApplicationFrame</tt> class corresponds to the model of 
* this window. The <tt>CATApplicationFrame</tt> class is also able
* to create workshops and workbenches since workshop and workbench 
* factories are defined as its data extensions.
*/
class ExportedByCATAfrFoundation CATApplicationFrame: public CATEventSubscriber
{
    CATDeclareClass;
    
public:
    
    /** @nodoc */
    CATApplicationFrame(CATInteractiveApplication *,
        const CATString & declarationSet);
    virtual ~CATApplicationFrame();
    
    /**  
    * Retrieves a pointer to the application frame.
    * @return 
    *   The application frame pointer.
    *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
    *   returned value.
    */
    static CATApplicationFrame * GetFrame();
    
    /** 
     * Type of message to displays in the status bar.
     * @param Information
     *  Simple text.
     * @param Prompt
     *  Internal usage.
     * @param MultiDocumentPrompt
     *  Internal usage.
     * @param ShortPrompt
     *  Internal usage.
     * @param LogMessage
     *  Internal usage.
     */
    enum MessageType {Information, Prompt, MultiDocumentPrompt, ShortPrompt, LogMessage};
    
    /**
    * Displays a message in the status bar.
    * @param iMessageType
    *   The message type.
    *   <br><b>Legal values</b>: The parameter must
    *   be set to <tt>CATApplicationFrame::Information</tt>.
    * @param iMessage
    *   The message.
    */
    void SetMessage(MessageType iMessageType, 
        const CATUnicodeString & iMessage);
    
        /** 
        * @nodoc
        * Displays text in the keyboard area field.
    */  
//    void SetKeyboardText(const CATUnicodeString &);
    
    /** 
    * @nodoc
    * Displays the keyboard area.
    */
    void ShowKeyboard();
    
    /**
    * @nodoc
    * Removes the keyboard area from display.
    */
    void HideKeyboard();
    
    /**
    * Displays a toolbar.
    * @param iPaletteName
    *  The name of the toolbar to set visible. This name is third argument of the
    * @href NewAccess macro. 
    *  <pre>
    *  NewAccess(CATCmdContainer, pMyTlb, iPaletteName);
    * </pre>
    */
    void ShowPalette(const CATString & iPaletteName);
    
    /**
    * Hides a toolbar.
    * @param iPaletteName
    *  The name of the toolbar to set invisible. This name is third argument of the
    * @href NewAccess macro. 
    *  <pre>
    *  NewAccess(CATCmdContainer, pMyTlb, iPaletteName);
    * </pre>
    */
    void HidePalette(const CATString & paletteName);
    
    /** @nodoc */  
    void SetVisibility(CATULong nState);
    
    /**
    * Changes the cursor mouse into a busy cursor.
    * <br><b>Role</b>: Use this method to indicate that
    * your application is busy. This method calls the
    * <tt>SetBusyCursor</tt> method of the @href CATInteractiveApplication class.
    */
    static void SetBusyCursor() ;
    
    /** 
    * Returns the main window.
    * <br><b>Role</b>: This method returns:
    *  <ul>
    *    <li>If no document is open: the only one <tt>CATApplicationDocument</tt> instance. The
    *        instance that you retrieve also with the @href #GetApplicationDocument method</li>
    *    <li>Otherwise: a dialog object dedicated to the current @href CATFrmEditor. This dialog 
    *      object is an invisible dialog object which contains all the dialog objects related to 
    *        the document: all its windows and all its dialog boxes. Thanks to this object, 
    *         the application can hide/deactivate all the dialog objects when the document
    *         loses the focus.</li>
    *  </ul>
    * It enables you mainly to find a parent for your dialog box:
    *  <ul>
    *  <li>If you create a dialog box which is document's independent, use the 
    *  @href #GetApplicationDocument method; your dialog box will be always visible. For
    *   example, if you create a dialog box inside a command launched from the General workshop 
    *   addin ( @href CATIAfrGeneralWksAddin ) you will use the <tt>GetApplicationDocument</tt> method</li>
    * <li>If you create a dialog box which is in relationship with a document, use this
    *     method. In generally, the commands associated with a document use this method.</li>
    * </ul>
    * @return
    *    A dialog object.  
    *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
    *   returned value.
    */    
    CATDlgWindow * GetMainWindow();
    
    /** @nodoc */  
    void CreateMainWindow(CATInteractiveApplication *);
    
    /**  
     * Returns the application document.
     * <br><b>Role</b>: This method returns the document window of the application. Refer to the
     * @href #GetMainWindow method for its usage.
     * @return
     *   The application document.
     *   <br><b>Lifecycle rules deviation</b>: This method doesn't AddRef the 
     *   returned value.
     *
     */  
    CATDlgWindow * GetApplicationDocument();
    
    /** 
    * @nodoc
    * To add components to the permanent dialog area.
    */    
    CATDialog * GetPermanentDialogArea();
    
    /** 
    * @nodoc 
    * Returns a parent component for a viewer inside the frame.
    */
    CATDlgBox * GetViewerFrame();
    
    /** 
    * @nodoc
    * Get a pointer to the current viewer.
    */
    CATDialog * GetViewer();
    
    /** 
    * @nodoc
    * Attach a viewer at the proper position inside the frame.
    */  
    void SetViewer(CATDialog * viewer);
    
    /**
    * Returns the internal name of the current workshop.
    */
    CATString GetCurrentWorkshop();
    
    /**
    * Returns the internal name of the current workbench.
    */
    CATString GetCurrentWorkbench();
    
    /** 
    * @nodoc
    * Changes the current workshop.
    * <br><b>Role</b>: ApplicationFrame internal use only.
    * Use @href CATFrmEditor#SetActivePath instead.
    */
    void SetCurrentWorkshop  (const CATString & name);
    
    /** 
    * @nodoc
    * Discards the current workshop.
    * <br><b>Role</b>: ApplicationFrame internal use only.
    */
    void UnsetCurrentWorkshop();
    
    /**
    * Returns a resource value.
    * <br><b>Role</b>: Reads a resource in the Application resource file (CATRsc file).
    * @param iResourceKey
    *  The resource key.
    * @param oResourceValue
    *  The resource value.
     * @return
     * Returns S_OK if the resource was found and correctly read, else returns E_FAIL.
    */
    HRESULT GetApplicationResource (CATString & iResourceKey, CATString & oResourceValue);

    /** @nodoc */
    HRESULT SetApplicationName (CATUnicodeString & iString);
    /** @nodoc */
    HRESULT GetApplicationName (CATUnicodeString & oString);
    
    /** @nodoc */  
    HRESULT SetCopyrightInfo (CATUnicodeString & iString);
    /** @nodoc */
    HRESULT GetCopyrightInfo (CATUnicodeString & oString);
    
    /** @nodoc */  
    HRESULT SetReleaseName (CATUnicodeString & iString);
    /** @nodoc */
    HRESULT GetReleaseName (CATUnicodeString & oString);
    
    /** @nodoc */  
    HRESULT SetSplashScreen (CATString & iString);
    /** @nodoc */
    HRESULT GetSplashScreen (CATString & oString);
    
    /** @nodoc */  
    HRESULT SetApplicationIcon (CATString & iString);
    /** @nodoc */
    HRESULT GetApplicationIcon (CATString & oString);
    
    /** @nodoc */  
    HRESULT SetDocURLMappingFile (CATString & iString);
    /** @nodoc */
    HRESULT GetDocURLMappingFile (CATString & oString, 
                                  const char * iKey="DocumentMap.Name");
    /** @nodoc */
    HRESULT GetDocURLUserMappingFile (CATString & oString, 
                                      const char * iKey="DocumentMap.Name");
    
    /** @nodoc */
    HRESULT SetDocAccessDir (CATString & iString);
    /** @nodoc */
    HRESULT GetDocAccessDir (CATString & oString);
    
    /** @nodoc */  
    HRESULT SetApplicationLogo (CATString & iString);
    /** @nodoc */
    HRESULT GetApplicationLogo (CATString & oString);
    
    /** @nodoc */  
    HRESULT SetBackgroundImage (CATString & iString);
    /** @nodoc */
    HRESULT GetBackgroundImage (CATString & oString);
    
    /** @nodoc */  
    HRESULT SetDialogBoxBottom (CATString & iString);
    /** @nodoc */
    HRESULT GetDialogBoxBottom (CATString & oString);

    /** @nodoc */
    HRESULT GetLogonImage      (CATString & oImageName) ;
    
    /** 
    * @nodoc 
    * Display blocked panels ?
    */
    int  GetDisplayAlertsMode();
    /** @nodoc */
    void SetDisplayAlertsMode(int);
    
    /** 
    * @nodoc
    * Quits the application.
    */
    void Destroy();
    
    /**
    * @nodoc
    * Returns the access under construction name.
    * <br><b>Role</b>: Manage the name of the access under 
    * construction for the headers to be assigned to the 
    * right access.
    */
    const CATString & GetAccessUnderConstruction();
    /** @nodoc */
    void SetAccessUnderConstruction(const CATString & Access);

    /**
    * @nodoc
    * Retrieves the Callback manager which sends the CATAfrAccessChangedNotification
    */
    CATCallbackManager *GetDispatcher();	

	/**
	* @nodoc
	* HEB - IR-797196 - Deployed workbench need to be reloaded
	* Callback event emitted when the license is modified dynamicaly.
	* It is dipatched when the UI has been reloaded.
	*
	*/
	CATDeclareCBEvent(DYNAMIC_LICENSE_CHANGED_DW);
    
    
 private:
     
     enum CATDialogBitmap {RightBottomCornerBackground,
         RightBottomCornerBackgroundP1,
         RightBottomCornerBackgroundP2IX,
         RightBottomCornerBackgroundP1IX,
         ClientMDIBackgroundNT,
         ClientMDIBackgroundIX,
         DialogBackgroundP2,
         DialogBackground};
     CATInteractiveApplication *_appli;
     
     l_CATApplicationFrame * _letter;
     
     CATUnicodeString _ApplicationName;
     CATUnicodeString _CopyrightInfo;
     CATUnicodeString _ReleaseName;
     CATString _ApplicationResourceFile;
     CATString _SplashScreen;
     CATString _ApplicationIcon;
     CATString _DocURLMappingFile;
     CATString _DocURLUserMappingFile;
     CATString _DocAccessDir;
     
     CATString _ApplicationLogo;
     CATString _BackgroundImage;
     CATString _DialogBoxBottom;

     friend class CATWorkbench;
};
#endif
