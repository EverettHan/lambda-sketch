/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================

/**
 * @level Protected
 * @usage U1
 */
#ifndef CATOmyCioStatCacheSnapshot_H
#define CATOmyCioStatCacheSnapshot_H

#include "CATOMYCioAnalyzer.h"
#include "CATDataType.h"
#include "CATOmyCioTypeOfCaches.h"

class CATOmyCacheAnalyzer;
#include "CATUuid.h"

/**
 * This object reports the activities of CuteIO.
 */
class ExportedByCATOMYCioAnalyzer CATOmyCioStatCacheSnapshot 
{
public:
  
 /**
  * Constructs this object.
  */
  CATOmyCioStatCacheSnapshot(const CATUuid & iTransactionUuid);

 /**
  * Delete this object.
  */
  ~CATOmyCioStatCacheSnapshot();
    
  /** 
  * Returns the number of all successfull searches of URL in CuteIO specific cache.
  * @return
  *   The number of successfull searches.
  */   
  unsigned int GetNbHit() const;
  
  /** 
  * Returns the number of all failed searches of URL in CuteIO specific cache.
  * @return
  *   The number of failed searches.
  */      
  unsigned int GetNbMissed() const;
    
  /** 
  * Returns the number of URL duplicated in CuteIO caches.
  * @return
  *   The number of duplicated streams.
  */   
  unsigned int GetNbInjected() const;
  
  /** 
  * Returns the number of URL removed from CuteIO caches.
  * @return
  *   The number of removed streams.
  */   
  unsigned int GetNbRemoved() const;

 /** 
  * Reports numbers of streams  found, not found, duplicated, and removed by CuteIO.
  * <br><b>Role</b>: This call reports the activities of CuteIo. The trace TraceOmyCuteIO
  * must be activated to diplay informations.
  */
  void WriteCuteIoReport() const;

	/** 
   * Returns the elapsed time and the stream size of a injected action.
   * @return
   *   The elapsed time and the stream size.
   */ 
	HRESULT GetElapsedTimeAndStreamSizeFromInjectedAction(CATOmyCioTypeOfCache iCacheIn, CATOmyCioTypeOfCache iCacheOut, CATLONG32 & oElapsedTime, CATLONG32 & oStreamSize) const;

private:
	CATOmyCacheAnalyzer * _CacheAnalyzer;
	//const CATUuid * _TransactionUuid;

};

#endif


