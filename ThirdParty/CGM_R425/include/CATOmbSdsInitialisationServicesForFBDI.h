// COPYRIGHT Dassault Systemes 2005
//===================================================================
//  Oct 2005  Creation: Code generated by the CAA wizard  bes
//===================================================================
#ifndef CATOmbSdsInitialisationServicesForFBDI_H
#define CATOmbSdsInitialisationServicesForFBDI_H

/**
* @level  Protected
* @usage   U1
*/

#include "CATOmbSessionService.h"
#include "CATListOfCATUnicodeString.h"
#include "CATOmbStreamDescriptorFormat.h"

class CATBaseUnknown;
class CATUnicodeString;
class CATVVSUrl;
class CATDocument;
class CATComponentId;
class CATOmbLoadableDataUniqueKey;
class CATOmbSessionContext;
class CATComponentId;

// INTERNAL USE
// The supported transtyping operations when updating a V6 SD (SD1), resulting from a previous migration, with current V5 migration SD (SD2)
//   V5 stream initially attached to SD2 is attached to SD1 and detached from SD2, excepted for KeepNativeProxy migration
//
// BasicMigration                       SD1/2 LateType and SD1/2 Role unchanged
// PromoteV5NativeToV6                  SD1 CATIAV5INV6 role promoted to V6 role
// ChangeLateType                       SD1 LateType changed to SD2 one
// ChangeLateTypeAndDemoteV6ToV5Native  SD1 LateType changed to SD2 one + SD1 V6 role demoted to CATIAV5INV6
// KeepV5Native                         SD1 V6 deleted + SD2 V5native kept
// MigrateV5Archive                     SD CATV5Archive LateType changed to rel V5 LateType and role changed from Authoring to CATIAV5

typedef unsigned char ombSDMigration;
#define BasicMigration                      0x00
#define PromoteV5NativeToV6                 0x01
#define ChangeLateType                      0x02
#define ChangeLateTypeAndDemoteV6ToV5Native 0x04
#define KeepV5Native                        0x08
#define MigrateV5Archive                    0x10

/**
* Class providing services for Selective Loading on Representation Reference objects.
*/
class ExportedByCATOmbSelectiveLoading CATOmbSdsInitialisationServicesForFBDI : public CATOmbSessionService
{
public:

  /**
  * Constructor
  */
  inline CATOmbSdsInitialisationServicesForFBDI() : CATOmbSessionService(NULL) { _Migration = BasicMigration; }

  //stupid useless virtuality...
  virtual ~CATOmbSdsInitialisationServicesForFBDI() { _Migration = BasicMigration; }

  /**
  * This method inits a RepRef with the necessary data for selective loading.
  *
  * <b>Role</b>
  * This method creates and inits the ObjecModelerBase data structure in a default mode.
  * Only one authoring SD of the given latetype is created. Authoring SD is created from phase1 stream (ie phase1 CATPart...)
  * This service should be used only by FBDI.
  *
  *
  * @param ioComp [inout]
  *   The RepRef for which the selective loading will be set up.
  * @param iAuthoringType [in]
  *   Late type of the authoring Stream Descriptor that will be added to the RepRef.
  * @param iContentUrl [in]
  *   It provides an access to the phase 1 stream.
  *
  * @return
  *   <code>S_OK</code>         the Selective loading data structure has been created with success
  *   <code>E_FAIL</code>       unexpected error.
  *   <code>E_INVALIDARG</code> invalid latetype (latetype must V5 phase 1 authoring )or empty url.
  */
  HRESULT InitComponentFromPhase1Stream(CATBaseUnknown& ioComp, const CATUnicodeString& iAuthoringType, const CATVVSUrl& iContentUrl);

  /**
  * This method checks if a RepRef needs to be migrated by DBDI.
  *
  * <b>Role</b>
  * This method checks if the input RepRef has a V5 SD (Authoring, CATIAV5)
  * and no V6 SD (means RepRef already migrated).
  * This service should be used only by FBDI.
  *
  * @param iRepRef [in]
  *   The RepRef to analyze.
  *
  * @return
  *   <code>S_OK</code>         The RepRef needs to be migrated.
  *   <code>S_FALSE</code>      The RepRef must not be migrated.
  *   <code>E_FAIL</code>       unexpected error.
  */
  HRESULT IsRepRefMigrable(CATBaseUnknown& iRepRef);

