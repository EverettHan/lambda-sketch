// COPYRIGHT Dassault Systemes 2004
#ifndef CATIGeometryViewModel_H
#define CATIGeometryViewModel_H

#include <CATViewItf.h>
#include <CATBaseUnknown.h>
#include <CATBaseUnknown_var.h>

class CAT3DRep;

extern ExportedByCATViewItf IID IID_CATIGeometryViewModel;

/**
 * Get representation of a model object.
 **/
class ExportedByCATViewItf CATIGeometryViewModel: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Get 3D representation associated to model object
	 **/
	virtual CAT3DRep *Get3DRep( CATBaseUnknown_var iObject ) = 0;
};

CATDeclareHandler( CATIGeometryViewModel, CATBaseUnknown );

#endif
