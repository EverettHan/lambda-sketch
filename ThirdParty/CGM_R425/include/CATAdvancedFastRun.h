#ifndef CATAdvancedFastRun_H_
#define CATAdvancedFastRun_H_

// Operateur Fast Update Black Box pour Scnenarios 1 et 2.

#include "BODYNOPE.h"
#include "CATBasicFastRun.h"

class CATBody;
class CATContextForFastRun;

class ExportedByBODYNOPE CATAdvancedFastRun : public CATBasicFastRun
{
  CATCGMVirtualDeclareClass(CATAdvancedFastRun);
public : 
  CATAdvancedFastRun( CATGeoFactory*     iContainer,
                   CATTopData*        iData,
                   CATExtTopOperator* iExtensible = NULL);
  ~CATAdvancedFastRun();

private :
  int  RunOperator();
  

};

/**
 * @return [out, delete]
 */
ExportedByBODYNOPE CATAdvancedFastRun* CATCreateAdvancedFastRun (CATGeoFactory * ipContainer, CATTopData * ipData, CATError ** iopError );
ExportedByBODYNOPE CATAdvancedFastRun* CATCreateAdvancedFastRun (CATGeoFactory * ipContainer, CATTopData * ipData, CATContextForFastRun * ipContext, CATError ** iopError);

#endif
