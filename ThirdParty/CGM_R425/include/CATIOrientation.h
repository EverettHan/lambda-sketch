/* -*-c++-*- */
#ifndef CATIOrientation_h
#define CATIOrientation_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Level L1
* @CAA2Usage U3
*/


#include "CATBaseUnknown.h"
#include "AD0XXBAS.h"

class CATMathPoint;

extern IID ExportedByAD0XXBAS IID_CATIOrientation;

/**
 * Interface to manage access to the orientation (material inside) of a sub-element(BRep Access).
 * <br><b>Note:</b> available only on faces for the moment.
 */

class ExportedByAD0XXBAS CATIOrientation : public CATBaseUnknown
{
  CATDeclareInterface;

public:
	/**
	* Returns the orientation.
	* @param iSolid
	*       corresponds to a body.
	*      <br>if NULL, computation is done on the topological body where the sub-element is defined.
	*      <br>else computation is done on this body
	* @return 
	*       1 if the orientation of material and geometry underlying the face are the same.
	*  <br> -1 if the orientation of material and geometry underlying the face are opposite.
	*  <br> 0 if the system didn't succeed in computing the result 
	*/
  virtual int GetOrientation(const CATBaseUnknown_var &iSolid=NULL_var)const  = 0;

	/**
	* Returns the coordinates of a characteristic point of the sub-element.
	* @param iBody
	*       if NULL, computation is done on the topological body where the sub-element is defined.
	* <br>  else computation is done on this body.
	* @return 
	*       a CATMathPoint
	*/
  virtual CATMathPoint GetFavoritePoint(const CATBaseUnknown_var &iBody=NULL_var) const = 0;
};

CATDeclareHandler(CATIOrientation,CATBaseUnknown);

#endif


