//=======================================================================================
//** WARNING: YWE 19:02:25 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//=======================================================================================
#ifndef  PLMExchangeTransaction_h
#define  PLMExchangeTransaction_h
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
//    Class that to support transaction management on exchange Model.
//
// *****************************************************************
//
//   Remarks :
//   ---------
//
//
// ****************************************************************
//
//   Story :
//   -------
//
//   Revision 1.0  March     2007  (JLM) Initial Revision from ENORepNode
//   Revision 2.0  December  2012  (JLM) Duplication to implement Exchange Experience Model 
//   Revision 2.1  September 2015  (JLM) Manage multi-load by Delta 
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
// --- * Mother class

#include "PLMExchangeModel.h"
#include "PLMExchangeBasicNode.h"

// --- * System framework

#include "CATHashTable.h"

// --- Class definition

/**
  * Class representing a transaction manager.
  *
  * <b>Role</b>:
  * Define the transaction manager of an Exchange model.
  * Several transaction managers could be defined in the same process and Node under one transaction manager is one its direct or indirect children.
  */
class ExportedByPLMExchangeModel PLMExchangeTransaction : public PLMExchangeBasicNode
{
   public:

    /**
      * Constructs one Transaction.
      * 
      * @param ixFather
      *   Father node that aggregates node to be created.
      */
      PLMExchangeTransaction( PLMExchangeBasicNode * ixFather = NULL ) ;          

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      ~PLMExchangeTransaction() ;

