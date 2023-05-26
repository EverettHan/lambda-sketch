//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef  PLMExchangeClassObject_h
#define  PLMExchangeClassObject_h
// COPYRIGHT DASSAULT SYSTEMES 2012-2013
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
//    Base class for a simple object hierarchical model
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Class that enables to define object clas definition.
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
//   Revision 1.0  March 2007     (JLM) Initial Revision from ENORepNode
//   Revision 2.0  December 2012  (JLM) Duplication to implement Exchange Experience Model 
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

// --- * System framework

#include "CATUnicodeString.h"

// --- * Mother class

#include "PLMExchangeModel.h"
#include "PLMExchangeNode.h"
#include "PLMExchangeObject.h"

// --- Class definition

/**
 * Class representing an declaration of an object type.
 *
 * <b>Role</b>:
 * Define an object class.
 */

class ExportedByPLMExchangeModel PLMExchangeClassObject : public PLMExchangeNode
{
   public:

    /**
      * Constructs an object type.
      * 
      * @param ixFather
      *   Father node that aggregates node to be created.
      */
      PLMExchangeClassObject( PLMExchangeBasicNode * ixFather = NULL ) ;          

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      ~PLMExchangeClassObject() ;

    /**
      * Copy constructor.
      * 
      * @param ixNode
      * Object to be duplicated.
      */
      PLMExchangeClassObject( const PLMExchangeClassObject & ixNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param ixNode
      * Object used as reference for the assignment.
      */
      PLMExchangeClassObject & operator=( const PLMExchangeClassObject & ixNode ) ;

      // -------------------------------------------
      // --- Manage services
      // -------------------------------------------

    /**
      * Gets core object type.
      *
      * <br><b>Role</b>: Gets core object type.
      * 
      * @return
      *   Object core Type. 
      * <br><b>Legal values</b>: It can be set to either:
      * <dl>
      * <dt>PLMExchangeObjectType_Reference</dt>      <dd>Reference.</dd>
      * <dt>PLMExchangeObjectType_Port</dt>           <dd>Port.</dd>
      * <dt>PLMExchangeObjectType_Connection</dt>     <dd>Connection.</dd>
      * <dt>PLMExchangeObjectType_Instance</dt>       <dd>Instance.</dd>
      * <dt>PLMExchangeObjectType_Representation</dt> <dd>Representation.</dd>
      * <dt>PLMExchangeObjectType_RepInstance</dt>    <dd>Representation Instance.</dd>
      * <dt>PLMExchangeObjectType_Entity</dt>         <dd>Entity.</dd>
      * <dt>PLMExchangeObjectType_Relation</dt>       <dd>Relation.</dd>
      * </dl>
      */
      PLMExchangeNode::PLMExchangeObjectType GetObjectType() const ;

    /**
      * Sets  core object type.
      *
      * <br><b>Role</b>: Sets  core object type.
      * 
      * @param ixChild
      *   Object core Type.
      * <br><b>Legal values</b>: It can be set to either:
      * <dl>
      * <dt>PLMExchangeObjectType_Reference</dt>      <dd>Reference.</dd>
      * <dt>PLMExchangeObjectType_Port</dt>           <dd>Port.</dd>
      * <dt>PLMExchangeObjectType_Connection</dt>     <dd>Connection.</dd>
      * <dt>PLMExchangeObjectType_Instance</dt>       <dd>Instance.</dd>
      * <dt>PLMExchangeObjectType_Representation</dt> <dd>Representation.</dd>
      * <dt>PLMExchangeObjectType_RepInstance</dt>    <dd>Representation Instance.</dd>
      * <dt>PLMExchangeObjectType_Entity</dt>         <dd>Entity.</dd>
      * <dt>PLMExchangeObjectType_Relation</dt>       <dd>Relation.</dd>
      * </dl>
      */
      void SetObjectType( PLMExchangeNode::PLMExchangeObjectType inMoType ) ;

      // -----------------------------------------------
      // --- To support XML streaming                ---
      // -----------------------------------------------

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

      // --- Member definition
      // --- * _nObjectType      Defines basic object type (core type).

    protected :
    /** Defines basic object type (core type). */
      PLMExchangeObjectType    _nObjectType     ;
} ;
#endif
 
