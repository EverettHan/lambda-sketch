#ifndef  PLMExchangeValue_h
#define  PLMExchangeValue_h
// COPYRIGHT DASSAULT SYSTEMES 2013-2015
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
//    Internal classes to manage on values whatever is internal type.
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Internal classes to manage on values whatever is internal type.
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
//   Revision 1.0  August 2014  (JLM) Creation to enable management of multiple values
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

#include "PLMExchangeModel.h"

// --- * System framework

#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATSysBoolean.h"
#include "CATBinary.h"
#include "CATTime.h"

// --- * Forward declaration

class PLMExchangeNode ;

// --- Class definition

/**
  * Class representing a metric.
  *
  * <b>Role</b>:
  * Define a metric ie a information represention a named and a value.
  */
class ExportedByPLMExchangeModel PLMExchangeValue
{
   public:

    /**
      * Constructs one value object.
      * 
      * <br><b>Role</b>: Constructs one value object.
      */
      PLMExchangeValue() ;          

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      ~PLMExchangeValue() ;

    /**
      * Copy constructor.
      * 
      * @param ixNode
      * Object to be duplicated.
      */
      PLMExchangeValue( const PLMExchangeValue & ixNode ) ;

    /**
      * Assignment operator from another object node.
      * 
      * @param ixNode
      * Object used as reference for the assignment.
      */
      PLMExchangeValue & operator=( const PLMExchangeValue & ixNode ) ;
 
      // -----------------------------------------------------------
      // --- Generic information on values
      // -----------------------------------------------------------

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
      *  <dt>PLMExchangeNlsStringAttribute</dt>   <dd>NLS string value</dd>
      *  <dt>PLMExchangeNodeRefAttribute</dt>     <dd>Reference a Node in the Exchange Model</dd>
      *  </dl>
      */
      int GetValueType() const ;

    /**
      * Converts value to string.
      *
      * <br><b>Role</b>: Converts value to string according value type for purpose of XML and JSON streaming.
      * 
      * @return
      *   String representing the value accoring its types. 
      */
      CATUnicodeString ToString() const ;
 
    /**
      * Converts to a printable string.
      *
      * <br><b>Role</b>: Converts to a printable string
      * <b>NB:</b> Dedicated to display values compare to ToString() that is used for streaming (XML & JSON) and this is not using locale settings.
      * 
      * @return
      *   String enabling to display the value. 
      */
      CATUnicodeString PrintToString() const ;

      // -------------------------------------------
      // --- Manage values
      // -------------------------------------------

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
      * Gets local value.
      *
      * <br><b>Role</b>: Gets only the current local value.
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
      HRESULT GetNlsValue( CATUnicodeString & ocNlsValue ) const ;

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
      * Unsets current value.
      *
      * <br><b>Role</b>: Unsets current value to free memory type will not been changed.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>    <dd>Unset succeeded.</dd>
      * <dt>E_FAIL</dt>  <dd>Case of errors.</dd>
      * </dl>
      */
      HRESULT UnSetValue() ;

    /**
      * Sets value from string.
      *
      * <br><b>Role</b>: Sets value from string
      * 
      * @param inValueType [in]
      *  String Value.
      * <br><b>Legal values</b>:
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
      * @param icValue [in]
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
      HRESULT SetValueFromString( int inValueType , const CATUnicodeString & icValue ) ;

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
      * Sets file Name.
      *
      * <br><b>Role</b>: Sets value to file path.
      * 
      * @param icFileName [in]
      *  File path.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>S_FALSE</dt>        <dd>In case of empty file path (value is reseted).</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid file path.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetFileName( const CATUnicodeString & icFileName ) ;

    /**
      * Sets directory file path.
      *
      * <br><b>Role</b>: Sets value to directory file path.
      * 
      * @param icDirectoryPath [in]
      *  Directory file path.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>S_FALSE</dt>        <dd>In case of empty file path (value is reseted).</dd>
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
      * Sets value to Boolean from a string.
      *
      * <br><b>Role</b>: Sets value to Boolean from a string.
      * 
      * @param icValue [in]
      *  Value to decode as Boolean.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid Boolean value.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetBooleanString( const CATUnicodeString & icValue ) ;

    /**
      * Sets value to integer from a string.
      *
      * <br><b>Role</b>: Sets value to integer from a string.
      * 
      * @param icValue [in]
      *  Value to decode as integer.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid integer value.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetIntegerFromString( const CATUnicodeString & icValue ) ;

    /**
      * Sets value to double from a string.
      *
      * <br><b>Role</b>: Sets value to double from a string.
      * 
      * @param icValue [in]
      *  Value to decode as double.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid double value.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetDoubleFromString( const CATUnicodeString & icValue ) ;

    /**
      * Sets value to binary from a string.
      *
      * <br><b>Role</b>: Sets value to binary from a string.
      * 
      * @param icValue [in]
      *  Value to decode as binary.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid binary value.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetBinaryFromString( const CATUnicodeString & icValue ) ;

    /**
      * Sets value to date from a string.
      *
      * <br><b>Role</b>: Sets value to date from a string.
      * 
      * @param icValue [in]
      *  Value to decode as date.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid date value.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetDateFromString( const CATUnicodeString & icValue ) ;

    /**
      * Sets NLS String from one unicode string.
      *
      * <br><b>Role</b>: Sets NLS String from one unicode string.
      * 
      * @param icKey [in]
      *  Key String.
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>           <dd>Value has been correctly set.</dd>
      * <dt>E_INVALIDARG</dt>   <dd>Not a valid NLS string.</dd>
      * <dt>E_FAIL</dt>         <dd>Value has not been set, but value type has been set.</dd>
      * </dl>
      */
      HRESULT SetNlsValueFromString( const CATUnicodeString & icKey ) ;

