#ifndef CATVisAnnotationTypeAndDef_H
#define CATVisAnnotationTypeAndDef_H

//--- debug mode ---//
#if defined(CNEXT_CLIENT)
	#if defined(CATVIS_ANNOTATION_DEBUG)
		#undef CATVIS_ANNOTATION_DEBUG
	#endif
#else
	#define CATVIS_ANNOTATION_DEBUG			
#endif

#ifndef NULL
#undef NULL
#define NULL 0
#endif

/** 
 *	This file is very important to use CATVisAnnotation feature. It describes several enum types used by annotation feature. 	
 */

//------------------------------------------------------------------------------

/** Severals modes for Annotation */
enum fAnnotationMode
{
	fModeNormal,
	fModeInvertInvisibilityAndNoPick,
	fModeInvertNoPick,
	fModeForceShow,
	fModeUndefined //something bad happened - use in case of there is an error		
};

//------------------------------------------------------------------------------

/**
 *	 INTERNAL USE ONLY
 *	 DO NOT USE IT : NEVER . any code under "internal use only" tag are not supposed to stay forever. They could be changed or deleted
 */

//+++ INTERNAL USE ONLY +++//
/*
enum eAnnPropInternal
{
	eIndexPropInvisibility			= 0,
	eIndexPropNoPick				= 1,
	eIndexPropRGB					= 2,
	eIndexPropAlpha					= 3,
	eIndexPropViewMode				= 4,
	eIndexPropMaterial				= 5,

	//+++ viewMode values +++//
	eIndexPropViewMesh				= 6,
	eIndexPropViewEdge				= 7,
	eIndewPropViewWithoutWires		= 8,
	eIndexPropViewWithoutAxis		= 9, 
	eIndexPropViewWithoutPoints		= 10,
	eIndexPropViewWithoutOutline	= 11,
	//--- viewMode values ---//

	eValuePadding					= (32 - 11) - 1 // = 20
};
*/
//--- INTERNAL USE ONLY ---//

//------------------------------------------------------------------------------

/** Properties which can be overloaded */
enum fAnnProp
{
	fPropInvisibility				= 0x00000001 << 0, //eIndexPropInvisibility,
	fPropNoPick						= 0x00000001 << 1, //eIndexPropNoPick,	
	fPropRGB						= 0x00000001 << 2, //eIndexPropRGB,
	fPropAlpha						= 0x00000001 << 3, //eIndexPropAlpha,
	fPropViewMode					= 0x00000001 << 4, //eIndexPropViewMode,
	fPropMaterial					= 0x00000001 << 5, //eIndexPropViewMode,
    fPropUnCut = 0x00000001 << 12, //eIndexPropUncut, //UO4_UnCut++
};

//------------------------------------------------------------------------------

/** to set values of colors and transparency */
enum fAnnValueRGBA
{
	fValueRGB						= 0xffffff00,
	fValueAlpha						= 0x000000ff,
	fValueAllRGBA					= 0xffffffff
};

//------------------------------------------------------------------------------

/** to set values for view mode */
enum fAnnValueViewMode
{
	fValueViewMesh					= 0x00000001 << 6,	//eIndexPropViewMesh, 
	fValueViewEdge					= 0x00000001 << 7,	//eIndexPropViewEdge,
	fValueViewWithoutWires			= 0x00000001 << 8,	//eIndewPropViewWithoutWires,
	fValueViewWithoutAxis			= 0x00000001 << 9,	//eIndexPropViewWithoutAxis,
	fValueViewWithoutPoints			= 0x00000001 << 10,	//eIndexPropViewWithoutPoints,
	fValueViewWithoutOutline		= 0x00000001 << 11  //eIndexPropViewWithoutOutline,
};

//------------------------------------------------------------------------------

/** Properties which support inheritance */
enum fAnnInheritanceProp
{
	fInhRGB							= fPropRGB,
	fInhAlpha						= fPropAlpha,
	fInhViewMode					= fPropViewMode,
	fInhMaterial					= fPropMaterial,
    fInhUncut                       = fPropUnCut //UO4_UnCut++
};

//------------------------------------------------------------------------------

/** Mode of Inheritance
 *	fModeInherit and fModeForceInherit will apply the overloaded attribute.
 *	fModeGraphScene will reapply the attribute which is the graph scene.
 *  In a Visu tree,  if a father has fModeForceInherit or fModeGraphScene and the son has fModeForceInherit or fModeGraphScene -> the son wins
 *  If a father has fModeInherit and the son has fModeInherit -> the father wins
 *	If a father has fModeInherit and its son has fModeForceInherit or fModeGraphScene -> the son wins
 *  If a father has fModeForceInherit or fModeGraphScene and the son has fModeInherit -> the father wins
 *	@see more detail in the PES 	
 */
enum fAnnInheritanceMode
{
	fModeInherit					= 0,
	fModeForceInherit				= 1,
	fModeGraphScene					= 2
};

//------------------------------------------------------------------------------

//UO4_UnCut+
/** to set values of UnCut mode on Clipping Planes */
enum fAnnValueUncut
{
    fValueUncut = 0x00000001 << 13,
};
//UO4_UnCut-

#endif // end : CATVisAnnotationType_H
