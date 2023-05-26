// COPYRIGHT Dassault Systemes 2004
#ifndef CATIViewModelNode_H
#define CATIViewModelNode_H

#include <CATViewItf.h>
#include <CATUnicodeString.h>
#include <CATBaseUnknown.h>
#include <CATBaseUnknown_var.h>
#include <CATLISTV_CATBaseUnknown.h>
typedef  CATLISTV(CATBaseUnknown_var)  CATListOfCATBaseUnknown_var; 

extern ExportedByCATViewItf IID IID_CATIViewModelNode;

/**
 * Interface to implement delegate presentation to model object
 * instead of CATViewModel implementation.
 **/
class ExportedByCATViewItf CATIViewModelNode: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Get label
	 **/
	virtual CATUnicodeString GetLabel( void ) = 0;
	/**
	 * Get Icon
	 **/
	virtual CATUnicodeString GetIcon( void ) = 0;
	/**
	 * Get Icon
	 **/
	virtual int GetIconMask( int iIndex, CATUnicodeString &oMask, int &oX, int &oY ) = 0;
	/**
	 * Return node style.
	 * Use the CATTreeNodeStyleXXX constants to define node style
	 **/
	virtual int GetStyle( void ) = 0;
};

CATDeclareHandler(CATIViewModelNode, CATBaseUnknown);

#endif
