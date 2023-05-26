#ifndef CATMMPIPIXELCOLORSPEC_H
#define CATMMPIPIXELCOLORSPEC_H

#include "CATMMediaPixelImage.h"

#include "CATMMCTSBaseUnknownPoolInstance.h"
#include "CATSysTSListOfUnicodeString.h"
#include "CATMMPITypeDesc.h"
#include "CATPixelImage.h"

#define MAX_NB_CHANNELS  8
#define MAX_SZ_CHANNEL  32

struct CATMMPITypeDesc;
class CATMMPIColorSpace;
class CATPixelConverterParameters;


using FuncPixelConverter = int(*)(void*, const void*, CATPixelConverterParameters&);
/**
 * @ingroup groupPixelImageColor
 **/
class ExportedByCATMMediaPixelImage CATMMPIPixelColorSpec : public CATMMCTSBaseUnknownPoolInstance
{
  CATSysTSDeclareClass;
  friend CATMMCTSBaseUnknownPoolInstance* __CreateMMPIColorSpecForPool();
public:

  /** @name CATMMCTSBaseUnknownPoolInstance */
  /**@{*/
  virtual bool                    BeforeReleasingInstanceToPool();
  /**@}*/



  /** @name Lifecycle / memory */
  /**@{*/
  /**
   * Return CATMMPIPixelColorSpec build from a CATPixelImageFormat.
   * @param format. A PixelImageFormat to build the CATMMPIPixelColorSpec from.
   * @param ipColorSpace is optional.
   * @return Returns the CATMMPIPixelColorSpec. Has to be Released after use.
   */
  static CATMMPIPixelColorSpec*   CreatePixelColorSpec(CATPixelImageFormat format, CATMMPIColorSpace *ipColorSpace=NULL);

  /**
   * Return CATMMPIPixelColorSpec build from a CATMMPIPixelColorSpec and a CATMMColorPorfile.
   * @param iColorSpec. A CATMMPIPixelColorSpec to retrieve information for building new CATMMPIPixelColorSpec.
   * @param ipColorProfile the desired color profile for new CATMMPIPixelColorSpec.
   * @return Returns the CATMMPIPixelColorSpec. Has to be Released after use.
   */
  static CATMMPIPixelColorSpec*   GetOrCreatePixelColorSpec(CATMMPIPixelColorSpec& iColorSpec, CATMMColorProfile *ipColorProfile);

  /**
   * Return CATMMPIPixelColorSpec build or retrieved from a CATPixelImage.
   * @param ipImage. The CATPixelImage on which the CATPixelColorSpec has to be retrieved.
   * @return Returns the CATMMPIPixelColorSpec. Has to be Released after use.
   */
  static CATMMPIPixelColorSpec*   BuildOrRetrievePixelColorSpecFromPixelImage(CATPixelImage &iImage);

  /**
   * @return Returns the CATMMPIPixelColorSpec. Has to be Released after use.
   */
  static CATMMPIPixelColorSpec*   GetDefaultRGBPixelColorSpec();
  static CATMMPIPixelColorSpec*   GetDefaultPixelColorSpec(CATPixelImageFormat iFormat);

  virtual ~CATMMPIPixelColorSpec();
  /**@}*/



