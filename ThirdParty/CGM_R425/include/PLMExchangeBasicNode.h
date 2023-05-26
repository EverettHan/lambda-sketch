//=======================================================================================
//** WARNING: YWE 19:02:25 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//=======================================================================================
#ifndef  PLMExchangeBasicNode_h
#define  PLMExchangeBasicNode_h
// COPYRIGHT DASSAULT SYSTEMES 2013-2016
// *****************************************************************
//
//   Identification :
//   ---------------
//
//      RESPONSIBLE : Jean-Luc MEDIONI
//      FUNCTION    : Exchange Experience 
//      USE         : ENOVIA
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Base data structure for a simple object hierarchical model.
//
// *****************************************************************
//
//   Remarks :
//   ---------
//
// ****************************************************************
//
//   Story :
//   -------
//
//   Revision 1.0  March    2007  (JLM) Initial Revision from ENORepNode
//   Revision 2.0  December 2012  (JLM) Duplication to implement Exchange Experience Model 
//   Revision 2.1  December 2013  (JLM) Enable management of multiple Exchange Experience Model by removing static variable using transaction as 
//                                      container managing one Exchange Experience Model and this class representing internal structure of data.
//   Revision 2.2  December 2014  (JLM) Extend working area to improve ordering algorithm that are today quadratic 
//
// ****************************************************************
//
// INSIDE class:
// -------------
//
//
//
// ****************************************************************
// Abstract class    : No
// Template code     : No
// Ilined   Function : No
// ****************************************************************

// --- Header that need to be referenced

#include <time.h>

// --- List of referenced classes

class PLMExchangeBasicNode   ;
class PLMExchangeTransaction ;
class PLMExchangeNode        ;
class CATHashTable           ;

// --- Header that need to be referenced

#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATLib.h"

// --- * PLMExchangeModel framework

#include "PLMExchangeModel.h"
#include "PLMExchangeStreamBuffer.h"

// --- Define application constant
// --- * Node type

/**
  * Constant value to define the node type : Unknown
  */
#define PLMExchangeNodeForbidden       0x00000000
/**
  * Constant value to define the node type for Transaction.
  */
#define PLMExchangeNodeTransaction     0x00000001
/**
  * Constant value to define the node type : Unknown
  */
#define PLMExchangeNodeUnknown         0x00000002
/**
  *  Constant value to define the node type for a Set representing root of the report or Option sets.
  */
#define PLMExchangeNodeSet             0x00000006
/**
  * Constant value to define the node type for software Engine.
  */
#define PLMExchangeNodeEngine          0x0000000E
/**
  * Constant value to define the node type for Execution.
  */
#define PLMExchangeNodeExecution       0x00000016
/**
  *  Constant value to define the node type for a specialized Set representing one Option's Group.
  */
#define PLMExchangeNodeOptionSet       0x00000026
/**
  * Constant value to define the node type for Notification (Error, warning, information messages).
  */
#define PLMExchangeNodeNotification    0x00000042
/**
  * Constant value to define the node type for Data repository.
  */
#define PLMExchangeNodeDataSource      0x00000082
/**
  * Constant value to define the node type for an Mapping Object instance.
  */
#define PLMExchangeNodeBaseObject      0x00000102
/**
  * Constant value to define the node type for an Mapping Object instance.
  */
#define PLMExchangeNodeMapping         0x00000302
/**
  * Constant value to define the node type for an Object instance.
  */
#define PLMExchangeNodeObject          0x00000502
/**
  * Constant value to define the node type for Object class.
  */
#define PLMExchangeNodeClassObject     0x00000802
/**
  * Constant value to define the node type for Metrics capture.
  */
#define PLMExchangeNodeBasicMetric     0x00001002
/**
  * Constant value to define the node type for Metrics capture.
  */
#define PLMExchangeNodeMetric          0x00003002
/**
  * Constant value to define the node type for an Attribute value.
  * NB: child class of BasicMetric to share value setting method.
  */
#define PLMExchangeNodeAttribute       0x00005002
/**
  * Constant value to define the node type for Option.
  * NB: child class of Metrics to share value setting method.
  */
#define PLMExchangeNodeOption          0x00009002
/**
  *  Constant value to define the node type for definition of a constraint as a set of authorized values.
  */
#define PLMExchangeNodeEnum            0x00010002
/**
  * Constant value to define the node type for Attribute class.
  */
#define PLMExchangeNodeClassAttribute  0x00020002

/**
  * Constant value to define the number of node type defines
  */
#define PLMExchangeNodeTypeNumber      16

// --- * Mask to test or activate a debug trace in debug mode

#define PLMExchangeDebugClean          0x00000001
#define PLMExchangeDebugSearch         0x00000002
#define PLMExchangeDebugXmlStream      0x00000004
#define PLMExchangeDebugGUI            0x00000008
#define PLMExchangeDebugInit           0x00000010
#define PLMExchangeDebugOid            0x00000020
#define PLMExchangeDebugService        0x00000040
#define PLMExchangeDebugTransaction    0x00000080
#define PLMExchangeDebugMetric         0x00000100
#define PLMExchangeDebugJustInCase     0x00000200

// --- * Mask to manage options.

#define PLMExchangeOptionsNone         0x00000000
#define PLMExchangeOptionsCompactXml   0x00000001

// --- * Attribute types
//       (Limited to only first 16 bits)

#define PLMExchangeUnknownAttribute    0x00000000
#define PLMExchangeBooleanAttribute    0x00000001
#define PLMExchangeIntegerAttribute    0x00000002
#define PLMExchangeFloatAttribute      0x00000004
#define PLMExchangeStringAttribute     0x00000008
#define PLMExchangeBinaryAttribute     0x00000010
#define PLMExchangeDateAttribute       0x00000020
#define PLMExchangeBinaryTSAttribute   0x00000040
#define PLMExchangeFileNameAttribute   0x00000080
#define PLMExchangeFolderPathAttribute 0x00000100
#define PLMExchangeObjectAttribute     0x00000200
#define PLMExchangeNlsStringAttribute  0x00000400
#define PLMExchangeNodeRefAttribute    0x00000800

// --- * Global status

#define PLMExchangeUnknownStatus       0x00000000
#define PLMExchangeSucceededStatus     0x00000001
#define PLMExchangeWarningStatus       0x00000002
#define PLMExchangeErrorStatus         0x00000004
#define PLMExchangeAbortStatus         0x00000008

// --- * Endianess representation

#define nUnknownEndianRepresentation 0
#define nBigEndianRepresentation     1
#define nLittleEndianRepresentation  2

// --- * Type of events to be logged in transaction

#define PLMExchangeUnknownEvent            0x00000000 // -- No operations.
#define PLMExchangeCreateEvent             0x00000001 // -- Object creation.
#define PLMExchangeDeleteEvent             0x00000002 // -- Object deletion.
#define PLMExchangeModifyDataEvent         0x00000004 // -- Data modification.
#define PLMExchangeChangeSetEvent          0x00000008 // -- Move object in another set.
#define PLMExchangeModifyPropertyEvent     0x00000010 // -- Node property modification.
#define PLMExchangeSelectEvent             0x00000020 // -- For future usage, selection event.

// --- * Transaction status

#define PLMExchangeTransactionNotActivated 0x00000000
#define PLMExchangeTransactionOpen         0x00000001
#define PLMExchangeTransactionClose        0x00000002
#define PLMExchangeTransactionSuspend      0x00000004

// --- * Loading modes

#define PLMExchangeLoadingMode_File           0x00000001  // -- Define XML source as a file.
#define PLMExchangeLoadingMode_Memory         0x00000002  // -- Define XML source as a memory buffer.
#define PLMExchangeLoadingMode_No_Root        0x00000004  // -- Define XML source as not having the root object (object must be attached to root).
#define PLMExchangeLoadingMode_Inhibit        0x00000008  // -- Inhibite transaction recording.
#define PLMExchangeLoadingMode_AllocateNodeId 0x00000010  // -- Force Instance Id table allocation.
#define PLMExchangeLoadingMode_InitNodeId     0x00000020  // -- Force Instance Id table initialization with current model content.
#define PLMExchangeLoadingMode_FreeNodeId     0x00000040  // -- Reset and free Instance Id table.
#define PLMExchangeLoadingMode_Full           0x00000078  // -- Set of options to load an exchange model in full mode.
#define PLMExchangeLoadingMode_PrepareDelta   0x00000038  // -- Set of options to load the first exchange model to prepare loading by delta.
#define PLMExchangeLoadingMode_ByDelta        0x00000008  // -- Set of options to load to load in delta mode (update or delete existing objects or create new ones).

// --- Class definition

/**
  * Generic class to manage nodes Structure.
  *
  * <b>Role</b>:
  * All information in this domain will be managed as nodes in a tree structure.
  */
class ExportedByPLMExchangeModel PLMExchangeBasicNode
{
   // --- Object constructor

   public:
      
    /**
      * Constructs a generic node object with no name.
      * 
      * @param inType
      *   Node type
      *   <br><b>Legal values</b>: see @href PLMExchangeBasicNode#GetType
      *
      * @param ixFather
      *   Father node that aggregates node to be created.
      *
      * @see PLMExchangeObject , PLMExchangeMetric , PLMExchangeAttribute , PLMExchangeOption ...
      */
      PLMExchangeBasicNode( PLMExchangeBasicNode * ixFather = NULL ) ;

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      virtual ~PLMExchangeBasicNode() ;

