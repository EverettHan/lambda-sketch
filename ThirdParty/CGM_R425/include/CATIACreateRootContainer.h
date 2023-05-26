/**
 * @level Protected
 * @usage U1
 */
/* -*-c++-*- */

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1997  
//-----------------------------------------------------------------------------
// ObjectModelerCATIA Global Functions
// 
//-----------------------------------------------------------------------------
// Usage Notes:
//
//
// Global functions for general CATElement and CATContainer services
//-----------------------------------------------------------------------------
// Creation by User pjo - February 97
// OGM le 07/04/2003 :
//   En vue du passage en 64 bits, je mets en place les fonctions necessaires
//   pour eviter le passage de int à CATIAModel*
//-----------------------------------------------------------------------------

#ifndef CATIACreateRootContainer_h
#define CATIACreateRootContainer_h

#include "CATOmcBase.h"
#include "CATBaseUnknown.h"
class CATBaseUnknown;
class CATDocument;
class CATUnicodeString;
class CATIAModel ;
class CATIAEntity ;
//

ExportedByCATOmcBase CATBaseUnknown* CATIACreateRootContainer( CATDocument* doc,
                                                               CATClassId   containerType,
                                                               CATClassId   interfaceID,
                                                               CATClassId   containerSuperType = "" ) ;




#endif
