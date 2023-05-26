#ifndef ByteArrayOutputSource_h
#define ByteArrayOutputSource_h

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIXMLPPOutputSource.h"

/**
 * Class to implement the CATIXMLPPOutputSource with
 * a variable size memory buffer.
 */
class ExportedByCatXmlItfExt ByteArrayOutputSource: public CATIXMLPPOutputSource {
	CATDeclareClass;
	public:
		/**
		 * Constructor.
		 * @param iCapacity
		 * The initial capacity of the memory buffer.
		 */
		ByteArrayOutputSource(
			unsigned int iCapacity = 1024);

		/**
		 * Destructor.
		 */
		~ByteArrayOutputSource();
		
		// Implementation of the CATIXMLPPOutputSource interface
		HRESULT Write(
			unsigned char* iByteArray,
			unsigned int iByteCount);
		void Reset();
	public:
		unsigned char* _array;
		unsigned int _size;
		unsigned int _capacity;
};

#endif // ByteArrayOutputSource
