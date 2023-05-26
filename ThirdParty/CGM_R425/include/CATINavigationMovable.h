// COPYRIGHT DASSAULT SYSTEMES 2014
#ifndef CATINavigationMovable_H
#define CATINavigationMovable_H
/**
* @CAA2Level L0
* @CAA2Usage U0
*/
#include "CATBaseUnknown.h"

#include "CATPLMModeler3DInterfaces.h"



extern ExportedByCATPLMModeler3DInterfaces  IID IID_CATINavigationMovable ;

class CATMathTransformation;
/**
* Interface to manage product movable object in navigation window.
* <b>Role:</b> A movable object is an object that is intended to define 
* its coordinates in a particular 3D-coordinates system.<br>
* This interface provides methods to retrieve the relative position
* of the item.<br>
* This interface does not take into account overloaded data (PMR)
*/

class ExportedByCATPLMModeler3DInterfaces CATINavigationMovable : public CATBaseUnknown
{
	CATDeclareInterface;

	/**
	* Return the position of the Instance or Occurrence relatively to its father.
	* @param oPos
	*   The CATMathTransformation matrix of the position<br>
	*   @return 
	*      <ul>
	*       <li>S_OK if the position was successfully retrieved</li>
	*       <li>E_FAIL otherwise</li>
	*      </ul>
	*/
	virtual HRESULT GetPosition(
		CATMathTransformation& oPos) const=0;

	/**
	* Retrieves the position of the Occurence in its global context. This position is named the absolute position.
	* For an instance the AbsPosision = Position
	* For an Occurrence the AbsPosition is the composition of the Occurrence Position and its father absolute position. This position does not take into account the overload
	* @param oPos  
	*     The absolute position of the movable object
	*   @return 
	*      <ul>
	*       <li>S_OK if the position was successfully retrieved</li>
	*       <li>E_FAIL otherwise</li>
	*      </ul>
	*/
	virtual HRESULT GetAbsPosition(
		CATMathTransformation & oPos ) const = 0;
};
CATDeclareHandler(CATINavigationMovable,CATBaseUnknown); 

#endif
