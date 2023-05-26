#ifndef CATVisContextFilterValue_H
#define CATVisContextFilterValue_H
//
// CATIA Version 5 Release 15 Framework Visualization
// Copyright Dassault Systemes 2004

#include "SGInfra.h"

class CATVisAnnotationValue;

class ExportedBySGInfra CATVisContextFilterValue 
{
public :
	CATVisContextFilterValue(int invisible = 0, int nopick = 0, int lowint = 0);
	CATVisContextFilterValue(const CATVisContextFilterValue& value);
	CATVisContextFilterValue& operator= (const CATVisContextFilterValue& value) ;
	~CATVisContextFilterValue() ;

	inline unsigned int IsNotPickable()       			const; 
	inline unsigned int IsInvisible()         			const;
	inline unsigned int IsLowIntensified()    			const;
	inline unsigned int IsViewModeOverload()  			const;
	inline unsigned int IsViewMeshOverload()  			const;
	inline unsigned int GetViewMesh()         			const;
	inline unsigned int IsViewEdgeOverload()  			const;
	inline unsigned int GetViewEdge()         			const;
	inline unsigned int IsViewLineOverload()  			const;
	inline unsigned int GetViewLine()         			const;
	inline unsigned int IsViewAxisOverload()  			const;
	inline unsigned int GetViewAxis()         			const;
	inline unsigned int IsViewPointOverload() 			const;
	inline unsigned int GetViewPoint()        			const;

	inline unsigned int IsColorOverLoad()				const;	// is the color (rgb) overloaded
	inline unsigned int	GetColorRGBA()					const;	// Get the rgba color. one byte for each channel ( from the left to the right : red/green/blue/alpha )
	inline void			GetColorRGB(							// get rgb color
								unsigned int& oRed, 
								unsigned int& oGreen, 
								unsigned int& oBlue)	const;
	inline unsigned int	IsTransparencyOverload()		const; // is the transparency overloaded 
	inline unsigned int GetTransparency()				const; // get alpha. (0<= alpha 0<= 255)
	

	inline void SetInvisible      			(int iOnOff = 1);
	inline void OverloadViewMesh  			(unsigned int iOnOff);
	inline void OverloadViewEdge  			(unsigned int iOnOff);
	inline void OverloadViewLine  			(unsigned int iOnOff);
	inline void OverloadViewAxis  			(unsigned int iOnOff);
	inline void OverloadViewPoint 			(unsigned int iOnOff);

	/** Cvt a CATVisContextFilterValue to CATVisAnnotationValue */
	CATVisAnnotationValue CvtToAnnotationValue() const;

	/**
	 *	to overload color
	 *	iRed, iGreen and iBlue must have values between 0 and 255 (both included). If the value is more than 255, so the function will use 255 instead.
	 */ 
	inline void OverloadColorRGB			(unsigned int iRed, unsigned int iGreen, unsigned int iBlue); 
	inline void	OverloadTransparency		(const unsigned int iAlpha); // to overload transparency ( 0 <= iAlpha <= 255)

private : 
	unsigned int 	_invisible					: 1 ; 
	unsigned int 	_noPick 					: 1 ;
	unsigned int 	_lowInt 					: 1 ;

	unsigned int 	_overloadViewMesh   		: 1 ;
	unsigned int 	_viewMesh           		: 1 ;
	unsigned int 	_overloadViewEdge   		: 1 ;
	unsigned int 	_viewEdge           		: 1 ;
	unsigned int 	_overloadViewLine   		: 1 ;
	unsigned int 	_viewLine           		: 1 ;
	unsigned int 	_overloadViewAxis   		: 1 ;
	unsigned int 	_viewAxis           		: 1 ;
	unsigned int 	_overloadViewPoint  		: 1 ;
	unsigned int 	_viewPoint          		: 1 ;
	unsigned int	_overloadColor				: 1 ;	
	unsigned int	_overloadTransparency		: 1 ;	

	unsigned int	_padding					: 17 ;
	
	unsigned int	_colorRGBA;					// Color RGBA ( 1 byte for each channels in this order : red / green / blue / alpha )
};


inline unsigned int CATVisContextFilterValue::IsNotPickable() const
{
	return _noPick;
}

inline unsigned int CATVisContextFilterValue::IsInvisible() const
{
	return _invisible;
}

inline unsigned int CATVisContextFilterValue::IsLowIntensified() const
{
	return _lowInt;
}

