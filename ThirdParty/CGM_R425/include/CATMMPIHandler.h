#ifndef CATMMPIHANDLER_H
#define CATMMPIHANDLER_H

#include "DSYSysCommon.h"
#include "CATSysTSBaseUnknown.h"
#include "CATSYPCheck.h"
#include "CATPixelImage.h"


class CATMMPISpec;
class CATMMPIBuffer;
class CATImageBuffer;
class CATMMPIImageInst;


class CATMMPIImageItf
{
public:
  virtual bool                          isValid()                                 const     ;
  virtual const CATMMPISpec*            getSpec()                                 const     ;
  virtual CATPixelImageFormat           getFormat()                               const     ;
  virtual const void*                   getBufferToRead()                         const     ;
  virtual void*                         getBufferToModify()                                 { return NULL; };
  virtual unsigned int                  w()                                       const     ;
  virtual unsigned int                  h()                                       const     ;
  virtual unsigned int                  bpp()                                     const     ;

protected:
  CATMMPIImageItf():_hdl(NULL)                                                              {};
  CATMMPIImageItf(const CATMMPIImageItf&)                                                   ;
  CATMMPIImageItf& operator=(const CATMMPIImageItf& icHdl)                                  ;
  virtual ~CATMMPIImageItf()                                                                ;
  CATMMPIImageInst* _hdl;
};

class CATMMPIConstImageHdl : public CATMMPIImageItf
{
public:
  CATMMPIConstImageHdl()                                                                    :CATMMPIImageItf(){};
  virtual ~CATMMPIConstImageHdl()                                                           ;
  
  /**
   * @param ipImage: is AddRef.
   */
  CATMMPIConstImageHdl(const CATPixelImage*  ipImage)                                       ;
  /**
   * @param ipImage: is AddRef.
   */
  CATMMPIConstImageHdl(const CATImageBuffer* ipImage)                                       ;
  /**
   * @param ipSpec: is duplicated.
   * @param ipBuffer: data buffer is pointed.
   */
  CATMMPIConstImageHdl(const CATMMPISpec* ipSpec, CATUINT32 iNbElem, const void* ipBuffer)  ;
  /**
   * @param ipSpec: is duplicated.
   * @param ipBuffer: data buffer is pointed.
   */
  CATMMPIConstImageHdl(const CATMMPISpec* ipSpec, unsigned int w, unsigned int h, const void* ipBuffer);
  /**
   * @param ipSpec: is duplicated.
   * @param ipBuffer: is duplicated, but pointed buffer is not duplicated.
   */
  CATMMPIConstImageHdl(const CATMMPISpec* ipSpec, const CATMMPIBuffer* ipBuffer, unsigned int h = 1);

  CATMMPIConstImageHdl(const CATMMPIConstImageHdl& icHdl)                                   ;
  CATMMPIConstImageHdl& operator=(const CATMMPIConstImageHdl& icHdl)                        ;

  static CATMMPISpec* CreateSpec(CATPixelImageFormat iFmt);

};

class CATMMPIImageHdl : public CATMMPIConstImageHdl
{
public:
  CATMMPIImageHdl()                                                                         :CATMMPIConstImageHdl(){};
  virtual ~CATMMPIImageHdl();

  /**
   * @param ipImage: is AddRef.
   */
  CATMMPIImageHdl(CATPixelImage*  ipImage)                                                  ;
  /**
   * @param ipImage: is AddRef.
   */
  CATMMPIImageHdl(CATImageBuffer* ipImage)                                                  ;
  /**
   * @param ipSpec: is duplicated.
   * @param ipBuffer: data buffer is pointed.
   */
  CATMMPIImageHdl(const CATMMPISpec* ipSpec, CATUINT32 iNbElem, void* ipBuffer)             ;
  /**
   * @param ipSpec: is duplicated.
   * @param ipBuffer: data buffer is pointed.
   */
  CATMMPIImageHdl(const CATMMPISpec* ipSpec, unsigned int w, unsigned int h, void* ipBuffer);
  CATMMPIImageHdl(const CATMMPISpec* ipSpec, CATMMPIBuffer* ipBuffer, unsigned int h=1)     ;

  CATMMPIImageHdl(const CATMMPIImageHdl& icHdl)                                             ;
  CATMMPIImageHdl& operator=(const CATMMPIImageHdl& icHdl)                                  ;

  virtual void*                         getBufferToModify()                                 ;
};

#endif
