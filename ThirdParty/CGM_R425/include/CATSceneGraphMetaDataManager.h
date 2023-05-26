#pragma once

#include <map>
#include <vector>
#include "CATUnicodeString.h"
#include "SGInfra.h"

class CATRep;
class CATSceneGraphImpl;
class CATSceneGraphMetaDataManagerImpl;

class ExportedBySGInfra CATSceneGraphMetaDataManager
{
public:

	HRESULT		Clear();
	CATBoolean	HasData(CATRep * p_Rep, const CATUnicodeString &p_Name) const;
	HRESULT		SetData(CATRep * p_Rep, const CATUnicodeString &p_Name, const CATUnicodeString &p_Value);
	HRESULT		GetData(CATRep * p_Rep, const CATUnicodeString &p_Name, CATUnicodeString &p_Value) const;
	HRESULT		GetData(CATRep * p_Rep, CATULONG32 iPos, CATUnicodeString &oName, CATUnicodeString &oValue) const;
	CATULONG32	GetDataCount(CATRep * p_Rep) const;
	CATULONG32	GetElementsCount() const;
	CATRep *		GetElement(CATULONG32 iPos) const;

	/** @nodoc */
	CATSceneGraphMetaDataManagerImpl * GetImpl() const;

	/**
	Simple "select" operation. Returns the list of reps where the metadata p_Attname has been set to p_Value	
	*/
	HRESULT SimpleSelect(std::vector<CATRep *> & p_DestList, const CATUnicodeString &p_Attname, const CATUnicodeString &p_Value) const;
private:
	// can only be instanciated by CATSceneGraphImpl
	CATSceneGraphMetaDataManager();
	CATSceneGraphMetaDataManager(CATSceneGraphImpl * iSG);
	virtual ~CATSceneGraphMetaDataManager();
	friend class CATSceneGraphImpl;

	CATSceneGraphMetaDataManagerImpl * _Impl;

	
};
