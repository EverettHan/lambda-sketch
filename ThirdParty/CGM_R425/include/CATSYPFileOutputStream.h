#ifndef CATSYPFileOutputStream_H
#define CATSYPFileOutputStream_H


#include <IntroInfra.h>
#include <CATSYPOutputStream.h>
// System/PublicInterfaces/CATErrorMacros.h defines try/catch/throw as
// ERROR; as a consequence #include<string> may fail to compile since
// std::string is based on a template so its code is inlined and may
// contain exception code.
#undef try
#undef catch
#undef throw
#include <string>
#include <stdio.h>

/** @ingroup groupVidIO
 * Output stream that writes in a file using <code>stdio.h</code>
 * streams.
 *
 * Don't forget to close the stream with @ref #Close. It will be
 * automatically called by destructor but the error will be lost if
 * you don't do it.
 *
 * You can also flush pending writed using @ref #Flush.
 *
 * In case an @ref CATSYPOutputStream#IOError occurs then a detailed
 * message is available though @ref GetLastIOError.
 */
class ExportedByIntroInfra CATSYPFileOutputStream : public CATSYPOutputStream
{
public:
  /**
   * Create or truncate to zero length the file @ref #i_path.
   *
   * If an I/O error occur during the opening then it will be
   * available using @ref GetLastErrorKind. It should be tested before
   * any call to @ref #Write since this function would replace the
   * error with an @ref CATSYPOutputStream#IOError indicating that
   * that the stream is closed. More details about the error if it is
   * an @ref CATSYPOutputStream#IOError are available thought @ref
   * #GetLastIOError.
   *
   * @par Implementation Details
   * This function is implemented using @c fopen from
   * <code>stdio.h</code> using @c "wb" mode.
   *
   * @param i_path the path; can't be @c NULL.
   */
  CATSYPFileOutputStream(const char *i_path);

  /** Destroy this class */
  virtual ~CATSYPFileOutputStream();
 
  /** @copydoc CATSYPOutputStream#Write
   *
   * @par Implementation Details
   * This function is implemented using @c fwrite from
   * <code>stdio.h</code>.
   *
   * @par
   * It also has additional informations in case of @ref
   * CATSYPOutputStream#IOError with an error message available with
   * @ref #GetLastIOError.
   *
   * @par
   * If called after the stream is closed (or failed to open, see
   * constructor for details) then it will fail and set error as @ref
   * CATSYPOutputStream#IOError and @ref #GetLastIOError as @c "Stream
   * is closed".
   */
  virtual int Write(const unsigned char *i_aValue, int i_aValueSize);

  /**
   * Flushes the stream.
   *
   * Don't have any effect if the stream has been closed.
   *
   * @return @c !=0 if the flush succeeded (no error is positioned),
   * @c 0 if an error occured. In that case the type of the error
   * retrieved using @ref #GetLastErrorKind is @ref
   * CATSYPOutputStream#IOError. The exact error is available though
   * @ref #GetLastIOError.
   */
  int Flush();

  /**
   * Close the stream.
   *
   * Don't have any effect if the stream has already been closed.
   *
   * No action can be taken on the stream after it has been closed.
   *
   * @return @c !=0 if the close succeeded (no error is positioned),
   * @c 0 if an error occured. In that case the type of the error
   * retrieved using @ref #GetLastErrorKind is @ref
   * CATSYPOutputStream#IOError. The exact error is available though
   * @ref #GetLastIOError.
   */
  int Close();

  /**
   * Get a string the describes the last @ref
   * CATSYPOutputStream#IOError that occurs when calling functions of
   * this class.
   *
   * @return the last I/O error. Empty string is no I/O error occured.
   */
  std::string GetLastIOError() const;

private:
  CATSYPFileOutputStream(const CATSYPFileOutputStream &);
  CATSYPFileOutputStream &operator=(const CATSYPFileOutputStream &);
private:
  /**
   * Set last error kind to @ref CATSYPOutputStream#IOError and set
   * the @ref #_lastError to @c strerror(errno).
   */
  void SetErrorFromErrno();
private:
  /** the underlying file; @c NULL after close. */
  FILE * _file; 

  /** the last @ref CATSYPOutputStream#IOError that occured */
  std::string _lastError;
};


#endif // CATSYPFileOutputStream_H
