//===================================================================
// COPYRIGHT Dassault Systemes 2014/09/29
//===================================================================
// SWXIUtStateListener.cpp
// Header definition of class SWXIUtStateListener
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2014/09/29 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef SWXIUtStateListener_H
#define SWXIUtStateListener_H

#include "SWXUtGeneral.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

class CATUnicodeString;

extern ExportedBySWXUtGeneral  IID IID_SWXIUtStateListener ;

class ExportedBySWXUtGeneral SWXIUtStateListener: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	virtual HRESULT GetStates(CATListOfCATUnicodeString & oStateList) = 0;

	virtual HRESULT HandleStateEnter(const CATUnicodeString & iState) = 0;
	virtual HRESULT HandleStateExit(const CATUnicodeString & iState) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( SWXIUtStateListener, CATBaseUnknown );

#endif
