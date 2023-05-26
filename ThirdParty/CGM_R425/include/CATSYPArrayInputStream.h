#ifndef CATSYPArrayInputStream_H
#define CATSYPArrayInputStream_H

#include "IntroInfra.h"
#include "CATSYPInputStream.h"

class CATSYPConstByteBuffer;

/** @ingroup groupVidIO
 * Input stream that reads data from a byte array.
 * It can copy the array or only reference it. It's up
 * to the user to choose the behavior when building an
 * instance of this class.
 */
class ExportedByIntroInfra CATSYPArrayInputStream : public CATSYPInputStream
{
public:
  /** The referencing mode */
  enum Mode {
    /** make of copy of the input array */
    Copy,
    /** only reference the input array */
    Reference
  };
public:
  /**
   * Initialize the stream.
   * @param i_aData the byte buffer. Can be @c NULL only if @a i_aDataSize is @c 0. 
   * @param i_aDataSize the size of the byte buffer. Must be @c >=0.
   * @param i_mode the referencing mode, use @c Copy if you want this object to
   * keep a copy of @a i_aData, use @c Reference if you want this object to only
   * reference the given array.<br/>
   * When using @c Reference, you must ensure that the array is usable until 
   * this object is destroyed.
   */
  CATSYPArrayInputStream(unsigned char *i_aData, int i_aDataSize, Mode i_mode);
  /** 
   * Destructor. 
   * Note that it will free the associated array only if the @ref #Copy
   * mode is used.
   */
  ~CATSYPArrayInputStream();
  /** @copydoc CATSYPInputStream#Read */
  virtual int Read(unsigned char *i_aData, int i_aDataSize);
private:
  /**
   * Function used to build _pByteBuffer in constructors.
   * @return NULL if input is invalid (in that case, FAILURE has already
   * been called in case of error).
   */
  static CATSYPConstByteBuffer *CreateByteBuffer(unsigned char *i_aData, int i_aDataSize, Mode i_mode);
private:
  CATSYPArrayInputStream(const CATSYPArrayInputStream&);
  CATSYPArrayInputStream &operator=(const CATSYPArrayInputStream&);
private:
  /**
   * The byte buffer holding the data.
   */
  CATSYPConstByteBuffer *_pByteBuffer;
  /** the offset of the next byte to be read. 
   *  It must be >=0 and <=_aDataSize. Note that when ==_aDataSize
   *  that means that the end of the stream has been reached. 
   */
  int _nextReadingPosition;
};

#endif // CATSYPArrayInputStream_H