  /**
  * This method retrieves the StreamDescriptor document of the RepRef.
  *
  * <b>Role</b>
  * This method returns the document relative to the SD (format, role) of the RepRef.
  * This service should be used only by FBDI.
  *
  * @param iRepRef [in]
  *   The RepRef to analyze.
  * @param iFormat [in]
  *   The format of the StreamDescriptor.
  * @param iRole [in]
  *   The role of the StreamDescriptor.
  * @param oLateType [out]
  *   The LateType of the StreamDescriptor.
  *
  * @return
  *   <code>S_OK</code>         The latetype has been retrieved successfully.
  *   <code>E_FAIL</code>       unexpected error.
  */
  HRESULT GetLateTypeFromSD(CATBaseUnknown& iRepRef, const CATOmbStreamDescriptorFormat& iFormat, const CATUnicodeString& iRole, CATUnicodeString& oLateType);

  /**
  * This method retrieves the StreamDescriptor document of the RepRef.
  *
  * <b>Role</b>
  * This method returns the document relative to the SD (format, role) of the RepRef.
  * This service should be used only by FBDI.
  *
  * @param iRepRef [in]
  *   The RepRef to analyze.
  * @param iFormat [in]
  *   The format of the StreamDescriptor.
  * @param iRole [in]
  *   The role of the StreamDescriptor.
  * @param oDoc [out, IUnknown#Release]
  *   The Document object behind the SD.
  *
  * @return
  *   <code>S_OK</code>         The document has been retrieved successfully.
  *   <code>E_FAIL</code>       unexpected error.
  */
  HRESULT GetDocumentFromSD(CATBaseUnknown& iRepRef, const CATOmbStreamDescriptorFormat& iFormat, const CATUnicodeString& iRole, CATDocument*& oDoc);

  /**
  * This method completes the migration of a RepRef.
  *
  * <b>Role</b>
  * This method is called after the stream migration.
  * It moves the migrated document into the V6 SD of the input RepRef.
  * Firstly, it checks if the current mode of the input RepRef is Migration_Mode.
  * Then, a V6 SD is added to the input RepRef. The document is detached from the V5 SD and attached to the V6 SD.
  * Finally, the current mode of the RepRef is set to AuthoringFullEdit_Mode.
  * This service should be used only by FBDI.
  *
  * @param iRepRef [inout]
  *   The RepRef for which the migration will be completed.
  *
  * @return
  *   <code>S_OK</code>         The Migration has been completed with success.
  *   <code>E_FAIL</code>       unexpected error.
  */
  HRESULT CompleteMigrationAndSwitchAuthoring(CATBaseUnknown& iRepRef);

  /**
  * Switch RepRef to CATIAV5INV6 role.
  */
  HRESULT CompleteMigrationAndSwitchAuthoringToCATIAV5INV6(CATBaseUnknown& iRepRef);

  /**
  * Deprecated, see InitRepRefWithV5Document
  */
  HRESULT InitRepRefWithPhase1Document(CATBaseUnknown& ioRepRef, const CATUnicodeString& iAuthoringType, CATDocument* iDocument);

  /**
  * This method initializes a RepRef with a V5 document.
  *
  * <b>Role</b>
  * This method creates one authoring SD with the given latetype and with the given phase1 document on the RepRef.
  * RepRef will then be loaded in AuthoringFullEdit and the authoring document will be marked as dirty and would impact the RepRef's updatestamp.
  * This service should be used only by FBDI.
  *
  * @param iCID
  *   The RepRef.
  * @param iKey
  *   The key of the SD that must hold the document
  * @param iDocument
  *   A V5 document
  */
  static HRESULT InitRepRefWithV5Document(const CATComponentId& iCID, const CATOmbLoadableDataUniqueKey& iKey, CATDocument& iDocument);
  static HRESULT InitRepRefWithV5Document(CATBaseUnknown* iRepRef, const CATOmbLoadableDataUniqueKey& iKey, CATDocument& iDocument);
  /**
  * Moves the SD CATIAV5INV6 to a CATIAV5 role
  * This allows to be able to perform [DF]BDI migration and then complete migration thanks to CompleteMigrationAndSwitchAuthoring.
  * After call, the V5 document is fully loaded and the representation is in "Migration_Mode".
  *
  * Notes:
  *  - CATIAV5 SD must not exist before this call.
  *    As a consequence sequence
  *      CompleteMigrationAndSwitchAuthoringToCATIAV5INV6 -> DemoteToCATIAV5
  *    is not supported (unless a Save is performed between the two calls)
  *
  *  - CompleteMigrationAndSwitchAuthoring MUST be called before any save
  */
  static HRESULT DemoteToCATIAV5(const CATComponentId& iCID);

