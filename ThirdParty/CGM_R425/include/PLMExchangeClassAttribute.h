//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef  PLMExchangeClassAttribute_h
#define  PLMExchangeClassAttribute_h
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
//    Class that enables to define an attribute class on a PLMExchangeObject
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

#include "PLMExchangeNode.h"

// --- * System framework

#include "CATString.h"
#include "CATUnicodeString.h"

// --- * Mother class

#include "PLMExchangeModel.h"

// --- Class definition

/**
 * Class representing an attribute class.
 *
 * <b>Role</b>:
 * Class representing an attribute classused to be able at parsing to capture information 
 * that will be used by the program.
 */
class ExportedByPLMExchangeModel PLMExchangeClassAttribute : public PLMExchangeNode
{
   public:

   /**
     * Constructs an attribute class.
     * 
     * @param ixFather
     *   Father node.
     */
      PLMExchangeClassAttribute( PLMExchangeBasicNode * ixFather = NULL ) ;          

   /**
     * Destructor.
     * 
     * <br><b>Role</b>: Destructor.
     */
     ~PLMExchangeClassAttribute() ;

    /**
      * Copy constructor.
      * 
      * @param ixNode
      * Object to be duplicated.
      */
      PLMExchangeClassAttribute( const PLMExchangeClassAttribute & ixNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param ixNode
      * Object used as reference for the assignment.
      */
      PLMExchangeClassAttribute & operator=( const PLMExchangeClassAttribute & ixNode ) ;
 
      // -------------------------------------------
      // --- Manage services
      // -------------------------------------------

   /**
     * Gets attribute value type.
     *
     * <br><b>Role</b>: Gets attribute value type among authorized ones.
     * 
     * @return
     *   Attribute value Type.
     *  <p><u>Legal values:</u></p>
     *  <dl>
     *  <dt>PLMExchangeUnknownAttribute</dt>   <dd>Value type not defined (0)</dd>
     *  <dt>PLMExchangeBooleanAttribute</dt>   <dd>Boolean value          (1)</dd>
     *  <dt>PLMExchangeIntegerAttribute</dt>   <dd>Integer value          (2)</dd>
     *  <dt>PLMExchangeFloatAttribute</dt>     <dd>Floating point valie   (3)</dd>
     *  <dt>PLMExchangeStringAttribute</dt>    <dd>Character string value (4)</dd>
     *  <dt>PLMExchangeBinaryAttribute</dt>    <dd>Binary string  value   (5)</dd>
     *  <dt>PLMExchangeDateAttribute</dt>      <dd>Date value             (6)</dd>
     *  <dt>PLMExchangeBinaryTSAttribute</dt>  <dd>Binary TS value        (7)</dd>
     *  </dl>
     */
      int GetValueType() const ;

   /**
     * Sets attribute value type.
     *
     * <br><b>Role</b>: Sets attribute value type among authorized ones.
     * 
     * @param inValueType
     *   Attribute value Type.
     *  <p><u>Legal values:</u></p>
     *  <dl>
     *  <dt>PLMExchangeUnknownAttribute</dt>   <dd>Value type not defined (0)</dd>
     *  <dt>PLMExchangeBooleanAttribute</dt>   <dd>Boolean value          (1)</dd>
     *  <dt>PLMExchangeIntegerAttribute</dt>   <dd>Integer value          (2)</dd>
     *  <dt>PLMExchangeFloatAttribute</dt>     <dd>Floating point valie   (3)</dd>
     *  <dt>PLMExchangeStringAttribute</dt>    <dd>Character string value (4)</dd>
     *  <dt>PLMExchangeBinaryAttribute</dt>    <dd>Binary string  value   (5)</dd>
     *  <dt>PLMExchangeDateAttribute</dt>      <dd>Date value             (6)</dd>
     *  <dt>PLMExchangeBinaryTSAttribute</dt>  <dd>Binary TS value        (7)</dd>
     *  </dl>
     */
      void SetValueType( int inValueType ) ;

   /**
      * Gets attribute alias name.
      *
      * <br><b>Role</b>: Gets attribute alias name (NLS string).
      * 
      * @return
      *   Attribute alias name .
      */
      CATUnicodeString GetAlias() const ;

    /**
      * Sets attribute alias name.
      *
      * <br><b>Role</b>: Sets attribute alias name (NLS string).
      * 
      * @param iusAlias
      *   Attribute alias name .
      * 
      * @return
      *   Returns error code.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>    <dd>NLS label computed from input key.</dd>
      *   <dt>E_FAIL</dt>  <dd>Error during processing.</dd>
      *   </dl>
      */
      HRESULT SetAlias( const CATUnicodeString & iusAlias ) ;

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
      * <li><tt>0</tt> if operation are executed without any errors.</li>
      * <li><tt>1</tt> otherwise.</li>
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
       // --- * _cAliasNls       NLS label to be used to display attribute name.

    protected :
 
    /** NLS label to be used to display attribute name. */
      CATUnicodeString _cAliasNls ;
     
} ;
#endif
 
