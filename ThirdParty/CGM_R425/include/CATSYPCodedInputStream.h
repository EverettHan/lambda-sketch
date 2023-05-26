#ifndef CATSYPCodedInputStream_H
#define CATSYPCodedInputStream_H

#include "IntroInfra.h"
#include <CATDataType.h>

class CATUnicodeString;
class CATSYPInputStream;

/** @ingroup groupVidIO
 * Macro that can be used in a function that unstreams an object
 * from a CATSYPCodedInputStream.
 * This macro will:
 *   - call the @c Read* function
 *   - check that if an error occured
 *   - [ if an error occured ] it will check if it is an @href CATSYPCodedInputStream::IOError
 *   - [ if an error occured & if this error is NOT an @href CATSYPCodedInputStream::IOError ] it will
 *     make a @ref FAILURE with a diagnostic and which message will be the error
 *   - [ if an error occured ] it will return @c 0.
 *
 * \par Example
 * \code
 * MyClass * MyClass::Unstream(CATSYPCodedInputStream &i_inputStream) 
 * {
 *   // Read the version of the stream
 *   unsigned int version = 0xFFFFFFFF;
 *   CHECK_READ_RET0(i_outputStream, ReadVarUInt32(version));
 *   CHECK_TRUE_RETV(version == 0, 0);
 *   CATUnicodeString data;
 *   CHECK_READ_RET0(i_outputStream, ReadUnicodeString(data));
 *   ...
 * }
 * \endcode
 */
#define CHECK_READ_RET0(codedStreamRef, readCall)                       \
  do {                                                                  \
    int rc = codedStreamRef.readCall;                                   \
    if (!rc) {                                                          \
      if (codedStreamRef.GetLastErrorKind()!=CATSYPCodedInputStream::IOError) { \
        FAILURE_MSG(#readCall " failed for an error that is not an IOError (see message)", \
                    CATSYPCodedInputStream::ErrorKind2String(codedStreamRef.GetLastErrorKind())); \
      }                                                                 \
      return 0;                                                         \
    }                                                                   \
  } while(0)

/** @ingroup groupVidIO
 * Class that reads and decodes from a @ref #CATSYPInputStream
 * some basic data types.
 *
 * @par Encoding
 * Note that all encodings are done in little-endian, that 
 * means that the least significant byte is always written 
 * first.
 *
 * @par
 * The encoding is specified on each @c Read* function.
 *
 * @par Error handling
 * Errors are signaled by the @c Read* function with
 * its boolean return code.<br/>When a stream encountered an
 * error, it is considered to be in error and can not be
 * reseted. Note that only the last error is available
 * to the caller; it can be queried using @ref #GetLastErrorKind.
 *
 * @par VarInt encoding
 * See documentation of class @ref #CATSYPCodedOutputStream for
 * details about variable length encoding.
 *
 * @par Macro
 * The macro @ref CHECK_READ_RET0 can be use to handle errors
 * in code that uses a @c CATSYPCodedInputStream to stream a
 * component.<br>
 * See macro documentation for details.
 *
 * @see CATSYPCodedOutputStream
 * @see CATSYPInputStream
 */
