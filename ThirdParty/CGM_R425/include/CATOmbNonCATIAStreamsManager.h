/* -*-c++-*- */
//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2012
//------------------------------------------------------------------------------
//
// OMB wrapper: facade for all Streams access/management services
// 
//------------------------------------------------------------------------------
// 20/09/2012 Creation                                                       VCS
//------------------------------------------------------------------------------
#ifndef CATOmbNonCATIAStreamsManager_H
#define CATOmbNonCATIAStreamsManager_H
#define CATOmbStreamsOnEntitiesDevForPC2

// CATVirtualVaultSystem
#include "CATVVSEnv.h"
#include "CATVVSFileDescriptionServices.h"
// ObjectModelerBase
#include "CATIOmbNonCATIASDPersistencyMngt.h"
#include "CATOmbComponentStreamsManager.h"
#include "CATOmbLoadableDataUniqueKey.h"
#include "CATOmbSelectiveLoading.h"
// SystemTS
#include "CATBoolean.h"
#include "IUnknown.h"
// System
#include "CATUnicodeString.h"
// ObjectModelerCollection
#include "CATOmxIter.h"
#include "CATOmxKeyValueBlock.h"
#include "CATOmxSR.h"

class CATComponentId;
class CATIOmbNonCATIADocumentApplicativeBehavior;

class ExportedByCATOmbSelectiveLoading CATOmbNonCATIAStreamsManager : public CATOmbComponentStreamsManager
{
public:

  //-------------------------------------------------------------------------------------------------------------------
  //                                   Access to a PLM component streams                                       
  //-------------------------------------------------------------------------------------------------------------------

  /**
  * Initializes a CATOmbComponentStreamsManager from a pointer.
  * ipComponent must be a pointer to a representation reference or entity with stream.
  * If you already have the CATComponentId object, for performance reason prefer next constructor.
  */
  CATOmbNonCATIAStreamsManager(CATBaseUnknown* ipComponent);

  /**
  * Initializes a CATOmbComponentStreamsManager from a CATComponentId.
  * iComponentID must be a refer to a representation reference or entity with stream.
  */
  CATOmbNonCATIAStreamsManager(const CATComponentId& iComponentID);

  /** dtor*/
  ~CATOmbNonCATIAStreamsManager();

  /**
  Reads the Local Storage status for the stream handled by a Stream Descriptor
  Dedicated to (Format:authoring Role:Extended) typed SDs
  * @param iKey [in]
  *        the key identifying the Stream Descriptor to look for
  * @return
  *        TRUE : the authoring extended SD have been declared as Local Storage
  *        FALSE : Not an authoring extended SD or not declared as Local Storage
  */
  CATBoolean IsALocalStorage(const CATOmbLoadableDataUniqueKey& iKey, FD::FileDescriptionBehavior& oLocalStorageBehavior);

  /**
  Sets a Stream Descriptor as a Local Storage
  The stream handled by the SD is no more propagated to SessionCache/FCS at next Save(s), but its location path on a local disk (creation path or projection/checkout pathes)
  * @param iKey [in]
  *        the key identifying the Stream Descriptor to look for
  * @return
  *        S_OK : operation succeeded
  *        S_FALSE : nothing has to be done (the status was already the one in entry)
  *        CATOmb_E_KEY_INVALID:  SD not found or not typed as (Format:authoring Role:Extended)
  */
  HRESULT SetAsLocalStorage(const CATOmbLoadableDataUniqueKey& iKey);

  /**
  Unsets the Local storage status of the stream handled by a Stream Descriptor
  The stream is again propagated to FCS at next Save(s) from its location path on a local disk (creation path or projection/checkout pathes)
  * @param iKey [in]
  *        the key identifying the Stream Descriptor to look for
  * @return
  *        S_OK : operation succeeded and local path will still remain locked, so not deleted, at next save.
  *        CATOmb_S_LocalStorageRemovable : operation succeeded  and local path will be unlocked, so potentially deleted, at next save.
  *        S_FALSE : nothing has to be done (the status was already set before)
  *        CATOmb_E_KEY_INVALID:  SD not found or not typed as (Format:authoring Role:Extended)
  */
  HRESULT UnsetLocalStorage(const CATOmbLoadableDataUniqueKey& iKey);