  /**
  * This method re-initializes an existing RepRef with a Phase1 document.
  *
  * <b>Role</b>
  * This method will associate the provided document to the Authoring SD of the RepRef. (LateType must be consistent between the document and the SD)
  * RepRef would be loaded in PLM_Mode before calling this service and the input CATDocument would be loaded globally.
  * this API fails
  * - if Document could not be loaded globally or the RepRef could not be switched in PLM_Mode
  * - if trying to reinit the RepRef with same document
  * This API would do the following sequence
  * - RepRef would be loaded in PLM_Mode before calling this service and the input CATDocument would be loaded globally.
  * - The RelationView will be flushed to avoid desynchronisation. It will not be consistent until the migration process has updated it.
  * - RepRef will then be loaded in AuthoringFullEdit and the authoring document will be marked as dirty and would impact the RepRef's updatestamp.
  * - Document Identification is modified.
  *
  * This service should be used only by FBDI.
  *
  * @param ioComp [inout]
  *   The RepRef.
  * @param iDocument [in]
  *   The document of the authoring Stream Descriptor that will be added to the RepRef.
  *
  * @return
  *   <code>S_OK</code>         the Selective loading data structure has been created with success
  *   <code>E_FAIL</code>       unexpected error.
  *   <code>E_INVALIDARG</code> invalid latetype (latetype must V5 phase 1 authoring ); invalid RepRef LoadingMode; Document is not loaded globally
  */
  HRESULT ReInitRepRefWithPhase1Document(CATBaseUnknown& ioRepRef, CATDocument& iDocument);

  /**
  * This method re-initializes an existing RepRef with a new document.
  *
  * <b>Role</b>
  * this APIs do the same as ReInitRepRefWithPhase1Document while the document used for initialisation is created inside this API
  * This service should be used only by FBDI.
  *
  * @param ioComp [inout]
  *   The RepRef.
  *
  * @return
  *   <code>S_OK</code>         the Selective loading data structure has been created with success
  *   <code>E_FAIL</code>       unexpected error.
  *   <code>E_INVALIDARG</code> invalid latetype (latetype must V5 phase 1 authoring ); invalid RepRef LoadingMode; Document is not loaded globally
  *
  */
  HRESULT ReInitRepRefWithNewDocument(CATBaseUnknown& ioRepRef);

  /**
  * Re-initializes the Authoring V6/CATIAV5INV6 stream data of the input RepRef from its CATIAV5 Stream data.
  *
  * <b>Role</b>
  * This method associates in session the document attached to its CATIAV5 StreamDescriptor to the Authoring V6/CATIAV5InV6 StreamDescriptor of the input RepRef.
  * this API FAILS when the RepRef doesn't match specific input conditions:
  *  - the RepRef is not loaded in PLM_Mode
  *  - the RepRef doesn't aggregate both (Authoring,V6 or CATIAV5INV6) AND (Authoring,CATIAV5) StreamDescriptors
  *  - LateType of these two StreamDescriptors are different
  *  - (Authoring,CATIAV5) SD's document cannot not be loaded globally
  *  - trying to reinit the RepRef with the same document
  * This API executes the following sequence:
  * - Loads globally the document attached to the (Authoring,CATIAV5) StreamDescriptor.
  * - Flushes The relational view of the RepRef to avoid desynchronisation with other components. It will not be consistent until the migration process has updated it.
  * - The RepRef is loaded in AuthoringFullEdit mode.
  * - The Authoring document is marked as dirty, impacting the RepRef's updatestamp.
  * - Document Identification is modified.
  *
  * This service should be used only by DBDI.
  *
  * @param ioRepRef [inout]
  *   The RepRef to update
  *
  * @return
  *   <code>S_OK</code>         The RepRef has been updated successfully
  *   <code>E_FAIL</code>       Unexpected error
  *   <code>E_UNEXPECTED</code> Unexpected error
  *   <code>E_INVALIDARG</code> The input repRef doesn't match input conditions (see above)
  */
  HRESULT ReInitRepRefWithPhase1DocumentForUpdate(CATBaseUnknown& ioRepRef);

