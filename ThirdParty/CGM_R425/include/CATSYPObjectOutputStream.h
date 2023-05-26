#ifndef CATSYPObjectOutputStream_H
#define CATSYPObjectOutputStream_H

#include <IntroInfra.h>
#include <CATSYPCodedOutputStream.h>

class CATBaseUnknown;

/** @ingroup groupVidIO
 * Interface that encodes and writes to an @ref #CATSYPOutputStream @c
 * CATBaseUnknown objects and basic types.
 *
 * The streaming of basic types is available through the API of @ref
 * CATSYPCodedOutputStream that this class have through inheritance.
 *
 * For each implementation of this interface, a corresponding
 * implementation of @ref CATSYPObjectInputStream may exist to
 * unstream the objects streamed by this output stream.
 *
 * @note
 * The class @ref CATSYPCodedOutputStream does not have a virtual
 * destructor. As a consequence you must not delete an object
 * inheriting from this interface with a pointer of type @ref
 * CATSYPCodedOutputStream.<br/>
 * Note that this class has a virtual destructor so there is no issue
 * to delete an object implementing this interface with a pointer on
 * this interface.
 *
 * @see CATSYPObjectInputStream
 */
class ExportedByIntroInfra CATSYPObjectOutputStream : public CATSYPCodedOutputStream
{
public:
  /**
   * Initialize the object output stream.
   * @param i_pStream the stream to write to. Can't be @c NULL.
   * Note that there is no reference mechanism for CATSYPOutputStream
   * streams, consequently the caller must ensure that the stream
   * is not destroyed until this instance is destroyed.
   */
  CATSYPObjectOutputStream(CATSYPOutputStream *i_pStream);

  /** Destroy this class */
  virtual ~CATSYPObjectOutputStream();

  /**
   * Stream an object.
   *
   * The implementation of this method must stream the type of the
   * object along the object data. As a consequence the caller does
   * not have to stream this type itself.<br/>
   * The exact implementation of this stream of the type depends on
   * the sub-class, but the chosen algorithm should be compatible with
   * an implementation of @ref CATSYPObjectInputStream.
   *
   * @param i_pObj the object to stream. The support of @c NULL
   * pointer, as the support of other values, depends on the
   * implementation of this interface so please refer to the sub-class
   * documentation.
   *
   * @return !=0 if the stream succeeded, else 0. Note that it may have
   * also raise an assertion (@ref #FAILURE) except if an IOError occured 
   * on the underlying output stream (see @ref #GetLastErrorKind).
   */
  virtual int WriteObject(CATBaseUnknown *i_pObj) = 0;
  
private:
  CATSYPObjectOutputStream(const CATSYPObjectOutputStream &);
  CATSYPObjectOutputStream &operator=(const CATSYPObjectOutputStream &);
};

#endif // CATSYPObjectOutputStream_H
