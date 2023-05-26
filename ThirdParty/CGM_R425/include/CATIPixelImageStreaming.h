#ifndef CATIPixelImageStreaming_H
#define CATIPixelImageStreaming_H

// COPYRIGHT DASSAULT SYSTEMES 2008

#include "CATMMediaPixelImage.h"
#include "CATBaseUnknown.h"
#include "CATPixelImage.h"
class CATStreamer;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATMMediaPixelImage IID IID_CATIPixelImageStreaming;
#else
extern "C" const IID IID_CATIPixelImageStreaming;
#endif

class ExportedByCATMMediaPixelImage CATIPixelImageStreaming : public CATBaseUnknown
{
	    CATDeclareInterface;

	public:

		/**
		* @nodoc
		* Streams a <tt>CATPixelImage</tt>.
		*/
		virtual HRESULT Stream(CATStreamer& oStr) = 0;
		
		/**
		* @nodoc
		* Streams a <tt>CATPixelImage</tt>.
		* The iStrCmpFormat parameter sets the format type of the stream.
		* For BILEVEL bitmap, the format used is CCITT Group3(Stream_CCITTG3).
		* For RGBA, RGB, LA, or L bitmap, the format used can be PNG or JPEG or not compressed
		* (Stream_PNG or Stream_JPEG or Stream_UNCOMPRESSED).
		*/
		virtual HRESULT Stream(CATStreamer& oStr, CATStreamFormat iStrCmpFormat) = 0;
		
		/**
		* @nodoc
		* UnStreams a <tt>CATPixelImage</tt>.
		*/
		virtual HRESULT UnStream(CATStreamer& iStr) = 0;
		

		/**
		* @nodoc
		* Get the format of a <tt>CATPixelImage</tt> stream.
		* The oStrCmpFormat parameter is the format type of the stream.
		* For BILEVEL bitmap, the format used is CCITT Group3(Stream_CCITTG3).
		* For RGBA, RGB, LA, or L bitmap, the format used can be PNG or JPEG or not compressed
		* (Stream_PNG or Stream_JPEG or Stream_UNCOMPRESSED).
		*/
		virtual HRESULT GetStreamFormat(CATStreamer& iStr, CATStreamFormat& oStrCmpFormat) = 0;	
};

CATDeclareHandler(CATIPixelImageStreaming, CATBaseUnknown);

#endif
