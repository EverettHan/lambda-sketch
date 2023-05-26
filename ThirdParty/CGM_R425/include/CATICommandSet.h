#ifndef __CATICommandSet_h
#define __CATICommandSet_h

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATString.h"
#include "CATCommandSet.h"

extern ExportedByCATAfrFoundation IID IID_CATICommandSet;

class ExportedByCATAfrFoundation CATICommandSet : public CATBaseUnknown {
	
  CATDeclareInterface;
  
public:
 
	virtual HRESULT EnumTopics    (
		CATListOfCATString     & ioTopics
		) = 0;
	
	virtual HRESULT GetCommandSet (
		const CATString  &  iTopic,
		CATCommandSet    ** oSet
		) = 0;
	
};

CATDeclareHandler (CATICommandSet, CATBaseUnknown);

#endif
