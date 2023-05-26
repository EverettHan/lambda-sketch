/* -*-c++-*- */
#ifndef CAT_SESSION_H
#define CAT_SESSION_H
// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @level Protected
 * @usage U1
  */

#include "CATDocument.h"
#include "CATListOfInt.h"
#include "CATBaseUnknown.h"
#include "booleanDef.h"
#include "AC0XXLNK.h"
#include "sequence_octet.h"
#include "CATLISTP_CATBaseUnknown.h"
class CATIDocId;
class CATOmbSessionContext;

// iterator 
template <class Type> class CATOmxIter;

/**
 * Interface used only to allow the usage of a CATSession object.
 */

class ExportedByAC0XXLNK CATSession : public CATBaseUnknown
{

  CATDeclareClass;

public:
  /** @nodoc */
  static  CATSession * Create_Session(char const * IdSession);
  /** @nodoc */
  static  void Delete_Session(char const * IdSession, int ODTRollMode = 0, int exitContext = 0);
  /** @nodoc */
  static  CATSession * GetPtrSession();

  /** @nodoc */
  virtual void Attach_DocumentToSession(CATDocument *);
  /** @nodoc */
  virtual void Delete_DocumentFromSession(CATDocument *);

  // Do Not Use
  /** @nodoc */
  virtual void Attach_Object(CATBaseUnknown *);
  // Do Not Use
  /** @nodoc */
  virtual void Detach_Object(CATBaseUnknown *);

  /** @nodoc */
  virtual char * Get_Id_Session();

  /** @nodoc */
  virtual void   Dump_Session(const char * IdSession);

  // Do Not Use
  /** @nodoc */
  virtual const CATLISTP(CATBaseUnknown) * AttachedObject();

  /** @nodoc */
  virtual const CATLISTP(CATDocument) * SessionToDocuments();

  /** @nodoc */
  virtual void ManageGarbage();


  // WARNING 
  // =======
  // The 2 followings methods are reserved for File Management
  // during Open Session. DO NOT USE THEM in other Context...
  //

    /** @nodoc */
  virtual CATDocument * RecognizedDoc() const;
  /** @nodoc */
  virtual void  RecognizedDoc(CATDocument *);

  /** @nodoc */
  virtual const CATDocumentsInSession * SessionToDocuments2();

  //-------------------------
  // Load and Save Diagnosis
  // ------------------------
    /** @nodoc */
  // SML1 : data member will be migrated as private
  boolean DataTransferAborted;
  void SetDataTransferAborted(boolean iArg);
  boolean IsDataTransferAborted();
  /** @nodoc */
  HRESULT AddBrokenLink(CATIDocId * iDocId);
  /** @nodoc */
  CATLISTV(CATUnicodeString) * LinksResolutionFailed;

  //-----------------------------
  // Links resolution management
  // ----------------------------
  unsigned int LocateBrokenLink(const CATUnicodeString & iId);
  void InsertBrokenLink(const CATUnicodeString & iId);
  void RemoveBrokenLink(const CATUnicodeString & iId);
  void RemoveAllBrokenLinks();
  unsigned int GetBrokenLinksSize();
  CATOmxIter<CATUnicodeString> GetBrokenLinksIterator();


  //----------------------------------------
  // Pointed document Services 
  //----------------------------
    /** @nodoc */
  CATLISTP(CATDocument) * GetListOfPointedDocument(CATDocument * PointingDocument);



  //
  //    virtual void   Backup_Session() ;
  //    virtual void   Save_Session  () ;
  //    virtual void   Write_Session () ;
  //    

    //-------------------------------------------------------------
    // Make a document reachable by a container or any other object
    //-------------------------------------------------------------
      /** @nodoc */
  static CATDocument * GetCurrentDoc();
  /** @nodoc */
  static void SetCurrentDoc(CATDocument *);


  //-------------------------------------------------------------
  // Session context object 
  //-------------------------------------------------------------
    /** @nodoc */
  CATOmbSessionContext * GetContext() const;

  void CreateErrorPanel();

private:

  ~CATSession();
  CATSession(char const * id);

  static void CleanGlobalObjects();
  // VCS 25/08/2006: implement new R1.x SessionUndo management
  //-------------------------------------------------------------
  // Session UndoRedo Management
  //-------------------------------------------------------------
  // Initialize Session Undo environment.
   /** @nodoc */
  HRESULT StartSessionUndoManagement();

  // Resume Session Undo environment.
   /** @nodoc */
  HRESULT EndSessionUndoManagement();

  char * IdSession; // identificateur de la Session

  enum Type_wf { V4, SDAI, OTHERS }; // type de la session supportable
  static CATSession * PtrSession; // pointeur de l'objet session
  CATLISTP(CATDocument) DocumentsInSession;// tableau des documents de la session
  CATDocumentsInSession HDocumentsInSession;// tableau des documents de la session
  CATLISTP(CATBaseUnknown) ObjectInSession;
  CATDocument * _recognizedDoc;
  //CATListOfInt TypesDocument ; // tableau des tyeps de documents  
  //CATDocument* _StarterDocument; VCS 06/01/2006: clean obsolete code: Roll mecanism removed in R1.x releases
  static CATDocument * _currentDoc;

  CATOmbSessionContext * m_pContextObject; // Associated session context object 
};

#endif      
