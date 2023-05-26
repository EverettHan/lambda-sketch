//===================================================================
// COPYRIGHT Dassault Systemes 2015/06/26
//===================================================================
// CATIVolatileGhostable.cpp
// Header definition of class CATIVolatileGhostable
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2016/08/19 Creation:
//===================================================================
#ifndef CATIVolatileGhostable_H
#define CATIVolatileGhostable_H

#include "CATVisItf.h"
#include "CATBaseUnknown.h"

extern ExportedByCATVisItf  IID IID_CATIVolatileGhostable ;

class ExportedByCATVisItf CATIVolatileGhostable: public CATBaseUnknown
{
CATDeclareInterface;

public:
  
public:
	//
	virtual HRESULT Ghost()=0;
	virtual HRESULT UnGhost()=0;

};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIVolatileGhostable, CATBaseUnknown );

#endif
