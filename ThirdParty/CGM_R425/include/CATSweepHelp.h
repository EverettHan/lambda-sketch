#ifndef CATSWEEPHELP_H
#define CATSWEEPHELP_H

// COPYRIGHT DASSAULT SYSTEMES 1999
//
//
//--------------------------------------------------------------------------
// 08 12 09 NLD Definition d'une nomenclature pour les classes utilitaires du sweep, la plupart exportees
//              SpecCell  devient CATSweepSpecCell
//              Tableau   devient CATSweepArrayOfSpecCell
//              Spec      devient CATSweepSpec
//              Brep      devient CATSweepBRep
//              BrepCell  devient CATSweepBRepCell
//              Journal   devient CATSweepJournal
//              Ajout SetBCellToRemove() et _BCellToRemove dans CATSweepBRepCell
// 21 10 10 NLD CATSweepArrayOfSpecCell devient une classe et non plus une structure
//              NbCell y devient _NbCell et Cell y devient _Cell
//              La destruction du tableau et des ses elements est assurée par son destructeur
//              Ajout StoreSpecCell() pour stockage des cellules
//              Ajout LocateSpecFromCell() pour localisation de cellule
//              Optimisation des recherches dans LocateSpecFromCell() par usage d'une HashTable
//              (pour Sweep123 Case1235)
// 03 03 11 DLP Allow slightly different implementations of IsFree in CATSweepSpecCell (IR 073580).
// 09 01 18 NLD Mise au propre. Smart indent
//--------------------------------------------------------------------------

#include <CATIACGMLevel.h>
#include <CATCGMDebugSwitchNLD.h> // A faire avant toutes choses

#ifndef CATCGMDebugSwitchNLD_ForceShuntOldPerfo
#define CATSweepHelp_OptimArray "NLD211010"
#endif

#include "BO0SWEEPLight.h"
#include "CATDataType.h"
#include "CATMathDef.h"
class CATBody;
class CATCell;
class CATGeometry;
class CATSweepGeo2;
class CATSweepSpec;
class CATCGMJournalList;
class CATTopData;
class CATSweepBRep;
#include "CATListOfCATGeometries.h"


                                       #ifdef CATSweepHelp_OptimArray
#include <CATCGMHashTable.h>
#endif
//--------------------------------------------------------------------------
// classe des cellules de specs
// ---------------------------
//--------------------------------------------------------------------------
class ExportedByBO0SWEEPLight CATSweepSpecCell
{
  public :

  friend class CATSweepArrayOfSpecCell;


                             CATSweepSpecCell           (CATCell          * iCell        ,
                                                         CATLONG32          iNum         );
                            ~CATSweepSpecCell           ();

          CATCell          * GetCell                    ();

          CATLONG32          GetNum                     ();

  virtual CATLONG32          IsFree                     (CATSweepSpec     * spec         ) = 0;

          CATLONG32          IsFreeCommon               (CATSweepSpec     * spec         ,
                                                         CATBoolean         iSurfacicMode);

  static CATSweepSpecCell  * CreateCATSweepSpecCell     (CATCell          * iCell        ,
                                                         CATLONG32          iNum         ,
                                                         CATBoolean         iSurfacicMode);
  protected :
  CATLONG32  _Num;
  CATCell  * _Cell;
  CATLONG32  _Free;
};

//--------------------------------------------------------------------------
class CATSweepSpecCellManifold : public CATSweepSpecCell
{
public :
                             CATSweepSpecCellManifold   (CATCell          * iCell        ,
                                                         CATLONG32          iNum         );

  virtual CATLONG32          IsFree                     (CATSweepSpec     * spec         );
};

//--------------------------------------------------------------------------
class CATSweepSpecCellNonManifold : public CATSweepSpecCell
{
public :
                             CATSweepSpecCellNonManifold(CATCell          * iCell        ,
                                                         CATLONG32          iNum         );

  virtual CATLONG32          IsFree                     (CATSweepSpec     * spec         );
};

//--------------------------------------------------------------------------
// classe des specs
// ----------------
//--------------------------------------------------------------------------
class /*ExportedByBO0SWEEPLight*/ CATSweepArrayOfSpecCell
{

 public:

 CATLONG32            _NbCell;
 int                  _DeleteAtEnd;

 protected:
 CATSweepSpecCell  ** _Cell;
                                       #ifdef CATSweepHelp_OptimArray
 CATCGMHashTable      _HashTableCell;
 int                  _UseHashTable;
                                       #endif

