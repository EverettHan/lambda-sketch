#ifndef  PLMExchangeNode_h
#define  PLMExchangeNode_h
// COPYRIGHT DASSAULT SYSTEMES 2012-2016
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
//    Base class for a simple object hierarchical model.
//
// *****************************************************************
//
//   Remarks :
//   ---------
//
//    Code inspired by ENOVIA V5 Replication component (ENORepNode)
//
// ****************************************************************
//
//   Story :
//   -------
//
//   Revision 1.0  March    2007  (JLM) Initial Revision from ENORepNode
//   Revision 2.0  December 2012  (JLM) Duplication to implement Exchange Experience Model 
//   Revision 2.1  April    2013  (JLM) Introduce transaction capability
//
// ****************************************************************
//
// INSIDE class:
// -------------
//
//
//
// ****************************************************************
// Abstract class    : Yes
// Template code     : No
// Ilined   Function : No
// ****************************************************************

#include <time.h>

// --- List of referenced classes

class PLMExchangeNode              ;
class PLMExchangeTransaction       ;
class CATHashTable                 ;
class CATHashTableMultiple         ;
class CATListValCATUnicodeString   ;
class CATBaseUnknown               ;

// --- Header that need to be referenced

#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATLib.h"

// --- * PLMExchangeModel framework

#include "PLMExchangeModel.h"
#include "PLMExchangeBasicNode.h"
#include "PLMExchangeStreamBuffer.h"

#include "CATLISTPPLMExchangeNode.h"

// --- Class definition

/**
  * Base class to manage instantiable nodes in the Exchange Model.
  *
  * <b>Role</b>:
  * Enable to provide general ExchangeModel services such as Naming, Object id & search, node type.
  */
class ExportedByPLMExchangeModel PLMExchangeNode : public PLMExchangeBasicNode
{
   // --- Authorize PLMExchangeTransaction to access to protected attribute.

   friend class PLMExchangeTransaction ;

   // --- Object constructor

   public:
      
    /**
      * Constructs a generic node object with no name.
      * 
      * @param inType
      *   Node type
      *   <br><b>Legal values</b>: see @href PLMExchangeNode#GetType
      *
      * @param ixFather
      *   Father node that aggregates node to be created.
      *
      * @see PLMExchangeObject , PLMExchangeMetric , PLMExchangeAttribute , PLMExchangeOption ...
      */
      PLMExchangeNode( int                    inType   = PLMExchangeNodeUnknown
                     , PLMExchangeBasicNode * ixFather = NULL ) ;

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      ~PLMExchangeNode() ;

      // --- Copy-constructor

    /**
      * Copy constructor.
      * 
      * @param iNode
      * Object to be duplicated.
      */
      PLMExchangeNode( const PLMExchangeNode & iNode ) ;

      // --- Equal operator

    /**
      * Assignment operator from another object node.
      * 
      * @param iNode
      * Object used as reference for the assignment.
      */
      PLMExchangeNode & operator=( const PLMExchangeNode & iNode ) ;

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
      int GetType() const ;

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
      const CATUnicodeString & GetName() const ;

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
      HRESULT GetInstanceId( int & onId ) const ;

    /**
      * Sets the node name.
      *
      * <br><b>Role</b>: Sets the instance id.
      *
      * @return
      * Returns error code
      *
      * @param icName
      * Node name.
      */
      HRESULT SetName( const CATUnicodeString & icName ) ;

    /**
      * Search object by its Oid.
      *
      * <br><b>Role</b>: Search the first object found having a certain Oid.
      *
      * @param icOid [in]
      *   Object Oid.
      *
      * @return
      *   Object or NULL.
      */
      PLMExchangeNode * SearchByOid( const CATString & icOid ) const ;

    /**
      * Search Node by Oid.
      *
      * <br><b>Role</b>: Search Node having a specific Oid.
      *
      * @return
      *  Returns error code
      *
      * @param inInTypeNode
      * Defines the type node you want to query on.
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
      * </dl>
      * 
      * @param icOid
      *   Object Oid.
      *
      * @param oxResultList
      *  List of PLMExchangeNode with specified Oid.
      * 
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>At least one object found by Oid & Type.</dd>
      * <dt>S_FALSE</dt> <dd>No object found with type & oid criteria.</dd>
      * <dt>E_FAIL</dt>  <dd>One error raised during this operation.</dd>
      * </dl>
      */
      HRESULT SearchByOid( int inInTypeNode , const CATString & icOid , CATListOfPLMExchangeNode & oxResultList ) const ;

