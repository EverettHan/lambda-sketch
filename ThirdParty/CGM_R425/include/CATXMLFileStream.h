#ifndef CATXMLFileStream_h
#define CATXMLFileStream_h

// XMLParser framework
#include "CatXmlItfBase.h"
class CATIXMLInputStream_var;

// System framework
#include "CATBaseUnknown.h"
class CATUnicodeString;

/**
 * Class to provide a file-based implementation of the CATIXMLInputStream interface
 * @author: Jean-Francois Doue (JDU)
 */
class ExportedByCatXmlItfBase CATXMLFileStream : public CATBaseUnknown {
	CATDeclareClass;
	public:
		static HRESULT CreateCATXMLFileStream(
			const CATUnicodeString& iPath,
			CATIXMLInputStream_var& oStream);

		CATXMLFileStream(
			unsigned int iFileDescriptor);
		virtual ~CATXMLFileStream();

		// Implement the CATIXMLInputStream interface
		virtual HRESULT Read(
			unsigned char* ioByteArray,
			unsigned int iByteArrayCapacity,
			unsigned int& oSizeRead);
	private:
		unsigned int _fileDescriptor;
		unsigned int _sizeRead;
};

#endif // CATXMLFileStream_h
