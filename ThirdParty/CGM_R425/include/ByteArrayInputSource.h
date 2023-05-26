#ifndef ByteArrayInputSource_h
#define ByteArrayInputSource_h

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIXMLInputStream.h"

/**
 * Class to implement the CATIXMLInputStream backed by
 * a byte array.
 */
class ExportedByCatXmlItfExt ByteArrayInputSource: public CATIXMLInputStream {
	CATDeclareClass;
	public:
		ByteArrayInputSource(
			unsigned char* iArray, 
			unsigned int iArraySize);

		~ByteArrayInputSource();

		// Implementation of the CATIXMLPPInputSource interface
		HRESULT Read(
			unsigned char* ioByteArray,
			unsigned int iByteArrayCapacity,
			unsigned int& oSizeRead);
		void Reset(
			unsigned char* iArray, 
			unsigned int iArraySize);
	public:
		unsigned char* _array;
		unsigned int _index;
		unsigned int _size;
};

#endif // ByteArrayInputSource_h

