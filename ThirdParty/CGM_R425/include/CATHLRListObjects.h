#ifndef CATHLRLISTOBJECTS_H
#define CATHLRLISTOBJECTS_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
//
// CATHLRListObjects :
//
// DESCRIPTION :
// 
/** List of CATHLRObject. Implemented with the framework "Collections"
 */
// Main Methods :
//    - Append()
//    - Destroy()
//=============================================================================
// Abstract Class     : No
// Template Code      : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 98      Creation              Jose CHILLAN (jch)
//
//=============================================================================

#include "HLRModele.h"

// Name of the class to be listed
class CATHLRObject;

// Clean previous function requests
#include <CATLISTP_Clean.h>

// Define all the required methods
//#define CATLISTP_Append
//#define CATLISTP_ReSize
//#define CATLISTP_RemoveAll
#include  "CATLISTP_PublicInterface.h"

// Get the macros
#include <CATLISTP_Declare.h>

// Generate interface of collection class
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByHLRModele
CATLISTP_DECLARE( CATHLRObject )

// define the Type of the class
//  typedef CATLISTP(CATHLRObject) CATHLRListObject ;
#define CATHLRListObjects CATLISTP(CATHLRObject)   

#endif
