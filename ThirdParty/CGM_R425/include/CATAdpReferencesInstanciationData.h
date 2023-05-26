/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2013
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATAdpReferencesInstanciationData_H
#define CATAdpReferencesInstanciationData_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATPLMID.h"
class CATAdpReferencesInstanciationDataImpl;
class CATPLMID;
class CATPLMIDSet;
class CATIAdpPLMIdentificator;
class CATAdpInstanciationData;
class CATAdpReferencesInstanciationDataIter;

/*
 * Collection associating some Instanciation Data to References.
 * If you retrieved such a collection through a query (such as @href CATAdpExtendedQueryServices::WhereInstanciated), you can handle it this way:
 *
 * <code>
 * CATAdpReferencesInstanciationData myInfos;
 * // ... your query here.
 * CATAdpReferencesInstanciationDataIter iter = myInfos.GetIterator();
 * while ( iter.Next() )
 * {
 *   CATAdpInstanciationData Data;
 *   if ( SUCCEEDED( iter.GetInstanciationData(Data)) )
 *   {
 *     // ... your treatment here.
 *   }
 * }
 * </code>
 */
class ExportedByCATPLMIntegrationAccess CATAdpReferencesInstanciationData
{
public:
  CATAdpReferencesInstanciationData();
  ~CATAdpReferencesInstanciationData();
  CATAdpReferencesInstanciationData & operator=( const CATAdpReferencesInstanciationData & );
  CATAdpReferencesInstanciationData( const CATAdpReferencesInstanciationData & );  

  
/**
 * Retrieve the Instanciation Data for a given Reference.
 * <br><b>Role</b>: Enables the user to retrieve the Instanciation results for a given Reference.
 *
 * @param iReference [in]
 *   The identifier of the Reference.
 * @param oData [out]
 *   The Instanciation Data for the given Reference.
 *
 * @return
 * <ul>
 *   <li><code>S_OK</code> if the informations are available for the Reference.</li>
 *   <li><code>E_FAIL</code> if no infos are available.</li>
 * </ul>
 */
  HRESULT GetInstanciationData( CATIAdpPLMIdentificator * iReference, CATAdpInstanciationData & oData ) const;
  HRESULT GetInstanciationData( const CATPLMID & iReference, CATAdpInstanciationData & oData ) const;

/**
 * Retrieve an iterator on the collection.
 */
  CATAdpReferencesInstanciationDataIter GetIterator() const;

private:
  friend class CATPLMInstanciationDataQueryRecordParser;
  friend class CATAdpReferencesInstanciationDataFinder;
  friend class CATAdpReferencesInstanciationDataIter;
  CATAdpReferencesInstanciationDataImpl * _letter;
};

class ExportedByCATPLMIntegrationAccess CATAdpReferencesInstanciationDataIter
{
public:
  ~CATAdpReferencesInstanciationDataIter();
  CATAdpReferencesInstanciationDataIter( const CATAdpReferencesInstanciationDataIter & );  

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
 * <br><b>Role</b>: Enables the user to retrieve the Instanciation results for the current Reference.
 *
  * @param oData [out]
  *   The instanciation Data of the Reference concerned by this iteration.
  *
  * @return
  * <ul>
  *   <li><code>S_OK</code> if the Component identifier was retrieved.</li>
  *   <li><code>E_FAIL</code>if an unexpected error occured</li>
  * </ul>
  */
  HRESULT GetInstanciationData( CATAdpInstanciationData & oData ) const;

private:
  CATAdpReferencesInstanciationDataIter & operator=( const CATAdpReferencesInstanciationDataIter & );

  friend class CATAdpReferencesInstanciationData;
  CATAdpReferencesInstanciationDataIter( const CATAdpReferencesInstanciationData & iReferences );	

private:
  const CATAdpReferencesInstanciationData & _ReferencesInstanciationData;
  CATLISTV(CATPLMID) _InputReferences;
  int _Count;
  int _Size;
};
#endif
