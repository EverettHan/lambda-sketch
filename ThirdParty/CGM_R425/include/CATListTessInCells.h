#ifndef CATListTessInCells_h
#define CATListTessInCells_h

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2001
//
// CATListTessInCells : list of CATTessInCell
//
// 
/**
  * Implemented with the framework "Collections"
  */
// Main Methods :
//    - Append()
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Fev. 2001 TPD Mise en place nouvel interface MAILLAGE
//
//=============================================================================

// Name of the class to be listed
class CATTessInCell;

// Clean previous function requests
#include "CATLISTP_Clean.h"

// Defines all the required methods
//#include "CATLISTP_PublicInterface.h"
//#define CATLISTP_RemoveAll
#include  "CATLISTP_PublicInterface.h"

// Get the macros
#include "CATLISTP_Declare.h"

// For Windows NT
#include "TessTopology.h"
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByTessTopology

// Generate interface of collection class 
CATLISTP_DECLARE( CATTessInCell );

// define the Type of the class
typedef CATLISTP(CATTessInCell) CATListTessInCells ;
     
#endif
