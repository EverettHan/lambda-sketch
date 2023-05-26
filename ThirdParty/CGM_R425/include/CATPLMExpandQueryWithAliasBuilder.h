#ifndef CATPLMExpandQueryWithAliasBuilder_H
#define CATPLMExpandQueryWithAliasBuilder_H
//===================================================================
// COPYRIGHT Dassault Systemes 2013
//===================================================================
/**
* @level Protected
* @usage U1
*/
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATPLMImplAdapterBase.h"
#include "CATOmxOMap.h"
#include "CATOmxSet.h"
#include "CATPLMID.h"
#include "CATUnicodeString.h"
#include "CATListPtrCATIAdpPLMIdentificator.h"
#include "CATListPtrOfListPtrCATIAdpPLMIdentificator.h"

class CATIDOMElement;
class CATPLMQueryFilter;
class CATIPLMQueryFilter;
class CATIPLMFilterCriteria;
class CATIPLMFilterCondition;
class CATIAdpPLMIdentificator;
class CATIPLMMsgWriter;
class CATIPLMFilterVolume;
class CATIPLMFilterAttribute;
class CATIPLMFilterCondition;

class ExportedByCATPLMImplAdapterBase CATPLMExpandQueryWithAliasBuilder : public CATBaseUnknown
{
public:
  CATPLMExpandQueryWithAliasBuilder();
  virtual ~CATPLMExpandQueryWithAliasBuilder();
  CATPLMExpandQueryWithAliasBuilder(const CATPLMExpandQueryWithAliasBuilder& );
  CATPLMExpandQueryWithAliasBuilder& operator=(const CATPLMExpandQueryWithAliasBuilder& );//not impl

  /*
  *@param oFilter [out, CATBaseUnknown#Release]
  */
  HRESULT GetQueryFilter( CATIPLMQueryFilter *& oFilter );
  HRESULT ReadXMLExpression (CATUnicodeString *  iMessage);

  CATBoolean IsValid();
  CATBoolean IsFullyValid();

  HRESULT SetAliasIdentificatorAssociation(const CATUnicodeString & iAlias, CATIAdpPLMIdentificator * iId);

  /*
  *@param oAdpId [out, CATBaseUnknown#Release]
  */
  HRESULT GetAliasIdentificatorAssociation(const CATUnicodeString &iAlias, CATIAdpPLMIdentificator *& oAdpId) const;

  void SetRoot(CATIAdpPLMIdentificator * iId);

  /*
  *@param oAdpId [out, CATBaseUnknown#Release]
  */
  HRESULT GetRoot(CATIAdpPLMIdentificator *& oAdpId) const;

  HRESULT SetQueryFilter( CATIPLMQueryFilter * iFilter );

  HRESULT WriteXML(CATUnicodeString& oExpression);

  HRESULT SetConfigurationFilterId(CATIAdpPLMIdentificator * iId);

  /*
  *@param oAdpId [out, CATBaseUnknown#Release]
  */
  HRESULT GetConfigurationFilterId(CATIAdpPLMIdentificator *& oAdpId) const;
  HRESULT AddExplicitBranchToKeep(const CATListPtrCATIAdpPLMIdentificator& iPathToKeep );
  HRESULT AddExplicitBranchesToKeep(const CATListPtrOfListPtrCATIAdpPLMIdentificator & iPathsToKeep );
  HRESULT ListExplicitBranchesToKeep(CATListPtrOfListPtrCATIAdpPLMIdentificator & oPathsToKeep ) const;
  HRESULT ResetExplicitBranchesToKeep();	 
  HRESULT AddExplicitBranchToRemove(const CATListPtrCATIAdpPLMIdentificator& iPathToRemove );
  HRESULT AddExplicitBranchesToRemove(const CATListPtrOfListPtrCATIAdpPLMIdentificator & iPathsToRemove );
  HRESULT ListExplicitBranchesToRemove(CATListPtrOfListPtrCATIAdpPLMIdentificator & oPathsToRemove ) const;
  HRESULT ResetExplicitBranchesToRemove();
  HRESULT RemoveFilterCategories();
  HRESULT ResetConfig();

private:
  HRESULT ReadXMLPathFilter(CATIDOMElement *ispDOMElement);
  HRESULT ReadXMLIterativeFilter(CATIDOMElement *ispDOMElement);
  HRESULT ReadXMLVolumeFilter(CATIDOMElement *ispDOMElement);
  HRESULT ReadXMLVolumeFilter(CATIDOMElement *ispDOMElement, CATIPLMFilterCondition * iEnglobingCondition);
  HRESULT ReadXMLZoneFilter(CATIDOMElement *ispDOMElement);
  HRESULT ReadXMLZoneFilter(CATIDOMElement *ispDOMElement,   CATIPLMFilterVolume * fv);
  HRESULT ReadXMLProximityFilter(CATIDOMElement *ispDOMElement);
  HRESULT ReadXMLProximityFilter(CATIDOMElement *ispDOMElement,  CATIPLMFilterVolume * fv);

  HRESULT ReadXMLCondition(CATIDOMElement * ispDOMElement, CATIPLMFilterCriteria * iCriteriaContext);
  HRESULT ReadXMLCondition(CATIDOMElement * ispDOMElement, CATIPLMFilterCondition * iEnglobingCondition);
  HRESULT ReadXMLExpressionNode( CATIDOMElement *ispDOMElement, CATIPLMFilterCondition * iEnglobingCondition );

  HRESULT InternalWrite(CATIPLMMsgWriter * writer);
  HRESULT WriteSingleCriteria(CATIPLMMsgWriter * ioStream, CATIPLMFilterCriteria * criteria);
  HRESULT GetStreamSelectConditions(CATIPLMMsgWriter * ioStream);
  void WriteAliases(CATIPLMMsgWriter & ioStream, const CATLISTV(CATPLMID)& ids);
  HRESULT WritePathFilter(CATIPLMMsgWriter * ioStream, CATIPLMFilterCondition * iFilterCondition);
  HRESULT CheckRootNode(CATIAdpPLMIdentificator * ipAdpId, CATBoolean & obIsRoot);
  HRESULT WriteSingleVolume(CATIPLMFilterVolume * iFilterVolume, CATIPLMMsgWriter * ioStream);
  HRESULT WriteSingleAttribute(CATIPLMFilterAttribute * iFilterAttribute , CATIPLMMsgWriter * ioStream);
  HRESULT WriteSingleCondition(CATIPLMFilterCondition * iFilterCondition , CATIPLMMsgWriter * ioStream);
  HRESULT ManageUnresolvedAliasOnVolumes(const CATUnicodeString & iAlias);
  HRESULT ManageUnresolvedAliasOnVolume(CATBaseUnknown * iFilter, const CATListOfCATUnicodeString & iAliases);

  void SetRootToFilter();

  CATPLMQueryFilter * m_filter_impl;
  CATOmxOMap<CATUnicodeString, CATPLMID> m_associations;
  CATOmxOMap<CATPLMID, CATUnicodeString> m_reverse_assoc;
  CATOmxOMap<CATBaseUnknown*,CATListOfCATUnicodeString> m_volume_filters_with_plmids_undefined;
  CATIAdpPLMIdentificator * m_root_ptr;
  CATBoolean m_state;
  CATBoolean Is_RootRemoved;
};

class ExportedByCATPLMImplAdapterBase CATPLMExpandQueryWithAliasBuilderFactory
{
public:
  virtual CATPLMExpandQueryWithAliasBuilder * GetQueryBuilder() const = 0;
};

#endif
