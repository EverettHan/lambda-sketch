#ifndef CATColorPathElementRep_h
#define CATColorPathElementRep_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATPathElementRep.h"

/** Class representing a CATPathElementRep created with a CATColorPathElement
  * <b>Role</b>: this class is used to visualize objects that are highlighted and it is
  * based on a path of 3D graphical representations ( @href CATRepPath ), which is an input of the class,
  * to draw the geometry. This class overrides attributes associated to graphical representations hold in
  * the path.
  * This class uses the color associated with the @ref CATColorPathElement
  * @see CATPathElementRep
  * @see CATColorPathElement
  */
class ExportedBySceneGraphManager CATColorPathElementRep : public CATPathElementRep
{
	/** @nodoc */
	CATDeclareClass;

public:

	/** Constructs a rep from a path of objects and a path of graphical representations.
	* @param iPathOfObject
	*   path of objects
	* @param iPathOfRep
	*    path of graphical representations.
	*/
	CATColorPathElementRep(const CATColorPathElement& iPathOfObject, CATRepPath& iPathOfRep);
	
	/** Constructs a rep from a path of objects and a path of graphical representations.  
	* @param iPathOfObject
	*   path of objects
	* @param iPathOfRep
	*    path of graphical representations.
	*/
	CATColorPathElementRep(CATColorPathElement* iPathOfObject, CATRepPath* iPathOfRep);

	/** Copy constructor.
	*/
	CATColorPathElementRep(const CATColorPathElementRep& iRep);

	virtual ~CATColorPathElementRep();

};

//------------------------------------------------------------------------------
//MORE INFORMATION
//This class is used by MulticolorHighlight feature
//	When a user add a CATColorPathElement in the HSO, the VisuManager will
//	create a corresponding CATColorPathElementRep used by VisualizationFondation.
//Both : CATColorPathElement and CATColorPathElementRep are used to make a connection
//	   between VisualizationController and VisualizationFondation.
//CATColorPathElement : VisualizationController.
//CATColorPathElementRep : VisualizationFondation
//
//						 This class seems empty, but it's important. 
//						 In fact, I said CATColorPathElemenRep is used by VisualizationFondation, but this class is
//						 located in VisualizationController. 
//						 Actually, it's its super super class (CATVizBasePathElementRep which is the superclass of CATPathElementRep) which is 
//						 located in VisualizationFondation
//
//						 So this class is here to set some specific params in its super class (CATVizBasePathElementRep) to enable multicolor highlight
//						 -> CATVizBasePathElementRep::_colorSlot is set with the slot value contained by CATColorPathElement.
//						 -> CATVizBasePathElementRep::_bMultiColorHighlight = 1; to enable multicolor highlight
//------------------------------------------------------------------------------

#endif // CATColorPathElementRep_h
