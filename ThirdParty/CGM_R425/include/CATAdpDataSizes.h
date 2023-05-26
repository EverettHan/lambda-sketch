/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
/**
* @level Protected
* @usage U1  
*/


#ifndef __CATAdpDataSizes__
#define __CATAdpDataSizes__

#include "IUnknown.h"
#include "CATPLMIntegrationAccess.h"
#include "CATSysSimpleHashTable.h"

class CATIAdpPLMIdentificator;
class CATAdpDataSize;

/**
 * This class is an Hash table that manage CATAdpDataSize object. This hash table
 * is indexed on CATIAdpPLMIdentificator
 */
class ExportedByCATPLMIntegrationAccess CATAdpDataSizes
{
public:
  
  /** 
  * Constructs this hash table.
  * @param iNbOfElem [in]
  *   The approximative number of elements stored in Hashtable.
  */
  CATAdpDataSizes(unsigned int iNbOfElem);

  /**
   * Destructs this object.
   */
  virtual ~CATAdpDataSizes();


  /** 
  * Gets the object CATAdpDataSize indexed on CATIAdpPLMIdentificator in the Database.
  * @param iIdentificator [in]
  *   The index of the expected object
  * @param oDataSize [out, CATBaseUnknown#Release]
  *   The found object. Must be released.
  * @return
  *   <UL>
  *     <LI><code>S_OK</code>: the object is found in the hash table.</LI>
  *     <LI><code>S_FALSE</code>: the object is NOT found in the hash table.</LI>
  *     <LI><code>E_FAIL</code>: A problem occurs.</LI>
  *   </UL>
  */
  HRESULT GetAdpDataSize(CATIAdpPLMIdentificator& iIdentificator, CATAdpDataSize*& oDataSize);
  
  /**
   * Gets the nbr of element stored in this Hash table.
   * @return
   *    The number of Elements.
   */
  unsigned int Size();

  /** 
  * Deletes all Elements in the Hash table.
  *
  */
  void Clear();

private:
  /**
   * Add an element in the hash table. Internal usage.
   * @param iDataSize [in]
   *   The object to insert.
  * @return
  *   <UL>
  *     <LI><code>S_OK</code>: the object is successfully inserted.</LI>
  *     <LI><code>S_FALSE</code>: an object is already inserted at this index.</LI>
  *     <LI><code>E_FAIL</code>: A problem occurs.</LI>
  *   </UL>  
  */
  HRESULT PutAdpDataSize(CATAdpDataSize* iDataSize);

  // Internal usage.
  CATSysSimpleHashTable _Implhash;

  // class that can call PutAdpDataSize.
  friend class CATAdpProtectedDataSizeServices;
};

#endif //__CATAdpDataSizes__
