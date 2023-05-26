//* -*-c++-*- */
//===========================================================================
// Class CATExtrapolWireOnShellAtVtxOpr
//---------------------------------------------------------------------------
// Classe operateur d'extrapolation de wire pose sur un shell, en un vertex
// donne. Peut se decliner en plusieurs types (jusqu'au bord, d'une longueur
// donnee, ... ).
//       
//---------------------------------------------------------------------------
// Nov. 99  Creation.                                                L. Alt
// Jul. 17  New method to get Config and Versioning level.           G. Doctors
//===========================================================================
#ifndef CATExtrapolWireOnShellAtVtxOpr_H
#define CATExtrapolWireOnShellAtVtxOpr_H

#include "ExportedBySHL.h"
#include "CATAlgoElt.h"
#include "CATTopDef.h"
#include "CATTopOpSpecAttr.h"
#include "CATSurParam.h"
#include "CATMathVector2D.h"
#include "CATMathInline.h"

class CATBody;
class CATWire;
class CATShell;
class CATCell;
class CATVertex;
class CATEdge;
class CATFace;
class CATGeoFactory;
class CATCGMJournalList;
class CATTopologicalOperator;
class CATPCurve;
class CATEdgeCurve;
class CATMathVector;
class CATExtrapolWireOnShellContext;
class CATCrvParam;
class CATSoftwareConfiguration;

#include "CATGeometry.h"
INLINE CATULONG32  Tag(const void* iItf) {
  if (iItf) {
    const CATGeometry * geo = (const CATGeometry*) iItf;
    CATULONG32  tag = (geo->GetImpl() && ! geo->GetImpl()->IsNull()) ?
      (geo->GetPersistentTag()) : (-9999);
    return tag;
  }
  else return 0;
}

class ExportedBySHL CATExtrapolWireOnShellAtVtxOpr : public CATAlgoElt
{
  
public :
  
  // constructeur & destructeur
  CATExtrapolWireOnShellAtVtxOpr( CATVertex         * iVertex, 
                                  CATWire           * iWire, 
                                  CATShell          * iShell,
                                  CATGeoFactory     * iGeoFactory,
                                  CATBody           * iResultBody,
                                  CATBody           * iShellBody,
                                  CATCGMJournalList * iJournalList,
                                  CATExtrapolWireOnShellContext * iContext );

  ~CATExtrapolWireOnShellAtVtxOpr();

  // Lance le calcul de l'extrapolation.
  virtual void  Run();

  // Determination des conditions de depart pour l'extrapolation (uniquement 
  // au tout debut : ensuite, on calcule par propagation avec la methode
  // ComputeStartConditionsFromPrev).
  void ComputeStartConditions();

  // Determination des conditions de fin d'extrapolation en vue 
  // de l'eventuelle extrapolation suivante
  void ComputeEndConditions();

  // Cree une edge qui extrapole l'edge existante, en reutilisant la geometrie
  // de _PreviousEdge (si c'est une CATPLine). L'orientation de l'edge obtenue
  // est :                    
  //    - dans le meme sens que le wire d'origine si _Direction == 1
  //    - dans le sens oppose si _Direction == -1
  CATEdge * CreateEdgeOnExistingGeometry();

  // Cree une edge qui extrapole l'edge existante, en creant la geometrie
  // necessaire. L'orientation de l'edge obtenue est :                    
  //    - dans le meme sens que le wire d'origine si _Direction == 1
  //    - dans le sens oppose si _Direction == -1
  CATEdge * CreateEdgeAndGeometry();
  
  // Determination des geometries (point et tangente 2D) en un vertex
  // bordant une edge, poses tous les deux sur une face.
  void ComputeGeometriesAtVertex( CATVertex       * iVertex,
                                  CATEdge         * iBoundedEdge, 
                                  CATFace         * iUnderlyingFace,
                                  CATSurParam     & ioSurParam,
                                  CATMathVector2D & ioTangent2D );


  void GetEndConditions( CATVertex      *& ioVertex,
                         CATEdge        *& ioBoundedEdge, 
                         CATFace        *& ioUnderlyingFace,
                         CATSurParam     & ioSurParam,
                         CATMathVector2D & ioTangent2D );


  // Initialisation des conditions de depart pour l'extrapolation.
  void SetStartConditions( CATSurParam      & ioSurParam,
                           CATMathVector2D  & ioTangent2D,
                           CATFace          * ioUnderlyingFace );

