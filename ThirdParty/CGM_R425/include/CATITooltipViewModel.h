// COPYRIGHT Dassault Systemes 2004
#ifndef CATITooltipViewModel_H
#define CATITooltipViewModel_H

#include <CATViewItf.h>
#include <CATUnicodeString.h>
#include <CATBaseUnknown.h>
#include <CATBaseUnknown_var.h>

extern ExportedByCATViewItf IID IID_CATITooltipViewModel;

/**
 * CATITooltipViewModel. Interface to customize object tooltip.
 **/
class ExportedByCATViewItf CATITooltipViewModel: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Get tooltip.
	 * iNode is the object for which a tooltip is requested.
	 * iArgs is an optional parameter defined by the view (not implemented at this time => always NULL)
	 **/
	virtual CATUnicodeString GetTooltip( CATBaseUnknown_var iNode, CATBaseUnknown_var iArgs ) = 0;
};

CATDeclareHandler(CATITooltipViewModel, CATBaseUnknown);

#endif
