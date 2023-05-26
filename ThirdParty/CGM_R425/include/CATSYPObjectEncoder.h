#ifndef CATSYPObjectEncoder_H
#define CATSYPObjectEncoder_H

#include <IntroInfra.h>

#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>

class CATMetaClass;
class CATSYPObjectOutputStream;

/** @ingroup groupVidIO
 * Interface for objects that can encode a given type of @ref
 * CATBaseUnknown object to an @ref CATSYPObjectOutputStream.
 *
 * @see CATSYPObjectDecoder
 */
class ExportedByIntroInfra CATSYPObjectEncoder : public CATBaseUnknown
{
  CATDeclareClass;
public:
  /** Initialize this class */
  CATSYPObjectEncoder();

  /** Destroy this class */
  virtual ~CATSYPObjectEncoder();

  /**
   * Get the type of object that this encoder can encode.
   *
   * @return the type of object. Can be @c NULL if the encoder is
   * there to encode @c NULL value (which has not type).
   */
  virtual CATMetaClass *GetObjectType() = 0;

  /**
   * Get the name of the type to use to identify the object type in
   * the stream.
   *
   * @return the name of the type in the stream.
   */
  virtual CATUnicodeString GetStreamedType() = 0;

  /**
   * Stream an object to the given stream. 
   *
   * This encoder does not have to stream the object type; it's the
   * caller that will stream it based on the value returned by @ref
   * #GetStreamedType.
   *
   * @param i_outputStream the object stream to use to stream the
   * value. It can be used to stream basic data types and also to
   * stream children objects.
   *
   * @param i_pObj the object to stream. Can't be @c NULL.
   *
   * @return @c !=0 if the stream succeeded, else @c 0. This function
   * may fail for an @ref CATSYPObjectOutputStream#IOError on the
   * output stream, in that case it should not raise an assertion
   * (@ref FAILURE). On the other hand, it may also fail due an other
   * error on the output stream; in that case, it would be a good idea
   * to have an assertion. Consequently, the macro CHECK_WRITE_RET0
   * should be used to test each Write* call on @a
   * i_outputStream. Other errors should also be signaled by
   * assertions (@ref FAILURE).
   */
  virtual int WriteObject(CATSYPObjectOutputStream &i_outputStream, CATBaseUnknown *i_pObj) = 0;

private:
  CATSYPObjectEncoder(const CATSYPObjectEncoder &);
  CATSYPObjectEncoder &operator=(const CATSYPObjectEncoder &);
};

#endif // CATSYPObjectEncoder_H
