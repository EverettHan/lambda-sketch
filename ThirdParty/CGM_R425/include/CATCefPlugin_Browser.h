//===================================================================
// COPYRIGHT Dassault Systemes 2012-10-15
//===================================================================
//
// Abstract: This class is for private use only.
//
//===================================================================
// 2022-10-13 Creation: JBX
//===================================================================

#ifndef CATCefPlugin_Browser_H
#define CATCefPlugin_Browser_H

// ChromiumEmbedded
#include "CATCefPlugin_Structs.h"
#include "CATCefPlugin_Defines.h"

extern "C" {
    
  // pixel image for OSR  
  typedef struct _catpixelimage_c
  {
    bool           (CONV_CALL * isreadonly)       (_catpixelimage_c* );
    void           (CONV_CALL * getsize)          (_catpixelimage_c* , int&, int&);
    unsigned char* (CONV_CALL * allocatebuffer)   (_catpixelimage_c* , const int ixsize, const int iysize);
    unsigned char* (CONV_CALL * getpixelstomodify)(_catpixelimage_c* );
    void           (CONV_CALL * ignore_block)     (_catpixelimage_c* , const bool i_ignoreblock); 
    bool           (CONV_CALL * is_ignore_block)  (_catpixelimage_c* ); 
    bool           (CONV_CALL * modify_bgra)      (_catpixelimage_c* , const int ixsize, const int iysize, unsigned char* iPixels);
    int            (CONV_CALL * getpixellength)   (_catpixelimage_c* );
    PLUGIN_DECLARE_BASE(_catpixelimage_c)      
  } catpixelimage_c;
  
  // file dialog Callback  
  typedef struct _catceffiledialogcallback_c
  {    
    void    (CONV_CALL * continue_dlg)  (_catceffiledialogcallback_c*, const int i_selectedFilter, const catcefliststrings_c* i_filePaths);
    void    (CONV_CALL * cancel_dlg)    (_catceffiledialogcallback_c*);
    PLUGIN_DECLARE_BASE(_catceffiledialogcallback_c)    
  } catceffiledialogcallback_c;
  
  // js execution Callback  
  typedef struct _catcefjscallback_c
  {    
    void    (CONV_CALL * onresult)      (_catcefjscallback_c*, const catceftypes_jstype iType, const double iVal, const bool iBool, const catcefstringutf8_c* i_msg);  
    void    (CONV_CALL * onerror)       (_catcefjscallback_c*, const catcefstringutf8_c* i_msg, const catcefstringutf8_c* i_code, const catcefstringutf8_c* i_url, const int i_line, const int i_column);                 
    PLUGIN_DECLARE_BASE(_catcefjscallback_c)    
  } catcefjscallback_c;
       
  // Auth Callback  
  typedef struct _catcefauthcallback_c
  {    
    void    (CONV_CALL * continue_auth)  (_catcefauthcallback_c* ,const catcefstringutf8_c*,const catcefstringutf8_c*);
    void    (CONV_CALL * cancel_auth)    (_catcefauthcallback_c* );  
    PLUGIN_DECLARE_BASE(_catcefauthcallback_c)               
  } catcefauthcallback_c;

  // drag and drop data
  typedef struct _catcefdragdata_c
  {
    // List of authorized content names associated with their values
    // FragmentText > text
    // LinkURL      > URL      + title
    // FragmentHtml > URL      + HTML
    // FilesName    > FileName + DisplayName
    // FileContent  > FileName + FileContent (binary)
    catcefkeysvalues_c*   (CONV_CALL * get_contents)   (_catcefdragdata_c* );    
    bool                  (CONV_CALL * is_empty)       (_catcefdragdata_c* );
    PLUGIN_DECLARE_BASE(_catcefdragdata_c)
  } catcefdragdata_c;

  // media permission Callback  
  typedef struct _catcefPermissiondialogcallback_c
  {    
    void    (CONV_CALL * continue_c)    (_catcefPermissiondialogcallback_c*,catceftypes_permission_request_result);
    PLUGIN_DECLARE_BASE(_catcefPermissiondialogcallback_c)
  } catcefpermissiondialogcallback_c;

  // Notifications interface 
  typedef struct _catcefnotifier_c
  {
    public:  
      void (CONV_CALL *sendasync_genericnotification)              (_catcefnotifier_c*,const catceftypes_notificationtype) ; 
      void (CONV_CALL *sendasync_jscontextnotification)            (_catcefnotifier_c*,const bool i_exists) ;
      void (CONV_CALL *sendasync_jsmessagenotification)            (_catcefnotifier_c*,const catcefliststrings_c* i_messages, const catcefstringutf8_c* i_url, const int i_line, const int i_col, const bool i_recordable, const bool i_captureall);
      void (CONV_CALL *sendasync_titlenotification)                (_catcefnotifier_c*,const catcefstringutf8_c*) ;
      void (CONV_CALL *sendasync_urlnotification)                  (_catcefnotifier_c*,const catcefstringutf8_c*) ;
      void (CONV_CALL *sendasync_downloadprogressnotification)     (_catcefnotifier_c*,const int ,const long long,const long long ,const long long ,const bool ) ;
      void (CONV_CALL *sendasync_downloaddialognotification)       (_catcefnotifier_c*,const int i_id, const catcefstringutf8_c* i_fileName,
                                                                    const catcefstringutf8_c* i_originurl, const catcefstringutf8_c* i_mimetype, const long long i_totalbytes);           
      void (CONV_CALL *sendasync_onloadnotification)               (_catcefnotifier_c*,const bool i_isloading, const catcefstringutf8_c* i_url) ;
      void (CONV_CALL *sendasync_onloaderrornotification)          (_catcefnotifier_c*,const int i_errorcode, const catcefstringutf8_c* i_errorname, const catcefstringutf8_c* i_url, bool iIsMainFrame) ;
      void (CONV_CALL *sendasync_docsizenotification)              (_catcefnotifier_c*,const int i_width, const int i_height) ;
      void (CONV_CALL *sendasync_consolenotification)              (_catcefnotifier_c*,const catcefstringutf8_c* i_message,const catcefstringutf8_c* i_sourceURL,const int i_sourceLine) ;
      void (CONV_CALL *sendasync_zoomnotification)                 (_catcefnotifier_c*,const double i_delta) ;
      void (CONV_CALL *sendasync_webrecordnotification)            (_catcefnotifier_c*,const catcefstringutf8_c* i_data) ;
      void (CONV_CALL *sendasync_onhttpauthnotification)           (_catcefnotifier_c*,const catcefstringutf8_c* i_oriurl, const bool i_isProxy, 
                                                                    const catcefstringutf8_c* i_host, const int i_Port, catcefauthcallback_c * i_cb) ;
      void (CONV_CALL *sendasync_onhtterrornotification)           (_catcefnotifier_c*,const int i_status, const catcefstringutf8_c* i_statustext,const catcefstringutf8_c* i_method, const catcefstringutf8_c* i_url) ;
      void (CONV_CALL *sendasync_infonotification)                 (_catcefnotifier_c*,const catceftypes_notificationlevel i_notiflevel,const catcefstringutf8_c* i_text, const float i_suggestedUptime);
      void (CONV_CALL *sendasync_jsdialognotification)             (_catcefnotifier_c*,const catceftypes_jsdialogtype i_jstype,const catcefstringutf8_c* i_origin, const catcefstringutf8_c* i_message, const catcefstringutf8_c* i_defaultprompttext);
      void (CONV_CALL *sendasync_loginnotification)                (_catcefnotifier_c*,const bool i_success);
      void (CONV_CALL *sendasync_contextmenunotification)          (_catcefnotifier_c*,const contextmenuproperties_c * i_ctxmenu);
      void (CONV_CALL *sendasync_cursornotification)               (_catcefnotifier_c*,const catceftypes_mousecursor i_cursor);
      void (CONV_CALL *sendasync_tooltipnotification)              (_catcefnotifier_c*,const catcefstringutf8_c* i_tooltip);
      void (CONV_CALL *sendasync_onfiledialognotification)         (_catcefnotifier_c*,const catceftypes_filedialogtype i_dialogtype, const catceffiledialogfilter_c** i_filter, const int i_nbfilters, catceffiledialogcallback_c* i_cb);
      void (CONV_CALL *sendasync_keyeventnotification)             (_catcefnotifier_c*,const catceftypes_keytype i_keytype, const int i_vkCode, const int i_charCode, const int i_keyCode, const catceftypes_keymodifiermask i_modifier);
      void (CONV_CALL *sendasync_certificateselectionnotification) (_catcefnotifier_c*,const certicateselection_c * i_selection);
      void (CONV_CALL *sendasync_dragdatanotification)             (_catcefnotifier_c*,catceftypes_dragmodemask);
      void (CONV_CALL *sendasync_popupnotification)                (_catcefnotifier_c*,const popupproperties_c * i_props, const int i_browserid) ; 
      void (CONV_CALL *sendasync_popupclosenotification)           (_catcefnotifier_c*,const int) ;
      void (CONV_CALL *sendasync_onpermissionrequestnotification)  (_catcefnotifier_c*,const catcefstringutf8_c* i_origin, catceftypes_permission_request_mask i_requested_permissions, catcefpermissiondialogcallback_c * i_cb) ;
      void (CONV_CALL *sendasync_closenotification)                (_catcefnotifier_c*) ; 
      PLUGIN_DECLARE_BASE(_catcefnotifier_c)
  } catcefnotifier_c;  

  // Cef client methods 
  // For documentation about these methods, please refer to CATCefClient.h and its methods with same name
  typedef struct _catcefclient_c
  {    
    // Methods    
    bool                      (CONV_CALL * audiomediastreamsenabled)        (_catcefclient_c*);
    bool                      (CONV_CALL * backforwardenabled)              (_catcefclient_c*) ;
    void                      (CONV_CALL * bindto)                          (_catcefclient_c*,const int i_browserid);
    bool                      (CONV_CALL * cacheenabled)                    (_catcefclient_c*);
    void                      (CONV_CALL * canceldownload)                  (_catcefclient_c*,const int); 
    bool                      (CONV_CALL * cangoback)                       (_catcefclient_c*);
    bool                      (CONV_CALL * cangoforward)                    (_catcefclient_c*);
    void                      (CONV_CALL * cdelete)                         (_catcefclient_c*);
    void                      (CONV_CALL * closedevtools)                   (_catcefclient_c*);
    bool                      (CONV_CALL * consolemessageeventsenabled)     (_catcefclient_c*) ;
    void                      (CONV_CALL * copy)                            (_catcefclient_c*);
    void                      (CONV_CALL * createbrowser)                   (_catcefclient_c*,const catcefpluginwindowhandle_c , const rect_int_c* ,const catcefstringutf8_c* , const bool i_enableOffscreen);
    void                      (CONV_CALL * cut)                             (_catcefclient_c*);
    void                      (CONV_CALL * destroybrowser)                  (_catcefclient_c*,const bool i_forceClose);
    void                      (CONV_CALL * dragendedat)                     (_catcefclient_c*,const int , const int , const catceftypes_dragmodemask );
    void                      (CONV_CALL * dragenter)                       (_catcefclient_c*,catcefdragdata_c* ,const mouseevent_c *,const catceftypes_dragmodemask );
    void                      (CONV_CALL * dragleave)                       (_catcefclient_c*,const int , const int );
    void                      (CONV_CALL * dragover)                        (_catcefclient_c*,const mouseevent_c * , const catceftypes_dragmodemask );
    void                      (CONV_CALL * drop)                            (_catcefclient_c*,const mouseevent_c * );
    void                      (CONV_CALL * evaluatejavascript)              (_catcefclient_c*,const catcefstringutf8_c* i_code, const catcefstringutf8_c* i_url, const int i_line, catcefjscallback_c * i_callback);
    void                      (CONV_CALL * executejavascript)               (_catcefclient_c*,const catcefstringutf8_c* i_code, const catcefstringutf8_c* i_url, const int i_line);
    void                      (CONV_CALL*  executescriptbeforeloading)      (_catcefclient_c*,const catcefstringutf8_c* i_code, const catcefstringutf8_c* i_url, const int i_line);
    bool                      (CONV_CALL * fileaccessfromfileurlsenabled)   (_catcefclient_c*);
    // Returned catcefdragdata_c* must be released after use.
    catcefdragdata_c*         (CONV_CALL * getcurrentdragdata)              (_catcefclient_c*);
    catceftypes_dragmodemask  (CONV_CALL * getcurrentdragmode)              (_catcefclient_c*);
    catcefstringutf8_c*       (CONV_CALL * getdefaultdownloaddirectory)     (_catcefclient_c*);
    float                     (CONV_CALL * getdevicepixelratio)             (_catcefclient_c*);
    catcefstringutf8_c*       (CONV_CALL * gethomeurl)                      (_catcefclient_c*);
    int                       (CONV_CALL * getmaxframerate)                 (_catcefclient_c*);
    catceftypes_popupbehavior (CONV_CALL * getpopuppolicy)                  (_catcefclient_c*);
    void                      (CONV_CALL * getsize)                         (_catcefclient_c*,vect_int_c * o_size);
    catcefstringutf8_c*       (CONV_CALL * geturl)                          (_catcefclient_c*);
    void                      (CONV_CALL * goback)                          (_catcefclient_c*);
    void                      (CONV_CALL * goforward)                       (_catcefclient_c*);
    bool                      (CONV_CALL * hasfocusoneditfield)             (_catcefclient_c*);
    bool                      (CONV_CALL * insecurecontentallowed)          (_catcefclient_c*);
    void                      (CONV_CALL * invalidaterect)                  (_catcefclient_c*);
    bool                      (CONV_CALL * isdragging)                      (_catcefclient_c*);
    bool                      (CONV_CALL * javascriptenabled)               (_catcefclient_c*);
    void                      (CONV_CALL * loadcontent)                     (_catcefclient_c*,const catcefstringutf8_c*i_content, const catcefstringutf8_c*i_fakeURL);
    void                      (CONV_CALL * loadurl)                         (_catcefclient_c*,const catcefstringutf8_c*); 
    void                      (CONV_CALL * modifyzoomlevel)                 (_catcefclient_c*,const double);
    void                      (CONV_CALL * paste)                           (_catcefclient_c*);
    bool                      (CONV_CALL * pluginsenabled)                  (_catcefclient_c*);
    void                      (CONV_CALL * redo)                            (_catcefclient_c*);
    void                      (CONV_CALL * registercustomurischeme)         (_catcefclient_c*,const catcefstringutf8_c*);
    void                      (CONV_CALL * reload)                          (_catcefclient_c*,const bool i_ignoreCache);
    bool                      (CONV_CALL * reloadenabled)                   (_catcefclient_c*);
    replayresult_c *          (CONV_CALL * replay)                          (_catcefclient_c*,const catcefstringutf8_c*); 
    bool                      (CONV_CALL * sameoriginpolicyenabled)         (_catcefclient_c*);
    void                      (CONV_CALL * selectall)                       (_catcefclient_c*);
    void                      (CONV_CALL * sendcertificateselection)        (_catcefclient_c*,const int , const int );
    void                      (CONV_CALL * senddownloaddialogresponse)      (_catcefclient_c*,const catceftypes_downloaddialogresponse i_downloaddlgresp, const catcefstringutf8_c* i_downloadpath);
    void                      (CONV_CALL * sendfocusevent)                  (_catcefclient_c*,const bool);
    void                      (CONV_CALL * sendjsdialogesponse)             (_catcefclient_c*,const bool,const catcefstringutf8_c*);
    void                      (CONV_CALL * sendkeyevent)                    (_catcefclient_c*,const catcefkeyevent_c*);
    void                      (CONV_CALL * sendmouseclickevent)             (_catcefclient_c*,const int , const int , const catceftypes_mousebutton , const catceftypes_mousebuttonstate , const int);
    void                      (CONV_CALL * sendmousemoveevent)              (_catcefclient_c*,int i_x, int i_y, bool i_leave); 
    void                      (CONV_CALL * sendmousewheelevent)             (_catcefclient_c*,const int i_x, const int i_y, const int i_deltaX, const int i_deltaY);
    void                      (CONV_CALL * sendmultitouchevent)             (_catcefclient_c*,const touchevent_c*, const int);
    void                      (CONV_CALL * setaudiomediastreamsenabled)     (_catcefclient_c*,const bool); 
    void                      (CONV_CALL * setbackforwardenabled)           (_catcefclient_c*,const bool);
    void                      (CONV_CALL * setcacheenabled)                 (_catcefclient_c*,const bool);
    void                      (CONV_CALL * setconsolemessageeventsenabled)  (_catcefclient_c*,const bool);
    void                      (CONV_CALL * setdefaultdownloaddirectory)     (_catcefclient_c*,const catcefstringutf8_c*);
    void                      (CONV_CALL * setdevicepixelratio)             (_catcefclient_c*,const float i_ratio);
    void                      (CONV_CALL * setfileaccessfromfileurlsenabled)(_catcefclient_c*,const bool);
    void                      (CONV_CALL * sethiddenstate)                  (_catcefclient_c*,const bool); 
    void                      (CONV_CALL * sethomeurl)                      (_catcefclient_c*,const catcefstringutf8_c*);
    void                      (CONV_CALL * setinsecurecontentallowed)       (_catcefclient_c*,const bool);
    void                      (CONV_CALL * setjavascriptenabled)            (_catcefclient_c*,const bool);
    void                      (CONV_CALL * setmaxframerate)                 (_catcefclient_c*,const int);
    void                      (CONV_CALL * setpluginsenabled)               (_catcefclient_c*,const bool);
    void                      (CONV_CALL * setpopuppolicy)                  (_catcefclient_c*,const catceftypes_popupbehavior);
    void                      (CONV_CALL * setreloadenabled)                (_catcefclient_c*,const bool);
    void                      (CONV_CALL * setsameoriginpolicyenabled)      (_catcefclient_c*,const bool);
    void                      (CONV_CALL * setsize)                         (_catcefclient_c*,const vect_int_c * i_size);
    void                      (CONV_CALL * settransparencyenabled)          (_catcefclient_c*,const bool);
    void                      (CONV_CALL * setvideomediastreamsenabled)     (_catcefclient_c*,const bool);
    void                      (CONV_CALL * setzoomenabled)                  (_catcefclient_c*,const bool);
    void                      (CONV_CALL * setzoomlevel)                    (_catcefclient_c*,const double);
    void                      (CONV_CALL * startdevtools)                   (_catcefclient_c*);
    void                      (CONV_CALL * stoploading)                     (_catcefclient_c*);
    bool                      (CONV_CALL * transparencyenabled)             (_catcefclient_c*);
    catpixelimage_c*          (CONV_CALL * trygetsafepixelimage)            (_catcefclient_c*);
    void                      (CONV_CALL * undo)                            (_catcefclient_c*);
    void                      (CONV_CALL * unlockpixelimage)                (_catcefclient_c*);
    bool                      (CONV_CALL * videomediastreamsenabled)        (_catcefclient_c*);
    bool                      (CONV_CALL * zoomenabled)                     (_catcefclient_c*);
    PLUGIN_DECLARE_BASE(_catcefclient_c)
  } catcefclient_c;    
  
} // end of extern "C" 

#endif
