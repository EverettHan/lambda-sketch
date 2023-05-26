#ifndef CATBinary_h
#define CATBinary_h

#include <stddef.h>
#include "IUnknown.h"
#include "JS0CTYP.h"

// COPYRIGHT DASSAULT SYSTEMES 2002

class InternalBinary;

/**
 * Class to manipulate a binary blob.
 * It uses InternalBinary class internally to minimize the
 * amount of copying done when passing CATBinaries around.
 * @author: Philippe Leconte (PLE)
 */
class ExportedByJS0CTYP CATBinary{

	public:

		CATBinary();
		CATBinary(const CATBinary& iOther);
		CATBinary(size_t iLength, const signed char* iBuffer);
		CATBinary(size_t iLength, ...);
		~CATBinary();

		int operator == (const CATBinary& iOther) const;
		int operator != (const CATBinary& iOther) const;

		const signed char& operator [] ( size_t iIndex) const;
		signed char& operator [] (size_t iIndex);

		CATBinary& operator = (const CATBinary& iOrigin);

		/**
		 * Returns the length of the binary.
		 */
		size_t getLength() const;

		/**
		 * Returns the internal buffer of the binary.
		 */
		const signed char* getArray() const;

		/**
		 * Concatenates CATBinary instances.
		 * The binary passed as a parameter is appended to the current binary.
		 */
		CATBinary& Append(const CATBinary &iBinary);

		/**
		 * Resize the current binary.
		 * The original buffer will be copied into the new allocated buffer ; the 
		 * contents of the internal buffer will remained unchanged up to the 
		 * lesser of the new and old sizes.
		 * @param iLength
		 * The new length for the internal buffer.
		 * @return
		 * S_OK if the operation succeeded, E_FAIL otherwise.
		 */
		HRESULT Resize(size_t iLength);

		/**
		 * Copy a given buffer in the internal buffer with a specified starting index and size.
		 * @param iBufferSrc
		 * Buffer to copy in the binary.
		 * @param iAt
		 * Position in the binary to start the copy
		 * @param iSize
		 * Size of data to copy.
		 * @return 
		 * Return the number of copied bytes.
		 */
		size_t CopyFromBuffer(const signed char* iBufferSrc, size_t iAt, size_t iSize);
    
		void SetInternal(InternalBinary * iIntern);

	private:
		
		friend class CATBinaryHelper;

		InternalBinary* _intern;
};

#endif // CATBinary_h
