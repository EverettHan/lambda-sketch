/*
 * @fullReview LAI JBT 02:02:15
 */
#ifndef CATLicenseWorkbenchStatus_H
#define CATLicenseWorkbenchStatus_H
// COPYRIGHT DASSAULT SYSTEMES 2002

// - Dialog ne connait que les Workbenchs charges.
// - CATLM connait la liste des licences qui autorisent un Workbench.
//
// En fonction des modifications DYN du licensing, il est possible de dire
// si un Workbench peut etre POTENTIELLEMENT impacte par une modif DYN de licensing.

#include "LicensingFR.h"  // exportedby

class CATTrace;

class ExportedByLicensingFR CATLicenseWorkbenchStatus
{
   public:

   enum LicModStatus
   {
      NoImpact = 0,
      Impact
   };

   static LicModStatus GetStatus ( const char * ilicname, const char * & owname );
   static int UnMake ();
   
   private:
   CATLicenseWorkbenchStatus ();
   ~CATLicenseWorkbenchStatus ();

   void Dump ( );
 
   static CATLicenseWorkbenchStatus * _anchor;
   static CATTrace *                  _t;
   static char ***                    _handle;

};
#endif
