/**
 * @level Protected
 * @usage U1
 */
#ifndef CATVVSStreamSizes_H
#define CATVVSStreamSizes_H

#include "IUnknown.h"
#include "VVSCoreStructure.h"
#include "CATSysSimpleHashTable.h"
#include "CATBoolean.h"

class CATVVSStreamSize;
class CATVVSUrl;

/**
 * This class is an hashtable to store results of the call CATOmyCioAccess::GetSizeOfStreams.
 * After this call, this class contains informations about the size of streams stored in CuteIO caches
 * and vault.
 */
class ExportedByVVSCoreStructure CATVVSStreamSizes
{
public :
  /**
   * Contructs this object.
   */
  CATVVSStreamSizes();

  /**
   * Destructs this object.
   */
  virtual ~CATVVSStreamSizes();

  /**
   * Removes all elements of this hash table.
   */
  void Clear();

  /**
   * Gets the size of a stream identified by its URL.
   * @param iUrl [IN]
   *  The Url that identifies the stream.
   * @param oSizeInKo [OUT]
   *  Size in Ko of the stream.
   * @return
   * <UL>
   *    <LI><code>S_OK</code>: if the size associated with the url is found.</LI>
   *    <LI><code>S_FALSE</code>: The size associated with the url is  NOT found.</LI>
   * </UL>
   */
  HRESULT GetStreamSize(const CATVVSUrl& iUrl, unsigned int& SizeInKo);
  HRESULT GetStreamSizeByte(const CATVVSUrl& iUrl, CATLONG64& SizeInByte, CATBoolean * oIsExactSize=NULL);
  
  /**
   * This method accesses items stored in the Hashtable. Each item is located at a specific index.
   * @param iIndex
   *    The index in the hashtable. First index is 0.
   * @param oUrl
   *    The Url contained in the item.
   * @param oSizeInKo
   *    The size of the stream.
   * <UL>
   *   <LI><code>S_OK</code>: if the size associated with the url is found.</LI>
   *   <LI><code>E_INVALIDARG</code>: The given index was out of bound.</LI>
   *   <LI><code>E_FAIL</code>: An error occured.</LI>
   * </UL>
   */
  HRESULT GetStreamSize(unsigned int iIndex, CATVVSUrl& oUrl, unsigned int& oSizeInKo);

  /** 
  * Retrieves an access of an element of this Hashtable.
  * @param iIndex [in]
  *   The index of the element in the table. First index is 0.
  * @return
  *   NULL if the element was not found at this index, otherwise the element. This element is AddReffed !
  */
  CATVVSStreamSize* operator[] (unsigned int iIndex);

  /**
   * Returns the nb of items stored in the hashtable
   */
  unsigned int Size();

  /**
   * Inserts an element in the hashtable
   */
  HRESULT PutStreamSize(CATVVSStreamSize* iStreamSize);
  
  /**
   * Inserts a hashtable in the hashtable
   */
  HRESULT AddStreamSizes(CATVVSStreamSizes& iStreamSizes);

private :
  // The include hashtable.
  CATSysSimpleHashTable _implHash;
};

#endif //CATVVSStreamSizes_H
