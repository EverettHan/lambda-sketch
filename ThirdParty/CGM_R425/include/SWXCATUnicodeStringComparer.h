#pragma once

#include "CATUnicodeString.h"

struct SWXCATUnicodeStringComparer
{	
	bool operator()(const CATUnicodeString & iLeft, const CATUnicodeString & iRight) const
	{
		return (iLeft < iRight) ? true : false;
	}
};
