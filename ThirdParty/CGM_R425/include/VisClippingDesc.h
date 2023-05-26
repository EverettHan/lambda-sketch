#ifndef VisClippingDesc_H
#define VisClippingDesc_H

// Make clipping description consistent across renders and filters.
struct VisClippingDesc
{
  /*
  * Enumeration for clipping type
  * @param ePlane: CATVisClippingFilter
  * @param eSphere: CATVisClippingSphereFilter
  * @param eSection: CATVisClippingSectionsFilter
  * @param eVolume: CATVisClippingVolumesFilter
  * @param eCurve: CATVisCurveClippingFilter
  */
  enum Type
  {
    ePlane = 0,
    eSphere,
    eSection,
    eVolume,
    eCurve,
    eTypeCount
  };

  /*
  * Flags allowed on clipping filters
  * @param fApplyOnHiddenElements
  * Ensures that hidden elements are clipped (for eg. hidden edges)
  * @param fApplyOnPriority
  * Ensures objects with graphics attribute priority used (2D elements in CAT2DTo3DBagRep), are clipped
  * @param fApplyOnNonZParticipants
  * Ensures objects with graphics attribute type set to 0 or not participating in z-buffering, are clipped
  * @param fApplyOnFurtive
  * Ensures furtive reps are clipped
  * @param fApplyOnAllElements
  * Combination of fApplyOnHiddenElements, fApplyOnPriority, fApplyOnNonZParticipants and fApplyOnFurtive flags
  * @param fDefault
  * Normal clipping, only typical z-buffered volume, skin and transparent elements participate in clipping.
  */
	enum Flags
	{
    fMinClippingDescFlag = 0,
    fDefault = 0,
		fApplyOnHiddenElements = 1 << 0,
		fApplyOnPriority = 1 << 1,
		fApplyOnNonZParticipants = 1 << 2,
		fApplyOnFurtive = 1 << 3,
		fApplyOnAllElements = fApplyOnHiddenElements|fApplyOnPriority|fApplyOnNonZParticipants|fApplyOnFurtive,
		fAllowUncutting = 1 << 4,
    fMaxClippingDescFlag = 1 << 5
	};
};

#endif //VisClippingDesc_H
