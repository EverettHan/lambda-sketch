//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2013/01/11
//===================================================================
// SWXIUtDimFeatureRef.cpp
// Header definition of class SWXIUtDimFeatureRef
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/01/11 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef SWXIUtDimFeatureRef_H
#define SWXIUtDimFeatureRef_H

#include "SWXUtGeneral.h"
#include "CATBaseUnknown.h"


extern ExportedBySWXUtGeneral  IID IID_SWXIUtDimFeatureRef ;


class ExportedBySWXUtGeneral SWXIUtDimFeatureRef: public CATBaseUnknown
{
CATDeclareInterface;

public:

//
// TODO: Add your methods for this interface here.
//
	virtual HRESULT SetFeature(const CATBaseUnknown_var& iFeat) = 0;
	virtual HRESULT SetFeatRefId(int iFeatRefId) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( SWXIUtDimFeatureRef, CATBaseUnknown );

#endif