      // -----------------------------------------------
      // --- To support value checking               ---
      // -----------------------------------------------

    /**
      * Check binary stamp.
      * 
      * <br><b>Role</b>: Check TS (Big-endian or little-endian according inputs).
      * 
      * @param icBin [in]
      *   TS Binary string to convert in hexadecimal format.
      * 
      * @param inEndianRep [in]
      *   Endianess representation.
      *   <dl>
      *   <dt>nBigEndianRepresentation</dt>     <dd>For Big Endian encoding (UNIX and Mainframe mainly).</dd>
      *   <dt>nLittleEndianRepresentation</dt>  <dd>Not Little Endian encoding (MS Windows mainly).</dd>
      *   </dl>
      * 
      * @param ocTimeStamp [out]
      *   Timestamp decoded.
      * 
      * @return
      *   Conversion result.
      *   <br><b>Legal values</b>: 
      *   <dl>
      *   <dt>0</dt>  <dd>if conversion done without any issue</dd>
      *   <dt>1</dt>  <dd>Not a valid date.</dd>
      *   <dt>2</dt>  <dd>Valid date before conversion.</dd>
      *   <dt>3</dt>  <dd>Not having the expect size.</dd>
      *   </dl>
      */
      static int CheckBinaryStamp( const CATUnicodeString & icBin
                                 , int                      inEndianRep 
                                 , CATUnicodeString       & ocTimeStamp ) ;

    /**
      * Check if int value is a valid date.
      * 
      * <br><b>Role</b>: Convert TS to Big-endian to little-endian.
      * 
      * @param inTime [in]
      *   Integer representing a time.
      * 
      * @param oTime [out]
      *   Time.
      * 
      * @param ilPrint [int]
      *   Enable to activate debug traces.
      * 
      * @return
      *   Conversion result.
      *   <br><b>Legal values</b>: 
      *   <dl>
      *   <dt>0</dt>  <dd>Value seems ok.</dd>
      *   <dt>1</dt>  <dd>Not having the expect size.</dd>
      *   <dt>2</dt>  <dd>Not a valid date.</dd>
      *   </dl>
      */
      static int isValidBinaryStamp( int inTime , CATTime & oTime , int ilPrint ) ;

