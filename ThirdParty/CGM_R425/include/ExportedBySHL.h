/* -*-c++-To ensure dedicated Privilege Access to Topological Operators Implemenation*- */
//------------------------------------------------------------------------------------------------
// Ce Framework est le framework d'implementation d'Operateurs Topologiques V5
//------------------------------------------------------------------------------------------------
#undef ExportedBySHL

#ifdef _STATIC_SOURCE
#define	ExportedBySHL
  //----------------------------------------------------
  // Sur plateforme NT, Acces controle possible
  //----------------------------------------------------
#elif defined __SHL
#define ExportedBySHL DSYExport
#else
#define ExportedBySHL DSYImport
#endif
#include "DSYExport.h"
//#include "TopologicalOperatorsLightCommonDec.h"
