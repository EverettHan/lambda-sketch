/*
*  CATMMPIColorSpace.h
*
*  Created by sx6 on 06/03/2013.
*  Copyright 2013 Dassault Systemes. All rights reserved.
*
*/
#ifndef CATMMPIColorSpace_H
#define CATMMPIColorSpace_H
// COPYRIGHT DASSAULT SYSTEMES 2013
#include "CATMMediaPixelImage.h"
#include "CATMMCTSBaseUnknownPoolInstance.h"
#include "CATSysTSUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATMMColorProfile.h"

class CATMMColorProfile;

/**
 * @ingroup groupPixelImageColor
 **/
class ExportedByCATMMediaPixelImage CATMMPIColorSpace : public  CATMMCTSBaseUnknownPoolInstance
{
  CATSysTSDeclareClass;
public:
  static CATMMPIColorSpace* CreateColorSpace();
	/*
	* Constructor, destructor
	* copy constructor and assignement operator
	*/
	CATMMPIColorSpace ();
	~CATMMPIColorSpace ();
	CATMMPIColorSpace( const CATMMPIColorSpace& other );
	CATMMPIColorSpace& operator=( const CATMMPIColorSpace& other );

	/*
	* Device Dependance
	*
	* TRUE = no Color Profile = use sRGB virtual profile
	* FALSE = Color Profile defined by user (can be .icc file or embedded icc profile in image file)
	*
	* Remember to change its value when assigning / removing a CATMMColorProfile
	*/
	CATBoolean _deviceDependant;          
	/*
	* Color Space Name
	* e.g.,	"WORKING COLOR SPACE"
	*		"sRGB"
	*		"NO COLOR SPACE"
	*
	*/
	CATUnicodeString _name;

	enum CATMMCOLORMODEL{
		CATMMRGB,    /** Red, Green and Blue (nonlinear). */
		CATMMRGBA,    /** Red, Green and Blue (nonlinear). */
		CATMMMAP,    /** Indexed by RGB color map. */
		CATMMGRAY,   /** Shades of gray, or an intensity value that is not related to color. */
		CATMMMONO,   /** 2 colors: black (0) and white (1) .     */
		CATMMCMYK,   /** Cian, Magenta, Yellow and Black (nonlinear).                          */
		CATMMCMY,   /** Cian, Magenta, Yellow (nonlinear).                          */
		CATMMYCBCR,  /** ITU-R 601 Y'CbCr. Y' is luma (nonlinear Luminance).                   */
		CATMMLAB,    /** CIE L*a*b*. L* is Lightness (nonlinear Luminance, nearly perceptually uniform). */
		CATMMLUV,    /** CIE L*u*v*. L* is Lightness (nonlinear Luminance, nearly perceptually uniform). */
		CATMMXYZ,    /** CIE XYZ. Linear Light Tristimulus, Y is linear Luminance.             */
		CATMMDEVICEN,/** Multi-component color is any generic color space representing N color components */
		CATMMYUV,    /** Y'UV model, luma (Y') and two chrominance (UV) components.*/
		CATMMHSV,    /** hue, saturation, and value cylindrical-coordinate representations of points in an RGB color model*/
		CATMMHSL,    /** hue, saturation, and lightness cylindrical-coordinate representations of points in an RGB color model*/
		CATMMUNKNOWN
	};

	/*
	* Color Model Type
	* e.g.,	RGB
	*		HSV
	*		LAB...
	*
	*/
	CATMMCOLORMODEL _type;

	void ReadColorProfile();

  /*
   * @param ipColorProfile. Will be AddRef by CATMMPIColorSpace.
   */
	void SetColorProfile(CATMMColorProfile* ipColorProfile);

  /**
   * @return the referenced color profile. Has to be released after use.
   */
  CATMMColorProfile* GetColorProfile();

  CATBoolean HasSameColorSpaceThan(const CATMMPIColorSpace* ipColorSpace) const;

private:
  /*
	* Color profile to be used (ICC profile) 
	*/
	CATMMColorProfile *_pColorProfile;

	void CreateWorkingColorSpace ();
};

#endif  // CATMMPIColorSpace_H
