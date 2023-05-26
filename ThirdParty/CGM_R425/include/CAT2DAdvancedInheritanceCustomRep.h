/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CAT2DAdvancedInheritanceCustomRep for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CAT2DAdvancedInheritanceCustomRep_H
#define CAT2DAdvancedInheritanceCustomRep_H

#include "SGInfra.h"
#include "CAT2DCustomRep.h"
#include "CAT2DAdvancedInheritanceBagRep.h"

class ExportedBySGInfra CAT2DAdvancedInheritanceCustomRep : public CAT2DCustomRep
{
	CATDeclareClass;

public:

	// creation of a CAT2DAdvancedInheritanceCustomRep 
	static CAT2DAdvancedInheritanceCustomRep* CreateRep();

	virtual ~CAT2DAdvancedInheritanceCustomRep();

	/** Sets the InheritanceMode.
	* @param iInheritanceMode
	*/
	inline void SetInheritanceMode(const unsigned char iInheritanceMode) {_lineTypeAndInheritance._inheritanceMode = iInheritanceMode;}

	/** Retrieves the InheritanceMode.<br>
	*/
	inline unsigned char GetInheritanceMode() const {return _lineTypeAndInheritance._inheritanceMode;}

	/** Sets the LineType.
	* @param iLineType
	*/
	inline void SetLineType(const unsigned int iLineType) {_lineTypeAndInheritance._lineType = iLineType;}

	/** Retrieves the LineType.<br>
	*/
	inline unsigned int GetLineType() const {return _lineTypeAndInheritance._lineType;}

	/** Sets the LineWeight.
	* @param iLineWeight
	*/
	inline void SetLineWeight(const unsigned int iLineWeight) {_lineTypeAndInheritance._lineWeight = iLineWeight;}

	/** Retrieves the LineWeight.<br>
	*/
	inline unsigned int GetLineWeight() const {return _lineTypeAndInheritance._lineWeight;}

	/** Sets the LineTypeScale.
	* @param iLineTypeScale
	*/
	inline void SetLineTypeScale(const float iLineTypeScale) {_lineTypeAndInheritance._lineTypeScale = iLineTypeScale;}

	/** Retrieves the LineTypeScale.<br>
	*/
	inline float GetLineTypeScale() const {return _lineTypeAndInheritance._lineTypeScale;}

protected:
	CAT2DAdvancedInheritanceCustomRep();

private:
	LineTypeAndInheritance _lineTypeAndInheritance;
};

#endif


