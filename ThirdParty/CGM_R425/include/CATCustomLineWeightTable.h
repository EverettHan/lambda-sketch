/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CATCustomLineWeightTable for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CATCustomLineWeightTable_H
#define CATCustomLineWeightTable_H

#include "SGInfra.h"
#include "CATSysErrorDef.h"
#include "CATCustomLineWeight.h"
#include "CATUnicodeString.h"

#include <map>

class ExportedBySGInfra CATCustomLineWeightTable
{
public:
	// Standard constructors and destructors
	// -------------------------------------
	CATCustomLineWeightTable();
	virtual ~CATCustomLineWeightTable();

	// Copy constructor and equal operator
	// -----------------------------------
	CATCustomLineWeightTable(const CATCustomLineWeightTable&);
	CATCustomLineWeightTable& operator=(const CATCustomLineWeightTable&);

	// IsEqual
	// -----------------------------------
	bool IsEqual(const CATCustomLineWeightTable&) const;

	// Get number of CustomLineWeights
	inline unsigned int GetNumberOfCustomLineWeights() const;

	// Add CustomLineWeight, if already present returns corresponding Index
	inline HRESULT AddCustomLineWeight(const CATCustomLineWeight &iCustomLineWeight, unsigned int &oIndex);

	// Get CustomLineWeight of iIndex (0 to NumCustomLineWeights-1)
	inline HRESULT GetCustomLineWeight(unsigned int iIndex, CATCustomLineWeight& oCustomLineWeight) const;

	// Set (replace) CustomLineWeight at the valid Index (Index < NumberOfCustomLineWeights) otherwise return s_FALSE
	inline HRESULT SetCustomLineWeight(unsigned int iIndex, const CATCustomLineWeight &iCustomLineWeight);

	// Empty CustomLineWeights
	inline void Empty();

	// Streaming
	// -----------------------------------
	virtual HRESULT Stream(CATUnicodeString &oSerialization);
	virtual HRESULT UnStream(const char* iJson, float& oVersion);

private:
	std::map<unsigned int, CATCustomLineWeight> _customLineWeights;
	static float s_Version;
};

//------------------------------------------------------------------------------

// Get number of CustomLineWeights
inline unsigned int CATCustomLineWeightTable::GetNumberOfCustomLineWeights() const
{
	return (unsigned int)_customLineWeights.size();
}

// Add CustomLineWeight, if already present returns corresponding Index
inline HRESULT CATCustomLineWeightTable::AddCustomLineWeight(const CATCustomLineWeight &iCustomLineWeight, unsigned int &oIndex)
{
    // Create a map iterator and point to beginning of map
    std::map<unsigned int, CATCustomLineWeight>::iterator it = _customLineWeights.begin();
    
	// Iterate over the map using Iterator till end.
    while (it != _customLineWeights.end())
    {
        // Accessing KEY from element pointed by it.
        oIndex = it->first;
        // Accessing VALUE from element pointed by it.
        CATCustomLineWeight Layer = it->second;
		if (Layer.IsEqual(iCustomLineWeight))
			return S_OK;
        // Increment the Iterator to point to next entry
        it++;
    }

	oIndex = (unsigned int)_customLineWeights.size();
	_customLineWeights[oIndex] = iCustomLineWeight;
	
	return S_OK;
}

// Get CustomLineWeight of iIndex (0 to NumCustomLineWeights-1)
inline HRESULT CATCustomLineWeightTable::GetCustomLineWeight(unsigned int iIndex, CATCustomLineWeight& oCustomLineWeight) const
{
    // Create a map iterator and point to beginning of map
    std::map<unsigned int, CATCustomLineWeight>::const_iterator it = _customLineWeights.begin();
    
	// Iterate over the map using Iterator till end.
    while (it != _customLineWeights.end())
    {
        // Accessing KEY from element pointed by it.
        if (iIndex == it->first)
		{
			oCustomLineWeight = it->second;
			return S_OK;
		}
        // Increment the Iterator to point to next entry
        it++;
    }
	return E_FAIL;
}

// Set (replace) CustomLineWeight at the valid Index (Index < NumberOfCustomLineWeights) otherwise return s_FALSE
inline HRESULT CATCustomLineWeightTable::SetCustomLineWeight(unsigned int iIndex, const CATCustomLineWeight &iCustomLineWeight)
{
	std::map<unsigned int, CATCustomLineWeight>::const_iterator it;
	it = _customLineWeights.find(iIndex);
	if (it != _customLineWeights.end()) 
	{
		_customLineWeights[it->first] = iCustomLineWeight; 
		return S_OK;
	}
	else
		return S_FALSE;
	return E_FAIL;
}

// Empty CustomLineWeights
inline void CATCustomLineWeightTable::Empty()
{
	_customLineWeights.clear();
}

#endif
