#ifndef CATIComSidlInputStream_h
#define CATIComSidlInputStream_h

#include "CATComSidl.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATComSidlErrorDef.h"


extern "C" ExportedByCATComSidl const IID IID_CATIComSidlInputStream ;

class ExportedByCATComSidl CATIComSidlInputStream :public CATBaseUnknown 
{
	CATDeclareInterface;
public:
	virtual HRESULT BeginStream()=0;
	virtual int  GetAvailableBytes()=0;
	virtual HRESULT ReadDouble(double & Value)=0;
	virtual HRESULT ReadInt(int & Value)=0;
	virtual HRESULT ReadString(CATUnicodeString& oString)=0;
	virtual HRESULT ReadBinary(char* Value, unsigned int size, unsigned int* oSizeRead = NULL)=0;
	virtual HRESULT EndStream()=0;
};

CATDeclareHandler( CATIComSidlInputStream , CATBaseUnknown );

#endif

