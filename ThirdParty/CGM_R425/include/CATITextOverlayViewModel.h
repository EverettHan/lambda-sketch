// COPYRIGHT Dassault Systemes 2004
#ifndef CATITextOverlayViewModel_H
#define CATITextOverlayViewModel_H

#include <CATAfrItf.h>
#include <CATIObjectViewModel.h>
class CATMathPointf;

extern ExportedByCATAfrItf IID IID_CATITextOverlayViewModel;

/**
 * CATITextOverlayViewModel. Interface to display a model in a list view.
 **/
class ExportedByCATAfrItf CATITextOverlayViewModel: public CATIObjectViewModel
{
	CATDeclareInterface;
public:
	/**
	 * Get item label 3D anchor point (ex: bounding sphere center)
	 **/
	virtual HRESULT GetAnchor( CATBaseUnknown_var iNode, CATMathPointf &oAnchor ) = 0;
};

CATDeclareHandler( CATITextOverlayViewModel, CATIObjectViewModel );

#endif
