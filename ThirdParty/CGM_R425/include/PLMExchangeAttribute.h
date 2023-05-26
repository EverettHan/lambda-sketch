//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef  PLMExchangeAttribute_h
#define  PLMExchangeAttribute_h
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
//    Attribute as a name, value and type information and optionally access to class definition.
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Class that enables to define an attribute on a PLMExchangeObject or other PLMExchangeNode.
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
//   Revision 1.0  March 2007  (JLM) Initial Revision from ENORepNode
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
#include "PLMExchangeBasicMetric.h"

// --- List of referenced classes

class PLMExchangeClassAttribute ;

// --- Class definition

/**
 * Class representing an attribute with its value.
 *
 * <b>Role</b>:
 * Define an attribute information with its name, value and value type.
 */
class ExportedByPLMExchangeModel PLMExchangeAttribute : public PLMExchangeBasicMetric
{
   public:

    /**
      * Constructs an attribute.
      * 
      * @param ixFather
      *   Father node that aggregates node to be created.
      */
      PLMExchangeAttribute( PLMExchangeBasicNode * ixFather = NULL ) ;          

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      ~PLMExchangeAttribute() ;

    /**
      * Copy constructor.
      * 
      * @param ixNode
      * Object to be duplicated.
      */
      PLMExchangeAttribute( const PLMExchangeAttribute & ixNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param ixNode
      * Object used as reference for the assignment.
      */
      PLMExchangeAttribute & operator=( const PLMExchangeAttribute & ixNode ) ;
 
      // -------------------------------------------
      // --- Manage services
      // -------------------------------------------

    /**
      * Gets attribute class of this attribute.
      *
      * <br><b>Role</b>: Gets attribute class of this attribute.
      * 
      * @return
      * Attribute class. 
      */
      PLMExchangeClassAttribute * GetAttributeClass() const ;

    /**
      * Sets attribute class of this attribute.
      *
      * <br><b>Role</b>: Sets attribute class of this attribute.
      * 
      * @param ixClass
      *   Attribute class.
      * 
      * @param ilPropagateInformation
      *   Boolean value enabling to decide if Class definition if to be used as template for this atttribute (default).
      */
      void SetAttributeClass( PLMExchangeClassAttribute * const ixClass , int ilPropagateInformation = 1 ) ;

   /**
      * Gets attribute alias name.
      *
      * <br><b>Role</b>: Gets attribute alias name, NLS string to be use for NLS report and access from Class attribute object.
      * 
      * @return
      *   Attribute alias name .
      */
      CATUnicodeString GetAlias() const ;

    /** 
      * Notify that one object will be deleted.
      *
      * <br><b>Role</b>: Notify that one object will be deleted.
      * 
      * 
      * @param ixReferenced
      * Object.
      * 
      * @return
      *   0 if Ok
      */
      int NotifyObjectDeletion( const PLMExchangeNode * ixReferenced ) ;

    /** 
      * Notify an object replacement.
      *
      * <br><b>Role</b>: In case of XML loading, we may have to replace on PLMExchangeNode by another one
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
      int NotifyObjectReplace( const PLMExchangeNode * ixOld , PLMExchangeNode * ixNew ) ;

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
      int GetFromStream( const CATUnicodeString & icTag , CATUnicodeString & icValue ) ;

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
      // --- * _xAttrClass Attribute class.

    protected :
      /** Attribute class. */
      PLMExchangeClassAttribute * _xAttrClass ;

} ;
#endif
 
