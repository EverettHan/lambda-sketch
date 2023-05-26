//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef  PLMExchangeMetric_h
#define  PLMExchangeMetric_h
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
//    Metric node to manage NLS metrics in the report.
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Class relying on generic metric class PLMExchangeBaseMetric.
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
//   Revision 1.0  March    2007  (JLM) Initial Revision from ENORepNode
//   Revision 2.0  December 2012  (JLM) Duplication to implement Exchange Experience Model 
//   Revision 2.1  August   2013  (JLM) introduce Multi-values base on PLMExchangeValue
//   Revision 2.2  October  2013  (JLM) introduce PLMExchangeBasicMetric to add NLS identification on Metric
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
 * Class representing options.
 *
 * <b>Role</b>:
 *    Defines option that could be set in PLM Exchange Experience.
 */
class ExportedByPLMExchangeModel PLMExchangeMetric : public PLMExchangeBasicMetric
{
   public:

    /**
      * Constructs an option.
      * 
      * @param ixFather
      *   Father node that aggregates node to be created.
      */
      PLMExchangeMetric( PLMExchangeBasicNode * ixFather = NULL
                       , int                    inType   = PLMExchangeNodeMetric ) ;          

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      ~PLMExchangeMetric() ;

    /**
      * Copy constructor.
      * 
      * @param ixNode
      * Object to be duplicated.
      */
      PLMExchangeMetric( const PLMExchangeMetric & ixNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param ixNode
      * Object used as reference for the assignment.
      */
      PLMExchangeMetric & operator=( const PLMExchangeMetric & ixNode ) ;

      // -------------------------------------------
      // --- Manage services
      // -------------------------------------------

    /**
      * Gets identification key.
      *
      * <br><b>Role</b>: Gets identification key use to search NLS option name.
      * 
      * @return
      * Access key to NLS option name. 
      */
      CATUnicodeString GetKey() const ;

    /**
      * Sets identification key.
      *
      * <br><b>Role</b>: Sets identification key.
      * This string enables to look for NLS name. It is a structured string made of 3 fields CATNls file name, '.' character
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
      * Gets identification to displayed.
      *
      * <br><b>Role</b>: Gets NLS identification.
      * 
      * @return
      *    Access key to NLS name. 
      */
      CATUnicodeString GetNlsLabel() const ;

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
      // --- * _cAliasNls       NLS label to be used to display in report.

   protected :

    /** NLS label to be used to display NLS name. */
      CATUnicodeString _cAliasNls ;
} ;
#endif
 