  /**
  * Re-initializes the Authoring CATIAV5INV6 stream data of the input RepRef from its CATIAV5 Stream data and promotes it to a V6 Stream descriptor.
  *
  * <b>Role</b>
  * This method operates on the input RepRef to:
  * - associate the document attached to the CATIAV5 StreamDescriptor to the Authoring CATIAV5INV6 StreamDescriptor.
  * - migrate the Authoring CATIAV5INV6 StreamDescriptor to a new Authoring V6 one. The CATIAV5INV6 StreamDescriptor is then seen as deleted in session and deleted in FCS at next save
  *
  * +-------------+--------+-------------+------------+
  * |  Stream     | Format |   role	     |  LateType  |     SD1: the input Authoring SD V6               SD2 : the input Authoring SD V5
  * +-------------+--------+-------------+------------+     SD1 updated: the output SD1 after update     SD3 : the output SD3, created from SD2
  * |   SD1       |	   1	 | CATIAV5INV6 |  CATPart   |
  * +-------------+--------+-------------+------------+
  * |   SD2       |	   1   |   CATIAV5   |  CATPart   |
  * +-------------+--------+-------------+------------+
  *                    final state
  * +-------------+-------+-------------+-------------+
  * |   SD1 (DA)  |	  1	  | CATIAV5INV6 |  CATPart    |     (DA) Deletion asked: marked as deleted, no more accessible, will be deleted at next save
  * +-------------+-------+-------------+-------------+
  * |   SD2 (D)   |	  1   |   CATIAV5   |  CATPart    |     (D) : SD implicitely deleted at next Save
  * +-------------+-------+-------------+-------------+
  * |   SD3       |	  1	  |     ""      |  CATPart    |
  * +-------------+-------+-------------+-------------+
  *
  * this API FAILS when the RepRef doesn't match specific input conditions:
  *  - the RepRef is not loaded in PLM_Mode
  *  - the RepRef aggregates an (Authoring "") V6 StreamDescriptor
  *  - the RepRef doesn't aggregate both (Authoring CATIAV5INV6) AND (Authoring,CATIAV5) StreamDescriptors
  *  - LateType of these preivious two StreamDescriptors are different
  *  - (Authoring,CATIAV5) SD's document cannot not be loaded globally
  *  - trying to reinit the RepRef with the same document
  * This API executes the following sequence:
  * - Loads globally the authoring document attached to the (Authoring,CATIAV5) StreamDescriptor.
  * - Flushes The relational view of the RepRef to avoid desynchronisation with other components. It will not be consistent until the migration process has updated it.
  * - The RepRef is loaded in AuthoringFullEdit mode.
  * - The authoring document is marked as dirty, impacting the RepRef's updatestamp.
  * - Document Identification is modified.
  * - A new Authoring V6 stream descriptor is created with the authoring document attached
  * - the CATIAV5INV6 StreamDescriptor is marked as deleted and no more accessible
  *
  * This service should be used only by DBDI.
  *
  * @param ioRepRef [inout]
  *   The RepRef to update
  *
  * @return
  *   <code>S_OK</code>         The RepRef has been updated successfully
  *   <code>E_FAIL</code>       Unexpected error
  *   <code>E_UNEXPECTED</code> Unexpected error
  *   <code>E_INVALIDARG</code> The input repRef doesn't match input conditions (see above)
  */
  HRESULT ReinitForUpdateAndPromoteFromCATIAV5ToCATIAV6(CATBaseUnknown& ioRepRef);

