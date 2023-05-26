// COPYRIGHT Dassault Systemes 2004
#ifndef CATITreeViewController_H
#define CATITreeViewController_H

#include <CATViewItf.h>
#include <CATBaseUnknown.h>

extern ExportedByCATViewItf IID IID_CATITreeViewController;

/**
 * Tree view specific controller methods
 **/
class ExportedByCATViewItf CATITreeViewController: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * A node as been expanded (click on expander when collapsed)
	 **/
	virtual void OnExpand( CATBaseUnknown_var iNode ) = 0;
	/**
	 * A node as been expanded (click on expander when expanded)
	 **/
	virtual void OnCollapse( CATBaseUnknown_var iNode ) = 0;
};

CATDeclareHandler( CATITreeViewController, CATBaseUnknown );

#endif
