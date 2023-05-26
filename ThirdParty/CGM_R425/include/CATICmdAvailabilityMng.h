#ifndef CATICmdAvailabilityMng_H
#define CATICmdAvailabilityMng_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrItf.h"
//===========================================================================
// Interface for command Availability
//===========================================================================
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATICmdAvailabilityMng;
#else
extern "C" const IID IID_CATICmdAvailabilityMng;
#endif
class  ExportedByCATAfrItf CATICmdAvailabilityMng : public CATBaseUnknown
{
   CATDeclareInterface;

   public:
	   virtual int IsAvailable(CATBaseUnknown* obj, const char* HeaderID)=0;
}; 

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler(CATICmdAvailabilityMng, CATBaseUnknown);

#endif
