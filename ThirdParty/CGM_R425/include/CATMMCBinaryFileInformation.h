#ifndef CATMMCBINARYFILEINFORMATION_H
#define CATMMCBINARYFILEINFORMATION_H

#include "CATMMediaCore2.h"

#include "CATUnicodeString.h"
#include "CATMMCFile.h"

class ExportedByCATMMediaCore2 CATMMCBinaryFileInformation {
public:
  CATMMCBinaryFileInformation(CATUnicodeString iBinaryFile);
  ~CATMMCBinaryFileInformation();

  bool IsBinary();
  bool IsBinary32bit();
  bool IsBinary64bit();

private:
  CATMMCFile   _binaryFile;
  unsigned int _isbinary;
};

#endif
