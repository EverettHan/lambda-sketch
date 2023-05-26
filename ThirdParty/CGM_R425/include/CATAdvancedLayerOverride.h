/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CATAdvancedLayerOverride for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CATAdvancedLayerOverride_H
#define CATAdvancedLayerOverride_H

#include "SGInfra.h"
#include "CATAdvancedLayer.h"

class ExportedBySGInfra CATAdvancedLayerOverride
{
public:
	// Standard constructors and destructors
	// -------------------------------------
	CATAdvancedLayerOverride();
	virtual ~CATAdvancedLayerOverride();

	// Copy constructor and equal operator
	// -----------------------------------
	CATAdvancedLayerOverride(const CATAdvancedLayerOverride&);
	CATAdvancedLayerOverride& operator=(const CATAdvancedLayerOverride&);

	// IsEqual
	// -----------------------------------
	bool IsEqual(const CATAdvancedLayerOverride&);

	/** Sets the LayerNumber.
	* @param iLayerNumber
	* The LayerNumber index.
	* <b>Legal values</b>: <tt>iLayerNumber</tt> range from 1 to 100.
	*/
	inline void SetLayerNumber(const unsigned int iLayerNumber);

	/** Retrieves the LayerNumber.<br>
	*/
	inline unsigned int GetLayerNumber() const;

	/** Sets the AdvancedLayerOverride.
	* @param iAdvancedLayerOverride
	* The AdvancedLayerOverride.
	* <b>Legal values</b>: <tt>iAdvancedLayerOverride</tt>
	*/
	inline void SetAdvancedLayerOverride(const CATAdvancedLayer &iAdvancedLayerOverride);

	/** Retrieves the AdvancedLayerOverride.<br>
	*/
	inline CATAdvancedLayer& GetAdvancedLayerOverride();

private:
	unsigned int _layerNumber;
	CATAdvancedLayer _override;

};

inline void CATAdvancedLayerOverride::SetLayerNumber (const unsigned int iLayerNumber) { _layerNumber = iLayerNumber; }

inline unsigned int CATAdvancedLayerOverride::GetLayerNumber() const { return _layerNumber; }

inline void CATAdvancedLayerOverride::SetAdvancedLayerOverride(const CATAdvancedLayer &iAdvancedLayerOverride) {_override = iAdvancedLayerOverride;}

inline CATAdvancedLayer& CATAdvancedLayerOverride::GetAdvancedLayerOverride() { return (_override); }

#endif
