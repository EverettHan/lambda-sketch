//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef  PLMExchangeExecution_h
#define  PLMExchangeExecution_h
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
//    Class that enables to define an software component or Engine in exchange process.
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
#include "PLMExchangeSet.h"

// --- Class definition

/**
 * Class representing a software component or Engine in exchange process.
 *
 * <b>Role</b>:
 * Define an a software component or Engine in exchange process.
 */
class ExportedByPLMExchangeModel PLMExchangeExecution : public PLMExchangeSet
{
   public:

    /**
      * Constructs an Assembly relation.
      * 
      * @param ixFather
      *   Father node that aggregates node to be created.
      */
      PLMExchangeExecution( PLMExchangeBasicNode * ixFather = NULL ) ;          

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      ~PLMExchangeExecution() ;

    /**
      * Copy constructor.
      * 
      * @param ixNode
      * Object to be duplicated.
      */
      PLMExchangeExecution( const PLMExchangeExecution & ixNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param ixNode
      * Object used as reference for the assignment.
      */
      PLMExchangeExecution & operator=( const PLMExchangeExecution & ixNode ) ;

      // -----------------------------------------
      // ---  Access to Execution information  ---
      // -----------------------------------------

    /**
      * Gets the PLM Exchange model version.
      *
      * <br><b>Role</b>: Gets the PLM Exchange model version.
      *
      * @return
      *   PLM exchange Model version.
      */
      CATUnicodeString GetVersion() const ;

    /**
      * Gets Execution status.
      *
      * <br><b>Role</b>: Gets Execution status.
      *
      * @return
      *   Execution status.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>PLMExchangeUnknownStatus</dt>    <dd>No execution status defined.</dd>
      *    <dt>PLMExchangeSucceededStatus</dt>  <dd>Execution succeeded.</dd>
      *    <dt>PLMExchangeWarningStatus</dt>    <dd>Some warnings detected.</dd>
      *    <dt>PLMExchangeErrorStatus</dt>      <dd>Execution failed.</dd>
      *    <dt>PLMExchangeAbortStatus</dt>      <dd>Execution aborted.</dd>
      *    </dl>
      */
      int GetStatus() const ;

    /**
      * Sets Execution status.
      *
      * <br><b>Role</b>: Sets Execution status.
      *
      * @param inStatus
      *   Execution status.
      *    <p><b>Legal values</b>:</p>
      *    <dl>
      *    <dt>PLMExchangeUnknownStatus</dt>    <dd>No execution status defined.</dd>
      *    <dt>PLMExchangeSucceededStatus</dt>  <dd>Execution succeeded.</dd>
      *    <dt>PLMExchangeWarningStatus</dt>    <dd>Some warnings detected.</dd>
      *    <dt>PLMExchangeErrorStatus</dt>      <dd>Execution failed.</dd>
      *    <dt>PLMExchangeAbortStatus</dt>      <dd>Execution aborted.</dd>
      *    </dl>
      *
      * @return
      * Returns error code
      */
      HRESULT SetStatus( int inStatus ) ;

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
      * Fill XML attribute to stream.
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
      // --- * _cVersion PLM Exchange model version.
      // --- * _cStatus  Global Operation status.

    protected :
      /** _cVersion PLM Exchange model version. */
      CATUnicodeString _cVersion ;

      /**  _cStatus  Global Operation status. */
      int              _nStatus  ;
} ;
#endif
 