 public:
 //--------------------------------------------
 CATSweepArrayOfSpecCell()
   {
    _NbCell       = 0;
    _Cell         = NULL;
    _DeleteAtEnd  = 1;
                                       #ifdef CATSweepHelp_OptimArray
    _UseHashTable = 1;
                                       #endif
   }
 //--------------------------------------------
 void StoreSpecCell(CATLONG32          iNbCell,
                    CATSweepSpecCell** iCell  )
   {
    _NbCell       = iNbCell;
    _Cell         = iCell;
                                       #ifdef CATSweepHelp_OptimArray
    _HashTableCell.RemoveAll();
    for (int i = 0; i < _NbCell && _UseHashTable; i++)
      {
       if (_Cell[i])
          _HashTableCell.Insert(_Cell[i]->_Cell);
       else
         {
          // il faudrait sortir en erreur
          _UseHashTable = 0;
         }
      }
                                       #endif
   }
 //--------------------------------------------
 inline CATSweepSpecCell* GetSpecCell(int iIndexCell)
   {
    if ((iIndexCell >= 0) && (iIndexCell < _NbCell))
       return _Cell[iIndexCell];
    else
       return NULL;
   }
 //--------------------------------------------
 // rend la position de la Spec associée à une cellule;
 // (index de 0 à _NbCell-1, negatif si non trouvée)
 //--------------------------------------------
 CATLONG32 LocateSpecFromCell(CATCell * iCell)
   {
    CATLONG32 i;
                                       #ifdef CATSweepHelp_OptimArray
    if (_UseHashTable)
      {
       i = _HashTableCell.LocateReturnPos(iCell);// rend bien une position negative si non trouvé
       return i;
      }
                                       #endif
    // Recherche manuelle
    i = 0;
    while (i < _NbCell)
      {
       if (_Cell[i]->GetCell() == iCell )
          return i;
       i++;
      }
    return -1;
   }

 //--------------------------------------------
 ~CATSweepArrayOfSpecCell()
   {
    if (_DeleteAtEnd)
      {
       for ( int icell = 0; icell< _NbCell; icell++ )
           delete _Cell[icell];
       if ( _Cell )
          delete [] _Cell;
      }
    _Cell = NULL;
    _NbCell = 0;
  }
};


//--------------------------------------------------------------------------
// Anciennement
//--------------------------------------------------------------------------
#ifdef CATSweepHelp_OldCATSweepArrayOfSpecCell
struct /*ExportedByBO0SWEEPLight*/ CATSweepArrayOfSpecCell
{
   CATLONG32            _NbCell;
   CATSweepSpecCell  ** _Cell;
};
#endif



//--------------------------------------------------------------------------
class ExportedByBO0SWEEPLight CATSweepSpec
{
  public :
                             CATSweepSpec               (CATBody          * iBody        ,
                                                         CATBoolean         iSurfacicMode,
                                                         CATLONG32          iMode        = 0);
                            ~CATSweepSpec               ();

          CATBody          * GetBody                    ()                                  const;

          CATLONG32          GetNbOfCell                (CATLONG32          iDim         );

          CATSweepSpecCell * GetSpecCell                (CATCell          * iCell        );

          CATSweepSpecCell * GetSpecCell                (CATLONG32          iDim         ,
                                                         CATLONG32          iIndexCell   );

 protected :
  CATSweepArrayOfSpecCell   _Cellule [4];
  CATBody                *  _MyBody;
};



//--------------------------------------------------------------------------
// classe des cellules du Brep
//----------------------------
//--------------------------------------------------------------------------
class ExportedByBO0SWEEPLight CATSweepBRepCell
{
   public :
                             CATSweepBRepCell           (CATSweepSpecCell * iCntSpec     ,
                                                         CATSweepSpecCell * iProfSpec    ,
                                                         CATSweepBRep     * iBrep        );

                            ~CATSweepBRepCell           ();

          void               SetBCell                   (CATCell          * iBCell       );

          void               SetBCellToRemove           (int                iToRemove    );

          void               SetExtrude                 (CATSweepGeo2     * Extrude      );

          CATSweepGeo2     * GetExtrude                 ();

          CATCell          * GetBCell                   ();

          CATSweepSpecCell * GetProfSpec                ();

          CATSweepSpecCell * GetCntSpec                 ();