  /**
  Declares a local disk path as the Local storage location of the stream handled by the SD
  The local Storage status must have been previously assigned to the SD using SetAsLocalStorage
  The stream handled by the SD is not propagated to SessionCache/FCS at next Save, but this external location path
  Any eventual Projection/Export+Import operation already performed is reset by this call and so not taken into account at next Save.
  * @param iKey [in]
  *        the key identifying the Stream Descriptor to look for
  * @param iFilePath [in]
  *        the external (Local) storage location
  * @return
  *        S_OK : operation succeeded
  *        CATOmb_E_KEY_INVALID:  SD not found or not typed as (Format:authoring Role:Extended)
  *        E_INVALIDARG : SD not declared as LocalStorage
  */
  HRESULT ImportLocalStoragePath(const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iFilePath);

  /**
  Reads the local disk path previously defined as the Local storage location of the stream handled by the SD
  * @param iKey [in]
  *        the key identifying the Stream Descriptor to read
  * oFilePath [out]
  *        the external (Local) storage location, if any
  * @return
  *        S_OK : operation succeeded
  *        CATOmb_E_KEY_INVALID: SD not found or not typed as (Format:authoring Role:Extended)
  *        E_INVALIDARG :The SD is not declared as LocalStorage unmanaged
  *                      No ImportLocalStoragePath currently performed on SD to be saved
  *                      SD saved as Local Storage but does not reference a Local path previously Imported
  *        E_VVS_LS_FileNotFound:
  *                      SD saved as Local Storage but references an invalid or not found path (file path modified, deleted, not on local host ..)
  */
  HRESULT ExportLocalStoragePath(const CATOmbLoadableDataUniqueKey& iKey, CATUnicodeString& oFilePath);

  /**
  *Reads the eventual Local storage description of the stream handled by the SD
  * @param iKey [in]
  *        The key identifying the Stream Descriptor to read
  * oLSDescription [out]
  *        The Local storage description attributes block. Keys(Attributes) are (readable) the following (way):
  *        reference
  *
  *    LSDescription.GetValue(LSKey().LocalPath, LSPath) + LSPath.GetString()
  *        The Local storage location, if any. Path and existence of the file are checked.
  *
  *    LSDescription.GetValue(LSKey().OwnerId, LSOwnerId)) + LSOwnerId.GetUuid(uuid)
  *        The physical Id of the component owning the local storage file.
  *        IsOwner = FALSE when this physical Id is not the one of the current component, meaning that this component is a duplicate of an original one,
  *        which locally stored SD(s) has(have) been duplicated and might still point on the same stream.
  *
  *    LSDescription.GetValue(LSKey().IsOwner, IsLSOwner) + IsLSOwner.GetBoolean()
  *        TRUE if this component owns the Locally stored file, meaning that this component/SD is the one that created the locally stored file and not a duplicated one
  *         referencing this Locally stored file.
  *        FALSE otherwise, meaning that this component is a duplicate of an original one, which Locally stored SD(s) has(have) been duplicated.
  * @return
  *          For diagnostic cases below, a valid file description block is provided:
  *        S_OK : read operation succeeded. SD is in Local Storage mode. All information available.
  *        S_FALSE : read operation succeeded. SD is in Local Storage mode. V0 File Description version (no owner info available): oLSOwnerId=NULL and oIsLSOwner=FALSE, only oLSpath.
  *        CATOmb_S_ReconcileLocalStorage:
  *               In local storage Managed mode, local file locking information on local disk is not up to date and should be refreshed using Utility>Local Storage Explorer (Check/Clean mode):
  *               If current component is not the owner of the Local file the SD iKey points to, the local file might be deleted when it owning
  *               component will unset Local storage mode AND current or any other component has no lock on it. If local file is deleted, current component will no more be able to get its local stream.
  *               This situation occurs when this component is a duplicate on web side from another one previously set/saved to LocalResult mode (the local file owner).
  *               The reconciliation consists in adding a session lock for this component in the local lock table, to avoid losing the local file when still referenced by iKey SD.
  *        CATOmb_E_LocalFileNotFound: SD saved as Local Storage and references a well formatted local file path, but this file has not been found, so probably deleted.
  *
  *          For diagnostic cases below, empty or not pertinent file description block is provided
  *        CATOmb_E_KEY_INVALID: SD not found or not typed as (Format:authoring Role:Extended)
  *        E_INVALIDARG :The SD is not declared as LocalStorage.
  *        FAILED : -LocalStorage description informations cannot be read.
  *                 -SD saved as Local Storage but references a badly formatted local path, or OwnerId.
  */
  HRESULT GetLocalStorageDescription(const CATOmbLoadableDataUniqueKey& iKey, CATOmxKeyValueBlock& oLSDescription);

