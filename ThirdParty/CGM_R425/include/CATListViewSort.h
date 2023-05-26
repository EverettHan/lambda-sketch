// -*-C++-*-
//=================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=================================================================
// VPM (c) Copyright Dassault Systemes 2005
//=================================================================
// Usage Notes:
//=================================================================
// History:
// March 05 - RHG - Creation
//=================================================================


#ifndef __CATListViewSort_h_
#define __CATListViewSort_h_

// =================================================================
// Includes
// =================================================================
#include <CATView.h>
#include <CATIListViewModel.h>
#include <CATIObjectViewModel.h>
#include <CATLISTV_CATBaseUnknown.h>
#include <CATTime.h>

//------------------------------------------------------------------

/*
 * Items style constants
 */
// SCA : Modification des valeurs de style
//       Il y en a partout, c'est n'importe quoi !
//       voir CATIObjectViewModel.h
//       voir CATListViewSort.h
//       Donc regroupement dans CATViewUtility.h de tous les styles.
// The format modifier for date (use with CATTime) is %x
// #define CATObjectViewStyleDate   (1 << 7)
// Alphabetic sorting
// #define CATObjectViewStyleString (1 << 8)
// Use with numerical data. Numbers cannot be sorted like strings (ex. 1,10,11,12,2,20,3,4,5,55,6..)
// #define CATObjectViewStyleNumber (1 << 9)
#include <CATViewUtility.h>

//------------------------------------------------------------------

class ExportedByCATView CATListViewSort
{
public:


   /**
   * NOTE: This method is usually called within the implementation of CATIListViewModel::Sort
   *
   * This method will allow all implementations of CATIListViewModel to be sorted based
   * on the CATIListViewModel which inherits from the CATIObjectViewModel. This sort
   * relies on the implementation of the following interface methods:
   *
   *        CATIListViewModel::GetItemCount --- helps determine how many objects to get
   *        CATIListViewModel::GetItems     --- returns the list of items to be sorted
   *        CATIObjectViewMode::GetStyle    --- helps determine what type of sort criteria to use (string, numeric, date, etc)
   *        CATIObjectViewModel::GetLabel   --- get the value for each of the items from CATIListViewModel::GetItems
   *
   * @param  iLVM
   *    The CATIListViewModel which needs to be sorted
   * @param  iColumnName
   *    The column or specific entity within each row of the list (this is used during the call to GetLabel)
   * @param  iFocus
   *    The focus which is used in calls to  CATIListViewModel::GetItemCount and CATIListViewModel::GetItems
   * @param  reverse
   *    Determines ascending or descending sort. 0 = ascending, 1 = descending
   * @param  oSortedList
   *    This will contain all CATIListViewModel::GetItems objects in a sorted order. It is up to the implementation
   *    of CATIListViewModel how it will be stored after it's returned.
   * @return
   *    Error code of function :
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd>operation is successfully.</dd>
   *     <dt>S_FALSE</dt>
   *    <dd>Not enough objects to sort.</dd>
   *    <dt>E_FAIL</dt>
   *    <dd>Invalid CATIListViewModel object.</dd>
   *   </dl>
   */
   static HRESULT Sort(CATIListViewModel_var & iLVM,
                  const CATString& iColumnName,
                  CATBaseUnknown_var &iFocus,
                  int reverse,
                  CATLISTV(CATBaseUnknown_var) &oSortedList);

   //Old method signature which uses NULL_var as the focus item, and redirects to the method signature above:
   //
   //
   static HRESULT Sort(CATIListViewModel_var & iLVM,
                  const CATString& iColumnName,
                  int reverse,
                  CATLISTV(CATBaseUnknown_var) &oSortedList);



   //Static variables used so that the compare methods have access to the model when comparing two items
   static CATString _ColumnName;
   static CATIObjectViewModel_var _OVM;
   /**
    * Convert a CATUnicodeString to a CATTime
    **/
   static CATTime ParseDate( const CATUnicodeString &iTime );
   static void GetLocalDate(int & dayPos, int & monthPos, int & yearPos );
   static int IsSeparator(CATUnicodeChar c) { return !c.IsAlpha() && !c.IsDigit(); }
   static int ConvertMonth(const CATUnicodeString &d);
};

#endif // __CATListViewSort_h_
