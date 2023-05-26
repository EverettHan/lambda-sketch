/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
//===================================================================
//  July 2006  Creation: RJS
//===================================================================

#ifndef CATOmbSessionUndoMementoDefs_H
#define CATOmbSessionUndoMementoDefs_H

/**
* @level Protected 
* @usage U6
*/

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATOmbUndoRedoDefs.h"
#include "CATListPV.h"
#include "CATListPtrCATOmbUndoRedoMemento.h"
#include "CATSysSimpleHashTable.h"
#include "CATOmbUpdateStamp.h"

class CATIContainer;
class CATOmbUndoRedoMemento;
class CATListPtrCATBaseUnknown;
class CATOmbSessionUndoContext;
class CATDocument;
struct CATOmbMementoId;


#define MementoOwnerKey unsigned int
/**
* OmbMementoFlags is a bitfield to toggle Memento behaviors
*/
#include "CATOmeUndoRedoDefs.h"
#include "CATOmeUndoRedoMemento.h"
#define OmbMementoFactoryFlag OmeMementoFactoryFlag
#define OMB_UNDOREDO                       OME_UNDOREDO
#define OMB_WARMSTART                      OME_WARMSTART 
#define OMB_DIRTY                          OME_DIRTY 
#define OMB_VOLATILE                       OME_VOLATILE

#define OmbMementoFlag OmeMementoFlag
#define OMB_MemUNDOREDO                          OME_MemUNDOREDO 
#define OMB_MemWARMSTART                         OME_MemWARMSTART 
#define OMB_MemDIRTY                             OME_MemDIRTY 
#define OMB_MemUNDO_DONE                         OME_MemUNDO_DONE 
#define OMB_MemSPECIAL                           OME_MemSPECIAL 
#define OMB_MemVOLATILE                          OME_MemVOLATILE


/**
* CATOmbUndoRedoMementoFactory is an object gathering all needed informations to build a related Memento on UndoRedoEngine request.
* CATOmbUndoRedoMementoFactory has a bitfield OmbMementoFactoryFlag to define some behaviors :
* Available flags are :
* OMB_UNDOREDO : Memento is created to be involved in UndoRedo operations
* OMB_WARMSTART: Memento is created to be involved in WarmStart operations
* OMB_DIRTY    : Memento is created to be involved in computation of DirtyStatus
*/
#ifdef FULLCOMPONENTRECORDERMIGRATION
#define COMPONENTRECORDERDEFINED
class ExportedByAC0XXLNK CATOmbUndoRedoMementoFactory : public CATOmeUndoRedoMementoFactory
#else
class ExportedByAC0XXLNK CATOmbUndoRedoMementoFactory 
#endif
{
public:
  /**
  * Creates the memento's factory.   
  * @param iFlags
  *		flags to toggle Memento behaviors. 
  */
  CATOmbUndoRedoMementoFactory(OmbMementoFactoryFlag iFlags);
  /**
  * Build Memento to record in SessionUndo log form a factory. 
  * Memento must inherit CATOmbUndoRedoMemento.
  * @param iMementoFactory
  *		Factory of memento you want to record. 
  * @param oMtoId
  *		identifier of Memento which was created and re. 
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <dl>
  *   <code>S_OK</code>, operation succeeded.
  *   <code>E_OUTOFMEMORY</code>, Not enough memory to create Memento from factory.
  *   <code>E_NOTIMPL</code>, MementoFactory didn't define how to create memento.
  *   <code>E_UNEXPECTED</code>, unexpected error occured.
  *   <dl/>
  */
  virtual HRESULT BuildMemento(CATOmbUndoRedoMemento*& ioMemento) const;
#ifdef FULLCOMPONENTRECORDERMIGRATION
  virtual HRESULT BuildOmeMemento(CATOmeUndoRedoMemento*& ioMemento) const;
  /**
  * Get all flags of a MementoFactory. 
  * @return
  *   A <code>OmbMementoFactoryFlag</code> value.
  */
  OmeMementoFactoryFlag GetAllFlags() const;
#endif
  /**
  * Check whether a flag is activated. 
  * @return
  *   A boolean value:
  *   <br><b>Legal values</b>:
  *   <code>TRUE</code>, if it is enabled,<code>FALSE</code> otherwise.
  */
#ifndef FULLCOMPONENTRECORDERMIGRATION
  inline CATBoolean HasFlag(OmbMementoFactoryFlag iFlag) const {return (m_flags&iFlag ? TRUE : FALSE);}
  inline OmbMementoFactoryFlag GetAllFlags() const {return m_flags;}
#endif
  /**
  * Return type of a MementoFactory. 
  * @return
  *   A <code>const char</code> pointer.
  */
  virtual const char* GetType() const =0;
  virtual ~CATOmbUndoRedoMementoFactory();
private:
#ifndef FULLCOMPONENTRECORDERMIGRATION
  OmbMementoFactoryFlag m_flags;
#endif
  CATOmbUndoRedoMementoFactory();
  CATOmbUndoRedoMementoFactory (const CATOmbUndoRedoMementoFactory &);
  CATOmbUndoRedoMementoFactory& operator=(const CATOmbUndoRedoMementoFactory&);
};


