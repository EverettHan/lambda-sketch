#ifndef CATLicenseDynamicDispatcher_H
#define CATLicenseDynamicDispatcher_H

// COPYRIGHT DASSAULT SYSTEMES 2002

//#include "LicensingFR.h"  // ExportedBy
#include "JS0LIB.h"          // ExportedBy
#include "CATErrorExit.h"    // CATCallOnExit

//#include "CATBaseUnknown.h"

#include "CATDataExtendable.h"
#include "CATCallbackManager.h"

//class ExportedByLicensingFR CATLicenseDynamicDispatcher : public CATBaseUnknown 
//class ExportedByLicensingFR CATLicenseDynamicDispatcher : public CATDataExtendable
class ExportedByJS0LIB CATLicenseDynamicDispatcher : public CATDataExtendable
{
   public :
   CATDeclareClass;
   CATLicenseDynamicDispatcher ();
   ~CATLicenseDynamicDispatcher ();
   static CATLicenseDynamicDispatcher * Get ();
   static int Unmake ( int rc );

   private : 
   static CATLicenseDynamicDispatcher * _anchor;
   static int _ExitDone;
   static int DoExit ( int rc );
};



#endif
