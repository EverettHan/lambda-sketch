#ifndef CATSYPOutputStream_H
#define CATSYPOutputStream_H

#include "IntroInfra.h"

/** @ingroup groupVidIO
 * Base interface for an output stream of bytes.
 * @par Implementation Notes
 * Sub-classes must implement the function @ref #Write.
 *
 * @par Error Handling
 * Errors are signaled by the @ref #Write function with
 * its boolean return code. When a stream encountered an
 * error, it is considered to be in error and can not be
 * reseted. Note that only the last error is available
 * to the caller; it can be queried using @ref #GetLastErrorKind.
 *
 * @par
 * Note also that details about the error may be available
 * through an other APIs specific to sub-classes.
 *
 * @see CATSYPCodedOutputStream
 */
class ExportedByIntroInfra CATSYPOutputStream
{
public:
  /**
   * The type of error that occured.
   */
  enum ErrorKind {
    /** There has been no error */
    NoError,
    /** An IO error occured */
    IOError,
    /** The input of the Write function was invalid */
    InvalidInput,
    /** An internal error occured in the stream */
    InternalError
  };
protected:
  CATSYPOutputStream();
public:
  virtual ~CATSYPOutputStream();
  /**
   * Write the given bytes.
   *
   * Note that this function will write all the bytes. This API
   * does not authorize a partial write.<br/>For example, if this
   * interface is implemented for a socket, the implementation
   * of this function should loop until all bytes are written.
   *
   * @param i_aValue the input bytes. Can be @c NULL only if @a i_aValueSize
   * is @c 0. If @c NULL is given when @a i_aValueSize is @c !=0, then 
   * the error is positioned as @ref #InvalidInput.
   *
   * @param i_aValueSize the size of the input bytes. Must be @c >=0.
   * If @c <0, the error is positioned as @ref #InvalidInput.
   *
   * @return @c !=0 if the write succeeded (no error is positioned),
   * @c 0 if an error occured. In that case the type of the error
   * can be retrieved using @ref #GetLastErrorKind.<br/>Note that
   * sub-classes may have specific methods to get more informations
   * about the error.
   */
  virtual int Write(const unsigned char *i_aValue, int i_aValueSize) = 0;
  /**
   * Get the type of error that occured the last time @ref #Write
   * failed.
   *
   * @note
   * This error flag is not reseted when a call to @ref #Write succeeds.
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
  CATSYPOutputStream(const CATSYPOutputStream&);
  CATSYPOutputStream &operator=(const CATSYPOutputStream&);
private:
  /** The last error */
  ErrorKind _lastErrorKind;
};

#endif // CATSYPOutputStream_H
