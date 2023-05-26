//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef  PLMExchangeOption_h
#define  PLMExchangeOption_h
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
//    To be able to manage options for PLM Exchange operations.
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Class that enables to define options.
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
#include "PLMExchangeMetric.h"

// --- Class definition

/**
 * Class representing options.
 *
 * <b>Role</b>:
 *    Defines option that could be set in PLM Exchange Experience.
 */
class ExportedByPLMExchangeModel PLMExchangeOption : public PLMExchangeMetric
{
   public:

    /**
      * Constructs an option.
      * 
      * @param ixFather
      *   Father node that aggregates node to be created.
      */
      PLMExchangeOption( PLMExchangeBasicNode * ixFather = NULL ) ;

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      ~PLMExchangeOption() ;

    /**
      * Copy constructor.
      * 
      * @param ixNode
      * Object to be duplicated.
      */
      PLMExchangeOption( const PLMExchangeOption & ixNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param ixNode
      * Object used as reference for the assignment.
      */
      PLMExchangeOption & operator=( const PLMExchangeOption & ixNode ) ;

      // -------------------------------------------
      // --- Manage services
      // -------------------------------------------

    /**
      * Gets default option  value.
      *
      * <br><b>Role</b>:  Gets default option  value.
      * 
      * @return
      *  Default option value. 
      */
      CATUnicodeString GetDefaultValue() const ;

    /**
      * Sets default option  value.
      *
      * <br><b>Role</b>:  Sets default option  value.
      * 
      * @param icDefaultValue [in]
      *   Default option value.
      * 
      * @return
      *   Returns error code.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>    <dd>NLS label computed from input key.</dd>
      *   <dt>E_FAIL</dt>  <dd>Error during processing.</dd>
      *   </dl>
      */
      HRESULT SetDefaultValue( const CATUnicodeString & icDefaultValue ) ;

    /**
      * Gets filtering tag value.
      *
      * <br><b>Role</b>:  Gets filtering tag value.
      * 
      * @return
      *  Filtering tag value. 
      */
      CATUnicodeString GetFilteringTag() const ;

    /**
      * Sets filtering tag value.
      *
      * <br><b>Role</b>: Sets filtering tag value.
      * 
      * @param iusFilteringTag [in]
      *   Filtering tag value.
      * 
      * @return
      *   Returns error code.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>    <dd>NLS label computed from input key.</dd>
      *   <dt>E_FAIL</dt>  <dd>Error during processing.</dd>
      *   </dl>
       */
      HRESULT SetFilteringTag( const CATUnicodeString & iusFilteringTag ) ;

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
      * <br><b>Role</b>: Add in the write buffer XML attributes.
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
      // --- * _cDefaultValue    Default value to be used if not set.
      // --- * _cFilteringTag    Filtering tag to enable to filter option and option group.

   protected :

    /** Default value to be used if not set. */
      CATUnicodeString _cDefaultValue ;

    /** Filtering tag to enable to filter option and option group. */
      CATUnicodeString _cFilteringTag ;
} ;
#endif
 
