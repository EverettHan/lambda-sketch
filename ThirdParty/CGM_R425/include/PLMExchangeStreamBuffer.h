#ifndef  PLMExchangeStreamBuffer_h
#define  PLMExchangeStreamBuffer_h
// COPYRIGHT DASSAULT SYSTEMES 2013-2016
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
//    Class to enable to manage streaming on disk in UTF8.
//
// *****************************************************************
//
//   Remarks :
//   ---------
//
// ****************************************************************
//
//   Story :
//   -------
//
//   Revision 1.0  November 2013  (JLM) Initial Revision from PLMExchangeNode
//   Revision 1.1  December 2014  (JLM) Extend streaming to support not only XML (JSON first candidate)
//   Revision 1.2  April    2016  (JLM) Add special representation of floating point value with an mantissa & Exponent expression: FP(Mantissa,Exponent) such as FP(21,-2) for (21/4). 
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

#include <time.h>

// --- Header that need to be referenced

#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATSysBoolean.h"

// --- * PLMExchangeModel framework

#include "PLMExchangeModel.h"

// -----------------------------------------------
// --- To support XML streaming                ---
// -----------------------------------------------

/**
  * Base class to support buffer management during Node streaming.
  *
  * <b>Role</b>:
  * Base class to support buffer management during Node streaming some derived classess will provide advance services dedicated to XML & JSON format.
  */
class ExportedByPLMExchangeModel PLMExchangeStreamBuffer
{
   public:
    /**
      * Constructor of a new stream buffer.
      * 
      * @param iusFilePath [in]
      *   File path of the file.
      * 
      * @param inMode [in]
      *  Default buffer size
      * 
      * @param inInitialSize [in]
      *  Default buffer size
      */
      PLMExchangeStreamBuffer( const CATUnicodeString & iusFilePath
                             , int                      inMode        = FLUSH_AT_BUFFER_FULL
                             , int                      inInitialSize = 65512 ) ;

    /**
      * Constructor of a new stream buffer.
      * 
      * @param inFileDescriptor [in]
      *   File descriptor to be used to append the XML representation of the report model (cf CATFopen).
      * 
      * @param inMode [in]
      *  Default buffer size
      * 
      * @param inInitialSize [in]
      *  Default buffer size
      */
      PLMExchangeStreamBuffer( unsigned int inFileDescriptor
                             , int          inMode        = FLUSH_AT_BUFFER_FULL
                             , int          inInitialSize = 65512 ) ;

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      virtual ~PLMExchangeStreamBuffer() ;

    /**
      * Indicates streaming format.
      *
      * <br><b>Role</b>: Indicates streaming format among available ones (XML or JSON today).
      * 
      * @return
      *   Streaming format.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>1</dt>   <dd>XML streaming.</dd>
      *   <dt>2</dt>   <dd>JSON streaming.</dd>
      *   </dl>
      */
      int GetStreamingFormat() const ;

    /**
      * Reset buffer.
      */
      int Reset() ;

    /**
      * Abort current I/O operations.
      *
      * <br><b>Role</b>: Abort current I/O operations.
      * <sl>
      * <li>If some I/O has already been done on the file, the file will be removed from disk.
      * </sl>
      * 
      * @return
      *   Method return code.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>0</dt>   <dd>Abort operation successfuly done.</dd>
      *   <dt>1</dt>   <dd>Abort operation could not be done, in particular where stream is managed by caller and at least one buffer has been wrote.</dd>
      *   </dl>
      */
      int Abort() ;

    /**
      * Commit current I/O operations.
      *
      * <br><b>Role</b>: Flush data in the buffer and close the file.
      * 
      * @return
      *   Method return code. 
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>0</dt>   <dd>Commit operation successly done.</dd>
      *   <dt>1</dt>   <dd>Commit operation could not be done, in particular where streal is managed by callet and at least one buffer has been wrote.</dd>
      *   </dl>
      */
      int Commit() ;

    /**
      * Enable to fill buffer.
      *
      * <br><b>Role</b>: Manage insertion of data in the buffer.
      * 
      * @param icContent [in]
      *   Unicode string to add in the buffer.
      * 
      * @return
      * Method return code.
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddStringInBuffer( const CATUnicodeString & icContent ) ;

    /**
      * Get current UTF8 buffer content.
      *
      * <br><b>Role</b>: Manage insertion of data in the buffer.
      * 
      * @param ocBufferUTF8 [out]
      *  Stream buffer (data are stored in UFT8..
      * 
      * @param onBufferUTF8Len [out]
      *   Current buffer size in byte.
      * 
      * @return
      * Method return code.
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AccessToUTF8Buffer( const char *& ocBufferUTF8  , unsigned int & onBufferUTF8Len ) const ;

    /** 
      * Option relative to Stream buffer management:
      * 
      * @param FLUSH_AT_BUFFER_FULL
      *   Flush to disk when buffer limit is reached.
      * @param NEVER_FLUSH_BEFORE_COMMIT
      *   Never flush on disk before commit.
      * @param TO_MANAGE_PRIVATE_DATA
      *   Property on buffer to remind that we are in Private data management.
      * @param WITH_NEW_LINE
      *   Property to ease reading of stream adding new lines in case of JSON or XML
      */
      enum PLMExchangeStreamBufferOptions
      {
        FLUSH_AT_BUFFER_FULL      = 0x00000001  // Flush to disk when buffer limit is reached.
      , NEVER_FLUSH_BEFORE_COMMIT = 0x00000002  // Never flush on disk before commit.
      , TO_MANAGE_PRIVATE_DATA    = 0x00000004  // Property on buffer to remind that we are in Private data management.
      , WITH_NEW_LINE             = 0x00000008  // Property to ease reading of stream adding new lines in case of JSON or XML.
      } ;

