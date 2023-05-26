/* -*-c++-To ensure dedicated Privilege Access to Topological Operators Implemenation*- */
//------------------------------------------------------------------------------------------------
// Ce Framework est le framework d'implementation d'Operateurs Topologiques V5
//------------------------------------------------------------------------------------------------
#undef ExportedByFIL

#ifdef _STATIC_SOURCE
#define	ExportedByFIL
  //-----------------------------------------------------
  // Sur plateforme NT, Acces controle possible
  //----------------------------------------------------
#elif defined __FIL
#define ExportedByFIL DSYExport
#else
#define ExportedByFIL DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"

