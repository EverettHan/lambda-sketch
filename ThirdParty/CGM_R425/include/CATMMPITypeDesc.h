/*
*  CATMMPIDesc.h
*
*  Created by o1x on 01/03/2013.
*  Copyright 2013 Dassault Systemes. All rights reserved.
*
*/
#ifndef CATMMPIDesc_H
// COPYRIGHT DASSAULT SYSTEMES 2013
#define CATMMPIDesc_H

#include "CATMMediaPixelImage.h"
#include "CATPixelImage.h"

typedef unsigned char uchar;

using TypeConverter = void(*)(void*, const void*, int);

struct ExportedByCATMMediaPixelImage CATMMPITypeDesc
{
	unsigned char _basetype;     ///< C data type at the heart of our type
	unsigned short _nBits;

	enum BASETYPE { DEFAULT=8,
		UCHAR=8, UINT8=8, UCHAR5=5, UCHAR6=6, UCHAR7=7, SHORT=16, UINT16=17, FLOAT16=18, UINT32=32, FLOAT=33, DOUBLE=64, USER};

	CATMMPITypeDesc(BASETYPE btype, unsigned short  typeSize = DEFAULT);
  CATMMPITypeDesc(CATPixelImageFormat);

	CATMMPITypeDesc() : _basetype(DEFAULT) {}

  inline bool operator==(const CATMMPITypeDesc& iT) const { return _basetype == iT._basetype && _nBits == iT._nBits; };

	int getSize() const;

  void DeduceNBitsFromBasetype(unsigned short);
};


#endif  // CATMMPIDesc_H
