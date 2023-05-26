#ifndef CATDBLayoutGrid_H
#define CATDBLayoutGrid_H
// COPYRIGHT DASSAULT SYSTEMES 1997
//===========================================================================
//
// class CATDBLayoutGrid:
// Grid used for Layout management
//
//===========================================================================
//
// Usage Notes:
//
//===========================================================================
// Mar. 97   Creation                                   J. Faugeras
//===========================================================================

#include "DI0BUILD.h"

class CATDBContainer;

//---------------------------------------------------------------------------
class ExportedByDI0BUILD CATDBLayoutGrid
{
 public:

   CATDBLayoutGrid(int rowCount, int columnCount);
   CATDBLayoutGrid(const CATDBLayoutGrid & grid);
   ~CATDBLayoutGrid();

   int operator== (const CATDBLayoutGrid &) const;

   int GetRowCount ();
   int GetColumnCount ();
   int GetValue (int row, int column);
   void SetValue (int row, int column, int value);
   void Fill (CATDBContainer * box);
   void ExpandHorizontally (int NewColumn, int NumExpansion = 1);
   void ExpandVertically (int NewRow, int NumExpansion = 1);

   void Clean ();
   CATDBContainer * GetContainer();

 private:

   int * _Array;
   int _RowCount;
   int _ColumnCount;
   CATDBContainer *_AssociatedContainer;
};
#endif