/**
* PCS_2
*/
struct CATOmbUndoRedoData{
  CATDocument* m_doc;
  CATOmbUpdateStamp m_swap;
  void SetOmbUndoRedoData(CATDocument& iDoc,CATOmbUpdateStamp iStamp, CATULONG32 iSDSessionStamp);
  void ResetOmbUndoRedoData();
  // ajout pour les problèmes de corruptions de données liées au combo localsave+undoredo
  // on récupère la repref pour pouvoir logger son stamp de session 
  CATULONG32 m_repRefSessionStamp;
};
/**
* CATOmbUndoRedoMemento is created from CATOmbUndoRedoMementoFactory on UndoRedoEngine request.
* CATOmbUndoRedoMemento has a bitfield OmbMementoFactoryFlag to define some behaviors :
* Available flags are :
* OMB_MemUNDOREDO : Memento is created to be involved in UndoRedo operations
* OMB_MemWARMSTART: Memento is created to be involved in WarmStart operations
* OMB_MemDIRTY    : Memento is created to be involved in computation of DirtyStatus
* another flag OMB_UNDO_DONE is private and is computed by UndoRedoEngine.
*/
#define OSMMementoToOMBMemento
class ExportedByAC0XXLNK CATOmbUndoRedoMemento : public CATOmeUndoRedoMemento
{            
  CATDeclareClass;
public:
  /**
  * Creates the memento.   
  * @param iFlags
  *		flags to toggle Memento behaviors according to its factory. 
  */
  CATOmbUndoRedoMemento(OmbMementoFactoryFlag iFlags);
  virtual HRESULT Redo(CATOmeSessionUndoContext& ioContext,OmeUndoRedoErrorId& oErrorId);
  virtual HRESULT Undo(CATOmeSessionUndoContext& ioContext,OmeUndoRedoErrorId& oErrorId);  
  /**
  * Replay forwards  a Model's state.
  *	@param oErrorId
  *		Typed informations if an error is detected and S_OK is not returned.
  *	@param ioContext
  *		CATOmbSessionUndoContext to add a CATOmbSessionUndoContextClient or update an existing one.
  *   CATOmbSessionUndoContextClient is postprocessed at the end of UndoRedoEngine operation.
  *	@return
  *		An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <dl>
  *   <code>S_OK</code>, operation succeeded.
  *   <code>E_UNEXPECTED</code>, unexpected error occured.
  *   <dl/>
  */
  virtual HRESULT Redo(CATOmbSessionUndoContext& ioContext,OmbUndoRedoErrorId& oErrorId);
  /**
  * Replay backwards  a Model's state.
  *	@param oErrorId
  *		Typed informations if an error is detected and S_OK is not returned.
  *	@param ioContext
  *		CATOmbSessionUndoContext to add a CATOmbSessionUndoContextClient or update an existing one.
  *   CATOmbSessionUndoContextClient is postprocessed at the end of UndoRedoEngine operation.
  *	@return
  *		An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <dl>
  *   <code>S_OK</code>, operation succeeded.
  *   <code>E_UNEXPECTED</code>, unexpected error occured.
  *   <dl/>
  */
  virtual HRESULT Undo(CATOmbSessionUndoContext& ioContext,OmbUndoRedoErrorId& oErrorId);   
  /**
  * Prepare Restore phasis in WarmStart.
  *	@param oErrorId
  *		Typed informations if an error is detected and S_OK is not returned.
  *	@return
  *		An integer value:
  *   <br><b>Legal values are not yet specified</b>:
  */
  virtual int UnMarshall(OmbUndoRedoErrorId& oErrorId); //prepare Warmstart ?
  /**
  * Prepare Autosave phasis in WarmStart.
  *	@param oErrorId
  *		Typed informations if an error is detected and S_OK is not returned.
  *	@return
  *		An integer value:
  *   <br><b>Legal values are not yet specified</b>:
  */
  virtual int Marshall(OmbUndoRedoErrorId& oErrorId); //prepare Warmstart ?
  virtual ~CATOmbUndoRedoMemento();
  /**
  * Check whether a Memento is undone. 
  * @return
  *   A boolean value:
  *   <br><b>Legal values</b>:
  *   <code>TRUE</code>, if it is true,<code>FALSE</code> otherwise.
  */
  CATBoolean IsUndone() const;

