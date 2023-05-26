#ifndef CATMMMETADATAXMPSTREAMING_H
#define CATMMMETADATAXMPSTREAMING_H

#include "CATMMediaPixelImage.h"
#include "CATUnicodeString.h"

class CATMMMetadataXMP;
class CATMMediaXMPItf;

class ExportedByCATMMediaPixelImage CATMMMetadataXMPStreaming
{
public:
  CATMMMetadataXMPStreaming();
  ~CATMMMetadataXMPStreaming();
  
  int  OpenFile(const CATUnicodeString  iFilepath, bool ibRequestWritable=false);
  bool ReadXMP (CATMMMetadataXMP *&opMetadata, const char* iNamespace);
  bool WriteXMP(const CATMMMetadataXMP *ipMetadata);

  CATUnicodeString DumpXMP();

  CATUnicodeString _errors;
private:
  CATMMediaXMPItf *_xmp;
  bool _writtenMeta;

};

#endif
