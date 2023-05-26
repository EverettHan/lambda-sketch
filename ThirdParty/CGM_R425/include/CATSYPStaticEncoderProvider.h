#ifndef CATSYPStaticEncoderProvider_H
#define CATSYPStaticEncoderProvider_H

#include <IntroInfra.h>

#include <CATSYPObjectEncoderProvider.h>
#include <CATSYPHashMap.h>

class CATSYPObjectOutputStream;

/** @ingroup groupVidIO
 * Implementation of @ref CATSYPObjectEncoderProvider based on a
 * static list of encoder instances.
 *
 * @par No Parent Class Lookup
 * The @ref #GetEncoder implementation of this class will look for a
 * provider for the exact class. If there is no encoder for the class
 * it will return @c NULL without looking for an encoder for the
 * parent class.<br/>
 * This design decision is there to ensure that a class specialization
 * is not automatically streamed as its parent class and then
 * unstreamed as its parent class by unstream code.
 */
class ExportedByIntroInfra CATSYPStaticEncoderProvider : public CATSYPObjectEncoderProvider
{
  CATDeclareClass;
public:
  /** Initialize this class */
  CATSYPStaticEncoderProvider();

  /** Destroy this class */
  virtual ~CATSYPStaticEncoderProvider();

  /**
   * Register an encoder in this provider.
   *
   * No encoder for the class returned by @ref
   * CATSYPObjectEncoder#GetObjectType should already be registered in
   * this provider.
   *
   * An encoder for @c NULL class can be registered.
   *
   * @param i_pEncoder the encoder to register. Can't be @c NULL.
   *
   * @param i_release_ptr if @c !=0 and @a i_pEncoder is not @c NULL,
   * call @c Release on @a i_pEncoder. This is used to steal the
   * reference of @a i_pEncoder, meaning the after call to this
   * function, the input pointer should be set to @c NULL. Typical
   * usage is to do <code>provider->AddEncoder(new MyEncoder(), 1);</code>
   * 
   * @return @c !=0 if registration succeeded, else @c 0. Note that
   * even when this function returned @c 0, if @a i_release_ptr was @c
   * !=0 @c Release has been called on @a i_pEncoder. So the caller
   * can safely assume that when @a i_release_ptr is used @c Release
   * is always called by this function, event in case of error (for
   * example if there is already an encoder for the same type).
   */
  int AddEncoder(CATSYPObjectEncoder *i_pEncoder, int i_release_ptr);

  /**
   * Register a static/regular function as an encoder.
   *
   * This function is a shortcut to instantiating a @ref
   * CATSYPFunctionObjectEncoder and registering it on this object.
   *
   * @param i_pMetaClass the type of object that this encoder can
   * encode. Can be @c NULL if this encoder is there to encoder @c
   * NULL object.
   *
   * @param i_streamedType the name of the type to use to identify the
   * object type in the stream.
   *
   * @param i_pWriteObjectFunc the function to call to do the actual
   * stream. The arguments and the return value are the same as the
   * one documented by @ref CATSYPObjectEncoder#WriteObject.
   * 
   * @return @c !=0 if registration succeeded, else @c 0.
   *
   * @see CATSYPFunctionObjectEncoder
   */
  int AddFuncEncoder(CATMetaClass *i_pMetaClass, 
                     const CATUnicodeString &i_streamedType,
                     int (*i_pWriteObjectFunc)(CATSYPObjectOutputStream &, CATBaseUnknown *));

  /** @copydoc CATSYPObjectEncoderProvider#GetEncoder */
  virtual CATSYPObjectEncoder *GetEncoder(CATMetaClass *i_pClass);
private:
  CATSYPStaticEncoderProvider(const CATSYPStaticEncoderProvider &);
  CATSYPStaticEncoderProvider &operator=(const CATSYPStaticEncoderProvider &);
private:
  /**
   * Empty @ref #_encoders after having called @c Release on all
   * encoders.
   */
  void Clear();
private:
  /** a map associating a class to an encoder. Note that @c AddRef has
      been called on encoders */
  CATSYPHashMap<CATMetaClass*, CATSYPObjectEncoder*, CATSYPHashMapPointerHasher>
    _encoders;
};

#endif // CATSYPStaticEncoderProvider_H
