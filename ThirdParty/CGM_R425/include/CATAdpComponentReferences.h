/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2012
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATAdpComponentReferences_H
#define CATAdpComponentReferences_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATPLMIDCollections.h"

class CATPLMTypeH;
class CATIAdpPLMIdentificator;
class CATAdpComponentReferencesIter;

/*
* Collection associating some informations (PLMAttributes) to components. Mainly used as @href CATAdpComponentQuery output.
*
* If you retrieved such a collection through a query (such as @href CATAdpComponentQuery::GetElementsByUniqueKey), you can handle it this way:
*
* <code>
* CATAdpComponentReferences myInfos;
* // ... Your query here.
* CATAdpComponentReferencesIter iter = myInfos.GetIterator();
* while ( iter.Next() )
* {
*   CATIAdpPLMIdentificator * instAdpId=NULL;
*   if(SUCCEEDED(iter.GetCurrentInstance(instAdpId)) && instAdpId)
*   {
*     CATIAdpPLMIdentificator * ownerAdpId=NULL;
*     if(SUCCEEDED(myInfos.GetOwner(instAdpId, ownerAdpId)) && ownerAdpId)
*     {
*       //...
*     }
*     CATSysReleasePtr(ownerAdpId);
*     CATIAdpPLMIdentificator * refAdpId=NULL;
*     if(SUCCEEDED(myInfos.GetReference(instAdpId, refAdpId)) && refAdpId)
*     {
*       //...
*     }
*     CATSysReleasePtr(refAdpId);
*   }
*   CATSysReleasePtr(instAdpId); 
* }
* </code>
*/
class ExportedByCATPLMIntegrationAccess CATAdpComponentReferences
{
public:
  CATAdpComponentReferences();
  ~CATAdpComponentReferences();
  CATAdpComponentReferences & operator=(const CATAdpComponentReferences &);
  CATAdpComponentReferences(const CATAdpComponentReferences &);  
  
  /**
   * Retrive the informations associatied with a given identifier.
   * @param iComponentIdentifier [in]
   *   The identifier of the component.
   * @param oOwner [out]
   *   The owner.
   *
   * @return
   * <ul>
   *   <li><code>S_OK</code> if the informations are available for the component.</li>
   *   <li><code>E_FAIL</code> if no infos for iComponentIdentifier</li>
   * </ul>
   */
  HRESULT GetOwner(CATIAdpPLMIdentificator * iComponentIdentifier, CATIAdpPLMIdentificator *& oOwner ) const;
	
	HRESULT GetReference(CATIAdpPLMIdentificator * iComponentIdentifier, CATIAdpPLMIdentificator *& oReference ) const;

  /**
   * Number of components in the collection.
   */
  unsigned int Size() const;

  /**
   * Retrieve an iterator on the collection.
   */
  CATAdpComponentReferencesIter GetIterator() const;
  
private:
  friend class CATAdpComponentReferencesFinder;
	friend class CATAdpExtendedQueryServicesRepInstParser;
	friend class CATAdpComponentReferencesIter;
  /**
   * Associate the informations to a given identifier.
   * @param iComponentIdentifier [in]
   *   The identifier of the component.
   * @param iOwner [in]
   *   The owner of the instance.
   * @param iReference [in]
   *   The reference of the instance
   * @return
   * <ul>
   *   <li><code>S_OK</code> if the informations are set for the component.</li>
   *   <li><code>S_FALSE</code> if the component already has some associated informations. The informations are overwritten only if iOverWrite is set to TRUE.
   *   <li><code>E_FAIL</code>if an unexpected error occured</li>
   * </ul>
   */
  HRESULT AddReferences(CATIAdpPLMIdentificator * iComponentIdentifier, CATIAdpPLMIdentificator * iOwner, CATIAdpPLMIdentificator * iReference);
	HRESULT AddReferences(const CATPLMID& iKey , const CATPLMID& iOwner, const CATPLMID& iReference);
  
  CATPLMIDMap _implOwners;
  CATPLMIDMap _implReferences;
};

class ExportedByCATPLMIntegrationAccess CATAdpComponentReferencesIter
{
public:
	CATAdpComponentReferencesIter(const CATAdpComponentReferences & iReferences);	
  ~CATAdpComponentReferencesIter();

/**
  * Settles the iterator to the next iteration.
  * @return
  * <ul>
  *   <li><code>TRUE></code> if the next iteration was set.</li>
  *   <li><code>FALSE</code> if no more iteration is available.
  * </ul>
  */
	CATBoolean Next();

/**
  * Gets the Component available for this iteration.
  * @param oInstanceId [out, CATBaseUnknown#Release]
  *   The identifier of the component.
  * @return
  * <ul>
  *   <li><code>S_OK</code> if the Component identifier was retrieved.</li>
  *   <li><code>E_FAIL</code>if an unexpected error occured</li>
  * </ul>
  */
  HRESULT GetCurrentInstance(CATIAdpPLMIdentificator *& oInstanceId);

private:
  CATPLMIDMapIter _Iterator;
};
#endif