    /**
      * Install Oid access.
      *
      * <br><b>Role</b>: Search one object by its Oid.
      *
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int InitOidAccess() ;
      
      // -------------------------------------------
      // --- Access to underlying application object
      // -------------------------------------------

    /**
      * Gets underlying application object.
      *
      * <b>Role:</b> Gets underlying application object.
      * 
      * <br><b>Postcondition</b>: Interface to be released by the caller.
      *
      * @param opAppliObject [out, CATBaseUnknown#Release]
      *  Application object.
      *
      * @return
      * Method return code 
      * <br><b>Legal values</b>: 
      Returns <b><i>S_OK</i></b> if operation runs well. 
      * <dl>
      * <dt>S_OK</dt>         <dd>if one object is associated.</dd>
      * <dt>S_FALSE</dt>      <dd>if no object is associated.</dd>
      * <dt>E_FAIL</dt>       <dd>In case of error.</dd>
      * </dl>
      */
      HRESULT GetApplicationObject( CATBaseUnknown ** opAppliObject ) const ;

    /**
      *  Captures underlying application object.
      *
      * <b>Role:</b> Captures underlying application object.
      *
      * @param ipAppliObject
      *  Application object.
      *
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns <b><i>S_OK</i></b> if operation runs well. 
      */
      HRESULT SetApplicationObject( CATBaseUnknown * ipAppliObject ) ;

      // -----------------------------------------
      // --- Operator to manage tree structure ---
      // -----------------------------------------

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
      PLMExchangeNode * ScanChildren( const PLMExchangeNode * const ixPrevious ) const ;

    /**
      * Gets next child of a defined type.
      *
      * <br><b>Role</b>: Scans the list of children having a defined type.
      * 
      * @return
      * Next child object node. 
      * <br>Return <tt>NULL</tt> if <tt>ixPrevious</tt> is not a child of current node 
      * or if it is the last child
      * 
      * @param inInTypeNode
      * Defines the type node you want to query on.
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
      * </dl>
      * 
      * @param ixPrevious
      * Current child object.
      * <br><b>Legal values</b>:
      * <ul>
      * <li><tt>NULL</tt> to get the first child</li>
      * <ul/>
      */
      PLMExchangeNode * ScanChildren( int inInTypeNode , const PLMExchangeNode * const ixPrevious ) const ;

    /**
      * Gets next child of a defined type having a predefined name.
      *
      * <br><b>Role</b>: Gets next child of a defined type having a predefined name.
      * 
      * @return
      * Next child object node. 
      * <br>Return <tt>NULL</tt> if <tt>ixPrevious</tt> is not a child of current node 
      * or if it is the last child
      * 
      * @param inInTypeNode
      * Defines the type node you want to query on.
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
      * </dl>
      * 
      * @param icName
      * Name of the object we are looking for.
      * 
      * @param ixPrevious
      * Current child object.
      * <br><b>Legal values</b>:
      * <ul>
      * <li><tt>NULL</tt> to get the first child</li>
      * <ul/>
      */
      PLMExchangeNode * ScanChildrenByName( int inInTypeNode , const CATUnicodeString & icName , const PLMExchangeNode * const ixPrevious ) const ;

    /**
      * Gets next child in the node tree.
      *
      * <br><b>Role</b>: Scans node structure tree (in depth first).
      * 
      * @return
      * Next child object node. 
      * <br>Return <tt>NULL</tt> if <tt>ixPrevious</tt> is not a child of current node 
      * or if it is the last child
      * 
      * @param inInTypeNode
      * Defines the type node you want to query on.
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
      * </dl>
      * 
      * @param ixPrevious
      * Current child object.
      * <br><b>Legal values</b>:
      * <ul>
      * <li><tt>NULL</tt> To get the root of the structure (the <b><i>PLMExchangeNode</b></i> itself) and 
      * depth level is initialized to 0.</li>
      * <ul/>
      * 
      * @param ionUpDown 
      * Level of depth on the <b><i>PLMExchangeInstance</b></i>.
      * This value is initialized to 0 when full assembly scan is done or when scan is initialized (NULL value for <b>ixPrevious</b>).
      * Otherwise computed by incrementation or decrementation of the input value.
      * 
      */
      PLMExchangeNode * ScanTree( int inInTypeNode , PLMExchangeNode * ixPrevious , int & ionUpDown ) const ;

      // --------------------------------------------------
      // --- General declaration for Experience model.
      // --------------------------------------------------

    /** 
      * List of object type recognized.
      */
      enum PLMExchangeObjectType
      {
        PLMExchangeObjectType_Unknown        =  0   // --- Not defined
      , PLMExchangeObjectType_Reference      =  1   // --- Reference
      , PLMExchangeObjectType_Port           =  2   // --- Port
      , PLMExchangeObjectType_Connection     =  3   // --- Connection
      , PLMExchangeObjectType_Instance       =  4   // --- Instance
      , PLMExchangeObjectType_Representation =  5   // --- Representation
      , PLMExchangeObjectType_RepInstance    =  6   // --- Representation Instance
      , PLMExchangeObjectType_Entity         =  7   // --- Entity
      , PLMExchangeObjectType_Relation       =  8   // --- Relation
      } ;

