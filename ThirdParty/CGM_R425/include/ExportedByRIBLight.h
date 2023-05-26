/* -*-c++-To ensure dedicated Privilege Access to Topological Operators Implemenation*- */
//------------------------------------------------------------------------------------------------
// Ce Framework est le framework d'implementation d'Operateurs Topologiques V5
//------------------------------------------------------------------------------------------------
#undef ExportedByRIBLight
#ifdef _STATIC_SOURCE
#define	ExportedByRIBLight
  //----------------------------------------------------
  // Sur plateforme NT, Acces controle possible
  //----------------------------------------------------
#elif defined __RIBLight
#define ExportedByRIBLight DSYExport
#else
#define ExportedByRIBLight DSYImport
#endif
#include "DSYExport.h"
//#include "TopologicalOperatorsLightCommonDec.h"