inline void CATVisContextFilterValue::SetInvisible(int iOnOff)
{
	_invisible = (iOnOff ? 1 : 0);
}

inline unsigned int CATVisContextFilterValue::IsViewModeOverload()  const
{
	return (_overloadViewMesh || _overloadViewEdge || _overloadViewLine || _overloadViewAxis || _overloadViewPoint);
}

inline unsigned int CATVisContextFilterValue::IsViewMeshOverload()  const
{
	return _overloadViewMesh;
}

inline unsigned int CATVisContextFilterValue::GetViewMesh()         const
{
	return _viewMesh;
}

inline unsigned int CATVisContextFilterValue::IsViewEdgeOverload()  const
{
	return _overloadViewEdge;
}

inline unsigned int CATVisContextFilterValue::GetViewEdge()         const
{
	return _viewEdge;
}

inline unsigned int CATVisContextFilterValue::IsViewLineOverload()  const
{
	return _overloadViewLine;
}

inline unsigned int CATVisContextFilterValue::GetViewLine()         const
{
	return _viewLine;
}

inline unsigned int CATVisContextFilterValue::IsViewAxisOverload()  const
{
	return _overloadViewAxis;
}

inline unsigned int CATVisContextFilterValue::GetViewAxis()         const
{
	return _viewAxis;
}

inline unsigned int CATVisContextFilterValue::IsViewPointOverload()  const
{
	return _overloadViewPoint;
}

inline unsigned int CATVisContextFilterValue::GetViewPoint()        const
{
	return _viewPoint;
}

inline unsigned int CATVisContextFilterValue::IsColorOverLoad() const
{
	return _overloadColor;
}


inline unsigned int CATVisContextFilterValue::GetColorRGBA() const
{
	return _colorRGBA;
}

inline void CATVisContextFilterValue::GetColorRGB(unsigned int& oRed, unsigned int& oGreen, unsigned int& oBlue) const
{
	oRed	= (_colorRGBA & 0xff000000) >> 24;
	oGreen	= (_colorRGBA & 0x00ff0000) >> 16;
	oBlue	= (_colorRGBA & 0x0000ff00) >> 8;
}

inline unsigned int CATVisContextFilterValue::IsTransparencyOverload() const
{
	return _overloadTransparency;
}

inline unsigned int CATVisContextFilterValue::GetTransparency() const
{
	return _colorRGBA & 0x000000ff;
}

inline void CATVisContextFilterValue::OverloadViewMesh(unsigned int iOnOff)
{
	_overloadViewMesh = 1;
	_viewMesh = iOnOff;
}

inline void CATVisContextFilterValue::OverloadViewEdge(unsigned int iOnOff)
{
	_overloadViewEdge = 1;
	_viewEdge = iOnOff;
}

inline void CATVisContextFilterValue::OverloadViewLine(unsigned int iOnOff)
{
	_overloadViewLine = 1;
	_viewLine = iOnOff;
}

inline void CATVisContextFilterValue::OverloadViewAxis(unsigned int iOnOff)
{
	_overloadViewAxis = 1;
	_viewAxis = iOnOff;
}

inline void CATVisContextFilterValue::OverloadViewPoint(unsigned int iOnOff)
{
	_overloadViewPoint = 1;
	_viewPoint = iOnOff;
}

inline void CATVisContextFilterValue::OverloadColorRGB( unsigned int iRed, unsigned int iGreen, unsigned int iBlue )
{
	_overloadColor = 1;
	
	unsigned int red	= (iRed > 255)		? 255 : iRed;
	unsigned int green	= (iGreen > 255)	? 255 : iGreen;
	unsigned int blue	= (iBlue > 255)		? 255 : iBlue;
	
	//remove the red green blue channels
	//if the transparency is overloaded we keep the alpha channel
	(0 == _overloadTransparency) ? (_colorRGBA = 0x000000ff) :  (_colorRGBA &= 0x000000ff);

	//color rgb (but don't touch the alpha channel for now)
	_colorRGBA |= ((red << 24) | (green << 16) | (blue << 8));
}

inline void CATVisContextFilterValue::OverloadTransparency(const unsigned int iAlpha)
{
	_overloadTransparency = 1;
	_colorRGBA &= 0xffffff00;
	_colorRGBA |= (iAlpha > 254) ? 0x000000ff : iAlpha;

}
#endif 


