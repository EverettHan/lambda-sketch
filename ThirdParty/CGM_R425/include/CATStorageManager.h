/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
/**
*  CATStorageManager :
*	- manages application container save and load
*	- manages storage creation, naming, opening and using
*	- is able to read file information
*
*/
//================================================================
//  Usage notes :
//
//    This object is a gate between the document as a volatile 
//    session object and the file (persistent data area)
//
//		04/98		slg/lbf
//================================================================
/**
* @level Private
* @usage U2
*/

#ifndef CATStorageManager_H
#define CATStorageManager_H

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
//
#include "CATILockBytes.h"
#include "booleanDef.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATListPV.h"
#include "CATDocumentsInSession.h"
#include "CATContainersInSession.h"
#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"
#include "CATIContainer.h"
#include "CATFile.h"
#include "CATIPointedSymbols.h"
#include "CATDocumentsInSession.h"
#include "CATLISTV_sequence_octet.h"
#include "CATListOfInt.h"
#include "CATVVSUrl.h"
#include "CATSysMacros.h"
#include "CATAssert.h"
#include "CATOmbStorageManagerEnum.h"
#include "CATOmxSR.h"
//
class CATDocument;
class CATStorageData;
class CATIStorageData_var;
class CATILinkableObject_var;
class CATSymbolicLink;
class CATIContainer_var;
class CATSysMultiBuffer;
class CATOmbStorageManager;
class CATComponentId;


class ExportedByAC0XXLNK CATStorageManager
{

public:

  /**
  * Create a storage manager from a storage name. By default LinkTable data are loaded.
  */
  static CATStorageManager * CreateStorageManager(const CATUnicodeString & FilePath, CATILockBytes * iLB = NULL, CATBoolean iUnmarshallLinkTable = TRUE);

  /**
  * Create a storage manager from a document. LinkTable data are never loaded.
  */
  static CATStorageManager * CreateStorageManager(CATDocument * Doc, CATILockBytes * iLB = NULL);

  static void RemoveAll();


  //------------------------------------------------------------
  // to recover the storage manager relative to our FILE
  //-----------------------------------------------------
  static CATStorageManager * GetStorageManager(const CATUnicodeString & FilePath, int mode = 1);
  static CATStorageManager * GetStorageManager(CATDocument * Doc);

  //--------------------------------------------------------------
  // mode of load and save: partial or not
  //--------------------------------------------------------------
  static CATLoadMode GetLoadMode();
  static void SetLoadMode(CATLoadMode loadmode);

  //--------------------------------------------------------------
  // Load and Save services
  //--------------------------------------------------------------
  // Init and End Of Save & Load Operations
  HRESULT InitLoadOperation(CATDocument * Doc);
  HRESULT EndOfLoadOperation(); // Load Additional Data

  //   mode = 0 Roll Mode. For Warmstart only. 
  //   mode > 0 Save standard. 
  HRESULT InitSaveOperation(CATDocument * Doc, int mode = 1);
  HRESULT EndOfSaveOperation(int mode = 1); // Save Additional Data

  //Give the SNB correspomding to the stream to exclude for Copy operations
  static HRESULT GetStreamToExcludeForDoc(CATDocument * Doc, SNB & snb);

  /**
  * Copies unmodified storages/streams bit to bit from an origin RootStorage to a destiantion RootStorage.
  *
  * <br><b>Role</b>:
  * This method computes for a document, the storages/streams to be directly copied bit to bit
  *
  * @param iDocToSave [in]
  *   The CATDocument those storages/streams will be copied directly from a root storage to another one.
  * @param ipSourceStorage [in]
  *   The RootStorage from which the copied storages/streams will be read.
  * @param ipDestStorage [in]
  *   The RootStorage in which the storages/streams will be copied. ipDestStorage is NULL in case of a save operation.
  *
  * @return
  *   <code>S_OK</code> copy is successfull
  *   <code>E_FAIL</code> unexpected error. Destination storage modification should be canceled.
  */
  static HRESULT OmbDirectStreamCopyOfUnmodifiedStorage(CATDocument & iDocToSave, CATStorage & ipSourceStorage, CATStorage * ipDestStorage);

