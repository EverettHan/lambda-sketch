/* -*-c++-*- */
#ifndef CATOmbUndoRedoDefs_H
#define CATOmbUndoRedoDefs_H
/// COPYRIGHT DASSAULT SYSTEMES 2006
//===================================================================
//  July 2006  Creation: RJS
//===================================================================

/**
* @level Private
* @usage U3
*/

#include "CATError.h"
#include "AD0XXBAS.h"

#include "CATListOfInt.h"
#include "CATOmxSharable.h"
#include "CATOmeUndoRedoDefs.h"
/**
* <b>Role</b> CATOmbSessionUndoTransactionIdVector is list of Transaction Id  for CATOmbUndoRedoObserver operations
* NOTICE : CATOmbSessionUndoTransactionIdVector start from ZERO
*/
class ExportedByAD0XXBAS CATOmbSessionUndoTransactionIdVector
{
public:
  /**
  * Get Size of CATOmbSessionUndoTransactionIdVector
  */
  inline unsigned int Size() const {return m_list.Size();}
  /**
  * Get element located at iPos in CATOmbSessionUndoTransactionIdVector
  */
  unsigned int GetElem(unsigned int iPos) const;

  CATOmbSessionUndoTransactionIdVector(unsigned int iSize);
  virtual ~CATOmbSessionUndoTransactionIdVector();
protected:
  friend class CATEModelUndoRedoManager;
  void InsertElem(unsigned int iElem,unsigned int iPos);
  void AppendElem(unsigned int iElem);
private:
  CATListOfInt m_list;//tempo
};
/**
* MementoId
*/

struct ExportedByAD0XXBAS CATOmbMementoId : public CATOmeMementoId{
  CATOmbMementoId(){};
};

  

/**
* OmbDocumentUndoRedoContext
*/
enum OmbDocumentUndoRedoContext{OMB_NOVALUECONTEXTDOC,OMB_UNDEFINEDCONTEXTDOC,OMB_NEWCONTEXTDOC,OMB_OPENCONTEXTDOC};

enum OmbHandlingMode{OMB_HM_DENYNONE=0,OMB_HM_DENYMODEL,OMB_HM_DENYUNDOREDO,OMB_HM_DENYALL};

/**
* CATOmbUndoRedoEventID for CATOmbUndoRedoObserver
*/
#if _MSC_VER >= 1600
namespace CATOmbUndoRedoEventID_Namespace
{
#endif
enum CATOmbUndoRedoEventID{
  OMB_UO_UndefEvent=0,
  OpenTransaction,
  CloseTransaction,
  BeforeUndo,
  AfterUndo,
  BeforeRedo,
  AfterRedo,
  UndoTransaction,
  RedoTransaction,
  ConcatenateTransaction,
  DeleteTransaction,
  ContainerInitializing,//do not use 
  ContainerInitialized,
  ContainerWithoutUndo,
  ContainerRemoving,//do not use 
  ContainerRemoved,
  UndoRedoReset,
  EndOfSubscription,
  UndoRedoError,
  BeforeDelete,
  AfterDelete
};
#if _MSC_VER >= 1600
}
using namespace CATOmbUndoRedoEventID_Namespace;
#endif


/**
* OmbUndoRedoMode :
*  OMB_UNR_UNDEF=0,
*  OMB_UNR_INIT                   : Transaction ZERO
*  OMB_UNR_RECORD                 : Do action
*  OMB_UNR_PLAY,                  : Undo/Redo actions
*  OMB_UNR_LOCKED,                :  not used
*  OMB_UNR_DISABLED,              : Log is flushed and remain closed 
*  OMB_UNR_DISABLED_BYINHIBITORS, : Log is disabled for ServerTransactions
*  OMB_UNR_HANDLINGSTEPS,         : Log is idsabled for LocalSave
*  OMB_UNR_CONCATENATE,           : Concatenate
*  OMB_UNR_DELETE,                : Delete
*  OMB_UNR_PURGE,                 : Purge Log
*  OMB_UNR_SELECTIVEPURGE,        : Selective Purge Log
*  OMB_UNR_END                    : End of SessionUndo
*  OMB_UNR_RESET                  : all data are flushed
*/
enum OmbUndoRedoMode{
  OMB_UNR_UNDEF=0,
  OMB_UNR_INIT,
  OMB_UNR_RECORD,
  OMB_UNR_PLAY,  
  OMB_UNR_LOCKED,
  OMB_UNR_DISABLED_BYINHIBITORS,
  OMB_UNR_CONCATENATE,
  OMB_UNR_DELETE,
  OMB_UNR_PURGE,
  OMB_UNR_SELECTIVEPURGE,
  OMB_UNR_END,
  OMB_UNR_RESET
};

#define OMB_UNR_DISABLED_FORSERVERTRANSACTION OMB_UNR_DISABLED_BYINHIBITORS

