/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2013
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATAdpInstanciationData_H
#define CATAdpInstanciationData_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATPLMIDCollections.h"
#include "CATPLMID.h"
#include "CATOmxSet.h"
#include "CATOmxPair.h"
#include "CATOmxIter.h"
class CATIAdpPLMIdentificator;
class CATAdpInstanciationDataIter;

/*
 * Collection associating some Instanciation Data to References.
 * If you retrieved such a collection through a query (such as @href CATAdpExtendedQueryServices::WhereInstanciated), you can handle it this way:
 *
 * <code>
 * CATAdpInstanciationData myInfos;
 * // ... your query here.
 * while ( myInfos.Next() )
 * {
 *   CATIAdpPLMIdentificator * pInstance=0;
 *   CATIAdpPLMIdentificator * pReference=0;
 *   CATAdpInstanciationData Data;
 *   if ( SUCCEEDED( myInfos.GetInstanceData(pInstance, pReference)) )
 *   {
 *     // ... your treatment here.
 *   }
 *   CATSysReleasePtr(pInstance);
 *   CATSysReleasePtr(pReference);
 * }
 * </code>
 */
class ExportedByCATPLMIntegrationAccess CATAdpInstanciationData
{
public:
  CATAdpInstanciationData();
  ~CATAdpInstanciationData();
  CATAdpInstanciationData & operator=( const CATAdpInstanciationData & );
  CATAdpInstanciationData( const CATAdpInstanciationData & );  

/**
  * Gets the Reference for which instanciation information are available.
  * <br><b>Role</b>: Enables the user to retrieve the Reference the instanciation information are dealing with.
  *
  * @param oReference [out, CATBaseUnknown#Release]
  *   The identifier of the Reference which instanciation information are available.
  *
  * @return
  * <ul>
  *   <li><code>S_OK</code> if the information were retrieved.</li>
  *   <li><code>E_FAIL</code>if an unexpected error occured</li>
  * </ul>
  */
  HRESULT GetInstanciatedReference( CATIAdpPLMIdentificator *& oReference ) const;

/**
  * Gets the Reference for which instanciation information are available.
  * <br><b>Role</b>: Enables the user to retrieve the Reference the instanciation information are dealing with.
  *
  * @param oReference [out]
  *   The identifier of the Reference which instanciation information are available.
  *
  * @return
  * <ul>
  *   <li><code>S_OK</code> if the information were retrieved.</li>
  *   <li><code>E_FAIL</code>if an unexpected error occured</li>
  * </ul>
  */
  HRESULT GetInstanciatedReference( CATPLMID & oReference ) const;
  

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
  * Gets the results available for this iteration.
  * <br><b>Role</b>: Enables the user to retrieve an Instanciation Data for the current Reference.
  *
  * @param oInstance [out, CATBaseUnknown#Release]
  *   The identifier of the Instance of the input Reference.
  * @param oReference [out, CATBaseUnknown#Release]
  *   The identifier of the Reference owning the Instance of the input Reference.
  *
  * @return
  * <ul>
  *   <li><code>S_OK</code> if the information were retrieved.</li>
  *   <li><code>E_FAIL</code>if an unexpected error occured</li>
  * </ul>
  */
  HRESULT GetInstanceData( CATIAdpPLMIdentificator *& oInstance, CATIAdpPLMIdentificator *& oReference ) const;

/**
  * Gets the results available for this iteration.
  * <br><b>Role</b>: Enables the user to retrieve an Instanciation Data for the current Reference.
  *
  * @param oInstance [out]
  *   The identifier of the Instance of the input Reference.
  * @param oReference [out]
  *   The identifier of the Reference owning the Instance of the input Reference.
  *
  * @return
  * <ul>
  *   <li><code>S_OK</code> if the information were retrieved.</li>
  *   <li><code>E_FAIL</code>if an unexpected error occured</li>
  * </ul>
  */
  HRESULT GetInstanceData( CATPLMID & oInstance, CATPLMID & oReference ) const;

private:
  HRESULT Finalize();
  friend class CATAdpReferencesInstanciationDataImpl;
  HRESULT SetInstanciatedReference( const CATPLMID & iReference );
  HRESULT AddInstanceData( const CATPLMID & iInstance, const CATPLMID & iReference );

private:
  CATPLMID _InstanciatedReference;
  CATPLMIDMap _InstanceData;
  CATPLMIDMapIter * _Iterator;
  CATBoolean _Iterating;
};
#endif
