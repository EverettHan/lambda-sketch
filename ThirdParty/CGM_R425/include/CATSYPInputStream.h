#ifndef CATSYPInputStream_H
#define CATSYPInputStream_H

#include "IntroInfra.h"

/** @ingroup groupVidIO
 * Base interface for an input stream of bytes.
 * @par Implementation Notes
 * Sub-classes must implement the function @ref #Read.
 *
 * @par Error Handling
 * Errors are signaled by the @ref #Read function with
 * its boolean return code. When a stream encountered an
 * error, it is considered to be in error and can not be
 * reseted. Note that only the last error is available
 * to the caller; it can be queried using @ref #GetLastErrorKind.
 *
 * @par
 * Note also that details about the error may be available
 * through an other APIs specific to sub-classes.
 *
 * @see CATSYPCodedInputStream
 */
class ExportedByIntroInfra CATSYPInputStream
{
public:
  /**
   * The type of error that occured.
   */
  enum ErrorKind {
    /** There has been no error */
    NoError,
    /** The last read failed because the end of the stream has been reached */
    EndOfStream,
    /** An IO error occured */
    IOError,
    /** The input of the Write function was invalid */
    InvalidInput,
    /** An internal error occured in the stream */
    InternalError
  };
protected:
  CATSYPInputStream();
public:
  virtual ~CATSYPInputStream();
  /**
   * Read some bytes from the stream.
   *
   * Note that this function may not read all the bytes requested.<br/>
   * The caller may need to call this function in a loop to read
   * all the bytes it needs (see @ref CATSYPCodedInputStream#ReadByteArray).
   *
   * @param i_aValue the byte buffer where read bytes will be written.<br/>
   * Can be @c NULL only if @a i_aValueSize is @c 0. If @c NULL is given when 
   * @a i_aValueSize is @c !=0, then the error is positioned as @ref #InvalidInput.
   *
   * @param i_aValueSize the size of the byte buffer. <br/>
   * Must be @c >=0. If @c <0, the error is positioned as @ref #InvalidInput.<br/>
   * If @c ==0, the function immediately returns doing nothing.
   *
   * @return the number of bytes read. @c -1 if an error occured. In that case 
   * the type of the error can be retrieved using @ref #GetLastErrorKind.<br/>
   * Note that sub-classes may have specific methods to get more informations
   * about the error.<br/>
   * Note that reaching the end of the stream is the error @ref #EndOfStream.<br/>
   * Note that an implementation of Read might return @c 0 only if @a i_aValueSize
   * is @c 0. In other cases @c Read should block as long as at least one byte is
   * not available.
   */
  virtual int Read(unsigned char *i_aValue, int i_aValueSize) = 0;
  /**
   * Get the type of error that occured the last time @ref #Read
   * failed.
   *
   * @note 
   * This error flag is not reseted when a call to @ref #Read succeeds.
   *
   * @return the last error kind
   */
  ErrorKind GetLastErrorKind() const;
  /**
   * Convert the given enum value to a string (which is the same as the
   * C++ id of the enum).
   *
   * @return the string representing the enum value, @c "invalid_input" if
   * the given value is invalid.
   */
  static const char *ErrorKind2String(ErrorKind i_errorKind);
protected:
  /**
   * Sets the last error.
   *
   * @param i_errorKind the error. Not that you must NOT call it
   * with @ref #NoError!
   */
  void SetError(ErrorKind i_errorKind);
private:
  CATSYPInputStream(const CATSYPInputStream&);
  CATSYPInputStream &operator=(const CATSYPInputStream&);
private:
  /** The last error */
  ErrorKind _lastErrorKind;
};

#endif // CATSYPInputStream_H
