#ifndef CATIMAGEBUFFER_H
#define CATIMAGEBUFFER_H

#include "CATMMediaPixelImage.h"

#include "CATSysTSBaseUnknown.h"
#include "CATMMPISpec.h"
#include "CATMMPIBuffer.h"

/**
 * @ingroup groupPixelImageData
 * Image Buffer used by Multimedia Engines.
 * Using CATMMPIBuffer.
 * @todo: Check if CATImageBuffer could be used by lCATPixelImage.
 */
class ExportedByCATMMediaPixelImage CATImageBuffer :  public CATSysTSBaseUnknown
{
  CATSysTSDeclareClass;
public:
  static CATImageBuffer* CreatePixelImageTS(CATMMPISpec* iSpec, CATMMPIBuffer* ipBuffer, unsigned int iXSize, unsigned int iYSize);
  static CATImageBuffer* MakeACopyFrom(const CATImageBuffer& iImgBuf);

  virtual ~CATImageBuffer();

  virtual void        SetXPixelSize(float iXPixelSize)                          { _xPixelSize = iXPixelSize; };
  virtual void        SetYPixelSize(float iYPixelSize)                          { _yPixelSize = iYPixelSize; };

  CATBoolean          IsReadOnly()                                              { return TRUE; };
  const CATMMPISpec*  GetBufferSpecification() const;
  virtual void        GetSize(unsigned int& oXSize, unsigned int& oYSize) const;
  virtual float       GetXPixelSize() const                                     { return _xPixelSize; };
  virtual float       GetYPixelSize() const                                     { return _yPixelSize; };
  virtual const void* GetPixelsToRead() const;
  virtual const CATMMPIBuffer* GetImageBuffer() const;

private:
  CATImageBuffer(CATMMPISpec* iSpec, CATMMPIBuffer* ipBuffer, unsigned int iXSize, unsigned int iYSize);
  CATImageBuffer(const CATImageBuffer&);
  const CATImageBuffer operator=(const CATImageBuffer&);

  CATMMPISpec*    _spec;
  unsigned int    _xSize,_ySize;
  float           _xPixelSize,_yPixelSize;
  CATMMPIBuffer*  _pBuffer;
};

#endif