  /** @name Info */
  /**@{*/
  enum RoundToBytes { RTB_Bits = 0, RTB_LowerByte = -1, RTB_UpperByte = 1 };
  /**
   * Returns true if pixel buffers are available through GetPixelsToRead() and GetPixelsToModify().
   */
  static CATBoolean               UsingBaseFormat(CATPixelImageFormat iFormat);
  /**
   * Returns true if pixel buffers are available through GetFloatingPixelsToRead() and GetFloatingPixelsToModify().
   */
  static CATBoolean               UsingFloatFormat(CATPixelImageFormat iFormat);
  CATBoolean                      HasSameSpecThan(const CATMMPIPixelColorSpec& iColorSpec)  const;
  /**
   * @return Returns the CATMMPIColorSpace. Has to be released after use.
   */
  CATMMPIColorSpace*              GetColorSpace()                                           const;
  /**
   * Return the index if exist, and -1 if fails.
   */
  CATBoolean                      HasAlpha()                                                const {return 0<=_hasAlpha; };
  int                             HasChannel(const CATUnicodeString& iChannel)              const;
  CATSysTSListOfUnicodeString     GetChannels()                                             const;
  const unsigned int*             GetOrdering()                                             const;
  const CATMMPITypeDesc*          GetFormat(int iIndex)                                     const;
  CATPixelImageFormat             GetFormat()                                               const { return _piFormat; };
  /*
   * Check if all channels have same type.
   * @param testAlsoOnBits: if true, the algorithm will not only check if all channels are of the same type
   *                        more generally, it will check if all channels are of the same size.
   *                        Theefore, it will be possible to initialize the memory through a new with a primitive data of size of bits.
   */
  const CATMMPITypeDesc*          HomogeneousFormats(bool testAlsoOnBits = 0)               const;
  bool                            HomogeneousFormatsTo(const CATMMPITypeDesc iTD)           const;
  bool                            HomogeneousFormatsToB(const CATMMPITypeDesc::BASETYPE iBT)const;
  unsigned int                    ChannelsGetNB()                                           const;
  const char*                     GetChannel(int iIndex)                                    const;
  /**@}*/                         
                                  
                                  
  /** @name Memory */
  /**@{*/
  static int                      GetBitsPerPixel(const CATPixelImageFormat iFormat);
  static int                      GetSizePerPixel(const CATPixelImageFormat iFormat, RoundToBytes getInBytes = RTB_UpperByte);
  static size_t                      GetValidSize(const int iWidth, const int iHeight, const CATPixelImageFormat iFormat);
  size_t                          GetMemorySize(RoundToBytes getInBytes = RTB_UpperByte)          const;
  /**
   * Return array of free memory initialized to 0 in which can be stored a color specified by CATMMPIPixelColorSpec.
   * @param iCount. The number of pixel color to create. Default is 1, so one pixel.
   * @return color's memory array. Pointer to array has to be deleted.
   */
  void*                           CreateColorMemory(CATUINT32 iCount = 1)                   const;
  CATMMPIBuffer*                  CreateBufferOfColorMemory(CATUINT32 iCount = 1)           const;
  bool                            DeleteBufferOfColorMemory(void*&ioBuffer)                 const;
  /**@}*/


  /** @name Conversion */
  /**@{*/                         
  static FuncPixelConverter       GetPixelConverter(PixelImageFormat oFormat, PixelImageFormat iFormat);
  static bool                     GetPixelConverterParameters(PixelImageFormat oFormat, PixelImageFormat iFormat, CATPixelConverterParameters& oParameters);
  /**@}*/

private:
  CATMMPIPixelColorSpec();
  CATMMPIPixelColorSpec(const CATMMPIPixelColorSpec&);
  CATMMPIPixelColorSpec& operator=(const CATMMPIPixelColorSpec&);

  CATMMPITypeDesc*              _format;
  CATMMPIColorSpace*            _pColorSpace;
  /*
   * Image channel ordering
   * e.g. BGR -> _ordering[2,1,0]
   */
  unsigned int*                 _ordering;
  unsigned int                  _channelsNB;
  CATPixelImageFormat           _piFormat;
  unsigned int                  _bufferMemSzInBits;
  char                          _channelnames[MAX_NB_CHANNELS][MAX_SZ_CHANNEL];
  int                           _hasAlpha;
  bool                          _premultiplied_alpha;

  void                          InitTable();
  void                          Clear();
  void                          ClearChannels();
  void                          ChannelsAddAlpha();
  const char*                   DumpChannels() const;
  unsigned int                  ComputeMemorySize();

  /*
   * Table of CATMMPIPixelColorSpec for each CATPixelImageFormat.
   */
  static CATMMPIPixelColorSpec* _lstBaseFormat[Specific + 1];
  /*
   * CreatePixelColorSpecFromPool manage a pool of instances to minimise instanication.
   */
  static CATMMPIPixelColorSpec* CreatePixelColorSpecFromPool();
  /*
   * Table  of pixel converter from a CATPixelImageFormat to another CATPixelImageFormat.
   *                                               [output format][input format]
   */
  static FuncPixelConverter     _TablePixelConverter[Specific + 1][Specific + 1];
public:
  /*
   * Return index of alpha channel.
   */
  int                             HasAlphaI()                                                const;

};


#endif
