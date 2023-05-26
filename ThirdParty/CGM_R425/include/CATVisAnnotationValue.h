#ifndef CATVisAnnotationValue_H
#define CATVisAnnotationValue_H

//--- cat fw ---//
#include "CATDataType.h"

//--- visu fw ---//
#include "SGInfra.h"
#include "CATVisAnnotationTypeAndDef.h"
#include "CATMaterialApplication.h"
#include <memory>

class CATGraphicMaterial;

/** 
 *	An instance of this class contains filtering data for a specific CATPathElement added in a CATVisAnnotation.
 */	
class ExportedBySGInfra CATVisAnnotationValue
{
public:
	
	//+++ CTR / DTR
	/** @nodoc */
	CATVisAnnotationValue();
	/** @nodoc */
	CATVisAnnotationValue(const CATVisAnnotationValue& iValue);
	/** @nodoc */
	~CATVisAnnotationValue();
	//--- CTR / DTR
	
	//+++ operators
	
	/** @nodoc */
	inline  CATVisAnnotationValue&	operator = (const CATVisAnnotationValue& iValue);
	/** @nodoc */
	inline	CATINT32				operator == (const CATVisAnnotationValue& iValue) const;

	//--- operators

	//+++ Overload properties

	/** To overload a property of a path element */
	inline void			OverloadProperty(const fAnnProp iFlag);

	/** To disable an overload */
	inline void			DisableOverloadedProperty(const fAnnProp iFlag);

	/** To test if a property is overloaded
	 *	Returns 0 if the given property is overloaded.
	 *	Returns another unsigned integer otherwise
	 */
	inline CATUINT32	IsPropertyOverloaded(const fAnnProp iFlag)		const;	

	//--- Overload properties


	//+++ Property values
	
	/** To set a color or/and a transparency
	 *	Color (red green blue) and transparency (alpha) are stored in the same unsigned integer of 4 bytes in this exact order : red / green / blue / alpha (whatever the OS or the platform). (From the left to the right)
	 *	The four components (red green blue alpha) could have values between 0 and 255 (both included).
	 *	if iFlag == fValueRGB -> the last byte of iValue is ignored.
	 *	if iFlag == fValueAlpha -> the first three bytes of iValue are ignored.
	 *	if iFlag == fValueAllRGBA -> the all four bytes are used.
	 *	
	 *	Example : for red = 0x000000aa, green = 40, blue = 0x000000cc -> SetPropertyValue(fValueRGB, 0xaabbcc00).
	 *	For alpha = 0x000000dd -> SetPropertyValue(fValueAlpha, 0x000000dd).
	 *	And you can use both -> SetPropertyValue(fValueAllRGBA, 0xaabbccdd).
	 *
	 * @note: If you need Low lighting -> You can use 0x42665400 color value. This value is in fact the color of the lowLight. (Actually, LowLight is only a predetermined color. 
	 *	You can find it in initColor.h file, and access to it thanks to CATColorMap.h
	 */
	inline void 		SetPropertyValue(const fAnnValueRGBA iFlag, const CATUINT32 iValue);

	/** To activate or deactivate an option of the view mode
	 *	iOnOff == 0 -> Deactivate
	 *	iOnOff != 0 -> Activate
	 */
	inline void 		SetPropertyValue(const fAnnValueViewMode iFlag, const int iOnOff);

    /** To activate or deactivate an option of the uncut mode
    *	iOnOff == 0 -> Deactivate -> Object clipped
    *	iOnOff != 0 -> Activate   -> Object not clipped (by the Clipping Planes with Uncut mode on)
    */
    inline void 		SetPropertyValue(const fAnnValueUncut iFlag, const int iOnOff); //UO4 Uncut++

	/** Sets the material
	* Sets the CATGraphicMaterial
	* If this is called before SetMaterialApplication this this will win.
	* If this is called after SetMaterialApplication, this will loose
	* @param iMaterial- pointer to input CATGraphicMaterial
	 */
	void 		SetMaterial(CATGraphicMaterial *iMaterial);

	/** Sets the material application
	*  New API to Set CATMaterialApplication
	* @param iMaterialApp- input CATMaterialApplication to set
	* @return E_FAIL- if the SetMaterial is called before this, S_OK otherwise
	 */
	HRESULT 		SetMaterialApplication(const CATMaterialApplication & iMaterialApp);

