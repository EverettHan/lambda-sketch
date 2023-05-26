// COPYRIGHT Dassault Systemes 2005
#ifndef CATIColumnModel2_H
#define CATIColumnModel2_H

#include <CATViewItf.h>
#include <CATBaseUnknown.h>
#include <CATString.h>
#include <CATListOfCATString.h>

extern ExportedByCATViewItf IID IID_CATIColumnModel2;


/**
 * CATIColumnModel2. Interface for column models that manage hide/show of columns.
 **/
class ExportedByCATViewItf CATIColumnModel2: public CATBaseUnknown
{
    CATDeclareInterface;
public:
	/**
	 * Hide a column
	 **/
    virtual void HideColumn( const CATString &iID ) = 0;
	/**
	 * Show a column
	 **/
	virtual void ShowColumn( const CATString &iID ) = 0;
	/**
	 * Get list of hidden columns
	 **/
	virtual void GetHiddenColumns( CATListOfCATString &oIDs ) = 0;

	/**
	 * Get list of columns
	 **/
  virtual void GetColumns( CATListOfCATString &oIDs ) = 0;
};

CATDeclareHandler(CATIColumnModel2, CATBaseUnknown);

#endif
