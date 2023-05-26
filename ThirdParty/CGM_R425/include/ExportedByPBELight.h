/* -*-c++-To ensure dedicated Privilege Access to Topological Operators Implemenation*- */
//------------------------------------------------------------------------------------------------
// Ce Framework est le framework d'implementation d'Operateurs Topologiques V5
//------------------------------------------------------------------------------------------------
#undef ExportedByPBELight
#ifdef _STATIC_SOURCE
#define	ExportedByPBELight
  //----------------------------------------------------
  // Sur plateforme NT, Acces controle possible
  //----------------------------------------------------
#elif defined __PBELight
#define ExportedByPBELight DSYExport
#else
#define ExportedByPBELight DSYImport
#endif
#include "DSYExport.h"
//#include "TopologicalOperatorsLightCommonDec.h"