    /**
      * Get buffer options.
      *
      * <br><b>Role</b>: Get buffer options.
      * 
      * @return
      *   Return buffer options; options are defined through a mask of bits.
      *   <br><b>Legal values</b>: ( @see PLMExchangeStreamBufferOptions )
      *   <dl>
      *   <dt>FLUSH_AT_BUFFER_FULL</dt>      <dd>Flush to disk when buffer limit is reached.</dd>
      *   <dt>NEVER_FLUSH_BEFORE_COMMIT</dt> <dd>Never flush on disk before commit.</dd>
      *   <dt>TO_MANAGE_PRIVATE_DATA</dt>    <dd>Property on buffer to remind that we are in Private data management.</dd>
      *   <dt>WITH_NEW_LINE</dt>             <dd>Property to ease reading of stream adding new lines in case of JSON or XML.</dd>
      *   </dl>
      */
      int GetBufferOptions() const ;

    /**
      * Get buffer content with a specific encoding.
      *
      * <br><b>Role</b>: Get buffer content with a specific encoding.
      * 
      * @param inEncodingMode [in]
      *   Encoding mode.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>0</dt>   <dd>No encoding.</dd>
      *   <dt>1</dt>   <dd>Compression + Base 64 encoding.</dd>
      *   </dl>
      *   <br><b>Legal values</b>:
      * 
      * @param ousBuffer [in]
      *   Stream encoded.
      * 
      * @return
      *   Method return code. 
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int GetEncodedStream( int inEncodingMode , CATUnicodeString & ousBuffer ) ;

    /**
      * Convert floating point value to string using C representation.
      *
      * <br><b>Role</b>: Convert floating point value to string using C representation (compatible JSON & XML).
      * 
      * @param ifValue [in]
      *   The floating point value.
      * 
      * @param ousString [out]
      *   string where to encode previous value.
      * 
      * @return
      *   Method return code. 
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      static int ConvertDoubleToString( const double ifValue , CATUnicodeString & ousString ) ;

    /**
      * Decode decimal value stored in a string using C representation to a floating point value.
      *
      * <br><b>Role</b>: Decode decimal value stored in a string using C representation to a floating point value. Could be used when reading JSON.
      * 
      * @param iusString [in]
      *   string to decode to get floating point value.
      * 
      * @param ofValue [out]
      *   The floating point value decoded.
      * 
      * @return
      *   Method return code. 
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      static int ConvertStringToDouble( const CATUnicodeString & iusString , double & ofValue ) ;

    /**
      * Convert floating point value to string using Exponent/Mantissa representation.
      *
      * <br><b>Role</b>: Convert floating point value to string using Exponent/Mantissa representation in form of an exoression:
      *   <dl>
      *   <dd>FP(<i>+zero</i><dd>                     <dt>Special number for positive zero that could also represented by <i>FP(+0)</i>.<dt>
      *   <dd>FP(<i>-zero</i><dd>                     <dt>Special number for negative zero that could also represented by <i>FP(-0)</i>.<dt>
      *   <dd>FP(<i>NaN</i><dd>                       <dt>Special number representing the <i>"Not a Number"</i> result of impossible operations.<dt>
      *   <dd>FP(<i>+inf</i><dd>                      <dt>Special number representing positive infinity.<dt>
      *   <dd>FP(<i>-inf</i><dd>                      <dt>Special number representing negative infinity.<dt>
      *   <dd>FP(<i>Mantissa</i>,<i>Exponent</i>)<dd> <dt>Where <i>Mantissa</i> and <i>Exponent</i> are two signed integers values enabling to define real number with a value of <i>Mantissa*2^exponent</i>.<dt>
      *   <dd>FP(<i>Mantissa</i>)<dd>                 <dt>Where <i>Mantissa</i> is one signed integer value enabling to define special case of real number with a value of <i>Mantissa</i>.(NB: it could be also reprented as represented by <i>FP(Mantissa,0)</i><dt>
      *   </dl>
      * 
      * @param ifValue [in]
      *   The floating point value.
      * 
      * @param ousString [out]
      *   string where to encode previous value in form "FP(<i>Mantissa</i>,<i>Exponent</i>)" where value is equal to <i>(Mantissa * 2^Exponent)</i>.
      *   <dl>
      *   <dt>Mantissa</dt> <dd>is a signed integer value that represents the Mantissa.</dd>
      *   <dt>Exponent</dt> <dd>is a signed integer that represents the exponent in base 2.</dd>
      *   </dl>
      * 
      * @return
      *   Method return code. 
      * <br><b>Legal values</b>:
      *   <dl>
      *   <dt>0</dt> <dd>if operation runs well.</dd>
      *   <dt>1</dt> <dd>WARNING: valid expression for infinity.</dd>
      *   <dt>2</dt> <dd>WARNING: valid expression for "Not a Number".</dd>
      *   </dl>
      */
      static int ConvertDoubleToExponentAndMantissa( const double ifValue , CATUnicodeString & ousString ) ;

