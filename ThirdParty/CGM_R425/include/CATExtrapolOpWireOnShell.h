/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1999
//------------------------------------------------------------------------------
//      
// CATExtrapolOpWireOnShell :
//      
// Extrapolation d'un body filaire pose sur un body surfacique shell.
//
//
//------------------------------------------------------------------------------
// Creation PBE
//
// Rearchitecture LAT (Jan. 2000)
//
// modif check auto intersection 05 09 02  aov
// 
// NE PAS UTILISER / DO NOT USE
//------------------------------------------------------------------------------
//
#ifndef CATExtrapolOpWireOnShell_h
#define CATExtrapolOpWireOnShell_h

//------------------------------------------------------------------------------
#include "CATHybDef.h"
#include "HybOper.h"
#include "CATTopDef.h"
#include "CATTopOperator.h"
#include "ListPOfCATFace.h"
#include "CATCGMDebug.h"
#include "CATCGMStream.h"

#include "CATGeoFactory.h"
#include "CATTopData.h"
#include "CATCGMJournalList.h"
#include "CATCGMOutput.h"
#include "CATCGMOperatorDebug.h"

class CATMathVector;
class CATMathVector2D;
class CATExtrapolWireOnShellAtVtxOpr;
class CATExtrapolWireOnShellContext;
class CATWireOnShellExtrSpecAttr;



/**
 * Do not use.
 * Interface representing a topological operation of extrapolation of a wire 
 * CATBody 
 */
class ExportedByHybOper CATExtrapolOpWireOnShell : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATExtrapolOpWireOnShell);
public:

  //  Constructor
  CATExtrapolOpWireOnShell( CATGeoFactory * iFactory, 
                            CATTopData    * iTopData, 
                            CATBody       * BodyWire,
                            CATBody       * BodyShell );
  //  Destructor
  virtual ~CATExtrapolOpWireOnShell();     

  // Ajout d'une spec d'extrapolation sur un vertex
  void Append( CATVertex * iVertex, double iLengthToAchieve = -1. );

  // Execution of the operator
  virtual int Run();
  
  // Get the resulting Body
  virtual CATBody * GetResult();

  virtual short GetFreezeMode() const;
  virtual void  SetFreezeMode(short iMode=1);
  
  // force le logging dans le journal par des :
  //  Creation (Edge Extrapolee) a partir de (Face support, Edge a Extrapoler)
  void SetJournalFromEdges();

  // Force l'operateur a ne pas verifier les auto-intersections. A utiliser
  // quand on sait ce qu'on fait.
  void SetNoSelfIntersectionCheck();

  // On arrete l'extrapolation au bord de la Face
  // possible (1 pour oui, 0 pour non).
  void SetPartialExtrapol(short iOnOff);


  // Force l'operateur a reutiliser la geometrie existante quand c'est
  // possible (1 pour oui, 0 pour non).
  void SetUseExistingGeometry( short iOnOff );

  // Force l'operator to extrapolate on tangent border even on non-default behavior
  // possible (1 pour oui, 0 pour non).
  void SetAllowExtrapolTangentBorder( short iOnOff );

  // ST5: Methods for CGMReplay
  static const  CATString  *GetDefaultOperatorId();
  void Dump(CATCGMOutput& os) ;

  static void ReadInput(CATCGMStream       & iStr,
                        CATGeoFactory      * iFactory,
                        CATBody          	*& oWireBody,
                        CATBody						     *& oShellBody,
                        CATBoolean         & oCheckSelfIntersection);

  virtual int RunOperator();