  CATBoolean IsDirtyfying() const;

  int GetRecordNumber();
  int GetTransactionNumber();
  virtual ULONG __stdcall AddRef();
  virtual ULONG __stdcall Release();
private:	
  friend class CATEModelUndoRedoManager;
  friend class CATOmbSessionRecorder;
  friend class CATOmbObserverRecorder;
  friend class CATOmbComponentRecorder;
  friend class CATOmbSessionUndoRedoTransaction;
  friend class MementosCaretaker;
  void SetUndone();
  void UnsetUndone();
  MementoOwnerKey GetOwnerKey();
  void SetOwnerKey(MementoOwnerKey iOwnerKey);
  HRESULT SwapData(CATBoolean iUndo,CATOmbSessionUndoContext& ioContext,OmbUndoRedoErrorId& oErrorId);
  HRESULT SwapData(CATBoolean iUndo,CATOmeSessionUndoContext& ioContext,OmeUndoRedoErrorId& oErrorId);

  CATOmbUndoRedoData m_DocData;

  CATOmbUndoRedoMemento();
  CATOmbUndoRedoMemento( const CATOmbUndoRedoMemento &);
  CATOmbUndoRedoMemento& operator = (const CATOmbUndoRedoMemento &);
protected:
  void SetOmbFlags(OmbMementoFactoryFlag iFlags);
};

/**
* CATOmbSessionUndoContextClient is an applicative context that you can register in CATOmbSessionUndoContext during Undo or Redo operation.
* It is an alternative to CATOmbUndoRedoObserver in order to subscribe to only AfterUndo and AfterRedo operation when your memento is involved in this operation.
* You must inherit from it.
* When you register an inheriting CATOmbSessionUndoContextClient, CATOmbSessionUndoContext compute an id for it. So you can reuse it during the same Undo or Redo operation.
* At the end of Undo or Redo operation CATOmbSessionUndoContextClient is updated about the end of this operation with CATOmbUndoRedoEventID 5AfterRedo, AfterUndo.
* After updating all its clients,  CATOmbSessionUndoContext will destroyed them.
*/
class ExportedByAC0XXLNK CATOmbSessionUndoContextClient: public IUnknown{
private:
  friend class CATOmbSessionUndoContext;
  CATOmbSessionUndoContextClient( const CATOmbSessionUndoContextClient &);
  CATOmbSessionUndoContextClient& operator = (const CATOmbSessionUndoContextClient &);
  const char* m_id;
  unsigned int m_cRef;
protected:
  inline CATOmbSessionUndoContextClient():m_cRef(1){}
  virtual ~CATOmbSessionUndoContextClient(){}
public:
  /**
  * GetId
  */
  inline const char* GetId(){return m_id;}
  /**
  * QueryInterface not implemented
  */
  virtual HRESULT __stdcall QueryInterface(const IID &iIID, void **oPPV);
  /**
  * AddRef
  */
  virtual ULONG __stdcall AddRef();
  /**
  * Release
  */
  virtual ULONG __stdcall Release();

  /**
  * Update CATOmbSessionUndoContextClient. 
  *	@param iEvent
  *		Current UndoRedoEngine's operation when updating CATOmbSessionUndoContextClient.
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, if succeeded,<code>E_FAIL</code> otherwise.
  */
  virtual HRESULT UpdateContext(const CATOmbUndoRedoEventID iEvent)=0;
  /**
  * Reset CATOmbSessionUndoContextClient. 
  *	@param iEvent
  *		Current UndoRedoEngine's operation when updating CATOmbSessionUndoContextClient.
  */
  virtual void ResetContext(const CATOmbUndoRedoEventID iEvent)=0;
};


