#ifndef CATlsoXTrimMultimap_H
#define CATlsoXTrimMultimap_H

// ++++ Includes ++++
#include "AdvTrimOpe.h"
#include "CATCGMNewArray.h"
#include "ListPOfCATCell.h"
#include "CATCGMHashTableWithAssoc.h"
#include "CATMathInline.h"

// ++++ Predeclarations ++++
class CATCell;

//=============================================================================
// CATlsoXTrimMultimap
// 
// responsable: ZUT
// Multimap (CATCell - ListPOfCATCell)
//=============================================================================

class ExportedByAdvTrimOpe CATlsoXTrimMultimap
{
public:
  //---------------------------------------------------------------------------
  // CONSTRUCTEUR(S) / DESTRUCTEUR
  //---------------------------------------------------------------------------
  CATlsoXTrimMultimap();

  virtual ~CATlsoXTrimMultimap();

  // Surcharge du new / delete
  CATCGMNewClassArrayDeclare;

  //---------------------------------------------------------------------------
  // METHODES NON-INLINE
  //---------------------------------------------------------------------------

  int       Insert( CATCell * iCell, CATCell * iAssocCell );

  int       InsertReturnPos( CATCell * iCell, CATCell * iAssocCell );


  int       LocateCell( CATCell * iCell ) const;

  int       LocateCell( CATCell * iCell, CATLISTP(CATCell) & oAssocCells ) const;

  int       LocateCellAndAssoc( CATCell * iCell, CATCell * iAssocCell ) const;

  int       RemoveCell( CATCell * iCell );

  int       RemoveAssoc( CATCell * iCell, CATCell * iAssocCell );


  void      SetCell( int iPos, CATCell * iCell );

  void      InsertAssoc( int iPos, CATCell * iAssocCell );

  void      RemoveAssoc( int iPos, CATCell * iAssocCell );

  CATCell * GetCell( int iPos ) const;

  void      GetAssoc( int iPos, CATLISTP(CATCell) & oAssocCells ) const;

  CATCell * GetCellAndAssoc( int iPos, CATLISTP(CATCell) & oAssocCells ) const;


  void      RemoveAll();

  //---------------------------------------------------------------------------
  // METHODES INLINE
  //---------------------------------------------------------------------------

  int       Size() const;

private:
  //---------------------------------------------------------------------------
  // METHODES PRIVEES
  //---------------------------------------------------------------------------
  void Clean();

  //------------------------------------------------------------------------------
  // Forbidden (Declared but not Defined) : Copy constructor & assignment operator
  //------------------------------------------------------------------------------
  CATlsoXTrimMultimap ( const CATlsoXTrimMultimap & );            // Not Implemented
  CATlsoXTrimMultimap & operator=( const CATlsoXTrimMultimap & ); // Not Implemented

  //---------------------------------------------------------------------------
  // DONNEES MEMBRES
  //---------------------------------------------------------------------------
  CATCGMHashTableWithAssoc _HTWithAssoc;
};

//-----------------------------------------------------------------------------
// IMPLEMENTATION METHODES INLINE
//-----------------------------------------------------------------------------

INLINE int CATlsoXTrimMultimap::Size() const {
  return _HTWithAssoc.Size(); }

#endif /* CATlsoXTrimMultimap_H */
