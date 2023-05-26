/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2012
/**
* @level Protected
* @usage U1  
*/
#ifndef CATAdpComponentsInfos_H
#define CATAdpComponentsInfos_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATOmxOMap.h"
#include "CATAdpComponentInfos.h"
#include "CATPLMIDCollecManager.h"

class CATPLMTypeH;
class CATIAdpPLMIdentificator;
class CATAdpComponentsInfosIter;


typedef CATOmxOMap<CATPLMID, CATAdpComponentInfos > CATAdpComponentsInfosMap;

/*
* Collection associating some informations (PLMAttributes) to components. Mainly used as @href CATAdpComponentQuery output.
*
* If you retrieved such a collection through a query (such as @href CATAdpComponentQuery::GetElementsByUniqueKey), you can handle it this way:
*
* <code>
* CATAdpComponentsInfos myInfos;
* // ... Your query here.
* CATAdpComponentsInfosIter iter = myInfos.GetIterator();
* while ( iter.Next() )
* {
*    CATOmxSR<CATIAdpPLMIdentificator> Id;
*    iter.GetComponent(Id.AsPtrRef();
*    CATAdpComponentInfos & componentInfos = iter.GetComponentInfos();
*    // ... Your code here
* }
* </code>
*/
//template <> CATOmxCollecManager & CATOmxDefaultCollecManager <CATIAdpPLMIdentificator *>::manager();
//template <> CATOmxCollecManager & CATOmxDefaultCollecManager <CATAdpComponentInfos>::manager () ;

class ExportedByCATPLMIntegrationAccess CATAdpComponentsInfos
{
public:
  CATAdpComponentsInfos();
  ~CATAdpComponentsInfos();
  CATAdpComponentsInfos & operator=(const CATAdpComponentsInfos &);
  CATAdpComponentsInfos(const CATAdpComponentsInfos &);  

  /**
  * Retrive the informations associatied with a given identifier.
  * @param iComponentIdentifier [in]
  *   The identifier of the component.
  * @param oInfos [out]
  *   The inforamtions for the given component see @href CATAdpComponentInfos.
  *
  * @return
  * <ul>
  *   <li><code>S_OK</code> if the informations are available for the component.</li>
  *   <li><code>E_FAIL</code> if no infos for iComponentIdentifier</li>
  * </ul>
  */
  HRESULT GetInfos(CATIAdpPLMIdentificator * iComponentIdentifier, CATAdpComponentInfos & oInfos);

  /**
  * Associate the informations to a given identifier.
  * @param iComponentIdentifier [in]
  *   The identifier of the component.
  * @param iInfos [in]
  *   The inforamtions for the given component see @href CATAdpComponentInfos.
  * @param iOverWrite [in]
  *   Specify what to do if the component already has some associated informations:
  *   <ul>
  *     <li><code>TRUE</code> The information is overwritten.</li>
  *     <li><code>FALSE</code> The information is NOT overwritten.</li>
  *    </ul>
  * @return
  * <ul>
  *   <li><code>S_OK</code> if the informations are set for the component.</li>
  *   <li><code>S_FALSE</code> if the component already has some associated informations. The informations are overwritten only if iOverWrite is set to TRUE.
  *   <li><code>E_FAIL</code>if an unexpected error occured</li>
  * </ul>
  */
  HRESULT AddInfos(CATIAdpPLMIdentificator * iComponentIdentifier, const CATAdpComponentInfos & iInfos, CATBoolean iOverWrite=FALSE);

  /**
  * Number of components in the collection.
  */
  unsigned int Size() const;

  /**
  * Retrieve an iterator on the collection.
  */
  CATAdpComponentsInfosIter GetIterator() const;

private:

  CATAdpComponentsInfosMap _impl;
};

class ExportedByCATPLMIntegrationAccess CATAdpComponentsInfosIter
{
public:
  CATAdpComponentsInfosIter( const CATAdpComponentsInfosMap & iInfos ) : _Iterator(iInfos.MapIterator()) {}
  ~CATAdpComponentsInfosIter() {}

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
  * @param oComponent [out, CATBaseUnknown#Release]
  *   The identifier of the component.
  * @return
  * <ul>
  *   <li><code>S_OK</code> if the Component identifier was retrieved.</li>
  *   <li><code>E_FAIL</code>if an unexpected error occured</li>
  * </ul>
  */
  HRESULT GetComponent( CATIAdpPLMIdentificator *& oComponent );

  /**
  * Gets the Component information available for this iteration.
  * @return
  * <ul>
  *   <li>The Component infos.</li>
  * </ul>
  */
  CATAdpComponentInfos & GetComponentInfos();

private:
  CATAdpComponentsInfosMap::MapIteratorType _Iterator;
};
#endif
