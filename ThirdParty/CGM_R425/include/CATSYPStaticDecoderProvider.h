#ifndef CATSYPStaticDecoderProvider_H
#define CATSYPStaticDecoderProvider_H

#include <IntroInfra.h>

#include <CATSYPObjectDecoderProvider.h>
#include <CATSYPHashMap.h>
#include <CATUnicodeString.h>

class CATSYPObjectInputStream;
class CATBaseUnknown_var;

/** @ingroup groupVidIO
 * Implementation of @ref CATSYPObjectDecoderProvider based on a
 * static list of decoder instances.
 */
class ExportedByIntroInfra CATSYPStaticDecoderProvider : public CATSYPObjectDecoderProvider
{
  CATDeclareClass;
public:
  /** Initialize this class */
  CATSYPStaticDecoderProvider();

  /** Destroy this class */
  virtual ~CATSYPStaticDecoderProvider();

  /**
   * Register a decoder in this provider.
   *
   * No decoder for the type returned by @ref
   * CATSYPObjectDecoder#GetStreamedType should already be registered
   * in this provider.
   *
   * @param i_pDecoder the decoder to register. Can't be @c NULL.
   *
   * @param i_release_ptr if @c !=0 and @a i_pDecoder is not @c NULL,
   * call @c Release on @a i_pDecoder. This is used to steal the
   * reference of @a i_pDecoder, meaning the after call to this
   * function, the input pointer should be set to @c NULL. Typical
   * usage is to do <code>provider->AddDecoder(new MyDecoder(), 1);</code>
   * 
   * @return @c !=0 if registration succeeded, else @c 0. Note that
   * even when this function returned @c 0, if @a i_release_ptr was @c
   * !=0 @c Release has been called on @a i_pDecoder. So the caller
   * can safely assume that when @a i_release_ptr is used @c Release
   * is always called by this function, event in case of error (for
   * example if there is already an decoder for the same type).
   */
  int AddDecoder(CATSYPObjectDecoder *i_pDecoder, int i_release_ptr);

  /**
   * Register a static/regular function as an encoder.
   *
   * This function is a shortcut to instantiating a @ref
   * CATSYPFunctionObjectEncoder and registering it on this object.
   *
   * @param i_streamedType the name of the type to use to identify the
   * object type in the stream.
   *
   * @param i_pReadObjectFunc the function to call to do the actual
   * unstream. The arguments and the return value are the same as the
   * one documented by @ref CATSYPObjectDecoder#ReadObject. Can't be
   * @c NULL.
   * 
   * @return @c !=0 if registration succeeded, else @c 0.
   *
   * @see CATSYPFunctionObjectDecoder
   */
  int AddFuncDecoder(const CATUnicodeString &i_streamedType,
                     int (*i_pReadObjectFunc)(CATSYPObjectInputStream &, CATBaseUnknown_var &));

  /** @copydoc CATSYPObjectDecoderProvider#GetDecoder */
  virtual CATSYPObjectDecoder *GetDecoder(const CATUnicodeString &i_streamedType);

private:
  CATSYPStaticDecoderProvider(const CATSYPStaticDecoderProvider &);
  CATSYPStaticDecoderProvider &operator=(const CATSYPStaticDecoderProvider &);
private:
  /**
   * Empty @ref #_decoders after having called @c Release on all
   * decoders.
   */
  void Clear();
private:
  /** a map associating a streamed type to a decoder. Note that @c
      AddRef has been called on decoders */
  CATSYPHashMap<CATUnicodeString, CATSYPObjectDecoder*> _decoders;
};

#endif // CATSYPStaticDecoderProvider_H