/**
* Observers def
*/
enum OmbObserverType{
  OMB_INVALIDOBSERVER,
  OMB_MODELOBSERVER,
  OMB_VIEWOBSERVER,
  OMB_DEBUGOBSERVER
};



/**
* NewTransaction type regarding command type (exclusive toggle)
* OMBUNDO_C_UNDEFCOMMAND=0,
* OMBUNDO_C_TRANSACTIONZERO,  // Transaction ZERO of ModelUndoRedoEngine, RESERVED (before any command)
* OMBUNDO_C_ROOTCOMMAND,      // Exclusive Command        
* OMBUNDO_C_STACKEDCOMMAND,   // Shared Command
* OMBUNDO_C_SUBCOMMAND,       // Undefined Command
* OMBUNDO_C_ReservedSlot29,   // reserved
* OMBUNDO_C_ReservedSlot30,   // reserved
* OMBUNDO_C_ReservedSlot31,   // reserved
* OMBUNDO_C_ReservedSlot32    // reserved
*/
enum CommandTransactionType{
  OMBUNDO_C_UNDEFCOMMAND=0,
  OMBUNDO_C_TRANSACTIONZERO,
  OMBUNDO_C_ROOTCOMMAND, 
  OMBUNDO_C_STACKEDCOMMAND,    
  OMBUNDO_C_SUBCOMMAND,       
  OMBUNDO_C_ReservedSlot29,   
  OMBUNDO_C_ReservedSlot30,   
  OMBUNDO_C_ReservedSlot31,   
  OMBUNDO_C_ReservedSlot32    
};
/**
* NewTransaction request (exclusive toggle)
* OMBUNDO_R_UNDEFREQUEST=0,
* OMBUNDO_R_BEFOREACTIVATION, // start activate (begin or resume)
* OMBUNDO_R_AFTERACTIVATION,  // end activate (begin or resume)
* OMBUNDO_R_LOCALSTEP,        // StateUndoRequest (including AddLocalUndo)
* OMBUNDO_R_RESUMEEDITOR,     // Return From another editor
* OMBUNDO_R_END,              // Cancel, CommitCommand
* OMBUNDO_R_STARTGLOBALSTEP,  // FirstStateUndoRequest, ActiveObjectUndo
* OMBUNDO_R_ENDGLOBALSTEP,    // UndoCommand
* OMBUNDO_R_ReservedSlot24    // reserved
*/
enum CommandRequestType{
  OMBUNDO_R_UNDEFREQUEST=0,
  OMBUNDO_R_BEFOREACTIVATION, 
  OMBUNDO_R_AFTERACTIVATION, 
  OMBUNDO_R_LOCALSTEP,
  OMBUNDO_R_RESUMEEDITOR,
  OMBUNDO_R_END,
  OMBUNDO_R_STARTGLOBALSTEP,
  OMBUNDO_R_ENDGLOBALSTEP,
  OMBUNDO_R_ReservedSlot24
};

/**
* informations regarding command type
* incoming behaviors not yet implemented
*   OMBUNDO_B_UNDEFBEHAVIOR=0,
*   OMBUNDO_B_NOUNDO,         // Transaction is opened on command activation but after some transition UI_UndoRedoEngine may ask to flush UndoRedolog and stop create transaction
*   OMBUNDO_B_FLUSHCHECK,     // This transaction may be flushed at the end of command
*   OMBUNDO_B_CANCELCHECK,    // Transaction may be cancelled by during Do operation if bad things are going on and we can SAVE working session
*   OMBUNDO_B_DIRTYCHECK,     // Transaction involved in traditionnal dirty computation
*   OMBUNDO_B_NODIRTYCHECK,   // Transaction not involved in traditionnal dirty computation
*   OMBUNDO_B_ReservedSlot14, // unused
*   OMBUNDO_B_ReservedSlot15, // unused
*/
enum CommandBehaviorType{
  UNDEFBEHAVIOR=0,
  OMBUNDO_B_NOUNDO,         
  OMBUNDO_B_FLUSHCHECK,     
  OMBUNDO_B_CANCELCHECK,    
  OMBUNDO_B_DIRTYCHECK,     
  OMBUNDO_B_NODIRTYCHECK,   
  OMBUNDO_B_ReservedSlot14, 
  OMBUNDO_B_ReservedSlot15, 
};

/**
* Transaction internal flags
*/
enum TransactionStatus{
  OMBUNDO_T_UNDEFSTATUS=0,
  OMBUNDO_T_SPECIALSTEP,  // Transaction is handling a SpecialStep      
  OMBUNDO_T_UNDONE,       //Undo operation has been performed on this Transaction
  OMBUNDO_T_CONCATENATED, //Concatenate operation has been performed on this Transaction
  OMBUNDO_T_DELETED,      //Delete operation has been performed on this Transaction
  OMBUNDO_T_ISDIRTY,      //When Transaction handles at least one memento of dirtyfying  modification
  OMBUNDO_T_UNKDIRTY,     //When Dirty Status of transaction is unknown
  OMBUNDO_T_NOTDIRTY,     //When Transaction handles only non-dirtyfying modification
  OMBUNDO_T_FULLTRANSACTION,// When Transaction handles at least one memento of modification (dirtyfying or not)
  OMBUNDO_T_CLOSEDTRANSACTION // When Transaction is closed
};

