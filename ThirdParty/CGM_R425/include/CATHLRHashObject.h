#ifndef CATHLRHashObject_H
#define CATHLRHashObject_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
//
// CATHLRHashObject : hash table made to associate each jele to a geometric
// object
//
// DESCRIPTION :
// 
// Main Methods : IMPLEMENTED WITH COLLECTIONS
//  
//=============================================================================
// Abstract Class     : No
// Template Code      : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Aug. 97   Jose CHILLAN (jch)    Creation            
//
//=============================================================================

// For Windows NT
#include "HLRModele.h"

// Include the class on which the hash table will be built
#include "CATHLRObject.h"

// Clean up the definitions
#include "CATHTAB_Clean.h"

// Define the needed methods
#define CATHTAB_Insert
#define CATHTAB_KeyLocate
#define CATHTAB_ApplyDelete
#define CATHTAB_KeyLocatePosition
#define CATHTAB_Next

// For debug
#define CATHTAB_PrintStats
#define CATHTAB_PrintAddr

// Include the macro
#include "CATHTAB_Declare.h"

#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByHLRModele

CATHTAB_DECLARE( CATHLRObject )

// Defines the type
 typedef CATHTAB( CATHLRObject ) CATHLRHashObject;


#endif

