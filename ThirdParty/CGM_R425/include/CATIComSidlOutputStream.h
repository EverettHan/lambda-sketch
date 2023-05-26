#ifndef CATIComSidlOutputStream_h
#define CATIComSidlOutputStream_h

#include "CATComSidl.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"


extern "C" ExportedByCATComSidl const IID IID_CATIComSidlOutputStream ;

class ExportedByCATComSidl CATIComSidlOutputStream :public CATBaseUnknown 
{
	CATDeclareInterface;
public:
	virtual HRESULT BeginStream()=0;
	virtual HRESULT WriteDouble(double iNum)=0;
	virtual HRESULT WriteInt(int iNum)=0;
	virtual HRESULT WriteString(const CATUnicodeString & iChar)=0;
	virtual HRESULT WriteBinary(const char * iSrc , int iLen)=0;
	virtual HRESULT EndStream()=0;
};

CATDeclareHandler( CATIComSidlOutputStream , CATBaseUnknown );

#endif

