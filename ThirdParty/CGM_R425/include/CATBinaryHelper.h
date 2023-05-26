#ifndef CATBinaryHelper_h
#define CATBinaryHelper_h

#include "JS0CTYP.h"
#include "IUnknown.h"

// COPYRIGHT DASSAULT SYSTEMES 2004

class InternalBinary;
class CATBinary;

/**
 * Class used to manipulate the internal class of CATBinary.
 * This class is reserved for specific use.
 * DO NOT USE IT WITHOUT PERMISSION.
 */
class ExportedByJS0CTYP CATBinaryHelper{

	public:

		/**
		 * Returns the addrefed internal class of the given CATBinary.
		 * The caller must Release it when useless.
		 */
		static InternalBinary * GetInternal(const CATBinary& iBinary);
		
		/**
		 * Release the given InternalBinary.
		 */
		static ULONG Release(InternalBinary * iIntern);

};

#endif // CATBinaryHelper_h
