#pragma once

#include "CATStdLib.h"
#include "SGInfra.h"

class CATSceneGraphImpl;

class ExportedBySGInfra CATSGTransaction
{
public:


protected:
	// can only be inherited.

	CATSGTransaction();
	CATSGTransaction(CATSceneGraphImpl * iSG);	
	virtual ~CATSGTransaction();
	
		
};
