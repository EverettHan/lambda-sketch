//-*-C++-*-

#ifndef CATOmyOutputStreamReplay_h
#define CATOmyOutputStreamReplay_h

#include "CATOMYCommunication.h"
#include "CATIComSidlOutputStream.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

class ExportedByCATOMYCommunication CATOmyOutputStreamReplay : public CATIComSidlOutputStream 
{
  CATDeclareClass;

public:
  CATOmyOutputStreamReplay() ;
  ~CATOmyOutputStreamReplay();

  HRESULT BeginStream();
  HRESULT WriteDouble(double iNum);
  HRESULT WriteInt(int iNum);
  HRESULT WriteString(const CATUnicodeString & iChar);
  HRESULT WriteBinary(const char * iSrc , int iLen);
  HRESULT EndStream();
};
#endif
