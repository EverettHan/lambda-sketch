#ifndef CATMMMETADATA_H
#define CATMMMETADATA_H

#include "CATMMediaPixelImage.h"

#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
//#include "CATMMCPropertyType.h"

class CATMMCConstPropertiesPrototype;
//class CATMMCProperties;

class ExportedByCATMMediaPixelImage CATMMMetadata : public CATBaseUnknown
{
  friend class CATMMRasterEngine;
public:
  CATMMMetadata() :CATBaseUnknown() {};
  virtual ~CATMMMetadata() {};

  virtual CATUnicodeString GetIdentifier()                                    const = 0;
//virtual CATUnicodeString GetDump()                                          const = 0;

  virtual bool GetData(CATUnicodeString iParameter, CATBoolean       &oValue) const = 0;
  virtual bool GetData(CATUnicodeString iParameter, int              &oValue) const = 0;
  virtual bool GetData(CATUnicodeString iParameter, unsigned int     &oValue) const = 0;
  virtual bool GetData(CATUnicodeString iParameter, CATUnicodeString &oValue) const = 0;

  virtual bool SetData(CATUnicodeString iParameter, CATBoolean        iValue)       = 0;
  virtual bool SetData(CATUnicodeString iParameter, int               iValue)       = 0;
  virtual bool SetData(CATUnicodeString iParameter, unsigned int      iValue)       = 0;
  virtual bool SetData(CATUnicodeString iParameter, CATUnicodeString  iValue)       = 0;

private:
  virtual bool IsMetadataWrittenAfterFileGeneration()                     { return false; };
  virtual bool WriteMetadataToFile()                                      { return false; };
};

#endif
