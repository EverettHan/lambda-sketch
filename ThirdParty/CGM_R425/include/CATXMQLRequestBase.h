//===================================================================
// COPYRIGHT Microsoft 2012/02/09
//===================================================================

#ifndef CATXMQLRequestBase_H
#define CATXMQLRequestBase_H

#include "CATPLMAsyncRequestServicesLimitedAccess.h"

// ObjectModelerCollection
#include "CATOmxAny.h"
#include "CATOmxArray.h"
#include "CATOmxSharable.h"

// CATPLMServices
#include "CATAsyncXMQLStructures.h"
#include "CATAsyncXMQLCollections.h"
#include "CATPLMOmxCollections.h"
#include "CATPLMAsyncRequestCollections.h"
#include "CATXMQLRequestType.h"

//////////////////////////////////////////
/// Generic Interface XMQL - Selectors ///
//////////////////////////////////////////
class ExportedByCATPLMAsync CATXMQLRequestSelector
{
public:
  CATXMQLRequestSelector() : Name(""), Type(omx_string),
    IsMultiValuated(false), IsWithoutSize(false), AcceptEmpty(true) {}

  CATXMQLRequestSelector(const CATOmxKeyString& iName, CATOmxKind iType) : Name(iName.AsCUS()), Type(iType),
    IsMultiValuated(false), IsWithoutSize(false), AcceptEmpty(true) {}

  CATXMQLRequestSelector(const CATOmxKeyString& iName, CATOmxKind iType, bool isMultivaluated) : Name(iName.AsCUS()), Type(iType),
    IsMultiValuated(isMultivaluated), IsWithoutSize(false), AcceptEmpty(true) {}

  CATXMQLRequestSelector(const CATOmxKeyString& iName, CATOmxKind iType, bool iIsMultivaluated, bool iAcceptEmpty) : Name(iName.AsCUS()), Type(iType),
    IsMultiValuated(iIsMultivaluated), IsWithoutSize(false), AcceptEmpty(iAcceptEmpty) {}

  CATUnicodeString Name; // TCL attribute name
  CATOmxKind Type; // TCL Parser attribute type
  bool IsMultiValuated; // TCL type can have multiple values
  bool IsWithoutSize; // TCL type can have be without size
  bool AcceptEmpty; // TCL type can have be empty
  CATOmxAny DefaultValue; // TCL type default value
};

/////////////////////////////////////////////
/// Generic Interface XMQL - Base Request ///
/////////////////////////////////////////////
class CATPLMAsyncRequestServices;
class CATXMQLArgsBuilder;
class ExportedByCATPLMAsync CATXMQLRequestBase : public CATOmxSharable
{
  friend class CATPLMAsyncRequestServices;
  friend class CATXMQLArgsBuilder;
protected:

  /**
   * Create a base request.
   *
   * @param
   * <br/> [in] iType : Request type
   */
  CATXMQLRequestBase(CATXMQLRequestType iType);

  /**
  * Create a base request.
  *
  * @param
  * <br/> [in] iType : Request type
  * <br/> [in] ilAttrDesc : Request selectors (see CATXMQLRequestSelector)
  *            eg: in MQL declaration, we find for ChangeLog attribute ActionPhysicalId. ilAttrDesc contains ActionPhysicalId
  *                in XMQL request, we find Column[ActionPhysicalId]. CATOmxArray<CATXMQLRequestSelector> iSelectors contains Column[ActionPhysicalId].
  */
  CATXMQLRequestBase(CATXMQLRequestType iType, const CATUnicodeString &iTableName, const CATOmxArray<CATOmxKeyString>& ilAttrDesc);

