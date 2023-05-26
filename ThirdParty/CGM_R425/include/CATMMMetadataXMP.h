#ifndef CATMMMETADATAXMP_H
#define CATMMMETADATAXMP_H

#include "CATMMediaPixelImage.h"

#include "CATMMMetadata.h"
#include "CATMMCPropertyType.h"

class CATMMCConstPropertiesPrototype;
class CATMMCProperties;



class ExportedByCATMMediaPixelImage CATMMMetadataXMP : public CATMMMetadata
{
  CATDeclareClass;
public:
  CATMMMetadataXMP(const CATUnicodeString iNamespace, CATMMCConstPropertiesPrototype*ipPrototype);
  virtual ~CATMMMetadataXMP();

  virtual CATUnicodeString GetIdentifier() const          { return GetNamespace(); };
//virtual CATUnicodeString GetDump()       const                                    ;

  CATUnicodeString GetNamespace() const;

  bool SetPrefix(const CATUnicodeString iPrefix);
  CATUnicodeString GetPrefix() const;

  virtual bool GetData(CATUnicodeString iParameter, CATBoolean       &oValue) const ;
  virtual bool GetData(CATUnicodeString iParameter, int              &oValue) const ;
  virtual bool GetData(CATUnicodeString iParameter, unsigned int     &oValue) const ;
  virtual bool GetData(CATUnicodeString iParameter, CATUnicodeString &oValue) const ;

  virtual bool SetData(CATUnicodeString iParameter, CATBoolean        iValue);
  virtual bool SetData(CATUnicodeString iParameter, int               iValue);
  virtual bool SetData(CATUnicodeString iParameter, unsigned int      iValue);
  virtual bool SetData(CATUnicodeString iParameter, CATUnicodeString  iValue);

private:
  CATMMMetadataXMP();
  CATMMMetadataXMP(const CATMMMetadataXMP&);
  CATMMMetadataXMP& operator=(const CATMMMetadataXMP&);

  friend class CATMMMetadataXMPStreaming;
  CATMMCProperties* _properties;
  CATUnicodeString  _namespace;
  CATUnicodeString  _prefix;
};

#endif