    /**
      * Substitute of delete to isolate an object.
      * 
      * <br><b>Role</b>: Equivalent to a delete operation.
      * 
      * @return
      *   Return number of object in current transaction.
      */
      virtual int Delete() ;

      // --- Copy-constructor

    /**
      * Copy constructor.
      * 
      * @param iNode
      * Object to be duplicated.
      */
      PLMExchangeBasicNode( const PLMExchangeBasicNode & iNode ) ;

      // --- Equal operator

    /**
      * Assignment operator from another object node.
      * 
      * @param iNode
      * Object used as reference for the assignment.
      */
      PLMExchangeBasicNode & operator=( const PLMExchangeBasicNode & iNode ) ;

      // -----------------------------------------
      // --- General Option management         ---
      // -----------------------------------------

    /**
      * Enables to activate some management options.
      *
      * <br><b>Role</b>: Enables to activate some management options.
      * 
      * @param inOptionMask
      *   Mask of bits that describes option selected.
      */
      static void SetOptions( int inOptionMask ) ;

    /**
      * Gets activated management options.
      *
      * <br><b>Role</b>: Gets activated management options.
      * 
      * @return
      *   Mask current of bits that describes option selected.
      */
      static int GetOptions() ;

    /**
      * Test if some options are activated.
      *
      * <br><b>Role</b>: Test if some options are activated.
      * 
      * @param inOptionMask
      *   Option to be checked.
      * 
      * @return
      *   returns <b>0</b> if selected option is not active.
      */
      static int IsOptionActivated( int inOptionMask ) ;

      // -----------------------------------------
      // --- Transaction management            ---
      // -----------------------------------------

    /**
      * Create a new modification transaction.
      *
      * <br><b>Role</b>:  Create a new modification transaction.
      * 
      * @return
      * Returns error code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Transaction successfully opened.</dd>
      * <dt>S_FALSE</dt> <dd>One transaction is already opened.</dd>
      * <dt>E_FAIL</dt>  <dd>Fail to create a new transaction.</dd>
      * </dl>
      */
      HRESULT OpenTransaction() ;

    /**
      * Close current transaction.
      *
      * <br><b>Role</b>: Close current transaction and dispatch modification to subscribers if requested.
      * 
      * @return
      * Returns error code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Transaction successfully closed.</dd>
      * <dt>S_FALSE</dt> <dd>No current transaction opened.</dd>
      * <dt>E_FAIL</dt>  <dd>Fail to close current transaction.</dd>
      * </dl>
      */
      HRESULT CloseTransaction( int ilDispatch ) ;

    /**
      * Get current transaction.
      *
      * <br><b>Role</b>: Get current transaction if defined.
      * 
      * @return
      *   Current Transaction if defined, NULL otherwise.
      */
      PLMExchangeTransaction * GetCurrentTransaction() const ;

    /**
      * Print current transaction.
      *
      * <br><b>Role</b>: Print  current transaction.
      *
      * @param icInfo
      *   String that will appear in the header of long print.
      */
      void PrintTransaction( const char * const icInfo = NULL ) const ;

    /** 
      * Save on disk with an XML stream session definition.
      *
      * <br><b>Role</b>: Save on disc with an XML stream session definition.
      * 
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>0</dt> <dd>if operation are executed without any errors.</dd>
      * <dt>1</dt> <dd>otherwise.</dd>
      * </dl>
      * 
      * @param icFilePath
      *   File path of the file.
      *
      * @param ixTransaction
      *   Transaction to be used, if different from the current one.
      *
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Transaction successfully saved.</dd>
      * <dt>E_FAIL</dt>  <dd>Transaction save failed.</dd>
      * </dl>
      */
      static int SaveTransactionInFile( const CATUnicodeString & icFilePath
                                      , PLMExchangeTransaction * ixTransaction = NULL ) ;

      // --- * Activate session recording at each transaction.

    /**
      * Activate session recording at each transaction.
      *
      * <br><b>Role</b>: Enable to capture session content with an update at each transaction close. 
      * First call to this method will force the streaming of session, after each transaction close will stream only session delta.
      * 
      * @param icSaveFolder
      *   Folder path where each session delta will be streamed (XML streaming).
      * 
      * @param icFileNamePrefix
      *   File name prefix to name the session stream at each transaction close.
      * 
      * @return
      * Returns error code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Partial save correctly activated.</dd>
      * <dt>E_FAIL</dt>  <dd>Partial save could not be activated.</dd>
      * </dl>
      */
      HRESULT SaveAtCloseTransaction( const CATUnicodeString & icSaveFolder 
                                    , const CATUnicodeString & icFileNamePrefix ) ;

      // --- Manage subscribers to Exchange Model transaction.

      //static int  GetNumberOfTransactionSubscribers() ; 
      //static void AddTransactionSubscriber(    PLMExchangeTransactionSubscriber * ixSubscriber ) ; 
      //static void RemoveTransactionSubscribers( PLMExchangeTransactionSubscriber * ixSubscriber ) ; 
      //static PLMExchangeTransactionSubscriber * GetTransactionSubscribers( int inNum ) ;

      // -----------------------------------------
      // --- Access to Node type               ---
      // -----------------------------------------

    /**
      * Gets the node type.
      *
      * <br><b>Role</b>: Gets the object type information.
      *
      * @return
      * Gets the node type.
      * <br><b>Legal values</b>: It can be set to either:
      * <dl>
      * <dt>PLMExchangeNodeUnknown</dt>         <dd>Base type for all.</dd>
      * <dt>PLMExchangeNodeSet</dt>             <dd>Set of data to manage Report root or Options folders for instance.</dd>
      * <dt>PLMExchangeNodeMapping</dt>         <dd>Mapping instance.</dd>
      * <dt>PLMExchangeNodeObject</dt>          <dd>Object instance.</dd>
      * <dt>PLMExchangeNodeAttribute</dt>       <dd>Attribute value.</dd>
      * <dt>PLMExchangeNodeDataSource</dt>      <dd>Data repository.</dd>
      * <dt>PLMExchangeNodeClassObject</dt>     <dd>Object class.</dd>
      * <dt>PLMExchangeNodeClassAttribute</dt>  <dd>Attribute class.</dd>
      * <dt>PLMExchangeNodeNotification</dt>    <dd>Notification (Error, warning, information messages).</dd>
      * <dt>PLMExchangeNodeMetric</dt>          <dd>Metrics capture.</dd>
      * <dt>PLMExchangeNodeEngine</dt>          <dd>Software Engine.</dd>
      * <dt>PLMExchangeNodeOption</dt>          <dd>Option.</dd>
      * <dt>PLMExchangeNodeTransaction</dt>     <dd>Transaction.</dd>
      * </dl>
      */
      virtual int GetType() const ;

    /**
      * Checks that a node is of a certain type.
      *
      * <br><b>Role</b>: Checks that a node is of a certain type with respect to inheritance.
      *
      * @return
      * <dl>
      * <dt>1</dt> <dd>if the <b>PLMExchangeNode</b> is to type <b>inType</b></dd>
      * <dt>O</dt> <dd>otherwise</dd>
      * </dl>
      *
      * @param inType
      * Object type.
      */
      int IsOfType( int inType ) const ;

    /**
      * Gets the node type name.
      *
      * <br><b>Role</b>: Gets the object type name information.
      *
      * @return
      * Gets the node type name.
      */
      CATUnicodeString GetTypeName() const ;

    /**
      * Gets the node type name.
      *
      * <br><b>Role</b>: Gets the object type name information.
      *
      * @return
      * Gets the node type name.
      *
      * @param inType
      * Object type.
      */
      static CATUnicodeString GetTypeName( int inType ) ;

      // -----------------------------------------
      // --- Access to Node information        ---
      // -----------------------------------------

    /**
      * Gets name.
      *
      * <br><b>Role</b>: Gets the object name.
      *
      * @return
      * Object name.
      */
      virtual const CATUnicodeString & GetName() const ;

    /**
      * Gets the instance id.
      *
      * <br><b>Role</b>: Gets the instance id.
      *
      * @return
      * Returns error code
      *
      * @param onId
      * Instance id.
      */
      virtual HRESULT GetInstanceId( int & onId ) const ;

    /**
      * Gets the Oid.
      *
      * <br><b>Role</b>: Gets the Oid.
      *
      * @return
      * Object Oid.
      */
      virtual CATString GetOid() const ;

    /**
      * Sets the Oid.
      *
      * <br><b>Role</b>: Sets Oid.
      *
      * @return
      * Returns error code
      *
      * @param icId
      * Oid.
      */
      virtual HRESULT SetOid( const CATString & icId , int lUpdateIndex = 1 ) ;

    /**
      * Resets the Oid.
      *
      * <br><b>Role</b>: Resets Oid.
      *
      * @param ilUpdateIndex [in]
      *   <b>Only for internal use:</b> Enable to inhibit hash list update.
      *
      * @return
      * Returns error code
      */
      HRESULT ResetOid( int ilUpdateIndex = 1 ) ;

