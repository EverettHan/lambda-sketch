#ifndef BundleInputSource_h
#define BundleInputSource_h
/************************************************************************/
/* Defines                                                              */
/************************************************************************/

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "DSYSysRsc.h"
#include "CATIXMLInputStream.h"
#include "CatXmlItfBase.h"

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/

/**
 * @class CATILockBytes
 */
class CATILockBytes;

/************************************************************************/
/************************************************************************/

/**
 * @class BundleInputSource
 *
 * Class to implement the CATIXMLInputStream backed by
 * a resource bundle.
 */
class ExportedByCatXmlItfBase BundleInputSource : public CATIXMLInputStream
{
  ///////////////////////////////////////////
  ////// Types/Constants/Struct/Enum ////////
  ///////////////////////////////////////////

  ///////////////////////////////////////////
  ///////////////// Methods /////////////////
  ///////////////////////////////////////////

  CATDeclareClass;

public:
  /// Constructor.
  BundleInputSource(DSYSysRscHandle ipRscHandle);

  /// Destructor.
  virtual ~BundleInputSource();

  /// Read.
  virtual HRESULT Read(unsigned char* ioByteArray, unsigned int iByteArrayCapacity, unsigned int& oSizeRead);

  /// Reset.
  void Reset(unsigned char* iArray, unsigned int iArraySize);

  ///////////////////////////////////////////
  ///////////////// Members /////////////////
  ///////////////////////////////////////////
private:
  /// Current buffer index.
  unsigned int m_Index;

  /// Buffer size.
  unsigned int m_ByteArraySize;

  /// ILockBytes object.
  CATILockBytes* m_pILockBytes;
};
#endif // BundleInputSource_h
