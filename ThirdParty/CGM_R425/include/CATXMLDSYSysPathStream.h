#ifndef CATXMLDSYSysPathStream_h
#define CATXMLDSYSysPathStream_h

// XMLParser framework
#include "CatXmlItfExt.h"
class CATIXMLInputStream_var;

// System framework
#include "CATBaseUnknown.h"
class CATUnicodeString;

// System framework
#include "DSYSysPath.h"
#include "DSYSysStdIO.h"

/**
 * Class to provide a DSYSysPath-based implementation of the CATIXMLInputStream interface
 * @author: Jean-Francois Doue (JDU)
 */
class ExportedByCatXmlItfExt CATXMLDSYSysPathStream : public CATBaseUnknown {
	CATDeclareClass;
	public:
		static HRESULT CreateCATXMLDSYSysPathStream(
			const CATUnicodeString& iPath,
			CATIXMLInputStream_var& oStream);
		static CATBoolean IsExtendedPath(
			const CATUnicodeString& iPath);
		virtual ~CATXMLDSYSysPathStream();

		// Implement the CATIXMLInputStream interface
		virtual HRESULT Read(
			unsigned char* ioByteArray,
			unsigned int iByteArrayCapacity,
			unsigned int& oSizeRead);

	private:
		CATXMLDSYSysPathStream(
			DSYSysPath& iPath,
			DSYSysFileDescriptor& iFileDescriptor);
	private:
		DSYSysPath _path;
		DSYSysFileDescriptor _fileDescriptor;
		unsigned int _sizeRead;
};

#endif // CATXMLDSYSysPathStream_h