      // ---------------------------------------------
      // --- Manage Attribute value type name      ---
      // ---------------------------------------------

    /** 
      * Get value type name.
      *
      * <br><b>Role</b>: Get value type name string tag for a defined attribute type even when stored in a property.
      * 
      * @param inNodeProperty [in]
      *  Property or Attribute type.
      * 
      * @param ousTypeTag [out]
      *  String associated with this attribute type.
      */
      static CATUnicodeString GetValueTypeName( int inNodeProperty ) ;

      // ---------------------------------------------
      // --- Flag to be used for special operation ---
      // ---------------------------------------------

    /**
      * Resets flag on all sub-structure.
      *
      * <br><b>Role</b>: Resets flag on all sub-structure.
      */
      void ResetFlag() ;

    /**
      * Sets flag value.
      *
      * <br><b>Role</b>: Sets flag value on a PLMExchangeBasicNode.
      *
      * @param inFlag [in]
      * Value of the flag.
      */
      void SetFlag( int inFlag ) ;

    /** 
      * Gets flag value.
      *
      * <br><b>Role</b>: Gets flag value on a PLMExchangeBasicNode.
      *
      * @return
      *   Object flag value.
      */
      int GetFlag() const ;

    /**
      * Sets node in the  working area.
      *
      * <br><b>Role</b>: Sets working with a PLMExchangeBasicNode.
      *
      * @param ixNodeArea [in]
      *   Nod to be memorized in working area.
      */
      void SetNodeWorkingArea( PLMExchangeBasicNode * ixNodeArea ) ;

    /** 
      * Gets node in the  working area.
      *
      * <br><b>Role</b>: Gets working with a PLMExchangeBasicNode.
      *
      * @return
      *   Node stored in working area.
      */
      PLMExchangeBasicNode * GetNodeWorkingArea() const ;
 
      // ---------------------------------------------------------------
      // --- Describe Node characteristics:
      // ---------------------------------------------------------------

    /**
      * Enumeration of Metric properties.
      * 
      * <br><b>Role</b>: Enumeration of available metric properties.
      * 
      * @param PLMExchangeProperty_Unset
      *   No property define, to be used for property mask initialization.
      * @param PLMExchangeProperty_TypeBoolean
      *   boolean type of value.
      * @param PLMExchangeProperty_TypeInteger
      *   integer type of value.
      * @param PLMExchangeProperty_TypeFloat
      *   float type of value.
      * @param PLMExchangeProperty_TypeString
      *   string type of value.
      * @param PLMExchangeProperty_TypeBinary
      *   binary type of value.
      * @param PLMExchangeProperty_TypeDate
      *   date type of value.
      * @param PLMExchangeProperty_TypeBinaryTS
      *   timestamp type of value.
      * @param PLMExchangeProperty_TypeFileName
      *   file name type of value.
      * @param PLMExchangeProperty_TypeFolderPath
      *    directory path type of value.
      * @param PLMExchangeProperty_TypeObject
      *    object type of value.
      * @param PLMExchangeProperty_TypeNlsString
      *     enum type of value.
      * @param PLMExchangeProperty_TypeZone
      *   enables to isolate value type information.
      * @param PLMExchangeProperty_AntiTypeZone
      *   enables to reset value type information.
      * @param PLMExchangeProperty_IsSet
      *   to check if value is set.
      * @param PLMExchangeProperty_IsLocked
      *   to check if value is locked.
      * @param PLMExchangeProperty_IsInactive
      *   to check if a node is inactive (useful in context of options or metrics).
      * @param PLMExchangeProperty_IsHidden
      *   to check if value need to be hidden.
      * @param PLMExchangeProperty_IsDummy
      *   to mark object created at read stream as dummy object before finding the real object.
      * @param PLMExchangeProperty_IsSensitive
      *   to mark object where modification required to refresh views.
      * @param PLMExchangeProperty_IsDeleted
      *   to mark object where deletion is under process.
      * @param PLMExchangeProperty_IsPrivateData
      *   to mark that following sub-tree is considered as private data.
      */
      enum PLMExchangeProperty
      {
        PLMExchangeProperty_Unset           = 0x00000000
      , PLMExchangeProperty_TypeBoolean     = PLMExchangeBooleanAttribute    // 0x00000001
      , PLMExchangeProperty_TypeInteger     = PLMExchangeIntegerAttribute    // 0x00000002
      , PLMExchangeProperty_TypeFloat       = PLMExchangeFloatAttribute      // 0x00000004
      , PLMExchangeProperty_TypeString      = PLMExchangeStringAttribute     // 0x00000008
      , PLMExchangeProperty_TypeBinary      = PLMExchangeBinaryAttribute     // 0x00000010
      , PLMExchangeProperty_TypeDate        = PLMExchangeDateAttribute       // 0x00000020
      , PLMExchangeProperty_TypeBinaryTS    = PLMExchangeBinaryTSAttribute   // 0x00000040
      , PLMExchangeProperty_TypeFileName    = PLMExchangeFileNameAttribute   // 0x00000080
      , PLMExchangeProperty_TypeFolderPath  = PLMExchangeFolderPathAttribute // 0x00000100
      , PLMExchangeProperty_TypeObject      = PLMExchangeObjectAttribute     // 0x00000200
      , PLMExchangeProperty_TypeNlsString   = PLMExchangeNlsStringAttribute  // 0x00000400
      , PLMExchangeProperty_TypeNode        = PLMExchangeNodeRefAttribute    // 0x00000800
      , PLMExchangeProperty_TypeZone        = 0x0000FFFF
      , PLMExchangeProperty_AntiTypeZone    = 0xFFFF0000
      , PLMExchangeProperty_IsSet           = 0x00010000
      , PLMExchangeProperty_IsLocked        = 0x00020000
      , PLMExchangeProperty_IsInactive      = 0x00040000
      , PLMExchangeProperty_IsHidden        = 0x00080000
      , PLMExchangeProperty_IsDummy         = 0x00100000
      , PLMExchangeProperty_IsSensitive     = 0x00200000
      , PLMExchangeProperty_IsDeleted       = 0x00400000
      , PLMExchangeProperty_IsPrivateData   = 0x00800000
      } ;

    /**
      * Identifies if metrics, option or attribute is locked.
      *
      * <br><b>Role</b>: Identifies if metrics, option or attribute is locked.
      * 
      * @return
      *    status relative to lock status.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>Node is not locked.</dd>
      *  <dt>1</dt>   <dd>Node is locked.</dd>
      *  </dl>
      */
      int IsLocked() const ;

    /**
      * Sets lock status.
      *
      * <br><b>Role</b>: Sets lock status.
      * 
      * @param inLockStatus
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>Node is not locked.</dd>
      *  <dt>1</dt>   <dd>Node is locked.</dd>
      *  </dl>
      */
      void SetLockStatus( int inLockStatus ) ;

    /**
      * Identifies if metrics, option or attribute need to be hidden.
      *
      * <br><b>Role</b>: Identifies if metrics, option or attribute need to be hidden.
      * 
      * @return
      *    status relative to lock status.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>Node not to be hidden.</dd>
      *  <dt>1</dt>   <dd>Node to be hidden.</dd>
      *  </dl>
      */
      int IsHidden() const ;

    /**
      * Sets hidden status.
      *
      * <br><b>Role</b>: Defines if node need to be Hidden or Showed.
      * 
      * @param inHideStatus
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>Node not to be hidden.</dd>
      *  <dt>1</dt>   <dd>Node to be hidden.</dd>
      *  </dl>
      */
      void SetHideStatus( int inHideStatus ) ;

    /**
      * Identifies if node is considered as dummy.
      *
      * <br><b>Role</b>: Identifies if node is considered as dummy.
      * 
      * @return
      *    status relative to <i>Dummy</i> status.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>Node not considered as dummy.</dd>
      *  <dt>1</dt>   <dd>Node marked as dummy.</dd>
      *  </dl>
      */
      int IsDummy() const ;

    /**
      * Sets dummy status.
      *
      * <br><b>Role</b>: Sets dummy status.
      * 
      * @param inDummyStatus
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>Node not to be marked as dummy.</dd>
      *  <dt>1</dt>   <dd>Node to be marked as dummy.</dd>
      *  </dl>
      */
      void SetDummyStatus( int inDummyStatus ) ;

    /**
      * Identifies if node is considered as Sensitive.
      *
      * <br><b>Role</b>: Identifies if node is considered as Sensitive and thus modification require propagation.
      * 
      * @return
      *    status relative to lock status.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>Node not considered as Sensitive.</dd>
      *  <dt>1</dt>   <dd>Node marked as Sensitive.</dd>
      *  </dl>
      */
      int IsSensitive() const ;

    /**
      * Sets node Sensitivivity.
      *
      * <br><b>Role</b>: Identifies if node modification require propagation to applications.
      * 
      * @param inSensitiveStatus
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>Node not to be marked as Sensitive.</dd>
      *  <dt>1</dt>   <dd>Node to be marked as Sensitive.</dd>
      *  </dl>
      */
      void SetSensitiveStatus( int inSensitiveStatus ) ;

