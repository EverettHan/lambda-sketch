#pragma once

// Comparator based on the cellTag
// useful for set of cell for stability

// Polyhedral Objects
#include "CATPolyCell.h"

class CATCellTagComparator
{
public:

  unsigned int Hash(const CATPolyCell * cell) const
  {
    return cell ? cell->GetCellTag() : 0;
  }

  int Compare(const CATPolyCell * cell0, const CATPolyCell * cell1) const
  {
    unsigned int cellTag[2] = { cell0 ? cell0->GetCellTag() : 0, cell1 ? cell1->GetCellTag() : 0 };
    return cellTag[0] - cellTag[1]; // -1 if cellTag[0]<cellTag[1], 1 if cellTag[0]>cellTag[1], 0 otherwise.
  }

  bool Equal(const CATPolyCell * cell0, const CATPolyCell * cell1) const
  {
    unsigned int cellTag[2] = { cell0 ? cell0->GetCellTag() : 0, cell1 ? cell1->GetCellTag() : 0 };
    return cellTag[0] == cellTag[1];
  }

  bool operator () (const CATPolyCell * cell0, const CATPolyCell * cell1) const
  {
    unsigned int cellTag[2] = { cell0 ? cell0->GetCellTag() : 0, cell1 ? cell1->GetCellTag() : 0 };
    return cellTag[0] < cellTag[1];
  }
};
