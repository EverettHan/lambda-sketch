
#ifndef __DataCommonProtocolServices_h__
#define __DataCommonProtocolServices_h__

// COPYRIGHT DASSAULT SYSTEMES 2009  

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

class CATIUseEntity;
#include "DataCommonProtocolUse.h" // ExportedByDataCommonProtocolUse

#include "CATSysBoolean.h" // CATBoolean
#include "CATSysErrorDef.h" // HRESULT

/**
 * Generic services that operate on all objets implementing CATIUseEntity interface.
 * For more specific details, please refer to the documentation of each entity.
 * @see CATIUseEntity
 */
class ExportedByDataCommonProtocolUse DataCommonProtocolServices
{
public:

  // Services related to the Update protocol.

  /**
   * Returns the update status of an entity.
   * @param iEntity
   *      the object to consider.
   * @param oUpToDate
   *      the computed or retrieved update status.
   * @return
   *  <ul><li><tt>S_OK</tt>: the update status has been computed or retrieved sucessfully and been stored in oUpToDate parameter.</li>
   *      <li><tt>E_POINTER</tt>: input parameter iEntity is null or invalid.</li>
   *      <li><tt>E_NOTIMPL</tt>: there is no update aspect implemented on the provided object.</li>
   *      <li><tt>E_FAIL</tt>: the operation could not be completed.<br>
   *              More information may be available via <tt>CATError::CATGetLastError</tt>.</li></ul>
   */
  static HRESULT IsUpToDate(const CATIUseEntity * iEntity, CATBoolean & oUpToDate);
  /**
   * Updates an entity.
   * This service will first call the IsUpToDate service.<br>
   * Depending on the result, the following action(s) will be taken:
   *   <ul><li><tt>(S_OK, oUpToDate == FALSE)</tt>: invoke actual update code, return update return code.
   *       <li><tt>(S_OK, oUpToDate == TRUE)</tt>: return S_FALSE (update code is NOT invoked).
   *       <li><tt>E_POINTER</tt>: return E_POINTER (update code is NOT invoked).
   *       <li><tt>E_NOTIMPL</tt>: return E_NOTIMPL (update code is NOT invoked).
   *       <li><tt>E_FAIL</tt>: return E_UNEXPECTED (update code is NOT invoked).<br>
   *              More information may be available via <tt>CATError::CATGetLastError</tt>.</li></ul>
   * @param iEntity
   *      the object to consider.
   * @return
   *  <ul><li><tt>S_OK</tt>: the update was sucessful.</li>
   *      <li><tt>E_POINTER</tt>: input parameter iEntity is null or invalid.</li>
   *      <li><tt>E_NOTIMPL</tt>: there is no update aspect implemented on the provided object.</li>
   *      <li><tt>E_FAIL</tt>: the operation could not be completed.<br>
   *              More information may be available via <tt>CATError::CATGetLastError</tt>.<br>
   *              Warning: The model may be left modified after a failed call.</li></ul>
   */
  static HRESULT Update(CATIUseEntity * iEntity);

  // Services related to the Delete protocol.

  /**
   * Returns the deletable status of an entity.
   * @param iEntity
   *      the object to consider.
   * @param oDeletable
   *      the computed or retrieved deletable status.
   * @return
   *  <ul><li><tt>S_OK</tt>: the deletable status has been computed or retrieved sucessfully and been stored in oDeletable parameter.</li>
   *      <li><tt>E_POINTER</tt>: input parameter iEntity is null or invalid.</li>
   *      <li><tt>E_NOTIMPL</tt>: there is no deletion aspect implemented on the provided object.</li>
   *      <li><tt>E_FAIL</tt>: the operation could not be completed.<br>
   *              More information may be available via <tt>CATError::CATGetLastError</tt>.</li></ul>
   */
  static HRESULT CanDelete(const CATIUseEntity * iEntity, CATBoolean & oDeletable);
  /**
   * Deletes an entity.
   * This service will first call the CanDelete service.<br>
   * Depending on the result, the following action(s) will be taken:
   *   <ul><li><tt>(S_OK, oDeletable == TRUE)</tt>: invoke actual deletion code, return deletion return code.
   *       <li><tt>(S_OK, oDeletable == FALSE)</tt>: return E_ACCESSDENIED (deletion code is NOT invoked).
   *       <li><tt>E_POINTER</tt>: return E_POINTER (deletion code is NOT invoked).
   *       <li><tt>E_NOTIMPL</tt>: invoke actual deletion code, return deletion return code.
   *       <li><tt>E_FAIL</tt>: return E_UNEXPECTED (deletion code is NOT invoked).<br>
   *              More information may be available via <tt>CATError::CATGetLastError</tt>.</li></ul>
   * @param iEntity
   *      the object to consider.
   * @return
   *  <ul><li><tt>S_OK</tt>: the deletion was sucessful.</li>
   *      <li><tt>E_ACCESSDENIED</tt>: the entity may not be deleted.</li>
   *      <li><tt>E_UNEXPECTED</tt>: the entity failed to indicate whether it can be deleted or not.</li>
   *      <li><tt>E_POINTER</tt>: input parameter iEntity is null or invalid.</li>
   *      <li><tt>E_NOTIMPL</tt>: there is no deletion aspect implemented on the provided object.</li>
   *      <li><tt>E_FAIL</tt>: the operation could not be completed.<br>
   *              More information may be available via <tt>CATError::CATGetLastError</tt>.<br>
   *              Warning: The model may be left modified after a failed call.</li></ul>
   */
  static HRESULT Delete(CATIUseEntity * iEntity);

};

#endif // __DataCommonProtocolServices_h__
