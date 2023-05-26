//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013/06/27
//===================================================================
// CATIAfrCtxBar.cpp
// Header definition of class CATIAfrCtxBar
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/06/27 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIAfrCtxBar_H
#define CATIAfrCtxBar_H


/**
 * @level Protected 
 * @CAA2Usage U4 CATAdapterAfrCtxBar
 */

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATString;
class CATUnicodeString;

extern ExportedByCATAfrItf  IID IID_CATIAfrCtxBar ;

/**
* Interface to add items into the context bar or contextual menu.
* <b>Role</b>:This interface enables you to add commands into a context component 
* when it is filled and displayed. 
* <br>To become actor of the context, you need to subscribe to the context bar or contextual menu 
* thanks to methods provided by @href CATIAfrCtxBarManager interface.
* <br>If you implement this interface for an app, the late type should be: <AppName>_AfrCtxBar. In this case,
* you are automatically called when the app is active, without having to subscribe to the context.
* <p><b>BOA information</b>: this interface can be implemented
* using the BOA (Basic Object Adapter).
* To know more about the BOA, refer to the Object Modeler chapter in CAA Encyclopedia.
*</p>
*/
class ExportedByCATAfrItf CATIAfrCtxBar: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
	  * @nodoc deprecated  => on supprime???
    */

	 virtual void FillContextBar() = 0; // deprecated

	/**
    * Adds commands to a contextual menu.
    * @param iId
    *   The ID corresponding to the trigger clicked
    * @return
    *   An HRESULT value. 
    */

	virtual HRESULT FillCtxMenu(const CATString iId) = 0;

	/**
	  * Adds commands to the context bar.
    * @param iId
    *   The ID corresponding to the trigger cliked
    * @return
    *   An HRESULT value. 
	  */
    virtual HRESULT FillCtxBar(const CATString iId) = 0;

  /**
	  * Set a model to fill the contextual component.
    * Used in particular cases like when a model comes from JS world
    * @param iModel
    *   model used by the actor
    * @param iArgument2
    *   facultative argument
	  */
    virtual void SetModel(const CATUnicodeString & iModel,const CATUnicodeString & iArgument2) = 0;

	/**
	* Callback called when an element of the contextual bar is preselected
	* @param iEmitter
	*   Object emitter of the event
	*/
	virtual void PreselectedItemEventCB(CATBaseUnknown* iEmitter) = 0;

};

//-----------------------------------------------------------------------

#endif