  // Exprime un vecteur 3D tangent a une surface dans une base 2D de cette surface 
  void GetVectorParamsOnSurface( short             iLevel_to_execute,
                                 CATMathVector   & iMathVector, 
                                 CATMathVector   & iDU, 
                                 CATMathVector   & idV, 
                                 CATMathVector2D & oResult,
                                 int             & oIsOk); 

  // initialisation pour le journal
  void SetInitCellForJournal( CATCell * iInitCellForJournal );

  // direction
  void SetDirection( CATOrientation iDirection );
  INLINE CATOrientation GetDirection();


  // Creation d'un nouvel operateur, qui prolonge l'extrapolateur actuel sur la
  // prochaine face.
  virtual CATExtrapolWireOnShellAtVtxOpr * GetNewOperator() = 0;

  //recupere la dernier edge creee
  void GetResultEdge( CATEdge *& ioResultEdge );

  // Retourne la face sous-jacente
  INLINE CATFace * GetFace();

  // Cree le wire associe a la branche d'extrapolation en cours
  void CreateWireUnderConstruction( short iToInvert);
  
  // wire en cours de construction
  INLINE void SetWireUnderConstruction( CATWire * iWire, short iWireToInvert );
  
  //contexte topologique
  INLINE CATExtrapolWireOnShellContext * GetContext();
  
  //recupere wire extrapole
  INLINE void GetExtrapolWire( CATWire *& ioNewWire, short & oInvertWire );
  
  // Acces aux operateurs avant et apres, au sein de la meme branche
  INLINE CATExtrapolWireOnShellAtVtxOpr * GetPrevOperator();
  INLINE CATExtrapolWireOnShellAtVtxOpr * GetNextOperator();
  INLINE void                             SetPrevOperator( CATExtrapolWireOnShellAtVtxOpr * iPrevOperator );
  INLINE void                             SetNextOperator( CATExtrapolWireOnShellAtVtxOpr * iNextOperator );

  // If there is a previous operator, check that the extrapolated result doesn't overlap with the very first vertex
  // That would mean undetected loop, which is obviously to be avoided
  CATBoolean ResultSelfIntVsFirstVx();
  
  // Calcule les conditions de depart de l'extrapolation depuis l'operateur precedent
  void ComputeStartConditionsFromPrev( CATExtrapolWireOnShellAtVtxOpr * iPreviousOpr );

  // aov 05/09/02
  // conditions d edepart dans le cas de la recherche de la bonneface candidate
  //quand l'extrapolation s'est terminee sur un vertex 
  void ComputeStartConditionsFromPrev( CATExtrapolWireOnShellAtVtxOpr * iPreviousOpr, CATFace * iFace );

  
  void SetUnderlyingFace( CATFace * iUnderlyingFace );
  INLINE void GetUnderlyingFace( CATFace *& ioUnderlyingFace );

  INLINE void SetPreviousEdge( CATEdge * iPreviousEdge );

  // Initialise la nouvelle edge sous-jacente.
  INLINE void SetStartUnderlyingEdge( CATEdge * iStartUnderlyingEdge );

  //24/04/02 aov
  //verifie si la face est une bonne candidate
  void CandidateForExtrapolation(CATFace * boundedFace,CATFace * prevFace,CATEdge * edgeBetweenFaces, CATVertex * prevVertex , CATExtrapolWireOnShellAtVtxOpr * iPreviousOpr,CATSurParam & prevSurParam, short & ioresultat);
  //dans les limites de la surface
  int ExtrapolationPossibleOnFace(CATFace * boundedFace,CATSurParam & surparam,CATMathVector2D & startTangent2D);

  //si l'extrapolation se termine sur un vertex
  INLINE void SetStopOnVertex( short ivar );
  INLINE short GetStopOnVertex();

  INLINE void SetExtrapolOnBorder( CATBoolean ivar );
  INLINE CATBoolean GetExtrapolOnBorder();



 protected :

   // Calcule une edge extrapolee dans une direction donnee. L'edge retournee
   // est relimitee sur la face.
   CATEdge * ComputeExtrapolEdge();

   // Cree une edge a partir d'une courbe, entre deux parametres.
   CATEdge * MakeIsolateEdge( CATEdgeCurve * iEdgeCurve,
                              CATPCurve    * iPCurve, 
                              CATCrvParam  & iStartLimit,
                              CATCrvParam  & iEndLimit,
                              CATBody      * iBodyForCellCreation );