    /**
      * Decode real number express as Exponent & Mantissa expresion to a floating point value.
      *
      * <br><b>Role</b>: Decode real number express as Exponent & Mantissa expression to a floating point value.
      * 
      * @param iusString [in]
      *   string to decode to get floating point value.
      *   string encoded as form "FP(<i>Mantissa</i>,<i>Exponent</i>)" where value is equal to <i>(Mantissa * 2^Exponent)</i>.
      *   <dl>
      *   <dt>Mantissa</dt> <dd>is a signed integer value that represents the Mantissa.</dd>
      *   <dt>Exponent</dt> <dd>is a signed integer that represents the exponent in base 2.</dd>
      *   </dl>
      * 
      * @param ofValue [out]
      *   The floating point value decoded.
      * 
      * @return
      *   Method return code. 
      * <br><b>Legal values</b>:
      *   <dl>
      *   <dt>0</dt> <dd>if operation runs well.</dd>
      *   <dt>1</dt> <dd>ERROR: Not a valid expression.</dd>
      *   <dt>2</dt> <dd>WARNING: valid expression for infinity.</dd>
      *   <dt>3</dt> <dd>WARNING: valid expression for "Not a Number".</dd>
      *   <dt>4</dt> <dd>ERROR: Too large number set to infinity.</dd>
      *   <dt>5</dt> <dd>WARNING: Too small number set to 0.</dd>
      *   <dt>6</dt> <dd>WARNING: Mantissa too large some precision lost.</dd>
      *   </dl>
      */
      static int GetDoubleFromExponentAndMantissa( const CATUnicodeString & iusString , double & ofValue ) ;

    /**
      * Force numerical representation to C representation.
      *
      * <br><b>Role</b>: Force numerical representation to C representation (compatible JSON & XML).
      * 
      * @return
      *   Method return code. 
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      static int ForceNumericalRepresentationToC() ;

    /**
      * Restore numerical representation to previous representation stored.
      *
      * <br><b>Role</b>: Restore numerical representation to previous representation if one has been stored.
      *
      * @return
      *   Method return code. 
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      static int RestoreLocalNumericalRepresentation() ;

      // --------------------------------------------------------------------------------------
      // --- Declare virtual methods require to stream object/attribut for a specific format
      // --- (to be re-implemented for a specific format)
      // --------------------------------------------------------------------------------------

    /**
      * Add header.
      *
      * <br><b>Role</b>: Add header with UTF8 mode.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int AddHeader() ;

    /**
      * Add epilog.
      *
      * <br><b>Role</b>: Add epilog.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int AddEpilog() ;

    /**
      * Add one comment.
      *
      * <br><b>Role</b>: Add one comment.
      * 
      * @param icComment [in]
      *   Comment to be added.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int AddOneComment( const CATUnicodeString & icComment ) ;

    /**
      * Add reference to an XSL file.
      *
      * <br><b>Role</b>: Add reference to an XSL file.
      * 
      * @param icXslFilePath [in]
      *   Absolute or relative path to the XSL file.
      * 
      * @param inMode [in]
      *   Define protocol to be added to file path.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int AddXslReference( const CATUnicodeString & icXslFilePath , int inMode ) ;

    /**
      * Open one node.
      *
      * <br><b>Role</b>: Open one node in output stream.
      * 
      * @param icElement
      *   Element name.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int OpenNode( const CATUnicodeString & icElement ) ;

    /**
      * Start filling node with at least one child.
      *
      * <br><b>Role</b>:Start filling node with at least one child.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int StartChildren() ;

    /**
      * Close filling node with at least one child.
      *
      * <br><b>Role</b>:Close filling node with at least one child.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int CloseChildren() ;

    /**
      * Close one XML node.
      *
      * <br><b>Role</b>:Close one XML node. in XML stream.
      * 
      * @param icElement
      *   Element name.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int CloseNode( const CATUnicodeString & icElement ) ;

    /**
      * Close one node without child.
      *
      * <br><b>Role</b>:Close one node. in stream in case on no child.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int CloseNode() ;

    /**
      * Add one unicode string attribute.
      *
      * <br><b>Role</b>: Add one unicode string attribute in stream.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @param icAttrValue
      *   The attribute value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int AddAttribute( const CATUnicodeString & icAttrName , const CATUnicodeString & icAttrValue ) ;

    /**
      * Add one string attribute.
      *
      * <br><b>Role</b>: Add one string attribute in stream.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @param icAttrValue
      *   The attribute value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int AddAttribute( const CATUnicodeString & icAttrName , const CATString & icAttrValue ) ;

    /**
      * Add one floating point attribute.
      *
      * <br><b>Role</b>: Add one floating point attribute in stream.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @param ifValue
      *   The floating point value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int AddAttribute( const CATUnicodeString & icAttrName , const double ifValue ) ;

    /**
      * Add one integer attribute.
      *
      * <br><b>Role</b>: Add one integer attribute in stream.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @param inValue
      *   The integer value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int AddAttribute( const CATUnicodeString & icAttrName , const int inValue ) ;

    /**
      * Add one boolean attribute.
      *
      * <br><b>Role</b>: Add one boolean attribute in the stream.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @param ilValue
      *   The boolean value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int AddAttribute( const CATUnicodeString & icAttrName , const CATBoolean ilValue ) ;

    /**
      * Check if support mode for multi-values.
      *
      * <br><b>Role</b>: Check if support mode for multi-values.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      *   <dl>
      *   <dt>0</dt> <dd>Multi-values are supported as multi-nodes.<dd> 
      *   <dt>1</dt> <dd>Multi-values direct support (as case of JSON).<dd> 
      *   </dl>
      */
      virtual int IsMultiValueSupported() const ;

