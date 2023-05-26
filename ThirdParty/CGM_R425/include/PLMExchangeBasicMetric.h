//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
#ifndef  PLMExchangeBasicMetric_h
#define  PLMExchangeBasicMetric_h 
// COPYRIGHT DASSAULT SYSTEMES 2012-2014
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
//    Basic metric node is the base class for (attribute,value,type) paradigm that will be used for metrics, options and attributes.
//
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
#include "CATSysBoolean.h"
#include "CATBinary.h"
#include "CATTime.h"
#include "CATListOfCATUnicodeString.h"

// --- * Mother class

#include "PLMExchangeModel.h"
#include "PLMExchangeNode.h"

// --- * Forward declaration

class PLMExchangeObject ;
class PLMExchangeEnum   ;
class PLMExchangeValue  ;

// --- Class definition

/**
  * Class representing a metric.
  *
  * <b>Role</b>:
  * Define a metric ie a information represention a named and a value.
  */
class ExportedByPLMExchangeModel PLMExchangeBasicMetric : public PLMExchangeNode
{
   public:

    /**
      * Constructs one metric node.
      * 
      * <br><b>Role</b>: Enables to create a metric node to support metrics, options and attributes. ie case of object that manage a 
      *  single value or multiple values. Per default we create a single unlock string value.
      * 
      * @param ixFather
      *   Father node that aggregates node to be created.
      * 
      * @param inType
      *   Value type.
      */
      PLMExchangeBasicMetric( PLMExchangeBasicNode * ixFather = NULL
                            , int                    inType   = PLMExchangeNodeBasicMetric ) ;          

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      ~PLMExchangeBasicMetric() ;

