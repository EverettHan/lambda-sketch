#ifndef CATComSidlInputStream_h
#define CATComSidlInputStream_h

#include "CATComSidl.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATIComSidlInputStream.h"

class ExportedByCATComSidl CATComSidlInputStream :public CATIComSidlInputStream 
{
protected:
	int _Invalidated;
public:
	CATComSidlInputStream();
	virtual HRESULT ReadDouble(double & Value);
	virtual HRESULT ReadInt(int & Value);
	virtual HRESULT ReadString(CATUnicodeString& oString);
};


#endif

