#ifndef CATSYPCodedOutputStream_H
#define CATSYPCodedOutputStream_H

#include "IntroInfra.h"
#include <CATDataType.h>

class CATUnicodeString;
class CATSYPOutputStream;

/** @ingroup groupVidIO
 * Macro that can be used in a function that streams an object
 * in a CATSYPCodedOutputStream.
 * This macro will:
 *   - call the @c Write* function
 *   - check that if an error occured
 *   - [ if an error occured ] it will check if it is an @ref CATSYPCodedOutputStream#IOError
 *   - [ if an error occured & if this error is NOT an @ref CATSYPCodedOutputStream#IOError ] it will
 *     make a @ref FAILURE with a diagnostic and which message will be the error
 *   - [ if an error occured ] it will return @c 0.
 *
 * 
 * \par Example
 * \code
 * int MyClass::Stream(CATSYPCodedOutputStream &i_outputStream) 
 * {
 *   // Write the version of the stream (0)
 *   CHECK_WRITE_RET0(i_outputStream, WriteVarUInt32(0));
 *   CHECK_WRITE_RET0(i_outputStream, WriteUnicodeString(_data));
 *   ...
 *   return 1;
 * }
 * \endcode
 */
#define CHECK_WRITE_RET0(codedStreamRef, writeCall)                     \
  do {                                                                  \
    int rc = codedStreamRef.writeCall;                                  \
    if (!rc) {                                                          \
      if (codedStreamRef.GetLastErrorKind()!=CATSYPCodedOutputStream::IOError) { \
        FAILURE_MSG(#writeCall " failed for an error that is not an IOError (see message)", \
                    CATSYPCodedOutputStream::ErrorKind2String(codedStreamRef.GetLastErrorKind())); \
      }                                                                 \
      return 0;                                                         \
    }                                                                   \
  } while(0)


/** @ingroup groupVidIO
 * Class that encodes and writes to an @ref #CATSYPOutputStream 
 * some basic data types.
 *
 * @par Encoding
 * Note that all encodings are done in little-endian, that 
 * means that the least significant byte is always written 
 * first.
 *
 * @par
 * The encoding is specified on each @c Write* function.
 *
 * @par Error handling
 * Errors are signaled by the @c Write* function with
 * its boolean return code. When a stream encountered an
 * error, it is considered to be in error and can not be
 * reseted. Note that only the last error is available
 * to the caller; it can be queried using @ref #GetLastErrorKind.
 *
 * @par Unsigned VarInt encoding
 * The functions WriteVarUInt32 and WriteVarUInt64 are using a
 * variable length encoding. This encoding is done by dividing
 * the input value in groups of 7 bits.
 *
 * @par
 * Each group is written in the least significant bits of a byte.<br/>
 * The most most significant bit is set to:
 *   - @c 0 if the byte is the last byte of the encoding. That means
 *     that all following groups are only composed of @c 0.
 *   - @c 1 if more bytes follow.
 *
 * @par
 * For example when writing the 32 bits number (in binary, the
 * most significant bit written first):
 * @verbatim  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 1 1 0 1 0 1 0  1 1 0 0 1 1 0 1@endverbatim
 *
 * @par
 * This number is divided in groups of 7 bits:
 * @verbatim  0 0 0 0 | 0 0 0 0 0 0 0 | 0 0 0 0 0 0 1 | 1 0 1 0 1 0 1 | 1 0 0 1 1 0 1@endverbatim
 *
 * @par
 * Then each group is written in little endian order in a byte (
 * the most significant bit is separated by a | from other bits):
 * @verbatim
   byte 0 : 1 | 1 0 0 1 1 0 1
   byte 1 : 1 | 1 0 1 0 1 0 1
   byte 2 : 0 | 0 0 0 0 0 0 1@endverbatim
 *
 * @par
 * Note that this number is written in only three bytes in that 
 * case since other bits are null.
 *
 * @par Signed VarInt encoding
 * The function WriteVarInt32 and WriteVarInt64 are also using
 * a variable length encoding but the algorithm is a little more
 * complex.
 *
 * @par
 * Note that we could simply use the same algorithm to store 
 * signed integers and unsigned integer. The issue is that in
 * that case the negative numbers would always use the maximum
 * number of bytes (i.e. 5 bytes) since their bit sign (the most
 * significant bit) is always 1.
 *
 * @par
 * Consequently, before applying the algorithm used to encode
 * unsigned values, we modify the integer by:
 *  - shifting all bits by 1 place to the left.<br/>
 *    This removes the sign bit and make the least significant
 *    bit 0.
 *  - invert all bits of the previously obtained value if the
 *    initial value was negative.<br/>
 *    As a consequence the least significant bit is now the
 *    sign bit and the most significant bits of small negative
 *    values are now 0. Note that by small negative value we
 *    mean negative values next to 0 (such as -2, -10, ...).
 *
 * @par
 * Then we encode this result using the same algorithm as unsigned
 * value.
 *
 * @par
 * This transformation is called zig-zagging since it interleaves
 * the small negative values between the small positive values:
 *   - 0 is converted to 0
 *   - -1 is converted to 1
 *   - 1 is converted to 2
 *   - -2 is converted to 3
 *   - ...
 *
 * @par
 * Small negative values are now encoded using only one byte which
 * was the expected result.
 *
 * @par
 * Note that positive values are also modified before being encoded
 * consequently the signed variable length encoding of a positive
 * value is always different than the unsigned encoding of the same
 * value.
 *
 * @par Macro
 * The macro @ref CHECK_WRITE_RET0 can be use to handle errors
 * in code that uses a @c CATSYPCodedOutputStream to stream a
 * component.<br>
 * See macro documentation for details.
 *
 * @see CATSYPCodedInputStream
 * @see CATSYPOutputStream
 */