    /**
      * Identifies if node is considered as Inactive.
      *
      * <br><b>Role</b>: Identifies if node is considered as Inactive.
      * 
      * @return
      *    status relative to lock status.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>Node not considered as Inactive.</dd>
      *  <dt>1</dt>   <dd>Node marked as Inactive.</dd>
      *  </dl>
      */
      int IsInactive() const ;

    /**
      * Sets node Inactivity status.
      *
      * <br><b>Role</b>: Identifies if node is considered as Inactive.
      * 
      * @param inInactiveStatus
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>Node not to be marked as Inactive.</dd>
      *  <dt>1</dt>   <dd>Node to be marked as Inactive.</dd>
      *  </dl>
      */
      void SetInactiveStatus( int inInactiveStatus ) ;

    /**
      * Identifies if node is considered as private.
      *
      * <br><b>Role</b>: Identifies if node is considered as private and thus its sub-tree will be streamed as one unique XML node
      * with content wrote in XML value attribute as binary string.
      * 
      * @return
      *    status relative to private status.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>Node is not considered as private data.</dd>
      *  <dt>1</dt>   <dd>Node is considered as private data.</dd>
      *  </dl>
      */
      int IsPrivate() const ;

    /**
      * Sets private data property.
      *
      * <br><b>Role</b>: Sets private data property.
      * 
      * @param inLockStatus
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>Node is not considered as private data.</dd>
      *  <dt>1</dt>   <dd>Node is considered as private data.</dd>
      *  </dl>
      */
      void SetPrivate( int inPrivate ) ;

      // -----------------------------------------
      // --- Operator to manage tree structure ---
      // -----------------------------------------

    /** 
      * Inserts an object as a child at specific place.
      *
      * <br><b>Role</b>: Inserts an object as a child at specific place.
      * 
      * @param ixNewChild
      * Object node that needs to be added as a child.
      *
      * @param ixReference
      * Object node used to position <tt>ixNewChild</tt> in the children list.
      * <br><b>Legal values</b>: It can be set to either:
      * <ul>
      * <li><tt>NULL</tt> to insert at first position</li>
      * <li>If <tt>ixReference</tt> is not <tt>NULL</tt> and is not child of the current
      * object, then we insert <tt>ixNewChild</tt> at last position</li> 
      * <li>Otherwise we insert <tt>ixNewChild</tt> before <tt>ixReference</tt></li>
      * <ul/>
      */
      void InsertBefore( PLMExchangeBasicNode * const ixNewChild
                       , PLMExchangeBasicNode * const ixReference = NULL ) ;

      // ---  Insert an object as children at a last position

    /** 
      * Inserts an object as a child at last position.
      *
      * <br><b>Role</b>: Inserts an object as a child at last position.
      * 
      * @param ixNewChild
      * Object node that needs to be added as a child.
      */
      void Append( PLMExchangeBasicNode * const ixNewChild ) ;

      // --- Suppress the object from the father-child assembly

    /** 
      * Suppresses the object from the father-child assembly.
      *
      * <br><b>Role</b>: Suppresses the object from the father-child assembly.
      * 
      */
      void CutFromFather() ;

      // --- Remove and delete all child nodes

    /** 
      * Removes and deletes all child nodes.
      *
      * <br><b>Role</b>: Removes and deletes all child nodes.
      * 
      */
      void RemoveAllChildren() ;

      // --- Scans list of all children of node
      // ---   * To start scan initialize xPrevious to NULL
      // ---   * At scan ends whe return NULL

    /**
      * Gets next child.
      *
      * <br><b>Role</b>: Scans the list of children of current node object.
      *
      * @return
      * Next child object node. 
      * <br>Return <tt>NULL</tt> if <tt>ixPrevious</tt> is not a child of current node 
      * or if it is the last child
      * 
      * @param ixPrevious
      * Current child object.
      * <br><b>Legal values</b>:
      * <ul>
      * <li><tt>NULL</tt> to get the first child</li>
      * <ul/>
      */
      PLMExchangeBasicNode * ScanChildren( const PLMExchangeBasicNode * const ixPrevious ) const ;

    /**
      * Gets the father node.
      *
      * <br><b>Role</b>: Gets the father @href PLMExchangeNode of the current object.
      * 
      *
      * @return
      * Father node object. 
      */
      PLMExchangeNode * GetFather() const ;

    /**
      * Gets the father node.
      *
      * <br><b>Role</b>: Gets the father @href PLMExchangeBasicNode of the current object.
      * 
      *
      * @return
      * Father node object. 
      */
      PLMExchangeBasicNode * GetAllFather() const ;

    /**
      * Gets the root node.
      *
      * <br><b>Role</b>: Gets the root father node of the current object.
      * 
      *
      * @return
      * Father node object. 
      */
      PLMExchangeBasicNode * GetRoot() const ;

    /**
      * Gets next child in the node tree.
      *
      * <br><b>Role</b>: Scans node structure tree (in depth first).
      * 
      * @param ixPrevious
      * Current child object.
      * <br><b>Legal values</b>:
      * <ul>
      * <li><tt>NULL</tt> To get the root of the structure (the <b><i>PLMExchangeBasicNode</b></i> itself) and 
      * depth level is initialized to 0.</li>
      * <ul/>
      * 
      * @param ionUpDown 
      * Level of depth on the <b><i>PLMExchangeInstance</b></i>.
      * This value is initialized to 0 when full assembly scan is done or when scan is initialized (NULL value for <b>ixPrevious</b>).
      * Otherwise computed by incrementation or decrementation of the input value.
      * 
      * @return
      *   Next child object node. 
      *    <br>Return <tt>NULL</tt> if <tt>ixPrevious</tt> is not a child of current node 
      *    or if it is the last child
      */
      PLMExchangeBasicNode * ScanTree( PLMExchangeBasicNode * ixPrevious , int & ionUpDown ) const ;

      // -----------------------------
      // --- To manage object usage
      // -----------------------------

    /** 
      * Notify that one object will be deleted.
      *
      * <br><b>Role</b>: Notify that one object will be deleted.
      * 
      * @param ixReferenced
      * Object.
      * 
      * @return
      *   0 if Ok
      */
      virtual int NotifyObjectDeletion( const PLMExchangeNode * ixReferenced ) ;

    /** 
      * Notify an object replacement.
      *
      * <br><b>Role</b>: In case of XML loading, we may have to replace on PLMExchangeBasicNode by another one
      * (case of dummy node for instance).
      * <p><b>NB</b>: Does call <b><i>SuppressObjectUsage</i></b> to suppress all referencing
      * 
      * @param ixOld
      *  Object to be replaced.
      * 
      * @param ixNew
      *  Replacement Object.
      * 
      * @return
      *   0 if Ok
      */
      virtual int NotifyObjectReplace( const PLMExchangeNode * ixOld , PLMExchangeNode * ixNew ) ;

    /** 
      * List of defined stream filters:
      * 
      * @param WITH_OBJECT
      *   Add all objects, not only the one in errors.
      * @param WITH_ATTRIBUTE
      *   Add Attribute information.
      * @param WITH_CLASS
      *   Add Object and Attribute class information.
      * @param WITH_OID
      *   Add Oid on each nodes.
      * @param WITH_DATA_SOURCE  
      *  Add Data source information.
      * @param OBJECT_WITH_NOTIF 
      *  Add only objects having notification associated.
      * @param WITH_PRIVATE_DATA  
      *  Add Private data to the stream.
      * @param WITH_TRANSACTION  
      *  Add transaction in the stream.
      * @param WITHOUT_HIDDEN   
      *  Do not display or navigate hidden objects.
      * @param WITHOUT_INACTIVATED   
      *  Do not display or navigate inactivated objects.
      * @param ATTRIBUTE_WITH_VALUE 
      *  Add only attributes and metrics having values set.
      * @param XSL_FILE_PROTOCOL
      *  Enable to force definition of XSL with the addition of prefix protocole file://.
      * @param IGNORE_PRIVATE_INFO
      *  Ignore Private data property to stream Private information without encoded.
      * @param Debug
      *  All flags activated.
      * @param XMLStopRestart
      *  Generate reports with all information preserved to be able to restart without any loss of information.
      * @param XMLReport
      *  Generate reports with all objects with attribute, Oid and Data source.
      * @param XMLNotifReport
      *  Generates report with only objects having notifications with attribute, Oid and Data source.
      * @param XMLShortReport
      *  Generate reports with all objects with attributes & metrics set, Oid and Data source.
      */
      enum PLMExchangeStreamFilter
      {
        WITH_OBJECT          = 0x00000001  // Add all objects, not only the one in errors.
      , WITH_ATTRIBUTE       = 0x00000002  // Add Attribute information.
      , WITH_CLASS           = 0x00000004  // Add Object and Attribute class information.
      , WITH_OID             = 0x00000008  // Add Oid on each nodes
      , WITH_DATA_SOURCE     = 0x00000010  // Add Data source information
      , WITH_TRANSACTION     = 0x00000020  // Add transaction in the stream.
      , WITH_PRIVATE_DATA    = 0x00000040  // Add Private data to the stream.
      , XSL_FILE_PROTOCOL    = 0x00000080  // Enable to force definition of XSL with the addition of prefix protocole file://.
      , IGNORE_PRIVATE_INFO  = 0x00000100  // Ignore Private data property to stream Private information without encoded.
      , OBJECT_WITH_NOTIF    = 0x00010000  // Add only objects having notification associated.
      , ATTRIBUTE_WITH_VALUE = 0x00020000  // Add only attribute set.
      , WITHOUT_HIDDEN       = 0x00040000  // Do not display or navigate hidden objects.
      , WITHOUT_INACTIVATED  = 0x00080000  // Do not display or navigate inactivated objects.

