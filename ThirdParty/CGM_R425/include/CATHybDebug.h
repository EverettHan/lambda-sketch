/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
//      
// CATHybDebug : used to Debug Hybrid Operators
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATHybDebug_h
#define CATHybDebug_h

#include "HybOper.h"

//------------------------------------------------------------------------------

class ExportedByHybOper CATHybDebug
{
public:

   CATHybDebug(); 
   virtual ~CATHybDebug();
   
   // debug general
   short GetHybridDump();
   short GetBodyOrientation();
   short GetCheckJournal();

   
   // debug pour Assemble operator
   short GetAssembleDump();
   short GetAssembleBoundaryMode();
   
   // debug pour Project operator
   short GetProjectPosageMode();
   short GetProjectCellInput();
   short GetProjectGeometricalInput();
   short GetProjectGeometricalError();
   short GetProjectRelimitInput();
   short GetProjectRelimitError();
   short GetProjectAssemblyInput();
   short GetProjectAssemblyError();
   
   // debug pour Intersect operator
   short GetIntersectCellInput();
   short GetIntersectGeometricalInput();
   short GetIntersectGeometricalError();
   short GetIntersectRelimitInput();
   short GetIntersectRelimitError();
   short GetIntersectAssemblyInput();
   short GetIntersectAssemblyError();
   
   // debug pour Boolean operator
   short GetBooleanDisconnectError();

};
#endif










