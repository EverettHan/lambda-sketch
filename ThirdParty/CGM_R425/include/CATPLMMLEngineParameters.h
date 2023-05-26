//===================================================================
// COPYRIGHT  Dassault  Systemes  2011
//===================================================================
//
//  CATPLMMLEngineParameters.h
//  Define  the  CATPLMMLEngineParameters  object
//
//===================================================================
// http://osmwebdsy/wiki/index.php/1-Modeler_Language_ML_or_MeuL:_Navigation
//===================================================================
//
// Usage  notes:
// Modeler language (ML) describes navigation on Modeler level (To sum up, we
// recall that it exists 3 different levels: Core Level, Modeler Level, Custo Level)
// Using the current object, we are able to describe custo(s) to apply on each node of the navigation.
// 2 modes exist: filter with a specific custo or enrich with all custo.
//
// There is a characteristic node in the navigation described using ML grammar:
// The root of the navigation (it is the first element of the navigation) (metamodel level).
// Using the current object, we are able to pass the roots of the navigation (instantiated model level).
//
// difference between CATPLMMLEngineParameters and CATPLMMLParsingOptions:
// CATPLMMLEngineParameters dedicated to manage PLM (custo, plmids, fiter).
// CATPLMMLParsingOptions dedicated to parsing option.
//
//===================================================================
// March 2011    Creation:  EPB
//=================================================================== 

#ifndef CATPLMMLEngineParameters_H
#define CATPLMMLEngineParameters_H

#include "CATPLMModelerLanguage.h"

#include "CATString.h"            // System ProtectedInterfaces

#include "CATPLMMLOmxCollection.h"

#include "CATLISTV_CATPLMID.h"    // CATPLMIdentificationAccess ProtectedInterfaces CATPLMIdentifier.m CATPLMIdentificationAccess.dll

#include "CATOmxArray.h"
#include "CATOmxSR.h"
#include "CATOmxOMap.h"

class CATIPLMMLDicoAllAliasGenericTypesAttrs;
class CATPLMTypeH;
class CATError;
class CATIPLMMLFilterFunction;

class ExportedByCATPLMModelerLanguage CATPLMMLEngineParameters
{
  friend class CATPLMMLEngineCompServices;
public:
  CATPLMMLEngineParameters();
  ~CATPLMMLEngineParameters();

