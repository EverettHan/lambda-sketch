#ifndef CATComSidlError_H
#define CATComSidlError_H

#include "CATComSidl.h"

#include "CATBaseUnknown.h"
#include "CATInternalError.h"
#include "CATErrorDefs.h"


class ExportedByCATComSidl CATComSidlError : public CATInternalError
{
public :
	CATDeclareError(CATComSidlError, CATInternalError)
};


#endif
