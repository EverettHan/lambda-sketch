/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2006  
//-----------------------------------------------------------------------------
// class CATOmbSessionUndoRedoTransaction:
// 
// this class implements caretaker of mementos
//
//===================================================================
//  July 2006  Creation: RJS
//===================================================================
#ifndef CATOmeSessionUndoRedoTransaction_H_
#define CATOmeSessionUndoRedoTransaction_H_

/**
* @level Private 
* @usage U1
*/


#define OMB_OME_MIGRATION
#include "CATOme.h"
#include "CATOmeUndoRedoDefs.h"
#include "CATOmeUndoRedoMemento.h"
// SpecialAPI
#include "CATDataType.h"
// System
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATError.h"
#include "CATLISTP_Clean.h"
#include "CATLISTP_PublicInterface.h"
#include "CATLISTP_Declare.h"
// ObjectModelerCollection
#include "CATOmxSharable.h"
#include "CATOmxSR.h"

class CATBaseUnknown;
class CATBaseUnknown_var;

class CATListPtrCATBaseUnknown;
    
CATLISTP_DECLARE( CATOmeUndoRedoMemento )
typedef CATLISTP(CATOmeUndoRedoMemento) CATLISTP_CATOmeUndoRedoMemento;



#define CARETAKERSTACK_SIZE 100
#define FORWARDS_FOR_REDO TRUE
#define BACKWARDS_FOR_UNDO FALSE

class ExportedByCATOme MementosCaretaker
{
  MementosCaretaker();
  MementosCaretaker(const MementosCaretaker &);
  MementosCaretaker& operator =(const MementosCaretaker &);
  CATListPtrCATOmeUndoRedoMemento m_stack;
  int m_TransactionID;
  CATOmeUndoRedoMemento* m_errorMemento;
public:
  OmeUndoRedoContext m_flags;
  MementosCaretaker(int iTransactionID):m_stack(CARETAKERSTACK_SIZE),m_TransactionID(iTransactionID),m_errorMemento(0){};
  virtual ~MementosCaretaker(){
    FlushContents(0);
  };
  CATOmeUndoRedoMemento* returnErrorMemento(){ return m_errorMemento;}
  inline CATBoolean IsEmpty() const {return m_stack.Size()==0;}
  inline unsigned int Size(){return m_stack.Size();}
  inline HRESULT PushMemento(CATOmeUndoRedoMemento& iMemento,CATOmeMementoId& ioMementoID);
  HRESULT ConcatenateMementos(CATListPtrCATOmeUndoRedoMemento& iMementosList);
  void FlushContents(MementoOwnerKey iKey);
  CATListPtrCATOmeUndoRedoMemento& GetStack(int& oSize);
  HRESULT Play(CATBoolean iPlayMode,CATOmeSessionUndoContext& ioContext,OmeUndoRedoErrorId& ioErrorId);
  inline int GetId() const {return m_TransactionID;}

  CATBoolean ComputeDirtyTransaction(const CATOmeUndoRedoMemento* iMemento);
  inline void GetCopyOfOmbUndoRedoContext(OmeUndoRedoContext& ioCtx){ioCtx.Copy(m_flags);}

  inline void CopyFlags(OmeUndoRedoContext& iContext){m_flags.Copy(iContext);}
  inline CATBoolean SetFlag(OmeCommandTransactionType iBit){return m_flags.SetBit(iBit);}
  inline CATBoolean SetFlag(OmeCommandRequestType iBit){return m_flags.SetBit(iBit);}
  inline CATBoolean SetFlag(OmeCommandBehaviorType iBit){return m_flags.SetBit(iBit);}
  inline CATBoolean SetFlag(OmeTransactionStatus iBit){return m_flags.SetBit(iBit);}
  inline CATBoolean UnsetFlag(OmeCommandTransactionType iBit){return m_flags.UnsetBit(iBit);}
  inline CATBoolean UnsetFlag(OmeCommandRequestType iBit){return m_flags.UnsetBit(iBit);}
  inline CATBoolean UnsetFlag(OmeCommandBehaviorType iBit){return m_flags.UnsetBit(iBit);}
  inline CATBoolean UnsetFlag(OmeTransactionStatus iBit){return m_flags.UnsetBit(iBit);}
  inline CATBoolean HasFlag(OmeCommandTransactionType iBit) {return m_flags.BitValuated(iBit);}
  inline CATBoolean HasFlag(OmeCommandRequestType iBit) {return m_flags.BitValuated(iBit);}
  inline CATBoolean HasFlag(OmeCommandBehaviorType iBit) {return m_flags.BitValuated(iBit);}
  inline CATBoolean HasFlag(OmeTransactionStatus iBit) {return m_flags.BitValuated(iBit);}


