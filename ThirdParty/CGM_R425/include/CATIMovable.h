#ifndef CATI_MOVABLE__H
#define CATI_MOVABLE__H
// COPYRIGHT DASSAULT SYSTEMES 1998

/**
* @CAA2Level L1
* @CAA2Usage U3
*/
#include "CATBaseUnknown.h"
#include "CATCORBABoolean.h"

#include "CATPLMModeler3DInterfaces.h"

#ifndef CATIMovable_MIGRATION
#include "CATRepMode.h"
#else
#endif


extern ExportedByCATPLMModeler3DInterfaces  IID IID_CATIMovable ;

class CATMathTransformation;
class CATIMovable_var;

/**
* Interface to manage movable objects.
* <b>Role:</b> A movable object is an object that is intended to define 
* its coordinates in a particular 3D-coordinates system.<br>
* This interface provides methods to retrieve or set the relative position
* of the item, in the coordinate space of the context.<br>
* The context can be a movable object. There are two particular contexts : the default one and the
* global one (which is not a movable).
*/

class ExportedByCATPLMModeler3DInterfaces CATIMovable : public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	*@nodoc
	* Retrieves the position in a given context.
	* @param iPosObj
	*    The movable context to define position.<br>
	*    If NULL, it uses the default context.
	* @param Id
	*    Don't use it. Always 3D.
	* @param iInCtxt
	*    Don't use it. Always TRUE.
	* @return
	*     The CATMathTransformation matrix of the position
	*/
#ifndef CATIMovable_MIGRATION
	virtual CATMathTransformation GetPosition(
		const CATIMovable_var& iPosObj,
		const CATRepMode & Id = CATPrd3D,
		const CATBoolean iInCtxt = TRUE) const=0;
#else

	/**
	* Retrieves the position in a given context.
	* @param iPosObj
	*    The movable context to define position.<br>
	*    If NULL, it uses the default context.
	* @return
	*     The CATMathTransformation matrix of the position
	*/
	virtual CATMathTransformation GetPosition(
		const CATIMovable_var& iPosObj) const=0;
#endif

  /**
   * Retrieves the position in a global context.
   * @param oPos  
   *     The position of the movable object
	 *   @return 
	 *      <ul>
	 *       <li>S_OK if the position was successfully retrieved</li>
	 *       <li>E_FAIL otherwise</li>
	 *      </ul>
   */
	virtual HRESULT GetAbsPosition(
		CATMathTransformation & oPos ) const = 0;


	/**
	*@nodoc
   * Sets the relative position in a given context.<br>
   * <b>Note:</b> If the context is not defined, it uses the default context.
   * @param iTransfo
   *        The position to set.
   * @param iPosObj
   *    The movable context to define position.<br>
   *    If NULL, it uses the default context.
   * @param Id
   *    Don't use it. Always 3D.
   * @param InCtxt
   *    Don't use it. Always TRUE.
	 *   @return 
	 *      <ul>
	 *       <li>S_OK if the position was successfully set</li>
	 *       <li>E_FAIL otherwise</li>
	 *      </ul>
  */
#ifndef CATIMovable_MIGRATION
	virtual HRESULT SetPosition(
		const CATMathTransformation& iTransfo,
		const CATIMovable_var& iPosObj,
		const CATRepMode & Id = CATPrd3D,
		const CATBoolean InCtxt = TRUE) const=0;
#else
	/**
	* Sets the relative position in a given context.<br>
	* <b>Note:</b> If the context is not defined, it uses the default context.
	* @param iTransfo
	*        The position to set.
	* @param iPosObj
	*    The movable context to define position.<br>
	*    If NULL, it uses the default context.
	*   @return 
	*      <ul>
	*       <li>S_OK if the position was successfully set</li>
	*       <li>E_FAIL otherwise</li>
	*      </ul>
	*/
	virtual HRESULT SetPosition(
		const CATMathTransformation& iTransfo,
		const CATIMovable_var& iPosObj) const=0;
#endif

	/**
	* Sets position in an absolute 3D-coordinates space (global context).
	* @param iPos
	*        The position to set.
	*   @return 
	*      <ul>
	*       <li>S_OK if the position was successfully set</li>
	*       <li>E_FAIL otherwise</li>
	*      </ul>
	*/
	virtual HRESULT SetAbsPosition(
		const CATMathTransformation & iPos ) = 0;


	/**
	*@nodoc
	*/
#ifndef CATIMovable_MIGRATION
	virtual HRESULT ApplyTransformation(
		const CATMathTransformation & iTransfo,
		const CATIMovable_var& iPosObj,
		const CATRepMode & Id = CATPrd3D,
		const CATBoolean iInCtxt = TRUE) const=0;
#else
	/**
	* Applies a transformation in the 3D-coordinates space of the context.
	* @param iTransfo
	*        The transformation to apply.
	* @param iPosObj
	*    The movable context to define position.<br>
	*    If NULL, it uses the default context.
	*   @return 
	*      <ul>
	*       <li>S_OK if the transformation was successfully applied</li>
	*       <li>E_FAIL otherwise</li>
	*      </ul>
	*/
	virtual HRESULT ApplyTransformation(
		const CATMathTransformation & iTransfo,
		const CATIMovable_var& iPosObj) const=0;
#endif
};
CATDeclareHandler(CATIMovable,CATBaseUnknown); 

#endif
