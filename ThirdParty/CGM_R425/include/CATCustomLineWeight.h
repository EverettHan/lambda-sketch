/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CATCustomLineWeight for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CATCustomLineWeight_H
#define CATCustomLineWeight_H

#include "SGInfra.h"
#include "CATErrorDefs.h"

#include <stdint.h>

class CATJSONObject;
class CATJSONParser;

class ExportedBySGInfra CATCustomLineWeight
{
public:
	// Standard constructors and destructors
	// -------------------------------------
	CATCustomLineWeight();
	virtual ~CATCustomLineWeight();

	// Copy constructor and equal operator
	// -----------------------------------
	CATCustomLineWeight(const CATCustomLineWeight&);
	CATCustomLineWeight& operator=(const CATCustomLineWeight&);

	// IsEqual
	// -----------------------------------
	bool IsEqual(const CATCustomLineWeight&);

	/** Sets the PixelWidth.
	* @param iPixelWidth
	* The PixelWidth index.
	* <b>Legal values</b>: <tt>iPixelWidth</tt>
	*/
	inline void SetPixelWidth(const unsigned short iPixelWidth);

	/** Retrieves the PixelWidth.<br>
	*/
	inline unsigned short GetPixelWidth() const;

	/** Sets the PrintWidth.
	* @param iPrintWidth
	* The PrintWidth index.
	* <b>Legal values</b>: <tt>iPrintWidth</tt>
	*/
	inline void SetPrintWidth(const float iPrintWidth);

	/** Retrieves the PrintWidth.<br>
	*/
	inline float GetPrintWidth() const;

	// Streaming
	// -----------------------------------
	virtual HRESULT Stream(CATJSONObject& iJSONObject, float iVersion);
	virtual HRESULT UnStream(const CATJSONParser& iParser, const uint32_t iKey, float iVersion);

private:
	unsigned short _pixelWidth;   
	float _printWidth;  
};

inline void CATCustomLineWeight::SetPixelWidth(const unsigned short iPixelWidth) {_pixelWidth = iPixelWidth;}

inline unsigned short CATCustomLineWeight::GetPixelWidth() const { return (_pixelWidth); }

inline void CATCustomLineWeight::SetPrintWidth(const float iPrintWidth) {_printWidth = iPrintWidth;}

inline float CATCustomLineWeight::GetPrintWidth() const { return (_printWidth); }

#endif
