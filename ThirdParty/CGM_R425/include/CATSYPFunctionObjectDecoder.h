#ifndef CATSYPFunctionObjectDecoder_H
#define CATSYPFunctionObjectDecoder_H

#include <IntroInfra.h>

#include <CATSYPObjectDecoder.h>

/** @ingroup groupVidIO
 * An object decoder based on a static/regular function.
 */
class ExportedByIntroInfra CATSYPFunctionObjectDecoder : public CATSYPObjectDecoder
{
  CATDeclareClass;
public:
  /** 
   * Initialize this class.
   *
   * @param i_streamedType the name of the type to use to identify the
   * object type in the stream.
   *
   * @param i_pReadObjectFunc the function to call to do the actual
   * unstream. The arguments and the return value are the same as the
   * one documented by @ref CATSYPObjectDecoder#ReadObject. Can't be
   * @c NULL.
   */
  CATSYPFunctionObjectDecoder(const CATUnicodeString &i_streamedType,
                              int (*i_pReadObjectFunc)(CATSYPObjectInputStream &, CATBaseUnknown_var &));

  /** Destroy this class */
  virtual ~CATSYPFunctionObjectDecoder();

  /** @copydoc CATSYPObjectDecoder#GetStreamedType */
  virtual CATUnicodeString GetStreamedType();

  /** @copydoc CATSYPObjectDecoder#ReadObject */
  virtual int ReadObject(CATSYPObjectInputStream &i_inputStream, CATBaseUnknown_var &o_spObj);
private:
  CATSYPFunctionObjectDecoder(const CATSYPFunctionObjectDecoder &);
  CATSYPFunctionObjectDecoder &operator=(const CATSYPFunctionObjectDecoder &);
private:
  /** the name of the type to use to identify the object type in the
      stream */
  CATUnicodeString _streamedType;

  /** the function to call to do the actual unstream */  
  int (*_pReadObjectFunc)(CATSYPObjectInputStream &, CATBaseUnknown_var &);
};

#endif // CATSYPFunctionObjectDecoder_H
