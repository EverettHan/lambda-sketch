#ifndef CATMMEDIAIMAGECODEC_H
#define CATMMEDIAIMAGECODEC_H
//----------------------------------------------------------------------------
//	COPYRIGHT DASSAULT SYSTEMES 2001
//----------------------------------------------------------------------------
// Module Name:
//               CATMMediaImageCodec.h
//--------------------------------------------------------------
// Abstract:
//               Basic Codec for Raster compression/decompression
//               Current implementation of CCITT grp 3/4 ....
//
//--------------------------------------------------------------
//----------------------------------------------------------------------------------
//History :
// 	09/01/13 : XXL Fix conflict with isstrstream/ostrstream forward declaration
//----------------------------------------------------------------------------------

#include "CATMMediaRasterProcessor_Codec.h"
#include "CATBaseUnknown.h"

class ostream_withassign;

#ifdef _CAT_ANSI_STREAMS
#include <iostream.h>

#ifndef _OSTREAM_WITHASSIGN
#define _OSTREAM_WITHASSIGN
/**
 * @nodoc
 */
class ostream_withassign : public ostream
{
public:
/**
 * @nodoc
 */
    ostream_withassign() : ostream(NULL) {}
/**
 * @nodoc
 */
    ostream_withassign(const ostream& os) : ostream(os.rdbuf()) {}
/**
 * @nodoc
 */
    ostream& operator=(const ostream& os) { this->rdbuf(os.rdbuf()); return *this; }
/**
 * @nodoc
 */
    ostream& operator=(streambuf* sb) { this->rdbuf(sb); return *this; }
};
#endif
#endif // _CAT_ANSI_STREAMS

class CATPixelImage;


#ifndef uchar
typedef unsigned char uchar;
#endif

/** @nodoc */
ExportedByCATMMediaRasterProcessor_Codec int CCITT_G4_dec(const uchar * pixels, int nbIntBytes , int size[2], uchar* outPixels , 
                       int& nbLinesDec, int& status);

/** @nodoc */
ExportedByCATMMediaRasterProcessor_Codec int  CCITT_G4_enc(const uchar* pixels, int pixelSize[2], int& compressPixAlloc , uchar* compressPixels, 
                       int& compressPixelsSize , int& status);


/**
* Method performs Run Length Encoding on input image and dumps it into stream
* @param _out
*   Stream in which encoded image to be dumped
* @param iNoAlpha
*   1 - If alpha should not be considered
*   0 - If alpha should be considered
* @param ipImage
*   Input image to be RLE encoded
* @param iFlip
*   1 - If image to be flipped before encoding
*   0 - image need not be flipped
* @param iSimulation
*   1 - Just simulate RLE donot perform actual encoding
*   0 - Perform RLE encoding
* @return
*   The status of the method.
*   <br><b>Legal values</b>:  0 -> RLE not effiecient, 1 -> Success
*/
ExportedByCATMMediaRasterProcessor_Codec int RunLengthEncode(ostream_withassign &_out,int iNoAlpha,const CATPixelImage *ipImage=NULL,int iFlip=1,int iSimulation=0);

/**
* Method Dumps input unsigned character array in stream in ASCII85 format
* @param _out
*   Stream in which ASCII85 coded string to be dumped
* @param p
*   Input unsigned char array
* @param size
*   size of onput array in bytes
*/
ExportedByCATMMediaRasterProcessor_Codec void DumpASCII85(ostream_withassign &_out,const unsigned char* p, size_t size);

/**
* This method is usedful for dumping Transparency part of RGBA and LA image.
* Not useful for RGB,L,BILEVEL images.
* @param _out
*   Stream in which image mask to be dumped
* @param ipImage
*   Input image for which mask to be dumped
* @param iFlip
*   1 - If image to be flipped before dumping mask
*   0 - image need not be flipped
* @return
*   The status of the method.
*   <br><b>Legal values</b>:  E_FAIL -> Failure, S_OK -> Success
*/ 
ExportedByCATMMediaRasterProcessor_Codec HRESULT DumpMask(ostream_withassign &_out,const CATPixelImage * pPixelImage,int iFlip=1);

/**
* This method is used to dump color part of image into the stream (mostly done when image is not RLE compressible)
* Pixels of RGB,L are dumped as they are
* For RGBA and LA images, Transparency is changed to colour (if alpha < 126) pixel is made white.
* and color part of pixels is dumped.
* The Transparency needs to be dumped separately.
* @param _out
*   Stream in which image to be dumped
* @param ipImage
*   Input image to be dumped
* @param iFlip
*   1 - If image to be flipped before dumping.
*   0 - image need not be flipped
* @return
*   The status of the method.
*   <br><b>Legal values</b>:  E_FAIL -> Failure, S_OK -> Success
*/ 
ExportedByCATMMediaRasterProcessor_Codec HRESULT DumpImage(ostream_withassign &_out,const CATPixelImage * pPixelImage,int iFlip=1);


/**
* Method Decodes Run Length Encoded unsigned char array
* @param ipIn
*   Input unsigned char array
* @param iInSize
*   size of input array in bytes
* @param opOut
*   output unsigned char array (will be allocated by this function)
* @param oOutSize
*   size of output array in bytes
* @param iSimul
*   simulation of decode. Only gives probable size after decode, nothing will be filed in output array opOut.
*     0 - no simulation, output array (opOut) will be filled.
*     1 - simulation done for determining size, output array (opOut) remain NULL.
*   Default value is 0 (no simulation)
*/
ExportedByCATMMediaRasterProcessor_Codec HRESULT RunLengthDecode( const unsigned char *ipIn, const unsigned int iInSize, 
                                               unsigned char* &opOut, unsigned int &oOutSize, int iSimul=0);

/**
* Method Decodes ASCII85 encoded string
* @param ipIn
*   Input unsigned char array
* @param iInSize
*   size of input array in bytes
* @param opOut
*   output unsigned char array (will be allocated by this function)
* @param oOutSize
*   size of output array in bytes
* @param iSimul
*   simulation of decode. Only gives probable size after decode, nothing will be filed in output array opOut.
*     0 - no simulation, output array (opOut) will be filled.
*     1 - simulation done for determining size, output array (opOut) remain NULL.
*   Default value is 0 (no simulation)
*/
ExportedByCATMMediaRasterProcessor_Codec HRESULT ASCII85Decode(const unsigned char* ipIn, const unsigned int iInSize, 
                                             unsigned char* &opOut, unsigned int &oOutSize, int iSimul=0);


/**
* Method performs Run Length Encoding simulation
* @param _out
*   Stream for simulation
* @param iNoAlpha
*   1 - If alpha should not be considered
*   0 - If alpha should be considered
* @param ipImage
*   Input image to be RLE encoded (simulation)
* @param iFlip
*   1 - If image to be flipped before encoding
*   0 - image need not be flipped
* @return
*   The status of the method.
*   <br><b>Legal values</b>:  0 -> RLE not effiecient, 1 -> RLE effiecient
*/
ExportedByCATMMediaRasterProcessor_Codec int IsRLECompressible(ostream_withassign &_out,int iNoAlpha,const CATPixelImage *ipImage=NULL,int iFlip=1);

#endif
