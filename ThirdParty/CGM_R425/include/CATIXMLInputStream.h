#ifndef CATIXMLInputStream_h
#define CATIXMLInputStream_h

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

// COPYRIGHT DASSAULT SYSTEMES 2005

// System framework
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

// XMLParser framework
#include "CatXmlItfBase.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATIXMLInputStream;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIXMLInputStream ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface for objects which know how to provide XML
 * to an XML parser.
 */
class ExportedByCatXmlItfBase CATIXMLInputStream : public CATBaseUnknown {
	CATDeclareInterface;
	public:
		/**
		 * Asks the stream to fetch the next available bytes
		 * and put them the supplied byte array.
		 * @param ioByteArray
		 * The byte array to fill
		 * @param iByteArrayCapacity
		 * The size of the byte array
		 * @param oSizeRead
		 * The number of bytes read. 
		 * If not zero, the parser will call Read again to get the following bytes in the stream. 
		 * If zero, the parser will consider it has reached the end of the stream.
		 */
		virtual HRESULT Read(
			unsigned char* ioByteArray,
			unsigned int iByteArrayCapacity,
			unsigned int& oSizeRead) = 0;
};

CATDeclareHandler(CATIXMLInputStream, CATBaseUnknown);

#endif // CATIXMLInputStream_h
