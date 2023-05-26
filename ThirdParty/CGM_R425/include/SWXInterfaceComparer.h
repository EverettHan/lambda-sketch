#pragma once

#include "CATBaseUnknown.h"

struct SWXInterfaceComparer
{
	bool operator()(const CATBaseUnknown_var & iLeft, const CATBaseUnknown_var & iRight) const
	{
		CATBaseUnknown * lKey = (NULL_var == iLeft) ? NULL : iLeft->GetImpl();

		if(lKey && lKey->IsEqual(iRight))
			return false;

		CATBaseUnknown * rKey = (NULL_var == iRight) ? NULL : iRight->GetImpl();
		return lKey < rKey;
	}
};
