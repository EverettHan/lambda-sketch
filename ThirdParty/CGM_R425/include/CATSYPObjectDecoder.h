#ifndef CATSYPObjectDecoder_H
#define CATSYPObjectDecoder_H

#include <IntroInfra.h>
#include <CATBaseUnknown.h>
#include <CATBaseUnknown_var.h>
#include <CATUnicodeString.h>

class CATSYPObjectInputStream;

/** @ingroup groupVidIO
 * Interface for objects that can decode a given stream type of @ref
 * CATBaseUnknown object from a @ref CATSYPObjectInputStream.
 *
 * @see CATSYPObjectEncoder
 */
class ExportedByIntroInfra CATSYPObjectDecoder : public CATBaseUnknown
{
  CATDeclareClass;
public:
  /** Initialize this class */
  CATSYPObjectDecoder();

  /** Destroy this class */
  virtual ~CATSYPObjectDecoder();

  /**
   * Get the name of the type to use to identify the object type in
   * the stream.
   *
   * @return the name of the type in the stream.
   */
  virtual CATUnicodeString GetStreamedType() = 0;

  /**
   * Unstream an object from the given stream. 
   *
   * @param i_inputStream the object stream to use to unstream the
   * value. It can be used to unstream basic data types and also to
   * unstream children objects.
   *
   * @param o_spObj [out] the read object. Can be @c NULL_var if @c
   * NULL was streamed. Must be @c NULL_var when this function returns
   * @c 0 (i.e. when it fails).
   *
   * @return @c !=0 if the unstream succeeded, else @c 0. This
   * function may fail for an @ref CATSYPObjectInputStream#IOError in
   * the input stream, in that case it should not raise an assertion
   * (@ref FAILURE). On the other hand, it may also fail due an other
   * error in the input stream; in that case, it would be a good idea
   * to have an assertion. Consequently, the macro CHECK_READ_RET0
   * should be used to test each Read* call on @a i_inputStream. Other
   * errors should also be signaled by assertions (@ref FAILURE).
   */
  virtual int ReadObject(CATSYPObjectInputStream &i_inputStream, CATBaseUnknown_var &o_spObj) = 0;

private:
  CATSYPObjectDecoder(const CATSYPObjectDecoder &);
  CATSYPObjectDecoder &operator=(const CATSYPObjectDecoder &);
};

#endif // CATSYPObjectDecoder_H
