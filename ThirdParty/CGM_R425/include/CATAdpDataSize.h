/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
/**
* @level Protected
* @usage U1  
*/

#ifndef __CATAdpDataSize__
#define __CATAdpDataSize__

#include "CATPLMIntegrationAccess.h"
#include "CATOmyStreamSizes.h"

// System
#include "CATBaseUnknown.h"

class CATIAdpPLMIdentificator;



/**
* This object aggregates several CATOmyStreamSize around a representation implementing CATIAdpPLMIdentificator.
* It contains the sizes of the different streams of a representation, in distant vault or in local cache.
* Produced by CATAdpProtectedDataSizeServices::GetRepDataSize
*/
class ExportedByCATPLMIntegrationAccess CATAdpDataSize : public CATBaseUnknown
{
public:

  /** 
  * Get the total size of the blueprint of the representation in vault.
  * @param oSizeInKo [out]
  *   The size of the representation in vault. This size is in Kilo Bytes.
  */
  void GetDataSize(unsigned int& oSizeInKo);

  /** 
  * Get the total size of the blueprint of the representation stored in caches.
  * @param oCachedSizeInKo [out]
  *   The size of the representation stored in vault. This size is in Kilo Bytes.
  */
  void GetDataSizeInCache(unsigned int& oCachedSizeInKo);

  /** 
  * Gets the index of this object.
  * @param oIdentificator [out, CATBaseUnknown#Release]
  *   The identifier of the representation. It is used as index.
  */
  void GetAdpPLMIdentificator(CATIAdpPLMIdentificator*& oIdentificator);

  /** 
  * Get the number of streams aggregated in this representation.
  * @param oNbStream [out]
  *   The number of streams.
  */
  void GetNbStreams(unsigned int& oNbStream);

  /** 
  * Get the number of streams aggregated in this representation, and stored in cache.
  * @param oNbStream [out]
  *   The number of streams in cache.
  */
  void GetNbStreamsInCache(unsigned int& oNbStream);

 /** 
  * Compute Hash key method of this element.
  */
  static unsigned int Hash ( void * iObj);
 
 /** 
  * Comparison method to put this element in a Hashtable.
  */
  static int Compare(void *iObj1, void *iObj2);

  virtual ~CATAdpDataSize() {}

private:
  
  // The index of the representation
  CATOmxSR<CATIAdpPLMIdentificator> _spRepId;
  // The list of stream descriptors' data sizes
  CATOmyStreamSizes                 _StreamSizes;
  
  // ctor
  CATAdpDataSize(CATIAdpPLMIdentificator* iIdentifier);
  void SetSizes(const CATOmyStreamSizes & iStreamSizes)
    {_StreamSizes = iStreamSizes;}
                 
  CATAdpDataSize( const CATAdpDataSize & ); // NOT IMPLEMENTED
  CATAdpDataSize & operator =( const CATAdpDataSize & ); // NOT IMPLEMENTED

  HRESULT Hash( unsigned int & oKey );

  friend class CATAdpDataSizes;
  friend class CATAdpProtectedDataSizeServices;
};
#endif // __CATAdpDataSize__