  // Used through EndOfLoadOperation & EndOfSaveOperation and also
  // if save or load opeartion did not perform correctly
  HRESULT StandardEndOperation(boolean CommitBeforeClose = FALSE, boolean aProblemOccured = FALSE);


  HRESULT OpenTransaction(CATStgTransaction iStgTransaction = CATStgNoTransaction);
  HRESULT CloseTransaction();
  CATStgTransaction GetTransaction();

  //-----------------------------------------------------------------
  //	Access To Applicative Containers
  //-----------------------------------------------------------------
  // Get Storage Container Where The Container Is Saved (used in CATContainerStgExt.cpp)
  CATStorage * ProvideContainerStorage(const CATIContainer_var & ContToLoad, DWORD OpenMode);
  // Pour le load partiel, chargement de tous les containers non charges (abb oct.99)
  HRESULT LoadAllContainers(CATDocument * Doc, CATBoolean iOnlyCATFeatCont = FALSE);


  //-------------------------------------------------
  // To know the (root) hidden documents in the file
  //-------------------------------------------------
  CATListValCATUnicodeString * GetListIdUnderlyingDoc();

  //------------------------------------------------------------------
  // Creation Of Document In Case Of A Load Operation
  //------------------------------------------------------------------
  CATLISTP(CATDocument) * ProvideDocToLoad();
  CATLISTP(CATDocument) * ProvideDocToLoad(const CATUnicodeString & type);

  CATDocument * GetDocument();
  static void Detach_Document(CATDocument *); // do not use !!!

  // ---------------------------------------------------------------
  // Set Dirty Of Storage Manager: the root storage data may be out of date
  // ---------------------------------------------------------------
  void SetDirty();


  //---------------------------------------------------------------
  // To get The Root Storage Definition ( list of CATIStorageData_var )
  //-------------------------------------------------------
  CATOmxIter<CATStorageData> GetRootStorageData();
  HRESULT InitStorageData();


  //------------------------------------------------------------------
  // File Name management: internal services
  //------------------------------------------------------------------
  void SetFilePath(const CATUnicodeString & FileName);
  CATUnicodeString GetFilePath();

  //------------------------------------------------------------------
  // Get Document Storage: internal use only !!!
  //------------------------------------------------------------------
  CATStorage * GetDocumentStorage(DWORD OpenMode = STGM_READ, int mode = 1);

  //------------------------------------------------
  // internal use only !!!
  //-------------------------------------------------
  // destruction eventuelle du storage manager
  void remove();
  virtual ~CATStorageManager();

  /**
  * METHOD SetDocumentType
  * <B>Role</B> Set the document type ie "cgr", "model"
  * @param Type The type of the document
  */
  void SetDocumentType(const CATUnicodeString & Type);

  // Accesseurs for _IsCalledByOMB
  CATBoolean GetPersistIntegrityFlag();
  HRESULT SetPersistIntegrityFlag(CATBoolean flag);

  // Accesseurs for _TargetUrl
  HRESULT PlugTargetUrl(CATVVSUrl * iUrl);
  CATVVSUrl * GetTargetUrl();

  // Accesseurs for ComponentId
  void PlugComponentId(const CATComponentId & iComId);
  CATComponentId & GetComponentId();

  // Returns the doctype of a V5 doc
  HRESULT GetTypeUnderlyingDoc(CATUnicodeString & oDocType, CATBoolean iCATBackHack = FALSE);

  /**
  * Closes a storage using the CATOmbStorageManager.
  * <b>Role</b>
  * Decremetns the open counter for this storage in CATOmbStorageManager.
  * It counter reaches 0, then the storage is phisically closed, otherwise it remains opened since
  * some sub storages/streams are still using it.
  * @param
  *   storage : the storage to close
  * @param
  *   CancelModification : Cancel any modifcation that occurs in the storage. //Currently not used
  * @result
  *   <ul>
  *     <li> S_OK : Storage close with succes
  *     <li> E_FAIL : unexpected error -> Storage not registered in CATOmbStorageManager, storage is however closed
  *   </ul>
  */
  HRESULT CloseAStorage(CATStorage & storage, int CancelModification) const;