  /** @deprecated
  * Use ProjectFile with new applicative behavior signature instead
  **/
  HRESULT MakeProjection(const CATOmbLoadableDataUniqueKey& iKey, CATUnicodeString& oFilePath, const CATUnicodeString& iProposedFileName, CATIOmbNonCATIASDPersistencyMngt* iNonCATIASDPersistencyMngt = NULL);

  /** @deprecated
  * Use ProjectFile with new applicative behavior signature instead
  **/
  inline HRESULT MakeProjection(const CATOmbLoadableDataUniqueKey& iKey, CATUnicodeString& oFilePath, CATIOmbNonCATIASDPersistencyMngt* iNonCATIASDPersistencyMngt = NULL) { CATUnicodeString Blank; return MakeProjection(iKey, oFilePath, Blank, iNonCATIASDPersistencyMngt); }

  /**
  * Reads identified Stream Descriptor projection status
  * @param iKey [in]
  *        the key identifying the Stream Descriptor to read
  * oFilePath [out]
  *        the path of projection file, if projected
  * @return
  *        S_OK   : the SD has been projected to oFilePath, not empty
  *        S_FALSE: the SD has not been projected, iFilePath is empty
  *        E_FAIL : an internal error occured
  */
  HRESULT HasBeenProjected(const CATOmbLoadableDataUniqueKey& iKey, CATUnicodeString& oFilePath);

  /**
  * Removes the current projected file, allowing so a next projection.
  * @param iKey [in]
  *        the key identifying the Stream Descriptor which stream projection is to be removed
  * @param iProjectedFilePath [in]: the complete path of the projected file path.
  * @return
  *        S_OK   : removal succesfull
  *        S_FALSE: iProjectedFilePath doesn't match the projected file of this document
  *        E_FAIL : iProjectedFilePath doesn't exist or an internal error occured
  */
  HRESULT RemoveProjectedFile(const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iProjectedFilePath);

  /**
  * Exports the stream handled by identified Stream Descriptor to a user file path (CheckOut)
  * Exported file life cycle is not managed by the system, but by the caller
  * Export policy is described by @href CATIOmbNonCATIAStreamDescriptor#ExportFile
  *
  * @param iKey [in]
  *        the key identifying the Stream Descriptor which stream is to be exported
  * @param iFilePath [in]
  *        the absolute file path of the projection
  * @param iForceOverwrite [in]
  *        TRUE: allows to overwrite an existing iFilePath content.
  *         FALSE: returns S_FALSE if already existing iFilePath.
  * @return
  *        S_OK   : Export successfull
  *        E_FAIL : Export failed:
  *                 input file extension doesn't match the SD persistency type
  *                 an internal error occured
  */
  HRESULT ExportFile(const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iFilePath, CATBoolean iForceOverwrite = FALSE);

  /** @deprecated
  * Use ImportFile with new applicative behavior signature instead
  **/
  HRESULT ImportFile(const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iFilePath, CATOmbLoadableDataUniqueKey& oNewKey, CATIOmbNonCATIASDPersistencyMngt* iNonCATIASDPersistencyMngt = NULL);

  /** @deprecated
  * Use SetWorkingFileAsProjection with new applicative behavior signature instead
  **/
  HRESULT SetProjectionPath(const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iFilePath, CATOmbLoadableDataUniqueKey& oNewKey, CATIOmbNonCATIASDPersistencyMngt* iNonCATIASDPersistencyMngt = NULL);

  /**
  * Checks and propagate stream modification state on identified Stream Descriptor
  * If the NonCatiaFile has been projected and updated, use this method to notice the infrastructure. It allows not to reimport the file projected.
  * @param iKey [in]
  *        the key identifying the Stream Descriptor to be eventually set as modified
  * @param iForceDirty
  *         If set to true the stream descriptor will be set as dirty (and saved at next save operation) even if the stream has not been modified.
  * @return
  *        S_OK      : if projection is dirty
  *        S_FALSE   : projection is not dirty
  *        E_FAIL    : internal error on dirty status evaluation
  **/
  HRESULT ForceDirtyCheck(const CATOmbLoadableDataUniqueKey& iKey, CATBoolean iForceDirty = FALSE);

  // ===============> New set of APIS replacing old Projection/Import/SetProjectionPath <===============

