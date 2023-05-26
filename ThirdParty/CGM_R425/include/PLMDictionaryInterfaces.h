// COPYRIGHT DASSAULT SYSTEMES 2011
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

// load dedicated to Dictionnary customisation
#if defined(__PLMDictionaryInterfaces)
#define ExportedByPLMDictionaryInterfaces DSYExport
#else
#define ExportedByPLMDictionaryInterfaces DSYImport
#endif
#include "DSYExport.h"
