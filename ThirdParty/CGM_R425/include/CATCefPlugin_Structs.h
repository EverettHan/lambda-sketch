//===================================================================
// COPYRIGHT Dassault Systemes 2012-10-15
//===================================================================
//
// Abstract: This class is for private use only as it exposes some
//           CEF headers. It manages the CEF context and the client
//           handler (browser events and callbacks).
//
//===================================================================
// 2012-10-15 Creation: D6K
//===================================================================

#ifndef CATCefPlugin_Structs_H
#define CATCefPlugin_Structs_H

// ChromiumEmbedded
#include "CATCefPlugin_Base.h"

extern "C" {
  
  struct _catcefbinary_c
  {
    char * data_c;
    int    size_c;    
    // LifeCycle
    void (CONV_CALL* del_c) (struct _catcefbinary_c* self);            
  };
  typedef _catcefbinary_c catcefbinary_c;
  typedef _catcefbinary_c catcefstringutf8_c;
  
  typedef struct _catcefliststrings_c
  {
    catcefstringutf8_c** _strings;
    int                  _nb_strings;    
    void (CONV_CALL* del_c) (struct _catcefliststrings_c* self);
  } catcefliststrings_c;  
  
  typedef struct _catcefkeysvalues_c 
  {
    catcefliststrings_c* _keys;
    catcefliststrings_c* _values;
    void (CONV_CALL* del_c) (struct _catcefkeysvalues_c* self);
  } catcefkeysvalues_c;  
  
  typedef struct _contextmenuproperties_c
  {
    // Data      
    int                              x_c, y_c;
    catceftypes_contextmenueditmask  editflags_c;
    catceftypes_contextmenumediamask mediaflags_c;
    catceftypes_contextmenutypemask  typeflags_c;
    catceftypes_contextmenumediatype mediatype_c;
    catcefstringutf8_c*              linkurl_c;
    catcefstringutf8_c*              unfilteredlinkurl_c;
    catcefstringutf8_c*              currenturl_c;
    catcefstringutf8_c*              selectedtext_c;
    catcefstringutf8_c*              sourceurl_c;
    bool                             iseditable_c;
    // LifeCycle
    void (CONV_CALL* del_c) (struct _contextmenuproperties_c* self);        
  } contextmenuproperties_c;
  
  
  typedef struct _vect_int_c {
    // Data      
    int width_c;
    int height_c;
  } vect_int_c;
  
  typedef struct _rect_int_c {
    // Data    
    int x_c;
    int y_c;
    int width_c;
    int height_c;
  } rect_int_c;
  
  typedef struct _catcefkeyevent_c
  {
    catceftypes_keytype         type_c;
    int                         char_c;
    int                         vk_c;
    int                         key_c;
    catceftypes_keymodifiermask modifier_c; 
  } catcefkeyevent_c;
  
  typedef struct _popupproperties_c
  {
    // Data
    rect_int_c          rect_c;
    catcefstringutf8_c* targeturl_c;
    catcefstringutf8_c* title_c;
    bool                ismenubarvisible_c;
    bool                isscrollbarvisible_c;
    bool                isstatusbarvisible_c;
    bool                istoolbarvisible_c;    
    // LifeCycle
    void (CONV_CALL* del_c) (struct _popupproperties_c* self);    
  } popupproperties_c;
  
  typedef struct _replayresult_c
  {
    // Data      
    int                         code_c;
    catcefstringutf8_c*         message_c; 
    // LifeCycle
    void (CONV_CALL* del_c) (struct _replayresult_c* self);    
  } replayresult_c;  

  typedef struct _touchevent_c
  {
    // Data
    int                    id_c;
    catceftypes_touchstate type_c;
    int                    x_c;
    int                    y_c;
  } touchevent_c;
  
  typedef struct _mouseevent_c
  {
    int                         x_c, y_c;
    catceftypes_mousebutton     button_c;
    catceftypes_keymodifiermask modifiers_c;
  } mouseevent_c;
  
  
  /**
   * Group of fields that identify a subject or an issuer for a certificate.
   * https://www.ietf.org/rfc/rfc5280.txt
   * https://tools.ietf.org/html/rfc2511
   */
  typedef struct _sslcertificateentity_c
  {
    // CN field.
    catcefstringutf8_c* commonName_c;
    // C field.
    catcefstringutf8_c* countryName_c;
    // L field.
    catcefstringutf8_c* localityName_c;
    // S or ST field.
    catcefstringutf8_c* stateOrProvinceName_c;
    // DC fields.
    catcefliststrings_c* domainComponents_c;
    // O fields.
    catcefliststrings_c* organizationNames_c;
    // OU fields.
    catcefliststrings_c* organizationUnitNames_c;
    // STREET fields.
    catcefliststrings_c* streetAddresses_c;
    // LifeCycle
    void (CONV_CALL* del_c) (struct _sslcertificateentity_c* self);   
  } sslcertificateentity_c;
  
  typedef struct _ceftime_c {
    int year_c;          // Four or five digit year "2007" (1601 to 30827 on
                       //   Windows, 1970 to 2038 on 32-bit POSIX)
    int month_c;         // 1-based month (values 1 = January, etc.)
    int day_of_month_c;  // 1-based day of month (1-31)
    int hour_c;          // Hour within the current day (0-23)
    int minute_c;        // Minute within the current hour (0-59)
    int second_c;        // Second within the current minute (0-59 plus leap
                         //   seconds which may take it up to 60).    
  } ceftime_c;
  
   /**
   * SSL certificate properties and data.
   */
  typedef struct _sslcertificate_c
  {
    // Certificate issuer i.e. who provided the certificate.
    sslcertificateentity_c* issuer_c;
    // Certificate subject i.e. what is being secured.
    sslcertificateentity_c* subject_c;
    // DER encoded data.
    catcefbinary_c * encodedData_c;
    // DER encoded serial number.
    catcefbinary_c * serialNumber_c;
    // First day of validity: the certificate is invalid before that date.
    ceftime_c validityStart_c;
    // Last day of validity: the certificate will be invalid after that date.
    ceftime_c validityEnd_c;
    // LifeCycle
    void (CONV_CALL* del_c) (struct _sslcertificate_c* self);   
  } sslcertificate_c;
  
  
  typedef struct _certicateselection_c
  {
    // Data    
    int                  id_c;
    sslcertificate_c  ** certificateslist_c;
    int                  nbcertificates_c;
    catcefstringutf8_c*  domain_c;
    // LifeCycle
    void (CONV_CALL* del_c) (_certicateselection_c* self);    
  } certicateselection_c;
    
   // File Dialog filter
  typedef struct _catceffiledialogfilter_c
  {    
    // List of file extensions, e.g. "jpg", "png"...
    catcefliststrings_c*     extensions_c;
    // Human-readable description for the list of extensions.
    catcefstringutf8_c*      description_c;
    // LifeCycle
    void (CONV_CALL* del_c) (_catceffiledialogfilter_c* self);
  } catceffiledialogfilter_c;   
  
  // Http headers
  typedef struct _cathcefttpresponse_c
  {
    bool                  reqsuccess_c; // Request has been sent successfully
    int                   status_c;     // Response status (200, ...)
    catcefstringutf8_c*   statustxt_c; 
    catcefkeysvalues_c *  header_c;
    catcefbinary_c*       body_c;
    void (CONV_CALL* del_c) (struct _cathcefttpresponse_c* self);    
  } catcefhttpresponse_c;    

} // end of extern "C" 

#endif