      , Debug                = 0x0000FFFF  // Activate all outputs.
      , XMLStopRestart       = 0x0000005F  // WITH_OBJECT|WITH_ATTRIBUTE|WITH_OID|WITH_DATA_SOURCE|WITH_CLASS|WITH_PRIVATE_DATA
      , XMLReport            = 0x0000001B  // WITH_OBJECT|WITH_ATTRIBUTE|WITH_OID|WITH_DATA_SOURCE
      , XMLFullReport        = 0x0000005B  // WITH_OBJECT|WITH_ATTRIBUTE|WITH_OID|WITH_DATA_SOURCE|WITH_PRIVATE_DATA
      , XMLNotifReport       = 0x0001001B  // OBJECT_WITH_NOTIF|WITH_OBJECT|WITH_ATTRIBUTE|WITH_OID|WITH_DATA_SOURCE
      , XMLShortReport       = 0x0002001B  // WITH_OBJECT|WITH_ATTRIBUTE|WITH_OID|WITH_DATA_SOURCE|ATTRIBUTE_WITH_VALUE
      } ;

    /** 
      * List of defined stream formats:
      * 
      * @param XML_STREAMING
      *   Request a streaming in XML.
      * @param JSON_STREAMING
      *   Request a streaming in JSON.
      */
      enum PLMExchangeStreamFormat
      {
        XML_STREAMING        = 0x00000001  // XML streaming.
      , JSON_STREAMING       = 0x00000002  // JSON streaming.
      } ;

    /** 
      * Save Report through a stream buffer.
      *
      * <br><b>Role</b>: Save Report through a stream buffer (enable XML, JSON... persistency).
      * 
      * @param iStreamBuffer
      *   Stream buffer.
      *
      * @param inFileFilter
      *   Filter to apply when streaming PLM Exchange Model.
      *
      * @param iusXSLFilePath
      *   XSL file to add to the XML header.
      *
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>File successfully generated.</dd>
      * <dt>E_FAIL</dt>  <dd>Error during save transaction.</dd>
      * </dl>
      */
      int SaveInStreamBuffer( PLMExchangeStreamBuffer & iStreamBuffer
                            , int                       inFileFilter  = XMLReport
                            , const CATUnicodeString  & iusXSLFilePath = ""        ) ;

    /** 
      * Save on disk with an XML stream session definition.
      *
      * <br><b>Role</b>: Save on disc with an XML stream session definition.
      * 
      * @param icFilePath
      *   File path of the file.
      *
      * @param inFileFilter
      *   Filter to apply when streaming PLM Exchange Model.
      *
      * @param iusXSLFilePath
      *   XSL file to add to the XML header.
      *
      * @param inFileFormat
      *   Define file format to be used.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>XML_STREAMING</dt>   <dd>XML streaming.</dd>
      * <dt>JSON_STREAMING</dt>  <dd>JSON streaming.</dd>
      * </dl>
      *
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>File successfully generated.</dd>
      * <dt>E_FAIL</dt>  <dd>Error during save transaction.</dd>
      * </dl>
      */
      int SaveStreamAsFile( const CATUnicodeString & icFilePath
                          , int                      inFileFilter  = XMLReport
                          , const CATUnicodeString & iusXSLFilePath = ""        
                          , int                      inFileFormat   = XML_STREAMING ) ;

    /** 
      * Append XML stream on an already open file.
      *
      * <br><b>Role</b>: Append XML stream on an already open file.
      * 
      * @param inFileDescriptor [in]
      *   File descriptor to be used to append the XML representation of the report model.
      *
      * @param inFileFilter [in]
      *   Filter to apply when streaming PLM Exchange Model.
      *
      * @param inFileFormat
      *   Define file format to be used.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>XML_STREAMING</dt>   <dd>XML streaming.</dd>
      * <dt>JSON_STREAMING</dt>  <dd>JSON streaming.</dd>
      * </dl>
      *
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>File successfully generated.</dd>
      * <dt>E_FAIL</dt>  <dd>Error during save transaction.</dd>
      * </dl>
      */
      int AppendReportInFile( unsigned int inFileDescriptor
                            , int          inFileFilter = XMLReport 
                            , int          inFileFormat = XML_STREAMING ) ;

    /** 
      * Append model in an existing stream.
      *
      * <br><b>Role</b>: Append model in an existing stream.
      *
      * @param iStreamBuffer [in]
      *  Stream buffer.
      *
      * @param inFileFilter [in]
      *   Filter to apply when streaming PLM Exchange Model.
      *
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>File successfully generated.</dd>
      * <dt>E_FAIL</dt>  <dd>Error during save transaction.</dd>
      * </dl>
      */
      int AppendReportInStream( PLMExchangeStreamBuffer & iStreamBuffer , int inFileFilter ) ;

    /** 
      * Access to default Report style sheet.
      *
      * <br><b>Role</b>: Access to default Report style sheet.
      *  <p>Per default, we are looking in CATInstallPath to find \resources\xsl\PLMExchangeReport.xsl .</p>
      * 
      * @param ocXslPath [out]
      *   Default xsl file to add to the XML header.
      * 
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>One default XSL file found.</dd>
      * <dt>S_FALSE</dt> <dd>No default XSL file found.</dd>
      * <dt>E_FAIL</dt>  <dd>No default XSL file found.</dd>
      * </dl>
      */
      static HRESULT GetDefaultReportStyleSheet( CATUnicodeString &  ocXslPath ) ;

    /** 
      * Read from disk an XML stream.
      *
      * <br><b>Role</b>: Read from disk an XML stream containing PLMExchangeBasicNodes.
      * 
      * @param icFilePath [in]
      * File path of the file.
      * 
      * @param inMode [in]
      *    Set up the loading mode as a mask of bits:
      *    <br><b>Legal values</b>:
      *    <dl>
      *    <dt>PLMExchangeLoadingMode_File</dt>             <dd>Define XML source as a file.</dd>
      *    <dt>PLMExchangeLoadingMode_Memory</dt>           <dd>Define XML source as a memory buffer.</dd>
      *    <dt>PLMExchangeLoadingMode_No_Root</dt>          <dd>Define XML source as not having the root object (object must be attached to root).</dd>
      *    <dt>PLMExchangeLoadingMode_Inhibit</dt>          <dd>Inhibite transaction recording.</dd>
      *    <dt>PLMExchangeLoadingMode_AllocateNodeId</dt>   <dd>Force Instance Id table allocation.</dd>
      *    <dt>PLMExchangeLoadingMode_InitNodeId</dt>       <dd>Force Instance Id table initialization with current model content.</dd>
      *    <dt>PLMExchangeLoadingMode_FreeNodeId</dt>       <dd>Reset and free Instance Id table.</dd>
      *    <dt>PLMExchangeLoadingMode_Full</dt>             <dd>Set of options to load an exchange model in full mode.</dd>
      *    <dt>PLMExchangeLoadingMode_PrepareDelta</dt>     <dd>Set of options to load the first exchange model to prepare loading by delta.</dd>
      *    <dt>PLMExchangeLoadingMode_ByDelta</dt>          <dd>Set of options to load to load in delta mode (update or delete existing objects or create new ones).</dd>
      *    </dl>
      * 
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>0</dt> <dd>if operation are executed without any errors.</dd>
      * <dt>1</dt> <dd>otherwise.</dd>
      * </dl>
      */
      int LoadFromFile( const CATUnicodeString & icFilePath , int inMode = PLMExchangeLoadingMode_Full ) ;

      // --- Print attribute identity card

    /** 
      * Print a report on standard output.
      *
      * <br><b>Role</b>: Print the content of this node and its children.
      * 
      * @param icInfo
      *   String that will appear in the header of long print.
      * 
      * @param inOption
      *    Enable to display model content differently:
      *    <br><b>Legal values</b>:
      *    <dl>
      *    <dt>0</dt> <dd>(Default) Enables to have a long report with the node only.</dd>
      *    <dt>1</dt> <dd>Enables to have a one line report with the node only.</dd>
      *    <dt>2</dt> <dd>Enables to have a one line report with the whole sub-structure.</dd>
      *    </dl>
      */
      void Print( const char * const icInfo = NULL , int inOption=0 ) const ;

    /**
      * Internal print method to generate a report on standard output.
      *
      * <br><b>Role</b>: Internal method to generate a report on standard output that display the content
      *   of this node and its children.
      * 
      * @param icInput
      *  String to be used as header of the output.
      * 
      * @param icType
      *  String representing the object type
      * 
      * @param inMode
      *  Type of report to be generated.
      * 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>0</dt> <dd>Standard mode.</dd>
      * <dt>1</dt> <dd>One line mode.</dd>
      * </dl>
      */
      virtual void _print( const char * const icInput , const char * const icType , int inMode = 0 ) const ;

    /** Debug trace mask. */
      static int nDebugMask  ;

    /** Debug trace level.*/
      static int nDebugLevel ;

