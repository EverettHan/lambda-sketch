/**
@file

Native CPP to v8 conversion and v8 to native CPP conversion

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/

#ifndef __CATStreamHelpers_h
#define __CATStreamHelpers_h

//ES
#include "ESKernelLib.h"
#include "ESWorld.h"

//CAT
#include "DSYString.h"

	/**
	* Read a ECMA / Javascript file
	* Set the optional iNoCoverage to true if you don't want the file to be preprocessed for coverage
	* If you don't know what this means, don't use the argument, the default value is the good value
	*/
	ESKERNEL_API 
	bool CATReadTextStream (const CATUnicodeString& iPath, CATUnicodeString& oFile, bool NoCoverage=false);

#endif