  /**
  * <br><b>Role</b>: Roots of navigation.
  * @param iListOfPLMID
  *   Root of navigation
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  void SetListPlmid(const CATLISTV(CATPLMID)& iListOfPLMID);

  /**
  * <br><b>Role</b>: Complete type of <iAliasOrModelerType> with custo <ipCustoType>.
  *
  * Be careful! At this step, it is forbidden to add a plmtype that is not a custo type.
  * check that attribute associated to to the plmtype exist is made.
  *
  * @param iAliasOrModelerType
  *  Formalism for iAliasOrTypeNameIdentifier:
  *  <aliasOrTypeName> defined in the navigation written in ML.
  * @param iCustoTypeName
  *  Custo type.
  * @param iListAttr
  *  Attributes of DsType described in ML are inherited.
  *  Only custo attributes are supported at this step (attributes between iCustoTypeName and first DS type).
  * @param opError [out,CATBaseUnknown#Release]
  *  Don't do new CATError... if necessary.
  *  Kind of error raised: iCustoTypeName is not a custo type...
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  HRESULT CompleteDsTypeWithSpecificChildType(const CATString & iAliasOrModelerType,
                                              const CATPLMTypeH& iCustoType,
                                              const CATListOfCATString & iListAttr,
                                              CATError* & opError);

  /**
  * <br><b>Role</b>: Complete type of <iAliasOrModelerType> with all custo type.
  *
  * @param iAlias
  *  Formalism for iAliasOrTypeNameIdentifier:
  *  <aliasOrTypeName> defined in ML.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  HRESULT CompleteDsTypeWithAllChildrenType(const CATString & iAliasOrModelerType);

  /**
  * <br><b>Role</b>: Complete extension with specific extension.
  *
  * @param iAlias
  *  Formalism for iAliasOrTypeNameIdentifier:
  *  <aliasOrTypeName> defined in the navigation written in ML.
  * @param iExtType
  *  extension that extend base type <aliasOrTypeName> defined in ML.
  *  No DS extension (if DS extension needed use CompleteDsTypeWithSpecificExtType2)
  * @param iListAttr
  *  Attributes of DsType described in ML are inherited.
  *  Only custo attributes are supported at this step (attributes between iExtType and first DS type).
  * @param opError [out,CATBaseUnknown#Release]
  *  Don't do new CATError... if necessary.
  *  Kind of error raised: iExtType is not an extension type...
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  HRESULT CompleteDsTypeWithSpecificExtType(const CATString & iAliasOrModelerType,
                                            const CATPLMTypeH& iExtType,
                                            const CATListOfCATString & iListAttr,
                                            CATError* & opError);

  /**
  * <br><b>Role</b>: Complete type of <iAliasOrModelerType> with all extensions.
  *
  * @param iAlias
  *  Formalism for iAliasOrTypeNameIdentifier:
  *  <aliasOrTypeName> defined in ML.
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  HRESULT CompleteDsTypeWithAllExtType(const CATString & iAliasOrModelerType);

  /**
  * <br><b>Role</b>: 
  * @param iAliasOrModelerType
  * 
  * @param iListAttr
  *  Internal attribute are not supported
  * @param opError
  * 
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  HRESULT CompleteDsTypeWithAttribute(  const CATString & iAliasOrModelerType,
                                        const CATListOfCATString & iListAttr);

  /**
  * <br><b>Role</b>: 
  * Ability given to reduce the size of the table (and free memory...) using the following method:
  * void SetFilter( CATIPLMMLFilterFunction ipFilterFunc = NULL); on class CATPLMMLEngineParameters.
  * Function is called for each line of the table. Then the line is kept or not.

  * AddRef is made on this object.
  */
  void SetFilter( CATIPLMMLFilterFunction* ipFilterFunc );

#if !defined(_WINDOWS_SOURCE) || \
     defined(__CATPLMModelerLanguage) || defined(__TSTCATPLMMLNewTyping3) || defined(__TSTCATPLMMLNewTyping5) || defined(__TSTCATPLMMLInstRelEnt1ExtInheritance)
  /**
  * <br><b>Role</b>: Same contract as CompleteDsTypeWithSpecificExtType.
  * DS extension are supported.
  *
  * @param iAlias
  * @param iExtType
  *  DS extension are supported.
  * @param iListAttr
  * @param opError [out,CATBaseUnknown#Release]
  * @return
  * <dl><dt><code>S_OK</code> <dd></dl>
  */
  // all extension are supported: DsExtension
  HRESULT CompleteDsTypeWithSpecificExtType2(const CATString & iAliasOrModelerType,
                                             const CATPLMTypeH& iExtType,
                                             const CATListOfCATString & iListAttr,
                                             CATError* & opError);
#endif

#if !defined(_WINDOWS_SOURCE) || \
     defined(__CATPLMModelerLanguage) || defined(__TSTCATPLMMLCusto) || defined(__TSTCATPLMMLMultiCustoFilterOneCusto) || defined(__TSTCATPLMMLMultiCustoFilterAllCusto) || defined(__TSTCATPLMMLCustoAndFilter) || defined(__TSTCATPLMMLUIDebug)
  /**
  * <br><b>Role</b>: Replace type of <iAliasOrModelerType> by <ipCustoType>.
  *
  * Be careful! At this step, it is forbidden to add a plmtype that is not a custo type.
  * check that attribute associated to to the plmtype exist is made.
  *
  * @param iAliasOrModelerType
  *  Formalism for iAliasOrTypeNameIdentifier:
  *  <aliasOrTypeName> defined in the navigation written in ML.
  * @param iCustoTypeName
  *  Custo type.
  * @param iListAttr
  *  Attributes of DsType described in ML are inherited.
  *  Only custo attributes are supported at this step (attributes between iCustoTypeName and first DS type).
  * @param opError [out,CATBaseUnknown#Release]
  *  Don't do new CATError... if necessary.
  *  Kind of error raised: iCustoTypeName is not a custo type...
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  HRESULT ReplaceDsTypeBySpecificChildType(const CATString & iAliasOrModelerType,
                                             const CATPLMTypeH& iExtType,
                                             const CATListOfCATString & iListAttr,
                                             CATError* & opError);
#endif

#if !defined(_WINDOWS_SOURCE) || \
     defined(__CATPLMModelerLanguage) || defined(__TSTCATPLMMLAddAttribute)
  /**
  * <br><b>Role</b>: 
  * @param iAliasOrModelerType
  * 
  * @param iListAttr
  *  Internal attribute are supported
  * @param opError
  * 
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  HRESULT CompleteDsTypeWithAttribute2( const CATString & iAliasOrModelerType,
                                        const CATListOfCATString & iListAttr);
#endif

  CATLISTV(CATPLMID) GetListPlmid() const;

  /**
  * <br><b>Role</b>: 
  * @param opFilterFunc [out,CATBaseUnknown#Release]
  */
  void GetFilter(CATIPLMMLFilterFunction* & opFilterFunc) const;