    /**
      * Enables to activate Debug traces.
      *
      * <br><b>Role</b>: Enables to activate Debug traces by APIs.
      *   It could also been globally activated using RT variables <b><i>PLMExchangeDebug</i></b> & <b><i>PLMExchangeDebugLevel</i></b>.
      * 
      * @param inDebugMask
      *   Type of traces to be activated according a mask of bits .
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>PLMExchangeDebugClean</dt>       <dd>Trace in New/Delete operations.</dd>
      *   <dt>PLMExchangeDebugSearch</dt>      <dd>Trace in Search & Locate methods.</dd>
      *   <dt>PLMExchangeDebugXmlStream</dt>   <dd>Trace in XML generation or load.</dd>
      *   <dt>PLMExchangeDebugGUI</dt>         <dd>Trace for GUI.</dd>
      *   <dt>PLMExchangeDebugInit</dt>        <dd>Trace relative to reconciliator initialization mainly in PLMExchangeSession.</dd>
      *   <dt>PLMExchangeDebugOid</dt>         <dd>Trace relative to Oid management (search and other).</dd>
      *   <dt>PLMExchangeDebugService</dt>     <dd>Trace relative to PLM ExchangeModel Service.</dd>
      *   <dt>PLMExchangeDebugTransaction</dt> <dd>Trace relative to PLM ExchangeModel Service.</dd>
      *   <dt>PLMExchangeDebugMetric</dt>      <dd>Trace relative to Metric valuation.</dd>
      *   <dt>PLMExchangeDebugJustInCase</dt>  <dd>Trace optional (before creation of a new flag).</dd>
      *   </dl>
      *   <br><b>Example of activation through RT</b>: set PLMExchangeDebug="PLMExchangeDebugXmlStream PLMExchangeDebugMetric"
      * 
      * @param inDebugLevel
      *    Level of traces to be generated.
      *   <br><b>Legal values</b>: Positive or null value.
      *   <br><b>Example of activation through RT</b>: set PLMExchangeDebugLevel="2"
      */
      static void DefinesTraceActivation( int inDebugMask , int inDebugLevel ) ;

    /**
      * Gets current activate Debug traces.
      *
      * <br><b>Role</b>: Gets current activate Debug traces.
      * 
      * @param onDebugMask
      *   Type of traces activated according a mask of bits .
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>PLMExchangeDebugClean</dt>       <dd>Trace in New/Delete operations.</dd>
      *   <dt>PLMExchangeDebugSearch</dt>      <dd>Trace in Search & Locate methods.</dd>
      *   <dt>PLMExchangeDebugXmlStream</dt>   <dd>Trace in XML generation or load.</dd>
      *   <dt>PLMExchangeDebugGUI</dt>         <dd>Trace for GUI.</dd>
      *   <dt>PLMExchangeDebugInit</dt>        <dd>Trace relative to reconciliator initialization mainly in PLMExchangeSession.</dd>
      *   <dt>PLMExchangeDebugOid</dt>         <dd>Trace relative to Oid management (search and other).</dd>
      *   <dt>PLMExchangeDebugService</dt>     <dd>Trace relative to PLM ExchangeModel Service.</dd>
      *   <dt>PLMExchangeDebugTransaction</dt> <dd>Trace relative to PLM ExchangeModel Service.</dd>
      *   <dt>PLMExchangeDebugMetric</dt>      <dd>Trace relative to Metric valuation.</dd>
      *   <dt>PLMExchangeDebugJustInCase</dt>  <dd>Trace optional (before creation of a new flag).</dd>
      *   </dl>
      *   <br><b>Example of activation through RT</b>: set PLMExchangeDebug="PLMExchangeDebugXmlStream PLMExchangeDebugMetric"
      * 
      * @param onDebugLevel
      *    Level of traces activated.
      *   <br><b>Legal values</b>: Positive or null value.
      *   <br><b>Example of activation through RT</b>: set PLMExchangeDebugLevel="2"
      */
      static void GetTraceActivation( int & onDebugMask , int & onDebugLevel ) ;

      // -------------------------------------------
      // --- Manage performance monitoring
      // -------------------------------------------

    /**
      * Start monitoring of performance.
      *
      * <b>Role:</b> Initialize information required for performance monitoring. 
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns <b><i>S_OK</i></b> if operation runs well. 
      */
      static HRESULT StartPerformanceMonitoring() ;

    /**
      * Capture time consume by an operation.
      *
      * <b>Role:</b> Monitoring of performance of an operation. 
      * 
      * @param inCounter
      *  Timer id (We support 3 timers identify by an integer between 0 and 2).
      * 
      * @param ilPrint
      *  Define if traces need to be printed on standard output.
      * 
      * @param icMessage
      *  Message associated with this operation.
      * 
      * @param odCpuTime
      *  CPU time consumes by this step.
      * 
      * @param odElapsedTime
      *  CPU time consumes by this step.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns <b><i>S_OK</i></b> if operation runs well. 
      */
      static HRESULT IdentifyEndOfPerformanceStep( int inCounter , int ilPrint , const char * icMessage 
                                                 , double & odCpuTime , double & odElapsedTime ) ;
    /**
      * Stop monitoring of performance.
      *
      * <b>Role:</b> Free all information required for performance monitoring. 
      * 
      * @return
      * Method return code. 
      * <br><b>Legal values</b>: Returns <b><i>S_OK</i></b> if operation runs well. 
      */
      static HRESULT StopPerformanceMonitoring() ;

    /**
      * Convert a one byte value on an hexadecimal characters string.
      *
      * <b>Role:</b> Convert a one byte value on an hexadecimal characters string.
      * 
      * @param inBinary
      *   unsigned byte value.
      * 
      * @param ocHexa
      *   A 2 characters string that will contain the hexadecimal value after conversion.
      * 
      * @return
      *   Method return code.
      *   <br><b>Legal values</b>: Returns <b><i>0</i></b> if operation runs well. 
      */
      static int EncodeBinaryCharacter( const unsigned char inBinary
                                      , char                ocHexa[2] ) ;

    /**
      * Convert a 2 characters hexadecimal string in its value.
      *
      * <b>Role:</b> Convert a 2 characters hexadecimal string in its value.
      * 
      * @param icHexa
      *   A 2 characters string that will contain the hexadecimal value after conversion.
      * 
      * @param onBinary
      *   unsigned byte value.
      * 
      * @return
      *   Method return code.
      *   <br><b>Legal values</b>: Returns <b><i>0</i></b> if operation runs well. 
      */
      static int DecodeBinaryCharacter( const char      icHexa[2]
                                      , unsigned char & onBinary ) ;
    /**
      * Compute NLS identification from key.
      *
      * <br><b>Role</b>: Compute NLS identification from key.
      * This string enables to look for NLS name. It is a structured string made of 3 fields CATNls file name, '.' character
      * and key inside this message catalog: name_CATNls_File.key 
      * 
      * @param iusKey
      *   Access key.
      * 
      * @param iusNlsName
      *   NLS name.
      * 
      * @return
      *   Returns error code.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>    <dd>NLS label computed from input key.</dd>
      *   <dt>S_FALSE</dt> <dd>NLS label valuated from key.</dd>
      *   <dt>E_FAIL</dt>  <dd>Error during processing.</dd>
      *   </dl>
      */
      static HRESULT ComputeNlsNameFromKey( const CATUnicodeString & iusKey , CATUnicodeString & iusNlsName ) ;

	 /**
	  * Process XSL transformation of XML report
	  */
	  static HRESULT XSLTransform(const CATUnicodeString& iReportFileName, const CATUnicodeString& iXSLFileName);  //IR-994482 


   private:
      static CATTimerId  _xTimerId         ;
      static double      _dCpuTime[3]      ;
      static double      _dEllapsedTime[3] ;

    /** Mask to store Options.*/
      static int _nMaskOptions ;

      // -----------------------------
      // --- Manage tree structure ---
      // -----------------------------

   protected:
      // --- Basic structure characteristic:
      // --- * _xFather         Father object.
      // --- * _xNextChild      Next child.
      // --- * _xPreviousChild  Previous child.
      // --- * _xFirstChild     First child.
      // --- * WorkingArea:     Work area used for some treatments.
      // --- *    _xNodeArea     + Node area to manage linear tree on model scanning.
      // --- *    _nFlag         + Integer area.
      // --- * _nNodeProperty   Property mask to define Nodes's properties.

    /** Father object in set structure. */
      PLMExchangeBasicNode          * _xFather        ;

    /**  Next child object in set structure. */
      PLMExchangeBasicNode          * _xNextChild     ;

    /** Previous child object in set structure. */
      PLMExchangeBasicNode          * _xPreviousChild ;

    /** First child of this object. */
      PLMExchangeBasicNode          * _xFirstChild    ;

    /** Work area. */

      union
      {
         PLMExchangeBasicNode       * _xNodeArea     ;
         int                          _nFlag         ;
      } ;

    /** 
      * Property mask to define Nodes's properties such as:
      *   <dl>
      *   <dt>IsSet</dt>           <dd>Defines if value has been set.</dd>
      *   <dt>IsLock</dt>          <dd>Defines if value is locked.</dd>
      *   <dt>IsPrivate</dt>       <dd>Defines if node is priv.</dd>
      *   <dt>IsArrayOfValue</dt>  <dd>Defines is metric is an array of values or a single value.</dd>
      *   <dt>Value type</dt>      <dd>Define type of values expected for metric.</dd>
      *   </dl>
      */
      int                             _nNodeProperty  ;

