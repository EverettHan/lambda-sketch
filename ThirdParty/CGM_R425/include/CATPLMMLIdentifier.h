#ifndef CATPLMMLIdentifier_H
#define CATPLMMLIdentifier_H

#if defined (private) || defined(friend) || defined (protected)

  #error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 
#endif


#define AuthorizedModule1789     1789

// Check no one makes a declaration to by-pass our control. 
#if _MK_MODNAME_ == AuthorizedModule1789  
  #error Module declared as authorized by another header  
  // Fatal error on solaris
  @error 
#endif  


// List of authorized infrastructure modules 
#define CATPLMModelerLanguage                       AuthorizedModule1789
#define CATPLMMLCreateRecordSet                     AuthorizedModule1789
#define CATPLMMLCreatePathWithPushExpand            AuthorizedModule1789
#define CATPLMMLCSExchange                          AuthorizedModule1789
#define CATPLMMLDicoBaseType                        AuthorizedModule1789
#define CATPLMMLDicoCheckEngine                     AuthorizedModule1789
#define CATPLMMLEngine                              AuthorizedModule1789
#define CATPLMMLCreateTable                         AuthorizedModule1789
#define CATPLMMLParsingEngine                       AuthorizedModule1789

#if _MK_MODNAME_ == AuthorizedModule1789
#else
      #error Forbidden Access To CATPLMServicesLimitedAccess Services from a non-authorized module
        // Fatal error on solaris
        @error 
#endif

#undef CATPLMModelerLanguage
#undef CATPLMMLCreateRecordSet
#undef CATPLMMLCreatePathWithPushExpand
#undef CATPLMMLCSExchange
#undef CATPLMMLDicoBaseType
#undef CATPLMMLDicoCheckEngine
#undef CATPLMMLEngine
#undef CATPLMMLCreateTable
#undef CATPLMMLParsingEngine

#if _MK_MODNAME_ == AuthorizedModule1789
  #error Declared Module has not been undeclared correctly
  // Fatal error on solaris
  @error 
#endif

#include "CATSysErrorDef.h"

class CATString;

#if defined(__CATPLMModelerLanguage)
#define ExportedByCATPLMModelerLanguage DSYExport
#else
#define ExportedByCATPLMModelerLanguage DSYImport
#endif
#include "DSYExport.h"

class ExportedByCATPLMModelerLanguage CATPLMMLIdentifier
{
public:

  // aliasOrTypeName.iAttr
  // aliasOrTypeName.Ext(iObjExtType).iAttr
  // aliasOrTypeName::Custo.attr
  static HRESULT Encode( const CATString & iAliasOrTypeName,
                         const CATString & iCustoTypeName,
                         const CATString & iObjExtType,
                         const CATString & iAttr,
                         CATString & oAttrIdentifier);

  // aliasOrTypeName.iAttr
  // aliasOrTypeName.Ext(iObjExtType).iAttr
  // aliasOrTypeName::Custo.attr
  static HRESULT Decode( const CATString & iAttrIdentifier,
                         CATString & oAliasOrTypeName,
                         CATString & oCustoTypeName,
                         CATString & oObjExtType,
                         CATString & oAttr);

  //// format generated:
  //// Pointing.Rel.Pointed
  //static HRESULT EncodeRelation( const CATString & iTypeNameOrAliasPointing,
  //                               const CATString & iRelationAlias,
  //                               const CATString & iTypeNameOrAliasPointed,
  //                               CATString & oRelIdentifier);

  //// format expected:
  //// Pointing.Rel.Pointed
  //static HRESULT DecodeRelation( const CATString & iAttrIdentifier,
  //                               CATString & oTypeNameOrAliasPointing,
  //                               CATString & oRelationAlias,
  //                               CATString & oTypeNameOrAliasPointed);

};

#endif
