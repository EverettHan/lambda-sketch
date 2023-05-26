#ifndef CATPLMPrivateAttributeServices_H
#define CATPLMPrivateAttributeServices_H
// COPYRIGHT DASSAULT SYSTEMES 2007

/**
* @level Private
* @usage U1
*/

#undef ExportedByCATPLMPrivateAccess  
#if defined (private) || defined(friend) || defined (protected)

  #error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 
#endif

#define AuthorizedModule     999
// List of authorized infrastructure modules 
#define CATPLMServicesItf                  AuthorizedModule
#define CATPLMxQueryDataSet                AuthorizedModule
#define CATPLMImplAdapterClass             AuthorizedModule
#define CATPLMREDataAccessor               AuthorizedModule
#define RecordManagement                   AuthorizedModule
#define TSTCATPLMxMetadataHandling         AuthorizedModule
#define CATPLMiPMLDataStream               AuthorizedModule
#define CATPLMImplAdapterQLBase            AuthorizedModule
#define CATPLMDebugProviderImpl            AuthorizedModule
#define TSTCATPLMDbgSaveBasic              AuthorizedModule
#define TSTCATPLMDbgSaveBasicAttrMapping   AuthorizedModule
#define TSTCATPLMTyping                    AuthorizedModule
#define STEPPreview                        AuthorizedModule
#define CATTCLRecordBuilderMainThread      AuthorizedModule
#define CATPLMPlmqlIpmlXmql                AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule

#else
  #error Forbidden Access To CATPLMPrivateAttributeServices from a non-authorized module
  // Fatal error on solaris
  @error 
#endif

#undef CATPLMServicesItf
#undef CATPLMxQueryDataSet
#undef CATPLMImplAdapterClass
#undef CATPLMREDataAccessor
#undef RecordManagement
#undef TSTCATPLMxMetadataHandling
#undef CATPLMiPMLDataStream
#undef CATPLMImplAdapterQLBase
#undef CATPLMDebugProviderImpl
#undef TSTCATPLMDbgSaveBasic
#undef TSTCATPLMDbgSaveBasicAttrMapping
#undef TSTCATPLMTyping
#undef STEPPreview
#undef CATTCLRecordBuilderMainThread
#undef CATPLMPlmqlIpmlXmql

#if _MK_MODNAME_ == AuthorizedModule
  #error Missing #undef for one Module
  // Fatal error on solaris
  @error 
#endif

#if defined(__CATPLMServicesItf)
#define ExportedByCATPLMPrivateAccess DSYExport
#else
#define ExportedByCATPLMPrivateAccess DSYImport
#endif
#include "DSYExport.h"

#include "CATPLMAttribute.h" // For AttrType enum

#include "CATListPV.h"
class CATPLMType;

// class CATPLMAttribute;
// class CATLISTP(CATPLMAttribute);

class CATString;


/**
 * RESTRICTED TOOLBOX for special attribute API access
 * @nodoc
 */
class ExportedByCATPLMPrivateAccess CATPLMPrivateAttributeServices
{
public:
  /**
   * Retreive basic information on an attribute of a type.
   * This includes InternalRO and other attributes that can't be retrieved with CATPLMType::ListAttributes API.
   * @nodoc
   */
  static HRESULT GetModelerAttributeType (CATPLMType *iType, const CATString &iAttrId, AttrTypes &oType, CATBoolean &oIsMulti, CATBoolean &oIsEnum);

  /**
   * Retreive a fake CATPLMAttribute based on the Dictionary view of an attribute of a type.
   * This includes InternalRO and other attributes that can't be retrieved with CATPLMType::ListAttributes API.
   * This API does not returned the 'official' CATPLMAttribute returned by ListAttribute API.
   * If such definition exists, it should be better to use it because it is more complete.
   * oAttribute must be Released after use.
   * @nodoc
   */
  static HRESULT GetModelerAttribute (CATPLMType *iType, const CATString &iAttrId, CATPLMAttribute *&oAttribute);

private:
  static void _RattrapForVolatileAttrAndStrongRel(AttrTypes &oType, CATBoolean &oIsMulti, CATBoolean &oIsEnum);
};

#endif