    /**
      * Checks that the file is a valid path name.
      *
      * <br><b>Role</b>: Checks that the file is a valid path name.
      * 
      * @param iusPath [in]
      *   File path to be tested.
      * 
      * @param ilFileMustExist [in]
      *   The existence flag (TRUE if the file must exist, otherwise FALSE).
      * 
      * @param iusExtensionName [in]
      *   The extension to match (ex: xml, PLMBriefcase ...)
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>:
      * <dl>
      * <dt>S_OK</dt>            <dd>if the file corresponds to an existing directory, has the required extension and matches the existence flag.</dd>
      * <dt>S_FALSE</dt>         <dd>if there File Path is empty (attribute will be reseted).</dd>
      * <dt>E_ACCESSDENIED</dt>  <dd>if the file already exists in Read Write mode whereas the exitence flag is set to FALSE.</dd>
      * <dt>E_INVALIDARG</dt>    <dd>if the file does not comply with input arguments (wrong extension, or wrong existence flag...).</dd>
      * <dt>E_FAIL</dt>          <dd>if there is a problem.</dd>
      * </dl>
      */
      static HRESULT CheckValidFilePath( const CATUnicodeString & iusPath 
                                       , const CATBoolean         ilFileMustExist
                                       , const CATUnicodeString & iusExtensionName ) ;
    /**
      * Gets the extension of a file.
      *
      * @param iusPath [in]
      *   The path of a file.
      *
      * @param ousExtensionName [out]
      *   The extension of the file (ex: txt, xml, ...)
      *
      * @return
      * <dl>
      * <dt>S_OK</dt>   <dd>if the extension is successfully retrieved.</dd>
      * <dt>E_FAIL</dt> <dd>if the extension cannot be retrieved.</dd>
      * </dl>
      */
      static HRESULT GetFileExtension( const CATUnicodeString & iusPath , CATUnicodeString & ousExtensionName ) ;

    /**
      * Determines if a path exists.
      *
      * @param icPath [in]
      *   The path of a file or a directory to check.
      *
      * @param olAvailability [out]
      *   The availability: TRUE is the path exists, FALSE otherwise
      *
      * @return
      * <dl>
      * <dt>S_OK</dt>   <dd>if the availability of the path is successfully retrieved.</dd>
      * <dt>E_FAIL</dt> <dd>if the availability of the path cannot be retrieved.</dd>
      * </dl>
      */
      static HRESULT IsPathAvailable( const CATUnicodeString & icPath , CATBoolean& olAvailability ) ;

      // --- Enable to convert Binary to string and reverse

    /**
      * Convert a binary string into an hexadecimal Unicode string.
      *
      * @param ibBinaryValue [in]
      *   Binary to convert.
      *
      * @param ocValue [out]
      *   Output String.
      *
      * @return
      *   Error code (O is all is run well.)
      */
      static int EncodeBinaryString( const CATBinary & ibBinaryValue , CATUnicodeString & ocValue ) ;

    /**
      * Convert hexadecimal Unicode string into a binary string.
      *
      * @param icValue [in]
      *   String to convert.
      *
      * @param obBinaryValue [out]
      *   Binary field.
      *
      * @return
      *   Error code (O is all is run well.)
      */
      static int DecodeBinaryString( const CATUnicodeString & icValue , CATBinary & obBinaryValue ) ;

    /**
      * Convert Unicode string into a date.
      *
      * @param icValue [in]
      *   String to convert.
      * <br><b>Date format is</b>: YYYY.MM.DD hh:mm:ss
      *
      * @param otDateValue [out]
      *   Date.
      *
      * @return
      *   Error code (O is all is run well.)
      */
      static int DecodeDate( const CATUnicodeString & icValue , CATTime & otDateValue ) ;

      // --- Member definition
      // --- * _nValue           Case of a single integer or boolean Value.
      // --- * _dValue           Case of a single floating point value.
      // --- * _pValue           Element in the union to allocate complex value type such as CATUnicodeString...
      // --- * _nValueType       Type of values.

   protected :

    /** Union to manage different type of values: integer, double, Unicode string... */
      union
      {
         int              _nValue ;
         double           _dValue ;
         void           * _pValue ;
      } ;

    /** Attribute value type. */
      int                 _nValueType ;

    /** 
      * Structure to manage NLS String value one key wih one NSL unicode string.
      * <sl>
      * <li><b>NB:</b> This value enable to manage NLS display unsing CATNls paradigm, one key to get a local value. It is a structured string made of 3 fields CATNls file name, '.' character
      * and key inside this message catalog: name_CATNls_File.key </li>
      * </sl>
      */
      struct _NlsString
      {
       /** 
         * Key of NLS string. 
         * <sl>
         * <li><b>NB:</b> This value enable to manage NLS display unsing CATNls paradigm, one key to get a local value. It is a structured string made of 3 fields CATNls file name, '.' character
         * and key inside this message catalog: name_CATNls_File.key </li>
         * </sl>
         */
         CATString        _cNlsKey   ;

       /** 
         * NLS string according local definition. 
         */
         CATUnicodeString _cNlsValue ;
      } ;

    /**
      * Release value type and memory allocation.
      */
      void _releaseCurrentValue() ;
} ;
#endif