class ExportedByIntroInfra CATSYPCodedOutputStream
{
public:
  /**
   * The type of error that occured.
   */
  enum ErrorKind {
    /** There has been no error */
    NoError,
    /** A call to the underlying CATSYPOutputStream failed.
     *  The function CATSYPOutputStream#GetLastErrorKind should
     *  be called on this stream to find out details about the error
     */
    IOError,
    /** The input of the @c Write* function was invalid */
    InvalidInput,
    /** An internal error occured in the class */
    InternalError
  };
public:
  /**
   * Initialize the coded output stream.
   * @param i_pStream the stream to write to. Can't be @c NULL.
   * Note that there is no reference mechanism for CATSYPOutputStream
   * streams, consequently the caller must ensure that the stream
   * is not destroyed until this instance is destroyed.
   */
  CATSYPCodedOutputStream(CATSYPOutputStream *i_pStream);
  /** Destructor */
  ~CATSYPCodedOutputStream();
  /**
   * Write a single byte.
   * @param i_value the value to write
   * @return @c !=0 if the encoding and the write succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int WriteByte(unsigned char i_value);
  /**
   * Write an array of bytes.
   * @param i_aValue the input bytes. Can be @c NULL only if i_aValueSize
   * is @c 0. If @c NULL is given when @a i_aValueSize is @c !=0, then 
   * the error is positioned as @ref #InvalidInput.
   * @param i_aValueSize the size of the input bytes. Must be @c >=0.
   * If @c <0, the error is positioned as @ref #InvalidInput.
   * @return @c !=0 if the encoding and the write succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int WriteByteArray(const unsigned char *i_aValue, int i_aValueSize);
  /**
   * Write a 4 bytes long signed integer in little endian.
   * For example @c WriteInt32(0x12345678) will write @c "\x78\x56\x34\x12".
   * @param i_value the value to write
   * @return @c !=0 if the encoding and the write succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int WriteInt32(CATINT32 i_value);
  /**
   * Write a 4 bytes long unsigned integer in little endian.
   * For example @c WriteUInt32(0x12345678) will write @c "\x78\x56\x34\x12".
   * @param i_value the value to write
   * @return @c !=0 if the encoding and the write succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int WriteUInt32(CATUINT32 i_value);
  /**
   * Write a 4 bytes long signed integer in little endian using a
   * variable length encoding. See class documentation about VarInt.
   *
   * For example @c WriteVarInt32(-2) will write @c "\x03".
   *
   * @note
   * @c WriteVarInt32(x) gives a totaly different result than
   * @c WriteVarUInt32(x) (see class documentation).
   * @param i_value the value to write
   * @return @c !=0 if the encoding and the write succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int WriteVarInt32(CATINT32 i_value);
  /**
   * Write a 4 bytes long unsigned integer in little endian using a
   * variable length encoding. See class documentation about VarInt.
   *
   * For example WriteVarUInt32(3) will write "\x03".
   *
   * @note
   * @c WriteVarInt32(x) gives a totaly different result than
   * @c WriteVarUInt32(x) (see class documentation).
   * @param i_value the value to write
   * @return @c !=0 if the encoding and the write succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int WriteVarUInt32(CATUINT32 i_value);
  /**
   * Write a 8 bytes long signed integer in little endian.
   * For example WriteInt64(0x123456789ABCDEF0L) will write "\xf0\xde\xbc\x9a\x78\x56\x34\x12".
   * @param i_value the value to write
   * @return @c !=0 if the encoding and the write succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int WriteInt64(CATLONG64 i_value);
  /**
   * Write a 8 bytes long unsigned integer in little endian.
   * For example @c WriteUInt64(0x123456789ABCDEF0L) will write @c "\xf0\xde\xbc\x9a\x78\x56\x34\x12".
   * @param i_value the value to write
   * @return @c !=0 if the encoding and the write succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int WriteUInt64(CATULONG64 i_value);
  /**
   * Write a 8 bytes long signed integer in little endian using a
   * variable length encoding. See class documentation about VarInt.
   *
   * For example @c WriteVarInt64(-2L) will write @c "\x03".
   *
   * @note
   * @c WriteVarInt64(x) gives a totaly different result than
   * @c WriteVarUInt64(x) (see class documentation).
   * @param i_value the value to write
   * @return @c !=0 if the encoding and the write succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int WriteVarInt64(CATLONG64 i_value);
  /**
   * Write a 8 bytes long unsigned integer in little endian using a
   * variable length encoding. See class documentation about VarInt.
   *
   * For example @c WriteVarUInt64(0x03L) will write @c "\x03".
   *
   * @note
   * @c WriteVarInt64(x) gives a totaly different result than
   * @c WriteVarUInt64(x) (see class documentation).
   * @param i_value the value to write
   * @return @c !=0 if the encoding and the write succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int WriteVarUInt64(CATULONG64 i_value);
  /**
   * Write the float in little endian unsing the IEEE 754 floating-point 
   * "single format" bit layout.
   *
   * For example @c WriteFloat(3.5f) will write @c "\x00\x00\x60\x40".
   *
   * @note
   * All floating point values are permitted, including NaN, +Inf and -Inf.
   * @param i_value the value to write
   * @return @c !=0 if the encoding and the write succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int WriteFloat(float i_value);
  /**
   * Write the double in little endian unsing the IEEE 754 floating-point 
   * "double format" bit layout.
   *
   * For example @c WriteDouble(3.5) will write @c "\x00\x00\x00\x00\x00\x00\x0c\x40".
   *
   * @note
   * All floating point values are permitted, including NaN, +Inf and -Inf.
   * @param i_value the value to write
   * @return @c !=0 if the encoding and the write succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int WriteDouble(double i_value);
  /**
   * Write the unicode string in UTF-8. 
   * The written data are:
   *   - the length of the UTF-8 bytes written as a VarUInt32
   *   - the UTF-8 bytes
   *
   * For example @c WriteUnicodeString("abc") will write @c "\x03\x61\x62\x63".
   * @param i_string the value to write
   * @return @c !=0 if the encoding and the write succeeded, else @c 0. In that
   * case the function @ref #GetLastErrorKind can be used to get details
   * about the error.
   */
  int WriteUnicodeString(const CATUnicodeString &i_string);
  /**
   * Get the type of error that occured the last time a @c Write* function
   * failed.
   * Note that this error flag is not reseted when a call to a @c Write*
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
  CATSYPCodedOutputStream(const CATSYPCodedOutputStream&);
  CATSYPCodedOutputStream &operator=(const CATSYPCodedOutputStream&);
protected:
  /**
   * Sets the last error.
   * @param i_errorKind the error. Not that you must NOT call it
   * with @ref #NoError!
   */
  void SetError(ErrorKind i_errorKind);
private:
  /**
   * Encode the given 64bits unsigned value using varint algorithm.
   *
   * Note that if the function fails (due to an internal error), it
   * will have called @ref #SetError. Consequently, the caller does
   * not have to call SetError.
   *
   * Note that: <tt>9 @< 64/7 @< 10</tt>; consequently, there are at most 10 
   * bytes when encoding a 64-bits integer to a var int.
   * @param i_value the value to encode
   * @param o_aOutputBytes [out] the byte array where the result will be written,
   * it may be modified even if the function failed. It must be at least 10 bytes
   * long.
   * @param o_size [out] the number of bytes actually used to encode
   * the value. It may not have been modified if the function failed.
   * @return @c !=0 if the function succeeded, @c 0 if it failed (in that
   * case, SetError has already been called).
   */
  int EncodeVarUInt64(CATULONG64 i_value, unsigned char o_aOutputBytes[10], int &o_size);
private:
  /** The underlying stream where bytes are to be written */
  CATSYPOutputStream *_pStream;
  /** The last error */
  ErrorKind _lastErrorKind;
};

#endif // CATSYPCodedOutputStream_H

