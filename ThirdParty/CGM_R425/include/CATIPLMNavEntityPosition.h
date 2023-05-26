// COPYRIGHT Dassault Systemes 2006

/**
 * @level Protected
 * @usage U3
 */

#ifndef CATIPLMNavEntityPosition_H
#define CATIPLMNavEntityPosition_H

#include "CATPLMComponentInterfaces.h"

#include "CATBaseUnknown.h"
class CATMathTransformation;

extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMNavEntityPosition;

/**
 * Interface to retrieve the spacial position of an Entity of type Instance or Occurrence.
 */
class ExportedByCATPLMComponentInterfaces CATIPLMNavEntityPosition: public CATBaseUnknown
{
	CATDeclareInterface;

	public:
		
		/**
		* Return the position of the Instance or Occurrence relatively to its father.
		* @param oPos  
		*     The relative position
			*   @return 
			*      <ul>
			*       <li>S_OK if the position was successfully retrieved</li>
			*       <li>E_FAIL otherwise</li>
			*      </ul>
		*/
		virtual HRESULT GetPosition(CATMathTransformation& oPos ) const = 0;

		/**
		* Retrieves the position of the Occurence in its global context. This position is named the absolute position.
		* For an instance the AbsPosision = Position
		* For an Occurrence the AbsPosition is the composition of the Occurrence Position and its father absolute position.
		* @param oPos  
		*     The absolute position
			*   @return 
			*      <ul>
			*       <li>S_OK if the position was successfully retrieved</li>
			*       <li>E_FAIL otherwise</li>
			*      </ul>
		*/
		virtual HRESULT GetAbsPosition(CATMathTransformation& oPos ) const = 0;
		
};

CATDeclareHandler(CATIPLMNavEntityPosition, CATBaseUnknown);

#endif
