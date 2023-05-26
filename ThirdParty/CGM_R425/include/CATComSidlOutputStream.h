#ifndef CATComSidlOutputStream_h
#define CATComSidlOutputStream_h

#include "CATComSidl.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATIComSidlOutputStream.h"

class ExportedByCATComSidl CATComSidlOutputStream :public CATIComSidlOutputStream 
{
protected:
	int _Invalidated;
public:
	CATComSidlOutputStream();
	virtual HRESULT WriteDouble(double iNum);
	virtual HRESULT WriteInt(int iNum);
	virtual HRESULT WriteString(const CATUnicodeString & iChar);
};


#endif