  inline void SET_EMPTY_TRANSAC(){
    m_flags.UnsetBit(OMEUNDO_T_UNKDIRTY);
    m_flags.UnsetBit(OMEUNDO_T_ISDIRTY);
    m_flags.SetBit(OMEUNDO_T_NOTDIRTY);
  };
  inline void SET_DIRTY_TRANSAC(){
    m_flags.UnsetBit(OMEUNDO_T_UNKDIRTY);
    m_flags.UnsetBit(OMEUNDO_T_NOTDIRTY);
    m_flags.SetBit(OMEUNDO_T_ISDIRTY);
  };
  inline void SET_UNSET_TRANSAC(){
    m_flags.UnsetBit(OMEUNDO_T_ISDIRTY);
    m_flags.UnsetBit(OMEUNDO_T_NOTDIRTY);
    m_flags.SetBit(OMEUNDO_T_UNKDIRTY);
  };
};

class CATOmbSessionUndoRedoTransaction;

typedef CATOmxSR<CATOmbSessionUndoRedoTransaction> CATOmbSessionUndoRedoTransaction_SR;

class ExportedByCATOme CATOmbSessionUndoRedoTransaction : public CATOmxSharable
{
public:
  CATOmbSessionUndoRedoTransaction(int iTransactionID,CATOmbSessionUndoRedoTransaction* iPreviousTransaction);
  virtual ~CATOmbSessionUndoRedoTransaction();

  HRESULT RegisterMemento(CATOmeUndoRedoMemento& iMemento,CATOmeMementoId& ioMementoID);

  HRESULT UndoMementos(CATOmeSessionUndoContext& ioContext,OmeUndoRedoErrorId& ioErrorId);

  HRESULT RedoMementos(CATOmeSessionUndoContext& ioContext,OmeUndoRedoErrorId& ioErrorId);

  HRESULT FlushMementos(OmeUndoRedoErrorId& ioErrorId);

  HRESULT FlushMatchingMementos(MementoOwnerKey iKey);

  void DirtyTransaction();

  HRESULT ConcatenateTransactions(CATOmbSessionUndoRedoTransaction& iSource);
  HRESULT ConcatenateMementos(CATListPtrCATOmeUndoRedoMemento& iMementosList){return m_MementosCaretaker.ConcatenateMementos(iMementosList);}
  inline CATBoolean FullTransaction(OmeTransactionStatus iFilterBit=OMEUNDO_T_UNDEFSTATUS){return (HasFlag(OMEUNDO_T_FULLTRANSACTION) && HasFlag(OMEUNDO_T_SPECIALSTEP)==HasFlag(iFilterBit));} //m_MementosCaretaker.IsEmpty()==FALSE;}
  inline int GetId() const {return m_MementosCaretaker.GetId();}
  void Isolate();

  CATError* GetReportedError();