  CATPLMMLEngineParameters (const CATPLMMLEngineParameters &);
  CATPLMMLEngineParameters& operator=(const CATPLMMLEngineParameters&);

private:
  

  /**
  * <br><b>Role</b>: 
  * @param opAliasCustosTypesAttrs [out,CATBaseUnkown#Release]
  * @return
  */
  HRESULT _GetNodeDsTypeCompletedWithSpecificChildType(CATIPLMMLDicoAllAliasGenericTypesAttrs*& opAliasCustosTypesAttrs) const;

  /**
  * <br><b>Role</b>: 
  * @param const;
  * @return
  */
  CATOmxArray<CATString> _GetNodeDsTypeCompletedWithAllChildrenType() const;

  /**
  * <br><b>Role</b>: 
  * @param opAliasExtTypesAttrs [out,CATBaseUnkown#Release]
  * @return
  */
  HRESULT _GetNodeDsTypeCompletedWithSpecificChildTypeExt(CATIPLMMLDicoAllAliasGenericTypesAttrs*& opAliasExtTypesAttrs) const;

  /**
  * <br><b>Role</b>: 
  * @param opAliasExtTypesAttrs [out,CATBaseUnkown#Release]
  * @return
  */
  HRESULT _GetNodeDsTypeCompletedWithSpecificChildTypeExt2(CATIPLMMLDicoAllAliasGenericTypesAttrs*& opAliasExtTypesAttrs) const;

  /**
  * <br><b>Role</b>: 
  * @param const;
  * @return
  */
  CATOmxArray<CATString> _GetNodeDsTypeCompletedWithAllChildrenTypeExt() const;

  /**
  * <br><b>Role</b>: 
  * @param opAliasCustosTypesAttrs [out,CATBaseUnkown#Release]
  * @return
  */
  HRESULT _GetNodeDsTypeReplacedBySpecificChildType(CATIPLMMLDicoAllAliasGenericTypesAttrs*& opAliasCustosTypesAttrs) const;

  HRESULT _GetNodeDsTypeWithAttribute( MapStringWithArrayOfString& omAliasOrTypeNamelAttr) const;

  HRESULT _GetNodeDsTypeWithAttribute2( MapStringWithArrayOfString& omAliasOrTypeNamelAttr) const;

  CATLISTV(CATPLMID) _ListOfPLMID;

  CATOmxSR<CATIPLMMLDicoAllAliasGenericTypesAttrs> _spListNodeReplaceSpecific;

  CATOmxSR<CATIPLMMLDicoAllAliasGenericTypesAttrs> _spListNodeCompleteSpecific;
  CATOmxArray<CATString> _ListNodeCompleteAll;

  CATOmxSR<CATIPLMMLDicoAllAliasGenericTypesAttrs> _spListNodeCompleteSpecificExt;//Ds Type are not supported
  CATOmxSR<CATIPLMMLDicoAllAliasGenericTypesAttrs> _spListNodeCompleteSpecificExt2;//Ds Type are supported
  CATOmxArray<CATString> _ListNodeCompleteAllExt;

  MapStringWithArrayOfString _mAliasOrTypeNamelAttr;
  MapStringWithArrayOfString _mAliasOrTypeNamelAttrInt;

  CATOmxSR<CATIPLMMLFilterFunction> _spFilterFunc;/*HRESULT (*_pFilterFunc)(CATIPLMMLLine* ipLine,CATBoolean & oIsLineToBeDeleted);*/
};

#endif