    /**
      * Copy constructor.
      * 
      * @param ixNode
      * Object to be duplicated.
      */
      PLMExchangeBasicMetric( const PLMExchangeBasicMetric & ixNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param ixNode
      * Object used as reference for the assignment.
      */
      PLMExchangeBasicMetric & operator=( const PLMExchangeBasicMetric & ixNode ) ;
 
      // -----------------------------------------------------------
      // --- Generic information on values
      // -----------------------------------------------------------

    /**
      * Gets value information.
      *
      * <br><b>Role</b>: Gets information relative to this value.
      * 
      * @param ocName
      *   Value name.
      * 
      * @param onType
      *   Attribute value Type.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>PLMExchangeUnknownAttribute</dt>     <dd>Value type not defined<</dd>
      *  <dt>PLMExchangeBooleanAttribute</dt>     <dd>Boolean value</dd>
      *  <dt>PLMExchangeIntegerAttribute</dt>     <dd>Integer value</dd>
      *  <dt>PLMExchangeFloatAttribute</dt>       <dd>Floating point value</dd>
      *  <dt>PLMExchangeStringAttribute</dt>      <dd>Character string value</dd>
      *  <dt>PLMExchangeBinaryAttribute</dt>      <dd>Binary string value</dd>
      *  <dt>PLMExchangeDateAttribute</dt>        <dd>Date value</dd>
      *  <dt>PLMExchangeBinaryTSAttribute</dt>    <dd>Binary TS value</dd>
      *  <dt>PLMExchangeFileNameAttribute</dt>    <dd>File name value</dd>
      *  <dt>PLMExchangeFolderPathAttribute</dt>  <dd>File folder value</dd>
      *  <dt>PLMExchangeObjectAttribute</dt>      <dd>Object value</dd>
      *  <dt>PLMExchangeNlsStringAttribute</dt>   <dd>NLS string value</dd>
      *  <dt>PLMExchangeNodeRefAttribute</dt>     <dd>Reference a Node in the Exchange Model</dd>
      *  </dl>
      *
      * @param ocValue
      *   Value.
      *
      * @param oisSet
      *   Information to identify if value has been set.
      *  <br><b>Legal values</b>:
      *  <dl>
      *  <dt>0</dt>  <dd>Value not set.</dd>
      *  <dt>1</dt>  <dd>Value has been set.</dd>
      *  </dl>
      * 
      * @return
      *   Return the result of the method.
      *  <br><b>Legal values</b>:
      *  <dl>
      *  <dt>S_OK</dt>     <dd>Both attribute name and value are defined</dd>
      *  <dt>S_FALSE</dt>  <dd>Attribute name is defined, but no value is set.</dd>
      *  <dt>E_FAIL</dt>   <dd>Attribute name and value are not set.</dd>
      *  </dl>
      */
      HRESULT GetAttributeInfo( CATUnicodeString & ocName 
                              , int              & onType 
                              , CATUnicodeString & ocValue 
                              , int              & oisSet ) const ;

    /**
      * Identifies if value is set.
      *
      * <br><b>Role</b>: Identifies if value is set.
      * 
      * @return
      *    status relative to value.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>Value not set.</dd>
      *  <dt>1</dt>   <dd>Value set.</dd>
      *  </dl>
      */
      int IsValueSet() const ;

    /**
      * Identifies if it is an array of values.
      *
      * <br><b>Role</b>: Identifies if it is an array of values
      * 
      * @return
      *    If it is a array of values.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>0</dt>   <dd>single value.</dd>
      *  <dt>1</dt>   <dd>Array of values.</dd>
      *  </dl>
      */
      int IsArrayOfValues() const ;

    /**
      * Gets number of values.
      *
      * <br><b>Role</b>: Gets number of values.
      * 
      * @return
      *   Number of values.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>0</dt>      <dd>if value not set.</dd>
      * <dt>1</dt>      <dd>if value is set and only one value is defined.</dd>
      * <dt>otherL</dt> <dd>number of values for a multi-value.</dd>
      * </dl>
      */
      int GetNumberOfValues() const ;

    /**
      * Gets attribute value type.
      *
      * <br><b>Role</b>: Gets attribute value type.
      * 
      * @return
      *   Attribute value Type.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>PLMExchangeUnknownAttribute</dt>     <dd>Value type not defined<</dd>
      *  <dt>PLMExchangeBooleanAttribute</dt>     <dd>Boolean value</dd>
      *  <dt>PLMExchangeIntegerAttribute</dt>     <dd>Integer value</dd>
      *  <dt>PLMExchangeFloatAttribute</dt>       <dd>Floating point value</dd>
      *  <dt>PLMExchangeStringAttribute</dt>      <dd>Character string value</dd>
      *  <dt>PLMExchangeBinaryAttribute</dt>      <dd>Binary string value</dd>
      *  <dt>PLMExchangeDateAttribute</dt>        <dd>Date value</dd>
      *  <dt>PLMExchangeBinaryTSAttribute</dt>    <dd>Binary TS value</dd>
      *  <dt>PLMExchangeFileNameAttribute</dt>    <dd>File name value</dd>
      *  <dt>PLMExchangeFolderPathAttribute</dt>  <dd>File folder value</dd>
      *  <dt>PLMExchangeObjectAttribute</dt>      <dd>Object value</dd>
      *  <dt>PLMExchangeNlsStringAttribute</dt>   <dd>NLS string value</dd>
      *  <dt>PLMExchangeNodeRefAttribute</dt>     <dd>Reference a Node in the Exchange Model</dd>
      *  </dl>
      */
      int GetValueType() const ;

    /**
      * Gets attribute value type name.
      *
      * <br><b>Role</b>: Gets attribute value type name.
      * 
      * @param ocTypeName
      *   Attribute value Type name.
      *  <p><u>Legal values:</u></p>
      *  <ul>
      *  <li>boolean</li>
      *  <li>integer</li>
      *  <li>float</li>
      *  <li>string</li>
      *  <li>binary</li>
      *  <li>date</li>
      *  <li>timestamp</li>
      *  <li>file</li>
      *  <li>folder</li>
      *  <li>nls_string</li>
      *  <li>Node</li>
      *  </ul>
      */
      void GetValueTypeName( CATUnicodeString & ocTypeName ) const ;

    /**
      * Sets attribute value type.
      *
      * <br><b>Role</b>: Sets attribute value type among authorized ones.
      * 
      * @param inValueType
      *   Attribute value Type.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>PLMExchangeUnknownAttribute</dt>     <dd>Value type not defined<</dd>
      *  <dt>PLMExchangeBooleanAttribute</dt>     <dd>Boolean value</dd>
      *  <dt>PLMExchangeIntegerAttribute</dt>     <dd>Integer value</dd>
      *  <dt>PLMExchangeFloatAttribute</dt>       <dd>Floating point value</dd>
      *  <dt>PLMExchangeStringAttribute</dt>      <dd>Character string value</dd>
      *  <dt>PLMExchangeBinaryAttribute</dt>      <dd>Binary string value</dd>
      *  <dt>PLMExchangeDateAttribute</dt>        <dd>Date value</dd>
      *  <dt>PLMExchangeBinaryTSAttribute</dt>    <dd>Binary TS value</dd>
      *  <dt>PLMExchangeFileNameAttribute</dt>    <dd>File name value</dd>
      *  <dt>PLMExchangeFolderPathAttribute</dt>  <dd>File folder value</dd>
      *  <dt>PLMExchangeNlsStringAttribute</dt>   <dd>NLS string value</dd>
      *  <dt>PLMExchangeNodeRefAttribute</dt>     <dd>Reference a Node in the Exchange Model</dd>
      *  </dl>
      */
      void SetValueType( int inValueType ) ;
 
      // -------------------------------------------------
      // --- Associates constraint to values (Enum, ...)
      // -------------------------------------------------

    /**
      * Gets associated value Enumeration constraint.
      *
      * <br><b>Role</b>: Gets, if exists, associated value enumeration constraint use to restrict authorized value.
      * 
      * @return
      *   Enumeration object instance. 
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>NULL</dt>   <dd>If no value enumeration constraint defined.</dd>
      *  <dt>Otherwise</dt>   <dd>access to associated @see PLMExchangeEnum object.</dd>
      *  </dl>
      */
      PLMExchangeEnum * SearchForEnumConstraint() const ;

    /**
      * Adds one value Enumeration constraint.
      *
      * <br><b>Role</b>: Adds one value Enumeration constraint, if no value Enumeration constraint exists.
      * 
      * @param ipEnum [out]
      *   Enumeration object instance ( @see PLMExchangeEnum ). 
      * 
      * @return
      *   Return code. 
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>S_OK</dt>    <dd>Creation of one value Enumeration constraint.</dd>
      *  <dt>S_FALSE</dt> <dd>One value Enumeration constraint is already associated to this object.</dd>
      *  <dt>E_FAIL</dt>  <dd>Creation fails.</dd>
      *  </dl>
      */
      HRESULT AddEnumConstraint( PLMExchangeEnum *& ipEnum ) ;

      // -------------------------------------------
      // --- Manage metric values
      // -------------------------------------------

    /**
      * Removes all values.
      *
      * <br><b>Role</b>: Removes all values.
      * 
      * @return
      *   Return code. 
      *   <p><u>Legal values:</u></p>
      *   <dl>
      *   <dt>S_OK</dt>    <dd>All values has been reset and removed.</dd>
      *   <dt>S_FALSE</dt> <dd>No value defines.</dd>
      *   <dt>E_FAIL</dt>  <dd>Error during operations.</dd>
      *   </dl>
      */
      HRESULT RemoveAllValues() ;

    /**
      *  Removes one value.
      *
      * <br><b>Role</b>: Removes one value at a specified position.
      * 
      * @param inPos [in]
      *  Position in the list of values.
      *   <br><b>Legal values</b>: <i>Authorize position values are between 1 and number of values stored.</i>
      * 
      * @return
      *  Return code 
      *  <br><b>Legal values</b>:
      *  <dl>
      *  <dt>S_OK</dt>    <dd>Value removed.</dd>
      *  <dt>S_FALSE</dt> <dd>Last value removed.</dd>
      *  <dt>E_FAIL</dt>  <dd>Invalid position or value not set.</dd>
      *  </dl>
      */
      HRESULT RemoveValue( int inPos ) ;

    /**
      * Sets Type and value.
      *
      * <br><b>Role</b>: Sets value with check of the value according to the value type provided.
      * 
      * @param inType
      *   Attribute value Type.
      *  <p><u>Legal values:</u></p>
      *  <dl>
      *  <dt>PLMExchangeUnknownAttribute</dt>     <dd>Value type not defined<</dd>
      *  <dt>PLMExchangeBooleanAttribute</dt>     <dd>Boolean value</dd>
      *  <dt>PLMExchangeIntegerAttribute</dt>     <dd>Integer value</dd>
      *  <dt>PLMExchangeFloatAttribute</dt>       <dd>Floating point value</dd>
      *  <dt>PLMExchangeStringAttribute</dt>      <dd>Character string value</dd>
      *  <dt>PLMExchangeBinaryAttribute</dt>      <dd>Binary string value</dd>
      *  <dt>PLMExchangeDateAttribute</dt>        <dd>Date value</dd>
      *  <dt>PLMExchangeBinaryTSAttribute</dt>    <dd>Binary TS value</dd>
      *  <dt>PLMExchangeFileNameAttribute</dt>    <dd>File name value</dd>
      *  <dt>PLMExchangeFolderPathAttribute</dt>  <dd>File folder value</dd>
      *  <dt>PLMExchangeNlsStringAttribute</dt>   <dd>NLS string value</dd>
      *  <dt>PLMExchangeNodeRefAttribute</dt>     <dd>Reference a Node in the Exchange Model</dd>
      *  </dl>
      * 
      * @param icValue
      *  Value.
      * 
      * @return
      *  Return Code. 
      */
      HRESULT SetValueAndType( int inType , const CATUnicodeString & icValue ) ;

    /**
      * Gets attribute value.
      *
      * <br><b>Role</b>: Gets attribute class of this attribute.
      * 
      * @return
      * Attribute class. 
      */
      CATUnicodeString GetValue() const ;

    /**
      * Gets string value.
      *
      * <br><b>Role</b>: Gets string value.
      * 
      * @param ocValue [out]
      *  String Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a string value.</dd>
      * </dl>
      */
      HRESULT GetValue( CATUnicodeString & ocValue ) const ;

    /**
      * Gets integer value.
      *
      * <br><b>Role</b>: Gets integer value.
      * 
      * @param onValue [out]
      *  Integer Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a integer value.</dd>
      * </dl>
      */
      HRESULT GetValue( int & onValue ) const ;

   /**
      * Gets boolean value.
      *
      * <br><b>Role</b>: Gets boolean.
      * 
      * @param olValue [out]
      *  Boolean Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a boolean value.</dd>
      * </dl>
      */
      HRESULT GetValue( CATBoolean & olValue ) const ;

    /**
      * Gets floating point value.
      *
      * <br><b>Role</b>: Gets floating point value.
      * 
      * @param odValue [out]
      *  Floating point Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a double value.</dd>
      * </dl>
      */
      HRESULT GetValue( double & odValue ) const ;

    /**
      * Gets binary string value.
      *
      * <br><b>Role</b>: Gets binary string value.
      * 
      * @param obValue [out]
      *  Binary Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a binary value.</dd>
      * </dl>
      */
      HRESULT GetValue( CATBinary & obValue ) const ;

   /**
      * Gets date value.
      *
      * <br><b>Role</b>: Gets date value.
      * 
      * @param otValue [out]
      *  Date Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a date value.</dd>
      * </dl>
      */
       HRESULT GetValue( CATTime & otValue ) const ;

    /**
      * Gets file Name.
      *
      * <br><b>Role</b>: Gets file path value.
      * 
      * @param ocFileName [out]
      *  File path.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid file path.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT GetFileName( CATUnicodeString & ocFileName ) const ;

    /**
      * Gets directory file path.
      *
      * <br><b>Role</b>: gets directory file path value.
      * 
      * @param ocDirectoryPath [out]
      *  Directory file path.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid directory path.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT GetDirectoryPath( CATUnicodeString & ocDirectoryPath ) const ;

    /**
      * Gets NLS string value.
      *
      * <br><b>Role</b>: Gets NLS value both the key and the current local value.
      * 
      * @param ocKey [out]
      *  Key String.
      * <sl>
      * <li>This value enable to manage NLS display unsing CATNls paradigm, one key to get a local value. It is a structured string made of 3 fields CATNls file name, '.' character
      * and key inside this message catalog: name_CATNls_File.key </li>
      * </sl>
      * 
      * @param ocNlsValue [out]
      *  NLS string value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a string value.</dd>
      * </dl>
      */
      HRESULT GetNlsValue( CATString & ocKey , CATUnicodeString & ocNlsValue ) const ;

    /**
      * Gets PLMExchangeNode value.
      *
      * <br><b>Role</b>: Gets PLMExchangeNode value.
      * 
      * @param opNode [out]
      *  PLMExchangeNode.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a PLMExchangeNode value.</dd>
      * </dl>
      */
      HRESULT GetValue( PLMExchangeNode * & opNode ) const ;

    /**
      * Gets one string value.
      *
      * <br><b>Role</b>: Gets one string value at a specific position in the list at a specified position.
      *   <br><b>Legal values</b>: <i>Authorize position values are between 1 and number of values stored.</i>
      * 
      * @param inPos [in]
      *  Position in the list of values.
      * 
      * @param ocValue [out]
      *  String Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a string value.</dd>
      * </dl>
      */
      HRESULT GetValue( int inPos , CATUnicodeString & ocValue ) const ;

    /**
      * Gets one of integer value.
      *
      * <br><b>Role</b>: Gets one integer value.
      * 
      * @param inPos [in]
      *  Position in the list of values at a specified position.
      *   <br><b>Legal values</b>: <i>Authorize position values are between 1 and number of values stored.</i>
      *
      * @param onValue [out]
      *  Integer Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a integer value.</dd>
      * </dl>
      */
      HRESULT GetValue( int inPos , int & onValue ) const ;

   /**
      * Gets one boolean value.
      *
      * <br><b>Role</b>: Gets one boolean values at a specified position.
      * 
      * @param inPos [in]
      *  Position in the list of values.
      *   <br><b>Legal values</b>: <i>Authorize position values are between 1 and number of values stored.</i>
      * 
      * @param olValue [out]
      *  Boolean Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a boolean value.</dd>
      * </dl>
      */
      HRESULT GetValue( int inPos , CATBoolean & olValue ) const ;

    /**
      * Gets one floating point values.
      *
      * <br><b>Role</b>: Gets one floating point value at a specified position.
      * 
      * @param inPos [in]
      *  Position in the list of values.
      *   <br><b>Legal values</b>: <i>Authorize position values are between 1 and number of values stored.</i>
      * 
      * @param odValue [out]
      *  Floating point Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a double value.</dd>
      * </dl>
      */
      HRESULT GetValue( int inPos , double & odValue ) const ;

    /**
      * Gets one binary string value.
      *
      * <br><b>Role</b>: Gets one binary string value at a specified position.
      * 
      * @param inPos [in]
      *  Position in the list of values.
      *   <br><b>Legal values</b>: <i>Authorize position values are between 1 and number of values stored.</i>
      * 
      * @param obValue [out]
      *  Binary Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a binary value.</dd>
      * </dl>
      */
      HRESULT GetValue( int inPos , CATBinary & obValue ) const ;

   /**
      * Gets one date value.
      *
      * <br><b>Role</b>: Gets one date value at a specified position.
      * 
      * @param inPos [in]
      *   Position in the list of values.
      *   <br><b>Legal values</b>: <i>Authorize position values are between 1 and number of values stored.</i>
      * 
      * @param otValue [out]
      *  Date Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a date value.</dd>
      * </dl>
      */
       HRESULT GetValue( int inPos , CATTime & otValue ) const ;

    /**
      * Gets one NLS string value.
      *
      * <br><b>Role</b>: Gets NLS value both the key and the current local value at a specified position.
      * 
      * @param inPos [in]
      *   Position in the list of values.
      *   <br><b>Legal values</b>: <i>Authorize position values are between 1 and number of values stored.</i>
      * 
      * @param ocKey [out]
      *  Key String.
      * <sl>
      * <li>This value enable to manage NLS display unsing CATNls paradigm, one key to get a local value. It is a structured string made of 3 fields CATNls file name, '.' character
      * and key inside this message catalog: name_CATNls_File.key </li>
      * </sl>
      * 
      * @param ocNlsValue [out]
      *  NLS string value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a date value.</dd>
      * </dl>
      */
      HRESULT GetNlsValue( int inPos , CATString & ocKey , CATUnicodeString & ocNlsValue ) const ;

    /**
      * Gets one file Name.
      *
      * <br><b>Role</b>: Gets file one path value.
      * 
      * @param inPos [in]
      *   Position in the list of values.
      *   <br><b>Legal values</b>: <i>Authorize position values are between 1 and number of values stored.</i>
      * 
      * @param ocFileName [out]
      *  File path.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid file path.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT GetFileName( int inPos , CATUnicodeString & ocFileName ) const ;

    /**
      * Gets one directory file path.
      *
      * <br><b>Role</b>: Gets one directory file path value.
      *
      * @param inPos [in]
      *   Position in the list of values.
      *   <br><b>Legal values</b>: <i>Authorize position values are between 1 and number of values stored.</i>
      * 
      * @param ocDirectoryPath [out]
      *  Directory file path.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid directory path.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT GetDirectoryPath( int inPos , CATUnicodeString & ocDirectoryPath ) const ;

    /**
      * Gets one PLMExchangeNode value.
      *
      * <br><b>Role</b>: Gets one PLMExchangeNode value.
      *
      * @param inPos [in]
      *   Position in the list of values.
      *   <br><b>Legal values</b>: <i>Authorize position values are between 1 and number of values stored.</i>
      * 
      * @param opNode [out]
      *  PLMExchangeNode.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value from the correct type is not currently set.</dd>
      * <dt>E_FAIL</dt>  <dd>Value is not a PLMExchangeNode value.</dd>
      * </dl>
      */
      HRESULT GetValue( int inPos , PLMExchangeNode * & opNode ) const ;

    /**
      * Gets list of values.
      *
      * <br><b>Role</b>: Gets list of values.
      * 
      * @param olstValue [out]
      *  list of string Values.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value is not set.</dd>
      * <dt>E_FAIL</dt>  <dd>Error when decoding list of values.</dd>
      * </dl>
      */
      HRESULT GetValue( CATListOfCATUnicodeString & olstValue ) const ;
 
    /**
      * Gets object value.
      *
      * <br><b>Role</b>: Gets object associated to this metric.
      * 
      * @param opObject [out]
      *  Object value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Value from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value is not set.</dd>
      * <dt>E_FAIL</dt>  <dd>Error when decoding list of values or metric is not of the right type.</dd>
      * </dl>
      */
      HRESULT GetValue( PLMExchangeObject *& opObject ) const ;

    /**
      * Sets string value.
      *
      * <br><b>Role</b>: Sets string value the value type will be forced.
      * 
      * @param icValue [in]
      *  String Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>   <dd>Value has been correctly set.</dd>
      * <dt>E_FAIL</dt> <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetValue( const CATUnicodeString & icValue ) ;

    /**
      * Sets integer value.
      *
      * <br><b>Role</b>: Sets integer value forcing the value type to PLMExchangeIntegerAttribute.
      * 
      * @param inValue [in]
      *  Integer Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>   <dd>Value has been correctly set.</dd>
      * <dt>E_FAIL</dt> <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetValue( int inValue ) ;

   /**
      * Sets boolean value.
      *
      * <br><b>Role</b>: Sets boolean value forcing the value type to PLMExchangeBooleanAttribute.
      * 
      * @param ilValue [in]
      *  Boolean Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>   <dd>Value has been correctly set.</dd>
      * <dt>E_FAIL</dt> <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetValue( CATBoolean ilValue ) ;

    /**
      * Sets floating point value.
      *
      * <br><b>Role</b>: Sets floating point value forcing the value type to PLMExchangeFloatAttribute.
      * 
      * @param idValue [in]
      *  Floating point Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>   <dd>Value has been correctly set.</dd>
      * <dt>E_FAIL</dt> <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetValue( double idValue ) ;

    /**
      * Sets binary string value.
      *
      * <br><b>Role</b>: Sets binary string value forcing the value type to PLMExchangeBinaryAttribute.
      * 
      * @param ibValue [in]
      *  Binary Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>   <dd>Value has been correctly set.</dd>
      * <dt>E_FAIL</dt> <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetValue( const CATBinary & ibValue ) ;

    /**
      * Sets date value.
      *
      * <br><b>Role</b>: Sets date value forcing the value type to PLMExchangeDateAttribute.
      * 
      * @param itValue [in]
      *  Date Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>   <dd>Value has been correctly set.</dd>
      * <dt>E_FAIL</dt> <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetValue( const CATTime & itValue ) ;

    /**
      * Sets PLMExchangeNode value.
      *
      * <br><b>Role</b>: Sets PLMExchangeNode value.
      * 
      * @param ipNode [in]
      *  PLMExchangeNode.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>NULL</dt>    <dd>Reset current value.</dd>
      * <dt>Otherwise</dt> <dd>Reference an allocated PLMExchangeNode.</dd>
      * </dl>
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid PLMExchangeNode value.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetValue( PLMExchangeNode * ipNode ) ;

    /**
      * Sets one string value.
      *
      * <br><b>Role</b>: Sets one string value at a defined position in context of multivaluation.
      * <p><b>Note:</b> Using this method will force the multi-value context.</p>
      * 
      * @param inPos [in]
      *   Position in the list of values.
      *   <ul>
      *   <li>If set to -1, we will append the value at the end of the list.</li>
      *   <li>Otherwise value must be between 1 and last value position.</li>
      *   </ul>
      * 
      * @param icValue [in]
      *   String Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>         <dd>Value has been correctly inserted.</dd>
      * <dt>E_INVALIDARG</dt> <dd>Position is not a valid ones.</dd>
      * <dt>E_FAIL</dt>       <dd>Value has not been set.</dd>
      * </dl>
      */
      HRESULT SetValue( int inPos , const CATUnicodeString & icValue ) ;

    /**
      * Sets one integer value.
      *
      * <br><b>Role</b>: Sets one integer value at a defined position in context of multivaluation.
      * <p><b>Note:</b> Using this method will force the multi-value context.</p>
      * 
      * @param inPos [in]
      *   Position in the list of values.
      *   <ul>
      *   <li>If set to -1, we will append the value at the end of the list.</li>
      *   <li>Otherwise value must be between 1 and last value position.</li>
      *   </ul>
      * 
      * @param inValue [in]
      *  Integer Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>         <dd>Value has been correctly inserted.</dd>
      * <dt>E_INVALIDARG</dt> <dd>Position is not a valid ones.</dd>
      * <dt>E_FAIL</dt>       <dd>Value has not been set.</dd>
      * </dl>
      */
      HRESULT SetValue( int inPos , int inValue ) ;

   /**
      * Sets one boolean value.
      *
      * <br><b>Role</b>: Sets one boolean value at a defined position in context of multivaluation.
      * <p><b>Note:</b> Using this method will force the multi-value context.</p>
      * 
      * @param inPos [in]
      *   Position in the list of values.
      *   <ul>
      *   <li>If set to -1, we will append the value at the end of the list.</li>
      *   <li>Otherwise value must be between 1 and last value position.</li>
      *   </ul>
      * 
      * @param ilValue [in]
      *  Boolean Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>         <dd>Value has been correctly inserted.</dd>
      * <dt>E_INVALIDARG</dt> <dd>Position is not a valid ones.</dd>
      * <dt>E_FAIL</dt>       <dd>Value has not been set.</dd>
      * </dl>
      */
      HRESULT SetValue( int inPos , CATBoolean ilValue ) ;

    /**
      * Sets one floating point value.
      *
      * <br><b>Role</b>: Sets one floating point value at a defined position in context of multivaluation.
      * <p><b>Note:</b> Using this method will force the multi-value context.</p>
      * 
      * @param inPos [in]
      *   Position in the list of values.
      *   <ul>
      *   <li>If set to -1, we will append the value at the end of the list.</li>
      *   <li>Otherwise value must be between 1 and last value position.</li>
      *   </ul>
      * 
      * @param idValue [in]
      *  Floating point Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>         <dd>Value has been correctly inserted.</dd>
      * <dt>E_INVALIDARG</dt> <dd>Position is not a valid ones.</dd>
      * <dt>E_FAIL</dt>       <dd>Value has not been set.</dd>
      * </dl>
      */
      HRESULT SetValue( int inPos , double idValue ) ;

    /**
      * Sets one binary value.
      * 
      * @param inPos [in]
      *   Position in the list of values.
      *   <ul>
      *   <li>If set to -1, we will append the value at the end of the list.</li>
      *   <li>Otherwise value must be between 1 and last value position.</li>
      *   </ul>
      *
      * <br><b>Role</b>: Sets one binary value at a defined position in context of multivaluation.
      * <p><b>Note:</b> Using this method will force the multi-value context.</p>
      * 
      * @param ibValue [in]
      *  Binary Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>         <dd>Value has been correctly inserted.</dd>
      * <dt>E_INVALIDARG</dt> <dd>Position is not a valid ones.</dd>
      * <dt>E_FAIL</dt>       <dd>Value has not been set.</dd>
      * </dl>
      */
      HRESULT SetValue( int inPos , const CATBinary & ibValue ) ;

    /**
      * Sets one date value.
      *
      * <br><b>Role</b>: Sets one date value at a defined position in context of multivaluation.
      * <p><b>Note:</b> Using this method will force the multi-value context.</p>
      * 
      * @param inPos [in]
      *   Position in the list of values.
      *   <ul>
      *   <li>If set to -1, we will append the value at the end of the list.</li>
      *   <li>Otherwise value must be between 1 and last value position.</li>
      *   </ul>
      * 
      * @param itValue [in]
      *  Date Value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>         <dd>Value has been correctly inserted.</dd>
      * <dt>E_INVALIDARG</dt> <dd>Position is not a valid ones.</dd>
      * <dt>E_FAIL</dt>       <dd>Value has not been set.</dd>
      * </dl>
      */
      HRESULT SetValue( int inPos , const CATTime & itValue ) ;

    /**
      * Sets one Key of string value.
      *
      * <br><b>Role</b>: Sets one Key of string value.
      * 
      * @param inPos [in]
      *   Position in the list of values.
      *   <ul>
      *   <li>If set to -1, we will append the value at the end of the list.</li>
      *   <li>Otherwise value must be between 1 and last value position.</li>
      *   </ul>
      * 
      * @param icKey [in]
      *  Key String.
      * <sl>
      * <li>This value enable to manage NLS display unsing CATNls paradigm, one key to get a local value. It is a structured string made of 3 fields CATNls file name, '.' character
      * and key inside this message catalog: name_CATNls_File.key </li>
      * </sl>
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>         <dd>Value has been correctly inserted.</dd>
      * <dt>E_INVALIDARG</dt> <dd>Position is not a valid ones.</dd>
      * <dt>E_FAIL</dt>       <dd>Value has not been set.</dd>
      * </dl>
      */
      HRESULT SetNlsValue( int inPos , const CATString & icKey ) ;

    /**
      * Sets one file Name.
      *
      * <br><b>Role</b>: Sets one file path.
      * 
      * @param inPos [in]
      *   Position in the list of values.
      *   <ul>
      *   <li>If set to -1, we will append the value at the end of the list.</li>
      *   <li>Otherwise value must be between 1 and last value position.</li>
      *   </ul>
      * 
      * @param icFileName [in]
      *  File path.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid file path.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetFileName( int inPos , const CATUnicodeString & icFileName ) ;

    /**
      * Sets one directory file path.
      *
      * <br><b>Role</b>: Sets one directory file path.
      * 
      * @param inPos [in]
      *   Position in the list of values.
      *   <ul>
      *   <li>If set to -1, we will append the value at the end of the list.</li>
      *   <li>Otherwise value must be between 1 and last value position.</li>
      *   </ul>
      * 
      * @param icDirectoryPath [in]
      *  Directory file path.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid directory path.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetDirectoryPath( int inPos , const CATUnicodeString & icDirectoryPath ) ;

    /**
      * Sets one PLMExchangeNode value.
      *
      * <br><b>Role</b>: Sets one PLMExchangeNode value.
      * 
      * @param inPos [in]
      *   Position in the list of values.
      *   <ul>
      *   <li>If set to -1, we will append the value at the end of the list.</li>
      *   <li>Otherwise value must be between 1 and last value position.</li>
      *   </ul>
      * 
      * @param ipNode [in]
      *  PLMExchangeNode.
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>NULL</dt>    <dd>Reset current value.</dd>
      * <dt>Otherwise</dt> <dd>Reference an allocated PLMExchangeNode.</dd>
      * </dl>
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid PLMExchangeNode value.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetValue( int inPos , PLMExchangeNode * ipNode ) ;

   /**
      * Sets list of values.
      *
      * <br><b>Role</b>: Sets list of values.
      * 
      * @param ilstValue [in]
      *  list of string Values.
      * 
      * @param inType [in]
      *  Type to be used for decocing this set values.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>   <dd>Value has been correctly set.</dd>
      * <dt>E_FAIL</dt> <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetValue( const CATListOfCATUnicodeString & ilstValue , int inType = PLMExchangeStringAttribute ) ;

    /**
      * Sets metric to file Name.
      *
      * <br><b>Role</b>: Sets metric to file path.
      * 
      * @param icFileName [in]
      *  File path.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid file path.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetFileName( const CATUnicodeString & icFileName ) ;

    /**
      * Sets metric to directory file path.
      *
      * <br><b>Role</b>: Sets metric to directory file path.
      * 
      * @param icDirectoryPath [in]
      *  Directory file path.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid directory path.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetDirectoryPath( const CATUnicodeString & icDirectoryPath ) ;

    /**
      * Sets Key of string value.
      *
      * <br><b>Role</b>: Sets Key of string value.
      * 
      * @param icKey [in]
      *  Key String.
      * <sl>
      * <li>This value enable to manage NLS display unsing CATNls paradigm, one key to get a local value. It is a structured string made of 3 fields CATNls file name, '.' character
      * and key inside this message catalog: name_CATNls_File.key </li>
      * </sl>
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid directory path.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetNlsValue( const CATString & icKey ) ;

    /**
      * Initializes an object value.
      *
      * <br><b>Role</b>: Initializes an object value to one metric.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>      <dd>Value has been correctly initialized.</dd>
      * <dt>S_FALSE</dt>   <dd>Value already set.</dd>
      * <dt>E_FAIL</dt>    <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT InitializeObjectValue() ;

    /**
      * Adds one new object value.
      *
      * <br><b>Role</b>: Adds one new object value.
      * 
      * @param opObject [out]
      *  Object value.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>      <dd>Value has been correctly initialized.</dd>
      * <dt>S_FALSE</dt>   <dd>Value already set.</dd>
      * <dt>E_FAIL</dt>    <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT AddNewObjectValue( PLMExchangeObject *& opObject ) ;

    /**
      * Gets list of objects.
      *
      * <br><b>Role</b>: Gets list of objects.
      * 
      * @param olstValue [out]
      *  list of objects.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Values from the correct type has been correctly set.</dd>
      * <dt>S_FALSE</dt> <dd>Value is not set.</dd>
      * <dt>E_FAIL</dt>  <dd>Error either because it is not an object metric or during object list build.</dd>
      * </dl>
      */
      HRESULT GetValue( CATListOfPLMExchangeNode & olstValue ) const ;

    /**
      * Updates metric from object.
      *
      * <br><b>Role</b>: Updates metric from object.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>      <dd>Update has been correctly initialized.</dd>
      * <dt>S_FALSE</dt>   <dd>Object Metric is not set.</dd>
      * <dt>E_FAIL</dt>    <dd>Either metric is not an Object metric or update operation fails.</dd>
      * </dl>
      */
      HRESULT UpdateFromObjectValue() ;

      // -------------------------------------------
      // --- Manage model services
      // -------------------------------------------

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
      * @param icTag  [in]
      *   XML Attribute tag.
      * 
      * @param icValue [in]
      *   XML Attribute value.
      * 
      * @return
      *  Return code.
      * <br><b>Legal values</b>:
      * <ul>
      * <li><tt>0</tt> if operation are executed without any errors.
      * <li><tt>1</tt> otherwise.
      * </ul>
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
      *  Returns XML streaming mode: 
      * <br><b>Legal values</b>: 
      * <dl>
      * <dt>0</dt>  <dd>if node not to be traversed by streaming.</dd>
      * <dt>1</dt>  <dd>case of a node to be streamed without sub-XML nodes.</dd>
      * <dt>2</dt>  <dd>case of a node to be streamed with sub-XML nodes.</dd>
      * </dl>: 
      */
      int IsValidForPutToStream( int inFileFilter , CATUnicodeString & ocXmlNodeName ) const ;

     /**
      * Check if node needs to be streamed.
      *
      * <br><b>Role</b>: Checks if this node needs to be streamed according properties and current reporting filter.
      * 
      * @param inFileFilter
      *   Streaming option to define what need to be streamed.
      * 
      * @return
      *  Returns XML streaming mode: 
      * <br><b>Legal values</b>: 
      * <dl>
      * <dt>0</dt>  <dd>if node not to be traversed by streaming.</dd>
      * <dt>1</dt>  <dd>case of a node to be streamed without sub-XML nodes.</dd>
      * <dt>2</dt>  <dd>case of a node to be streamed with sub-XML nodes.</dd>
      * </dl>: 
      */
      int IsValidForPutToStream( int inFileFilter ) const ;
     
    /**
      * Fill XML attribute to stream.
      *
      * <br><b>Role</b>: Add in the XML write buffer XML attributes.
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

    /**
      * Fill XML sub-nodes of node.
      *
      * <br><b>Role</b>: Add XML sub-nodes in XML write buffer XML attributes.
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
      int PutNodeToStream( PLMExchangeStreamBuffer & iStreamBuffer , int inFileFilter ) ;

      // --- Print attribute identity card

    /**
      * Internal print method to generate a report on standard output.
      *
      * <br><b>Role</b>: Internal method to generate a report on standard output that display the content
      *   of this node and its children.
      * 
      * @param icInput [in]
      *  String to be used as header of the output.
      * 
      * @param icType [in]
      *  String representing the object type
      * 
      * @param inMode [in]
      *  Type of report to be generated.
      * 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>0</dt> <dd>Standard mode.</dd>
      * <dt>1</dt> <dd>One line mode.</dd>
      * </dl>
      */
      void _print( const char * const icInput , const char * const icType , int inMode = 0 ) const ;

    /** String separator between values in case of array values. */
      static const CATUnicodeString usMultiValueSeparator        ;
      static const CATUnicodeString usReplaceMultiValueSeparator ; 

      // --- Member definition
      // --- * _pArrayValues     Element in the union to allocate an array of values.
      // --- * _nLastValues      Number of values defined.
      // --- * _nMaxValues       Number of values allocated.

   protected :

    /** Attribute value for case different from Unicode string. */
      PLMExchangeValue * _pArrayValues ;

    /** Number of values defined. */
      int                _nLastValues  ;

    /** Number of values allocated. */
      int                _nMaxValues   ;

    /**
      * Prepare addition of new values.
      *
      * <br><b>Role</b>: Prepare addition of a new valueConverts by allocating enough PLMExchangeValue block.
      * 
      * @param inNewValues [in]
      *  Number of new values to add.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>   <dd>New values allocated.</dd>
      * <dt>E_FAIL</dt> <dd>Not able to insert new values.</dd>
      * </dl>
      */
      HRESULT _addValue( int inNewValues = 1 ) ;

    /**
      * Checks that value insertion is authorized.
      *
      * <br><b>Role</b>: Checks that value insertion is authorized.
      * 
      * @param ionPos [inout]
      *   Position where insertion is to be done.
      *   <ul>
      *   <li>If set to -1, we will append the value at the end of the list. In this case the method will return the insertion position</li>
      *   <li>Otherwise value must be between 1 and last value position.</li>
      *   </ul>
      * 
      * @param ilLastPos [in]
      *   Define if we have to force this position to be the last one.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>   <dd>New values allocated.</dd>
      * <dt>E_FAIL</dt> <dd>Not able to insert new values.</dd>
      * </dl>
      */
      HRESULT _checkValueInsertion( int & ionPos , int ilLastPos = 1 ) ;

    /**
      * Checks value type modification authorization.
      *
      * <br><b>Role</b>: Checks and applies value type modification authorization.
      * 
      * @param inType [in]
      *   Type to be used for this metric.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>   <dd>Value type set.</dd>
      * <dt>E_FAIL</dt> <dd>Value set not acceptable.</dd>
      * </dl>
      */
      HRESULT _checkTypeModification( int inType ) ;

    /**
      * Converts a list of values in a string.
      *
      * <br><b>Role</b>: Converts a list of values in a string by string concatenation with a separator.
      * 
      * @param ilstValue [in]
      *  list of string Values.
      * 
      * @param ocValue [out]
      *   string containing the set of values.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>   <dd>Value has been correctly set.</dd>
      * <dt>E_FAIL</dt> <dd>Error during conversion.</dd>
      * </dl>
      */
      static HRESULT _convertListToString( const CATListOfCATUnicodeString & ilstValue , CATUnicodeString & ocValue ) ;

    /** @nodoc
      * Sets list of values.
      *
      * <br><b>Role</b>: Sets list of values.
      * 
      * @param icValue [in]
      *   string containing the set of values.
      * 
      * @param olstValue [out]
      *  list of string Values.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>   <dd>Value has been correctly set.</dd>
      * <dt>E_FAIL</dt> <dd>Error during string decoding conversion.</dd>
      * </dl>
      */
      //static HRESULT _convertStringToList( const CATUnicodeString & icValue , CATListOfCATUnicodeString & olstValue ) ;
} ;
#endif
 
