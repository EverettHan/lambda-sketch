#ifndef CATColorPathElement_h
#define CATColorPathElement_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

#include "CATPathElement.h"

/** Class representing a CATPathElement with a color.
* <b> Role </b>: provides a particular kind of CATPathElement with a color for the highlighting
* <p>
* For example, if when we need to use different color for highlighting in the same time, 
* we will use CATColorPathElement instead of CATPathElement. 
* Actually, there are limited number of "extra" colors provided. Each of these colors are
* associated to a slot. The CATColorPathElement will contain this slot.
* @see CATPathElement
* 
*/
class ExportedByCATVisItf CATColorPathElement : public CATPathElement
{
	/** @nodoc */
	CATDeclareClass;

public:

	/** Slot associated with a color. 
	*/
	enum eSlot
	{
		//these values correspond to index of several arrays, do never change these values.
		//If you need more slot, just add another one eSlot(i) just before eSlotCount (a rebuild is necessary)
		eSlot0 = 0, 
		eSlot1,
		eSlot2,
		eSlot3,
		eSlot4,
		eSlot5,
		eSlot6,
		eSlot7,
		eSlot8,
		eSlot9,
		eSlotCount
	};

	/**
    * Constructs the class from an object.
    * @param   iObject
    *     the object which will be the first object of the path. 
    * Notice that one @href CATBaseUnknown#AddRef is done on this object.
    *
    */
	CATColorPathElement( const CATBaseUnknown *iObject = NULL );

	

	/** Constructs the class from a @href CATPathElement and a slot.
	* @param iPathElement
	*		The CATPathElement to copy.
	* @param iSlot
	*		The Slot of the color.
	*/
	CATColorPathElement(const CATPathElement& iPathElement, CATColorPathElement::eSlot iSlot = eSlot0);

	/** Copy Constructor.
	* <br><b>Role</b>: This method creates a new CATColorPathElement which is a copy of the input 
	* CATColorPathElement.
	* #param iPath
	*		path to copy.
	*/
	CATColorPathElement( const CATColorPathElement & iPath);

	/** Copy Constructor.
	*/
	virtual ~CATColorPathElement();

	/** Returns a pointer to a new path of objects which is the clone of the current one.
	*/
	virtual CATColorPathElement * Clone() const;

	/** Retrieves the color slot.
	* @return
	*        The slot.
	*/
	const CATColorPathElement::eSlot GetColorSlot() const;

	/** set the color slot.
	* @param iSlot
	*        The slot.
	*/
	void SetColorSlot(CATColorPathElement::eSlot iSlot);


protected:

	/** @nodoc */
	eSlot _colorSlot;
};





#endif
