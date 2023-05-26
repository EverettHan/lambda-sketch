// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATXMLPPCodec_h
#define CATXMLPPCodec_h

// XMLParser framework private headers
#include "CatXmlItfBase.h"

// System framework
#include "CATUnicodeString.h"
#include "CATBoolean.h"

#ifndef _WINDOWS_SOURCE
#ifndef _ANDROID_SOURCE
#include <iconv.h>
#endif // _ANDROID_SOURCE
#endif // _WINDOWS_SOURCE

/**
 * Class to manage character set conversions from UCS-2
 * to another code page.
 * @author Jean-Francois DOUE (JDU)
 */
class ExportedByCatXmlItfBase CATXMLPPCodec {
	
	public:
		/**
		 * Factory method
		 */
		static HRESULT CreateCATXMLPPCodec(
			const CATUnicodeString& iTo,
			CATXMLPPCodec*& oCodec);

		/**
		 * Destructor
		 */
		virtual ~CATXMLPPCodec();

		HRESULT Transcode(
			const char* const iSrcBytes,
			const unsigned int iSrcCount,
			char* const ioDestBytes,
			const unsigned int iDestCapacity,
			unsigned int& oDestCount,
			unsigned int& oSrcConsumed);

	private:
		// The copy constructor and the equal operator must not be implemented
		CATXMLPPCodec (CATXMLPPCodec &);
		CATXMLPPCodec& operator=(CATXMLPPCodec&);

		/**
		 * Constructor
		 */
#ifdef _WINDOWS_SOURCE
		CATXMLPPCodec(
			unsigned int iCodePage,
			int mode);

		/**
		 * Returns the code page ID base on the code page name.
		 */
		static HRESULT _GetCodePage(
			const CATUnicodeString& iName,
			unsigned int& oCodePage);

		static CATBoolean _IsAlias(
			const HKEY iEncodingKey,
			unsigned char* const ioAliasBuf = 0,
			const unsigned int iNameBufSz = 0 );

#else // _WINDOWS_SOURCE
		CATXMLPPCodec(
#ifndef _ANDROID_SOURCE
			iconv_t iConverter,
#endif // _ANDROID_SOURCE
			int mode);

		/**
		 * Returns the OS-dependent charset name for the supplied
		 * character set.
		 */
		static char* _GetCharSetName(
			const CATUnicodeString& iName);

#endif // _WINDOWS_SOURCE
	private:
#ifdef _WINDOWS_SOURCE
		unsigned int _codePage;
#else // _WINDOWS_SOURCE
#ifndef _ANDROID_SOURCE
	iconv_t	_converter;
#endif // _ANDROID_SOURCE
#endif // _WINDOWS_SOURCE
		int _mode;
};

#endif // CATXMLPPCodec_h
