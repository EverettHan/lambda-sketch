// COPYRIGHT DASSAULT SYSTEMES 2000

//LME
//Error class for interfaces applications ( handlers ... )

#ifndef __CATBaseError
#define __CATBaseError

#include "JS0CORBA.h"
#include "CATErrors.h"

typedef enum {
		OleNullHandler = 0x00020001u
	     } OleErrors;

class ExportedByJS0CORBA CATBaseError : public CATInternalError
{
   public :
      CATDeclareErrorClass(CATBaseError,CATInternalError)
};


#endif