  /**
  * Create a base request.
  *
  * @param
  * <br/> [in] iType : Request type
  * <br/> [in] iSelectors : Request selectors (see CATXMQLRequestSelector)
  *            eg: in MQL declaration, we find for ChangeLog attribute ActionPhysicalId. ilAttr contains ActionPhysicalId
  *                in XMQL request, we find Column[ActionPhysicalId]. CATOmxArray<CATXMQLRequestSelector> iSelectors contains Column[ActionPhysicalId].
  */
  CATXMQLRequestBase(CATXMQLRequestType iType, const CATOmxArray<CATXMQLRequestSelector>& iSelectors);

public:
  HRESULT _BuildSelectables(const CATUnicodeString &iTableName, const CATOmxArray<CATOmxKeyString>& ilAttrDesc, CATOmxArray<CATXMQLRequestSelector>& oSelectors);
  virtual ~CATXMQLRequestBase() {}; // making sure destructor of derived class get called
  inline void SetLabel(const CATUnicodeString& iLabel) { Label = iLabel; }
  inline CATUnicodeString GetLabel() { return Label; }
  inline void AddSelector(const CATXMQLRequestSelector& iSelector) { Selectors.Append(iSelector); }
  CATXMQLRequestType Type; // Request type
  CATUnicodeString Label; // TCL parser label
  CATOmxArray<CATXMQLRequestSelector> Selectors; // TCL Parser selectors identified by Label

};

class CATXMQLRequestQueryBusOrConn : public CATXMQLRequestBase
{
  friend class CATPLMAsyncRequestServices;
  friend class CATXMQLArgsBuilder;
  friend class CATPLMxBasicParallelQueryBuilder;
protected:
  inline CATXMQLRequestQueryBusOrConn(CATXMQLRequestType iType, const CATOmxKeyString& iObjectsType, const CATOmxArray<CATXMQLRequestSelector>& iSelectors, const CATOmxArray<CATUuid>& iObjectIdsList, const CATUnicodeString& iWhereClause, const CATOmxArray<CATUnicodeString>& iVaults) :CATXMQLRequestBase(iType, iSelectors), _ListObjectIds(iObjectIdsList), WhereClause(iWhereClause), Vaults(iVaults), ObjectsType(iObjectsType) {}

  CATOmxArray<CATUuid> _ListObjectIds;
  CATUnicodeString WhereClause;
public:
  inline void AddObjectId(const CATUuid& iUuid) { _ListObjectIds.Append(iUuid);}
  inline void RemoveAllObjectIds() { _ListObjectIds.RemoveAll(TRUE);}
  inline int ObjectIdsSize() {return _ListObjectIds.Size();}

  CATOmxKeyString ObjectsType;
  CATOmxArray<CATUnicodeString> Vaults;
};

//////////////////////////////////////////
/// Generic Interface XMQL - Query Bus ///
//////////////////////////////////////////
class CATXMQLRequestQueryBus : public CATXMQLRequestQueryBusOrConn
{
  friend class CATPLMAsyncRequestServices;
  friend class CATXMQLArgsBuilder;
  friend class CATPLMxIteration;

  /**
  * Create a Query Business Object request.
  *
  * @param
  *  iSelectors [in]: Request selectors (see CATXMQLRequestSelector)
  *  iObjectIdsList [in] : List of object id on which fetch attributes defined in the selectors
  *  iWhereClause [in]: Single Where clause
  */
  inline CATXMQLRequestQueryBus(const CATOmxKeyString& iObjectsType, const CATOmxArray<CATXMQLRequestSelector>& iSelectors, const CATOmxArray<CATUuid>& iObjectIdsList, const CATUnicodeString& iWhereClause, const CATOmxArray<CATUnicodeString>& iVaults) :CATXMQLRequestQueryBusOrConn(QueryBus, iObjectsType, iSelectors, iObjectIdsList, iWhereClause, iVaults) {}
};

///////////////////////////////////////////
/// Generic Interface XMQL - Query Conn ///
///////////////////////////////////////////
class CATXMQLRequestQueryConn : public CATXMQLRequestQueryBusOrConn
{
  friend class CATPLMAsyncRequestServices;
  friend class CATXMQLArgsBuilder;

