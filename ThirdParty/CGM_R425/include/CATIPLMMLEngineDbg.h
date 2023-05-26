//===================================================================
// COPYRIGHT  Dassault  Systemes  2011
//===================================================================
//
//  CATIPLMMLEngineDbg.h
//  Define  the  CATIPLMMLEngine  interface
//
//===================================================================
// http://osmwebdsy/wiki/index.php/1-Modeler_Language:_Navigation
//===================================================================
//
// Usage  notes:
// Execution of a navigation described using Modeler language (ML) grammar 
// and creation of a table containing datas extracted from database is made using interface CATIPLMMLEngine.
// This interface provides usefull services for debug.
//
//===================================================================
// March 2011    Creation:  EPB
//=================================================================== 

#ifndef CATIPLMMLEngineDbg_H
#define CATIPLMMLEngineDbg_H


#if defined (private) || defined(friend) || defined (protected)

  #error Forbidden re-define of 'private', 'friend' or 'protected'
    // Fatal error on solaris
    @error 
#endif


#define AuthorizedModule789     789

// Check no one makes a declaration to by-pass our control. 
#if _MK_MODNAME_ == AuthorizedModule789  
  #error Module declared as authorized by another header  
  // Fatal error on solaris
  @error 
#endif  


// List of authorized infrastructure modules 
#define CATPLMModelerLanguage                     AuthorizedModule789
#define CATPLMMLEngine                            AuthorizedModule789
#define TSTCATPLMMLMultiCustoEnrichAllCusto       AuthorizedModule789
#define TSTCATPLMMLInfra                          AuthorizedModule789
#define TSTCATPLMMLUIDebug                        AuthorizedModule789
#define TSTCATPLMMLPostFiltering                  AuthorizedModule789

#if _MK_MODNAME_ == AuthorizedModule789
#else
      #error Forbidden Access To CATPLMServicesLimitedAccess Services from a non-authorized module
        // Fatal error on solaris
        @error 
#endif

#undef CATPLMModelerLanguage
#undef CATPLMMLEngine
#undef TSTCATPLMMLMultiCustoEnrichAllCusto
#undef TSTCATPLMMLInfra
#undef TSTCATPLMMLUIDebug
#undef TSTCATPLMMLPostFiltering

#if _MK_MODNAME_ == AuthorizedModule789
  #error Declared Module has not been undeclared correctly
  // Fatal error on solaris
  @error 
#endif


#if defined(__CATPLMModelerLanguage)
#define ExportedByCATPLMModelerLanguage DSYExport
#else
#define ExportedByCATPLMModelerLanguage DSYImport
#endif
#include "DSYExport.h"


#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerLanguage IID IID_CATIPLMMLEngineDbg;
#else
extern "C" const IID IID_CATIPLMMLEngineDbg ;
#endif

#include "CATBaseUnknown.h"     // System PublicInterfaces

#include "CATPLMMLRelationStatus.h"
#include "CATPLMMLRelationSynchroStatus.h"

#include "CATPLMModelerLanguage.h"          // CATPLMModelerLanguage ProtectedInterfaces

#include "CATListOfCATString.h"

#include "CATListOfInt.h"

#include "CATLISTV_Declare.h"
class CATLISTV(CATPLMID);

class CATString;
class CATUnicodeString;
class CATOmxAny;
class CATIPLMError;
class CATPLMType;

