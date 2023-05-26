#ifndef CATOmeUndoRedoDefs_H_
#define CATOmeUndoRedoDefs_H_

#include "CATOme.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATOmxSharable.h"

#define FULL_UNDO_OPEN
#define FULLCOMPONENTRECORDERMIGRATION

#define UNDO_OPEN_FIX

/**
* OmeMementoFlags is a bitfield to toggle Memento behaviors
*/
#define OmeMementoFactoryFlag unsigned char
#define OME_WARMSTART                         0x00 
#define OME_UNDOREDO                          0x01 
#define OME_VOLATILE                          0x02
#define OME_DIRTY                             0x04 


#define OmeMementoFlag OmeMementoFactoryFlag
#define OME_MemWARMSTART                         OME_WARMSTART 
#define OME_MemUNDOREDO                          OME_UNDOREDO 
#define OME_MemVOLATILE                          OME_VOLATILE
#define OME_MemDIRTY                             OME_DIRTY 
#define OME_MemUNDO_DONE                         0x08 
#define OME_MemSPECIAL                           0x10 

#define MementoOwnerKey unsigned int

#define CATOsmUndoRedoMementoFlags unsigned char

#define OsmM_WARMSTART                      0x00 //Memento is created to be involved in WarmStart operations (to be removed once flag is removed from Specs)
#define OsmM_UNDEF                          0x00 //
#define OsmM_UNDOREDO                       0x01 //Memento is created to be involved in UndoRedo operations
#define OsmM_VOLATILE                       0x02
#define OsmM_DIRTY                          0x04 //Memento is created to be involved in computation of DirtyStatus
#define OsmM_UNDONE                         0x08 //Memento has been replayed backwards
enum OmeHandlingMode{OME_HM_DENYNONE=0,OME_HM_DENYMODEL,OME_HM_DENYUNDOREDO,OME_HM_DENYALL};

/**
* CATIUndoVisitor dedicated flag
*/
#define OsmM_VISITABLE       0x10 //Memento is created may be visited by a CATIUndoVisitor
#define OsmM_ModifiedStatus  0x20 //Memento is created to be involved in intrisic modification of an object
#define OsmM_CreatedStatus   0x40 //Memento is created to be involved in creation of an object
#define OsmM_DeletedStatus   0x80 //Memento is created to be involved in deletion an object

