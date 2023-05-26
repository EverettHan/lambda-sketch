/** 
@level Protected 
@usage U1
*/
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2002

#ifndef CATOmbDocServices_H
#define CATOmbDocServices_H


#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATDocumentsInSession.h"
#include "CATListOfCATUnicodeString.h"
#include "CATBoolean.h"
#include "CATOmbDocDirtyStatus.h"

class CATIDocId;
class CATIProperty;
class CATIDocEnvironment;


class ExportedByAC0XXLNK CATOmbDocServices
{
public:

  /**
   * Provides the information if a givent document is under a remove transaction.
   * @param iDoc
   *   The document
   * @param oIsUndeRemove
   *   The result
   * @return
   *   S_OK if everything is OK, E_FAIL if the document is null.
   */
	static HRESULT IsDocInRemoveTransaction(CATDocument& iDoc, CATBoolean& oIsUndeRemove);

  /**
   * Computes the hash key on the address of a document (for <tt>CATHashTabCATDocument</tt>).
   * @param ipDoc
   *   The document
   * @return
   *   The hash key
   */
  static unsigned int ComputeHashKeyOnAddr(CATDocument *ipDoc);

  /**
   * Compare the addresses of two documents (for <tt>CATHashTabCATDocument</tt> and <tt>CATListPtrCATDocument</tt>).<br>
   * BEWARE: do not use with @href CATSysSimpleHashTable .
   * @param ipDoc1
   *   The first document
   * @param ipDoc2
   *   The second document
   * @return
   *   <tt>-1</tt> if <tt>ipDoc1</tt> < <tt>ipDoc2</tt>, <tt>0</tt> if <tt>ipDoc1</tt> == <tt>ipDoc2</tt>, <tt>1</tt> if <tt>ipDoc1</tt> > <tt>ipDoc2</tt>
   */
  static int CompareOnAddr(CATDocument *ipDoc1, CATDocument *ipDoc2);

  // DON'T USE THIS METHOD / see HAG or CFO
  // Use to plug an url and an Ilockbytes on a document which has been partially loaded with
  // CATIPersistent::Load method (ex: File/Open)
  // this is necessary to save it with CATDocumentServices::SavesAs in VVS context (ex: Save Management)
  // This function will be removed when the File/Open command will be migrated on VVS services
  static HRESULT PlugUrlAndILockBytesOnDocument(CATDocument& iDocument);


  // VCS 25/08/2005 new method for Phase1 (R1x)/ Phase2 (R2yy) document discrimination
  /**
  * Gets the DS CATIA releases set (R1x/R2x) the document currently belongs to.
  * @param ipDocument
  *   The document wich current release set is to be read.
  * @param oR2xReleaseSet
  *         TRUE if the document is newly created or has beeen last saved in DS PLM release versions R2.xx
  *         FALSE if the document has been last saved in DS CATIA release versions R1.xx
  * @return
  *		 S_OK : Document release set successfully read
  *	<br> E_FAIL : internal software error while reading document release set
  */
  static HRESULT CATOmbGetDocumentReleaseSet(CATDocument & iDocument, CATBoolean & oR2xReleaseSet);

private :
	static HRESULT CodeImpactChecker();


};


// Service a USAGE INTERNE pour changer les uuids d'un ensemble de documents deja ouverts en session.
// ATTENTION : ce service ne doit etre utilise que sur des documents ouverts en LOAD GLOBAL
// et non references par ailleurs 
// (un usage inapproprié  peut corrompre une session --> voir avec l'equipe d'ObjectModelerBase avant de l'utiliser)
// 
// La liste en entree/sortie ioListOfDocuments peut contenir des pointeurs nuls dans le cas ou le changement d'uuids a echoue sur le document
// correspondant en entree.
// La liste iListOfNewFileNames correspond aux nouveaux noms des documents (si elle est nulle un nommage par defaut est utilise)

ExportedByAC0XXLNK 
HRESULT  CATRegenerateUuids ( CATLISTP(CATDocument)* ioListOfDocuments, const CATLISTV(CATUnicodeString)* iListOfNewFileNames=NULL);


ExportedByAC0XXLNK 
HRESULT  CATCheckLinksToClipBoard(const CATDocument* iDocument);

// Service testant l'etat de chargement d'un document :
// renvoie S_OK si tous les containers applicatifs sont charges
// renvoie E_FAIL si au moins un container applicatif n'est pas charge

ExportedByAC0XXLNK 
HRESULT  CATIsDocumentGloballyLoaded(CATDocument* iDocument);

// Service permettant de recuperer un property set appartenant au stream des proprietes 
// d'un document (charge ou non) a partir de son docId (File seulement)
ExportedByAC0XXLNK 
HRESULT  CATGetDocumentPropertySet(CATIDocId* iDocId, const CATUnicodeString& iPropertySetName, CATIProperty** oProperty);

// Service permettant de "resseter" les liens casses d'un document afin de pouvoir
// redemander leur resolution ... 
ExportedByAC0XXLNK 
HRESULT  CATResetDocumentBrokenLinks(CATDocument* iDocument);

// Service permettant de scanner les liens en session/persistent et de mettre a jour la table des liens en consequence
// iOperationCode = 1 => apres unload
// iOperationCode = 2 => apres paste
ExportedByAC0XXLNK 
HRESULT  ProcessAfterOperation(CATDocument* iDocument,int iOperationCode);

 /**
  * Creates a new document from an existing one and saves it.
  * <br><b>Role:</b>The new document is identical to the original except for its UUIDs. 
  * The original document, iDocument, remains unchanged.  
  * <br>The new document does not exist in the session,it is just created in a file. 
  * @param iDocument
  *        The original document from which the new document will be generated and saved 
  *        with different UUIDs.
  * @param iStorageName
  *        The name under which the new document will be saved.
  * @param iSaveRecursively 
  *        Not used.  FALSE by default.
  * @param iChangeUUID
  *        The UUID of the new document could be change (TRUE) or not (FALSE).
  */
ExportedByAC0XXLNK 
HRESULT  SaveAsNew ( CATDocument& iDocument, const CATUnicodeString& iStorageName, CATBoolean iChangeUUID=TRUE);

// Dirty status
// They are now defined in CATOmbDocDirtyStatus.h. I provide the following macros to ensure ascending compatibility. Clients should migrate.
#define DocDirtyStatus      CATOmbDocDirtyStatus
#define NotModified         CATOmbNotModified
#define ModifiedBySynchro   CATOmbModifiedBySynchro
#define AttachedDocModified CATOmbAttachedDocModified
#define Modified            CATOmbModified

 /**
  * Gets a document's modified status using the CATOmbDocDirtyStatus enum : 
  *
  * CATOmbNotModified : the document has not been modified in the session
  * CATOmbModifiedBySynchro : the document has been modified by synchronization (cf CATIModifiedBySynchro interface)
  * CATOmbAttachedDocModified : one of the attached document of the input document has been modified. 
  *(by attached document, we mean, a document for which AddDocForUndo has been called on the input document)
  * CATOmbModified : The document itself has been modified 
  *
  * The correspondence of the last two status with the Dirty() method of CATIPersistent interface can be explained this way :
  * CATIPersistent::Dirty() returns TRUE if the document is modified 
  *							OR if one of the attached document of the document has been modified. (meaningfull only for Spec documents)
  * The output status of the CATGetDocumentDirtyStatus will allow to differenciate these two cases (ie Modified or AttachedDocModified)
  * 
  */
ExportedByAC0XXLNK 
HRESULT  CATGetDocumentDirtyStatus ( CATDocument& iDocument, CATOmbDocDirtyStatus& oStatus);

#endif
