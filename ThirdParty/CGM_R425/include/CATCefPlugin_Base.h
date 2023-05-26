// COPYRIGHT DASSAULT SYSTEMES 2015

#ifndef CATCefPlugin_Base_H
#define CATCefPlugin_Base_H

#include "CATCefPlugin.h"
#include "CATCefPlugin_Defines.h"

#define PLUGIN_DECLARE_BASE(StrucType)   void * internal_data_c;                     \
                                         void (CONV_CALL* add_ref_c) (StrucType* );  \
                                         void (CONV_CALL* release_c) (StrucType* ); // return 1 if the object has been deleted


#define PLUGIN_DEL(obj)       { if (obj && obj->del_c)                                                         \
                                  obj->del_c(obj);                                                             \
                                obj = 0; }
       
#define PLUGIN_RELEASE(obj)   { if (obj && obj->release_c)                                                     \
                                  obj->release_c(obj);                                                         \
                                obj = 0; }
                                
#define PLUGIN_DEL_LIST(objlist,nbobj) \
                              { if (objlist) {                                                                 \
                                   for (int indObj=0 ; indObj<nbobj ; indObj++ ) PLUGIN_DEL(objlist[indObj]);  \
                                   delete [] objlist; objlist =0;                                              \
                                } } 
                         
extern "C" {

  // Forward declarations
  typedef struct _catcefnotifier_c        catcefnotifier_c;
  typedef struct _catcefclient_c          catcefclient_c;
  typedef struct _catceftools_c           catceftools_c;
  typedef struct _catcefbinary_c          catcefstringutf8_c;
  typedef struct _catpixelimage_c         catpixelimage_c;
  
  // Cef client basic and factory methods
  // implemented in plugin 
  // used out of plugin  
  //
  // There is no method to manage its lifecycle as a catcefglobal_c should not be stored.
  // The only way to use it is as following :
  // - get the session catcefglobal_c object using the single exported method catcef_pluginfactory
  // - call one or several methods it provides
  // - forget it
  typedef struct _catcefglobal_c
  {   
    // Factory methods
    // ---------------
    // creation of a cef client
    catcefclient_c*      (CONV_CALL* createclient)             (_catcefglobal_c*,catcefnotifier_c*,catpixelimage_c*,const catcefstringutf8_c*);    
    
    // Basic methods
    // -------------
    // Init and destroy of a cef context
    void                 (CONV_CALL* initcefcontext)           (_catcefglobal_c*);
    void                 (CONV_CALL* destroycefcontext)        (_catcefglobal_c*);  
    
    // 3DSWebHelper.exe
    int                  (CONV_CALL* subprocessmain)           (_catcefglobal_c*,int argc, char** argv); 
    
    // Set the tools object implemented in the non-plugin component
    void                 (CONV_CALL* setcatceftools)           (_catcefglobal_c*,catceftools_c*); 
    
    // Get the plugin versions
    int                  (CONV_CALL* getmaxversion)            (_catcefglobal_c*);
    int                  (CONV_CALL* getminversion)            (_catcefglobal_c*);    
    
    // Get a const string 
    const char*          (CONV_CALL* getconststring)           (_catcefglobal_c*, const char * i_constid);
    
    // Set a new cookie from the session
    void                 (CONV_CALL* setnewcookievalue)        (_catcefglobal_c*,const catcefstringutf8_c* i_cookie, const catcefstringutf8_c* i_url); 
    
  } catcefglobal_c; 
}

#endif
