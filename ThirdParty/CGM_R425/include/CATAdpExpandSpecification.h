// COPYRIGHT Dassault Systemes 2013
#ifndef CATAdpExpandSpecification_H
#define CATAdpExpandSpecification_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATPLMExpandQueryWithAliasBuilder.h"
#include "CATListPtrOfListPtrCATIAdpPLMIdentificator.h"

class CATIAdpPLMIdentificator;
class CATAdpPLMExpandFilter;
class CATAdpExpandFilter;
class CATIPLMQueryFilter;
class CATAdpPLMExpandSpecification;
class CATListPtrCATIAdpPLMIdentificator;

class ExportedByCATPLMIntegrationAccess CATAdpExpandSpecification : protected CATPLMExpandQueryWithAliasBuilderFactory
{
public:
  CATAdpExpandSpecification(CATIAdpPLMIdentificator * iRootSpecification, CATAdpExpandFilter * iFilter);

  virtual ~CATAdpExpandSpecification();

  CATAdpExpandSpecification(const CATAdpExpandSpecification&);
  CATAdpExpandSpecification& operator=(const CATAdpExpandSpecification&);

  CATBoolean IsValid() const;
  HRESULT SetAliasIdentificatorAssociation(const CATUnicodeString & iAlias, CATIAdpPLMIdentificator * iId);
  HRESULT GetAliasIdentificatorAssociation(const CATUnicodeString &iAlias, CATIAdpPLMIdentificator *& oAdpId) const;
  HRESULT FillFilter(CATAdpExpandFilter & oFilter) const;
  HRESULT GetRootIdentificator(CATIAdpPLMIdentificator *& oAdpId) const;
  HRESULT SetConfigurationFilterId(CATIAdpPLMIdentificator * iId);
  HRESULT GetConfigurationFilterId(CATIAdpPLMIdentificator *& oAdpId) const;
	HRESULT AddExplicitBranchToKeep(const CATListPtrCATIAdpPLMIdentificator& iPathToKeep );
  HRESULT AddExplicitBranchesToKeep(const CATListPtrOfListPtrCATIAdpPLMIdentificator & iPathsToKeep );
  HRESULT ListExplicitBranchesToKeep(CATListPtrOfListPtrCATIAdpPLMIdentificator & oPathsToKeep ) const;
  HRESULT ResetExplicitBranchesToKeep();	 
  HRESULT AddExplicitBranchToRemove(const CATListPtrCATIAdpPLMIdentificator& iPathToRemove );
  HRESULT AddExplicitBranchesToRemove(const CATListPtrOfListPtrCATIAdpPLMIdentificator & iPathsToRemove );
  HRESULT ListExplicitBranchesToRemove(CATListPtrOfListPtrCATIAdpPLMIdentificator & oPathsToRemove ) const;
  HRESULT ResetExplicitBranchesToRemove();

  static HRESULT FillCAASpecFromExistingFilter(CATIPLMQueryFilter * iQFilter, CATAdpPLMExpandSpecification & oExpandSpecification);
protected:
  CATPLMExpandQueryWithAliasBuilder * GetQueryBuilder() const;
private:
  CATAdpExpandSpecification();
  CATPLMExpandQueryWithAliasBuilder * m_internal_builder;
};
#endif
