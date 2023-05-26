#ifndef CATSYPObjectInputStream_H
#define CATSYPObjectInputStream_H

#include <IntroInfra.h>
#include <CATSYPCodedInputStream.h>

class CATBaseUnknown_var;

/** @ingroup groupVidIO
 * Interface that reads and decodes from a @ref #CATSYPInputStream @c
 * CATBaseUnknown objects and basic types.
 *
 * The unstreaming of basic types is available through the API of @ref
 * CATSYPCodedInputStream that this class have through inheritance.
 *
 * For each implementation of this interface, a corresponding
 * implementation of @ref CATSYPObjectOutputStream may exist to stream
 * the objects unstreamed by this input stream.
 *
 * @note
 * The class @ref CATSYPCodedInputStream does not have a virtual
 * destructor. As a consequence you must not delete an object
 * inheriting from this interface with a pointer of type @ref
 * CATSYPCodedInputStream.<br/>
 * Note that this class has a virtual destructor so there is no issue
 * to delete an object implementing this interface with a pointer on
 * this interface.
 *
 * @see CATSYPObjectOutputStream
 */
class ExportedByIntroInfra CATSYPObjectInputStream : public CATSYPCodedInputStream
{
public:
  /** Initialize this class */
  CATSYPObjectInputStream(CATSYPInputStream *i_pStream);

  /** Destroy this class */
  virtual ~CATSYPObjectInputStream();

  /**
   * Unstream an object.
   *
   * The implementation of this method will unstream the type of the
   * object along the object data. As a consequence the caller does
   * not have to provide the expected type of the object itself.<br/>
   * The exact implementation of this stream of the type depends on
   * the sub-class, but the chosen algorithm should be compatible with
   * an implementation of @ref CATSYPObjectOutputStream.
   *
   * @param o_spObj [out] the read object. The support of @c NULL
   * pointer, as a support for other values, depends on the
   * implementation of this interface. So please refer to the
   * sub-class documentation.
   *
   * @return !=0 if the unstream succeeded, else 0. Note that it may
   * have also raise an assertion (@ref #FAILURE) except if an IOError
   * occured on the underlying input stream. (see @ref
   * #GetLastErrorKind).
   */
  virtual int ReadObject(CATBaseUnknown_var &o_spObj) = 0;
private:
  CATSYPObjectInputStream(const CATSYPObjectInputStream &);
  CATSYPObjectInputStream &operator=(const CATSYPObjectInputStream &);
};

#endif // CATSYPObjectInputStream_H
