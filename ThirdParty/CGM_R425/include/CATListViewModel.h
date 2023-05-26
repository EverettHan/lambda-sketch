// COPYRIGHT Dassault Systemes 2004
#ifndef CATListViewModel_H
#define CATListViewModel_H

#include <CATView.h>
#include <CATViewModel.h>
#include <CATIListViewModel.h>

/**
 * Base class for list model.
 **/
class ExportedByCATView CATListViewModel: public CATViewModel
{
   CATDeclareClass;
public:
   /**
    * Constructor
    **/
   CATListViewModel( void );
   /**
    * Destructor
    **/
   virtual ~CATListViewModel( void );
   /**
    * Get item count
    * iNode is the parent object with focus in the view.
    **/
   virtual int GetItemCount( CATBaseUnknown_var iNode ) = 0;
   /**
    * Get list of items, starting from item iStart, getting iCount items
    * iNode is the parent object with focus in the view.
    **/
   virtual void GetItems( CATBaseUnknown_var iNode, int iStart, int iCount, CATListOfCATBaseUnknown_var &oNodes ) = 0;
   /**
    * Get column content for item iItem
    **/
   virtual CATUnicodeString GetLabel( CATBaseUnknown_var iItem, const CATString &iColumnID ) = 0;
   /**
    * Get Icon
    **/
   virtual CATUnicodeString GetIcon( CATBaseUnknown_var iItem, const CATString &iColumnID ) { return ""; };
   /**
    * Return node style.
    * Use the CATViewItemStyleXXX constants to define item style
    **/
   virtual int GetStyle( CATBaseUnknown_var iItem, const CATString &iColumnID ) { return CATViewItemStyleNormal; };
   /**
    * Sort definition changed
    **/
   virtual void Sort( const CATString &iColumn, int iReverse ) {};

   /**
    * Remove an item from the model.
    */
   virtual void RemoveItem( CATBaseUnknown_var iNode ) {};

};

#endif
