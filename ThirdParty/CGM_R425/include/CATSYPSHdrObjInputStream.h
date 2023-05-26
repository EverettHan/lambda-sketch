#ifndef CATSYPSHdrObjInputStream_H
#define CATSYPSHdrObjInputStream_H

#include <IntroInfra.h>
#include <CATSYPObjectInputStream.h>

class CATSYPObjectDecoderProvider;

/** @ingroup groupVidIO
 * Implementation of @ref CATSYPObjectInputStream that unstream
 * objects with a header containing the type name and size of the
 * stream of the object.
 *
 * Objects are unstreamed using a @ref CATSYPObjectDecoder provided by
 * an instance of @ref CATSYPObjectDecoderProvider.
 *
 * The "SHdr" in the name of the class stands for "Size Header".
 *
 * @par Header Format
 * The @ref #WriteObject is expecting a header before the stream of an
 * object. The actual unsteam of the object data is made by the
 * corresponding @ref CATSYPObjectDecoder. The binary stream of this
 * header is:
 *   - valueType : unicodeString (WriteUnicodeString) the value returned
 *     by @ref CATSYPObjectEncoder#GetStreamedType.
 *   - valueDataSize : varUInt32 (WriteVarUInt32) the size of the stream
 *     of the value.
 *   - valueData : byteArray[valueDataSize] (WriteByteArray) the actual
 *     streamed data that will be decoded by @ref CATSYPObjectDecoder#ReadObject.
 *
 * @par Unknown Type Handling
 * The unsteam of an object will fail if no @ref CATSYPObjectDecoder
 * is available for the corresponding streamed type.
 *
 * @par No Specialization
 * Note that you can't specialize this class due to the algorithm it
 * uses to support recursion of object reading.<br/>
 * Before each call to @ref CATSYPObjectDecoder#ReadObject a new
 * instance of this class is created (that shares the @ref
 * CATSYPObjectDecoderProvider) and given to this function as first
 * argument (this ensures that only the expected bytes are read by
 * providing a sub-stream to decoders). As a consequence a sub-class
 * of this class would only be used on first call @ref #ReadObject,
 * not on recursive calls (made by decoders to read children objects).
 *
 * @see CATSYPSHdrObjOutputStream
 */
class ExportedByIntroInfra CATSYPSHdrObjInputStream : public CATSYPObjectInputStream
{
public:
  /** 
   * Initialize this class 
   *
   * @param i_pStream the stream to read from. Can't be NULL.<br/>
   * Note that there is no reference mechanism for CATSYPInputStream
   * streams, consequently the caller must ensure that the stream
   * is not destroyed until this instance is destroyed.
   *
   * @param i_pDecoderProvider the provider for decoders to use. Can't
   * be @c NULL. It will be shared by other instances of this class
   * used for recursive unstream of children objects.
   */
  CATSYPSHdrObjInputStream(CATSYPInputStream *i_pStream, CATSYPObjectDecoderProvider * i_pDecoderProvider);

  /** Destroy this class */
  virtual ~CATSYPSHdrObjInputStream();

  /** @copydoc CATSYPObjectInputStream#ReadObject */
  virtual int ReadObject(CATBaseUnknown_var &o_spObj);
private:
  CATSYPSHdrObjInputStream(const CATSYPSHdrObjInputStream &);
  CATSYPSHdrObjInputStream &operator=(const CATSYPSHdrObjInputStream &);
private:
  /** the provider of decoders for @ref #ReadObject */
  CATSYPObjectDecoderProvider *_pDecoderProvider;
};

#endif // CATSYPSHdrObjInputStream_H
