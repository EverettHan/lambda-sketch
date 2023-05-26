#pragma once

#include <map>
#include <string>

#include "CATUnicodeString.h"
#include "CATStdLib.h"
#include "SGInfra.h"

class CATRep;
class CATSceneGraphImpl;
class CATSceneGraphIndexImpl;

/**
The index is basically an ID -> Rep map. It helps to reference reps from an applicative context
*/
class ExportedBySGInfra CATSceneGraphIndex
{
public:
	
	/**
	Clears the index
	*/
	HRESULT			Clear();

	/**
	Remove a rep from the index
	*/
	HRESULT			RemoveRep(const CATUnicodeString &p_ID);

	/**
	Retrieves a rep from its index entry
	*/
	CATRep *			GetRep(const CATUnicodeString &p_ID);

	/**
	Adds a rep to the index, with a given identifier	
	*/
	HRESULT			AddRepToIndex(CATRep * p_Rep, const CATUnicodeString &p_ID);

	/**
	Returns the index entry of the given rep
	*/
	HRESULT			GetRepID(const CATRep * iRep, CATUnicodeString &p_IndexID) const;	

	/**
	Retrieves the number of elements in the index
	*/
	CATULONG32		GetIndexSize() const;

	/**
	Retrieve a rep from its position in the index.
	*/
	CATRep *			GetIndexedRep(CATULONG32 iPos) const;


	/** @nodoc */
	CATSceneGraphIndexImpl * GetImpl() const;

private:	

	// private ctor/dtor: can be instanciated only by CATSceneGraphImpl
	CATSceneGraphIndex();
	CATSceneGraphIndex(CATSceneGraphImpl * iSG);
	virtual ~CATSceneGraphIndex();
	CATSceneGraphIndex(const CATSceneGraphIndex &);
	friend class CATSceneGraphImpl;

	CATSceneGraphIndexImpl * _Impl;
};