    /**
      * Start filling node with at least one child.
      *
      * <br><b>Role</b>:Start filling node with at least one child.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      *   <dl>
      *   <dt>0</dt> <dd>operation runs well and stream support multi-values.<dd> 
      *   <dt>1</dt> <dd>In case of error.<dd> 
      *   <dt>-1</dt> <dd>Multi-Values not supported, need to introduce values one by one as normal attributes.<dd> 
      *   </dl>
      */
      virtual int StartMultiValue( const CATUnicodeString & icAttrName ) ;

    /**
      * Close filling node with at least one child.
      *
      * <br><b>Role</b>:Close filling node with at least one child.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int CloseMultiValue( const CATUnicodeString & icAttrName ) ;

    /**
      * Add one unicode string value.
      *
      * <br><b>Role</b>: Add one unicode string value in stream.
      * 
      * @param icAttrValue
      *   The attribute value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int AddOneValue( const CATUnicodeString & icAttrValue ) ;

    /**
      * Add one string value.
      *
      * <br><b>Role</b>: Add one string value in stream.
      * 
      * @param icAttrValue
      *   The attribute value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int AddOneValue( const CATString & icAttrValue ) ;

    /**
      * Add one floating point value.
      *
      * <br><b>Role</b>: Add one floating point value in stream.
      * 
      * @param ifValue
      *   The floating point value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int AddOneValue( const double ifValue ) ;

    /**
      * Add one integer value.
      *
      * <br><b>Role</b>: Add one integer value in stream.
      * 
      * @param inValue
      *   The integer value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int AddOneValue( const int inValue ) ;

    /**
      * Add one boolean value.
      *
      * <br><b>Role</b>: Add one boolean value in the stream.
      * 
      * @param ilValue
      *   The boolean value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      virtual int AddOneValue( const CATBoolean ilValue ) ;

      // -----------------------------------------------
      // --- To support Base 64 encoding & decoding ---
      // -----------------------------------------------

    /**
      * Encode a set of bytes using Base 64 encoding.
      *
      * <br><b>Role</b>: Encode a set of bytes using Base 64 encoding (cf RFC 4648).
      * 
      * @param ixStreamIn [in]
      *   Array of bytes to be encoded.
      * 
      * @param inStreamInLen [in]
      *   Number of bytes to be encoded.
      * 
      * @param oxStreamOut [out]
      *   Array of bytes allocated by the method and fill with base 64 encoded of input set of bytes.
      * 
      * @param onStreamOutLen [out]
      *   Size of the encoded string (including the '\0' character at the end)
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      static int EncodeToBase64( const char * const ixStreamIn  , unsigned int   inStreamInLen 
                               , char       *&      oxStreamOut , unsigned int & onStreamOutLen ) ;

    /**
      * Encode a set of bytes using Base 64 encoding.
      *
      * <br><b>Role</b>: Encode a set of bytes using Base 64 encoding (cf RFC 4648).
      * 
      * @param ixStreamIn [in]
      *   Array of bytes to be decoded.
      * 
      * @param inStreamInLen [in]
      *   Number of bytes to be decoded.
      * 
      * @param oxStreamOut [out]
      *   Array of bytes allocated by the method and fill with base 64 decoded of input set of bytes.
      * 
      * @param onStreamOutLen [out]
      *   Size of the encoded string (including the '\0' character at the end)
      * 
      * @return
      * Method return code 
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      static int DecodeFromBase64( const char * const ixStreamIn  , unsigned int   inStreamInLen 
                                 , char       *&      oxStreamOut , unsigned int & onStreamOutLen ) ;
      
    /**
      * Decode an encoding stream.
      *
      * <br><b>Role</b>: Get buffer content with a specific encoding.
      * 
      * @param inEncodingMode [in]
      *   Encoding mode.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>0</dt>   <dd>No encoding.</dd>
      *   <dt>1</dt>   <dd>Compression + Base 64 encoding.</dd>
      *   </dl>
      * 
      * @param iousBuffer [in/out]
      *   Buffer to decode in input and decoded buffer if operation succeeded.
      * 
      * @return
      *   Method return code. 
      * <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      static int DecodeStream( int inEncodingMode , CATUnicodeString & iousBuffer ) ;

      // -----------------------------------------------
      // --- Constant to ease XML streaming          ---
      // -----------------------------------------------

      // --- * XML special characters and tags

    /** Standard Dassault Systemes Copyright 2012. */
      static const CATUnicodeString usCopyRight            ;

