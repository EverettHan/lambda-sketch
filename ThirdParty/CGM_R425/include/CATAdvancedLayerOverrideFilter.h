/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CATAdvancedLayerOverrideFilter for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CATAdvancedLayerOverrideFilter_H
#define CATAdvancedLayerOverrideFilter_H

#include "SGInfra.h"
#include "CATSysErrorDef.h"
#include "CATVisFilter.h"
#include "CATAdvancedLayerOverride.h"

#include <map>

class ExportedBySGInfra CATAdvancedLayerOverrideFilter : public CATVisFilter
{
public:
	// Standard constructors and destructors
	// -------------------------------------
	CATAdvancedLayerOverrideFilter();
	virtual ~CATAdvancedLayerOverrideFilter();

	// Copy constructor and equal operator
	// -----------------------------------
	CATAdvancedLayerOverrideFilter(const CATAdvancedLayerOverrideFilter&);
	CATAdvancedLayerOverrideFilter& operator=(const CATAdvancedLayerOverrideFilter&);

	// Get number of LayerOverrides
	inline unsigned int GetNumberOfLayerOverrides() const;

	// Add LayerOverride, if already present returns corresponding Index
	inline HRESULT AddLayerOverride(const CATAdvancedLayerOverride &iLayerOverride, unsigned int &oIndex);

	// Get LayerOverride of iIndex (0 to NumLayerOverrides-1)
	inline HRESULT GetLayerOverride(unsigned int iIndex, CATAdvancedLayerOverride& oLayerOverride) const;

	// Set (replace) LayerOverride at the valid Index (Index < NumberOfLayerOverrides) otherwise return s_FALSE
	inline HRESULT SetLayerOverride(unsigned int iIndex, const CATAdvancedLayerOverride &iLayerOverride);

	// Empty LayerOverrides
	inline void Empty();

private:
	std::map<unsigned int, CATAdvancedLayerOverride> _layerOverrides;
};

//------------------------------------------------------------------------------

// Get number of LayerOverrides
inline unsigned int CATAdvancedLayerOverrideFilter::GetNumberOfLayerOverrides() const
{
	return (unsigned int)_layerOverrides.size();
}

// Add LayerOverride, if already present returns corresponding Index
inline HRESULT CATAdvancedLayerOverrideFilter::AddLayerOverride(const CATAdvancedLayerOverride &iLayerOverride, unsigned int &oIndex)
{
    // Create a map iterator and point to beginning of map
    std::map<unsigned int, CATAdvancedLayerOverride>::iterator it = _layerOverrides.begin();
    
	// Iterate over the map using Iterator till end.
    while (it != _layerOverrides.end())
    {
        // Accessing KEY from element pointed by it.
        oIndex = it->first;
        // Accessing VALUE from element pointed by it.
        CATAdvancedLayerOverride Layer = it->second;
		if (Layer.IsEqual(iLayerOverride))
			return S_OK;
        // Increment the Iterator to point to next entry
        it++;
    }

	oIndex = (unsigned int)_layerOverrides.size();
	_layerOverrides[oIndex] = iLayerOverride;
	
	return S_OK;
}

// Get LayerOverride of iIndex (0 to NumLayerOverrides-1)
inline HRESULT CATAdvancedLayerOverrideFilter::GetLayerOverride(unsigned int iIndex, CATAdvancedLayerOverride& oLayerOverride) const
{
    // Create a map iterator and point to beginning of map
    std::map<unsigned int, CATAdvancedLayerOverride>::const_iterator it = _layerOverrides.begin();
    
	// Iterate over the map using Iterator till end.
    while (it != _layerOverrides.end())
    {
        // Accessing KEY from element pointed by it.
        if (iIndex == it->first)
		{
			oLayerOverride = it->second;
			return S_OK;
		}
        // Increment the Iterator to point to next entry
        it++;
    }
	return E_FAIL;
}

// Set (replace) LayerOverride at the valid Index (Index < NumberOfLayerOverrides) otherwise return s_FALSE
inline HRESULT CATAdvancedLayerOverrideFilter::SetLayerOverride(unsigned int iIndex, const CATAdvancedLayerOverride &iLayerOverride)
{
	std::map<unsigned int, CATAdvancedLayerOverride>::const_iterator it;
	it = _layerOverrides.find(iIndex);
	if (it != _layerOverrides.end()) 
	{
		_layerOverrides[it->first] = iLayerOverride; 
		return S_OK;
	}
	else
		return S_FALSE;
	return E_FAIL;
}

// Empty LayerOverrides
inline void CATAdvancedLayerOverrideFilter::Empty()
{
	_layerOverrides.clear();
}

#endif
