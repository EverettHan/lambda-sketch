#ifndef CATSYPArrayOutputStream_H
#define CATSYPArrayOutputStream_H

#include "IntroInfra.h"
#include "CATSYPOutputStream.h"
#include "CATSYPMacros.h"

/** @ingroup groupVidIO
 * Output stream that write in a dynamic array of bytes.
 * The dynamic array can be retrieved using @ref #GetArray function.
 */
class ExportedByIntroInfra CATSYPArrayOutputStream : public CATSYPOutputStream
{
public:
  /**
   * Initialize the stream.
   * @param i_initialSize the initialize size of the dynamic array.
   * Can't be @c <0. If @c 0, then a default value is used.
   */
  explicit CATSYPArrayOutputStream(int i_initialSize = 0);
  /** 
   * Destructor. 
   * Note that it will free the associated array consequently this array
   * should not be used anymore after the destruction of this class.
   */
  ~CATSYPArrayOutputStream();
  /** @copydoc CATSYPOutputStream#Write */
  virtual int Write(const unsigned char *i_aValue, int i_aValueSize);
  /**
   * Get a pointer on the dynamic array of bytes.
   * @note
   * The returned pointer may become invalid if
   * the @ref #Write function is called. This is due to
   * the fact that the array is dynamic and may be relocated
   * if its size need to change.
   * @param [out] oSize the size of the array. Always @c >=0.
   * @return a pointer on the array. @c NULL if @a oSize is 0.<br/>
   * Note that this class keeps the property on the array
   * so it must not be freed/deleted.
   */
  unsigned char *GetArray(int &oSize) const;
  /**
   * Get a pointer on the dynamic array of bytes.
   * @note
   * The returned pointer may become invalid if
   * the @ref #Write function is called. This is due to
   * the fact that the array is dynamic and may be relocated
   * if its size need to change.
   * @return a pointer on the array. @c NULL if @ref #GetSize is @c 0.<br/>
   * Note that this class keeps the property on the array
   * so it must not be freed/deleted.
   */
  unsigned char *GetArray() const;
  /**
   * Get the size of the array returned by @ref #GetArray.
   *
   * @return the size of the array. Always @c >=0.
   */
  int GetSize() const;
private:
  CATSYPArrayOutputStream(const CATSYPArrayOutputStream&);
  CATSYPArrayOutputStream &operator=(const CATSYPArrayOutputStream&);
private:
  /** The array, can be NULL when _allocatedSize == 0. It must be allocated with malloc */
  unsigned char *_aArray;
  /** The logical size of the array _aArray, it should be
   *  <= to the allocated size _allocatedSize */
  int _size;
  /** The actual size of the @ref #_aArray array, it should 
   *  always be >= to the logical size _size */
  int _allocatedSize;
  /** The default size to use at the first allocation */
  const int _initialSize;
};

#endif // CATSYPArrayOutputStream_H
