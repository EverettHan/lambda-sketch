//===================================================================
// COPYRIGHT Dassault Systemes 2012-12-17
//===================================================================
// 2012-12-17 Creation: D6K
//===================================================================

#ifndef CATCefPlugin_Tools_H
#define CATCefPlugin_Tools_H

// ChromiumEmbedded
#include "CATCefPlugin_Structs.h"

extern "C" {
  
  // Utility methods
  // implemented out of plugin 
  // used in plugin  
  typedef struct _catceftools_c
  {
    catcefstringutf8_c*             (CONV_CALL * getusercefpreferences)           ();
    void                            (CONV_CALL * catcallonexit)                   (int (*ifunct)(int));
    void                            (CONV_CALL * catexit)                         (int irc);
    bool                            (CONV_CALL * coverageenabled)                 ();
    catcefbinary_c*                 (CONV_CALL * enablecoverage)                  (const char* i_path);
    catcefstringutf8_c*             (CONV_CALL * fetchsyscookie)                  (const catcefstringutf8_c* i_name, const catcefstringutf8_c* i_url);  
    int                             (CONV_CALL * getcatiareleaselevelinfo)        ();
    const char*                     (CONV_CALL * getenv)                          (const char* env_var );
    catcefstringutf8_c*             (CONV_CALL * getjsonmodulemap)                ();   
    catcefstringutf8_c*             (CONV_CALL * getlabel)                        (const char* i_name);
    catcefstringutf8_c*             (CONV_CALL * getmyappsurl)                    ();
    catcefstringutf8_c*             (CONV_CALL * gettransientticketurl)           (const catcefstringutf8_c* i_servicetoconnect);
    catceftypes_recordmode          (CONV_CALL * getrecordmode)                   ();  
    catcefstringutf8_c*             (CONV_CALL * gettempdirectory)                ();  
    catcefstringutf8_c*             (CONV_CALL * getuserinterfacelanguagename)    ();    
    bool                            (CONV_CALL * pathexist)                       (const catcefstringutf8_c* ipath, bool idirmode);
    void                            (CONV_CALL * posttaskonmainthread)            (void (*iFunct)(void*), void* iParams);
    bool                            (CONV_CALL * processcoverage)                 (const char* i_jsonCoverage);  
    bool                            (CONV_CALL * putenv)                          (const char* env_var );   
    catcefstringutf8_c*             (CONV_CALL * readfrompreferences)             (const char* ireponame, const char* ipreferencename);
    bool                            (CONV_CALL * readfromsettings)                (const char* ireponame, const char* isettingname, int * osettingval); 
    catcefstringutf8_c*             (CONV_CALL * remapurl)                        (const catcefstringutf8_c* ioriurl);  
    void                            (CONV_CALL * replayrestart)                   ();
    void                            (CONV_CALL * replaysuspend)                   ();
    catcefstringutf8_c*             (CONV_CALL * saveinpreference)                (const char* ireponame, const char* ipreferencename, const catcefstringutf8_c* ivalue);
    bool                            (CONV_CALL * shoulddispatcheventsonmainthread)(); 
    void                            (CONV_CALL * startloginlistening)             ();
    void                            (CONV_CALL * stoploginlistening)              ();
    void                            (CONV_CALL * asynctrylogin)                   (int iRemainingAttempts, void (*iFailureCB)(int,int));
    catcefhttpresponse_c*           (CONV_CALL * sendhttprequest)                 (const catcefstringutf8_c* , const catcefstringutf8_c* , const catcefstringutf8_c* , const catcefbinary_c * );
    unsigned int                    (CONV_CALL * getprocessid)                    ();
    
  } catceftools_c;
}

#endif
