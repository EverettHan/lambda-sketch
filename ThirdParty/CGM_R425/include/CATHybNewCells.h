/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 2005
//------------------------------------------------------------------------------
// CATHybNewCells :
//    List of CATHybNewCell*
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: CATLISTP
//------------------------------------------------------------------------------
//
#ifndef CATHybNewCells_h
#define CATHybNewCells_h

#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"

class CATHybNewCell;

#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy

CATLISTPP_DECLARE_TS(CATHybNewCell, 4)

typedef CATLISTP(CATHybNewCell) CATHybNewCells;

#endif
