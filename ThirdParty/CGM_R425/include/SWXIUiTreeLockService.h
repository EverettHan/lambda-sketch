//===================================================================
// COPYRIGHT DS SolidWorks Corporation 2012/07/03
//===================================================================
// SWXIUiTreeLockService.cpp
// Header definition of class SWXIUiTreeLockService
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/07/03 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef SWXIUiTreeLockService_H
#define SWXIUiTreeLockService_H

#include "SWXUtGeneral.h"
#include "CATBaseUnknown.h"

extern ExportedBySWXUtGeneral  IID IID_SWXIUiTreeLockService ;

class ExportedBySWXUtGeneral SWXIUiTreeLockService : public CATBaseUnknown
{
	CATDeclareInterface;

	public:

		enum SWXUiTreeLockLevel_e
		{
			LockLevel_Unknown,
			LockLevel_Unlocked,
			LockLevel_PartiallyLocked,
			LockLevel_Locked
		};

	public:

		virtual HRESULT LockTrees( SWXUiTreeLockLevel_e iLockLevel, SWXIUiTreeLockService::SWXUiTreeLockLevel_e& oPrevLockLevel ) = 0;
		virtual HRESULT UnlockTrees( SWXIUiTreeLockService::SWXUiTreeLockLevel_e& oPrevLockLevel ) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( SWXIUiTreeLockService, CATBaseUnknown );

#endif
