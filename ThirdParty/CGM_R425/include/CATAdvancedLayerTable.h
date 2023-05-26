/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CATAdvancedLayerTable for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CATAdvancedLayerTable_H
#define CATAdvancedLayerTable_H

#include "SGInfra.h"
#include "CATSysErrorDef.h"
#include "CATAdvancedLayer.h"

#include <map>

class ExportedBySGInfra CATAdvancedLayerTable
{
public:
	// Standard constructors and destructors
	// -------------------------------------
	CATAdvancedLayerTable();
	virtual ~CATAdvancedLayerTable();

	// Copy constructor and equal operator
	// -----------------------------------
	CATAdvancedLayerTable(const CATAdvancedLayerTable&);
	CATAdvancedLayerTable& operator=(const CATAdvancedLayerTable&);

	// Get number of AdvancedLayers
	inline unsigned int GetNumberOfAdvancedLayers() const;

	// Add AdvancedLayer, if already present returns corresponding Index
	inline HRESULT AddAdvancedLayer(const CATAdvancedLayer &iAdvancedLayer, unsigned int &oIndex);

	// Get AdvancedLayer of iIndex (0 to NumAdvancedLayers-1)
	inline HRESULT GetAdvancedLayer(unsigned int iIndex, CATAdvancedLayer& oAdvancedLayer) const;

	// Set (replace) AdvancedLayer at the valid Index (Index < NumberOfAdvancedLayers) otherwise return s_FALSE
	inline HRESULT SetAdvancedLayer(unsigned int iIndex, const CATAdvancedLayer &iAdvancedLayer);

	// Empty AdvancedLayers
	inline void Empty();

private:
	std::map<unsigned int, CATAdvancedLayer> _advancedLayers;
};

//------------------------------------------------------------------------------

// Get number of AdvancedLayers
inline unsigned int CATAdvancedLayerTable::GetNumberOfAdvancedLayers() const
{
	return (unsigned int)_advancedLayers.size();
}

// Add AdvancedLayer, if already present returns corresponding Index
inline HRESULT CATAdvancedLayerTable::AddAdvancedLayer(const CATAdvancedLayer &iAdvancedLayer, unsigned int &oIndex)
{
    // Create a map iterator and point to beginning of map
    std::map<unsigned int, CATAdvancedLayer>::iterator it = _advancedLayers.begin();
    
	// Iterate over the map using Iterator till end.
    while (it != _advancedLayers.end())
    {
        // Accessing KEY from element pointed by it.
        oIndex = it->first;
        // Accessing VALUE from element pointed by it.
        CATAdvancedLayer Layer = it->second;
		if (Layer.IsEqual(iAdvancedLayer))
			return S_OK;
        // Increment the Iterator to point to next entry
        it++;
    }

	oIndex = (unsigned int)_advancedLayers.size();
	_advancedLayers[oIndex] = iAdvancedLayer;
	
	return S_OK;
}

// Get AdvancedLayer of iIndex (0 to NumAdvancedLayers-1)
inline HRESULT CATAdvancedLayerTable::GetAdvancedLayer(unsigned int iIndex, CATAdvancedLayer& oAdvancedLayer) const
{
    // Create a map iterator and point to beginning of map
    std::map<unsigned int, CATAdvancedLayer>::const_iterator it = _advancedLayers.begin();
    
	// Iterate over the map using Iterator till end.
    while (it != _advancedLayers.end())
    {
        // Accessing KEY from element pointed by it.
        if (iIndex == it->first)
		{
			oAdvancedLayer = it->second;
			return S_OK;
		}
        // Increment the Iterator to point to next entry
        it++;
    }
	return E_FAIL;
}

// Set (replace) AdvancedLayer at the valid Index (Index < NumberOfAdvancedLayers) otherwise return s_FALSE
inline HRESULT CATAdvancedLayerTable::SetAdvancedLayer(unsigned int iIndex, const CATAdvancedLayer &iAdvancedLayer)
{
	std::map<unsigned int, CATAdvancedLayer>::const_iterator it;
	it = _advancedLayers.find(iIndex);
	if (it != _advancedLayers.end()) 
	{
		_advancedLayers[it->first] = iAdvancedLayer; 
		return S_OK;
	}
	else
		return S_FALSE;
	return E_FAIL;
}

// Empty AdvancedLayers
inline void CATAdvancedLayerTable::Empty()
{
	_advancedLayers.clear();
}

#endif