/**
* CATOmbSessionUndoContext class provides a way to inform Mementos owners about end of its Undo or Redo operation.
* It is an alternative to CATOmbUndoRedoObserver in order to listen to only AfterUndo and AfterRedo operation when your memento is involved in this operation.
* CATOmbSessionUndoContext manages CATOmbSessionUndoContextClient. 
* CATOmbSessionUndoContext register CATOmbSessionUndoContextClient and return back an CATOmbSessionUndoContextClientId for reusability during Undo or Redo operation.
* At the end of Undo or Redo operation CATOmbSessionUndoContext is destroyed.
*/

#define OMB_UNDO_ILED

class ExportedByAC0XXLNK CATOmbSessionUndoContext : CATOmeSessionUndoContext{
public:
  inline CATOmbSessionUndoContext(){}
  virtual ~CATOmbSessionUndoContext();

  /**
  * Register a CATOmbSessionUndoContextClient. 
  *	@param iApplicativeContext
  *		Client to register.
  *	@param oContextId
  *		Computed Id of registered client.
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, if succeeded,<code>E_FAIL</code> otherwise.
  */
  HRESULT RegisterApplicativeContext(CATOmbSessionUndoContextClient* iApplicativeContext,const char* iContextId);

  /**
  * return a registered CATOmbSessionUndoContextClient from its Id. 
  *	@param iContextId
  *		Id of CATOmbSessionUndoContextClient.
  * @return
  *   A CATOmbSessionUndoContextClient pointer.
  */
  CATOmbSessionUndoContextClient* GetApplicativeContext(const char* iContextId);

  /**
  * Update all CATOmbSessionUndoContextClient. 
  *	@param iEvent
  *		Current UndoRedoEngine's operation when updating CATOmbSessionUndoContextClient.
  * @return
  *   An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <code>S_OK</code>, if succeeded,<code>E_FAIL</code> otherwise.
  */
  HRESULT UpdateContext(const CATOmbUndoRedoEventID iEvent);

  /**
  * Reset all CATOmbSessionUndoContextClient. 
  *	@param iEvent
  *		Current UndoRedoEngine's operation when updating CATOmbSessionUndoContextClient.
  */
  void ResetContext(const CATOmbUndoRedoEventID iEvent);

  /**
  * OnlyForOsm
  */
  CATSysSimpleHashTable& GetEventDocuments() {return m_EventDocuments;}  ;

private:  
  CATListPV m_ChildrenContext;//temporary I will Put an HT or a Set
  friend class CATEModelUndoRedoManager;
  CATSysSimpleHashTable m_EventDocuments;//FIXME this is bullshit to keep all Undo/Redo shit based on AddDocForUndo with CATIDocEvents mechanisms
};



/**
* <b>Role</b> CATOmbUndoRedoMementoVector is list of  addreffed CATOmbUndoRedoMemento 
* NOTICE : CATOmbUndoRedoMementoVector starts from ZERO
*/
class ExportedByAC0XXLNK CATOmbUndoRedoMementoVector
{
public:
  CATOmbUndoRedoMementoVector();
  virtual ~CATOmbUndoRedoMementoVector();
  /**
  * Get Size of CATOmbUndoRedoMementoVector
  */
  inline unsigned int Size() const {return m_vect.Size();}
  /**
  * CATOmbUndoRedoMemento* GetElem(int iPos)
  */
  CATOmbUndoRedoMemento* GetElem(int iPos);
  /**
  * Append and AddRef a CATOmbUndoRedoMemento in Vector.
  * If it already exist in Vector, it is returned without AddRef
  */
  void AppendElem(CATOmbUndoRedoMemento& iToAdd);
  /**
  * Put a CATOmbUndoRedoMemento at position, AddRef it and Release existing CATOmbUndoRedoMemento
  */
  void SetElem(CATOmbUndoRedoMemento& iToAdd,unsigned int iPos);
  /**
  * Remove a CATOmbUndoRedoMemento in Vector.
  * return position of element if succeeded or -1 if Failed
  */
  int RemoveElem(CATOmbUndoRedoMemento& iToRem);
  /**
  * Locate a CATOmbUndoRedoMemento in Vector.
  * return position of element if succeeded or -1 if Failed
  */
  int LocateElem(CATOmbUndoRedoMemento& iToLocate);
  /**
  * RemoveAll
  */
  void RemoveAll();
  /**
  * Trivial
  */
  CATOmbUndoRedoMementoVector(const CATOmbUndoRedoMementoVector& iVect);
  /**
  * Trivial
  */
  CATOmbUndoRedoMementoVector & operator=(const CATOmbUndoRedoMementoVector& iVect);

private:
  CATListPtrCATOmbUndoRedoMemento m_vect;
};



#endif


