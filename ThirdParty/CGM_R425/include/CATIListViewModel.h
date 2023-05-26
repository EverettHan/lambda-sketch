// COPYRIGHT Dassault Systemes 2004
#ifndef CATIListViewModel_H
#define CATIListViewModel_H

#include <CATViewItf.h>
#include <CATIObjectViewModel.h>
#include <CATUnicodeString.h>
#include <CATLISTV_CATBaseUnknown.h>
typedef  CATLISTV(CATBaseUnknown_var)  CATListOfCATBaseUnknown_var;

extern ExportedByCATViewItf IID IID_CATIListViewModel;

/*
 * Items style constants
 */
// SCA : Modification des valeurs de style
//       Il y en a partout, c'est n'importe quoi !
//       voir CATIObjectViewModel.h
//       voir CATListViewSort.h
//       voir CATIListViewModel.h
//       Donc regroupement dans CATViewUtility.h de tous les styles.
// #define CATViewItemStyleNormal	(1 << 0) // Standard cell look (1 << 2)
// #define CATViewItemStyleOK	 	(1 << 1) // Green cell
// #define CATViewItemStyleKO		(1 << 2) // Red cell
// #define CATViewItemStyleWarning	(1 << 3) // Orange cell
// #define CATViewItemStyleCustom	(1 << 4) // Orange cell
// #define CATViewItemStyleColor	(1 << 5) // Custom cell
#include <CATViewUtility.h>

/**
 * CATIListViewModel. Interface to display a model in a list view.
 **/
class ExportedByCATViewItf CATIListViewModel: public CATIObjectViewModel
{
   CATDeclareInterface;
public:
   /**
    * Get item count
    * iNode is the parent object with focus in the view.
    **/
   virtual int GetItemCount( CATBaseUnknown_var iNode ) = 0;
   /**
    * Get list of items, starting from item iStart, getting iCount items
    * iNode is the parent object with focus in the view.
    * iStart is 0 for first item.
    **/
   virtual void GetItems( CATBaseUnknown_var iNode, int iStart, int iCount, CATListOfCATBaseUnknown_var &oNodes ) = 0;
   /**
    * Sort definition changed
    **/
   virtual void Sort( const CATString &iColumn, int iReverse ) = 0;
};

CATDeclareHandler( CATIListViewModel, CATIObjectViewModel );

#endif
