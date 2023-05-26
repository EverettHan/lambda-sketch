// COPYRIGHT DASSAULT SYSTEMES 2013
#ifndef CATAdpPLMExpandSpecification_H
#define CATAdpPLMExpandSpecification_H

/**
* @CAA2Level L1
* @CAA2Usage U1  
*/

#include "CATPLMIntegrationAccess.h"
#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATListPtrOfListPtrCATIAdpPLMIdentificator.h"

class CATUnicodeString;
class CATIAdpPLMIdentificator;
class CATAdpPLMExpandFilter;
class CATAdpExpandSpecification;
class CATListPtrCATIAdpPLMIdentificator;

class ExportedByCATPLMIntegrationAccess CATAdpPLMExpandSpecification
{
public:
  /**
   * Constructs an Expand specification.
   *
   * @param iRootSpecification [in]
   *   the root identifier of the expand.
   * @param iFilter [in]
   *   the filter to apply during the expand.
   */
  CATAdpPLMExpandSpecification(CATIAdpPLMIdentificator * iRootSpecification, const CATAdpPLMExpandFilter & iFilter);

  /**
   * Destructs the specification.
   */
  virtual ~CATAdpPLMExpandSpecification();

  /**
   * Constructs a clone expand specification.
   */
  CATAdpPLMExpandSpecification(const CATAdpPLMExpandSpecification & );

  /**
   * Affectation operator.
   */
   CATAdpPLMExpandSpecification & operator = (const CATAdpPLMExpandSpecification &);

  /**
   * Checks if the specification is correctly built.
   */
  CATBoolean IsValid() const;

  /**
   * Associates an identificator to an alias used in the construction of the filter.
   * If the alias was previously set with this api, the previous identificator value will be replaced by this new identificator value.
   *
   * @return
   *   <code>S_OK</code> The association succeeded.
   *   <code>E_FAIL</code> Otherwise.
   */
  HRESULT SetAliasIdentificatorAssociation(const CATUnicodeString & iAlias, CATIAdpPLMIdentificator * iId);

  /**
   * Fills an empty filter with a clone of the original filter.
   *
   * @return
   *   <code>S_OK</code> The operation succeeded.
   *   <code>E_FAIL</code> Otherwise.
   */
  HRESULT FillFilter(CATAdpPLMExpandFilter & oFilter) const;

  /**
   * Retrieves the identificator of the expand root.
   * @param oAdpId [out, CATBaseUnkonwn#Release]
   *
   * @return
   *   <code>S_OK</code> The expand root identificator was retrieved.
   *   <code>E_FAIL</code> Otherwise.
   */
  HRESULT GetRootIdentificator(CATIAdpPLMIdentificator *& oAdpId) const;

  /** 
   * Retrieves the identificator associated to an alias, if any has been set.
   * @param oAdpId [out, CATBaseUnknown#Release]
   * @return
   *   <code>S_OK</code> The corresponding identificator was retrieved.
   *   <code>E_FAIL</code> Otherwise.
   */
  HRESULT GetAliasIdentificatorAssociation(const CATUnicodeString &iAlias, CATIAdpPLMIdentificator *& oAdpId) const;

  
  /**
   * Associates a Persistent Configuration Filter to the Expand specification.
   *
   * @param iId [in]
   *   the identificator of the persistent configuration filter.
   * Only one persistent configuration filter can be set on an Expand specification. 
   * If a persistent configuration filter was previously set, it will be replaced by the input configuration filter.
   *
   * @return
   *   <code>S_OK</code> The configuration filter identificator was properly set.
   *   <code>E_FAIL</code> Otherwise.
   *
   */
  HRESULT SetConfigurationFilterId(CATIAdpPLMIdentificator * iId);

