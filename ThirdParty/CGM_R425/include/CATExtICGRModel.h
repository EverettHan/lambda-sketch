#ifndef CATExtI3CGRModel_H
#define CATExtI3CGRModel_H

// COPYRIGHT DASSAULT SYSTEMES 2004

#include "SGInfra.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

class CATRep;
class CATCGRSetting;


/**
 *  Adapter for CATICGRModel interface.
 *
 *  <b>Role</b>: This class provides a default implementation for any extension of interface deriving  
 *  from @href CATICGRModel.
 */  


//===============================================================================================
class ExportedBySGInfra CATExtICGRModel : public CATBaseUnknown
{
   CATDeclareClass;

   public :
     
     CATExtICGRModel();
     ~CATExtICGRModel();

     //CATICGRmodel Adhesion
     CATRep*        BuildCGRRep();
     int            IsFiltered(const CATListOfCATUnicodeString * iApplicativeFilters);
     HRESULT        DestroyCGRRep(CATRep *iCGRRep);
     CATCGRSetting* GetCGRSetting(const CATCGRSetting* iSetting);

};
#endif
