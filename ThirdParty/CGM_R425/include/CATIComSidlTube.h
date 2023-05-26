#ifndef CATIComSidlTube_h
#define CATIComSidlTube_h

#include "CATComSidl.h"
#include "CATBaseUnknown.h"
#include "CATHashDico.h"

extern "C" ExportedByCATComSidl const IID IID_CATIComSidlTube ;

class ExportedByCATComSidl CATIComSidlTube :public CATBaseUnknown 
{
	CATDeclareInterface;
public:
	virtual HRESULT SetConnectionParameters( CATHashDico *iParameters ) = 0 ;
	virtual HRESULT Transmit( const char * iData , int  iSize , char *& oData , int & oSize ) = 0 ;
	virtual HRESULT Clean() = 0 ;
};

CATDeclareHandler( CATIComSidlTube , CATBaseUnknown );

HRESULT ExportedByCATComSidl CATComSidlCreateTube(CATHashDico *iConnectionParameters,CATIComSidlTube**oTrs);

#endif



