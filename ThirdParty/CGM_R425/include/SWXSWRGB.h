#ifndef SWXSWRGB_H
#define SWXSWRGB_H

#include "CATDataType.h"

struct SWXSWRGB
{
#ifdef _ENDIAN_LITTLE
	unsigned mRed    : 8;
	unsigned mGreen  : 8;
	unsigned mBlue   : 8;
	unsigned mUnused : 8;
#else
	unsigned mUnused : 8;
	unsigned mBlue   : 8;
	unsigned mGreen  : 8;
	unsigned mRed    : 8;
#endif
};

#endif
