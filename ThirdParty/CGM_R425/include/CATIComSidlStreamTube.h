#ifndef CATIComSidlStreamTube_h
#define CATIComSidlStreamTube_h

#include "CATComSidl.h"
#include "CATBaseUnknown.h"
#include "CATHashDico.h"

class CATIComSidlOutputStream;
class CATIComSidlInputStream;

extern "C" ExportedByCATComSidl const IID IID_CATIComSidlStreamTube ;

class ExportedByCATComSidl CATIComSidlStreamTube :public CATBaseUnknown 
{
	CATDeclareInterface;
public:
	virtual HRESULT SetConnectionParameters( CATHashDico *iParameters ) = 0 ;
	virtual HRESULT GetQueryStream (CATIComSidlOutputStream**oQuery) = 0;
	virtual HRESULT GetAnswerStream (CATIComSidlInputStream**oAnswer) = 0;
};

CATDeclareHandler( CATIComSidlStreamTube , CATBaseUnknown );

HRESULT ExportedByCATComSidl CATComSidlCreateStreamTube(CATHashDico *iConnectionParameters,CATIComSidlStreamTube**oTrs);

#endif
