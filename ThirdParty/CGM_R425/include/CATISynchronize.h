/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATISynchronize_h
#define _CATISynchronize_h

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"

/**
 * Interface to manage synchronization of elements.
 * <b>Role</b>: A element is synchronized according to its reference.
 *              The element points its reference.
 *              After the synchronization ReferenceTime and LastSynchronized
 *              time are equal.
 */
#include "AC0XXLNK.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAC0XXLNK IID IID_CATISynchronize;
#else
extern "C" const IID IID_CATISynchronize;
#endif

class CATTime;

class ExportedByAC0XXLNK CATISynchronize : public CATBaseUnknown
{
public:
  CATDeclareInterface;
  /**
   * Retrieves the synchronize status.
   * @param oSynchronizeStatus
   * The synchronize status.
   * <br><b>Legal values </b>:
   * <br>0 : the element is not synchronized. 
   * <br>1 : the element is synchronized 
   * <br>2 : synchronization has no meaning for this element 
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL
   */
  virtual HRESULT SynchronizeStatus(int& oSynchronizeStatus) = 0;

  /**
   * Synchronizes the element.
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL
   */
  virtual HRESULT Synchronize() = 0;

  /**
   * Retrieves the reference time.
   * @param oReferenceTime
   * The reference time.
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL
   */
  virtual HRESULT GetReferenceTime(CATTime& oReferenceTime) = 0;
  
   /**
   * Retrieves the last synchronized time.
   * @param oLastSynchronizedTime
   * The last synchronized time.
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL
   */
  virtual HRESULT GetLastSynchronizedTime(CATTime& oLastSynchronizedTime) = 0;
  
};

#endif
