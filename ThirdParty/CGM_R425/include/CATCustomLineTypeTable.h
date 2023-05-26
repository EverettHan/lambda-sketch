/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CATCustomLineTypeTable for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CATCustomLineTypeTable_H
#define CATCustomLineTypeTable_H

#include "SGInfra.h"
#include "CATCustomLineType.h"
#include "CATUnicodeString.h"
#include <map>

class ExportedBySGInfra CATCustomLineTypeTable
{
public:
	// Standard constructors and destructors
	// -------------------------------------
	CATCustomLineTypeTable();
	virtual ~CATCustomLineTypeTable();

	// Copy constructor and equal operator
	// -----------------------------------
	CATCustomLineTypeTable(const CATCustomLineTypeTable&);
	CATCustomLineTypeTable& operator=(const CATCustomLineTypeTable&);

	// IsEqual
	// -----------------------------------
	bool IsEqual(const CATCustomLineTypeTable&) const;

	// Get number of CustomLineTypes
	inline unsigned int GetNumberOfCustomLineTypes() const;

	// Add CustomLineType, if already present returns corresponding Index
	inline HRESULT AddCustomLineType(const CATCustomLineType &iCustomLineType, unsigned int &oIndex);

	// Get CustomLineType of iIndex (0 to NumCustomLineTypes-1)
	inline HRESULT GetCustomLineType(unsigned int iIndex, CATCustomLineType& oCustomLineType) const;

	// Set (replace) CustomLineType at the valid Index (Index < NumberOfCustomLineTypes) otherwise return s_FALSE
	inline HRESULT SetCustomLineType(unsigned int iIndex, const CATCustomLineType &iCustomLineType);

	// Empty CustomLineTypes
	inline void Empty();

	// Streaming
	// -----------------------------------
	virtual HRESULT Stream(CATUnicodeString &oSerialization);
	virtual HRESULT UnStream(const char* iJson, float& oVersion);

private:
	std::map<unsigned int, CATCustomLineType> _CustomLineTypes;
	static float s_Version;
};

//------------------------------------------------------------------------------
// Get number of CustomLineTypes
inline unsigned int CATCustomLineTypeTable::GetNumberOfCustomLineTypes() const
{
	return (unsigned int)_CustomLineTypes.size();
}

// Add CustomLineType, if already present returns corresponding Index
inline HRESULT CATCustomLineTypeTable::AddCustomLineType(const CATCustomLineType &iCustomLineType, unsigned int &oIndex)
{
    // Create a map iterator and point to beginning of map
    std::map<unsigned int, CATCustomLineType>::iterator it = _CustomLineTypes.begin();
    
	// Iterate over the map using Iterator till end.
    while (it != _CustomLineTypes.end())
    {
        // Accessing KEY from element pointed by it.
        oIndex = it->first;
        // Accessing VALUE from element pointed by it.
        CATCustomLineType CustomLineType = it->second;
		if (CustomLineType.IsEqual(iCustomLineType))
			return S_OK;
        // Increment the Iterator to point to next entry
        it++;
    }

	oIndex = (unsigned int)_CustomLineTypes.size();
	_CustomLineTypes[oIndex] = iCustomLineType;
	
	return S_OK;
}

// Get CustomLineType of iIndex (0 to NumCustomLineTypes-1)
inline HRESULT CATCustomLineTypeTable::GetCustomLineType(unsigned int iIndex, CATCustomLineType& oCustomLineType) const
{
    // Create a map iterator and point to beginning of map
    std::map<unsigned int, CATCustomLineType>::const_iterator it = _CustomLineTypes.begin();
    
	// Iterate over the map using Iterator till end.
    while (it != _CustomLineTypes.end())
    {
        // Accessing KEY from element pointed by it.
        if (iIndex == it->first)
		{
			oCustomLineType = it->second;
			return S_OK;
		}
        // Increment the Iterator to point to next entry
        it++;
    }
	return E_FAIL;
}

// Set (replace) CustomLineType at the valid Index (Index < NumberOfCustomLineTypes) otherwise return s_FALSE
inline HRESULT CATCustomLineTypeTable::SetCustomLineType(unsigned int iIndex, const CATCustomLineType &iCustomLineType)
{
	std::map<unsigned int, CATCustomLineType>::const_iterator it;
	it = _CustomLineTypes.find(iIndex);
	if (it != _CustomLineTypes.end()) 
	{
		_CustomLineTypes[it->first] = iCustomLineType; 
		return S_OK;
	}
	else
		return S_FALSE;
	return E_FAIL;
}

// Empty CustomLineTypes
inline void CATCustomLineTypeTable::Empty()
{
	_CustomLineTypes.clear();
}
#endif
