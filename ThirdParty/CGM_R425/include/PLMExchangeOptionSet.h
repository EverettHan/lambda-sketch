//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef  PLMExchangeOptionSet_h
#define  PLMExchangeOptionSet_h
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
//    Enable to manage group of options in PLM Exchange model.
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
//   Revision 1.0  July     2013  (JLM) Initial Revision to enable implementation of Option Group.
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
#include "PLMExchangeSet.h"

// --- Class definition

/**
 * Class representing options' Set.
 *
 * <b>Role</b>:
 *    Defines a group of options in PLM Exchange Experience.
 */
class ExportedByPLMExchangeModel PLMExchangeOptionSet : public PLMExchangeSet
{
   public:

    /**
      * Constructs an option.
      * 
      * @param ixFather
      *   Father node that aggregates node to be created.
      */
      PLMExchangeOptionSet( PLMExchangeBasicNode * ixFather = NULL ) ;

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      ~PLMExchangeOptionSet() ;

    /**
      * Copy constructor.
      * 
      * @param ixNode
      * Object to be duplicated.
      */
      PLMExchangeOptionSet( const PLMExchangeOptionSet & ixNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param ixNode
      * Object used as reference for the assignment.
      */
      PLMExchangeOptionSet & operator=( const PLMExchangeOptionSet & ixNode ) ;

      // -------------------------------------------
      // --- Manage services
      // -------------------------------------------

    /**
      * Gets Option Group key.
      *
      * <br><b>Role</b>: Gets Option Group key use to search NLS option name.
      * 
      * @return
      *   Access key to NLS option name. 
      */
      CATUnicodeString GetKey() const ;

    /**
      * Sets Option Group key.
      *
      * <br><b>Role</b>: Sets Option Group key.
      * This string enables to look for NLS option name. It is a structured string made of 3 fields CATNls file name, '.' character
      * and key inside this message catalog: name_CATNls_File.key 
      * 
      * @param icOptionKey
      *   Access key to NLS option name.
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
      HRESULT SetKey( const CATUnicodeString & icOptionKey ) ;

    /**
      * Gets Option Group label.
      *
      * <br><b>Role</b>: Gets Option Group NLS label.
      * 
      * @return
      *   Access key to NLS option name. 
      */
      CATUnicodeString GetNlsLabel() const ;

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
      // --- * _cOptionNls       Enable to access to NLS option name with a structured string.
      // --- * _cFilteringTag    Filtering tag to enable to filter option and option group.

   protected :

    /** Enable to access to NLS option name with a structured string. */
      CATUnicodeString _cOptionNls    ;

    /** Filtering tag to enable to filter option and option group. */
      CATUnicodeString _cFilteringTag ;
} ;
#endif
 
