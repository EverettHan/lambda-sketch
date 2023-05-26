/* -*-c++-To ensure dedicated Privilege Access to Topological Operators Implemenation*- */
//------------------------------------------------------------------------------------------------
// Ce Framework est le framework d'implementation d'Operateurs Topologiques V5
//------------------------------------------------------------------------------------------------
#undef ExportedByBOOLight

#ifdef _STATIC_SOURCE
#define	ExportedByBOOLight
  //----------------------------------------------------
  // Sur plateforme NT, Acces controle possible
  //----------------------------------------------------
#elif defined (__BOOLight) 
#define ExportedByBOOLight DSYExport
#else
#define ExportedByBOOLight DSYImport
#endif
#include "DSYExport.h"
//#include "TopologicalOperatorsLightCommonDec.h"

