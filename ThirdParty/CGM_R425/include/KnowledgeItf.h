// COPYRIGHT DASSAULT SYSTEMES 2000
/** @CAA2Required */
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

// load dedicated to Dictionnary customisation
#ifdef __KnowledgeItf

#define ExportedByKnowledgeItf DSYExport
#else
#define ExportedByKnowledgeItf DSYImport
#endif
#include "DSYExport.h"