      // --------------------------------------------------
      // --- Order node according name in model hierarchy.
      // --------------------------------------------------

    /**
      *  Compare two PLMExchangeNode (Quicksort).
      *
      * <br><b>Role</b>: Compare two PLMExchangeNode to use <b><i>qsort</i></b> function (Quick Sort).
      *
      * @return
      *   Comparison result. 
      *
      * <br><b>Legal values</b>: It can be set to either:
      * <dl>
      * <dt>0</dt>        <dd>If the 2 <b><i>PLMExchangeNode</i></b> are considered as equal (same name).</dd>
      * <dt>Negative</dt> <dd>If first <b><i>PLMExchangeNode</i></b> is considered as less than second one.</dd>
      * <dt>Positive</dt> <dd>If first <b><i>PLMExchangeNode</i></b> is considered as greater than second one.</dd>
      * </dl>
      *
      * @param ixNode1
      *  First <b><i>PLMExchangeNode</i></b>.
      *
      * @param ixNode2
      *  Second <b><i>PLMExchangeNode</i></b>.
      */
      static int CompareNode( const void * ixNode1 , const void * ixNode2 ) ;

    /** 
      * Order direct children.
      *
      * <br><b>Role</b>: Order direct children according ascending name order.
      */
      void OrderDirectChildren() ;

    /** 
      * Order complete sub-tree bellow this node.
      *
      * <br><b>Role</b>: Order complete sub-tree based on ascending name order level by level.
      */
      void OrderTree() ;

      // -----------------------------
      // --- To manage object usage
      // -----------------------------

    /** 
      * Add usage by one object.
      *
      * <br><b>Role</b>: Decreases object counter.
      * 
      * @param ixReferencing
      * Object referencing.
      * @return
      *   0 if Ok
      */
      int AddOneObjectUsage( PLMExchangeNode * ixReferencing ) ;

    /** 
      * Suppress one object usage.
      *
      * <br><b>Role</b>: Increases object counter.
      * 
      * @param ixReferencing
      * Object referencing.
      * 
      * @return
      *   0 if Ok
      */
      int SuppressObjectUsage( PLMExchangeNode * ixReferencing ) ;

    /** 
      * Gets object counter.
      *
      * <br><b>Role</b>: Gets object counter.
      * 
      * @return
      *  Object usage (not taking hierarchical structure)
      * 
      * @param inObjectType
      * Object type researched in child list. <b><i>PLMExchangeNodeUnknown</i></b> is the default value if attribute not proposed
      * and this case result will consider any objects what ever its type are.
      */
      int GetObjectCounter( int inObjectType = PLMExchangeNodeUnknown ) const ;

    /** 
      * Gets object referencing.
      *
      * <br><b>Role</b>: Gets object referencing this current <b><i>PLMExchangeNode</i></b>.
      * 
      * @return
      *  Object referencing this <b><i>PLMExchangeNodeUnknown</i></b>.
      * 
      * @param inObject
      * Iterator.
      */
      PLMExchangeNode * GetUsageObject( int inObject ) const ;

    /** 
      * Get list of objects referencing the current object.
      *
      * <br><b>Role</b>: Get list of objects referencing the current object.
      * 
      * @return
      *  Number of objects in the list.
      * 
      * @param inObjectType
      * Object type researched in child list. <b><i>PLMExchangeNodeUnknown</i></b> is the default value if attribute not proposed
      * and this case result will consider any objects what ever its type are.
      * 
      * @param oLstNode
      * List of objects.
      */
      int GetUsageObjectByType( int inObjectType , CATListOfPLMExchangeNode & oLstNode ) const ;

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
      * Gets children of a PLMExchangeNode.
      *
      * <br><b>Role</b>: Gets children of a PLMExchangeNode.
      *
      * @param inInTypeNode
      * Defines the type node you want to query on.
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
      * </dl>
      * 
      * @return
      *  List of Nodes.
      */
      CATListOfPLMExchangeNode * GetChildren( int inInTypeNode ) const ;

	  /** 
      * Gets number of children of a PLMExchangeNode.
      *
      * <br><b>Role</b>: Gets children's number of a PLMExchangeNode.
      *
      * @param inInTypeNode
      * Defines the type node you want to query on.
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
      * </dl>
      * 
	  * @param inRecursive
      * Specifies if the count will include indirect children or not.
      * @return
      *  Counter of children.
      */
      int GetChildrenCount( int inInTypeNode, int inRecursive ) const; 

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

      // ---------------------------------------------------------------
      // --- To manage object search by attribute values
      // ---------------------------------------------------------------

