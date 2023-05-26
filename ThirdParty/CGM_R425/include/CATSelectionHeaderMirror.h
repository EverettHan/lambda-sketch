/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CATSelectionHeaderMirror for PickingStyle
// ref. CATAfrSelectionTypeHeader
//
//=============================================================================
// 2022-10-07                                         Creation: TPG
//=============================================================================

#ifndef CATSelectionHeaderMirror_H
#define CATSelectionHeaderMirror_H

#include "CATVisFoundation.h"
#include "CATSysErrorDef.h"

class ExportedByCATVisFoundation CATSelectionHeaderMirror
{
public:
	CATSelectionHeaderMirror();

	// Retrieves a pointer on the CATSelectionHeaderMirror singleton.
	static CATSelectionHeaderMirror* GetInstance();

	inline HRESULT ResetNbChecked();
	inline HRESULT SetNbChecked(const int iNbTypeChecked, const int iNbModeChecked);
	inline HRESULT GetNbChecked(int &oNbTypeChecked, int& oNbModeChecked) const;

private:
	int _nbTypeChecked;
	int _nbModeChecked;
};

inline HRESULT CATSelectionHeaderMirror::ResetNbChecked()
{
	_nbTypeChecked = 0;
	_nbModeChecked = 0;
	return S_OK;
}

inline HRESULT CATSelectionHeaderMirror::SetNbChecked(const int iNbTypeChecked, const int iNbModeChecked)
{
	_nbTypeChecked = iNbTypeChecked;
	_nbModeChecked = iNbModeChecked;
	return S_OK;
}

inline HRESULT CATSelectionHeaderMirror::GetNbChecked(int &oNbTypeChecked, int& oNbModeChecked) const
{
	oNbTypeChecked = _nbTypeChecked;
	oNbModeChecked = _nbModeChecked;
	return S_OK;
}

#endif
