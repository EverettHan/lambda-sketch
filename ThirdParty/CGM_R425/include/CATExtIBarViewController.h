// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATExtIBarViewController.h
// Adapter for CATIBarViewController interface
//
//===================================================================
#ifndef CATExtIBarViewController_H
#define CATExtIBarViewController_H

#include "CATAfrItf.h"
#include "CATCommand.h"

/**
* Class representing the Controller of an immersive toolbar.
* <br>
* Use this adapter to implement CATIBarViewController interface.
* <br>
* See @href CATBarView for all explanations on the component.
* <br>
* The default behaviors are empty.
*/
class ExportedByCATAfrItf CATExtIBarViewController: public CATCommand
{
  CATDeclareClass;

  public:
    CATExtIBarViewController();
    ~CATExtIBarViewController() = default;

	/**
	 * A button was selected (simple-click)
	 **/
	virtual void OnSelect( CATBaseUnknown_var iBarComponent );
	/**
	 * A button was activated (double-click)
	 **/
	virtual void OnActivate( CATBaseUnknown_var iBarComponent );
	/**
	 * Request for contextual menu (right click)
	 **/
	virtual void OnContext( CATBaseUnknown_var iBarComponent );
	/**
	 * Cursor moved over a button
	 **/
	virtual void OnMoveOver( CATBaseUnknown_var iBarComponent );
	/**
	 * Cursor leaves a button
	 **/
	virtual void OnEndMoveOver( CATBaseUnknown_var iBarComponent );
	/**
	 * Is a button selected ?
	 **/
	virtual int IsSelected( CATBaseUnknown_var iBarComponent );
	/**
	 * Is a button pre-selected ?
	 **/
	virtual int IsPreSelected( CATBaseUnknown_var iBarComponent );
	/**
	 * Is a button active ?
	 **/
	virtual int IsActive( CATBaseUnknown_var iBarComponent );

};

#endif
