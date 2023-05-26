#ifndef __CATWORKBENCHUP
#define __CATWORKBENCHUP
// COPYRIGHT DASSAULT SYSTEMES 2000
//-----------------------------------------------------------------------------
// Abstract:	__CATWORKBENCHUP
//-----------------------------------------------------------------------------
//

#define _NEW_BMW_R201 1

#include "CATWorkbenchUpE.h" // exportation
#include "CATListOfCATUnicodeString.h"

ExportedByCATWorkbenchUpE void CATWorkbenchUp();
//=================================================================
class ExportedByCATWorkbenchUpE CATIsCATWorkbenchUp
{
   public:
   CATIsCATWorkbenchUp  ( ); 
   ~CATIsCATWorkbenchUp ( );


#ifdef _NEW_BMW_R201
   static CATListOfCATUnicodeString * _l6GrantedByShareable;
#endif
   static int _IsConfig ;
};
#endif