	/** Returns an unsigned integer of 4 bytes.
	 *	if iFlag == fValueRGB -> the first three bytes will contain : red, green and then blue
	 *	if iFlag == fValueAlpha -> the last byte will contain : alpha
	 *	if iFlag == fValueAllRGBA -> the bytes will contain : red, green, blue and then alpha
	 */
	inline CATUINT32 	GetPropertyValue(const fAnnValueRGBA iFlag)		const;

	/** Returns 0 if iFlag view mode is deactivate. 
	*	Returns Returns another unsigned integer otherwise.
	*/
	inline CATUINT32 	GetPropertyValue(const fAnnValueViewMode iFlag) const;

    /** Returns 0 if iFlag uncut mode is deactivate.
    *	Returns another unsigned integer otherwise.
    */
    inline CATUINT32 	GetPropertyValue(const fAnnValueUncut iFlag) const; //UO4 Uncut++
	
	/** Returns the current material, NULL if none is applied.
	*/
	inline CATGraphicMaterial *GetMaterial() const;

	/** Returns the current material applicaiton.
	*/
	inline HRESULT  GetMaterialApplication(CATMaterialApplication & oMaterialApp);
	//--- Property values
	
	
	//+++ Inheritance
	
	/** To set an inheritance mode to a property (which supports inheritance) */
	inline void					SetInheritance(const fAnnInheritanceProp, const fAnnInheritanceMode iInheritance);

	/** To Get the inheritance mode of a property (which supports inheritance) */
	inline fAnnInheritanceMode	GetInheritance(const fAnnInheritanceProp iFlag) const;

	//--- Inheritance

private:
	//utility function to check if two material applications are equal or not
	inline CATINT32 IsMaterialAppEqual(const std::unique_ptr<CATMaterialApplication> & lhsMatApp, const std::unique_ptr<CATMaterialApplication> & rhsMatApp)const;
#if defined(CATVIS_ANNOTATION_DEBUG)

	/**  Theses structures are here to make the debugging easier. Never use them for a release.
	 *	note : this struct has to have the same order than eAnnTypeInternal ( and the same padding values ) 	
	 */
	//+++ DEBUG - INTERNAL USE ONLY
	struct SOverloadAndValues_Debug
	{
		CATUINT32 _propInvisibility				: 1	; //1
		CATUINT32 _propNoPick					: 1	; //2
		CATUINT32 _propRGB						: 1	; //3
		CATUINT32 _propAlpha					: 1	; //4
		CATUINT32 _propViewMode					: 1	; //5
		CATUINT32 _propMaterial					: 1	; //6
                                                      
		CATUINT32 _valueViewMesh				: 1	; //7
		CATUINT32 _valueViewEdge				: 1	; //8
		CATUINT32 _valueViewWithoutWires		: 1	; //9
		CATUINT32 _valueViewWithoutAxis			: 1	; //10
		CATUINT32 _valueViewWithoutPoints		: 1	; //11
		CATUINT32 _valueViewNoOutline			: 1 ; //12
        CATUINT32 _propUncut                    : 1 ; //13 UO4_UnCut++
        CATUINT32 _valueUncut                   : 1 ; //14 UO4_UnCut++
		CATUINT32 _padding						: 18; // = eValuePadding

		
	};

	struct SInheritante_Debug
	{
		CATUINT32 _inhPadding_1					: 2 ; //invisibility and noPick do not support inheritance
		CATUINT32 _inhRGB						: 1 ;
		CATUINT32 _inhAlpha						: 1 ;
		CATUINT32 _inhViewMode					: 1 ;
		CATUINT32 _inhMaterial					: 1 ;
        CATUINT32 _inhUncut                     : 1; //UO4 Uncut++
		CATUINT32 _inhPadding_2					: 25 ;
	};

	union
	{
		SOverloadAndValues_Debug	_overloadsAndProps_Debug;
		CATUINT32					_overloadsAndActivations;
	};

	union
	{
		SInheritante_Debug			_inheritProps_Debug;
		CATUINT32					_inheritProps;
	};

