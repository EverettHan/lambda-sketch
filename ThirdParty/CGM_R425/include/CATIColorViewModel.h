#ifndef _CATIColorViewModel_H
#define _CATIColorViewModel_H

#include <CATBaseUnknown.h>
#include <CATViewItf.h>

extern ExportedByCATViewItf IID IID_CATIColorViewModel;

/**
 * Interface to colorize nodes
 * Provided for VPM Nav/PSN needs for user customization of tree.
 * DO NOT USE FOR APPLICATION LOOK & FEEL PURPOSE.
 * Standard colors are definied by the global look & feel and should not
 * be modified in the intend to provide a dedicated application look.
 **/
class ExportedByCATViewItf CATIColorViewModel : public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Provide node background color
	 **/
	virtual HRESULT GetColor( CATBaseUnknown_var iNode, int &oRed, int &oGreen, int &oBlue ) = 0;
};

CATDeclareHandler( CATIColorViewModel, CATBaseUnknown );

#endif
