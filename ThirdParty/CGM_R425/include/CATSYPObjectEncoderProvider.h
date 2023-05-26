#ifndef CATSYPObjectEncoderProvider_H
#define CATSYPObjectEncoderProvider_H

#include <IntroInfra.h>

#include <CATBaseUnknown.h>

class CATSYPObjectEncoder;

/** @ingroup groupVidIO
 * Interface for an object that can provide an @ref
 * CATSYPObjectEncoder instance for a given type of object.
 *
 * @see CATSYPObjectEncoder
 */
class ExportedByIntroInfra CATSYPObjectEncoderProvider : public CATBaseUnknown
{
  CATDeclareClass;
public:
  /** Initialize this class */
  CATSYPObjectEncoderProvider();

  /** Destroy this class */
  virtual ~CATSYPObjectEncoderProvider();

  /**
   * Get the encoder to use for @a i_pClass class of objects.
   *
   * @par Parent Class Lookup
   * The look-up algorithm for a given class is implementation
   * dependent. On the one hand an implementation of this interface
   * may chose to look for an encoder for the parent class if no
   * encoder exist for the given class (and recursively). On the other
   * hand it may only look-up for an encoder that exactly matches the
   * class and fail if none exist.<br/>
   * Anyway the caller should not implement this strategy itself but
   * rely on the provider to implement it.
   *
   * @note
   * The returned encoder must be compatible with @a i_pClass;
   * i.e. the value returned by its @ref
   * CATSYPObjectEncoder#GetObjectType must be @a i_pClass or a
   * super-type of @a i_pClass.
   *
   * @param i_pClass the class of the object. Can be @c NULL. @c NULL
   * means that the provider may provide an encoder for the value @c
   * NULL.
   *
   * @return [IUnknown#Release] the encoder instance. @c AddRef has
   * been called on the returned pointer. @c NULL if no encoder exist
   * for given class.<br/>
   * This specification ensure that a provider can generate
   * dynamically some encoders without having to keep them in cache.
   */
  virtual CATSYPObjectEncoder *GetEncoder(CATMetaClass *i_pClass) = 0;
private:
  CATSYPObjectEncoderProvider(const CATSYPObjectEncoderProvider &);
  CATSYPObjectEncoderProvider &operator=(const CATSYPObjectEncoderProvider &);
};

#endif // CATSYPObjectEncoderProvider_H