  /**
  * Create a Query Connection request.
  *
  * @param
  * <br/> [in] iSelectors : Request selectors (see CATXMQLRequestSelector)
  * <br/> [in] iObjectIdsList : List of object id on which fetch attributes defined in the selectors
  * <br/> [in] iSelectClause : Single Select clause
  * <br/> [in] iWhereClause : Single Where clause
  *
  */
  inline CATXMQLRequestQueryConn(const CATOmxKeyString& iObjectsType, const CATOmxArray<CATXMQLRequestSelector>& iSelectors, const CATOmxArray<CATUuid>& iObjectIdsList, const CATUnicodeString& iWhereClause, const CATOmxArray<CATUnicodeString>& iVaults) : CATXMQLRequestQueryBusOrConn(QueryConn, iObjectsType, iSelectors, iObjectIdsList, iWhereClause, iVaults) {}
};

//////////////////////////////////////////////
/// Generic Interface XMQL - CheckoutTicket///
//////////////////////////////////////////////
//class ExportedByCATPLMAsync CATXMQLRequestCheckoutTicket : public CATXMQLRequestBase
//{
//public:
//  /**
//  * Create a Query Connection request.
//  *
//  * @param
//  * <br/> [in] iSelectors : Request selectors (see CATXMQLRequestSelector)
//  * <br/> [in] iBOProxys : List of business object proxy encoded in string format
//  * <br/> [in] iStore : Store where to fetch streams
//  * <br/> [in] iMCSUrl : MCS url store
//  *
//  */
//  CATXMQLRequestCheckoutTicket(CATOmxArray<CATXMQLRequestSelector>& iSelectors, CATAsyncBOProxyArray& iBOProxys,
//    CATUnicodeString &iStore, const CATUnicodeString &iMCSUrl) : CATXMQLRequestBase(CheckoutTicket, iSelectors), 
//    BOProxys(iBOProxys), 
//    Store(iStore), 
//    MCSUrl(iMCSUrl) {}
//
//  CATAsyncBOProxyArray BOProxys;
//  CATUnicodeString Store;
//  CATUnicodeString MCSUrl;
//};

///////////////////////////////////////////
/// Generic Interface XMQL - ListPolicy ///
///////////////////////////////////////////
class ExportedByCATPLMAsync CATXMQLRequestListPolicy : public CATXMQLRequestBase
{
  friend class CATPLMAsyncRequestServices;
  friend class CATXMQLArgsBuilder;
  /**
  * Create a Query Connection request.
  *
  * @param
  * <br/> [in] iSelectors : Request selectors (see CATXMQLRequestSelector)
  *
  */
  CATXMQLRequestListPolicy(const CATOmxArray<CATXMQLRequestSelector>& iSelectors) : CATXMQLRequestBase(ListPolicy, iSelectors) {}

};

////////////////////////////////////////////
/// Generic Interface XMQL - MassiveLink ///
////////////////////////////////////////////
class __TA__KOALA; // ODT
class ExportedByCATPLMAsync CATXMQLRequestMassiveLink : public CATXMQLRequestBase
{
  friend class CATPLMAsyncRequestServices;
  friend class CATXMQLArgsBuilder;
  friend class __TA__KOALA;

  /**
  * Create a Query Connection request.
  *
  * @param
  * <br/> [in] iSelectors : Request selectors (see CATXMQLRequestSelector)
  * <br/> [in] iStoreInfos : Object describing store information
  * <br/> [in] iMCSUrl : MCS url store
  *
  */
  CATXMQLRequestMassiveLink(const CATOmxArray<CATXMQLRequestSelector>& iSelectors,
    const xMQLRequest::StoreInfos& iStoreInfos,
    const CATUnicodeString& iMCSUrl) : CATXMQLRequestBase(MLink, iSelectors),
    StoreInfos(iStoreInfos),
    MCSUrl(iMCSUrl) {}

  CATUnicodeString MCSUrl;
  xMQLRequest::StoreInfos StoreInfos;
};
#endif
