#ifndef CATDlgMultiListProtected_H
#define CATDlgMultiListProtected_H

#include "DI0PANV2.h"

class CATDlgMultiList;

/**
 * This class provides some useful API on CATDlgMultiList
 */
class ExportedByDI0PANV2 CATDlgMultiListProtected
{
public:
  /**
   * Get row index in original model from row index in sorted view
   * @param iMultiList the multilist object to work with
   * @param iSortedIndex the row index in sorted view
   * @return the row index in original model or -1 on error
   */
  static int GetOriginalRowIndex(CATDlgMultiList * iMultiList, int iSortedIndex);

  /**
   * Get row index in sorted view from row index in original model
   * @param iMultiList the multilist object to work with
   * @param iOriginalIndex the row index in original model
   * @return the row index in sorted view or -1 on error
   */
  static int GetSortedRowIndex(CATDlgMultiList * iMultiList, int iOriginalIndex);

  /**
   * Check if a cell is editable
   * @param iMultiList the multilist object to work with
   * @param iRow the row index
   * @param iColumn the column index
   * @return 1 if the cell is editable
   */
  static int IsCellEditable(CATDlgMultiList * iMultiList, int iRow, int iColumn);

  /**
   * Set the selected column, as returned by GetSelectedColumn (you should never have to use this method)
   * @param iMultiList the multilist object to work with
   * @param iColumn the last selected column
   */
  static void SetSelectedColumn(CATDlgMultiList * iMultiList, int iColumn);
};

#endif
