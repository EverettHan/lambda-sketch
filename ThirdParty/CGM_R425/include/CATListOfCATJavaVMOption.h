#ifndef	CATListOfCATJavaVMOption_h
#define	CATListOfCATJavaVMOption_h

// COPYRIGHT DASSAULT SYSTEMES 2003

// CATJavaBridge framework
#include "CATJavaVMOption.h"
#include "CATJNIBridge.h"

// To undefine all possible methods of the list of values
#include "CATLISTV_Clean.h" 

// Define the methods supported by the list of values
#define	CATLISTV_Append
#define	CATLISTV_Locate
#define CATLISTV_RemovePosition

#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATJNIBridge
#endif // CATCOLLEC_ExportedBy

// Declare the class CATListValCATJavaVMOption : list of values of class <CATJavaVMOption>
#include "CATLISTV_Declare.h"
CATLISTV_DECLARE(CATJavaVMOption)
typedef CATListValCATJavaVMOption CATListOfCATJavaVMOption;

#endif // CATListOfCATJavaVMOption_h