    /**
      * Searches all nodes referencing another node.
      *
      * <br><b>Role</b>: Searches all nodes of a certain type pointing the current node.
      *
      * <b>Example:</b>
      * <ul>
      * <li>Search all <i><b>PLMExchangeInstances</i></b> referencing current object"
      * <br>     <b><i>this->SearchNode( PLMExchangeNodeInstance , ... )</i></b>
      * </li>
      * </ul>
      * <br><b>Precondition</b>: Beware that the result list will be emptied in the method.
      * 
      * @param inInTypeNode [in]
      * Defines the type node you want to query on.
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
      * </dl>
      * 
      * @param olstResult [out]
      * An array of objects that are compliant with the predicates (Type, tag & value). 
      * <br><b>Legal values</b>: If no object answer to search, the list is empty.
      * 
      * @param onResultSize [out]
      * Number of objects that fulfill the predicate (Type, tag & value). 
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int GetPointingNode( int                        inInTypeNode
                         , CATListOfPLMExchangeNode & olstResult
                         , int                      & onResultSize ) const ;

    /** 
      * Get Oid hash list where to integrate Oid.
      *
      * <br><b>Role</b>: Get Oid hash list where to integrate Oid.
      * Hash-table is found by scanning up the model hierarchy to find object with a such hash table.
      * 
      * @param oxOidHashTable
      *   Hash-table for access to objects through Oid.
      * 
      * @param oxHistoIdHashTable
      *   Hash-table for access to objects through Histo_Id.
      * 
      * @return
      * Returns error code
      */
      HRESULT _getOidHashList( CATHashTableMultiple * & oxOidHashTable ) const ;

      // --- General management
      // --- * _xUsedList           PLMExchangeNode list referencing this object.
      // --- * _cName               Object name.
      // --- * _nType               Object type.
      // --- * _nInstanceId         Object internal Id.
      // --- * _pDialogObject       Enable to manage relationship with a potential dialog object. Volatile information not to be streamed in XML.
      // --- * _xAccessThroughOid   Hash table that could be used to provide a direct access to a PLMExchangeNode by its Oid.

   protected:
    /** List of PLMExchangeNode having a relation on this object. */
      CATListOfPLMExchangeNode * _xUsedList         ;

    /** Node name. */
      CATUnicodeString           _cName             ;

    /** Node type among defined ones. */
      int                        _nType             ;

    /** Internal unique id. */
      int                        _nInstanceId       ;

    /** Enable to manage relationship with a potential dialog object. Volatile information not to be streamed in XML. */
      CATBaseUnknown           * _pDialogObject     ;

    /** Hash table that could be used to provide a direct access to a PLMExchangeNode by its Oid. */
      CATHashTableMultiple     * _xAccessThroughOid ;

    /** 
      * Comparison operator for PLMExchangeNode.
      *
      * <br><b>Role</b>: Compare two PLMExchangeNode to know if they are identical.
      * 
      * @param ixObject1
      * First object for comparison.
      * 
      * @param ixObject2
      * Second object for comparison.
      * 
      * @return
      *  0 If the two objects represent the same object
      */
      static int CompareOid( const void * ixObject1 , const void * ixObject2 ) ;

    /**
      * Compute hash key for a PLMExchangeNode based on theirOid.
      *
      * <br><b>Role</b>: Compute hash hash key for a PLMExchangeNode.
      * 
      * @param ixObject
      * Object on which hash key value need to be computed .
      * 
      * @return
      *   Hash key value
      */
      static unsigned int ComputeHashOid( const void * ixObject ) ;

      // -----------------------------------------------
      // --- PLMExchangeNode life cycle              ---
      // -----------------------------------------------

    /**
      * Free all information on a PLMExchangeNodel.
      * 
      * <br><b>Role</b>: Free all information on a PLMExchangeNode.
      * 
      * @param ixTransaction
      *   Current transaction (Exchange model session root).
      * 
      * @return
      *   Return number of object in current transaction.
      */
      int _isolateNode( PLMExchangeTransaction * ixTransaction ) ;

      // --- Stream information into an XML stream

   public:
      
    /**
      * Fill attribute to stream.
      *
      * <br><b>Role</b>: Add in the write buffer XML attributes.
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
      int GetFromStream( const CATUnicodeString & icTag , CATUnicodeString & icValue  ) ;

    /**
      * Replace one node by another.
      *
      * <br><b>Role</b>: Replace one node by another.
      * 
      * @param ixNodeToReplace
      *   Dummy node to be replaced.
      * 
      * @param ixSubsituteNode
      *   Not to be kept after replacements.
      * 
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>if operation are executed without any errors.</dd>
      * <dt>S_FALSE</dt> <dd>otherwise.</dd>
      * <dt>E_FAIL</dt>  <dd>otherwise.</dd>
      * </dl>
      */
      static HRESULT ReplaceOneNodebyAnother( PLMExchangeNode * ixNodeToReplace , PLMExchangeNode * ixSubsituteNode ) ;
} ;
#endif
