//===================================================================
// COPYRIGHT DS SolidWorks 2010/09/16
//===================================================================
// SWXDebugVisu.cpp
// Header definition of class SWXDebugVisu
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/09/16 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef SWXDebugVisu_H
#define SWXDebugVisu_H

#include "SWXDV.h"
#include "SWXUtDataDef.h"

class CATBaseUnknown;
class CATCurve;
class CATMathBox;
class CATMathLine;
class CATMathPoint;
class CATMathVector;
class CATTopology;

//-----------------------------------------------------------------------
class ExportedBySWXDV SWXDebugVisu
{
public:
	// Standard constructors and destructors
	// -----------------------------------
	SWXDebugVisu() {}
	virtual ~SWXDebugVisu();

	static SWXDebugVisu* Get();

	virtual bool Draw(const CATMathPoint *iStPoint, const CATMathPoint *iNdPoint, int iColor) = 0;
	virtual bool Draw(const CATMathPoint *iPoint, int iColor) = 0;
	virtual bool Draw(const CATMathVector *iVector, int iColor) = 0;
	virtual bool Draw(const CATMathLine *iLine, int iColor) = 0;
	virtual bool Draw(const CATMathBox *iBox, int iColor) = 0;
	virtual bool Draw(const CATTopology *iTopo, int iColor) = 0;
	virtual bool Draw(const CATCurve *iCurve, int iColor) = 0;
	virtual bool DrawSkEntity(const CATBaseUnknown *iSkEntity, int iColor) = 0;
	virtual bool DrawDim(CATBaseUnknown *iDim, int iColor) = 0;
	virtual bool Clear(const void *iItem = NULL) = 0;
	virtual bool Zoom(float iZoomFactor) = 0;
	virtual bool ZoomToFit() = 0;
	virtual bool Pan(float iDeltaH, float iDeltaV) = 0;
	virtual bool Rotate(int iAxis) = 0;
	virtual void SetTestViewer(void* iViewer) = 0;

private:
	// Copy constructor and equal operator
	// -----------------------------------
	SWXDebugVisu (SWXDebugVisu &);
	SWXDebugVisu& operator=(SWXDebugVisu&);

	static SWXDebugVisu* mImpl;
};

#endif
