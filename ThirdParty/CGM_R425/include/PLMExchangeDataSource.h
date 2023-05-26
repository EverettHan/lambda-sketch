//=======================================================================================
//** WARNING: YWE 19:02:25 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT **/
//=======================================================================================
#ifndef  PLMExchangeDataSource_h
#define  PLMExchangeDataSource_h
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
//    Class that enables to define an Data repository.
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
//   Revision 2.1  February 2016  (JLM) Fix comments and auto-documentation tags
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

// --- Class definition

/**
  * Class representing Data Repository.
  *
  * <b>Role</b>:
  * Define an Data Repository called a Data Source.
  */
class ExportedByPLMExchangeModel PLMExchangeDataSource : public PLMExchangeNode
{
   public:

    /**
      * Constructs One Data Surbce.
      * 
      * @param ixFather
      *   Father node that aggregates node to be created.
      */
      PLMExchangeDataSource( PLMExchangeBasicNode * ixFather = NULL ) ;          

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      ~PLMExchangeDataSource() ;

    /**
      * Copy constructor.
      * 
      * @param ixNode
      * Object to be duplicated.
      */
      PLMExchangeDataSource( const PLMExchangeDataSource & ixNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param ixNode
      * Object used as reference for the assignment.
      */
      PLMExchangeDataSource & operator=( const PLMExchangeDataSource & ixNode ) ;

      // -------------------------------------------
      // --- Manage services
      // -------------------------------------------

    /**
      * Gets Repository type.
      *
      * <br><b>Role</b>: Gets Repository type.
      * 
      * @return
      *  Repository type name. 
      */
      CATUnicodeString GetRepositoryType() const ;

    /**
      * Sets Repository type.
      *
      * <br><b>Role</b>: Sets Repository type.
      * 
      * @param icValue
      *   Repository type name.
      */
      void SetRepositoryType( const CATUnicodeString & icValue ) ;

      // ------------------------------------------------
      // --- Search information relatovely to mapping ---
      // ------------------------------------------------

    /**
      * Search objects associated to this Data Source by Oid.
      *
      * <br><b>Role</b>: Search all objects maps to this Data Source by Oid. 
      *  Data source association is done through Class object (@href PLMExchangeClassObject ) child of this Data source.
      *
      * @param icOid [in]
      *   Object Oid.
      * 
      * @param olstMapping [out]
      *   An array of mapping objects having the specied Oid.
      *   <br><b>Legal values</b>: If no object answer to search, the list is empty.
      *
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns <b><i>S_OK</i></b> if operation runs well. 
      */
      HRESULT SearchMappingByOid( const CATString          & icOid
                                , CATListOfPLMExchangeNode & olstMapping ) const ;

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
      *  Write buffer.
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
      // --- * _cRepositoryType   Repository type.

    protected :

    /** Repository type. */
      CATUnicodeString            _cRepositoryType ;
} ;

#endif
