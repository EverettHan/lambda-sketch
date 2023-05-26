#ifndef CATSYPObjectDecoderProvider_H
#define CATSYPObjectDecoderProvider_H

#include <IntroInfra.h>

#include <CATBaseUnknown.h>

class CATSYPObjectDecoder;
class CATUnicodeString;

/** @ingroup groupVidIO
 * Interface for an object that can provide an @ref
 * CATSYPObjectDecoder instance for a given streamed type of object.
 *
 * @see CATSYPObjectDecoder
 */
class ExportedByIntroInfra CATSYPObjectDecoderProvider : public CATBaseUnknown
{
  CATDeclareClass;
public:
  /** Initialize this class */
  CATSYPObjectDecoderProvider();

  /** Destroy this class */
  virtual ~CATSYPObjectDecoderProvider();

  /**
   * Get the decoder to use for @a i_streamedType type of objects.
   *
   * @note
   * The returned decoder must be compatible with @a i_streamedType;
   * i.e. the value returned by its @ref
   * CATSYPObjectDecoder#GetStreamedType must be @a i_streamedType.
   *
   * @param i_streamedType the streamed type stored in the stream.
   *
   * @return [IUnknown#Release] the decoder instance. @c AddRef has
   * been called on the returned pointer. @c NULL if no decoder exist
   * for given class.<br/>
   * This specification ensure that a provider can generate
   * dynamically some decoders without having to keep them in cache.
   */
  virtual CATSYPObjectDecoder *GetDecoder(const CATUnicodeString &i_streamedType) = 0;
private:
  CATSYPObjectDecoderProvider(const CATSYPObjectDecoderProvider &);
  CATSYPObjectDecoderProvider &operator=(const CATSYPObjectDecoderProvider &);
};

#endif // CATSYPObjectDecoderProvider_H
