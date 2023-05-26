// COPYRIGHT Dassault Systemes 2004
#ifndef CATIObjectSetViewModel_H
#define CATIObjectSetViewModel_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATBaseUnknown_var.h"
#include "CATLISTV_CATBaseUnknown.h"
typedef  CATLISTV(CATBaseUnknown_var)  CATListOfCATBaseUnknown_var; 

extern ExportedByCATAfrItf IID IID_CATIObjectSetViewModel;

class CATPathElement;

/**
 * List a set of interactive object = list of CATPathElement
 **/
class ExportedByCATAfrItf CATIObjectSetViewModel: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Get a list of items
	 **/
	virtual HRESULT GetObjects( CATListOfCATBaseUnknown_var &oObjects ) = 0;
	/**
	 * Get CATPathElement for item
	 **/
	virtual CATPathElement *GetPath( const CATBaseUnknown_var &iObject ) = 0;
};

CATDeclareHandler( CATIObjectSetViewModel, CATBaseUnknown );

#endif
