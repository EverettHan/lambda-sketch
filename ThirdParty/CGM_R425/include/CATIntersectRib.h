/* -*-C++-*- */

#ifndef CATIntersectRib_H
#define CATIntersectRib_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//------------------------------------------------------------------------------
//
// CATIntersectRib
// Operator : intersect a ribbon with something
//
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Usage notes:
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// November 1999    Creation                            F. Dujardin
//------------------------------------------------------------------------------
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATTopRibObject.h"
#include "CATTopRibDef.h"
#include "CATListOfInt.h"
#include "CATMathDef.h"
#include "CATTopRibNuplet.h"
#include "ListPOfCATSupContact.h"
#include "CATCGMNewArray.h"

#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h"

class CATTopRib;
class CATFace;
class CATEdge;
class CATVertex;
class CATTopRibMacroTool;

#include "CATSafe.h"
CATSafeDefine(CATIntersectRib);

class ExportedByRIBLight CATIntersectRib : public CATTopRibObject
{
 public:

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATIntersectRib(CATTopRib     * iRib,                            // Ruban
                  CATTopRibSign   iDir,                            // Direction de parcours du ruban 
                  int             iStart,                          // numero du Nuplet de depart      
                  int             iEnd,                            // Numero du Nuplet de fin 
                  int             iSupp,                           // Numero de support pour l'intersection 
                                                                   // aux resultats
                  CATTopRibSign   iPostDir=UnknownDirection);      // Direction a utiliser pour post-filtrer
                                                                   // les solutions sur le ruban

   
  CATCGMNewClassArrayDeclare;        // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  virtual ~CATIntersectRib();

  void SetVertexForSelection( CATVertex *iV );

  // -----------------------------------------------------------------------------     
  // Indique si l'on peut extrapoler les nuplets extremites (Non par defaut)
  // -----------------------------------------------------------------------------     
  void SetExtrapol(CATBoolean iExtrapol);

  // -----------------------------------------------------------------------------     
  // Indique si l'on recherche les solutions Out/Out. Non par défaut.
  // -----------------------------------------------------------------------------     
  void SearchForOutIntersections();

  // -----------------------------------------------------------------------------     
  // Indique si l'on recherche les solutions tangentes: non par défaut.
  // ----------------------------------------------------------------------------- 
  void SearchForTangentIntersections();

  // -----------------------------------------------------------------------------     
  // Indique qu'on va intersecter avec un ruban
  // ----------------------------------------------------------------------------- 
  void SetVsRib(CATTopRib    * iRib,                       // Ruban a intersecter 
                CATTopRibSign  iDir,                       // Direction de parcours du ruban 
                int            iStart,                     // Nuplet de depart      
                int            iEnd,                       // Nuplet de fin 
                int            iSupp,                      // Numero de support pour l'intersection 
                CATTopRibSign  iPostDir=UnknownDirection); // Direction a utiliser pour post-filtrer
                                                           // les solutions sur le ruban

  // -----------------------------------------------------------------------------     
  // Indique qu'on va intersecter avec une edge
  // ----------------------------------------------------------------------------- 
  void SetVsEdge(CATEdge      * iCuttingEdge,   // Edge coupante
                 CATTopRibSign  iChoiceDir  ,   // Direction du choix sur l'edge
                 CATVertex    * iStartCutting,  // Vertex debut de la coupante 
                 CATVertex    * iEndCutting ,   // Vertex fin de la coupante 
                 CATFace      * iBaseFace   );  // Face support de la coupante

  void SetVsEdgeOfNuplet(CATTopRibNuplet * iNuplet,     // Nuplet contentant l'edge coupante
                         int               iSupp,       // Numero de support pour l'intersection 
                         CATTopRibSign     iChoiceDir); // Direction du choix sur la coupante

