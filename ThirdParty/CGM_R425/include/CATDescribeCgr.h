#ifndef CATDescribeCgr_H
#define CATDescribeCgr_H

//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1997
//******************************************************************************
//  Abstract:
//  ---------
//    This class describes the save caractritics of cgr file : version number
//    and setting .
//
//******************************************************************************
//  Usage:
//  ------
//    Internal Object used by CATWriteCgr & CATReadCgr functions
//
//******************************************************************************
//  Inheritance:
//  ------------
//                CATBaseUnknown (SYSTEM Framework).
//
//******************************************************************************
//  Main Methods:
//  -------------
//    . Set Current version
//    . Set setting use 
//
//******************************************************************************
#include "SGInfra.h"
#include "CATBaseUnknown.h"
#include "CATReadWriteCgr.h"
#include "CATBoolean.h"
#include <atomic>

class CATColorMap;
class CATSGExtendedData;

class ExportedBySGInfra CATDescribeCgr : public CATBaseUnknown
{

	friend class CATMarshallableDescribeCgr;
	friend class CATDmuStreamDescribeCgr;
	CATDeclareClass;

public:

	CATDescribeCgr(const CATSettingCgr &iSetting = USE_LODS_TEXTURE_EDGE);

	virtual ~CATDescribeCgr(void);

	//  Cgr setting Read or Write
	CATSettingCgr GetSetting(void);
	void SetSetting(CATSettingCgr newSetting);

	//  return read version number
	int GetReadVersionNumber(void) const;

	//  return the current version number
	static int GetCurrentVersion(void);
	static void SetCurrentVersion(int iversion, CATBoolean UVR = FALSE);

	static HRESULT IsValidVersion(int iVersion, CATBoolean UVR = FALSE);

	// to manage the GM update
	static int GetUnMarshalGMFull(void);
	static void SetUnMarshalGMFull(const int imode);
	static int GetUnMarshalCurrentVersion(void);
	static void SetUnMarshalCurrentVersion(int iversion, CATBoolean UVR = FALSE);

	//  set and Get map color use to convert indexed color to RGB Composants
	static void SetColorMap(CATColorMap *icolmap);
	static CATColorMap *GetColorMap(void);

	// manage the demo flag
	CATBoolean IsDemoMarked();
	void SetDemoMarked(CATBoolean demoFlag = FALSE);

	//get and set the Show Noshow flag
	static unsigned int GetShowNoshowFlag();
	static void SetShowNoshowFlag(unsigned int showAndNoshow);

	inline CATSGExtendedData* GetSGExtendedData() const { return _SGExtendedData; }

private:
	//  setting 
	CATSettingCgr _Setting;

	// version
	static std::atomic<int> _CurrentVersion;
	static int  _FreezedPhase1Version;
	int _ReadVersionNumber;

	static int _MaxVersion;

	// GM
	static int _UnMarshalGMFull;

	// map color to convert index color to RGB composant before saving Rep
	static CATColorMap *_ColMap;

	// demo flag
	char*   _key;
	unsigned int _keyLength;

	//Show and Noshow flag : 1 -> show and noshow are saved in cgr file
	//                       0 -> only show is saved in cgr file
	static unsigned int _ShowNoshowFlag;

	void  SetDemoKey(unsigned int keyLength, char* key);
	void Crypt(char* chain, unsigned int& long0);
	void Uncrypt(char* chain, unsigned int& long0);

	CATSGExtendedData* _SGExtendedData;
};


#endif