  /**
  * Re-initializes and transtypes the Authoring V6 stream data of the input RepRef from its V5 Stream data.
  *
  * This method updates and transtypes in session the Authoring V6 StreamDescriptor of the RepRef with the document attached to its CATIAV5/CATIAV5INV6(V5Native) Authoring StreamDescriptor.
  * Transtyping the StreamDescriptor consists in attaching a stream with a different LateType and and eventually modifying its role, with following cases :
  *
  * cgr/CATPart are given as example below. This service can also deal with any other V4/V5 AuthoringVisu/Authoring late types: cgm/CATDrawing, model...etc
  *
  * SD1: the input Authoring SD V6               SD2 : the input Authoring SD V5
  * SD1 updated: the output SD1 after update     SD3 : the output SD3, created from SD2
  *
  * (D) : SD implicitely deleted at next Save   (DA) Deletion asked: marked as deleted, no more accessible, will be deleted at next save
  *
  *       	Update from Visu to Authoring  (I)                     Update from Visu to Native  (II)                    Update from Visu to Native Proxy (III)
  * +-------------+--------+---------+------------+    +-------------+--------+-------------+------------+   +----------------+--------+-------------+------------+
  * |  Stream     | Format |   role	 |  LateType  |    |  Stream     | Format |   role	    |  LateType  |   |  Stream        | Format |   role	     |  LateType  |
  * +-------------+--------+---------+------------+    +-------------+--------+-------------+------------+   +----------------+--------+-------------+------------+
  * |   SD1       |	   1	 |    ""	 |    cgr     |    |   SD1       |	  1	  |    ""       |    cgr     |   |   SD1          |	  1	   |    ""       |    cgr     |
  * +-------------+--------+---------+------------+    +-------------+--------+-------------+------------+   +----------------+--------+-------------+------------+
  * |   SD2       |	   1   | CATIAV5 |  CATPart   |    |   SD2       |	  1   |   CATIAV5   |  CATPart   |   |   SD2          |	  1    | CATIAV5INV6 |  CATPart   |
  * +-------------+--------+---------+------------+    +-------------+--------+-------------+------------+   +----------------+--------+-------------+------------+
  *                   final state                                        final state                                              final state
  * +-------------+--------+---------+------------+    +-------------+--------+-------------+------------+   +----------------+--------+-------------+------------+
  * | SD1 updated |	   1	 |    "" 	 |  CATPart   |    |   SD1 (DA)  |	  1	  |    ""       |    cgr     |   |   SD1 (DA)     |	   1   |    ""       |    cgr     |
  * +-------------+--------+---------+------------+    +-------------+--------+-------------+------------+   +----------------+--------+-------------+------------+
  * |   SD2 (D)   |	   1   | CATIAV5 |  CATPart   |    |   SD2 (D)   |	  1   |   CATIAV5   |  CATPart   |   |   SD2          |	  1    | CATIAV5INV6 |  CATPart   |
  * +-------------+--------+---------+------------+    +-------------+--------+-------------+------------+   +----------------+--------+-------------+------------+
  *                                                    |   SD3       |	  1	  | CATIAV5INV6 |  CATPart   |
  *                                                    +-------------+--------+-------------+------------+
  *
  * this API FAILS when the RepRef doesn't match specific input conditions:
  *  - the RepRef is not loaded in PLM_Mode
  *  - the RepRef doesn't aggregate both (Authoring,V6 ) AND (Authoring,CATIAV5 or CATIAV5INV6) StreamDescriptors
  *  - LateType of these two StreamDescriptors are NOT different
  *  - (Authoring,CATIAV5 or CATIAV5INV6) SD's document cannot not be loaded globally
  *  - trying to reinit the RepRef with the same document
  * This API executes the following sequence:
  * - When role is transtyped, the initial StreamDescriptor is marked as deleted (DA) and no more accessible
  *
  *   Excepted for case (III):
  * - Loads globally the document attached to the (Authoring, CATIAV5 or CATIAV5INV6) StreamDescriptor.
  * - Flushes The relational view of the RepRef to avoid desynchronisation with other components. It will not be consistent until the migration process has updated it.
  * - The RepRef is loaded in AuthoringFullEdit mode.
  * - The Authoring document is marked as dirty, impacting the RepRef's updatestamp.
  * - Document Identification is modified.
  * - A new Authoring V6/CATIAV5INV6 stream descriptor is created if needed, with the authoring document attached
  *
  * This service should be used only by DBDI.
  *
  * @param ioRepRef [inout]
  *   The RepRef to update
  * @param iDemoteToNative [in]
  *    FALSE : update input Authoring SD V6 (SD1) with V5 document content (SD2) : case (I)
  *    TRUE  : update input Authoring SD V6 (SD1) with V5 document content (SD2) AND demote SD1 to CATIAV5INV6 role: cases (II) (III)
  *
  * @return
  *   <code>S_OK</code>         The RepRef has been updated successfully
  *   <code>E_FAIL</code>       Unexpected error
  *   <code>E_UNEXPECTED</code> Unexpected error
  *   <code>E_INVALIDARG</code> The input repRef doesn't match input conditions (see above)
  */
  HRESULT ReInitRepRefWithPhase1DocumentForUpdateAndTransform(CATBaseUnknown& ioRepRef, CATBoolean iDemoteToNative = FALSE);

