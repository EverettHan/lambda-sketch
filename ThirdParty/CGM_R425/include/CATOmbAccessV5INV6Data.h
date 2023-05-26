#ifndef __CATOmbAccessV5INV6Data_H
#define __CATOmbAccessV5INV6Data_H

/**
 * @level Protected
 * @usage U1
 */

#include "CATOmbSelectiveLoading.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATError.h"
#include "CATBooleanDef.h"
#include "CATIAV5Level.h"
#include "CATOmxOMap.h"
#include "CATOmxMapIter.h"
#include "CATOmbStreamDescriptorFormat.h"
#include "CATOmxArray.h"

class CATFormat;
class CATDocument;
class CATComponentId;
class CATStorageManager;

#define VCS_IR_434428_RefreshV5NativeVisu

/**
 * Visitor class for V5 representations loaded in V6
 */
class CATOmbV5INV6DataVisitor
{
public:
  /**
   * Visit V5 data
   * @param iRepRef
   *   the representation reference.
   * @param iDocument
   *   the V5 document under this representation reference.
   */
  virtual void VisitV5INV6Data(CATBaseUnknown& iRepRef,CATDocument& iDocument) = 0;
};

/** 
 * Visit V5 data in V6.
 * Requirements: 
 *  iRepRef has a CATIAV5INV6 stream descriptor for the V5 data
 *  iRefRef is loaded in AuthoringVisu(2) mode (if CATOmbVariables::V5INV6FullAccess is activated this restriction disappears)
 * Steps:
 *  V5 document will be opened
 *  containers will be loaded according to iLoadMode (Omb selective loading nomenclature)
 *  iVisitor will be called back on this V5 document
 *  V5 document will be unloaded (if CATOmbVariables::V5INV6FullAccess is activated, it will be unloaded if it was not loaded in input)
 * Warnings:
 *  Noone except [FD]BDI teams must use this service, loading V5 data in V6 may require static activation in [DF]BDI layer.
 *  reference to V5 data should not be kept as V5 data will be destroyed at the end of the algorithm.
 *  Opening V5 data may have impact on V6 visualisation.
 *  
 */
ExportedByCATOmbSelectiveLoading HRESULT CATOmbAccessV5INV6Data(CATBaseUnknown* iRepRef,const CATUnicodeString& iLoadMode,CATOmbV5INV6DataVisitor* iVisitor);

/**
 * Return S_OK if iRepRef contains "V5INV6" data as a main Authoring.
 */
ExportedByCATOmbSelectiveLoading HRESULT CATOmbIsV5INV6Data(CATBaseUnknown* iRepRef);

/**
 * Return S_OK and the PersistencyType of the data when iRepRef contains "V5INV6" data as a main Authoring.
 */
ExportedByCATOmbSelectiveLoading HRESULT CATOmbIsV5INV6Data(CATBaseUnknown* iRepRef,CATUnicodeString& oType);

/**
 * Returns 
 *   S_OK if iObj is inside a CATIAV5INV6 stream (descriptor).
 *   S_FALSE if iObj is inside any other kind of stream (descriptor)
 *   failure if iObj is not inside a stream (descriptor)
 *
 *  iObj can be 
 *    a stream descriptor
 *    a document
 *    an object inside a document (container, feature, etc...)
 */
ExportedByCATOmbSelectiveLoading HRESULT CATOmbIsInV5INV6Stream(const CATBaseUnknown* iObj);

/**
 * Returns 
 *   S_OK if iObj is inside a DeriveFromCollaborative stream (descriptor).
 *   S_FALSE if iObj is inside any other kind of stream (descriptor)
 *   failure if iObj is not inside a stream (descriptor)
 *
 *  iObj can be 
 *    a stream descriptor
 *    a document
 *    an object inside a document (container, feature, etc...)
 */
ExportedByCATOmbSelectiveLoading HRESULT CATOmbIsDeriveFromCollaborativeStream(const CATBaseUnknown* iObj); // TODO L6I: Move to a better place

ExportedByCATOmbSelectiveLoading HRESULT CATOmbGetRepUsage(CATBaseUnknown* iRepRef, 
                                                           CATOmbStreamDescriptorFormat& oFormat,
                                                           CATUnicodeString& oRole,
                                                           CATUnicodeString& oPersistencyType);  // TODO L6I: Move to a better place
/**
 * Returns 
 *   TRUE if we need to check a V5 Type compatibility in V6 while loading data out of FBDI
 *   FALSE if not
 *
 *  oErrorType is the CATErrorType to use to report and error if V5 type is not compatible
 */
ExportedByCATOmbSelectiveLoading CATBoolean MustManageV5INV6TypeCertification(const CATBaseUnknown* iContainer, CATErrorType& oErrorType);

/**
 * Check if CCP format authorized regarding role of StreamDescriptor.
 * iObj can be the container or an object inside the container of the stream.
 * In case of V5INV6 Stream Native CCP format are not authorized.
 * Returns
 *   S_OK if iFormat is authorized 
 *   S_FALSE if iFormat is not authorized
 *   E_FAIL if iFormat does not exist or iObject is not a container nor in a container
 */
ExportedByCATOmbSelectiveLoading HRESULT IsFormatAuthorizedForCopyFromStream(const CATFormat* iFormat,const CATBaseUnknown* iObject);