  /**
  * Projects the stream handled by identified Stream Descriptor into a system file path
  * Projection policy is described by @href CATIOmbNonCATIAStreamDescriptor#MakeProjection
  *
  * @param iKey [in]
  *        the key identifying the Stream Descriptor which stream is to be projected
  * @param iNonCATIADocBehavior [in]
  *        pointer on CATIOmbNonCATIADocumentApplicativeBehavior user exit behaviors
  * @param iProposedFileName [in]
  *        the user input file name of the projection
  *        ex: toto.xls and not E:\docs\toto.xls
  * @param oFilePath [out]
  *        The absolute file path locating the projection
  * @return
  *        S_OK   : projection done
  *        S_FALSE: the Non CATIA document is already being projected or no replace requested
  *        E_FAIL : projection failed:
  *                 - the Non CATIA document is already being projected, but with a different file name
  *                 - invalid proposed file name: bad system file naming conventions or input file extension doesn't match the SD persistency type
  *                 - internal error
  */
  HRESULT ProjectFile(const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iProposedFileName, CATIOmbNonCATIADocumentApplicativeBehavior* iNonCATIADocBehavior, CATUnicodeString& oFilePath);

  /**
  * Projects the stream handled by this Stream Descriptor into a system file path
  * Same as above without iProposedFileName.
  * Projection policy is described by @href CATIOmbNonCATIAStreamDescriptor#MakeProjection
  *
  * @param iKey [in]
  *        the key identifying the Stream Descriptor which stream is to be projected
  * @param iNonCATIADocBehavior [in]
  *        pointer on CATIOmbNonCATIADocumentApplicativeBehavior user exit behaviors (can be NULL)
  * @param oFilePath [out]
  *        The absolute file path locating the projection
  * @return
  *        S_OK   : projection done
  *        S_FALSE: the Non CATIA document is already being projected or no replace requested
  *        E_FAIL : projection failed
  */
  inline HRESULT ProjectFile(const CATOmbLoadableDataUniqueKey& iKey, CATIOmbNonCATIADocumentApplicativeBehavior* iNonCATIADocBehavior, CATUnicodeString& oFilePath) { CATUnicodeString Blank; return ProjectFile(iKey, Blank, iNonCATIADocBehavior, oFilePath); }

  /**
  * Imports the input file content on the current projection path (system CheckIn)
  * The system copies the input file content into the (new) current system projection file.
  * Import policy is described by @href CATIOmbNonCATIAStreamDescriptor#ImportFile
  *
  * @param iKey [in]
  *        the key identifying the Stream Descriptor which stream is to be checked in
  * @param iFilePath [in]
  *        the absolute file path of the projection (user or system)
  *        this path must exist
  *        the extension of the file name must match the SD persistency type
  * @param iNonCATIADocBehavior [in]
  *        pointer on CATIOmbNonCATIADocumentApplicativeBehavior user exit behaviors (can be NULL)
  * @return
  *        S_OK   : Import successfull
  *        S_FALSE: No replace requested
  *        E_FAIL : Import failed
  *                 input file path doesn't exist or input file extension doesn't match the SD persistency type
  *                 an internal problem occurred
  *
  * Note: After CheckIn, the SD becomes dirty and is to be saved
  */
  HRESULT ImportFile(const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iFilePath, CATIOmbNonCATIADocumentApplicativeBehavior* iNonCATIADocBehavior, CATOmbLoadableDataUniqueKey& oNewKey);

  /**
  * Sets the input file path as the current projection of the Stream Descriptor (user CheckIn)
  * The new current user projected file will be uploaded to the session cache and FCS at next Save.
  * User projection policy is described by @href CATIOmbNonCATIAStreamDescriptor#SetWorkingFileForProjection
  *
  * @param iKey [in]
  *        the key identifying the Stream Descriptor which projection is to be set by user
  * @param iFilePath [in]
  *        the complete user file path of the projection file to be considered at next save.
  *         if input key identifies a (format:Authoring, role:Archive, PN:AFileName) SD type, the SD is re-identified as (format:Authoring, role:Archive, PN:terminal file name(iFilePath))
  * @param iNonCATIADocBehavior [in]
  *        pointer on CATIOmbNonCATIADocumentApplicativeBehavior user exit behaviors
  * @return
  *        S_OK   : checkin successfull
  *        E_FAIL : checkin failed:
  *                 input file path doesn't exist
  *                 input file extension doesn't match the SD persistency type
  *                 an internal problem occurred
  *
  * Note: After CheckIn, the SD becomes dirty and is to be saved
  **/
  HRESULT SetWorkingFileAsProjection(const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iFilePath, CATIOmbNonCATIADocumentApplicativeBehavior* iNonCATIADocBehavior);

private:

  CATOmbNonCATIAStreamsManager(const CATOmbNonCATIAStreamsManager& iCopy);
  CATOmbNonCATIAStreamsManager operator=(CATOmbNonCATIAStreamsManager& iCopy);
};
#endif