    /** Character "&" (ampersand) needs to be replaces by "&amp;" in an XML stream. */
      static const CATUnicodeString cAmpersand             ; 

    /** Character "<" (less than) needs to be replaces by "&lt;" in an XML stream. */
      static const CATUnicodeString cLessThan              ; 

    /** Character ">" (greater than) needs to be replaces by "&gt;" in an XML stream. */
      static const CATUnicodeString cGreaterThan           ; 

    /** Character "\r" (carriage return) needs to be replaces by "&#xD;" in an XML stream. */
      static const CATUnicodeString cCarriageReturn        ;

    /** Character "\n" (new line) needs to be replaces by "&#xA;" in an XML stream. */
      static const CATUnicodeString cNewLine               ;

    /** Character "\t" (tab) needs to be replaces by "&#x9;" in an XML stream. */
      static const CATUnicodeString cTab                   ;

    /** Character "\"" (quote mark) needs to be replaces by "&quot;" in an XML stream. */
      static const CATUnicodeString cDoubleQuote           ;

    /** Character "'" (apostrophe) needs to be replaces by "&apos;" in an XML stream. */
      static const CATUnicodeString cApostrophe            ;

    /** Replacement character for "&" (ampersand) in an XML stream. */
      static const CATUnicodeString cReplaceAmpersand      ; 

    /** Replacement character for "<" (less than) in an XML stream. */
      static const CATUnicodeString cReplaceLessThan       ; 

    /** Replacement character for ">" (greater than) in an XML stream. */
      static const CATUnicodeString cReplaceGreaterThan    ; 

    /** Replacement character for "\r" (carriage return) in an XML stream. */
      static const CATUnicodeString cReplaceCarriageReturn ;

    /** Replacement character for "\n" (new line) in an XML stream. */
      static const CATUnicodeString cReplaceNewLine        ;

    /** Replacement character for "\t" (tab) in an XML stream. */
      static const CATUnicodeString cReplaceTab            ;

    /** Replacement character for "\"" (quote mark) in an XML stream. */
      static const CATUnicodeString cReplaceDoubleQuote    ;

    /** Replacement character for "'" (apostrophe) in an XML stream. */
      static const CATUnicodeString cReplaceApostrophe     ;

    /** Blank character. */
      static const CATUnicodeString cBlank                 ;

    /** Header of setting value of an attribute (="). */
      static const CATUnicodeString cStartAttrValue        ;

    /** Epilog of setting value of an attribute ("). */
      static const CATUnicodeString cEndAttrValue          ;

    /** Epilog of XML Node to close attribute valiation(>\n). */
      static const CATUnicodeString cEndXMLNode            ;

    /** Epilog of simple XML node (/>\n). */           
      static const CATUnicodeString cEndSimpleXmlNode      ;

    /** Start end of an XML node (</). */              
      static const CATUnicodeString cStartEndXmlNode       ;

    /** Start an XML comment (<!-- ). */               
      static const CATUnicodeString cStartXmlComment       ;

    /** End an XML comment ( -->). */                  
      static const CATUnicodeString cEndXmlComment         ;

    /** Start an XML directive (<?). */
      static const CATUnicodeString cStartXmlDirective     ;

    /** End an XML directive (?>). */
      static const CATUnicodeString cEndXmlDirective       ;

    /** XML header in UTF8 mode (<?xml version=\"1.0\" encoding=\"UTF-8\"?>). */
      static const CATUnicodeString cXmlUtf8Header         ;

    /** Used for XSL declaration ("xml-stylesheet type=\"text/xsl\" href=\"). */
      static const CATUnicodeString cXslFileHeader         ;

      // --- * XML special values

    /** XML value to false statement "F". */
      static const CATUnicodeString usXmlFalseTag ;

    /** XML value to true statement "T". */
      static const CATUnicodeString usXmlTrueTag  ;

      // -----------------------------------------------
      // --- Constant to ease JSON streaming         ---
      // -----------------------------------------------

      // --- * JSON separators

    /** JSON characters use to begin an array. */
      static const CATUnicodeString usJsonBeginArray      ; // [ left square bracket
                                                          
    /** JSON characters use to end an array. */           
      static const CATUnicodeString usJsonEndArray        ; // ] right square bracket
                                                          
    /** JSON characters use to start an object. */        
      static const CATUnicodeString usJsonBeginObject     ; // { left curly bracket
                                                          
    /** JSON characters use to end an object. */          
      static const CATUnicodeString usJsonEndObject       ; // } right curly bracket
                                                          
    /** JSON characters use as Name separator. */         
      static const CATUnicodeString usJsonNameSeparator   ; // : colon
                                                          
    /** JSON characters use as value separator. */        
      static const CATUnicodeString usJsonValueSeparator  ; // , comma

