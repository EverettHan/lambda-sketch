/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2009
//=============================================================================
/**
* @level Protected
* @usage U1
*/

#ifndef CATOmbIncStream_H
#define CATOmbIncStream_H

#include "AD0XXBAS.h"
#include "CATDataType.h"
#include "CATFile.h"
#include "CATOmxArray.h"
template <> CATOmxCollecManager& CATOmxDefaultCollecManager<CATULONG64>::manager();

class ExportedByAD0XXBAS CATOmbIncStream 
{
  public:
 
  // Le constructeur sera à terme privé. Public pour permettre à CGM de se tester en attendant notre intégration 
  CATOmbIncStream(CATStream& iStream, DWORD iOpenMode, CATULONG64 iTotalSize, CATOmxArray<CATULONG64> iIncPosition);
  virtual ~CATOmbIncStream() ;
 
  
  /**
  * Get the applicative size of current stream
  * Role:
  *   This is the size of applicative data. The real size is higher since OMB will add some markers within the stream
  *
  *
  * @return
  *   size of all streams belonging to a container
  *
  */  
  CATULONG32 GetCurrentIncrementSize();
  
  /** 
  * Provide read-access at the beginning of the first stream of the persisted view of a container
  *
  * <br><b>Role</b>: 
  *   Provide read-access to the first FULL stream and not to the first increment.   
  *
  * @return
  *   <code>S_OK</code>
  *   <code>E_INVALIDARG</code>Write operation are forbidden with the stream after this call
  *   <code>E_*</code> unexpected error. do not try to read/write any data within the stream
  *
  */
  HRESULT SeekToFirstIncrement(CATStream*& opStream);
  
  /** 
  * Provide read-access  at the beginning of the last stream of the persisted view of a container
  *  
  * @param opStream [out] Please read limitation at the bottom of the file
  *
  * @return
  *   <code>S_OK</code>
  *   <code>E_INVALIDARG</code>Write operation are forbidden with the stream after this call
  *   <code>E_*</code> unexpected error. do not try to read/write any data within the stream
  *
  */
  HRESULT SeekToLastIncrement(CATStream*& opStream);
  
  /** 
  * Provide read-access at the beginning of the next stream of the persisted view of a container
  *
  * @param opStream [out] Please read limitation at the bottom of the file
  *
  * @return
  *   <code>S_OK</code>
  *   <code>S_FALSE</code> No next Increment available
  *   <code>E_INVALIDARG</code>Write operation are forbidden with the stream after this call
  *   <code>E_*</code> unexpected error. do not try to read/write any data within the stream
  *
  */
  HRESULT SeekToNextIncrement(CATStream*& opStream);
    
private:  
  
  CATINT32 _CurrentIndex;
  CATULONG64 _CurrentPos;
  CATLONG64 _StartPos;
  CATStream* _pStream;
  DWORD _OpenMode;    
  CATOmxArray<CATULONG64> _IncPosition;
  
  
  /** not implemented */
  CATOmbIncStream (const CATOmbIncStream& iOmbStream);
    
};


  /** 
  * Limitation of provided physical CATStream
  *  
  *  According to the inner implementation, one cannot do everything on the CATStream
  *  If IncrementalStreams are stored on only one physical CATStream (as it is so far in R208)
  *  each increment is stored in append mode
  *     - be very carefull when using seek on the physical CATStream... you may reach another increment... 
  *       and corrupt your data if writing there
  *     - Never work on a CATStream after you have retrieved a new one thanks to this service
  *  If IncrementalStreams are stored as independent CATStream (safer mode)
  *		-  you can seek within the CATStream with no problem
  *		-  All CATStream except the one returned by this service will be closed. Do not use them. 
  *
  */



#endif
