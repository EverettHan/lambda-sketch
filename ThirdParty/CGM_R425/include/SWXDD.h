//===================================================================
// SWXDD.h
//===================================================================
//  2010/09/21 Created by ARN(QNG)
//===================================================================
#include "SWXDV.h"
#include "SWXUtDataDef.h"

//Include this header in modules wherever you want to call DD functions from quick-watch
//Include it once per module (no need to include in each file)
class CATTopology;
class CATCurve;
class CATMathLine;
class CATMathVector;
class CATMathPoint;
class CATMathBox;
class CATBaseUnknown;

//ARN(QNG): Following functions can be called from immediate/quick-watch window from any dll including CATIA/CGM dlls. 
//You need not include this header to call these functions. Type {,,SWXDV} before the function name and pass direct pointer values. Examples:
//
//{,,SWXDV}dp(0x00000000xxxxxx, 1);	//For drawing point
//{,,SWXDV}dv(0x00000000xxxxxx, 1);	//For drawing vertex
//{,,SWXDV}dl(0x00000000xxxxxx, 1);	//For drawing line
//{,,SWXDV}db(0x00000000xxxxxx, 1);	//For drawing box
//{,,SWXDV}dt(0x00000000xxxxxx, 1);	//For drawing topology
//{,,SWXDV}clear(0x00000000xxxxxx);//For clearing item 0x00000000xxxxxx
//{,,SWXDV}zoom(1.4);				//For zoom in/out
//{,,SWXDV}pan(10, 0);				//Pan X,Y
//{,,SWXDV}rot(-2);					//Rotation about -ve sight axis
//



//You need not call these functions directly
ExportedBySWXDV bool SWXDDP(const CATMathPoint* iPoint, int iColor);
ExportedBySWXDV bool SWXDDPS(int iSize, const CATMathPoint** iPoints, int iColor);
ExportedBySWXDV bool SWXDDV(const CATMathVector* iVector, int iColor);
ExportedBySWXDV bool SWXDDL(const CATMathLine* iLine, int iColor);
ExportedBySWXDV bool SWXDDB(const CATMathBox* iBox, int iColor);
ExportedBySWXDV bool SWXDDClear(const void *iItem);
ExportedBySWXDV bool SWXDDT(const CATTopology* iTopo, int iColor);
ExportedBySWXDV bool SWXDDTS(int iSize, const CATTopology** iTopos, int iColor);
ExportedBySWXDV bool SWXDDC(const CATCurve* iCurve, int iColor);
ExportedBySWXDV bool SWXDDSK(const CATBaseUnknown* iSkEnt, int iColor);
ExportedBySWXDV bool SWXDDZoom(float iZoomFactor);
ExportedBySWXDV bool SWXDDPan(float iDeltaH, float iDeltaV);
ExportedBySWXDV bool SWXDDRot(int iAxis);
ExportedBySWXDV bool SWXDDDIM(CATBaseUnknown* iDim, int iColor);


#ifndef __SWXDV

//ARN(QNG): To call the following set of functions from immediate/quick-watch window,
//include this header in any CPP file of your dll
inline bool dp(const CATMathPoint* iPoint, int iColor)
{
	return SWXDDP(iPoint, iColor);
}

inline bool dps(int iSize, const CATMathPoint** iPoints, int iColor)
{
	return SWXDDPS(iSize, iPoints, iColor);
}

inline bool dv(const CATMathVector* iVector, int iColor)
{
	return SWXDDV(iVector, iColor);
}

inline bool dl(const CATMathLine* iLine, int iColor)
{
	return SWXDDL(iLine, iColor);
}

inline bool db(const CATMathBox* iBox, int iColor)
{
	return SWXDDB(iBox, iColor);
}

inline bool dt(const CATTopology* iTopo, int iColor)
{
	return SWXDDT(iTopo, iColor);
}

inline bool dts(int iSize, const CATTopology** iTopos, int iColor)
{
	return SWXDDTS(iSize, iTopos, iColor);
}

inline bool dc(const CATCurve* iCurve, int iColor)
{
	return SWXDDC(iCurve, iColor);
}

inline bool dsk(const CATBaseUnknown* iSkEnt, int iColor)
{
	return SWXDDSK(iSkEnt, iColor);
}

inline bool ddim(CATBaseUnknown* iDim, int iColor)
{
	return SWXDDDIM(iDim, iColor);
}

//Removes iItem from the drawn objects
//iItem = 0 => Clears everything
inline bool clear(const void *iItem) 
{
	return SWXDDClear(iItem);
} 

//iZoomFactor == 0 => Zoom to fit
inline bool zoom(float iZoomFactor)
{
	return SWXDDZoom(iZoomFactor);
}

// iDeltaH => horizontal, iDeltaV => vertical
inline bool pan(float iDeltaH, float iDeltaV)
{
	return SWXDDPan(iDeltaH, iDeltaV);
}

// Valid 'iAxis' inputs +/- 1, 2, 3.
//1=>screen up (vertical) axis;
//2=>sight axis (towards screen)
//3=>screen lateral (horizontal) axis
inline bool rot(int iAxis) 
{
	return SWXDDRot(iAxis);
} 

//ARN(QNG): This function makes sure that above inline functions are not removed by the linker (for optimization)
void SWXDDSymbolKeeper()
{
	dp((CATMathPoint*)0, 0);
	dps(0,(const CATMathPoint**)0, 0);
	dv((CATMathVector*)0, 0);
	dl((CATMathLine*)0, 0);
	db((CATMathBox*)0, 0);
	dt((CATTopology*)0, 0);
	dts(0,(const CATTopology**)0, 0);
	dc((CATCurve*)0, 0);
	dsk((CATBaseUnknown*)0, 0);
	ddim((CATBaseUnknown*)0, 0);
	clear((void*)NULL);
	zoom(1.0f);
	pan(0.0f, 0.0f);
	rot(1);
}
#endif //__SWXDV
