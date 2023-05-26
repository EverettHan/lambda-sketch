#ifndef CATMMPIPIXELCOLOR_H
#define CATMMPIPIXELCOLOR_H

#include "CATMMediaPixelImage.h"

#include "CATSysBoolean.h"

class CATMMPIPixelColorSpec;
class CATPixelImage;

/**
 * @ingroup groupPixelImageBufferAccess
 */
class ExportedByCATMMediaPixelImage CATMMPIPixelColor
{
  friend class CATMMPIPixelImageAccess;
  friend class CATMMPIImagePixelIterator;
  friend class CATMMPIPixelImageModifier;
  friend class lCATPixelImage;
public:

  /**
   * @param input spec will consuned by constructor: has to be AddRef, will be released at destruction.
   **/
  CATMMPIPixelColor(CATMMPIPixelColorSpec*ipColorSpec);

  CATMMPIPixelColor(const CATPixelImage *ipPixelImage);
  
  //Value class:
  CATMMPIPixelColor();//Default RGB black.
  CATMMPIPixelColor(const CATMMPIPixelColor& iColor);
  CATMMPIPixelColor& operator=(const CATMMPIPixelColor& iColor);
  //.

  virtual ~CATMMPIPixelColor();
  
  /**
   * Change color specification, but DO NOT convert color value.
   * @param input spec will be AddRef.
   **/
  CATBoolean SetColorSpec(const CATMMPIPixelColorSpec* ipColorSpec);
  
  CATBoolean HasSameSpecThan(const CATMMPIPixelColor& iColor)               const;
  CATBoolean HasSameSpecThan(const CATMMPIPixelColorSpec* ipColorSpec)      const;

  /**
   * Compare color value assuming they have same specifications.
   *   Choose this function if performance is aimed.
   **/
  CATBoolean HasSameColorWithSameSpecThan(const CATMMPIPixelColor& iColor)  const;

  /**
   * Compare color value and specifications.
   *   If they have different specifications, return FALSE, no color conversion is done.
   **/
  CATBoolean HasSameSpecAndColorThan(const CATMMPIPixelColor& iColor)       const;

  /**
   * Return color specifications.
   * @param color specification. Pointer has to be released after use.
   */
  CATMMPIPixelColorSpec* GetColorSpec() const;
  /*
   * @return const CATMMPIPixelColorSpec. Lifecycle is linked to CATMMPIPixelColor.
   */
  const CATMMPIPixelColorSpec* GetConstColorSpec() const;

  /**
   * Set color value assuming they have same specifications.
   **/
  CATBoolean SetColorWithSameSpecThan(const CATMMPIPixelColor& iColor)  const;

  CATBoolean    SetBWColor(CATBoolean iValue);
  CATBoolean    GetBWColor()                  const; 

  CATBoolean    SetUCHARi(unsigned int iIndex, unsigned char iValue);
  unsigned char GetUCHARi(unsigned int iIndex) const;

  CATBoolean    SetUCHARc(const char*ipChannel, unsigned char iValue);
  unsigned char GetUCHARc(const char*ipChannel) const;

  CATBoolean    SetFloat(unsigned int iIndex, float iValue);
  float         GetFloat(unsigned int iIndex) const;

  CATBoolean    SetQuickUCHARi(unsigned int iIndex, unsigned char iValue);
  unsigned char GetQuickUCHARi(unsigned int iIndex) const;

protected:
  void          DeleteData();
  const CATMMPIPixelColorSpec *_pColorSpec;
  void*                        _pColorValue;
};

#endif