   // Determination de la face support courante.
   void GetSupportCell( CATVertex *  iEndVertex, 
                        CATEdge   *  iEdge,
                        CATBody   *  iShellBody,
                        CATFace   *& ioPreviousFace,
                        CATFace   *& oNextFace );

   // Determine la nouvelle face sous-jacente, a partir de la face precedente et de l'edge
   // qui les separe.
   /*void GetNewUnderlyingFace( CATEdge *  iEdgeBetweenFaces, 
                              CATFace *  iPrevFace,
                              CATFace *& ioNextFace );*/

   // Utilitaire : recupere une edge qui se trouve en dessous d'un vertex (au sens pose
   // sur), au sein d'un body donne.
   void RetrieveEdgeUnderVertex( CATVertex *  iVertex, 
                                 CATEdge   *& ioEdgeUnderVertex, 
                                 CATBody   *  iShellBody  );

   // 08/04/02 aov
   // Utilitaire : recupere un vertex qui se trouve en dessous d'un vertex (au sens pose
   // sur), au sein d'un body donne.
   void RetrieveVertexUnderVertex( CATVertex *  iVertex, 
                                   CATVertex   *& ioVertexUnderVertex, 
                                   CATBody   *  iShellBody  );


   // 08/04/02 aov
   // Utilitaire : recupere la meilleure edge candidate bordee par le vertex donne en argument
   // (cas ou l'extrapolation se termine sur un vertex)
   void RetrieveBestEdgeFromVertex(  CATVertex *  iVertex, 
                                     CATEdge   *& ioEdgeUnderVertex,
                                     CATFace   *& iFace,
                                     CATBody   *  iShellBody,
                                     CATVertex   *  iUnderlyingVertex);

   // 08/04/02 aov
   // Utilitaire: test si l'extrapolation du wire a une solution
   // rajout parametre face le 05/09/02
   CATBoolean LanceExtrapolationOnFace(CATWire * iWire,
                                       CATVertex * iVertex,CATFace * iFace);

 protected :

   // Utilitaire
   int IsCellInBody( CATBody * iBody, CATCell * iCell );

   CATGeoFactory          * _GeoFactory;

   // Body resultat, dans lequel on va mettre les edges extrapolees
   CATBody                * _ResultBody;

   // Wire a extrapoler 
   CATWire                * _Wire;

   // Body shell sur lequel on est pose. Comme un wire peut etre
   // pose sur plusieurs shells, il faut le specifier.
   CATBody                * _ShellBody;

   // Shell sur lequel est pose le wire a extrapoler
   CATShell               * _Shell;

   // Journal topologique
   CATCGMJournalList      * _LocalReport;

   // Vertex depuis lequel on extrapole.
   CATVertex              * _StartVertex;

   // Point de depart de l'extrapolation
   CATSurParam              _StartSurParam;

   // Direction 2D de depart de l'extrapolation
   CATMathVector2D          _StartTangent2D;

   // Edge sous-jacente au vertex de depart de l'operateur d'extrapolation.
   // Elle peut etre nulle si le vertex de depart se trouve au milieu d'une
   // face.
   CATEdge                * _StartUnderlyingEdge;


   // Vertex extremite (la fin de l'edge qu'on a rajoutee, et 
   // auquel sera concatene la prochaine extrapolation)
   CATVertex              * _EndVertex;

   // Point d'arrivee de l'extrapolation
   CATSurParam              _EndSurParam;

   // Direction 2D d'arrivee de l'extrapolation
   CATMathVector2D          _EndTangent2D;

   // Edge sous-jacente au vertex de fin de l'operateur d'extrapolation
   CATEdge                * _EndUnderlyingEdge;

   // Vertex sous-jacent au vertex de fin de l'operateur d'extrapolation
   CATVertex                * _EndUnderlyingVertex;


   // Orientation de l'extrapolation.
   CATOrientation           _Direction;

   // Wire en cours de construction (issu d'un vertex)
   CATWire                * _WireUnderConstruction;

   // Il faut inverser le wire si il part du vertex debut.
   short                    _WireToInvert;

   // Cellule initial du wire, pour le journal (en general, toute
   // la branche extrapolee est creee a partir de la meme cellule).
   CATCell                * _InitCellForJournal;