   protected :
   CATSweepBRep       * _Brep;
   CATCell            * _BCell;
   CATSweepSpecCell   * _ProfSpec;
   CATSweepSpecCell   * _CntSpec;
   CATSweepGeo2       * _Extrude;
   int                  _BCellToRemove;
};
#define CATSweepBrepCell CATSweepBRepCell


//--------------------------------------------------------------------------
// classe des Breps
//-----------------
//--------------------------------------------------------------------------
class ExportedByBO0SWEEPLight CATSweepBRep
{
  public :
                             CATSweepBRep               (CATLONG32          iNCntCell    ,
                                                         CATLONG32          iNProfCell   );
                            ~CATSweepBRep ();

          CATSweepBRepCell * SearchBrepCell             (CATCell          * iBCell       );

          CATLONG32          GetNbOfCell                ();

          CATSweepBRepCell * GetBCell                   (CATSweepSpecCell * iCntSpec     ,
                                                         CATSweepSpecCell * iProfSpec    );

          CATSweepBRepCell * GetBCell                   (CATLONG32          iNCell       );

          CATLONG32          GetKey                     ();

  protected :
  CATLONG32           _NCntCell;
  CATLONG32           _NProfCell;
  CATLONG32           _NCntProfCell;
  CATLONG32           _BRepKey;
  CATSweepBRepCell ** _Cell;
};
#define CATSweepBrep CATSweepBRep
//
//
//
// classe des journaux
// -------------------
//
class ExportedByBO0SWEEPLight CATSweepJournal
{
  public :
                             CATSweepJournal            (CATTopData       * iData        );

                            ~CATSweepJournal            ();

          void               AddCenterVertex            (int                iExt         ,
                                                         CATCell          * iCntCell     );

          void               AddCenterEdge              (int                iExt         ,
                                                         CATCell          * iCntCell     );

          void               AddCenterEdge              (CATCell          * iCntCell     );

          void               AddItem                    (CATCell          * iCntCell     ,
                                                         CATCell          * iProfCell    ,
                                                         CATCell          * iBCell       );

          void               AddCreation                (CATGeometry      * iInitGeo     ,
                                                         CATGeometry      * iGenGeo      );

          CATCGMJournalList* GetReport ();
//  void Dump ();

  protected :
  CATCGMJournalList        * _InitReport;
  CATCGMJournalList        * _Report;
  CATLISTP (CATGeometry)   * _input;
  CATLISTP (CATGeometry)   * _output;
};

//==========================================================================
// inline
//==========================================================================
// CATSweepBRepCell
//==========================================================================
inline CATSweepGeo2 *     CATSweepBRepCell::GetExtrude()
{
 return _Extrude;
}

//--------------------------------------------------------------------------
inline void               CATSweepBRepCell::SetExtrude (CATSweepGeo2 * iExtrude)
{
 _Extrude = iExtrude;
}

//--------------------------------------------------------------------------
inline CATSweepSpecCell * CATSweepBRepCell::GetProfSpec ()
{
 return _ProfSpec;
}

//--------------------------------------------------------------------------
inline CATSweepSpecCell * CATSweepBRepCell::GetCntSpec ()
{
 return _CntSpec;
}


//==========================================================================
// CATSweepBRep
//==========================================================================
inline CATLONG32          CATSweepBRep::GetNbOfCell ()
{
 return _NProfCell*_NCntCell;
}

//--------------------------------------------------------------------------
inline CATSweepBRepCell * CATSweepBRep::GetBCell (CATLONG32 iNCell)
{
 return _Cell[iNCell];
}


//--------------------------------------------------------------------------
inline CATLONG32          CATSweepBRep::GetKey ()
{
 return _BRepKey;
}

//==========================================================================
// CATSweepSpecCell
//==========================================================================
inline CATCell * CATSweepSpecCell::GetCell ()
{
 return _Cell;
}

//--------------------------------------------------------------------------
inline CATLONG32 CATSweepSpecCell::GetNum ()
{
 return _Num;
}

//==========================================================================
// CATSweepSpec
//==========================================================================
inline CATLONG32      CATSweepSpec::GetNbOfCell (CATLONG32 iDim)
{
 return  _Cellule[iDim]._NbCell;
}

//--------------------------------------------------------------------------
inline CATBody *      CATSweepSpec::GetBody() const
{
 return _MyBody;
}
//-----------------------------------------------------------------------------

#endif
