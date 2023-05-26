//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef  PLMExchangeEnum_h
#define  PLMExchangeEnum_h
// COPYRIGHT DASSAULT SYSTEMES 2013
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
//    Definition of a constraint as a set of authorized values.
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Class that enables to define one constraint as a set of authorized values.
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
//   Revision 1.0  July 2013  (JLM) Class creation for Exchange Experience Model 
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

// --- Class definition

/**
 * Class representing one constraint on an attribute based on a set of authorized values.
 *
 * <b>Role</b>:
 *   Define set of authorized values for an attribute.
 */
class ExportedByPLMExchangeModel PLMExchangeEnum : public PLMExchangeBasicMetric
{
   public:

    /**
      * Constructs an attribute.
      * 
      * @param ixFather
      *   Father node that aggregates node to be created.
      */
      PLMExchangeEnum( PLMExchangeBasicNode * ixFather = NULL ) ;

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      ~PLMExchangeEnum() ;

    /**
      * Copy constructor.
      * 
      * @param ixNode
      * Object to be duplicated.
      */
      PLMExchangeEnum( const PLMExchangeEnum & ixNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param ixNode
      * Object used as reference for the assignment.
      */
      PLMExchangeEnum & operator=( const PLMExchangeEnum & ixNode ) ;
 
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
      * Fill XML attribute to stream.
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

    protected :
} ;
#endif
 