    /** JSON string delimiter ("). */
      static const CATUnicodeString usJsonStringDelimiter ; // " 

    /** JSON characters use to begin a comment. */
      static const CATUnicodeString usJsonBeginComment    ; // /* left square bracket
                                                          
    /** JSON characters use to end a comment. */           
      static const CATUnicodeString usJsonEndComment      ; // */ right square bracket
 
      // --- * JSON characters to be escaped and their substitution string

      static const CATUnicodeString usQuotationMark  ;
      static const CATUnicodeString usReverseSolidus ;
      static const CATUnicodeString usSolidus        ;
      static const CATUnicodeString usBackspace      ;
      static const CATUnicodeString usFormFeed       ;
      static const CATUnicodeString usLineFeed       ;
      static const CATUnicodeString usCarriageReturn ;
      static const CATUnicodeString usTab            ;

      static const CATUnicodeString usEscapeQuotationMark  ;
      static const CATUnicodeString usEscapeReverseSolidus ;
      static const CATUnicodeString usEscapeSolidus        ;
      static const CATUnicodeString usEscapeBackspace      ;
      static const CATUnicodeString usEscapeFormFeed       ;
      static const CATUnicodeString usEscapeLineFeed       ;
      static const CATUnicodeString usEscapeCarriageReturn ;
      static const CATUnicodeString usEscapeTab            ;

      // --- * JSON special values

      static const CATUnicodeString usJsonFalseTag ;
      static const CATUnicodeString usJsonTrueTag  ;

      // --- * Use in JSON to declare as attribute value the type of node to be created and its component.

      static const CATUnicodeString usClassName     ;
      static const CATUnicodeString usChildListName ;

   protected:
   
    /** File path where the data will be stored. */
      CATUnicodeString _usFilePath   ;

    /** Unicode string use as working area to fill buffer). */
      CATUnicodeString _usTemp       ;
   
    /** Handler on the file on which stream will be saved. */
      unsigned int     _nStreamDesc  ;
   
    /** Enable to define how to manage file descriptor life cycle. */
      int              _nStreamMode  ;

    /** Define streaming format: 
      *   <dl>
      *   <dt>1</dt>   <dd>XML streaming.</dd>
      *   <dt>2</dt>   <dd>JSON streaming.</dd>
      *   </dl>
      */
      int              _nStreamFormat ;

    /** Define write mode of the buffer.
      *   Method return code. 
      * <br><b>Legal values</b>: ( @see PLMExchangeStreamBufferOptions )
      *   <dl>
      *   <dt>FLUSH_AT_BUFFER_FULL</dt>      <dd>Flush to disk when buffer limit is reached.</dd>
      *   <dt>NEVER_FLUSH_BEFORE_COMMIT</dt> <dd>Never flush on disk before commit.</dd>
      *   <dt>TO_MANAGE_PRIVATE_DATA</dt>    <dd>Property on buffer to remind that we are in Private data management.</dd>
      *   <dt>WITH_NEW_LINE</dt>             <dd>Property to ease reading of stream adding new lines in case of JSON or XML.</dd>
      *   </dl>
      */
      int              _nWriteMode   ;

      /** Current cursor position in the stream. */
      unsigned int     _nStreamCurr  ; 

      /** Buffer size. */
      unsigned int     _nStreamMax   ; 

      /** Stream buffer (data are stored in UFT8). */
      char           * _cStreamUTF8  ; 

      /** Capture previous LC_NUMERIC locale environment. */

      static char * _pStoreNumericalLocale ;

   private:
      // --- * Reallocate buffer size.

      int _bufferReallocation( int inMinimalBufferSize ) ;

      // --- * Flush buffer content on disk.

      int _flushBufferOnDisk() ;
} ;

// -----------------------------------------------
// --- To support XML streaming                ---
// -----------------------------------------------

/**
  * Class use to manage XML write buffer.
  *
  * <b>Role</b>:
  * Class to be used to manage easily the streaming in XML.
  */
class ExportedByPLMExchangeModel PLMExchangeXMLStream : public PLMExchangeStreamBuffer
{
   public:
    /**
      * Constructor of a new XML stream buffer.
      * 
      * @param iusFilePath [in]
      *   File path of the file.
      * 
      * @param inMode [in]
      *  Default buffer size
      * 
      * @param inInitialSize [in]
      *  Default buffer size
      */
      PLMExchangeXMLStream( const CATUnicodeString & iusFilePath
                          , int                      inMode        = FLUSH_AT_BUFFER_FULL
                          , int                      inInitialSize = 65512 ) ;

    /**
      * Constructor of a new stream buffer.
      * 
      * @param inFileDescriptor [in]
      *   File descriptor to be used to append the XML representation of the report model (cf CATFopen).
      * 
      * @param inMode [in]
      *  Default buffer size
      * 
      * @param inInitialSize [in]
      *  Default buffer size
      */
      PLMExchangeXMLStream( unsigned int inFileDescriptor
                          , int          inMode        = FLUSH_AT_BUFFER_FULL
                          , int          inInitialSize = 65512 ) ;

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      ~PLMExchangeXMLStream() ;

      // ------------------------------------------------------------
      // --- Method to stream object/attribut as an XML structure ---
      // ------------------------------------------------------------

