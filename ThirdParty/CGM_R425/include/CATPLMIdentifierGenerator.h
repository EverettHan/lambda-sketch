#ifndef CATPLMIdentifierGenerator_H
#define CATPLMIdentifierGenerator_H

#include "CATUnicodeString.h"
#include "CATBoolean.h"

class CATPLMRepositoryName;

/**
* @level Protected
* @usage U3
*/

#if defined (private) || defined(friend) || defined (protected)

#error Forbidden re-define of 'private', 'friend' or 'protected'
// Fatal error on solaris
@error
#endif


#define AuthorizedModule1870     1870

// Check no one makes a declaration to by-pass our control. 
#if _MK_MODNAME_ == AuthorizedModule1870  
#error Module declared as authorized by another header  
// Fatal error on solaris
@error
#endif  


// List of authorized infrastructure modules 
#define CATPLMServicesItf                     AuthorizedModule1870
#define CATPLMAdapterOdtBase                  AuthorizedModule1870
#define CATPLMMLCreateTable                   AuthorizedModule1870
#define CATPCTNavigate                        AuthorizedModule1870
#define TSTCATPLMxImportIRPC2                 AuthorizedModule1870
#define TSTCATPLMxImportIRPC                  AuthorizedModule1870
#define TSTCATPLMxImportIRPC3                 AuthorizedModule1870
#define TSTCATPLMxCATPLMQL                    AuthorizedModule1870
#define TSTCATPLMxCSCI                        AuthorizedModule1870
#define TSTCATPLMxVersioningNLVStep1          AuthorizedModule1870
#define TSTCATPLMxVersioningNLVStep2          AuthorizedModule1870
#define TSTCATPLMxVersioningNLVStep3          AuthorizedModule1870
#define TSTCATPLMxVersioningNLVStep4          AuthorizedModule1870
#define TSTCATPLMxConversionDoubleString      AuthorizedModule1870
#define TSTCATPLMDbgImportIRPC                AuthorizedModule1870
#define TSTCATPLMxImportSaveIRPCError         AuthorizedModule1870
#define TSTCATPLMDbgImportSaveIRPCError         AuthorizedModule1870

#if _MK_MODNAME_ == AuthorizedModule1870
#else
#error Forbidden Access To CATPLMIdentifierGenerator Services from a non-authorized module
  // Fatal error on solaris
  @error
#endif

#undef CATPLMServicesItf
#undef CATPLMAdapterOdtBase
#undef CATPLMMLCreateTable
#undef CATPCTNavigate
#undef TSTCATPLMxImportIRPC2
#undef TSTCATPLMxImportIRPC
#undef TSTCATPLMxImportIRPC3
#undef TSTCATPLMxCATPLMQL
#undef TSTCATPLMxCSCI
#undef TSTCATPLMxVersioningNLVStep1
#undef TSTCATPLMxVersioningNLVStep2
#undef TSTCATPLMxVersioningNLVStep3
#undef TSTCATPLMxVersioningNLVStep4
#undef TSTCATPLMxConversionDoubleString
#undef TSTCATPLMDbgImportIRPC
#undef TSTCATPLMxImportSaveIRPCError
#undef TSTCATPLMDbgImportSaveIRPCError

#if _MK_MODNAME_ == AuthorizedModule1870
#error Declared Module has not been undeclared correctly
  // Fatal error on solaris
  @error
#endif


#if defined(__CATPLMServicesItf)
#define ExportedByCATPLMServicesItf DSYExport
#else
#define ExportedByCATPLMServicesItf DSYImport
#endif
#include "DSYExport.h"

  class ExportedByCATPLMServicesItf CATPLMIdentifierGenerator
{
public:

  static void Init(const CATUnicodeString& iKeyForSession = "");

  /**
  * <br><b>Role</b>: Specific treatment applied to name and PLM_ExternalID (M1 connection, ODT mode only)
  *
  * @param iAttrName
  *
  * @param iAttrValue
  *
  * @param oIdentifier
  *        if(iAttrName!="name" && iAttrName!="PLM_ExternalID") return S_OK. Nothing to do.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  static HRESULT RetrieveStableIdentifier(const CATUnicodeString& iAttrName, const CATUnicodeString& iAttrValue, CATUnicodeString& oIdentifier);

  /**
  * <br><b>Role</b>: Specific treatment applied to name and PLM_ExternalID (M1 connection)
  *
  * @param iAttrName
  *
  * @param iAttrValue
  *
  * @param oCompleteName
  *
  * @param iWithIncrement
  *   if left to TRUE, an automatic increment will be added to your component name. Setting in to FALSE may be useful, specially if you want to generate name for query.
  *
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code><dd>
  * <dt><code>E_INVALIDARG</code>iAttrName different from PLM_ExternalID and name<dd>
  * </dl>
  */
  static HRESULT CreateIdentifier(const CATUnicodeString& iAttrName, const CATUnicodeString& iAttrValue, CATUnicodeString& oCompleteName, CATBoolean iWithIncrement = TRUE);

  /**
  * <br><b>Role</b>: Specific treatment applied to name and PLM_ExternalID (M1 connection)
  *
  * @param iAttrName
  *
  * @param iAttrValue
  *
  * @param oCompleteName
  *
  * @param iWithIncrement
  *   if left to TRUE, an automatic increment will be added to your component name. Setting in to FALSE may be useful, specially if you want to generate name for query.
  *
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code><dd>
  * <dt><code>E_INVALIDARG</code>iAttrName different from PLM_ExternalID and name<dd>
  * </dl>
  */
  static CATUnicodeString CreateIdentifier(const CATUnicodeString& iAttrName, const CATUnicodeString& iAttrValue, CATBoolean iWithIncrement = TRUE);

  /**
  *
  * <br><b>Role</b>:
  * @param oProvider
  *
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code>if more than one connection<dd>
  * </dl>
  */
  static HRESULT GetConnectedProvider(CATPLMRepositoryName& oProvider);

private:

  CATPLMIdentifierGenerator(const CATPLMIdentifierGenerator &);
  CATPLMIdentifierGenerator & operator=(const CATPLMIdentifierGenerator &);

  static CATUnicodeString _Underscore_KeyForSession;
  static CATBoolean _isInitAlreadyCalled;
  static CATBoolean _isADL_ODT_TMP;
};

#endif
