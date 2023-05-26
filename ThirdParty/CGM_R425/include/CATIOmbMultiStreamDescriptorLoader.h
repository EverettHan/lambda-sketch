//===================================================================
// COPYRIGHT Dassault Systemes 2020/06/19
//===================================================================
// CATIOmbMultiStreamDescriptorLoader.cpp
// Header definition of class CATIOmbMultiStreamDescriptorLoader
//===================================================================
//
// Usage notes:
//		This Interface is used to load a multiple LockByte
//		Simultaneously check CATOmbLoaderInfo for more information 
//
//===================================================================
//  2020/06/19 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIOmbMultiStreamDescriptorLoader_H
#define CATIOmbMultiStreamDescriptorLoader_H

#include "CATOmbSwitchEngine.h"
#include "CATBaseUnknown.h"
#include "CATOmxList.h"



#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOmbSwitchEngine  IID IID_CATIOmbMultiStreamDescriptorLoader;
#else
extern "C" const IID IID_CATIOmbMultiStreamDescriptorLoader;
#endif

class CATOmbLoaderInfo;

class ExportedByCATOmbSwitchEngine CATIOmbMultiStreamDescriptorLoader: public CATBaseUnknown
{
CATDeclareInterface;

public:

	virtual HRESULT ParallelConsumeStream(CATOmxList<CATOmbLoaderInfo> & ioCGRLoaderArray) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIOmbMultiStreamDescriptorLoader, CATBaseUnknown );

#endif
