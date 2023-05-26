// COPYRIGHT Dassault Systemes 2004
#ifndef CATIDragViewController_H
#define CATIDragViewController_H

#include <CATViewItf.h>
#include <CATBaseUnknown.h>

extern ExportedByCATViewItf IID IID_CATIDragViewController;

/**
 * Methods for support of drag&drop by controllers
 **/
class ExportedByCATViewItf CATIDragViewController: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * A node as been expanded (click on expander when collapsed)
	 **/
	virtual void OnDrag( int iStart ) = 0;
};

CATDeclareHandler( CATIDragViewController, CATBaseUnknown );

#endif
