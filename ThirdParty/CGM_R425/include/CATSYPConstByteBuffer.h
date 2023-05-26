#ifndef CATSYPConstByteBuffer_H
#define CATSYPConstByteBuffer_H

#include "IntroInfra.h"
#include "CATSYPMacros.h"

/**
 * Represent a fixed size buffer of bytes.
 * Its main use is to ensure that temporary buffers
 * are correctly freed when the scope of a function
 * is ended abrubtly (compared to a raw allocation using
 * new[] or malloc that need explicit free code at each
 * exit of a scope).
 * Note that due to the modes TakeOwnership_* (see @ref
 * #Mode) there are no copy constructor or operator= for
 * this class since they would not make sense. Maybe
 * we could specify that the copy uses the @ref #Copy 
 * mode but they are more chances that this mode is not
 * then one expected.
 */
class ExportedByIntroInfra CATSYPConstByteBuffer
{
public:
  /** The referencing mode */
  enum Mode {
    /** make of copy of the input array */
    Copy,
    /** only reference the input array */
    Reference,
    /** take the ownership of the provided array,
     *  the provided array will be destroyed using
     *  the operator delete[] in the destructor */
    TakeOwnership_delete,
    /** take the ownership of the provided array,
     *  the provided array will be destroyed using
     *  the operator free in the destructor */
    TakeOwnership_free
  };
public:
  /**
   * Initialize the byte buffer to an empty array.
   */
  CATSYPConstByteBuffer();
  /**
   * Initialize the byte buffer with a newly allocated data block.
   * This data block will be owned by this class (i.e. as if @ref #Copy
   * mode was used with @ref #CATSYPConstByteBuffer(unsigned char*, int, Mode)
   * constructor was used.
   * @param i_size the size of the byte buffer to allocate, must be >=0.
   * Note that if 0, then the function @ref #GetData will return NULL.
   * @param i_defaultValue the value to used to initialize the allocated 
   * bytes. Note that if must be either -1 or a value in [0;0xFF] range.
   * The value -1 means that no initial value must be used; in that case
   * (which is the default case) the data block is left uninitialized
   * (i.e. it will be the raw result of malloc).
   */
  explicit CATSYPConstByteBuffer(int i_size, int i_defaultValue = -1);
  /**
   * Initialize the byte buffer from existing data.
   * @param i_aData the byte buffer. Can be NULL only if i_aDataSize is 0. 
   * @param i_aDataSize the size of the byte buffer. Must be >=0.
   * @param i_mode the referencing mode, use Copy if you want this object to
   * keep a copy of i_aData. Use Reference if you want this object to only
   * reference the given array. When using Reference, you must ensure that
   * the array is usable until this object is destroyed. Use TakeOwnership_*
   * if you want that this class takes the ownership of the provided data.
   * Giving it the ownership means that it will destroy i_aData in its destructor.
   * The method of destruction depends on the enum used:
   *   - TakeOwnership_delete will use the delete[] C++ operator
   *   - TakeOwnership_free will use the free C function
   */
  CATSYPConstByteBuffer(unsigned char *i_aData, int i_aDataSize, Mode i_mode);
  /**
   * Destructor. 
   * Note that it will free the associated array only if one of the following
   * mode is used:
   *   - @ref #Copy
   *   - @ref #TakeOwnership_delete
   *   - @ref #TakeOwnership_free
   */
  ~CATSYPConstByteBuffer();
  /**
   * Get the data block pointer.
   * @return !=NULL if the size is not 0, else NULL if size is 0.
   */
  unsigned char *GetData() const;
  /**
   * Get the size of the buffer.
   * @return the size in bytes
   */
  int GetSize() const;
private:
  /** see class documentation */
  CATSYPConstByteBuffer(const CATSYPConstByteBuffer&);
  /** see class documentation */
  CATSYPConstByteBuffer &operator=(const CATSYPConstByteBuffer&);
private:
  /** referencing mode */
  const Mode _mode;
  /** the array, can be NULL if _aDataSize is 0. */
  unsigned char *_aData;
  /** the size of _aData. >=0 */
  int _aDataSize;
};

#endif // CATSYPConstByteBuffer_H
