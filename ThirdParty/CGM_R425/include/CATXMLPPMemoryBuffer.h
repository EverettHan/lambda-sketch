// COPYRIGHT DASSAULT SYSTEMES 2004

#ifndef CATXMLPPMemoryBuffer_h
#define CATXMLPPMemoryBuffer_h

// XMLParser framework
#include "CatXmlItfBase.h"

// System framework
#include "CATBaseUnknown.h"

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * Class to implement a variable size memory buffer to store
 * XML content generated in memory.
 */
class ExportedByCatXmlItfBase CATXMLPPMemoryBuffer: public CATBaseUnknown {
	public:
		/**
		 * Constructor.
		 * @param iCapacity
		 * The initial capacity of the memory buffer.
		 */
		CATXMLPPMemoryBuffer(
			unsigned int iCapacity = 1024);

		/**
		 * Destructor.
		 */
		~CATXMLPPMemoryBuffer();
		/**
		 * Asks the memory buffer to store the supplied byte array.
		 * @param iByteArray.
		 * The byte array.
		 * @param iByteCount
		 * The size of the byte array.
		 */
		HRESULT Write(
			unsigned char* iByteArray,
			unsigned int iByteCount);

		/**
		 * Returns a pointer to the internal byte array of
		 * the memory buffer.
		 * @param oByteArray
		 * The byte array.
		 * @param oByteCount
		 * The size of the byte array.
		 */
		HRESULT GetBuffer(
			unsigned char*& oByteArray,
			unsigned int& oByteCount);

	private:
		unsigned char* _array;
		unsigned int _size;
		unsigned int _capacity;
};

#endif //CATXMLPPMemoryBuffer_h

