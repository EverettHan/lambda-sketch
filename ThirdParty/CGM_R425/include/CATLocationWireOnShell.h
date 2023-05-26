/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
// CATLocationWireOnShell:
//
// Operator returns the location of a CATWire on a CATShell. User can scan the
// wire and get the cell of the shell where the edge is lying on. Operator also
// gives the cell where every bounding vertex is lying on.
//
//=============================================================================
// WARNING: Operator was early designed to be used with CATWire that were not
//          granted with IsLyingOn() capacity. Nevertheless, it supports both cases.
//=============================================================================
// Usage notes:
// ------------
//            CATLocationWireOnShell MyService(factory, ...); 
//            if ( MyService.Run() )
//            {
//              CATVertex *StartVertex,
//                        *EndVertex;
//              CATCell   *StartVertexSupport,
//                        *EndVertexSupport;
//              CATCell   *EdgeOfWire = NULL;
//              while ( EdgeOfWire=MyService.Next(EdgeOfWire) )
//              {
//                MyService.GetResult(&EdgeSupport,
//                                    &StartVertex,
//                                    &StartVertexSupport,
//                                    &EndVertex,
//                                    &EndVertexSupport);
//                 ...
//              }
//            }
//=============================================================================
// HISTORIC
//  Nov. 98 LMH Creation                                                L. Mahe
//  Mar. 99 LMH Modification : IsInFace() pour TPG
//  Apr. 99 LMH Modification : Call to SplitEdge()
//  Jul. 99 LMH Modification : IsLyingOn integration
// 20/03/00 ALM Gestion des wires avec edges degenerees dans les wires, quand 
//              cela est demande par l'appelant
// 17/11/00 NLD Ajout constructeur avec iTopData
// 21/03/02 NLD Ajout IgnoreOutsidePart()
// 01/10/03 NLD Ajout IsValid()
// 29/11/06 NLD Ajout argument ioNewGeometryToDelete à DuplicateEdge()
// 30/06/09 NLD Ajout RunOperator()
// 09/09/09 NLD IsInFace() recoit iIgnoreOutsideParts au lieu d'attaquer _IgnoreOutsideParts
//              Ajout _CGMLevel
// 07/07/11 NLD Ajout _OperatorId, GetOperatorId(), GetDefaultOperatorId()
// 25/04/14 NLD IsEdgeIsDrownedInEdge() est enfin renommee IsEdgeDrownedInEdge()
//              Smart indent
//              Ajout _OLKCounts
// 05/11/15 NLD Ajout SplitEdgeSecured()
// 08/11/15 NLD Ajouts pour CGMReplay
//              IsRecordable()
//              RequireDefinitionOfInputAndOutputObjects()
//              WriteInput()
//              Dump()
//              DumpOutput()
// 13/11/15 NLD GetDefaultOperatorId() devient static (pour standard d'activation d'enregistrement CGMReplay)
//=============================================================================

//============================================================================= 
// ALGO OPTIONS
//============================================================================= 

//============================================================================= 
// DEFINES
#ifndef CATLocationWireOnShell_h
#define CATLocationWireOnShell_h

#include "AnalysisToolsLight.h"

#include "CATLocationTopology.h"
#include "CATString.h"
#include "ListPOfCATVertex.h"


//=============================================================================

//-----------------------------------------------------------------------------
class ExportedByAnalysisToolsLight CATLocationWireOnShell : public CATLocationTopology
{
  public :
    //-------------------------------------------------------------------------
    // Constructor/Destructor
    //-------------------------------------------------------------------------
    CATLocationWireOnShell               (CATGeoFactory         *  Factory             ,
                                          CATTopData            *  iTopData            ,
                                    const CATBody               *  BodyWire            ,
                                          CATWire               *  Wire                ,
                                    const CATBody               *  BodyShell           ,
                                          CATShell              *  Shell               ,
                                          CATLONG32                iDegeneratedEdgesManagement = 0);
    ~CATLocationWireOnShell();

    //-------------------------------------------------------------------------
    // Run and Result Access
    //-------------------------------------------------------------------------
    // restricted use; ignore edge parts outside the face,
    //                 if some parts are inside or on the border.
    // dangerous;      not all outputs by GetResult guaranteed
          void       IgnoreOutsidePart   ();
    

