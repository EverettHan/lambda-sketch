#ifndef CATOmyInputToOutputStream_h
#define CATOmyInputToOutputStream_h

#include "CATUnicodeString.h"
#include "CATOMYCommunication.h"
#include "CATIComSidlInputStream.h"

class CATIComSidlOutputStream_var;

class ExportedByCATOMYCommunication CATOmyInputToOutputStream
{
public:
  CATOmyInputToOutputStream(CATIComSidlInputStream_var iStream);
  ~CATOmyInputToOutputStream();

 

  HRESULT Extract(CATIComSidlOutputStream_var& iOutputStreamWhereToExtract);

  // S_OK=> still have things to read, E_FAIL=> reach the end
  //HRESULT StillHaveSomethigToRead();

private:
  CATIComSidlInputStream_var _Stream;
};

#endif
