/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CATCustomLineType for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CATCustomLineType_H
#define CATCustomLineType_H

#include "SGInfra.h"
#include "CATLinePatternSegment.h"
#include <stdint.h>
#include <vector>

class CATJSONObject;
class CATJSONParser;

class ExportedBySGInfra CATCustomLineType
{
public:
	// Standard constructors and destructors
	// -------------------------------------
	CATCustomLineType();
	virtual ~CATCustomLineType();

	// Copy constructor and equal operator
	// -----------------------------------
	CATCustomLineType(const CATCustomLineType&);
	CATCustomLineType& operator=(const CATCustomLineType&);

	// IsEqual
	// -----------------------------------
	bool IsEqual(const CATCustomLineType&) const;

	// Get number of Segments
	inline unsigned int GetNumberOfSegments() const;

	// Get Segment of iIndex (0 to NumSegments-1)
	inline void GetSegment(unsigned int iIndex, CATLinePatternSegment& oSegment) const;

	// Add Segment
	inline unsigned int AddSegment(const CATLinePatternSegment &iSegment);

	// Insert Segment
	inline unsigned int InsertSegment(const CATLinePatternSegment &iSegment, unsigned int iIndex);

	// Modify Segment
	inline void ModifySegment(unsigned int iIndex, const CATLinePatternSegment& iSegment);

	// Remove Segment
	inline void RemoveSegment(unsigned int iIndex);

	// Empty Segments
	inline void EmptySegments();

	// Streaming
	// -----------------------------------
	virtual HRESULT Stream(CATJSONObject& iJSONObject, float iVersion);
	virtual HRESULT UnStream(const CATJSONParser& iParser, const uint32_t iKey, float iVersion);

private:
	std::vector<CATLinePatternSegment> _LineSegments;
};

//------------------------------------------------------------------------------
// Get number of Segments
inline unsigned int CATCustomLineType::GetNumberOfSegments() const
{
	return (unsigned int)_LineSegments.size();
}

// Get Segment of iIndex (0 to NumSegments-1)
inline void CATCustomLineType::GetSegment(unsigned int iIndex, CATLinePatternSegment& oSegment) const
{
	if (iIndex >= _LineSegments.size()) return;
	oSegment = _LineSegments[iIndex];
}

// Add Segment
inline unsigned int CATCustomLineType::AddSegment(const CATLinePatternSegment &iSegment)
{
	_LineSegments.push_back(iSegment);
	return (unsigned int)_LineSegments.size();
}

// Insert Segment
inline unsigned int CATCustomLineType::InsertSegment(const CATLinePatternSegment &iSegment, unsigned int iIndex)
{
	if (iIndex > _LineSegments.size()) return 0;
	if (iIndex == _LineSegments.size()) // last position
		return AddSegment(iSegment);
	auto it = _LineSegments.begin() + iIndex;
	it=_LineSegments.insert(it, iSegment);
	return (unsigned int)_LineSegments.size();
}

// Modify Segment
inline void CATCustomLineType::ModifySegment(unsigned int iIndex, const CATLinePatternSegment& iSegment)
{
	if (iIndex >= _LineSegments.size()) return;
	_LineSegments[iIndex] = iSegment;
}

// Remove Segment
inline void CATCustomLineType::RemoveSegment(unsigned int iIndex)
{
	if (iIndex >= _LineSegments.size()) return;
	_LineSegments.erase(_LineSegments.begin() + iIndex);
}

// Empty Segments
inline void CATCustomLineType::EmptySegments()
{
	if (_LineSegments.size()==0) return;
	_LineSegments.clear();
}

#endif
