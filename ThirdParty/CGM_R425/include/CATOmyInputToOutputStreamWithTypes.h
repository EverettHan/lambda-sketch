#ifndef CATOmyInputToOutputStreamWithTypes_h
#define CATOmyInputToOutputStreamWithTypes_h

#include "CATUnicodeString.h"
#include "CATOMYCommunication.h"
#include "CATIComSidlInputStream.h"
#include "CATOmyEndianSafeStreamWithTypes.h" //datatypes

class CATIComSidlOutputStream_var;

class ExportedByCATOMYCommunication CATOmyInputToOutputStreamWithTypes
{
public:
  CATOmyInputToOutputStreamWithTypes(CATIComSidlInputStream_var iStream);
  ~CATOmyInputToOutputStreamWithTypes();

 

  HRESULT Extract(CATIComSidlOutputStream_var iOutputStreamWhereToExtract);

  // S_OK=> still have things to read, E_FAIL=> reach the end
  //HRESULT StillHaveSomethigToRead();

private:
  CATIComSidlInputStream_var _Stream;
  HRESULT _ReadDataType();
  HRESULT _ReadString (CATUnicodeString &oString );
  HRESULT _ReadInt(int &oNum);
  HRESULT _ReadEndian();
  HRESULT _ReadBinary (char*  Value, unsigned int  size, unsigned int*  oSizeRead) ;
  HRESULT _ReadBinaryLength();
  HRESULT _ReadDouble(double &oNum);

  CATOmyEndianSafeStreamDataType _CurrentType;
  CATLONG32 _BinaryDataLeftToRead;

};

#endif
