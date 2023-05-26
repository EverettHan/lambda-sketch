/**
 * @level Protected
 * @usage U1
 */
#ifndef GetCATIAEntity_H
#define GetCATIAEntity_H
//===============================================
// COPYRIGHT DASSAULT SYSTEMES  1997
//===============================================
#include "AC0CATPL.h"

class CATIAEntity ;
class CATBaseUnknown ;

ExportedByAC0CATPL CATIAEntity* GetCATIAEntity( const CATBaseUnknown* impl ) ;

#endif
