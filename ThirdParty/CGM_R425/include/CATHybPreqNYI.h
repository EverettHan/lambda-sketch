/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1996
//------------------------------------------------------------------------------
// CATHybPreqNYI : Prereq Not Yet Implemented
//      
//------------------------------------------------------------------------------
// Usage Notes: devrait disparaitre
//------------------------------------------------------------------------------
//      /99 LMH Creation
// 11/07/17 NLD Mise au propre. Smart indent
//------------------------------------------------------------------------------
#ifndef CATHybPreqNYI_h
#define CATHybPreqNYI_h

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
#include "CATHybDef.h"
#include "CATCell.h"
#include "CATCellHashTable.h" // tbd class

class CATEdgeCurve;
class CATMergedCurve;
class CATSoftwareConfiguration;

//class CATCellHashTable;
//------------------------------------------------------------------------------
//
// Fonctions Utilitaires a virer
//
//------------------------------------------------------------------------------
enum CATHybAttribType{ Vertex = 481860,
                       Edge   = 481861,
                       Face   = 481862,
                       Cell   = 481863,
                       Part   = 481864 };

//------------------------------------------------------------------------------

CATPointOnEdgeCurve* BuildPOEC                (      CATGeoFactory           * factory         ,
                                                     CATEdgeCurve            * mCrv            ,
                                                     CATPointOnEdgeCurve     * poec1           ,
                                                     CATPointOnEdgeCurve     * poec2           );

//------------------------------------------------------------------------------
// Utilitaires
// liste des cellules de meme dimension liees a une cellule dans body 
CATCellHashTable   * CreateLinkedIsoCellsTable(      CATGeoFactory           * iFactory         ,
                                                     CATSoftwareConfiguration* iConfig          ,
                                                     CATBody                 * body             ,
                                                     CATCell                 * cell             );

ExportedByPBELight
int               SortLinkedEdgesTable        (      CATBody                 *  body            ,
                                                     CATCellHashTable        *  isoList         ,
                                                     CATEdge                **& newlist         ,
                                                     CATOrientation           & StartOrientation);

ExportedByPBELight 
CATCell*          GetSafeNeighborCell         (      CATCell                 *  curr            ,
                                                     CATCell                 *  brd             ,
                                                     CATBody                 *  body            );
 
CATBoolean        AreConfused                 (      CATGeoFactory           *  iFactory        ,
                                                     CATSoftwareConfiguration*  iConfig         ,
                                                     double                     tol             ,
                                                     CATPointOnCurve         *  p1              ,
                                                     CATPointOnCurve         *  p2              );

//-----------------------------------------------------------------------------
//  Tests if Wire remains manifold when iToConnect is inserted
//        after iLast
//        Returns -2 if Edges are superimposed
//  Returns -1 if Edges are intersected
//        Returns 1 if iToConnect can be inserted
//-----------------------------------------------------------------------------
int               IsConfusedInAssembly        (      CATGeoFactory           *  iFactory        ,
                                                     CATSoftwareConfiguration*  iConfig         ,
                                                     CATCell                 *  iLast           ,
                                                     CATCell                 *  iToConnect      );

//------------------------------------------------------------------------------
#endif
