#ifndef CAT3DReferencePlaneSizeMode_H
#define CAT3DReferencePlaneSizeMode_H

/** The way CAT3DReferencePlaneRep and CAT3DReferencePlaneGP are rendered
* @param FixedFromSettings
*		Primitive is rendered fixed size, and the size is getting retrieved in a session setting
* @param Zoomable
*		Primitive is rendered zoomable, with 3D sizes provided to the representation
* @param FromSettings
*		Let a session setting decides whether the primitive is rendered FixedFromSetting or Zoomable
*/
enum class CAT3DReferencePlaneSizeMode
{
	FixedFromSettings,
	Zoomable,
	FromSettings
};

#endif
