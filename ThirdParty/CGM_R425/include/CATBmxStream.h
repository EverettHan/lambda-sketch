#ifndef __CATBmxStream_H
#define __CATBmxStream_H

#include "CATOmxKernel.h"
#include "CATOmxArray.h"
#include "CATOmxOMap.h"
#include "CATOmxPortability.h"
class CATWOmxBinaryStream;
class CATOsmStream;

/**
 * CATSpecNewStream legacy CXR1 "marxian" int/string streaming.
 * Use it only for compatibility purposes.
 * If you need to stream something, please use instead directly CATWOmxBinaryStream.
 * Do not try to understand format, it is beyond human understanding,
 * we just guarantee that it will never change.
 */
class ExportedByCATOmxKernel CATBmxStream
{
  friend class CATOsmStream;
  CATOmxArray<CATUnicodeString> _stringlist;
  int _dicoSize;
  CATOmxOMap<CATUnicodeString,int> _dico;
public:
  enum Checker
  {
    CATIntegGeneric = 128,
    CATIntegEco = CATIntegGeneric + 1,//129
    CATIntegSemiEco = CATIntegEco + 80 ,//209
    CATBin = CATIntegSemiEco + 20,//229
    CATNoValue = 254
  };

  enum StrChecker
  {
    CATStrLength , // = 0
    CATStrIndex = CATStrLength + 50,
    CATNoValueBis = CATNoValue
  };

  CATBmxStream();
  ~CATBmxStream();

  void    WriteInt(CATWOmxBinaryStream& Cout,int iValue,int iType = CATIntegGeneric, int iRange1 = CATIntegSemiEco - CATIntegGeneric, int iRange2 = CATBin - CATIntegSemiEco);
  HRESULT ReadInt(CATWOmxBinaryStream& Cin,int& oValue,int iRefChecker = CATIntegGeneric,int iRange1 = CATIntegSemiEco - CATIntegGeneric, int iRange2 = CATBin - CATIntegSemiEco);
  int     WriteString(CATWOmxBinaryStream& Cout, const CATUnicodeString& iStr);
  HRESULT ReadString(CATWOmxBinaryStream& Cin,CATUnicodeString& oStr);
  int     WriteCUS(CATWOmxBinaryStream& Cout,const CATUnicodeString& iString);
  HRESULT ReadCUS (CATWOmxBinaryStream& Cin,      CATUnicodeString& oString,int& oStringSize);
private:
  CATBmxStream(const CATBmxStream& );
  CATBmxStream& operator=(const CATBmxStream& );
};

#endif
