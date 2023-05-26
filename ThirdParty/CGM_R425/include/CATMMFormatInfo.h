/*
 *  CATMMFormatInfo.h
 *
 *  Created by azx on 21/02/2011.
 *  Copyright 2011 Dassault Systemes. All rights reserved.
 *
 */
#ifndef CATMMFormatInfo_H
#define CATMMFormatInfo_H

#include "CATMMRasterEngineDef.h"
// System
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

class CATPixelImage;

/*
* 
*/

class ExportedByCATMMediaPixelImage CATMMFormatInfo : public CATBaseUnknown
{
  CATDeclareClass;

public:

  CATMMFormatInfo( CATMMImageFormat type, CATMMImageCompression comp, CATMMImageBPP rBPP, CATMMImageBPP wBPP);
  CATMMFormatInfo( const CATMMFormatInfo& toCopy);
  CATMMFormatInfo& operator=( const CATMMFormatInfo& toCopy);

  virtual ~CATMMFormatInfo();
  virtual CATMMFormatInfo* Duplicate() { return new CATMMFormatInfo(*this); };

  static HRESULT GetDescAndExt(CATMMImageFormat iFormat, CATUnicodeString &oDesc, CATUnicodeString &oExt1, CATUnicodeString &oExt2);
  static HRESULT GetCompDesc(CATMMImageCompression iComp, CATUnicodeString &oDesc);

  inline CATMMImageFormat GetFormat() const { return _type; };
  inline CATMMImageCompression GetCompression() const { return _comp;};
  inline CATUnicodeString GetDescription() const { return _desc;};
  inline CATUnicodeString GetExtension1() const { return _ext1;};
  inline CATUnicodeString GetExtension2() const { return _ext2;};
  inline CATMMImageBPP GetReadBPP() const { return _rBPP;};
  inline CATMMImageBPP GetWriteBPP() const { return _wBPP;};

private: 

  CATMMImageFormat _type;
  CATMMImageCompression _comp;
  CATMMImageBPP _rBPP;
  CATMMImageBPP _wBPP;
  CATUnicodeString _desc, _ext1, _ext2;

};

// declare list class CATListPtrCATMMFormatInfo
#include "CATLISTP_Clean.h"
#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_RemoveAll
#include "CATLISTP_Declare.h"
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATMMediaPixelImage
CATLISTP_DECLARE(CATMMFormatInfo);
#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy



#endif  // CATMMFormatInfo_H
