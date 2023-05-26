#ifndef CreateTopOpDevelop_H 
#define CreateTopOpDevelop_H 

// COPYRIGHT DASSAULT SYSTEMES  1999
 

#include "BODYNOPE.h"
#include <stdlib.h>
//
class CATTopDevelop;
class CATGeoFactory;
class CATGeometry;
class CATBody;
class CATCGMJournalList;
class CATTopData;
class CATICGMSurTo2DGlobalMapping;
class CATSurTo2DGlobalMapping;

/** 
* @nodoc
* Use CATCreateTopDevelop (CATTopDevelop.h)
*/
ExportedByBODYNOPE
CATTopDevelop * CreateTopOpDevelop(CATGeoFactory           *iFactory,
                                   CATBody                 *iWire,        
                                   CATBody                 *iWireSupport,
                                   CATBody                 *iTargetSupport,
                                   CATSurTo2DGlobalMapping *iMappingIn,
                                   CATSurTo2DGlobalMapping *iMappingOut,
                                   CATTopData              *iData);
/** 
* @nodoc
* Use CATCreateTopDevelop (CATTopDevelop.h)
*/
ExportedByBODYNOPE
CATTopDevelop * CreateTopOpDevelop(CATGeoFactory           *iFactory,
                                   CATBody                 *iWire,        
                                   CATBody                 *iWireSupport,
                                   CATBody                 *iTargetSupport,
                                   CATICGMSurTo2DGlobalMapping *iIMappingIn,
                                   CATICGMSurTo2DGlobalMapping *iIMappingOut,
                                   CATTopData              *iData);

/** 
* @nodoc
* Use CATCreateTopDevelop (CATTopDevelop.h)
*/
ExportedByBODYNOPE
CATTopDevelop * CreateTopOpDevelop(CATGeoFactory           *iFactory,
                                   CATBody                 *iWire,        
                                   CATBody                 *iWireSupport,
                                   CATBody                 *iTargetSupport,
                                   CATSurTo2DGlobalMapping *iMappingIn,
                                   CATSurTo2DGlobalMapping *iMappingOut,
                                   CATCGMJournalList       *iReport = NULL);

/** 
* @nodoc
* Use CATCreateTopDevelop (CATTopDevelop.h)
*/
ExportedByBODYNOPE
CATTopDevelop * CreateTopOpDevelop(CATGeoFactory           *iFactory,
                                   CATBody                 *iWire,        
                                   CATBody                 *iWireSupport,
                                   CATBody                 *iTargetSupport,
                                   CATICGMSurTo2DGlobalMapping *iIMappingIn,
                                   CATICGMSurTo2DGlobalMapping *iIMappingOut,
                                   CATCGMJournalList       *iReport = NULL);
//
#endif


