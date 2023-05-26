//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003                                         
//===========================================================================
//                                                                            
//  CATKnowledgeDynamicLicensing                                               
//                                                                           
//  Usage Notes:                                        
//===========================================================================
//  Creation fevrier  2003                                         	
//===========================================================================
#ifndef __CATKNOWLEDGEDYNAMICLICENSING
#define __CATKNOWLEDGEDYNAMICLICENSING
#include "JS0LIB0.h"
// COPYRIGHT DASSAULT SYSTEMES 2003




typedef int (*FuncPtr)();
/**
* To declare knowlegde function to call when shareable products are updated
*/
class ExportedByJS0LIB0 CATKnowledgeDynamicLicensing
{
	
public :
	CATKnowledgeDynamicLicensing();
	~CATKnowledgeDynamicLicensing();
	
    //To store the function to call
    static void Set (FuncPtr & iFunctionToCall);

    //To get the function to call
    static void Get (FuncPtr & oFunctionToCall);

	
//private:
    static FuncPtr _FunctionToCall;
		
};
#endif