	union
	{
		SInheritante_Debug			_forceInheritProps_Debug;
		CATUINT32					_forceInheritProps;
	};
	//--- DEBUG INTERNAL USE ONLY

#else
	CATUINT32						_overloadsAndActivations;			// contain the overload and values on each digits
	CATUINT32						_inheritProps;						// properties with inherit mode
	CATUINT32						_forceInheritProps;					// properties with force inherit mode
#endif

#if defined(CATVIS_ANNOTATION_DEBUG)
	//+++ DEBUG - INTERNAL USE ONLY
	union
	{
		struct  
		{
			unsigned char 	_colorAlpha;
			unsigned char 	_colorBlue;
			unsigned char 	_colorGreen;
			unsigned char 	_colorRed;
		};
		CATUINT32			_colorRGBA;
	};
	//--- DEBUG INTERNAL USE ONLY
#else
	CATUINT32				_colorRGBA;					// color RGBA (1 byte for each channel in this exact order : red/green/blue/alpha)
#endif
	CATGraphicMaterial *_material;
	std::unique_ptr<CATMaterialApplication> _materialApp;
};

//////////////////////////////////////////////////////////////////////////
			//--- INLINE Implementations ---//
//////////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------------------

inline
void CATVisAnnotationValue::OverloadProperty( const fAnnProp iFlag )
{
	_overloadsAndActivations |= iFlag;
}

//------------------------------------------------------------------------------

inline
void CATVisAnnotationValue::DisableOverloadedProperty( const fAnnProp iFlag )
{
	_overloadsAndActivations &= (~iFlag);
}

//------------------------------------------------------------------------------

inline
CATUINT32 CATVisAnnotationValue::IsPropertyOverloaded( const fAnnProp iFlag ) const
{
	return (_overloadsAndActivations & iFlag) ? 1 : 0;
}

//------------------------------------------------------------------------------

inline
void CATVisAnnotationValue::SetPropertyValue( const fAnnValueRGBA iFlag, const CATUINT32 iValue )
{
	_colorRGBA &= (~iFlag); // we remove channel we do not want to touch according to iFlag

	_colorRGBA |= (iValue & iFlag);

}

//------------------------------------------------------------------------------