    /**
      * Add XML header.
      *
      * <br><b>Role</b>: Add XML header with UTF8 mode.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddHeader() ;

    /**
      * Add one XML comment.
      *
      * <br><b>Role</b>: Add one XML comment.
      * 
      * @param icComment [in]
      *   Comment to be added.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddOneComment( const CATUnicodeString & icComment ) ;

    /**
      * Add reference to an XSL file.
      *
      * <br><b>Role</b>: Add reference to an XSL file.
      * 
      * @param icXslFilePath [in]
      *   Absolute or relative path to the XSL file.
      * 
      * @param inMode [in]
      *   Define protocol to be added to file path.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddXslReference( const CATUnicodeString & icXslFilePath , int inMode ) ;

    /**
      * Open one XML node.
      *
      * <br><b>Role</b>: Open one XML node in XML stream.
      * 
      * @param icElement
      *   Element name.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int OpenNode( const CATUnicodeString & icElement ) ;

    /**
      * Start filling XML node without XML child.
      *
      * <br><b>Role</b>:Start filling XML node without XML child.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int StartChildren() ;

    /**
      * Close one node.
      *
      * <br><b>Role</b>:Close one node. in stream.
      * 
      * @param icElement
      *   Element name.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int CloseNode( const CATUnicodeString & icElement ) ;

    /**
      * Close one XML node without XML child.
      *
      * <br><b>Role</b>:Close one XML node. in XML stream in case on no XML child.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int CloseNode() ;

    /**
      * Add one Unicode string XML attribute.
      *
      * <br><b>Role</b>: Add one Unicode string XML attribute in XML stream .
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @param icAttrValue
      *   The attribute value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddAttribute( const CATUnicodeString & icAttrName , const CATUnicodeString & icAttrValue ) ;

    /**
      * Add one string XML attribute.
      *
      * <br><b>Role</b>: Add one string XML attribute in XML stream.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @param icAttrValue
      *   The attribute value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddAttribute( const CATUnicodeString & icAttrName , const CATString & icAttrValue ) ;

    /**
      * Add one floating point attribute.
      *
      * <br><b>Role</b>: Add one floating point attribute in stream.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @param ifValue
      *   The floating point value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddAttribute( const CATUnicodeString & icAttrName , const double ifValue ) ;

    /**
      * Add one integer attribute.
      *
      * <br><b>Role</b>: Add one integer attribute in stream.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @param inValue
      *   The integer value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddAttribute( const CATUnicodeString & icAttrName , const int inValue ) ;

    /**
      * Add one boolean attribute.
      *
      * <br><b>Role</b>: Add one boolean attribute in the stream.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @param ilValue
      *   The boolean value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddAttribute( const CATUnicodeString & icAttrName , const CATBoolean ilValue ) ;

  protected:
    /**
      * Convert a string to manage characters that need to be escaped for XML.
      *
      * <br><b>Role</b>: store in working area converted string on which required characters has been escaped.
      * 
      * @param iusString
      *   The string to stream.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
       int _transformUnicodeStringInXmlString( const CATUnicodeString &  iusString ) ;
} ;

// -----------------------------------------------
// --- To support JSON streaming              ---
// -----------------------------------------------

/**
  * Class use to manage JSON write buffer.
  *
  * <b>Role</b>:
  * Class to be used to manage easily the streaming as one JSON stream.
  */
class ExportedByPLMExchangeModel PLMExchangeJsonStream : public PLMExchangeStreamBuffer
{
   public:
    /**
      * Constructor of a new JSON stream buffer.
      * 
      * @param iusFilePath [in]
      *   File path of the file.
      * 
      * @param inMode [in]
      *  Default buffer size
      * 
      * @param inInitialSize [in]
      *  Default buffer size
      */
      PLMExchangeJsonStream( const CATUnicodeString & iusFilePath
                           , int                      inMode        = FLUSH_AT_BUFFER_FULL
                           , int                      inInitialSize = 65512 ) ;

    /**
      * Constructor of a new JSON stream buffer.
      * 
      * @param inFileDescriptor [in]
      *   File descriptor to be used to append the XML representation of the report model (cf CATFopen).
      * 
      * @param inMode [in]
      *  Default buffer size
      * 
      * @param inInitialSize [in]
      *  Default buffer size
      */
      PLMExchangeJsonStream( unsigned int inFileDescriptor
                           , int          inMode        = FLUSH_AT_BUFFER_FULL
                           , int          inInitialSize = 65512 ) ;

    /**
      * Destructor.
      * 
      * <br><b>Role</b>: Destructor.
      */
      ~PLMExchangeJsonStream() ;

      // ------------------------------------------------------------------
      // --- Method to stream object/name/value/array as an JSON stream ---
      // ------------------------------------------------------------------

