#ifndef CATMMPIIMAGEPIXELITERATOR_H
#define CATMMPIIMAGEPIXELITERATOR_H

#include "CATMMediaPixelImage.h"

#include "CATMMPIPixelColor.h"
#include "CATMMPIHandler.h"
#include "CATPixelImage.h"

class CATMMPISpec;
class CATImageBuffer;
class CATPixelImage;

/**
 * @ingroup groupPixelImageBufferAccess
 * @brief Iterator on CATPixelImage: forward, backward, jump to position...
 **/
class ExportedByCATMMediaPixelImage CATMMPIImagePixelIterator
{
public:
  CATMMPIImagePixelIterator();
//CATMMPIImagePixelIterator(const CATPixelImage*);
//CATMMPIImagePixelIterator(const CATImageBuffer* ipImageBuffer);
//CATMMPIImagePixelIterator(const CATMMPISpec* ipSpec, const CATMMPIBuffer* ipBuffer);
//CATMMPIImagePixelIterator(const CATMMPISpec* &ipSpec, CATUINT32 iNbElem, const void* ipBuffer);
  virtual ~CATMMPIImagePixelIterator();
  virtual void                      SetImage(const CATMMPIConstImageHdl&);

  virtual int                       GetX()                                            const = 0;
  virtual int                       GetY()                                            const = 0;
  virtual bool                      IsOutOfScope()                                    const = 0;
  virtual bool                      IsRowStartOrOutScope()                            const = 0;
  virtual bool                      IsRowEndOrOutScope()                              const = 0;
  /**
   * SetPosition 
   * y is impacted when inverting vertical processing.
   */
  virtual bool                      SetPosition(unsigned int x, unsigned int y)       const = 0;
  /**
   * Behavior impacted by inverted vertical processing.
   */
  virtual bool                      Next()                                            const = 0;
  /**
   * Behavior impacted by inverted vertical processing.
   */
  virtual bool                      Previous()                                        const = 0;
  /**
   * Go to next row but same abscissa.
   * Behavior impacted by inverted vertical processing.
   */
  virtual bool                      NextRow()                                         const = 0;

  /**
   * Compare pixels of two given rows.
   * @return returns -1 if service is not supported or failed, 0 if rows are equal, 1 if different.
   */
  virtual int                       CompareRows(unsigned int idxRow1, unsigned int idxRow2)const = 0;

  virtual const CATMMPIPixelColor*  GetSafeConstPixelColor()                          const = 0;
  virtual const CATMMPIPixelColor&  GetConstPixelColor()                              const = 0;
  virtual CATMMPIPixelColor*        GetSafePixelColor()                                     = 0;
  virtual CATMMPIPixelColor&        GetPixelColor()                                         = 0;

  virtual bool                      IsInvertedVerticalProcessing()                    const   { return _invV; };
  virtual bool                      InvertedVerticalProcessing(bool Invert)           const   { if(_h<=1) return 0; _invV=Invert; return 1; };

protected:
  void                              DeleteData(CATMMPIPixelColor& ioColor)            ;
  inline void                       SetData(CATMMPIPixelColor& ioColor, void* ipData) const   { ioColor._pColorValue=ipData; };
  inline void*                      GetData(CATMMPIPixelColor& ioColor)               const   { return ioColor._pColorValue; };
  bool                              IsPacked()                                        const;
  const CATMMPISpec*                getSpec()                                         const;
  CATPixelImageFormat               getFormat()                                       const;

  CATMMPIConstImageHdl        _img;
  unsigned int                _w, _h,_bpp;
  mutable bool                _invV;
};

#endif
