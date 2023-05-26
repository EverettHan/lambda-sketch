//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// List of CATPolyBVHTreeNodeAttribute
//
//=============================================================================
//  2009-02-04  BPG: New.
//=============================================================================
#ifndef CATPolyBVHTreeNodeAttributeList_H
#define CATPolyBVHTreeNodeAttributeList_H

class CATPolyBVHTreeNodeAttribute;

//
#include "CATLISTP_Clean.h"
#define	CATLISTP_Append
#define	CATLISTP_Locate
#define	CATLISTP_RemoveValue
#define	CATLISTP_RemoveAll
#include "CATLISTP_Declare.h"

//
#include "PolyBVH.h"
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByPolyBVH

//
CATLISTP_DECLARE(CATPolyBVHTreeNodeAttribute);

typedef CATLISTP(CATPolyBVHTreeNodeAttribute) CATPolyBVHTreeNodeAttributeList;

#endif // !CATPolyBVHTreeNodeAttributeList_H