class ExportedByCATPLMModelerLanguage CATIPLMMLEngineDbg : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  /**
  * Retrieve all columns of the table related to the value of attributes
  * <br><b>Role</b>: Retrieve all columns of the table related to the value of attributes
  *
  *  convention used for the name of columns:
  *  <aliasOrTypeName>.<attr>
  *  <aliasOrTypeName>::<custoTypeName>.<attrName>
  *  <aliasOrTypeName>.Ext(<typeNameExt>).<attr>
  *  <aliasOrTypeName>::<custoTypeName>.Ext(<typeNameExt>).<attr>.
  *  <aliasOrTypeName>,<attr> are defined in the navigation written in ML.
  *
  * @param oListAliasAttr
  *   list of columns of the table related to the value of attributes
  * @param iIsAttrIdSorted
  *   attr identifer are sorted in alphabetical order or not.
  *   be carefull, aliasOrTypeName appears in the following order:
  *   suppose we have REF-[Owner]>ALIAS
  *   Firstly, we visit the root object REF and then we visit the object ALIAS. So, REF appears before ALIAS.
  *   For each object, attribute are ordered.
  *   REF.AAA, REF.BBB, REF.CCC, ALIAS.AAA, ALIAS.BBB
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetAllAttributesIdentifier( CATListOfCATString & oListAliasAttr,
                                              CATBoolean iIsAttrIdSorted) = 0;

  /**
  * Retrieve all columns of the table related to the value of relations
  * <br><b>Role</b>: Retrieve all columns of the table related to the value of relations
  *
  *  convention used for the name of columns:
  *  <aliasOrTypeName>.<RelationName>
  *  <aliasOrTypeName>,<RelationName> defined in the navigation written in ML.
  *
  * @param oListAliasRelation
  *   list of columns of the table related to the value of attributes
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetAllRelationsIdentifier(CATListOfCATString & oListAliasRelation) = 0;

  /**
  * Retrieve value of attributes using CATString format
  * <br><b>Role</b>: Retrieve value of attributes using CATString format
  *
  *  convention used for the name of columns:
  *  <aliasOrTypeName>.<attr>
  *  <aliasOrTypeName>::<custoTypeName>.<attrName>
  *  <aliasOrTypeName>.Ext(<typeNameExt>).<attr>
  *  <aliasOrTypeName>::<custoTypeName>.Ext(<typeNameExt>).<attr>.
  *  <aliasOrTypeName>,<attr> are defined in the navigation written in ML.
  *
  * @param iAttrIdentifier
  *   Name of the column chosen.
  * @param iLinePos
  *   line chosen
  * @param iObjectPos
  *   position of object
  * @param oAttrValue
  *   value of attribute using CATString format
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetAttributeValue(  const CATString & iAttrIdentifier,
                                      int iLinePos,
                                      int iObjectPos,
                                      CATUnicodeString & oAttrValue) = 0;

  /**
  *
  * <br><b>Role</b>: 
  * @param iRelIdentifier
  * 
  * @param iLinePos
  * 
  * @param iObjectPos
  * 
  * @param oRelValue
  * 
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT GetRelationValue( const CATString & iRelIdentifier,
                                      int iLinePos,
                                      int iObjectPos,
                                      CATUnicodeString & oRelValue) = 0;

  /**
  * Retrieve all columns of the table related to the value of attributes
  * and all value of attributes for each of this column
  * <br><b>Role</b>: Retrieve all columns of the table related to the value of attributes
  * and all value of attributes for each of this column
  *
  * @param oStr
  *   all attributes value are stored in this string.
  * @param iCompleteWithRelationValue
  *   relation values are dumped or not.
  * @param iIsAttrIdSorted
  *   attr identifer are sorted in alphabetical order or not.
  *   be carefull, aliasOrTypeName appears in the following order:
  *   suppose we have REF-[Owner]>ALIAS
  *   Firstly, we visit the root object REF and then we visit the object ALIAS. So, REF appears before ALIAS.
  *   For each object, attribute are ordered.
  *   REF.AAA, REF.BBB, REF.CCC, ALIAS.AAA, ALIAS.BBB
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual void Dump(  CATUnicodeString & oStr,
                      CATBoolean iCompleteWithRelationValue,
                      CATBoolean iIsAttrIdSorted) = 0;


};

CATDeclareHandler( CATIPLMMLEngineDbg, CATBaseUnknown );

#endif