   /**
      * Add header.
      *
      * <br><b>Role</b>: Add header with UTF8 mode.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddHeader() ;

    /**
      * Add epilog.
      *
      * <br><b>Role</b>: Add epilog.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddEpilog() ;

    /**
      * Add one comment.
      *
      * <br><b>Role</b>: Add one comment.
      * 
      * @param icComment [in]
      *   Comment to be added.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddOneComment( const CATUnicodeString & icComment ) ;

    /**
      * Open one JSON object.
      *
      * <br><b>Role</b>: Open one JSON object in JSON stream.
      * 
      * @param icElement
      *   Element name.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int OpenNode( const CATUnicodeString & icElement ) ;

    /**
      * Start filling JSON object without JSON child.
      *
      * <br><b>Role</b>:Start filling XML node without XML child.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int StartChildren() ;

    /**
      * Close filling node with at least one child.
      *
      * <br><b>Role</b>:Close filling node with at least one child.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int CloseChildren() ;

    /**
      * Close one JSON node.
      *
      * <br><b>Role</b>:Close one node in stream.
      * 
      * @param icElement
      *   Element name.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int CloseNode( const CATUnicodeString & icElement ) ;

    /**
      * Close one JSON object without child.
      *
      * <br><b>Role</b>:Close one JSON object in JSON stream in case on no child.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int CloseNode() ;

    /**
      * Add one JSON name/value.
      *
      * <br><b>Role</b>: Add one JSON name/value in JSON stream.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @param icAttrValue
      *   The attribute value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddAttribute( const CATUnicodeString & icAttrName , const CATUnicodeString & icAttrValue ) ;

    /**
      * Add one JSON name/value.
      *
      * <br><b>Role</b>: Add one JSON name/value in JSON stream.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @param icAttrValue
      *   The attribute value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddAttribute( const CATUnicodeString & icAttrName , const CATString & icAttrValue ) ;

    /**
      * Add one floating point attribute.
      *
      * <br><b>Role</b>: Add one floating point attribute in stream.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @param ifValue
      *   The floating point value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddAttribute( const CATUnicodeString & icAttrName , const double ifValue ) ;

    /**
      * Add one integer attribute.
      *
      * <br><b>Role</b>: Add one integer attribute in stream.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @param inValue
      *   The integer value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddAttribute( const CATUnicodeString & icAttrName , const int inValue ) ;

    /**
      * Add one boolean attribute.
      *
      * <br><b>Role</b>: Add one boolean attribute in the stream.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @param ilValue
      *   The boolean value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddAttribute( const CATUnicodeString & icAttrName , const CATBoolean ilValue ) ;

    /**
      * Check if support mode for multi-values.
      *
      * <br><b>Role</b>: Check if support mode for multi-values.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      *   <dl>
      *   <dt>0</dt> <dd>Multi-values are supported as multi-nodes.<dd> 
      *   <dt>1</dt> <dd>Multi-values direct support (as case of JSON).<dd> 
      *   </dl>
      */
      int IsMultiValueSupported() const ;

    /**
      * Start filling node with at least one child.
      *
      * <br><b>Role</b>: Start filling node with at least one child.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      *   <dl>
      *   <dt>0</dt> <dd>operation runs well and stream support multi-values.<dd> 
      *   <dt>1</dt> <dd>In case of error.<dd> 
      *   <dt>-1</dt> <dd>Multi-Values not supported, need to introduce values one by one as normal attributes.<dd> 
      *   </dl>
      */
      int StartMultiValue( const CATUnicodeString & icAttrName ) ;

    /**
      * Close filling node with at least one child.
      *
      * <br><b>Role</b>: Close filling node with at least one child.
      * 
      * @param icAttrName
      *   The attribute name.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int CloseMultiValue( const CATUnicodeString & icAttrName ) ;

    /**
      * Add one unicode string value.
      *
      * <br><b>Role</b>: Add one unicode string value in stream.
      * 
      * @param icAttrValue
      *   The attribute value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddOneValue( const CATUnicodeString & icAttrValue ) ;

    /**
      * Add one string value.
      *
      * <br><b>Role</b>: Add one string value in stream.
      * 
      * @param icAttrValue
      *   The attribute value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddOneValue( const CATString & icAttrValue ) ;

    /**
      * Add one floating point value.
      *
      * <br><b>Role</b>: Add one floating point value in stream.
      * 
      * @param ifValue
      *   The floating point value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddOneValue( const double ifValue ) ;

    /**
      * Add one integer value.
      *
      * <br><b>Role</b>: Add one integer value in stream.
      * 
      * @param inValue
      *   The integer value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddOneValue( const int inValue ) ;

    /**
      * Add one boolean value.
      *
      * <br><b>Role</b>: Add one boolean value in the stream.
      * 
      * @param ilValue
      *   The boolean value.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
      int AddOneValue( const CATBoolean ilValue ) ;

  protected:
    /**
      * Convert a string to manage characters that need to be escaped for JSON.
      *
      * <br><b>Role</b>: store in working area converted string on which required characters has been escaped.
      * 
      * @param iusString
      *   The string to stream.
      * 
      * @return
      *   Method return code 
      *   <br><b>Legal values</b>: Returns 0 if operation runs well. 
      */
       int _transformUnicodeStringInJsonString( const CATUnicodeString &  iusString ) ;

      /** Capture JSON streaming status to identify if a comma is needed or not. */
      int _nStatus ;
} ;
#endif