inline
void CATVisAnnotationValue::SetPropertyValue( const fAnnValueViewMode iFlag, const int iOnOff )
{
	_overloadsAndActivations = (0 != iOnOff) ? (_overloadsAndActivations | iFlag) : (_overloadsAndActivations & (~iFlag));
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
////Uncut+
inline
void CATVisAnnotationValue::SetPropertyValue(const fAnnValueUncut iFlag, const int iOnOff)
{
    _overloadsAndActivations = (0 != iOnOff) ? (_overloadsAndActivations | iFlag) : (_overloadsAndActivations & (~iFlag));
}
//Uncut-
//------------------------------------------------------------------------------

inline
CATUINT32 CATVisAnnotationValue::GetPropertyValue( const fAnnValueRGBA iFlag ) const
{
	return (_colorRGBA & iFlag);
}

//------------------------------------------------------------------------------

inline
CATUINT32 CATVisAnnotationValue::GetPropertyValue( const fAnnValueViewMode iFlag ) const
{
	return (_overloadsAndActivations & iFlag) ? 1 : 0;
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//Uncut+
inline
CATUINT32 CATVisAnnotationValue::GetPropertyValue(const fAnnValueUncut iFlag) const
{
    return (_overloadsAndActivations & iFlag) ? 1 : 0;
}
//Uncut-
//------------------------------------------------------------------------------

inline 
CATGraphicMaterial *CATVisAnnotationValue::GetMaterial() const
{
	return _material;
}

inline HRESULT  CATVisAnnotationValue::GetMaterialApplication(CATMaterialApplication& oMaterialApp)
{
	HRESULT rc = E_FAIL;
	if (_materialApp)
	{
		if (_materialApp->GetGraphicMaterial())
		{
			oMaterialApp = *(_materialApp.get());
			rc = S_OK;
		}
	}
	return rc;
}
//------------------------------------------------------------------------------

inline
fAnnInheritanceMode CATVisAnnotationValue::GetInheritance( const fAnnInheritanceProp iFlag ) const
{
	if(0 != (_forceInheritProps & iFlag))
		return fModeForceInherit;
	else if(0 != (_inheritProps & iFlag))
		return fModeInherit;
	else
		return fModeGraphScene;
}

//------------------------------------------------------------------------------

inline
void CATVisAnnotationValue::SetInheritance( const fAnnInheritanceProp iFlag, const fAnnInheritanceMode iInheritance )
{

	if(fModeForceInherit == iInheritance)
	{
		_forceInheritProps	|= iFlag;
		_inheritProps		&= (~iFlag); 
	}
	else if(fModeInherit == iInheritance)
	{
		_inheritProps		|= iFlag;
		_forceInheritProps	&= (~iFlag) ; 
	}
	else
	{
		_forceInheritProps	&= (~iFlag);
		_inheritProps		&= (~iFlag);
	}
}

//------------------------------------------------------------------------------
inline CATINT32 CATVisAnnotationValue::IsMaterialAppEqual(const std::unique_ptr<CATMaterialApplication>& lhsMatApp, const std::unique_ptr<CATMaterialApplication>& rhsMatApp)const
{
	if (nullptr == lhsMatApp && nullptr == rhsMatApp) return 1;
	if (nullptr == lhsMatApp || nullptr == rhsMatApp)
	{
		//when called from SetMaterialApplication, it can happen that one pointer is null and other pointer is not null, 
		//but the CATGraphicMaterial pointer inside it is null, in this case we should consider both pointer equal and return true
		//with this we dont have to go for checking other vairables in CATMaterialApplication like below block
		if (nullptr == lhsMatApp && (rhsMatApp && nullptr == rhsMatApp->GetGraphicMaterial())) return 1;
		if (nullptr == rhsMatApp && (lhsMatApp && nullptr == lhsMatApp->GetGraphicMaterial())) return 1;
		
		return 0;
	}
	
	if (lhsMatApp->GetGraphicMaterial() == rhsMatApp->GetGraphicMaterial() && (lhsMatApp->GetVisuImpl() == rhsMatApp->GetVisuImpl()))
	{
		float lhsangle = 0.0f, lhsscale = 0.0f, lhstransU = 0.0f, lhstransV = 0.0f;
		float rhsAngle = 0.0f, rhsScale = 0.0f, rhsTransU = 0.0f, rhsTransV = 0.0f;
		lhsMatApp->GetUVRotation(lhsangle);
		lhsMatApp->GetUVScale(lhsscale);
		lhsMatApp->GetUVTranslation(lhstransU, lhstransV);
		rhsMatApp->GetUVRotation(rhsAngle);
		rhsMatApp->GetUVScale(rhsScale);
		rhsMatApp->GetUVTranslation(rhsTransU, rhsTransV);

		return  (lhsMatApp->GetLayer() == rhsMatApp->GetLayer()) &&
			(lhsMatApp->GetMaterialInheritance() == rhsMatApp->GetMaterialInheritance()) &&
			(lhsMatApp->GetMappingOperator() == rhsMatApp->GetMappingOperator()) &&
			(lhsangle == rhsAngle) &&
			(lhsscale == rhsScale) &&
			(lhstransU == rhsTransU) &&
			(lhstransV == rhsTransV);
	}
	return 0;

}


inline
CATINT32 CATVisAnnotationValue::operator == (const CATVisAnnotationValue& iValue) const
{
	CATINT32 bEval = (_overloadsAndActivations == iValue._overloadsAndActivations) &&
		(_colorRGBA == iValue._colorRGBA) &&
		(_inheritProps == iValue._inheritProps) &&
		(_forceInheritProps == iValue._forceInheritProps);
	
	if (_materialApp || iValue._materialApp)
	{
		return bEval && IsMaterialAppEqual(_materialApp, iValue._materialApp);
	}
	return bEval && (_material == iValue._material);
	
}

//------------------------------------------------------------------------------

inline
CATVisAnnotationValue& CATVisAnnotationValue::operator=( const CATVisAnnotationValue& iValue )
{
	_overloadsAndActivations	= iValue._overloadsAndActivations;
	_colorRGBA					= iValue._colorRGBA;
	_inheritProps				= iValue._inheritProps;
	_forceInheritProps			= iValue._forceInheritProps;

	SetMaterial(iValue._material);
	if (iValue._materialApp)
	{
		SetMaterialApplication(*(iValue._materialApp.get()));
	}
	else
	{
		_materialApp.reset();
	}
	return (*this);
}
//------------------------------------------------------------------------------

#endif // end : CATVisAnnotationValue_H
