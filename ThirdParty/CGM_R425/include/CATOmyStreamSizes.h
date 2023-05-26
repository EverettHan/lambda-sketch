/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2006
//=============================================================================

/**
 * @level Private
 * @usage U1
 */

#ifndef CATOmyStreamSizes_H
#define CATOmyStreamSizes_H

#include "CATOMYDataStructure.h"
#include "CATOmxVector.h"
#include "CATOmxOHMap.h"
#include "CATOmyCioTypeOfCaches.h"
#include "CATOmyResourceReference.h"

class CATOmyStreamSize;

/**
 * This class is an hastable to store results of the call CATOmyCioAccess::GetSizeOfStreams.
 * After this call, this class contains informations about the size of streams stored in CuteIO caches
 * and vault.
 */
class ExportedByCATOMYDataStructure CATOmyStreamSizes
{
public :
  
  // CTOR & DTOR
  CATOmyStreamSizes() {};
  CATOmyStreamSizes(const CATOmyStreamSizes& iToCopy);
  CATOmyStreamSizes& operator=(const CATOmyStreamSizes& iToCopy);    
  virtual ~CATOmyStreamSizes() {};

  // Gets the size in KByte of a stream identified by its index (starting at 0).
  HRESULT GetStreamSize(int iIndex, CATLONG64 & oSizeInKb, CATOmyCioTypeOfCache * oLoc=NULL,CATOmyResourceReference * oSrcRef=NULL, CATBoolean * oIsExactSize=NULL);
    
  // Gets the size in KByte of a stream identified by its URL.
  HRESULT GetStreamSize(const CATOmyResourceReference& iSrcRef, CATLONG64 & oSizeInKb, CATOmyCioTypeOfCache * oLoc=NULL, CATBoolean * oIsExactSize=NULL);
  
  // Gets the size in Byte of a stream identified by its index (starting at 0).  
  HRESULT GetStreamSizeInByte(int iIndex, CATLONG64 & oSizeInByte, CATOmyCioTypeOfCache * oLoc=NULL,CATOmyResourceReference * oSrcRef=NULL, CATBoolean * oIsExactSize=NULL);
  
  // Gets the size in Byte of a stream identified by its URL.  
  HRESULT GetStreamSizeInByte(const CATOmyResourceReference& iSrcRef, CATLONG64 & oSizeInByte, CATOmyCioTypeOfCache * oLoc=NULL, CATBoolean * oIsExactSize=NULL);
    
  // Returns the nb of items stored in the hashtable.
  unsigned int Size();
  
  // Inserts an element in the hashtable. If already present, data is not added.
  void AddStreamSizeInByte(const CATOmyResourceReference& iSrcRef, CATLONG64 iSizeInByte, CATOmyCioTypeOfCache iLocation, CATBoolean iIsExactSize=FALSE);

  // Removes all elements of this hash table.
  HRESULT Clear();    

private : 
  CATOmxOHMap<CATOmyResourceReference,int> _StreamsRef;
  CATOmxVector<CATOmyStreamSize>           _ListStreamsSize;  
};

#endif // CATOmyStreamSizes_H

