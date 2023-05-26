#ifndef PLMSidlError_H
#define PLMSidlError_H

#include "CATComSidl.h"

#include "CATBaseUnknown.h"
#include "CATInternalError.h"
#include "CATErrorDefs.h"


class ExportedByCATComSidl PLMSidlError : public CATInternalError
{
public :
	CATDeclareError(PLMSidlError, CATInternalError)
};


#endif