  inline CATBoolean SetFlag(OmeCommandTransactionType iBit){return m_MementosCaretaker.SetFlag(iBit);}
  inline CATBoolean SetFlag(OmeCommandRequestType iBit){return m_MementosCaretaker.SetFlag(iBit);}
  inline CATBoolean SetFlag(OmeCommandBehaviorType iBit){return m_MementosCaretaker.SetFlag(iBit);}
  inline CATBoolean SetFlag(OmeTransactionStatus iBit){return m_MementosCaretaker.SetFlag(iBit);}
  inline CATBoolean UnsetFlag(OmeCommandTransactionType iBit){return m_MementosCaretaker.UnsetFlag(iBit);}
  inline CATBoolean UnsetFlag(OmeCommandRequestType iBit){return m_MementosCaretaker.UnsetFlag(iBit);}
  inline CATBoolean UnsetFlag(OmeCommandBehaviorType iBit){return m_MementosCaretaker.UnsetFlag(iBit);}
  inline CATBoolean UnsetFlag(OmeTransactionStatus iBit){return m_MementosCaretaker.UnsetFlag(iBit);}
  inline CATBoolean HasFlag(OmeCommandTransactionType iBit) {return m_MementosCaretaker.HasFlag(iBit);}
  inline CATBoolean HasFlag(OmeCommandRequestType iBit) {return m_MementosCaretaker.HasFlag(iBit);}
  inline CATBoolean HasFlag(OmeCommandBehaviorType iBit) {return m_MementosCaretaker.HasFlag(iBit);}
  inline CATBoolean HasFlag(OmeTransactionStatus iBit) {return m_MementosCaretaker.HasFlag(iBit);}
  inline void CopyFlags(OmeUndoRedoContext& iContext){m_MementosCaretaker.CopyFlags(iContext);}
  inline void InitFlags(OmeUndoRedoContext& iContext){m_MementosCaretaker.m_flags.Init(iContext);}

  inline void GetCopyOfOmbUndoRedoContext(OmeUndoRedoContext& ioCtx){return m_MementosCaretaker.GetCopyOfOmbUndoRedoContext(ioCtx);}

  inline CATListPtrCATOmeUndoRedoMemento& GetStack(int& oSize){return m_MementosCaretaker.GetStack(oSize);}
  
  CATOmeUndoRedoMemento* returnErrorMemento(){ return m_MementosCaretaker.returnErrorMemento();}
private:
  friend class CATEModelUndoRedoManager;
  MementosCaretaker m_MementosCaretaker;

  CATOmbSessionUndoRedoTransaction(const CATOmbSessionUndoRedoTransaction &);
  CATOmbSessionUndoRedoTransaction& operator =(const CATOmbSessionUndoRedoTransaction &);
  inline CATOmbSessionUndoRedoTransaction* GetPreviousTransaction() const { return (CATOmbSessionUndoRedoTransaction*)m_previous_transaction.Ref();};
  inline CATOmbSessionUndoRedoTransaction* GetNextTransaction() const { return (CATOmbSessionUndoRedoTransaction*)m_next_transaction.Ref();};
  HRESULT SetNextTransaction(CATOmbSessionUndoRedoTransaction* iTransaction);
  inline void SetPreviousTransaction(CATOmbSessionUndoRedoTransaction* iTransaction){m_previous_transaction=iTransaction;}
  
  //-------------------------------------------------------
  CATOmbSessionUndoRedoTransaction_SR m_previous_transaction;
  CATOmbSessionUndoRedoTransaction_SR m_next_transaction;
};


class ExportedByCATOme CATOmeTransactionStatic
{
public :
  CATOmbSessionUndoRedoTransaction* GetTransactionForOme(OmbRecorderType iRecorderType, OmeUndoRedoMode& oUndoMode, OmeHandlingMode& oHandlingMode);
  void SetGetTransactionForOme(CATOmbSessionUndoRedoTransaction* (*iFctGetTransaction)(OmbRecorderType, OmeUndoRedoMode&, OmeHandlingMode&)){m_GetTransaction=iFctGetTransaction;}
private:
  typedef CATOmbSessionUndoRedoTransaction* (*fctGetTransaction)(OmbRecorderType, OmeUndoRedoMode&, OmeHandlingMode&);
  fctGetTransaction m_GetTransaction;
};

ExportedByCATOme CATOmeTransactionStatic& GetCATOmeTransactionStatic();

#endif
