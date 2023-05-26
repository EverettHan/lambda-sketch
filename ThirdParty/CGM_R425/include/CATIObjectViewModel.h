// COPYRIGHT Dassault Systemes 2004
#ifndef CATIObjectViewModel_H
#define CATIObjectViewModel_H

#include <CATAfrItf.h>
#include <CATBaseUnknown.h>
#include <CATUnicodeString.h>
#include <CATLISTV_CATBaseUnknown.h>
typedef  CATLISTV(CATBaseUnknown_var)  CATListOfCATBaseUnknown_var; 

extern ExportedByCATAfrItf IID IID_CATIObjectViewModel;

/*
 * Items style constants
 */
// SCA : Modification des valeurs de style
//       Il y en a partout, c'est n'importe quoi !
//       voir CATIObjectViewModel.h
//       voir CATListViewSort.h
//       voir CATIListViewModel.h
//       Donc regroupement dans CATViewUtility.h de tous les styles.
// #define CATObjectViewStyleNormal	0x0000
// #define CATObjectViewStyleRightJustify	0x0100
// #define CATObjectViewStyleCenterJustify	0x0010
#include <CATViewUtility.h>

/**
 * CATIObjectViewModel. Interface to display a multiple property object (ex: a list item where columns are properties)
 **/
class ExportedByCATAfrItf CATIObjectViewModel: public CATBaseUnknown
{
	CATDeclareInterface;
public:
	/**
	 * Get property label for item iItem
	 **/
	virtual CATUnicodeString GetLabel( CATBaseUnknown_var iItem, const CATString &iPropertyID ) = 0;
	/**
	 * Get property Icon for item iItem
	 **/
	virtual CATUnicodeString GetIcon( CATBaseUnknown_var iItem, const CATString &iPropertyID ) = 0;
	/**
	 * Return property style.
	 * Use the CATObjectViewStyleXXX constants to define item style
	 **/
	virtual int GetStyle( CATBaseUnknown_var iItem, const CATString &iPropertyID ) = 0;
};

CATDeclareHandler( CATIObjectViewModel, CATBaseUnknown );

#endif
