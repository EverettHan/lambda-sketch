// COPYRIGHT Dassault Systemes 2004
#ifndef CATITextOverlayViewModel2_H
#define CATITextOverlayViewModel2_H

#include <CATAfrItf.h>
#include <CATITextOverlayViewModel.h>
#include <CATListOfCATString.h>

extern ExportedByCATAfrItf IID IID_CATITextOverlayViewModel2;

/**
 * CATITextOverlayViewModel2. Interface to display a model in a list view.
 **/
class ExportedByCATAfrItf CATITextOverlayViewModel2: public CATITextOverlayViewModel
{
	CATDeclareInterface;
public:
	/**
	 * Get properties
	 **/
	virtual void GetProperties( CATListOfCATString &oProperties ) = 0;
};

CATDeclareHandler( CATITextOverlayViewModel2, CATITextOverlayViewModel );

#endif