class ExportedByIntroInfra CATSYPCodedInputStream
{
public:
  /**
   * The type of error that occured.
   */
  enum ErrorKind {
    /** There has been no error */
    NoError,
    /** A call to the underlying @ref CATSYPInputStream failed.
     *  The function @ref CATSYPInputStream#GetLastErrorKind should
     *  be called on this stream to find out details about the error
     */
    IOError,
    /** A data is not encoded correctly. For example there are
     *  too many bits in a VarInt.
     */
    DecodingError,
    /** The input of the @c Read* function was invalid*/
    InvalidInput,
    /** An internal error occured in the class */
    InternalError
  };
public:
  /**
   * Initialize the coded input stream.
   * @param i_pStream the stream to read from. Can't be NULL.<br/>
   * Note that there is no reference mechanism for CATSYPInputStream
   * streams, consequently the caller must ensure that the stream
   * is not destroyed until this instance is destroyed.
   */
  CATSYPCodedInputStream(CATSYPInputStream *i_pStream);
  /** Destructor */
  ~CATSYPCodedInputStream();
  /**
   * Read a single byte.
   * @param o_value [out] the value to read
   * @return @c !=0 if the read and the decoding succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int ReadByte(unsigned char &o_value);
  /**
   * Read an array of bytes.
   * Note that the main difference between this function and
   * @ref CATSYPInputStream#Read is that this function will read exactly
   * @a i_aValueSize bytes from the input stream (or break if a 
   * @ref CATSYPInputStream#Read failed).
   * @param i_aValue the buffer for the output bytes. Can be @c NULL only if 
   * @a i_aValueSize is @c 0. If @c NULL is given when i_aValueSize is != @c 0, then 
   * the error is positioned as @ref #InvalidInput.
   * @param i_aValueSize the size of the output bytes. Must be @c >=0.
   * If @c <0, the error is positioned as @ref #InvalidInput.
   * @return @c !=0 if the read and the decoding succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int ReadByteArray(unsigned char *i_aValue, int i_aValueSize);
  /**
   * Read a 4 bytes long signed integer in little endian.
   * For example @c ReadInt32 for data @c "\x78\x56\x34\x12" will return @c 0x12345678.
   * @param o_value [out] the value to read
   * @return @c !=0 if the read and the decoding succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int ReadInt32(CATINT32 &o_value);
  /**
   * Read a 4 bytes long unsigned integer in little endian.
   * For example @c ReadUInt32 for data @c "\x78\x56\x34\x12" will return @c 0x12345678.
   * @param o_value [out] the value to read
   * @return @c !=0 if the read and the decoding succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int ReadUInt32(CATUINT32 &o_value);
  /**
   * Read a 4 bytes long signed integer in little endian using a
   * variable length encoding. See class documentation about VarInt.
   *
   * For example ReadVarInt32 for data @c "\x03" will return @c -2.
   *
   * @note
   * @c ReadVarInt32(x) gives a totaly different result than
   * @c ReadVarUInt32(x) (see class documentation).
   * @param o_value [out] the value to read
   * @return @c !=0 if the read and the decoding succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int ReadVarInt32(CATINT32 &o_value);
  /**
   * Read a 4 bytes long unsigned integer in little endian using a
   * variable length encoding. See class documentation about VarInt.
   *
   * For example @c ReadVarUInt32 for data @c "\x03" will return @c 3.
   *
   * @note
   * @c ReadVarInt32(x) gives a totaly different result than
   * @c ReadVarUInt32(x) (see class documentation).
   * @param o_value [out] the value to read
   * @return @c !=0 if the read and the decoding succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int ReadVarUInt32(CATUINT32 &o_value);
  /**
   * Read a 8 bytes long signed integer in little endian.
   * For example @c ReadInt64 for data @c "\xf0\xde\xbc\x9a\x78\x56\x34\x12" will return @c 0x123456789ABCDEF0L.
   * @param o_value [out] the value to read
   * @return @c !=0 if the read and the decoding succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int ReadInt64(CATLONG64 &o_value);
  /**
   * Read a 8 bytes long unsigned integer in little endian.
   * For example @c ReadUInt64 for data @c "\xf0\xde\xbc\x9a\x78\x56\x34\x12" will return @c 0x123456789ABCDEF0L.
   * @param o_value [out] the value to read
   * @return @c !=0 if the read and the decoding succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int ReadUInt64(CATULONG64 &o_value);
  /**
   * Read a 8 bytes long signed integer in little endian using a
   * variable length encoding. See class documentation about VarInt.
   *
   * For example @c ReadVarInt64 for data @c "\x03" will return @c -2L.
   *
   * @note
   * @c ReadVarInt64(x) gives a totaly different result than
   * @c ReadVarUInt64(x) (see class documentation).
   * @param o_value [out] the value to read
   * @return @c !=0 if the read and the decoding succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int ReadVarInt64(CATLONG64 &o_value);
  /**
   * Read a 8 bytes long unsigned integer in little endian using a
   * variable length encoding. See class documentation about VarInt.
   *
   * For example @c ReadVarUInt64 for data @c "\x03" will return @c 0x03L.
   *
   * @note
   * @c ReadVarInt64(x) gives a totaly different result than
   * @c ReadVarUInt64(x) (see class documentation).
   * @param o_value [out] the value to read
   * @return @c !=0 if the read and the decoding succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int ReadVarUInt64(CATULONG64 &o_value);
  /**
   * Read the float in little endian unsing the IEEE 754 floating-point 
   * "single format" bit layout.
   * For example @c ReadFloat for data @c "\x00\x00\x60\x40" will return @c 3.5f.
   *
   * @note
   * All floating point values are permitted, including NaN, +Inf and -Inf.
   * @param o_value [out] the value to read
   * @return @c !=0 if the read and the decoding succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int ReadFloat(float &o_value);
  /**
   * Read the double in little endian unsing the IEEE 754 floating-point 
   * "double format" bit layout.
   * For example @c ReadDouble for data @c "\x00\x00\x00\x00\x00\x00\x0c\x40" will return @c 3.5.
   *
   * @note
   * All floating point values are permitted, including NaN, +Inf and -Inf.
   * @param o_value [out] the value to read
   * @return @c !=0 if the read and the decoding succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int ReadDouble(double &o_value);
  /**
   * Read the unicode string in UTF-8. 
   * The data are expected to be:
   *   - the length of the UTF-8 bytes written as a VarUInt32
   *   - the UTF-8 bytes
   *
   * For example @c ReadUnicodeString for data @c "\x03\x61\x62\x63" will return @c "abc".
   * @param o_string [out] the value to read
   * @return @c !=0 if the read and the decoding succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int ReadUnicodeString(CATUnicodeString &o_string);
  /**
   * Get the type of error that occured the last time a @c Read* function
   * failed.
   * Note that this error flag is not reseted when a call to a @c Read*
   * function succeeds.
   * @return the last error kind
   */
  ErrorKind GetLastErrorKind() const;
  /**
   * Convert the given enum value to a string (which is the same as the
   * C++ id of the enum).
   * @return the string representing the enum value, "invalid_input" if
   * the given value is invalid.
   */
  static const char *ErrorKind2String(ErrorKind i_errorKind);
private:
  CATSYPCodedInputStream(const CATSYPCodedInputStream&);
  CATSYPCodedInputStream &operator=(const CATSYPCodedInputStream&);
protected:
  /**
   * Sets the last error.
   * @param i_errorKind the error. Not that you must NOT call it
   * with @ref #NoError!
   */
  void SetError(ErrorKind i_errorKind);
private:
  /**
   * Read and decode a unsigned integer encoded using a variable
   * length encoding (see this class documentation and 
   * @ref CATSYPCodedOutputStream class documentation).
   *
   * Note that this function can be used to decode VarInts up
   * to 64bits, but you can limit the number of bytes it tries
   * to decode before failing.
   *
   * Note that this function checks that there is no more than
   * 64bits of data encoded. If there is more, it set the error
   * to @ref #DecodingError. But if this function is used to
   * decode a number that has less than 64bits, the caller has
   * to check that there is no more than the expected number of
   * bits in the returned value.
   *
   * @param o_value [out] the value to read
   * @param i_maxNbBytes the number of bytes that this function
   * should try to find the last byte of the encoding (i.e. the
   * one that has it most significant bit set to @c 0). If this
   * function read @a i_maxNbBytes bytes that all have their most
   * significant bit set to @c 1, it will fail and set the error
   * to @ref #DecodingError. This value should be @c >=1 and
   * @c <=10.
   * @return @c !=0 if the read and the decoding succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error. Note that if i_maxNbBytes is invalid, then
   * the error will be @ref #InvalidInput.
   */
  int DecodeVarUInt(CATULONG64 &o_value, int i_maxNbBytes);
private:
  /** The underlying stream where bytes are to be read from */
  CATSYPInputStream *_pStream;
  /** The last error */
  ErrorKind _lastErrorKind;
};

#endif // CATSYPCodedInputStream_H
