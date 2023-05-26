#ifndef CATVISPIXELIMAGE_H
#define CATVISPIXELIMAGE_H

#include "CATPixelImage.h"
#include "SGInfra.h"

class l_CATVisPixelImage;

class ExportedBySGInfra CATVisPixelImage : public CATPixelImage
{
  friend class l_CATVisPixelImage;

public :
  CATVisPixelImage();  
  CATVisPixelImage(int x,int y, CATPixelImageFormat format);
  CATVisPixelImage(int x,int y, CATPixelImageFormat format, float* floatPixels, CATDeallocatePixels iToDelete = PixDeallocateNO);  
  virtual ~CATVisPixelImage(); 
  
  void  SetUpdated  (bool iUpdated);
  bool  GetUpdated  ();    
  void  Update      ();

  void  SetSyncMode (int iSyncMode);
  int   GetSyncMode ();    

  virtual const unsigned char* GetPixelsToRead()  const;  
  virtual float* GetFloatingPixelsToModify(); // I do not really like to redefine that function, but I do not have something like     
  virtual l_CATVisPixelImage* GetLetter();  
   
private :  
  bool                _updated;
  int                 _syncMode;
  l_CATVisPixelImage* _letter;
};

#endif