  //------------------------------------------------------------------------------
  // Avec VsEdge... uniquement :
  // Indique si l'edge que l'on va intersecter est dans le meme ruban (par defaut, non)
  //------------------------------------------------------------------------------
  void SetSameRib(CATBoolean iSameRib);

//------------------------------------------------------------------------------
// Indique si l'edge que l'on va intersecter est dans le meme ruban initial (par defaut, non)
// (le ruban initial correspond au RibToRelimit (BlendRib pour le fillet)
//------------------------------------------------------------------------------
  void SetSameRibToRelimit(CATBoolean iSameRibToRelimit);
  
  //------------------------------------------------------------------------------
  // Donne le MacroTool pour eviter de detruire (dans un cas de sortie en erreur) 
  // les ExitContacts
  // si elles sont deja stockees dans le macrotool
  //------------------------------------------------------------------------------
  void SetMacroTool(CATTopRibMacroTool * iMacroTool);

  //------------------------------------------------------------------------------
  // Specifie au CATIntersectRib qu'il ne doit renvoyer des intersections que
  // pour les traces ayant le meme support
  //------------------------------------------------------------------------------
  void SetOnlySameSupport(CATBoolean iSameSupport);

  // -----------------------------------------------------------------------------     
  // Run with rib
  // ----------------------------------------------------------------------------- 
  void Run(ListPOfCATSupContact & oExitContact,    // Liste des contacts resultats
           CATListOfInt         & oNumNuplet,      // Liste des num de nuplet resu 1
           CATListOfInt         & oNumNupletVS);   // Liste des num de nuplet resu 2 

  // -----------------------------------------------------------------------------     
  // Run with edge
  // ----------------------------------------------------------------------------- 
  void Run(ListPOfCATSupContact & oExitContact,    // Liste des contacts resultats
           CATListOfInt         & oNumNuplet);     // Liste des num de nuplet resu

   void GetConfusionEdges(ListPOfCATEdge &oConfusionEdges);

   void SetConfusionManagement (CATBoolean iConfusionManagement);
   void SetDefaultVertexMerge(CATBoolean iMergeVertices);

   void AppendRibToSynchronize(CATTopRib* iRibToSynchronize);

   void FindTrueIntersectSolution(); // Search for an intersection which is truly at the loop of twist.   
   CATBoolean CheckIfWrongIntersection(ListPOfCATSupContact & iExitContact,
                                       CATTopRibNuplet * iNextNuplet,
                                       CATIntersectRib & iOpInt,
                                       CATTopRibSign & iOriCutting,
                                       CATEdge * iCuttingEdge,
                                       int iNrib1,
                                       int iNrib2,
                                       CATTopRibNuplet * iPrevNuplet);
   int restoreOriginalIntersection(CATListOfInt & iExtremityNumNuplet,
                                   int iNupletNbForExtremityIntersection,
                                   int iNRib2,
                                   CATBoolean iDeleteExitContact,
                                   ListPOfCATSupContact & ioExitContact, 
                                   CATListOfInt & ioNumNuplet, 
                                   CATListOfInt & ioNumNupletVS);
   void GetIntersectionParams(CATCrvParam & ioLeftParam, CATCrvParam & ioRightParam);
 private:

   // donnees entrees
   CATTopRib     * _Ribbon[2];
   CATTopRibSign   _Direction[2];
   int             _StartNuplet[2];
   int             _EndNuplet[2];
   int             _Nuplet[2];
   int             _Support[2];
   CATTopRibSign   _PostDirection[2];

   // Options
   CATBoolean           _Extrapol;
   CATBoolean           _SearchForOutIntersections;
   CATBoolean           _SearchForTangentIntersections;
   CATBoolean           _SameRib;
   CATBoolean           _SameRibToRelimit;
   CATTopRibNuplet    * _CuttingNuplet;
   CATEdge            * _CuttingEdge;
   CATTopRibSign        _CuttingDir;
   CATVertex          * _CuttingVertex[2];
   CATFace            * _CuttingBase;
   CATCell            * _CuttingLinkCell[2];
   CATTopRibMacroTool * _MTool;
   short                _DebugMode;
   CATBoolean           _OnlySameSupport;
   
