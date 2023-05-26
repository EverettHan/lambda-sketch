#ifndef CATComSidlInputStreamCommon_H
#define CATComSidlInputStreamCommon_H
#include "CATComSidl.h"

#include "CATBaseUnknown.h"
#include "CATComSidlInputStream.h"

class ExportedByCATComSidl CATComSidlInputStreamCommon : public CATComSidlInputStream
{
	CATDeclareClass;
	
public :
	CATComSidlInputStreamCommon(const char * iRequest,int iLength);
	virtual HRESULT BeginStream();
	virtual int  GetAvailableBytes();
	virtual HRESULT ReadBinary(char* Buffer, unsigned int Size, unsigned int* oSizeRead = NULL);
	virtual HRESULT EndStream();

private :
  int _Open;
  int _OpenOnce;
	const char*_Buffer;
	int _Pos;
	const char *_Request;
	int _Length;
};

#endif
