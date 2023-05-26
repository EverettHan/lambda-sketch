/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2022
//============================================================================
//
// CAT2DAdvancedInheritanceBagRep for ACAD Data model
//
//=============================================================================
// 2022-07-22                                         Creation: TPG
//=============================================================================

#ifndef CAT2DAdvancedInheritanceBagRep_H
#define CAT2DAdvancedInheritanceBagRep_H

#include "SGInfra.h"
#include "CAT2DBagRep.h"

enum LayerAndLineTypeInheritanceMode
{
	CATLineWeightByLayer   = (1u << 7),
	CATLineWeightByBlock   = (1u << 6),
	CATColorByLayer        = (1u << 5),
	CATColorByBlock        = (1u << 4),
	CATLineTypeByLayer     = (1u << 3),
	CATLineTypeByBlock     = (1u << 2),
	CATTransparencyByLayer = (1u << 1),
	CATTransparencyByBlock = (1u)
};

struct LineTypeAndInheritance
{
	unsigned char  _inheritanceMode;
	unsigned short _lineType; 
	unsigned short _lineWeight:8;
	float          _lineTypeScale;
};

class ExportedBySGInfra CAT2DAdvancedInheritanceBagRep : public CAT2DBagRep
{
	CATDeclareClass;

public:

	// creation of a CAT2DAdvancedInheritanceBagRep that can carry certains LineTypeAndInheritance
	// which will be applied to all its children
	static CAT2DAdvancedInheritanceBagRep* CreateRep();

	virtual ~CAT2DAdvancedInheritanceBagRep();

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

	// AZX: (A2X migration) This rep is not derived thus making draw functions final 
	virtual void DrawShading(CATRender& ioRender, int iInside) override final;
	virtual void DrawPath(CATRender& ioRender, int iInside, CATRepPath& ioPath) override final;
	virtual void Draw(CATRender& iRender, int iInside) override final;
	virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

protected:
	CAT2DAdvancedInheritanceBagRep();

private:
	LineTypeAndInheritance _lineTypeAndInheritance;
};

#endif


