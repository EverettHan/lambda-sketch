#ifndef CATDisconnect_h
#define CATDisconnect_h

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "BO0CELLS.h"
#include "ListPOfCATCell.h"

class CATInter;
class CATBody;
class CATCell;
class CATGeometry;


// 
// Disconnect d'une cellule par des coupantes
// iBody     est un CATBody de travail
// iGeometry est la geometrie support de la cellule a decouper (surface)
// iCells    est la liste des cellules coupantes
// iSides    est un tableau de cotes matieres connus ou non
// oCells    est la liste des cellules issues de la decoupe
//
ExportedByBO0CELLS 
void Disconnect (CATBody *iBidy, CATGeometry *iGeometry, 
                 const ListPOfCATCell&iCells, CATSide*iSides, 
                 ListPOfCATCell&oCells);

//
// Fonction de disconnect appelee par le booleen cellulaire
//
ExportedByBO0CELLS
void Disconnect (CATInter * inter, CATBody * bodyA, CATBody * bodyB, CATBody * bodyAB,
                 ListPOfCATCell & oCellsFromAout,
                 ListPOfCATCell & oCellsFromBout,
                 ListPOfCATCell & oCellsFromAin,
                 ListPOfCATCell & oCellsFromBin);

//
// Ancienne fonction de disconnect appelee par le booleen cellulaire
//
ExportedByBO0CELLS
void Disconnect (CATInter * inter, CATBody * bodyA, CATBody * bodyB, CATBody * bodyAB,
                 ListPOfCATCell & oCellsFromAout,
                 ListPOfCATCell & oCellsFromBout,
                 ListPOfCATCell & oCellsFromAB);


#endif
