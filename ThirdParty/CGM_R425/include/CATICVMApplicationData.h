#ifndef CATICVMApplicationData_h
#define CATICVMApplicationData_h


#include "CATBaseUnknown.h"

#include "CATCVMGeoObjects.h"
#include "CATCVMDef.h"

class CATMathStream;
class CATCVMContainer;

extern ExportedByCATCVMGeoObjects IID IID_CATICVMApplicationData;

//#include "CATMathConstant.h"
//#include "CATUnicodeString.h"
//#include "CATMathTransformation.h"

class ExportedByCATCVMGeoObjects CATICVMApplicationData : public CATBaseUnknown
{
public:
	CATDeclareInterface; 

public:
	//-----------------------------------
	// 
	//-----------------------------------
	virtual void	  UnStream (CATMathStream* Str) =0;
    virtual void    Stream   (CATMathStream* CVMStr) =0;
	virtual CATCVMObjectType GetType() =0;

};
//CATDeclareHandler(CATICVMApplicationData, CATBaseUnknown);
#endif