      // -----------------------------------------------
      // --- PLMExchangeBasicNode life cycle              ---
      // -----------------------------------------------

    /**
      * Free all information on a PLMExchangeBasicNode.
      * 
      * <br><b>Role</b>: Free all information on a PLMExchangeBasicNode.
      * 
      * @param ixTransaction
      *   Current transaction (Exchange model session root).
      * 
      * @return
      *   Return number of object in current transaction.
      */
      virtual int _isolateNode( PLMExchangeTransaction * ixTransaction ) ;

      // -----------------------------------------
      // --- Transaction management            ---
      // -----------------------------------------

    /**
      * Register one object modification event.
      *
      * <br><b>Role</b>: Register one object modification event to be managed by current transaction.
      * 
      * @param inOperation
      *   Modification Operations to be done.
      * <br><b>Legal values</b>: It can be set to either:
      * <dl>
      * <dt>PLMExchangeUnknownEvent</dt>        <dd>No event to log.</dd>
      * <dt>PLMExchangeCreateEvent</dt>         <dd>Creation.</dd>
      * <dt>PLMExchangeModifyDataEvent</dt>     <dd>Modification.</dd>
      * <dt>PLMExchangeDeleteEvent</dt>         <dd>Deletion.</dd>
      * <dt>PLMExchangeSelectEvent</dt>         <dd>Selection.</dd>
      * <dt>PLMExchangeModifyPropertyEvent</dt> <dd>Property modification.</dd>
      * </dl>
      * 
      * @return
      * Returns error code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Transaction successfully closed.</dd>
      * <dt>S_FALSE</dt> <dd>No current transaction opened.</dd>
      * <dt>E_FAIL</dt>  <dd>Fail to close current transaction.</dd>
      * </dl>
      */
      HRESULT _registerTransactionEvent( int inOperation ) ;

    /**
      * Stop recording events in current transaction.
      *
      * <br><b>Role</b>: Only for internal usage to stop recording events in current transaction.
      * 
      * @return
      * Returns error code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Transaction successfully closed.</dd>
      * <dt>S_FALSE</dt> <dd>No current transaction opened.</dd>
      * <dt>E_FAIL</dt>  <dd>Fail to close current transaction.</dd>
      * </dl>
      */
      HRESULT _stopEventRecording() ;

   /**
      * Activate event recording in current transaction.
      *
      * <br><b>Role</b>: Only for internal usage to activate event recording in current transaction.
      * 
      * @return
      * Returns error code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Transaction successfully closed.</dd>
      * <dt>S_FALSE</dt> <dd>No current transaction opened.</dd>
      * <dt>E_FAIL</dt>  <dd>Fail to close current transaction.</dd>
      * </dl>
      */
      HRESULT _activateEventRecording() ;

      // --- Build a stream from published information

   public:
    /** Blank character. */
      static const CATUnicodeString cBlank            ;

    /** XML Tag for node name. */
      static const CATUnicodeString cNameTag          ;

    /** XML Tag for node internal PLMExchangeBasicNode Id. */
      static const CATUnicodeString cIdTag            ;

    /** XML Tag for Oid. */
      static const CATUnicodeString cOidTag           ;

    /** XML boolean value true. */
      static const CATUnicodeString cTrueValue        ;

    /** XML boolean value false. */
      static const CATUnicodeString cFalseValue       ;

    /** XML Tag for attribute value. */
      static const CATUnicodeString cValueTag         ;

      /** XML Tag for local attribute value in case of NLS. */
      static const CATUnicodeString cLocalTag         ;

    /** XML Tag for type. */
      static const CATUnicodeString cTypeTag          ;

    /** XML Tag to identify if value is set. */
      static const CATUnicodeString cIsSetTag         ;

    /** XML Tag to access to key label. */
      static const CATUnicodeString cNlsTag           ;

    /** XML Tag to define default value. */
      static const CATUnicodeString cDefaultTag       ;

    /** XML Tag to define filtering value.. */
      static const CATUnicodeString cFilteringTag     ;

    /** XML Tag to define class information (Object or attribute). */
      static const CATUnicodeString cClassTag         ;

      /** XML Tag to define status value. */
      static const CATUnicodeString cStatusTag        ;

      /** XML Tag to define version value. */
      static const CATUnicodeString cVersionTag       ;

      /** XML Tag to define isLocked status. */
      static const CATUnicodeString cIsLockedTag      ;

      /** XML Tag to define node is hidden or not. */
      static const CATUnicodeString cIsHiddenTag      ;

      /** XML Tag to define node is sensitive or not (view have to be recomputed when set). */
      static const CATUnicodeString cIsSensitiveTag   ;

      /** XML Tag to define node is Inactive or not. */
      static const CATUnicodeString cIsInactiveTag    ;

      /** XML Tag to define node is deleted or not. */
      static const CATUnicodeString cIsDeletedTag    ;

      /** XML Tag to define node is considered as private data or not. */
      static const CATUnicodeString cIsPrivateTag    ;

      /** XML Tag to define encoding mode in case of private data. */
      static const CATUnicodeString  cEncodingTag       ;

      /** XML Tag to define alias name (NLS string). */
      static const CATUnicodeString cAliasTag         ;

      /** XML Tag to define operation. */
      static const CATUnicodeString cOperationTag     ;

      /** XML Tag to define Properties. */
      static const CATUnicodeString cPropertyTag      ;

      /** XML Tag to define From Relationship. */
      static const CATUnicodeString cFromTag          ;

      /** XML Tag to define To Relationship. */
      static const CATUnicodeString cToTag            ;

      /** XML Tag for node name. */
      static const CATUnicodeString  cObjectTag         ;
      static const CATUnicodeString  cBaseObjectTag     ;
      static const CATUnicodeString  cMappingTag        ;
      static const CATUnicodeString  cAttributeTag      ;
      static const CATUnicodeString  cClassAttributeTag ;
      static const CATUnicodeString  cClassObjectTag    ;
      static const CATUnicodeString  cNotificationTag   ;
      static const CATUnicodeString  cBasicMetricTag    ;
      static const CATUnicodeString  cMetricTag         ;
      static const CATUnicodeString  cEngineTag         ;
      static const CATUnicodeString  cDataSourceTag     ;
      static const CATUnicodeString  cSetTag            ;
      static const CATUnicodeString  cOptionSetTag      ;
      static const CATUnicodeString  cNodeTag           ;
      static const CATUnicodeString  cOptionTag         ;
      static const CATUnicodeString  cExecutionTag      ;
      static const CATUnicodeString  cTransactionTag    ;
      static const CATUnicodeString  cEnumTag           ;
      static const CATUnicodeString  cDataTag           ;

      /** XML Tag for attribute value type. */
      static const CATUnicodeString cBooleanTag    ;
      static const CATUnicodeString cIntegerTag    ;
      static const CATUnicodeString cFloatTag      ;
      static const CATUnicodeString cStringTag     ;
      static const CATUnicodeString cBinaryTag     ;
      static const CATUnicodeString cDateTag       ;
      static const CATUnicodeString cTimeStampTag  ;
      static const CATUnicodeString cFileNameTag   ;
      static const CATUnicodeString cFolderPathTag ;
      static const CATUnicodeString cNlsStringTag  ;

      /** XML Tag for managing transaction operations. */
      static const CATUnicodeString cDeleteTag     ;
      static const CATUnicodeString cCreateTag     ;
      static const CATUnicodeString cModifyTag     ;
      static const CATUnicodeString cChangeSetTag  ;

      /** Manage persistent session on disk (through transaction management). */
      static const CATUnicodeString cSaveSeparator ;
      static const CATUnicodeString cXmlExtension  ;
      static const CATUnicodeString cJsonExtension ;

      /** XML Tag for attribute value type. */
      static const CATUnicodeString cUnknownTag   ;
      static const CATUnicodeString cSucceededTag ;
      static const CATUnicodeString cWarningTag   ;
      static const CATUnicodeString cErrorTag     ;
      static const CATUnicodeString cAbortTag     ;

      // --- Stream information into an XML stream

    /**
      * Enable to fill XML write buffer.
      *
      * <br><b>Role</b>: Manage insertion of data in the XML write buffer.
      * 
      * @param iStreamBuffer
      *   XML write buffer.
      * 
      * @param inFileFilter
      *   Streaming option to define what need to be streamed.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int PutToStream( PLMExchangeStreamBuffer & iStreamBuffer , int inFileFilter ) ;

    /**
      * Check if this node needs to be streamed.
      *
      * <br><b>Role</b>: Checks if this node needs to be streamed, gets XML node name and if sub-node need to be wrote.
      * 
      * @param inFileFilter
      *   Streaming option to define what need to be streamed.
      * 
      * @param ocXmlNodeName
      *   XML Node name to be used.
      * 
      * @return
      *  Returns XML streaming mode: 
      * <br><b>Legal values</b>: 
      * <dl>
      * <dt>0</dt>  <dd>if node not to be traversed by streaming.</dd>
      * <dt>1</dt>  <dd>case of a node to be streamed without sub-XML nodes.</dd>
      * <dt>2</dt>  <dd>case of a node to be streamed with sub-XML nodes.</dd>
      * </dl>: 
      */
      virtual int IsValidForPutToStream( int inFileFilter , CATUnicodeString & ocXmlNodeName ) const ;

