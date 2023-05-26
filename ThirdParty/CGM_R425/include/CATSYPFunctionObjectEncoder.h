#ifndef CATSYPFunctionObjectEncoder_H
#define CATSYPFunctionObjectEncoder_H

#include <IntroInfra.h>

#include <CATSYPObjectEncoder.h>
#include <CATUnicodeString.h>

/** @ingroup groupVidIO
 * An object encoder based on a static/regular function.
 */
class ExportedByIntroInfra CATSYPFunctionObjectEncoder : public CATSYPObjectEncoder
{
  CATDeclareClass;
public:
  /** 
   * Initialize this class.
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
   * one documented by @ref CATSYPObjectEncoder#WriteObject. Can't be
   * @c NULL.
   */
  CATSYPFunctionObjectEncoder(CATMetaClass *i_pMetaClass, 
                              const CATUnicodeString &i_streamedType,
                              int (*i_pWriteObjectFunc)(CATSYPObjectOutputStream &, CATBaseUnknown *));

  /** Destroy this class */
  virtual ~CATSYPFunctionObjectEncoder();

  /** @copydoc CATSYPObjectEncoder#GetObjectType */
  virtual CATMetaClass *GetObjectType();

  /** @copydoc CATSYPObjectEncoder#GetStreamedType */
  virtual CATUnicodeString GetStreamedType();

  /** @copydoc CATSYPObjectEncoder#WriteObject */
  virtual int WriteObject(CATSYPObjectOutputStream &i_outputStream, CATBaseUnknown *i_pObj);

private:
  CATSYPFunctionObjectEncoder(const CATSYPFunctionObjectEncoder &);
  CATSYPFunctionObjectEncoder &operator=(const CATSYPFunctionObjectEncoder &);

private:
  /** the function to call to do the actual stream */
  int (*_pWriteObjectFunc)(CATSYPObjectOutputStream &, CATBaseUnknown *);
  /** the type of object that this encoder can encode. Can be @c
      NULL. */
  CATMetaClass *_pMetaClass;
  /** the name of the type to use to identify the object type in the
      stream */
  CATUnicodeString _streamedType;
};

#endif // CATSYPFunctionObjectEncoder_H
