#ifndef VisClipPlaneDesc_H
#define VisClipPlaneDesc_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


// Make plane description consistent across renders and filters.
// Although this structure will be used internally, the flags
// are public.
struct VisClipPlaneDesc
{
  /*
  * Flags allowed on clipping planes
  * @param fCapping
  * Enables capping on clipping planes
  * @param fHiddenElements
  * Ensures that hidden elements are clipped (for eg. hidden edges)
  * @param fNonZParticipants
  * Ensures objects with graphics attribute type set to 0 or not participating in z-buffering, are clipped
  * @param fFurtive
  * Ensures furtive reps are clipped
  * @param fUncutting
  * Ensures reps added to CATVisAnnotation Filter with uncutmode are not clipped
  * @param fAllElements
  * Combination of fCapping, fHiddenElements, fNonZParticipants and fFurtive flags
  * @param fDefault
  * Normal clipping, only typical z-buffered volume, skin and transparent elements participate in clipping.
  */
	enum Flags
	{

		fCapping = 1 << 0,
		// sectionning, this value is assigned -1 in CATCullingRender, so we cant make it a flag,
		// although I am not sure what purpose -1 serves and maybe we should be able to set it as a flag.
		// If we decide to make it a flag, maybe we should remove per plane flags too, because
		// they are not respected anyway.
		// fSectioning = 1 << 1,
		fHiddenElements = 1 << 2,
		fPriority = 1 << 3,
		fNonZParticipants = 1 << 4,
		fFurtive = 1 << 5,
        fUncutting = 1 << 6, //UO4 Uncut++
		fAllElements = fHiddenElements|fPriority|fNonZParticipants|fFurtive,
		fDefaultOnFlags = /*fCapping |*/ fAllElements | fUncutting,
		fDefault = 0,
	};

	enum 
	{
		// WARNING : Do not change following value without checking CATVisClippingFilter and every CATRepRender behavior !
		kMaxClippingPlanes = 6,
	};

  // data
	int   nb_planes;
	// GF8:  This will hold flags for not only capping, but other
	// flags as well
	// unsigned int   flags;
	float point[3*kMaxClippingPlanes];
	float normal[3*kMaxClippingPlanes];
	// GF8: I am avoiding too many changes, just renaming this variable.
	int flags[kMaxClippingPlanes];
	// GF8: we never respect capping flags on individual planes,
	// capping is either on/off on all planes, we should discard this variable.
	// this also makes us fix the behaviour on every CATRender and
	// CATVizClippingFilter, as well as streaming code. It should simplify
	// a few things. We simply dont modify too many things, except maintaining 
	// this structure internally, external API will still see everything as array of
	// capping flags.
	//int capping[kMaxClippingPlanes];
	int   sectionning[kMaxClippingPlanes];
};

struct VisClipPlaneDescWithID : public VisClipPlaneDesc
{
  // data
	int identifier[VisClipPlaneDesc::kMaxClippingPlanes];
};

#endif //VisClipPlaneDesc_H
