//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// List of CATPolyBVHTreeNodeImpl
//
//=============================================================================
//  2009-02-04  JXO: New.
//=============================================================================
#ifndef CATPolyBVHTreeNodeImplList_H
#define CATPolyBVHTreeNodeImplList_H

class CATPolyBVHTreeNodeImpl;

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
CATLISTP_DECLARE(CATPolyBVHTreeNodeImpl);

typedef CATLISTP(CATPolyBVHTreeNodeImpl) CATPolyBVHTreeNodeImplList;

#endif // !CATPolyBVHTreeNodeImpl_H
