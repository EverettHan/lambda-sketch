#ifndef CATPRTIMAGEITERATOR_H
#define CATPRTIMAGEITERATOR_H

#include "CATMMediaRasterProcessor_Codec.h"

//system
#include "CATBaseUnknown.h"

class CATPixelImage;

/**
 * @ingroup groupPixelImageBufferAccess
 * @brief CATPrtImageIterator is image iterator class, can be used to iterate through bytes in a CATPixelImage object
*/
///class ExportedByCATPrintBase CATPrtImageIterator : public CATBaseUnknown
class ExportedByCATMMediaRasterProcessor_Codec CATPrtImageIterator : public CATBaseUnknown
///
{
  CATDeclareClass;

public:
   
/** 
*   Constructs CATPrtImageIterator for an image
*   @param iP
*       input image pointer (CATPixelImage)
*   @param iFlip
*       1 , If input image needs to be fliped.
*       0 , If input image need not be fliped.
*   @param iNoAlpha
*       0 , To consider Alpha for RGBA, LA images
*       1 , Not to consider alpha for RGBA images
*/
   CATPrtImageIterator(const CATPixelImage* iP, int iFlip,int iNoAlpha); 

/** 
*   Give next char
*   @param oC
*       output char
*   @return 
*   The status of the method.
*   <br><b>Legal values</b>:  0 -> failure (no more bytes available), 1 ->  success
*/
   int NextChar(unsigned char& oC); //return 0 if no more pixels


private :
    int  NextPixel(); //return 0 if no more pixels
    CATPixelImage* _image;
    int            _bytesPerPixel;
    int            _flip;
    int            _noAlpha;
    unsigned char* _pixels;
    int            _width;
    int            _height;
    int            _index;
    unsigned int            _pixelIndex;
    unsigned int            _size;
};


#endif // CATPRTIMAGEITERATOR_H