          int        Run                 (); // Returns 1 if computation is successfull, 0 if not.

          int        RunOperator         (); // Returns 1 if computation is successfull, 0 if not.

          // Boucle sur les edges du wire  en entree (mettre iEdge a NULL au premier appel)
          CATEdge  * Next                (CATEdge               *  iEdge               = NULL,
                                          CATOrientation        *  oOrient             = NULL);

          // Obtention du resultat associe a l'edge courante du wire en entree
          // (voir Usage notes ci-dessus)
          // Les pointeurs non nuls en entree indiquent les resultats que l'on veut obtenir
          // ex:     GetResult(&CellSupport); // pour avoir seulement la cellule support
          void       GetResult           (CATCell              **  oCellSupport        ,
                                          CATVertex            **  oStartVertex        = NULL,
                                          CATCell              **  oStartVertexSupport = NULL,
                                          CATVertex            **  oEndVertex          = NULL,
                                          CATCell              **  oEndVertexSupport   = NULL);

       const CATString* GetOperatorId       ();
static const CATString* GetDefaultOperatorId();

  private:


    // Internal Methods

    // Indique si un objet géométrique est valide (pointeur vers élément non effacé)

          int        IsValid             (CATICGMObject         *  iGeom               );

          int        IsInFace            (CATEdge               *  iEdge               ,
                                          CATPCurve             *  iPCurve             ,
                                          CATFace               *  iFace               ,
                                          int                      iIgnoreOutsidePart  );

          void       FindFaceInShell     (CATEdge               *  iEdge               ,
                                          CATFace               *& oFaceSupport        ,
                                          CATPCurve             *& oPCurveTested       );

          void       FindEdgeInFace      (CATEdge               *  iEdge               ,
                                          CATPCurve             *  iPcurve             ,
                                          CATFace               *  iFaceSupport        ,
                                          CATEdge               *& oEdgeSupport        );

          int        GetBoundarySupport  (CATEdge               *  iEdge               ,
                                          CATCell               *& oCell1              ,
                                          CATCell               *& oCell2              );

          void       GetVertexSupport    (CATVertex             *  iVertex             ,
                                          CATCell               *& oCell               );

          int        IsEdgeDrownedInEdge (CATEdge               *  iEdge1              ,
                                          CATPCurve             *  iPcurve1            ,
                                          CATEdge               *  iEdge2              ,
                                          CATPCurve             *  iPcurve2            );

          CATEdge  * DuplicateEdge       (CATEdge               *  iEdge               ,
                                          CATPCurve             *  iPCurve             ,
                                          CATBody               *  iBody               ,
                                          CATLISTP(CATGeometry)  & ioNewGeometryToDelete);

          CATEdge ** SplitEdgeSecured    (CATTopData            *  iTopData            ,
                                          CATBody               *  iBody               ,
                                          CATEdge               *  iCutEdge            ,
                                          CATFace               *  iSplittingFace      ,
                                          int                    & oNbEdges            ,
                                          CATLocation          **  oLocations          ,
                                          CATError              *& oError              );

          // Ajouts pour CGMReplay NLD091115
          // mais cela ne saurait convenir sans modification de la classe mere CATLocationTopology
          CATExtCGMReplay* IsRecordable  (short                  & LevelOfRuntime      ,
                                          short                  & VersionOfStream     );
          void       RequireDefinitionOfInputAndOutputObjects();

          void       WriteInput          (CATCGMStream           & Str                 );
                                          
          void       Dump                (CATCGMOutput           & os                  );
          void       DumpOutput          (CATCGMOutput           & os                  );

    // Private Data
    static CATString       _OperatorId;

    CATBoolean             _IgnoreOutsidePart;
    int                    _CGMLevel;
    CATLISTP(CATCell)      _CellSupport;
    CATLISTP(CATVertex)    _StartVertex;
    CATLISTP(CATCell)      _StartVertexSupport;
    CATLISTP(CATVertex)    _EndVertex;
    CATLISTP(CATCell)      _EndVertexSupport;
    int                    _OLKCounts[2];
};
#endif










