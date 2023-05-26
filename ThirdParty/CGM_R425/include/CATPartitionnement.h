#ifndef CATPartitionnement_h
#define CATPartitionnement_h

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "BO0CELLS.h"
#include "CATCell.h"
#include "CATListOfCATCells.h"

class CATBody;

void ExportedByBO0CELLS CATPartitionnement(CATBody * iBody, CATCell * iOldCellA, CATCell * iOldCellB,
                                           const ListPOfCATCell& BndgCells, CATSide * iSides,
                                           ListPOfCATCell & oNewCellsA, ListPOfCATCell & oNewCellsB);

#endif
