// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATBuildPlateDeformImp
// 
// Execution de Throw CNext avec des syntaxes CAS.CADE
//
//
//=============================================================================
// Jul. 01 Creation                                          PMG
//=============================================================================
#ifndef CATStandard_Error_H
#define CATStandard_Error_H

#include "SysCascade.h"
#include "CATBoolean.h"

//  Ca ne compile plus !

//#define CATStandard_DomainError CATStandard_Error
//#define CATStandard_MultiplyDefined CATStandard_Error
//#define CATStandard_NoSuchObject CATStandard_Error

class CATStandard_Error 
{
	public :
	ExportedBySysCascade  static  void Raise(const char * = "") ;
//	ExportedBySysCascade  static  void Raise_if(const CATBoolean testRaise, const char* = "");
	private :
	 static  void Throw();
};

#endif
