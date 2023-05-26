#ifndef CATSYPSHdrObjOutputStream_H
#define CATSYPSHdrObjOutputStream_H

#include <IntroInfra.h>
#include <CATSYPObjectOutputStream.h>

class CATSYPObjectEncoderProvider;

/** @ingroup groupVidIO
 * Implementation of @ref CATSYPObjectOutputStream that stream objects
 * with a header containing the type name and size of the stream of
 * the object.
 *
 * Objects are streamed using a @ref CATSYPObjectEncoder provided by
 * an instance of @ref CATSYPObjectEncoderProvider.
 *
 * The "SHdr" in the name of the class stands for "Size Header".
 *
 * @par Header Format
 * The @ref #WriteObject will write a header before the stream of the
 * class made by the corresponding @ref CATSYPObjectEncoder. The
 * binary stream of this header is:
 *   - valueType : unicodeString (WriteUnicodeString) the value returned
 *     by @ref CATSYPObjectEncoder#GetStreamedType.
 *   - valueDataSize : varUInt32 (WriteVarUInt32) the size of the stream
 *     of the value.
 *   - valueData : byteArray[valueDataSize] (WriteByteArray) the actual
 *     streamed data produced by @ref CATSYPObjectEncoder#WriteObject.
 *
 * @par
 * Note that valueDataSize is not strictly needed to support
 * reading. It is only stored so that some unstreamer can be
 * implemented without supporting all types of data. Since they know
 * the size of the data block, they can skip it and continue the
 * unstream.
 *
 * @par
 * One consequence of streaming the valueDataSize is that the stream
 * of the object has to be prepared in memory instead of being
 * directly written to the target output stream.
 * 
 * @par No Specialization
 * Note that you can't specialize this class due to the algorithm it
 * uses to support recursion of object writting.<br/>
 * Before each call to @ref CATSYPObjectEncoder#WriteObject a new
 * instance of this class is created (that shares the @ref
 * CATSYPObjectEncoderProvider) and given to this function as first
 * argument (this is due to the fact that the header contains the size
 * of the object stream; as a consequence we must first stream the
 * object in memory before writting the header). As a consequence a
 * sub-class of this class would only be used on first call @ref
 * #WriteObject, not on recursive calls (made by encoders to write
 * children objects).
 *
 * @see CATSYPSHdrObjInputStream
 */
class ExportedByIntroInfra CATSYPSHdrObjOutputStream : public CATSYPObjectOutputStream
{
public:
  /** 
   * Initialize this class.
   *
   * @param i_pStream the stream to write to. Can't be @c NULL.
   * Note that there is no reference mechanism for CATSYPOutputStream
   * streams, consequently the caller must ensure that the stream
   * is not destroyed until this instance is destroyed.

   * @param i_pEncoderProvider the provider of encoders to use. Can't be
   * @c NULL. It will be shared by other instances of this class used
   * for recursive stream of children objects.
   */
  CATSYPSHdrObjOutputStream(CATSYPOutputStream *i_pStream, CATSYPObjectEncoderProvider *i_pEncoderProvider);

  /** Destroy this class */
  virtual ~CATSYPSHdrObjOutputStream();

  /** @copydoc CATSYPObjectOutputStream#WriteObject */
  virtual int WriteObject(CATBaseUnknown *i_pObj);

private:
  CATSYPSHdrObjOutputStream(const CATSYPSHdrObjOutputStream &);
  CATSYPSHdrObjOutputStream &operator=(const CATSYPSHdrObjOutputStream &);

private:
  /** the provider of encoders for @ref #WriteObject */
  CATSYPObjectEncoderProvider *_pEncoderProvider;
};

#endif // CATSYPSHdrObjOutputStream_H