/**
* OmbSpecialStepType type (usefull for error management strategy
* OMB_ST_UNDEF                  : 
* OMB_ST_SAVETRANSACTION        : Save transaction.
* OMB_ST_OPENTRANSACTION        : Open transaction
* OMB_ST_OPENMANAGERTRANSACTION : Open transaction triggered via CATOpenUndoManager (for project Undo vs Open)
* OMB_ST_SWITCHTRANSACTION      : Switch a document to edit mode
* OMB_ST_LOCALSAVE              : LocalSave transaction
* OMB_ST_RESTOREEDITORS         : Restore editors for LocalSave
* OMB_ST_DIRTYSTORAGE           : Storage transaction
* OMB_ST_REFRESHTRANSACTION     : Refresh transaction
* OMB_ST_NONUNDOABLEMODELER     : be nice, don't ask...
* OMB_ST_MAX                    : keyword for algorithm convenience
*/
enum OmbSpecialStepType{OMB_ST_UNDEF=0,OMB_ST_SAVETRANSACTION,
OMB_ST_OPENTRANSACTION,OMB_ST_OPENMANAGERTRANSACTION,
OMB_ST_LOCALSAVE,OMB_ST_RESTOREEDITORS,
OMB_ST_DIRTYSTORAGE,OMB_ST_REFRESHTRANSACTION,
OMB_ST_NONUNDOABLEMODELER,OMB_ST_SWITCHTRANSACTION,
OMB_ST_MAX};
/*
* OmbRecorderType type
* OMB_R_UNKNOWN     : Recorder cannot be initialized from input.
* OMB_R_CONTAINER   : Recorder for container.
* OMB_R_COMPONENT   : Recorder for Component
* OMB_R_OBSERVER    : Recorder for Observer
* OMB_R_SPECIALTOS  : Recorder for TOS
* OMB_R_ALL         : keyword for algorithm convenience
*/
enum OmbRecorderType{OMB_R_UNKNOWN=0,OMB_R_CONTAINER,OMB_R_COMPONENT,OMB_R_OBSERVER,OMB_R_SPECIALTOS,OMB_R_ALL};
/**
* OmeUndoRedoErrorId to define a static array of UndoRedo error with internal ID and NLS message
* OMEUNDO_NOERROR               : no error
* OMEUNDO_UNDEFINED             : unclassified error
* OMEUNDO_UNDOMEMENTO_ERROR     : error occured during Undo operation of Memento
* OMEUNDO_REDOMEMENTO_ERROR     : error occured during Redo operation of Memento
* OMEUNDO_RECORD_ERROR          : record error
* OMEUNDO_OBSERVER_UPDATE_ERROR : observer error
*/
enum OmeUndoRedoErrorId {
  OMEUNDO_NOERROR,OMEUNDO_UNDEFINED,
  OMEUNDO_UNDO_MEMENTO_ERROR,OMEUNDO_REDO_MEMENTO_ERROR,
  OMEUNDO_RECORD_ERROR,OMEUNDO_OBSERVER_UPDATE_ERROR,
  OMEUNDO_IRREVERSIBLE_OPERATION,OMEUNDO_REVERSIBLE_ERROR,
  OMEUNDO_EDITABILITY_ERROR,OMEUNDO_IRREVERSIBLE_EDITABILITY_ERROR
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
enum OmeCommandTransactionType{
  OMEUNDO_C_UNDEFCOMMAND=0,
  OMEUNDO_C_TRANSACTIONZERO,
  OMEUNDO_C_ROOTCOMMAND, 
  OMEUNDO_C_STACKEDCOMMAND,    
  OMEUNDO_C_SUBCOMMAND,       
  OMEUNDO_C_ReservedSlot29,   
  OMEUNDO_C_ReservedSlot30,   
  OMEUNDO_C_ReservedSlot31,   
  OMEUNDO_C_ReservedSlot32    
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
enum OmeCommandRequestType{
  OMEUNDO_R_UNDEFREQUEST=0,
  OMEUNDO_R_BEFOREACTIVATION, 
  OMEUNDO_R_AFTERACTIVATION, 
  OMEUNDO_R_LOCALSTEP,
  OMEUNDO_R_RESUMEEDITOR,
  OMEUNDO_R_END,
  OMEUNDO_R_STARTGLOBALSTEP,
  OMEUNDO_R_ENDGLOBALSTEP,
  OMEUNDO_R_ReservedSlot24
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
enum OmeCommandBehaviorType{
  OMEUNDEFBEHAVIOR=0,
  OMEUNDO_B_NOUNDO,         
  OMEUNDO_B_FLUSHCHECK,     
  OMEUNDO_B_CANCELCHECK,    
  OMEUNDO_B_DIRTYCHECK,     
  OMEUNDO_B_NODIRTYCHECK,   
  OMEUNDO_B_ReservedSlot14, 
  OMEUNDO_B_ReservedSlot15, 
};

/**
* Transaction internal flags
*/
enum OmeTransactionStatus{
  OMEUNDO_T_UNDEFSTATUS=0,
  OMEUNDO_T_SPECIALSTEP,  // Transaction is handling a SpecialStep      
  OMEUNDO_T_UNDONE,       //Undo operation has been performed on this Transaction
  OMEUNDO_T_CONCATENATED, //Concatenate operation has been performed on this Transaction
  OMEUNDO_T_DELETED,      //Delete operation has been performed on this Transaction
  OMEUNDO_T_ISDIRTY,      //When Transaction handles at least one memento of dirtyfying  modification
  OMEUNDO_T_UNKDIRTY,     //When Dirty Status of transaction is unknown
  OMEUNDO_T_NOTDIRTY,     //When Transaction handles only non-dirtyfying modification
  OMEUNDO_T_FULLTRANSACTION,// When Transaction handles at least one memento of modification (dirtyfying or not)
  OMEUNDO_T_CLOSEDTRANSACTION // When Transaction is closed
};

enum OmeUndoRedoMode{
  OME_UNR_UNDEF=0,
  OME_UNR_INIT,
  OME_UNR_RECORD,
  OME_UNR_PLAY,  
  OME_UNR_LOCKED,
  OME_UNR_DISABLED,
  OME_UNR_DISABLED_BYINHIBITORS,
  OME_UNR_HANDLINGSTEPS,
  OME_UNR_CONCATENATE,
  OME_UNR_DELETE,
  OME_UNR_PURGE,
  OME_UNR_SELECTIVEPURGE,
  OME_UNR_END,
  OME_UNR_RESET
};

struct ExportedByCATOme CATOmeMementoId{
  /**
  * Transaction number of registration
  */
  int m_transaction_number;
  /**
  * record number of registration
  */
  int m_record_number;
  CATOmeMementoId():m_transaction_number(-1),m_record_number(0){};
};

class ExportedByCATOme OmeUndoRedoContext {
public:
  OmeUndoRedoContext();
  ~OmeUndoRedoContext();
  /**
  * SetBit(CommandTransactionType iBit)
  */
  CATBoolean SetBit(OmeCommandTransactionType iBit);
  /**
  * SetBit(CommandRequestType iBit)
  */
  CATBoolean SetBit(OmeCommandRequestType iBit);
  /**
  * SetBit(CommandBehaviorType iBit)
  */
  CATBoolean SetBit(OmeCommandBehaviorType iBit);
  /**
  * SetBit(TransactionStatus iBit)
  */
  CATBoolean SetBit(OmeTransactionStatus iBit);
  /**
  * UnsetBit(CommandTransactionType iBit)
  */
  CATBoolean UnsetBit(OmeCommandTransactionType iBit);
  /**
  * UnsetBit(CommandRequestType iBit)
  */
  CATBoolean UnsetBit(OmeCommandRequestType iBit);
  /**
  * UnsetBit(CommandBehaviorType iBit)
  */
  CATBoolean UnsetBit(OmeCommandBehaviorType iBit);
  /**
  * UnsetBit(TransactionStatus iBit)
  */
  CATBoolean UnsetBit(OmeTransactionStatus iBit);
  /**
  * BitValuated(CommandTransactionType iBit)
  */
  CATBoolean BitValuated(OmeCommandTransactionType iBit) const;
  /**
  * BitValuated(CommandRequestType iBit)
  */
  CATBoolean BitValuated(OmeCommandRequestType iBit) const;
  /**
  * BitValuated(CommandBehaviorType iBit)
  */
  CATBoolean BitValuated(OmeCommandBehaviorType iBit) const;
  /**
  * BitValuated(TransactionStatus iBit)
  */
  CATBoolean BitValuated(OmeTransactionStatus iBit) const;

  
  inline void Copy(OmeUndoRedoContext& iFrom){m_mask=iFrom.m_mask;}
  inline void SetUIInfos(CATUnicodeString iCmdName){m_CommandName=iCmdName;}
  inline CATUnicodeString GetUIInfos(){return m_CommandName;}
  void Init(OmeUndoRedoContext& iFrom);
protected :
  unsigned int AsInt(){return m_mask;}
  unsigned int m_mask;
  CATUnicodeString m_CommandName;
};


class ExportedByCATOme CATOmbUndoRedoAction : public CATOmxSharable
{
public:

  enum ombUndoRedoActionType{OmbPurgeUndoRedoLog, OmbPurgeUndoLog, OmbPurgeRedoLog, OmbNewTransaction,OmbConcatenateTransaction, OmbUndoTransaction};
  enum ombUndoRedoActionStatus{NotStarted, Failed, Succeeded};

  CATOmbUndoRedoAction(ombUndoRedoActionType iActionType) : m_type(iActionType), m_status(NotStarted){};

  ombUndoRedoActionType GetType(){return m_type;}

  HRESULT SetStatus(ombUndoRedoActionStatus iStatus){m_status=iStatus; return S_OK;}

  //OmeUndoRedoContext& GetContext(){return m_context;}

private:
 ombUndoRedoActionType m_type;
 ombUndoRedoActionStatus m_status;
 //OmeUndoRedoContext m_context;
};

#endif
