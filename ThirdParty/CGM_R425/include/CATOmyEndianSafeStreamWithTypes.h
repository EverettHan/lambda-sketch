#ifndef CATOmyEndianSafeStreamWithTypes_h
#define CATOmyEndianSafeStreamWithTypes_h

#include "CATOmsStreamHelper.h"
#include "CATUnicodeString.h"
#include "CATOMYCommunication.h"
#include "CATOmxSR.h"
#include "CATOmyStreamHandler.h"

class CATStream;
class CATIComSidlOutputStream;

enum CATOmyEndianSafeStreamDataType{
  unknownData=0,
  doubleData=1,
  intData=2,
  stringData=3,
  binaryData=4,
  endData=5
};

class ExportedByCATOMYCommunication CATOmyEndianSafeStreamWithTypes
{
public:
  CATOmyEndianSafeStreamWithTypes(CATOmyStreamHandler * iStream);
  ~CATOmyEndianSafeStreamWithTypes();

  HRESULT WriteEndian();
  HRESULT ReadEndian();

  HRESULT WriteDouble(double iNum);
  HRESULT ReadDouble(double &oNum);

  HRESULT WriteInt(int iNum);
  HRESULT ReadInt(int &oNum);

  HRESULT WriteString (const CATUnicodeString &iString );
  HRESULT ReadString (CATUnicodeString &oString );

  HRESULT WriteBinary (const char *  iSrc   , int  iLen);
  HRESULT ReadBinary (char*  Value, unsigned int  size, unsigned int*  oSizeRead) ;

  HRESULT Extract(CATIComSidlOutputStream * iOutputStreamWhereToExtract);

  // S_OK=> still have things to read, E_FAIL=> reach the end
  HRESULT StillHaveSomethigToRead();

private:
  CATOmxSR<CATOmyStreamHandler> _handler;
  CATOmsStreamHelper _StreamHelper;
  CATLONG32 _BinaryDataLeftToRead;
  CATOmyEndianSafeStreamDataType _CurrentType;
  CATBoolean _WriteMode, _lastTypeWasABinary;

  HRESULT _ReadDouble(double &oNum);
  HRESULT _ReadInt(int &oNum);
  HRESULT _ReadString (CATUnicodeString &oString );
  HRESULT _ReadBinary (char*  Value, unsigned int  size, unsigned int*  oSizeRead) ;
  HRESULT _ReadBinaryLength();

  HRESULT _WriteDataType(CATOmyEndianSafeStreamDataType iType);
  HRESULT _ReadDataType();
  HRESULT _CheckDataType(CATOmyEndianSafeStreamDataType iExpectedType);
};

#endif
