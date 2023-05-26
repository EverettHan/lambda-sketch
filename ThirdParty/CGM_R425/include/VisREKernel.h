//COPYRIGHT DASSAULT SYSTEMES 2011

/**
@file		  VisREKernel.h
@author		j6h
@brief    Definition of ExportedByVisREKernel
*/

#if defined(__VisREKernel)
#define ExportedByVisREKernel DSYExport
#else
#define ExportedByVisREKernel DSYImport
#endif
#include "DSYExport.h"