  // General Services
  static CATUnicodeString GetContainerUUIDInString(const CATIContainer_var & Cont);

protected:


  //-------------------------------------------------------------
  // 'tors
  //-----------------------
  CATStorageManager(CATOmbStorageManager & OmbStorageManager, const CATUnicodeString & Path, CATDocument * Doc, CATBoolean iUnmarshallLinkTable);

  // ----------------------------------------------------------------
  // Save Load Operations
  // ----------------------------------------------------------------
  HRESULT StandardInitOperation(CATDocument * Doc, DWORD OpenMode, int mode = 1);

  //------------------------------------------------------------------
  // Storage Management: internal use only !!!
  //------------------------------------------------------------------
  CATStorage * ProvideApplicativeStorage(const CATIContainer_var & AppliCont, DWORD OpenMode = STGM_READ, CATStorage * CompoundStg = NULL);

  //-------------------------
  // Update Doc Properties
  //-------------------------
  HRESULT UpdateDocProperties(CATDocument * Doc); // Document Properties




  //---------------------------------------------------------------
  //	internal services
  //	----------------
  //---------------------------------------------------------------
  // Save
  // Properties
  HRESULT SaveFileStorageProperty(CATStorage & Stg, int mode = 1);
  HRESULT SaveDocProperty(CATStorage & Stg);
  // Data ( Applicative Containers)
  HRESULT SaveCompoundContainer(CATStorage & Stg);
  HRESULT SaveApplicativeContainer(const CATIContainer_var & Cont, CATStorage & Storage);

  // Load
  // Properties
  HRESULT UpdateAppliContProperties();   // Container Properties

  HRESULT InternalLoadAllContainers(CATDocument * iDoc, CATBoolean iOnlyCATFeatCont = FALSE);

  CATUnicodeString CreateApplicativeStgName(const CATIContainer_var & Cont);

private:

  // inacessible
  CATStorageManager(const CATStorageManager &);

  // Applicative containers.
  HRESULT LoadApplicativeContainer(CATIContainer_var const & iContainerToLoad);

  // DATA
  // ----
  static CATLoadMode _LoadMode;


  // Path Name Used For Load Or Save operations
  CATUnicodeString  _FileName;

  // Document Data (Root File Documents)
  CATUnicodeString _TypeDoc;
  CATOmxSR<CATDocument>  _Doc;

  // File Description
  CATOmxSR<CATStorageData> _CATIAStorageDatum; // aggregates The Root Storage Data

  // ******************************************************************
  // Save/Load Operation: temporary document and storage data member
  // ******************************************************************

  // Storages (Main Storages: data)
  CATBoolean			   _StorageManagerDirty;
  // flag provisoire pour s'assurer que SaveDoc 
  // n'est appellé que par l'intermédiaire des
  // services de persistence d'OMB et not pas directement
  // par CATIPersistent::SaveAs (que pour les docs V5)
  CATBoolean         _IsCalledByOMB;
  CATBoolean         _LinkTableUnmarshalling;  // Allows or not LinkTable unmarshalling
  CATBoolean _CurrentlyLoadingGlobally;
  CATStgTransaction  _StgTransaction; // 1 pour l'open, 2 pour le save

  CATOmxSR<CATILockBytes> _ILB;

  CATVVSUrl _TargetUrl;   // the target URL for Save (use only for V5 doc)

  CATOmbStorageManager & _OmbStorageManager; //Pointer to the omb storage manager that hols a list of document opened storage. 

  void DebugTool_DispatchCB(int  iCBCase, CATDocument * pDocInError, CATUnicodeString StorageNameOfDocInError, HRESULT ErrorHR);

};

#endif