   /** 
   * Retrieves the identificator of the persistent configuration filter, if any has been set.
   * @param oAdpId [out, CATBaseUnknown#Release]
   *
   * @return
   *   <code>S_OK</code> The configuration filter identificator was retrieved.
   *   <code>E_FAIL</code> No configuration filter identificator was previously set.
   *   <code>E_UNEXPECTED</code> Otherwise.
   */
  HRESULT GetConfigurationFilterId(CATIAdpPLMIdentificator *& oAdpId) const;
	  /**
   * Adds a branch of components to keep in the filter result. No check is done on the
   * integrity of the branch except that it must start with the same component used in
   * the class constructor.
   *
   * @param iPathToKeep [in]
   *   the list of components defining the branch to keep, starting from the root to
   *   the last reference of the branch and specifying all instances and references
   *   in between.
   * @return
   *   S_OK         : the branch is added
   *   E_INVALIDARG : the branch does not start with the expand root.
   *   E_FAIL       : internal error
   */
  HRESULT AddExplicitBranchToKeep(const CATListPtrCATIAdpPLMIdentificator& iPathToKeep );
	  /**
   * Adds a list of branches to keep in the filter result. No check is done on the
   * integrity of the branches except that they must start with the same component 
   * used in the class constructor.
   *
   * @param iPathsToKeep [in]
   *   the list of lists of components defining the branch to keep, starting from the 
   *   root to the last references of the branches and specifying all instances and
   *   references in between.
   * @return
   *   S_OK         : the branches are added 
   *   E_INVALIDARG : at least one branch does not start with the expand root.
   *                  No branch is added.
   *   E_FAIL       : internal error.
   */
  HRESULT AddExplicitBranchesToKeep(const CATListPtrOfListPtrCATIAdpPLMIdentificator & iPathsToKeep );
	  /**
   * Lists the branches to keep in the filter result.
   *
   * @param oPathsToKeep [out]
   *   the list of lists of components defining the branches to keep.
   * @return
   *   S_FALSE: no branches to keep. oPathsToKeep is empty.
   *   S_OK   : some branches are to keep.
   *   E_FAIL : internal error.
   */
  HRESULT ListExplicitBranchesToKeep(CATListPtrOfListPtrCATIAdpPLMIdentificator & oPathsToKeep ) const;

  /**
   * Resets the braches to keep in the filter result.
   * @return
   *   S_FALSE: no branche to keep was defined.
   *   S_OK   : some branches were to keep.
   *   E_FAIL : internal error.
   */
  HRESULT ResetExplicitBranchesToKeep();

	  /**
   * Adds a branch of components to remove from the filter result. No check is done on 
   * the integrity of the branch except that it must start with the same component 
   * used in the class constructor.
   *
   * @param iPathToRemove [in]
   *   the list of components defining the branch to remove, starting from the root to
   *   the last reference of the branch and specifying all instances and references in
   *   between.
   * @return
   *   S_OK         : the branch is added
   *   E_INVALIDARG : the branch does not start with the expand root.
   *   E_FAIL       : internal error
   */
  HRESULT AddExplicitBranchToRemove(const CATListPtrCATIAdpPLMIdentificator& iPathToRemove );

  /**
   * Adds a list branches of components to remove from the filter result. No check is
   * done on the integrity of the branches except that they must start with the same
   * component used in the class constructor.
   *
   * @param iPathsToRemove [in]
   *   the list of list of components defining the branches to remove, starting from
   *   the root to the last reference of the branch and specifying all instances and
   *   references in between.
   * @return
   *   S_OK         : the branch is added
   *   E_INVALIDARG : the branch does not start with the expand root.
   *   E_FAIL       : internal error
   */
  HRESULT AddExplicitBranchesToRemove(const CATListPtrOfListPtrCATIAdpPLMIdentificator & iPathsToRemove );

  /**
   * Lists the branches to remove from the filter result.
   *
   * @param oPathsToRemove [out]
   *   the list of lists of components defining the branches to remove.
   * @return
   *   S_FALSE: no branches to keep. oPathsToRemove is empty.
   *   S_OK   : some branches are to keep.
   *   E_FAIL : internal error.
   */
  HRESULT ListExplicitBranchesToRemove(CATListPtrOfListPtrCATIAdpPLMIdentificator & oPathsToRemove ) const;

  /**
   * Resets the branches to remove in the filter result.
   * @return
   *   S_FALSE: no branch to remove was defined.
   *   S_OK   : some branches were to remove.
   *   E_FAIL : internal error.
   */
  HRESULT ResetExplicitBranchesToRemove();


  /**
   * @nodoc
   * Retrieves internal implementation.
   */
  HRESULT GetImpl(CATAdpExpandSpecification *& opImpl) const;

private:

  CATAdpExpandSpecification * m_impl;
};

#endif