/**
 * Check if input belongs to a CATIAV5INV6 read-only stream 
 *
 * @param iObject [in]
 *   V6 object to be checked. It can be 
 *    a stream descriptor
 *    a document
 *    an object inside a document (container, feature, etc...)
 *
 * @param OnV5InV6Cancel [in]
 *   TRUE: Notifies a modification attempt and cancels current command
 *         when input belongs to a CATIAV5INV6 read-only stream (descriptor)
 * @return
 *   TRUE if iObject is inside a read-only CATIAV5INV6 stream (descriptor).
 *   FALSE otherwise.
 */
ExportedByCATOmbSelectiveLoading CATBoolean CATOmbIsInV5INV6ReadOnlyStream(const CATBaseUnknown* iObject, CATBoolean OnV5InV6Cancel=TRUE);

/**
 * Returns 
 *   TRUE if iObject contains or belongs to a CATIAV5INV6 stream and so cannot be saved,
 *   excepted under some restricted conditions
 *   FALSE otherwise.
 *
 *  iObject can be 
 *    a component
 *    a stream descriptor
 *    a document
 *    an object inside a document (container, feature, etc...)
 */
ExportedByCATOmbSelectiveLoading CATBoolean CATOmbIsV5InV6SaveForbidden(const CATBaseUnknown* iObject);

/**
* CATOmbV5INV6DataLoadingChecker is dedicated to debug tool
* do not use it for other purpose
*/
class ExportedByCATOmbSelectiveLoading CATOmbV5INV6DataLoadingChecker
{
public:
  
  CATOmbV5INV6DataLoadingChecker();
  ~CATOmbV5INV6DataLoadingChecker();

  /**
   * Add data to be checked in checker.
   * Please note that the RunCheck method has to be called later on checker in order to actually run the check.
   * @return
   *   S_OK if V5 Native data successfully added in checker.
   *   S_FALSE if there is no V5 Native data in RepRef.
   *   E_INVALIDARG if the RepRef is null.
   *   E_UNEXPECTED if the RepRef cannot be retrieved.
   *   E_FAIL if another error occured.
   */
  HRESULT AddComponentToCheck(const CATBaseUnknown & iRepRef);

  /** 
   * Check if the RepRefs are V5 Native certified, by attempting a switch in AuthoringFullEdit_Mode.
   * Please note that RepRefs to be checked must have been previously added in checker using AddDataToCheck method.
   * @return
   *   S_OK if all RepRefs are V5 Native certified.
   *   S_FALSE if at least one RepRef is not V5 Native certified.
   *   E_FAIL if an error occured during check.
   */
  HRESULT RunCheck();

  /**
   * Creates a file containing information about non-certified features (if any), for each RepRef which has been checked.
   * @param iFileName [in]
   *   The name of the file to be created.
   * @return
   *   S_OK if dump succeeded.
   *   E_UNEXPECTED if the dump file cannot be created.
   */
  HRESULT Dump(const CATUnicodeString & iFileName) const; 

  /**
   * Returns an iterator on the map of errors, if any.
   */
  inline CATOmxMapIter<CATBaseUnknown *, CATError *> GetIterator() const { return m_ErrorMap.MapIterator(); }

private:

  CATOmbV5INV6DataLoadingChecker(const CATOmbV5INV6DataLoadingChecker &); // not implemented.
  CATOmbV5INV6DataLoadingChecker & operator=(CATOmbV5INV6DataLoadingChecker &); // not implemented.

  CATOmxOMap<CATBaseUnknown *, CATUnicodeString> m_LoadingModeMap;
  CATOmxOMap<CATBaseUnknown *, CATError *, naive_manager, com_manager> m_ErrorMap;
};

// </CATOmbV5INV6DataLoadingChecker>

// <CATOmbV5INV6CertificationChecker>

class CATIDocId;
class CATILockBytes2;

/**
* CATOmbV5INV6CertificationChecker is dedicated to reporting tool only.
* For other purposes, please use CATIOmiSwitchEngine in order to load data in session and handle errors properly.
*/
class ExportedByCATOmbSelectiveLoading CATOmbV5INV6CertificationChecker
{
public:
  CATOmbV5INV6CertificationChecker();
  ~CATOmbV5INV6CertificationChecker();

  /** 
   * Check if the input RepRef is V5 Native certified.
   * @param iRepRef [in]
   *   The RepRef to be checked for V5 Native certification.
   * @return
   *   S_OK if the input RepRef is V5 Native certified.
   *   S_FALSE if the input RepRef is not V5 Native certified.
   *   E_INVALIDARG if the input RepRef is null.
   *   E_FAIL (or maybe E_UNEXPECTED) if another error occured during check.
   */
  HRESULT RunCheck(const CATBaseUnknown & iRepRef);

private:
  friend ExportedByCATOmbSelectiveLoading CATBoolean MustManageV5INV6TypeCertification(const CATBaseUnknown* iContainer, CATErrorType& oErrorType);
  static HRESULT OpenDocumentSilently(CATIDocId * iDocId, CATILockBytes2 * iLockBytes);
  static HRESULT InternalOpenDocument(CATIDocId& iDocId, CATStorageManager& iStorageManager, CATDocument*& oDocument, CATBoolean& oCertifErrorRaised);
  static CATBoolean s_CheckInProgress;
};

// </CATOmbV5INV6CertificationChecker>

#endif
