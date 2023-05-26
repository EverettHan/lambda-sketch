// COPYRIGHT Dassault Systemes 2004
#ifndef CATIViewController_H
#define CATIViewController_H

#include <CATViewItf.h>
#include <CATBaseUnknown.h>

extern ExportedByCATViewItf IID IID_CATIViewController;

/**
 * General controller methods
 **/
class ExportedByCATViewItf CATIViewController: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * A node as been selected (simple-click)
	 **/
	virtual void OnSelect( CATBaseUnknown_var iNode ) = 0;
	/**
	 * A node as been activated (double-click)
	 **/
	virtual void OnActivate( CATBaseUnknown_var iNode ) = 0;
	/**
	 * Request for contextual menu (right click)
	 **/
	virtual void OnContext( CATBaseUnknown_var iNode ) = 0;
	/**
	 * Cursor moved over a node
	 **/
	virtual void OnMoveOver( CATBaseUnknown_var iNode ) = 0;
	/**
	 * Is a node selected ?
	 **/
	virtual int IsSelected( CATBaseUnknown_var iNode ) = 0;
	/**
	 * Is a node pre-selected ?
	 **/
	virtual int IsPreSelected( CATBaseUnknown_var iNode ) = 0;
	/**
	 * Is a node active ?
	 **/
	virtual int IsActive( CATBaseUnknown_var iNode ) = 0;
};

CATDeclareHandler( CATIViewController, CATBaseUnknown );

#endif