protected:
  
  //  int SetCuttingWire(CATWire* wireToDuplic);
  void DuplicateWires(CATBody* bodyToDuplic, CATBody* bodyToTarget);
  // Configure l'operateur pour qu'il se comporte en mode par defaut 
  // (extrapoation de tous les wires jusqu'aux bords de skins).
  void SetDefaultBehaviour();

  // On recupere tous les operateurs locaux d'extrapolation 
  void CreateAllExtrapolationOperators();

  // On lance tous les operateurs les uns apres les autres
  void RunOperators();

  // Ajoute un operateur d'extrapolation a la liste
  void AppendOperator(CATExtrapolWireOnShellAtVtxOpr *iNewOperator);

  // Ajoute un attribut d'extrapolation a la liste
  void AppendAttribute(CATWireOnShellExtrSpecAttr     *iNewAttribute);

  // Verifie qu'il n'y a pas d'auto-intersection des edges posees sur la face
  // en cours (pour s'arreter des que deux branches d'extrapolation ne se
  // coupent).
  short CheckForSelfIntersectionsOnFace( CATFace * iFaceToCheck );

  CATBoolean CheckForConfusionOnFace(CATFace* iFaceToCheck, CATEdge* iNewEdge);

  // Utilitaire : ajoute une edge dans une liste.
  void  AddEdgeInList(CATEdge * iEdge, CATEdge **& ioEdgesList, CATLONG32 & ioListSize);

  // Utilitaire : detruit une liste d'edges
  void  ClearList(CATEdge ** ioEdgesList);

  //pour check auto intersection 05 09 02 aov
  void BuildEdgeAndFaceLists();

  //Check if Extrapolation is necessary on Shell Borders 12 01 08 IZE
  void CheckTangencyBetweenWireAndShellBorder(CATShell   *iShellOperande,
                                              CATWire    *iCuttingWire,
                                              CATBoolean &ioExtrapolOnBorderStartVertex, 
                                              CATBoolean &ioExtrapolOnBorderEndVertex);

  CATBoolean IsTangentToBoundaryAtVertex(CATVertex     *iVertex, 
                                         CATMathVector &iFirstTangentAtVtx);

   // ST5: Methods for CGMReplay
   static CATString  _OperatorId;
   const  CATString  *GetOperatorId();
   void   RequireDefinitionOfInputAndOutputObjects();
   CATExtCGMReplay* IsRecordable(short& oLevelOfRuntime, short& oVersionOfStream);
   void WriteInput(CATCGMStream& oStr);

  CATGeoFactory*           _GeoFactory;    // the Factory
  CATTopologicalOperator*  _TopOper;       // the TopologicalOperator services ...
  CATBody*		               _BasicWireBody; // the body containing the Initial CuttingWires
  CATBody*		               _ResultBody;    // the body containing the result
  CATBody*		               _ShellBody;     // the body containing the Shell Body
  CATBody*                 _CurrentBody;   // the body currently processed (_Body1 or _Body2)
  CATWire*		               _CuttingWire;   // the cutting wire
  CATFace*                 _CurrentFace;   // the current face 
  CATFace*                 _PreviousFace;  // the previous face 
  CATEdge*                 _CurrentEdge;   // the current extrapolate edge 
  CATVertex*               _StartVertex;   // the start vertex of _CuttingWire
  CATVertex*               _EndVertex;     // the end vertex of _CuttingWire
  CATVertex*               _CurrentVertex; // the current vertex of _CuttingWire to extrapol
  CATCGMJournalList*       _Report;        // the topological report
  CATCGMJournalList*       _LocalReport;   // the topological report for the operator only
  short                    _JournalFromEdges;
  short                    _DefaultBehaviour;
  short                    _PartialExtrapol;
  short                    _AllowExtrapolTangentBorder;
  short                    _GetHasBeenDone;

  // Tableau d'operateurs d'extrapolation en cours
  CATExtrapolWireOnShellAtVtxOpr**  _Operators;
  CATLONG32                         _NbOperators;

  // Tableau d'attributs d'extrapolation en cours
  CATWireOnShellExtrSpecAttr**      _Attributes;
  CATLONG32                         _NbAttributes;

  // Utilisation d'un body filaire de debug pour visualisation de ce qui est 
  // cree par extrapolation
  short                             _IsShowWire;
  CATBody*                          _DebugWireBody;

  // Contexte de l'operateur 
  CATExtrapolWireOnShellContext*    _Context;

  //pour check auto intersection 05 09 02 aov
  CATLONG32*                        _NbFaces;
  CATLONG32                         _NbEdges;
  CATLISTP(CATCell)                 _ListOfEdges;
  CATLISTP(CATFace)*                _TabFaces;

  CATTopData*                       _TopDataForLocalUse;
};


ExportedByHybOper CATExtrapolOpWireOnShell * CATCreateExtrapolOpWireOnShell(CATGeoFactory * iFactory, 
                                                                            CATTopData    * iTopData,
                                                                            CATBody       * BodyWire,
                                                                            CATBody       * BodyShell);

#endif