   ListPOfCATEdge       _ConfusionEdges;
   CATLISTP(CATTopRib)  _RibsToSynchronize;

   CATBoolean           _ConfusionManagement;
   CATBoolean           _MergeVertices;
   CATBoolean _FindTrueIntersectSolution;

   CATVertex          * _VertexForSelection;

  // -----------------------------------------------------------------------------     
  // Interne : Ruban contre Edge
  // ----------------------------------------------------------------------------- 
   void WithEdge(CATTopRib            * iRib        ,  // Ruban a intersecter 
                 CATTopRibSign          iDirection  ,  // Direction de parcours du ruban 
                 int                    iStart      ,  // Nuplet de depart      
                 int                    iEnd        ,  // Nuplet de fin 
                 int                    iSupp       ,  // Numero de support pour l'intersection 
                 ListPOfCATSupContact & oExitContact,  // Intersections 
                 CATListOfInt         & oNumNuplet  ,  // Numero de nuplet associe a chaque intersection pour le ruban 
                 CATTopRibSign          iPostDirection);

   //----------------------------------------------------------------------------
   // Interne : Utilitaire de WithEdge ci-dessus :
   // Ajout de nuplet d'extrapolation
   //----------------------------------------------------------------------------
   void ExtrapolationInWithEdge(CATTopologicalOperator  * iTopOp,
                                int                       iNumSupport,
                                ListPOfCATTopRibNuplets * iNuplets,
                                CATListOfInt            * iNupletsIndex,
                                int                       iPas);

   //----------------------------------------------------------------------------
   // Interne : Utilitaire de WithEdge ci-dessus :
   // Identification et gestion eventuelle des edges consecutives en confusion
   // Rend TRUE si l'intersection a ete geree pour les 2 edges, et donc si il n'y
   // a plus rien a faire ensuite
   //----------------------------------------------------------------------------
   CATBoolean WithEdgeInConfusion(CATTopologicalOperator *  iTopOp,
                                  CATBody                *  iCreationBody,
                                  CATTopRibNuplet        *  iNupletToIntersect,
                                  CATTopRibSupport       *  iSupport,
                                  CATFace                *  iSupportFace,
                                  CATVertex              *  iStartVertexToIntersect,
                                  CATVertex              *  iEndVertexToIntersect,
                                  const int                 iCommonVertexIndex,
                                  CATEdge                *& EdgeToIntersect);
   void IntersectOutEdges( CATTopologicalOperator &iTopOp, CATBody*  iCreationBody,
                           CATFace* iSupportFace, CATEdge* iEdge1, CATEdge* iEdge2,
                           int &oNbIntersections, CATVertex*** oIntersections );

   //-----------------------------------------------------------------------------
   // Interne : Verifie la validite des solutions
   //-----------------------------------------------------------------------------
   void CheckValidityOfSolutions(CATSoftwareConfiguration *iSoftwareConfiguration,
     CATTopologicalOperator  *iTopOp,
     CATFace                 *iFace, 
     CATEdge                 *iEdgeToIntersect,
     CATVertex               *iTabVertex[2][2],
     int                      inbintLoc,
     CATVertex              **iIntVertexLoc,
     int                      inbIntEdgeLoc,
     CATEdge                **iIntEdgeLoc,
     double                   iresolution,
     int                      iSupp,
     int                      iPos,
     CATTopRibNuplet         *iNuplet,
     ListPOfCATVertex        &oListOfVerticesToDestroy, 
     int                     &oNbDestroyedVertices, 
     ListPOfCATVertex        &ioIntVertex, 
     CATListOfInt            &ioIntersectedNupletIndex,
     ListPOfCATTopRibNuplets &ioIntersectedNuplets);

   // UVC 11-Oct-11: Hold curve chamfer.
   CATBoolean IntersectOnCommonEdge( CATEdge     * iEdge,
									 int         & oNbIntersections,
                   CATVertex *** oIntersections );

   CATCrvParam _leftParam, _rightParam;
};
#endif