   // Face sous-jacente a l'operateur d'extrapolation
   CATFace                * _UnderlyingFace;

   // Edge resultant de l'extrapolation
   CATEdge                * _ResultEdge;

   // Edge precedente dans l'extrapolation de la branche. Si on est
   // sur le premier operateur de la branche, c'est l'edge en extre-
   // mite du wire, sinon, elle doit etre egale a la _ResultEdge de
   // l'operateur precedent.
   CATEdge                * _PreviousEdge;

   // Contexte de l'operateur 
   CATExtrapolWireOnShellContext * _Context;

   // Operateurs avant et apres, au sein de la meme branche
   CATExtrapolWireOnShellAtVtxOpr * _PrevOperator;
   CATExtrapolWireOnShellAtVtxOpr * _NextOperator;

   //24/04/02 aov
   //variable utilisee dans le cas ou l'extrapolation 
   //s'est arretee sur un vertex
   short _StopOnVertex;

   //12/01/08 IZE
   //Defines wether the extrapolation is authorized for wires tangent to the shell border or not
   CATBoolean _ExtrapolOnBorder;

   private:
     void GetConfigAndLevel (int &oLevelToExecute, CATSoftwareConfiguration *& oConfig);

};


INLINE void CATExtrapolWireOnShellAtVtxOpr::SetWireUnderConstruction( CATWire * iWire, short iWireToInvert )
{
  _WireUnderConstruction = iWire;
  _WireToInvert          = iWireToInvert;
}


INLINE CATExtrapolWireOnShellContext  * CATExtrapolWireOnShellAtVtxOpr::GetContext()
{
  return( _Context );
}

INLINE void  CATExtrapolWireOnShellAtVtxOpr::GetUnderlyingFace( CATFace *& ioUnderlyingFace )
{
  ioUnderlyingFace = _UnderlyingFace;
}

INLINE void CATExtrapolWireOnShellAtVtxOpr::SetStartUnderlyingEdge( CATEdge * iEdgeBetweenFaces )
{
  _StartUnderlyingEdge = iEdgeBetweenFaces;
}

   
INLINE void CATExtrapolWireOnShellAtVtxOpr::GetExtrapolWire( CATWire *& ioNewWire, short & ioWireToInvert )
{
  ioNewWire      = _WireUnderConstruction;
  ioWireToInvert = _WireToInvert;
}

INLINE CATOrientation CATExtrapolWireOnShellAtVtxOpr::GetDirection()
{
  return _Direction;
}

INLINE CATFace *  CATExtrapolWireOnShellAtVtxOpr::GetFace()
{
  return _UnderlyingFace;
}

INLINE CATExtrapolWireOnShellAtVtxOpr * CATExtrapolWireOnShellAtVtxOpr::GetPrevOperator()
{
  return _PrevOperator;
}

INLINE CATExtrapolWireOnShellAtVtxOpr * CATExtrapolWireOnShellAtVtxOpr::GetNextOperator()
{
  return _NextOperator;
}

INLINE void CATExtrapolWireOnShellAtVtxOpr::SetPrevOperator( CATExtrapolWireOnShellAtVtxOpr * iPrevOperator )
{
  _PrevOperator = iPrevOperator;
}

INLINE void CATExtrapolWireOnShellAtVtxOpr::SetNextOperator( CATExtrapolWireOnShellAtVtxOpr * iNextOperator )
{
  _NextOperator = iNextOperator;
}

INLINE void CATExtrapolWireOnShellAtVtxOpr::SetPreviousEdge( CATEdge * iPreviousEdge )
{
  _PreviousEdge = iPreviousEdge;
}

INLINE void CATExtrapolWireOnShellAtVtxOpr::SetStopOnVertex( short ivar )
{
  _StopOnVertex = ivar;
}
INLINE short CATExtrapolWireOnShellAtVtxOpr::GetStopOnVertex(  )
{
  return _StopOnVertex;
}

INLINE void CATExtrapolWireOnShellAtVtxOpr::SetExtrapolOnBorder( CATBoolean ivar )
{
  _ExtrapolOnBorder = ivar;
}
INLINE CATBoolean CATExtrapolWireOnShellAtVtxOpr::GetExtrapolOnBorder(  )
{
  return _ExtrapolOnBorder;
}

#endif