    /**
      * Copy constructor.
      * 
      * @param iNode
      * Object to be duplicated.
      */
      PLMExchangeTransaction( const PLMExchangeTransaction & iNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param iNode
      * Object used as reference for the assignment.
      */
      PLMExchangeTransaction & operator=( const PLMExchangeTransaction & iNode ) ;

      // -----------------------------------------
      // --- Access to Node information        ---
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
      int GetType() const ;

      // ---------------------------------------------------
      // ---  Manage current Exchange Model  content     ---
      // ---------------------------------------------------

    /** 
      * Get number of allocated objects.
      *
      * <br><b>Role</b>: Get number of allocated object. Mainly dedicated to debug function.
      * 
      * @return
      *  Returns number of allocated object.
      */
      int GetNumberOfNodesInSession() const ;

    /** 
      * Allocate a new node in current sesion.
      *
      * <br><b>Role</b>: Allocate a new node in current sesion and generate a local Id.
      * 
      * @return
      *  Returns new Instance Id.
      */
      int AddNewInstance() ;

    /** 
      * Remove one instance node Get number of allocated objects.
      *
      * <br><b>Role</b>: Remove one instance node Get number of allocated objects.
      * 
      * @param ixNode
      *   Node that will be removed.
      * 
      * @return
      *  Returns number of instance in the current transaction (ie not deleted ones).
      */
      int RemoveInstance( PLMExchangeBasicNode * ixNode ) ;

      // -------------------------------------------
      // ---  Access to Transacfion information  ---
      // -------------------------------------------

    /**
      * Gets current transaction state.
      *
      * <br><b>Role</b>: Gets current transaction state.
      *
      * @return
      *   Transaction state.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>PLMExchangeTransactionNotActivated</dt> <dd>No transaction has been ever opened.</dd>
      *    <dt>PLMExchangeTransactionOpen</dt>         <dd>Transaction open.</dd>
      *    <dt>PLMExchangeTransactionClose</dt>        <dd>Transaction close.</dd>
      *    </dl>
      */
      int GetTransactionState() const ;

    /**
      * Gets transaction number.
      *
      * <br><b>Role</b>: Gets transaction number.
      *
      * @return
      *   Return transaction number.
      *    </dl>
      */
      int GetTransactionOrder() const ;

      // -----------------------------------------
      // --- Transaction management            ---
      // -----------------------------------------

    /**
      * Create a new transaction.
      *
      * <br><b>Role</b>:  Create a new transaction.
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
      * @param ilDispatch
      *   For future use.
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
      HRESULT CloseTransaction( int ilDispatch = 0 ) ;

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
      * @param ixModifiedNode
      *   Modified PLMExchangeBasicNode.
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
      HRESULT RegisterTransactionEvent( int inOperation , PLMExchangeBasicNode * ixModifiedNode ) ;

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
      HRESULT StopEventRecording() ;

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
      HRESULT ActivateEventRecording() ;

    /**
      * Transaction Event iterator.
      *
      * <br><b>Role</b>: Enable to scan list of event record for the transaction.
      */
      struct ExportedByPLMExchangeModel PLMExchangeEventTransactionIterator
      {      
         public:
            PLMExchangeEventTransactionIterator() ;
            
            void Init() ;
    
            int _nBucket ;
            int _nPos    ;
      } ;

    /**
      * Access to transaction events.
      *
      * <br><b>Role</b>: Enable through
      * 
      * @param ioIterator [in out]
      *   Iterator of transaction events.
      * 
      * @param onOperationNumber [out]
      *   Modification number.
      * 
      * @param onOperationType [out]
      *   Types of modification applied on this object using a mask of bit.
      * 
      * <br><b>Legal values</b>: list of basic types of transaction events:
      * <dl>
      * <dt>PLMExchangeUnknownEvent</dt>        <dd>No event to log.</dd>
      * <dt>PLMExchangeCreateEvent</dt>         <dd>Creation.</dd>
      * <dt>PLMExchangeModifyDataEvent</dt>     <dd>Modification.</dd>
      * <dt>PLMExchangeDeleteEvent</dt>         <dd>Deletion.</dd>
      * <dt>PLMExchangeSelectEvent</dt>         <dd>Selection.</dd>
      * <dt>PLMExchangeModifyPropertyEvent</dt> <dd>Property modification.</dd>
      * </dl>
      * 
      * @param oxNode [out]
      *   PLMExchangeBasicNode impacted.
      * 
      * @return
      * Returns error code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Next event successfully recovered.</dd>
      * <dt>S_FALSE</dt> <dd>No more event to analyzed.</dd>
      * <dt>E_FAIL</dt>  <dd>Error during transaction event scan.</dd>
      * </dl>
      */
      HRESULT GetNextEvent( PLMExchangeEventTransactionIterator & ioIterator 
                          , int                                 & onOperationNumber
                          , int                                 & onOperationType
                          , PLMExchangeNode                    *& oxNode           ) ;

      // -------------------------------------------
      // --- Manage partial save on Transaction  ---
      // -------------------------------------------

    /**
      * Activate session recording at each transaction.
      *
      * <br><b>Role</b>: Enable to capture session content with an update at each transaction close. 
      * First call to this method will force the streaming of session, after each transaction close will stream only session delta.
      * 
      * @param icSaveFolder [in]
      *   Folder path where each session delta will be streamed (XML streaming).
      * 
      * @param icFileNamePrefix [in]
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
      HRESULT SetTransactionSaveInformation( const CATUnicodeString & icSaveFolder 
                                           , const CATUnicodeString & icFileNamePrefix ) ;

    /**
      * Get access to partial save information.
      *
      * <br><b>Role</b>: Get accces of capture session paramters. 
      * 
      * @param ocSaveFolder [out]
      *   Folder path where each session delta will be streamed (XML streaming).
      * 
      * @param ocFileNamePrefix [out]
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
      HRESULT GetTransactionSaveInformation( CATUnicodeString & ocSaveFolder 
                                           , CATUnicodeString & ocFileNamePrefix ) ;

    /**
      * Remove all delta save files.
      *
      * <br><b>Role</b>: Remove all delta save files.
      * 
      * @param icSaveFolder [in]
      *   Folder path where each session delta will be streamed (XML streaming).
      * 
      * @param icFileNamePrefix [in]
      *   File name prefix to name the session stream at each transaction close.
      * 
      * @return
      * Returns error code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Partial save cleaning correctly executed.</dd>
      * <dt>E_FAIL</dt>  <dd>Partial save cleaning could not be executed.</dd>
      * </dl>
      */
      static HRESULT CleanPartialSaveFiles( const CATUnicodeString & icSaveFolder 
                                          , const CATUnicodeString & icFileNamePrefix ) ;

      // ------------------------------------------------------
      // --- Services to manage Node Id access by hash list ---
      // ------------------------------------------------------

    /**
      * Fill Node Id hash list.
      *
      * <br><b>Role</b>: Fill Node Id hash list traversing the provided node structure.
      * 
      * @param inInitMode [in]
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
      * <dt>S_OK</dt>    <dd>If Node Id hash list successfuly created & filled.</dd>
      * <dt>S_FALSE</dt> <dd>If Node Id hash list successfuly created empty.</dd>
      * <dt>E_FAIL</dt>  <dd>otherwise.</dd>
      * </dl>
      */
      HRESULT InitIdHashList( int inInitMode = PLMExchangeLoadingMode_Full ) ;

    /**
      * Empty & Freed Node Id hash list.
      *
      * <br><b>Role</b>: Empty & Freed Node Id hash list.
      * 
      * @param inInitMode [in]
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
      * <dt>S_OK</dt>    <dd>if Hash list has been successfuly freed.</dd>
      * <dt>S_FALSE</dt> <dd>Hash list has not been allocated.</dd>
      * <dt>E_FAIL</dt>  <dd>otherwise.</dd>
      * </dl>
      */
      HRESULT FreedIdHashList( int inInitMode = PLMExchangeLoadingMode_Full ) ;

    /**
      * Search a node by its Node Id.
      *
      * <br><b>Role</b>: Search a node by its Node Id.
      * 
      * @param inInstanceId
      *   Instance Id read.
      * 
      * @param oxNode
      *   PLMExchangeBasicNode founds (NULL is Node id is not hash list).
      * 
      * @param ilCreate
      *   if not null, we create a PLMExchangeBasicNode marked as dummy if PLMExchangeBasicNode not found by its Node Id.
      * 
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>If Node found by its Node Id.</dd>
      * <dt>S_FALSE</dt> <dd>No Node found with this Node Id.</dd>
      * <dt>E_FAIL</dt>  <dd>otherwise.</dd>
      * </dl>
      */
      HRESULT SearchOneNodeId( int inInstanceId , PLMExchangeNode * & oxNode , int ilCreate = 0 ) ;

    /**
      * Remove one node from Node Id hash-list.
      *
      * <br><b>Role</b>: Remove one node from Node Id hash-list.
      * 
      * @param ixNode
      *   PLMExchangeBasicNode founds (NULL is Node id is not hash list).
      * 
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>If Node found and removed from Node Id hash-list.</dd>
      * <dt>S_FALSE</dt> <dd>Node not found in the Node Id hash-list.</dd>
      * <dt>E_FAIL</dt>  <dd>otherwise.</dd>
      * </dl>
      */
      HRESULT RemoveFromNodeIdList( PLMExchangeNode * ixNode ) ;

    /**
      * Insert or replace node is node Id Hash list.
      *
      * <br><b>Role</b>: Insert or replace node is node Id Hash list.
      * 
      * @param inInstanceId
      *   Instance Id read.
      * 
      * @param ioxNode
      *   PLMExchangeBasicNode.
      * 
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>if operation are executed without any errors.</dd>
      * <dt>S_FALSE</dt> <dd>Input parameter are inconsistent or Node Id hash-list not allocated.</dd>
      * <dt>E_FAIL</dt>  <dd>otherwise.</dd>
      * </dl>
      */
      HRESULT ReplaceOneNodeId( int inInstanceId , PLMExchangeNode * ixNode ) ;

      // -----------------------------------------------
      // --- To support XML streaming                ---
      // -----------------------------------------------

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
      int PutToStream( PLMExchangeStreamBuffer & iStreamBuffer , int inFileFilter ) ;

      // --- Unstream information from an XML stream

    /**
      * Enables to decode XML stream.
      *
      * <br><b>Role</b>: Decode XML node associated to this instance of object.
      * 
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <ul>
      * <li><tt>0</tt> if operation are executed without any errors.
      * <li><tt>1</tt> otherwise.
      * </ul>
      * 
      * @param icTag
      *   XML Attribute tag.
      * 
      * @param icValue
      *   XML Attribute value.
      */
      int GetFromStream( const CATUnicodeString & icTag , CATUnicodeString & icValue  ) ;

      // --- Stream information into an XML stream

    /**
      * Check if this node need to be streamed.
      *
      * <br><b>Role</b>: Check if this node need to be streamed. and Get XML node name.
      * 
      * @param inFileFilter
      *   Streaming option to define what need to be streamed.
      * 
      * @param ocXmlNodeName
      *   XML Node name to be used.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns 0 if node not to be traversed by streaming. 
      */
      int IsValidForPutToStream( int inFileFilter , CATUnicodeString & ocXmlNodeName ) const ;
      
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
      int PutAttributeToStream( PLMExchangeStreamBuffer & iStreamBuffer , int inFileFilter ) ;

      // --- Print attribute identity card

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
      void _print( const char * const icInput , const char * const icType , int inMode = 0 ) const ;

    protected :

    /**
      * Structure use to manage PLMExchangeBasicNode modification operation.
      */
      struct PLMExchangeNodeTransactionOperation
      {
      /** Modification number. */
         int                    _nOperationNumber ;

      /** Modification applied. */
         int                    _nOperationType   ;

      /** PLMExchangeNode modified. */
         PLMExchangeBasicNode * _xNode            ;

         /*PLMExchangeNodeTransactionOperation( int inTransactionOrder ) 
            : _nOperationNumber(inTransactionOrder) 
            , _xNode(NULL) 
            , _nOperationType(PLMExchangeTransactionNotActivated) {} ;*/
      } ;

      // --- Member definition
      // --- * _nInstanceCounter           Number of PLMExchangeBasicNode created in this process.
      // --- * _nInstanceInSession         Number of PLMExchangeBasicNode remaining allocated.
      // --- * _nDebugMask                 Debug trace mask.
      // --- * _nDebugLevel                Debug trace level.
      // --- * _nTransactionOrder          Define transaction number.
      // --- * _nTransactionStatus         Define transaction state.
      // --- * _nTransactionNextOperation  Next operation to be logged in transaction table.
      // --- * _OperationsTable            Hash table dedicated to acccess to object modify in current transaction.
      // --- * _cTransactionSaveFolder     Folder path where each session delta will be streamed (XML streaming).
      // --- * _cTransactionPrefix         File name prefix to name the session stream at each transaction close.
      // --- * _xNodeIdAccess              Hash table that could be used as a correspondance table during XML loading from Node Id to PLMExchangeNode.

      // --- * To manage object in session

      /** Number of PLMExchangeBasicNode created in this process. */
      int              _nInstanceCounter          ;

      /** Number of PLMExchangeBasicNode remaining allocated. */
      int              _nInstanceInSession        ;

      /** Debug trace mask. */
      int              _nDebugMask                ;

      /** Debug trace level.*/
      int              _nDebugLevel               ;

      /** Transaction number. */
      int              _nTransactionOrder         ;

      /**  Transaction state. */
      int              _nTransactionStatus        ;

      /**  Next operation to be logged in transaction table. */
      int              _nTransactionNextOperation ;

      /** Hash table dedicated to access to object modify in current transaction. */
      CATHashTable     _OperationsTable           ;

      /** Folder path where each session delta will be streamed (XML streaming). */
      CATUnicodeString _cTransactionSaveFolder    ;

      /** File name prefix to name the session stream at each transaction close. */
      CATUnicodeString _cTransactionPrefix        ;

    /** Hash table that could be used as a correspondance table during XML loading from Node Id to PLMExchangeNode. */
      CATHashTable   * _xNodeIdAccess             ;

      // -----------------------------------------------
      // --- To manage Hash list on Operations       ---
      // -----------------------------------------------

    /** 
      * Compute hash key for a PLMExchangeNodeTransactionOperation.
      *
      * <br><b>Role</b>: Compute hash hash key for a PLMExchangeNodeTransactionOperation.
      * 
      * @param ixObject
      *  <b><i>PLMExchangeNodeTransactionOperation</i></b> on which hash key value need to be computed .
      * 
      * @return
      *   Hash key value
      */
      static unsigned int _computeOperationHashKey( const void * ixObject ) ;

    /** 
      * Comparison operator for PLMExchangeNodeTransactionOperation.
      *
      * <br><b>Role</b>: Compare two <b><i>PLMExchangeNodeTransactionOperation</i></b> to know if they are equivalent.
      * 
      * @param ixObject1
      * First <b><i>PLMExchangeNodeTransactionOperation</i></b> for comparison.
      * 
      * @param ixObject2
      * Second <b><i>PLMExchangeNodeTransactionOperation</i></b> for comparison.
      * 
      * @return
      *  0 If the two objects represent the same object
      */
      static int _compareOperation( const void * ixObject1 , const void * ixObject2 ) ;

   protected:
    /** 
      * Compute hash key for a PLMExchangeNode.
      *
      * <br><b>Role</b>: Compute hash hash key for a PLMExchangeNode.
      * 
      * @param ixObject
      *  <b><i>PLMExchangeNode</i></b> on which hash key value need to be computed .
      * 
      * @return
      *   Hash key value
      */
      static unsigned int _computeInstanceIdHashKey( const void * ixObject ) ;

    /** 
      * Comparison operator for PLMExchangeNode.
      *
      * <br><b>Role</b>: Compare two <b><i>PLMExchangeNode</i></b> to know if they are equivalent.
      * 
      * @param ixObject1
      * First <b><i>PLMExchangeNode</i></b> for comparison.
      * 
      * @param ixObject2
      * Second <b><i>PLMExchangeNode</i></b> for comparison.
      * 
      * @return
      *  0 If the two objects represent the same object
      */
      static int _compareSInstanceId( const void * ixObject1 , const void * ixObject2 ) ;

    /**
      * Structure use to manage Node Id at XML loading.
      */
      struct PLMExchangeNodeIdBucket
      {
         /** Previous PLMExchangeNode Id. */
         int               _nNodeId ;

         /** Current PLMExchangeNode in session. */
         PLMExchangeNode * _xNode   ;
      } ;
} ;
#endif