/** 
* OmbUndoRedoContext is a slot with 32 toggles split into 4 categories
* - NewTransaction type regarding command type 
* - NewTransaction request : Start or End a current command
* - informations regarding command type
* - internal transaction states
* OmbUndoRedoContext is formatted like this
* | 8 toggles          | 8 toggles          | 7 toggles          | 9 toggles          |
* | 5 defined          | 3 defined          | 5 defined          | 9 defined          |
* | EXCLUSIVE TOGGLE   | EXCLUSIVE TOGGLE   | ASSOCIATIVE TOGGLE | ASSOCIATIVE TOGGLE |
*/
class ExportedByAD0XXBAS OmbUndoRedoContext : public OmeUndoRedoContext{
public:
  /**
  * SetBit(CommandTransactionType iBit)
  */
  CATBoolean SetBit(CommandTransactionType iBit);
  /**
  * SetBit(CommandRequestType iBit)
  */
  CATBoolean SetBit(CommandRequestType iBit);
  /**
  * SetBit(CommandBehaviorType iBit)
  */
  CATBoolean SetBit(CommandBehaviorType iBit);
  /**
  * SetBit(TransactionStatus iBit)
  */
  CATBoolean SetBit(TransactionStatus iBit);
  /**
  * UnsetBit(CommandTransactionType iBit)
  */
  CATBoolean UnsetBit(CommandTransactionType iBit);
  /**
  * UnsetBit(CommandRequestType iBit)
  */
  CATBoolean UnsetBit(CommandRequestType iBit);
  /**
  * UnsetBit(CommandBehaviorType iBit)
  */
  CATBoolean UnsetBit(CommandBehaviorType iBit);
  /**
  * UnsetBit(TransactionStatus iBit)
  */
  CATBoolean UnsetBit(TransactionStatus iBit);
  /**
  * BitValuated(CommandTransactionType iBit)
  */
  CATBoolean BitValuated(CommandTransactionType iBit) const;
  /**
  * BitValuated(CommandRequestType iBit)
  */
  CATBoolean BitValuated(CommandRequestType iBit) const;
  /**
  * BitValuated(CommandBehaviorType iBit)
  */
  CATBoolean BitValuated(CommandBehaviorType iBit) const;
  /**
  * BitValuated(TransactionStatus iBit)
  */
  CATBoolean BitValuated(TransactionStatus iBit) const;

  /**
  * Copy(OmbUndoRedoContext& iFrom)
  */
  inline void Copy(OmbUndoRedoContext& iFrom){m_mask=iFrom.m_mask;}
  CommandTransactionType GetCommandTransactionTypeField() const;
  OmbUndoRedoContext();
  ~OmbUndoRedoContext();
private:
  friend class CATOmbSessionUndoRedoTransaction;

  OmbUndoRedoContext(const OmbUndoRedoContext&);
  OmbUndoRedoContext& operator =(const OmbUndoRedoContext &);
};
/**
* OmbUndoRedoErrorId to define a static array of UndoRedo error with internal ID and NLS message
* OMBUNDO_NOERROR               : no error
* OMBUNDO_UNDEFINED             : unclassified error
* OMBUNDO_UNDOMEMENTO_ERROR     : error occured during Undo operation of Memento
* OMBUNDO_REDOMEMENTO_ERROR     : error occured during Redo operation of Memento
* OMBUNDO_RECORD_ERROR          : record error
* OMBUNDO_OBSERVER_UPDATE_ERROR : observer error
*/
enum OmbUndoRedoErrorId {
  OMBUNDO_NOERROR,OMBUNDO_UNDEFINED,
  OMBUNDO_UNDO_MEMENTO_ERROR,OMBUNDO_REDO_MEMENTO_ERROR,
  OMBUNDO_RECORD_ERROR,OMBUNDO_OBSERVER_UPDATE_ERROR,
  OMBUNDO_IRREVERSIBLE_OPERATION,OMBUNDO_REVERSIBLE_ERROR,
  OMBUNDO_EDITABILITY_ERROR,OMBUNDO_IRREVERSIBLE_EDITABILITY_ERROR
};


/** 
* build compatibility
*/
#define OMBUNDO_ERROR1 6
#define OMBUNDO_ERROR2 7
#define OMBUNDO_ERROR3 8
#define OMBUNDO_ERROR4 9
/**
* private do not use
*/
#define NEW_SESSIONUNDO
#define SESSIONUNDO_ERRORMANAGEMENT

#endif