    /**
      * Check if node needs to be streamed.
      *
      * <br><b>Role</b>: Checks if this node needs to be streamed according properties and current reporting filter.
      * 
      * @param inFileFilter
      *   Streaming option to define what need to be streamed.
      * 
      * @return
      *  Returns XML streaming mode: 
      * <br><b>Legal values</b>: 
      * <dl>
      * <dt>0</dt>  <dd>if node not to be traversed by streaming.</dd>
      * <dt>1</dt>  <dd>case of a node to be streamed without sub-XML nodes.</dd>
      * <dt>2</dt>  <dd>case of a node to be streamed with sub-XML nodes.</dd>
      * </dl>: 
      */
      virtual int IsValidForPutToStream( int inFileFilter ) const ;
      
    /**
      * Fill attribute to stream.
      *
      * <br><b>Role</b>: Add in the write buffer attributes.
      * 
      * @param iStreamBuffer
      *   Write buffer.
      * 
      * @param inFileFilter
      *   Streaming option to define what need to be streamed.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int PutAttributeToStream( PLMExchangeStreamBuffer & iStreamBuffer , int inFileFilter ) ;

    /**
      * Fill XML sub-nodes of node.
      *
      * <br><b>Role</b>: Add XML sub-nodes in XML write buffer XML attributes.
      * 
      * @param iStreamBuffer
      *   Write buffer.
      * 
      * @param inFileFilter
      *   Streaming option to define what need to be streamed.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int PutNodeToStream( PLMExchangeStreamBuffer & iStreamBuffer , int inFileFilter ) ;

    /**
      * Enables to decode XML stream.
      *
      * <br><b>Role</b>: Decode XML node associated to this instance of object.
      * 
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>0</dt> <dd>if operation are executed without any errors.</dd>
      * <dt>1</dt> <dd>otherwise.</dd>
      * </dl>
      * 
      * @param icTag
      *   XML Attribute tag.
      * 
      * @param icValue
      *   XML Attribute value.
      */
      virtual int GetFromStream( const CATUnicodeString & icTag , CATUnicodeString & icValue  ) ;

   // -------------------------------------
   // --- Manage attribute value type   ---
   // -------------------------------------

   protected:
    /** 
      * Update attribute type from string tag.
      *
      * <br><b>Role</b>: Update attribute type in property value ).
      * 
      * @param iusTypeTag [in]
      *  String associated with this attribute type.
      * 
      * @param ionNodeProperty [out]
      *   Property.
      */
      static void _getTypeTagFromType( const CATUnicodeString & iusTypeTag , int & ionNodeProperty ) ;

    /**
      * Sets attribute value type.
      *
      * <br><b>Role</b>: Sets attribute value type among authorized ones.
      * 
      * @param inValueType
      *   Attribute value Type.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>PLMExchangeUnknownAttribute</dt>     <dd>Value type not defined<</dd>
      *  <dt>PLMExchangeBooleanAttribute</dt>     <dd>Boolean value</dd>
      *  <dt>PLMExchangeIntegerAttribute</dt>     <dd>Integer value</dd>
      *  <dt>PLMExchangeFloatAttribute</dt>       <dd>Floating point value</dd>
      *  <dt>PLMExchangeStringAttribute</dt>      <dd>Character string value</dd>
      *  <dt>PLMExchangeBinaryAttribute</dt>      <dd>Binary string value</dd>
      *  <dt>PLMExchangeDateAttribute</dt>        <dd>Date value</dd>
      *  <dt>PLMExchangeBinaryTSAttribute</dt>    <dd>Binary TS value</dd>
      *  <dt>PLMExchangeFileNameAttribute</dt>    <dd>File name value</dd>
      *  <dt>PLMExchangeFolderPathAttribute</dt>  <dd>File folder value</dd>
      *  <dt>PLMExchangeObjectAttribute</dt>      <dd>Object value</dd>
      *  <dt>PLMExchangeNlsStringAttribute</dt>   <dd>NLS string value</dd>
      *  <dt>PLMExchangeNodeAttribute</dt>        <dd>Reference a Node in the Exchange Model</dd>
      *  </dl>
      * 
      * @param ionNodeProperty [out]
      *   Property.
      * 
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Type recognized.</dd>
      * <dt>E_FAIL</dt>  <dd>otherwise and type is set to PLMExchangeStringAttribute.</dd>
      * </dl>
      */
      static HRESULT _setValueType( int inValueType , int & ionNodeProperty ) ;

    /**
      * Sets attribute value type.
      *
      * <br><b>Role</b>: Sets attribute value type among authorized ones.
      * 
      * @param inValueType
      *   Attribute value Type.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>PLMExchangeUnknownAttribute</dt>     <dd>Value type not defined<</dd>
      *  <dt>PLMExchangeBooleanAttribute</dt>     <dd>Boolean value</dd>
      *  <dt>PLMExchangeIntegerAttribute</dt>     <dd>Integer value</dd>
      *  <dt>PLMExchangeFloatAttribute</dt>       <dd>Floating point value</dd>
      *  <dt>PLMExchangeStringAttribute</dt>      <dd>Character string value</dd>
      *  <dt>PLMExchangeBinaryAttribute</dt>      <dd>Binary string value</dd>
      *  <dt>PLMExchangeDateAttribute</dt>        <dd>Date value</dd>
      *  <dt>PLMExchangeBinaryTSAttribute</dt>    <dd>Binary TS value</dd>
      *  <dt>PLMExchangeFileNameAttribute</dt>    <dd>File name value</dd>
      *  <dt>PLMExchangeFolderPathAttribute</dt>  <dd>File folder value</dd>
      *  <dt>PLMExchangeObjectAttribute</dt>      <dd>Object value</dd>
      *  <dt>PLMExchangeNlsStringAttribute</dt>   <dd>NLS string value</dd>
      *  <dt>PLMExchangeNodeAttribute</dt>        <dd>Reference a Node in the Exchange Model</dd>
      *  </dl>
      * 
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Type recognized.</dd>
      * <dt>E_FAIL</dt>  <dd>otherwise and type is set to PLMExchangeStringAttribute.</dd>
      * </dl>
      */
      HRESULT _setValueType( int inValueType ) ;

    /**
      * Gets attribute value type.
      *
      * <br><b>Role</b>: Gets attribute value type among authorized ones.
      * 
      * @return
      *   Attribute value Type.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>PLMExchangeUnknownAttribute</dt>     <dd>Value type not defined<</dd>
      *  <dt>PLMExchangeBooleanAttribute</dt>     <dd>Boolean value</dd>
      *  <dt>PLMExchangeIntegerAttribute</dt>     <dd>Integer value</dd>
      *  <dt>PLMExchangeFloatAttribute</dt>       <dd>Floating point value</dd>
      *  <dt>PLMExchangeStringAttribute</dt>      <dd>Character string value</dd>
      *  <dt>PLMExchangeBinaryAttribute</dt>      <dd>Binary string value</dd>
      *  <dt>PLMExchangeDateAttribute</dt>        <dd>Date value</dd>
      *  <dt>PLMExchangeBinaryTSAttribute</dt>    <dd>Binary TS value</dd>
      *  <dt>PLMExchangeFileNameAttribute</dt>    <dd>File name value</dd>
      *  <dt>PLMExchangeFolderPathAttribute</dt>  <dd>File folder value</dd>
      *  <dt>PLMExchangeObjectAttribute</dt>      <dd>Object value</dd>
      *  <dt>PLMExchangeNlsStringAttribute</dt>   <dd>NLS string value</dd>
      *  <dt>PLMExchangeNodeAttribute</dt>        <dd>Reference a Node in the Exchange Model</dd>
      *  </dl>
      */
      int _getValueType() const ;


    /** 
      * Set flag area with type information.
      *
      * <br><b>Role</b>: Set flag area with type information to identify if hierachical structure contains one node type object.
      */
      void _valuateFlagWithTypeInfo() ;

    /**
      * Enable to traverse node structure to fill write buffer.
      *
      * <br><b>Role</b>: Enable to traverse node structure to fill write buffer.
      * 
      * @param iStreamBuffer
      *   XML write buffer.
      * 
      * @param inStreamingMode
      *   streaming mode:
      * <dl>
      * <dt>0</dt>  <dd>if node not to be traversed by streaming.</dd>
      * <dt>1</dt>  <dd>case of a node to be streamed without sub-nodes.</dd>
      * <dt>2</dt>  <dd>case of a node to be streamed with sub-nodes.</dd>
      * </dl>: 
      * 
      * @param iusNodeName
      *   XML Node name to be used.
      * 
      * @param inFileFilter
      *   Streaming option to define what need to be streamed.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int _putToStream( PLMExchangeStreamBuffer & iStreamBuffer
                              , int                       inStreamingMode
                              , CATUnicodeString        & iusNodeName
                              , int                       inFileFilter ) ;

} ;
#endif