  /**
  * Initializes a RepRef with V5 or V6 data streams
  *
  * <b>Role</b>
  * This method initializes the Authoring Stream Description structure of the input repRef from V5 stream data , either in V5Native or V6 configuration
  * For Authoring streams with empty role (non CATIAV5INV6) this method is authorized to be reused for an update. The key and AuthoringType has to be unchanged.
  *
  * The RepRef must not be switched to any loading mode before operation, and have to be in PLM_Mode.
  * The RepRef is globally switched in AuthoringFullEdit_Mode at the end of the operation, meaning that V5 stream data are fully loaded in session.
  * Only one authoring SD of the given late type can be created.
  * This service should be used only by FBDI or UPS.
  * Does exactly the same as InitComponentFromPhase1Stream when called with CATOmbLoadableDataUniqueKey::Authoring() input key
  *
  * @param ioComp [inout]
  *   The RepRef for which Authoring Stream Description structure will be set up.
  * @param iKey [in]
  *   The key for the Stream Descriptor that must hold the document
  *   Authorized types are:  CATOmbLoadableDataUniqueKey::Authoring() or CATOmbLoadableDataUniqueKey::AuthoringCATIAV5INV6()
  * @param iAuthoringType [in]
  *   V5 Late t ype of the authoring Stream Descriptor that will be added to the RepRef
  *   Authorized types are:  CATPart, CATShape, CATDrawing, CATMaterial, fea, CATSwl

  * @param iContentUrl [in]
  *   An access to the V5 stream data to be attached to the RepRef
  *
  * @return
  *   <code>S_OK</code>         the Stream Description structure has been created with success
  *   <code>E_FAIL</code>       unexpected error.
  *   <code>E_INVALIDARG</code> invalid late type or empty url.
  */
  HRESULT InitComponentFromUrl(CATBaseUnknown& ioComp, const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iAuthoringType, const CATVVSUrl& iContentUrl);

  /**
  * In context of 3dxmldownward, we change authoring document of  a RepRef with another document
  *
  * <b>Role</b>
  * This method changes the Authoring document associated to a Representation. The new document to attached must not be linked to a Representation
  * After the operation the RepRef remains in AuthoringFullEdit_Mode and the former authoring document is removed from memory
  * We assume the Authoring SD od RepRef is V6/3DXP and not V5Native.*
  * the late type of the replacing document must be the same as the latetype of the current Authoring Document
  * if the replacing document is attached a RepresentationReference then it is detached from this RepresentationReference
  *
  * @param iRepRef [inout]
  *   The RepRef for which Authoring Stream Description structure will be changed.
  * @param iDocument [in]
  *   The document replacing the current authoring document.
  *
  * @return
  *   <code>S_OK</code>         the Stream Description structure has been created with success
  *   <code>E_FAIL</code>       unexpected error.
  *   <code>E_INVALIDARG</code> invalid late type or invalid document.
  */
  HRESULT ChangeRepRefAuthoringFor3dxmlDownward(CATBaseUnknown* iRepRef, CATDocument& iDocument);
  HRESULT InitComponentFromV5Url(CATBaseUnknown* iRepRef, CATDocument& iDocument);

protected:

  HRESULT UpdateCATIAV5FromV5Document(CATBaseUnknown& ioRepRef, CATDocument& iDocument);

private:

  ombSDMigration _Migration;

  HRESULT _InitComponentFromUrl(CATBaseUnknown* iRepRef, CATDocument& iDocument, const CATOmbLoadableDataUniqueKey& iKey, CATBoolean iDownwardCase);
  HRESULT DemoteAndAttachV5DocumentToNew(CATBaseUnknown& ioRepRef, const CATUnicodeString& iLateType, CATDocument& iDocument, int iWS, ombSDMigration iMigration);
  static HRESULT PrepareV5DocumentToV6Migration(const CATComponentId& iCID, const CATOmbLoadableDataUniqueKey& iKey, ombSDMigration iMigration, int& oWsLastStream, CATDocument*& oV5Document);
};
#endif
