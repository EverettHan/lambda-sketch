#ifndef SWXUtHashedUnicodeString_H
#define SWXUtHashedUnicodeString_H

#include "CATUnicodeString.h"

// Starting the journey of turning this into a class.

class SWXUtHashedUnicodeString : public CATUnicodeString
{
public:
	SWXUtHashedUnicodeString(const CATUnicodeString& iString) : CATUnicodeString(iString)
	{
		mHash = ComputeHashKey();
	}

	struct SWXUtHashedUnicodeStringComparer
	{
		bool operator()(const SWXUtHashedUnicodeString& iLeft, const SWXUtHashedUnicodeString& iRight) const
		{
			if (iLeft.mHash != iRight.mHash)
				return (iLeft.mHash < iRight.mHash) ? true : false;
			else
				return (iLeft < iRight) ? true : false;
		}
	};
protected:
	int mHash;
};

#endif
