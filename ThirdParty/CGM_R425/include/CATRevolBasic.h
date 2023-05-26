#ifndef CATRevolBasic_H
#define CATRevolBasic_H

//------------------------------------------------------------------------------
// CATRevolBasic : basic class for revol to be used by CVM only in surfacic mode
// Note : static method are useful for code sharing between Revol and RevolBasic
//------------------------------------------------------------------------------
// 08 12 09 NLD Definition d'une nomenclature pour les classes utilitaires du sweep, la plupart exportees
//              SpecCell  devient CATSweepSpecCell
//              Tableau   devient CATSweepArrayOfSpecCell
//              Spec      devient CATSweepSpec
//              Brep      devient CATSweepBRep
//              BrepCell  devient CATSweepBRepCell
//              Journal   devient CATSweepJournal

#include "CATSweepBasic.h"
#include "CATMathAxis.h"
#include "CATMathLine.h"
#include "BO0SWEEPLight.h"
#include "CATListOfCATCells.h"
#include "CATListOfCATCrvParams.h"

class CATGeoFactory;
class CATBody;
class CATVertex;
class CATEdge;
class CATFace;
class CATDomain;
class CATPointOnEdgeCurve;
class CATMergedCurve;
class CATEdgeCurve;
class CATMathDirection;
class CATTopData;

//
//=============================================================================
//
class ExportedByBO0SWEEPLight CATRevolBasic : public CATSweepBasic
{

  friend class CATRevol; // for code sharing with static routine

public :
//------

  // Constructeur d'une Revolution a partir d'un Body 
  // ATTENTION : angle en radian et non en degree
  CATRevolBasic(CATGeoFactory * iGeoFactory,
           CATTopData * iData,
           CATBody * iProfBody,
           const CATMathAxis& iAxis,
           CATAngle iStartAngle, 
           CATAngle iEndAngle,
           CATBoolean iShiftAnglesIfClosed = TRUE);

  // Destructeur 
  ~CATRevolBasic();

/*
 *
 */

protected :
//---------
 
  // Methodes
  //
  CATBody * SweepCnt(CATGeoFactory * iGeoFactory);

  static CATBody * SweepCntStatic ( CATGeoFactory  * iGeoFactory ,
                                    CATCGMOperator * iOper,
                                    CATSweepJournal        * iJournal,
                                    CATBoolean       iIsCntClosed,
                                    CATBoolean       iThinSolidMode,
                                    CATMathAxis    & iAxis,
                                    double         & iStartAngle,
                                    double         & iEndAngle);

  static void TestNumericalClosure ( CATGeoFactory * iGeoFactory   ,
                                     CATBody       * iProfBody     ,
                                     CATMathLine   & iMainLine     ,
                                     double        & ioStartAngle  ,
                                     double        & ioEndAngle    ,
                                     CATBoolean    & ioIsCntClosed );


  virtual void FixDegenerateCells();

  static void FixDegenerateCellsStatic( const CATBoolean        iIsCntClosed,
                                        CATSweepBasic         * iSweepBasic,
                                        CATGeoFactory         * iGeoFactory,
                                        CATBody               * iProfBody,
                                        CATBody               * iResultBody,
                                        CATSweepBRep          * iBrep[2][3],
                                        CATMathLine           & iMainLine,
                                        ListPOfCATCell        & iDegenerateCells,
                                        ListPOfCATCell        & oRelimitedEdges, 
                                        CATLISTP(CATCrvParam) & oStartParams,
                                        CATLISTP(CATCrvParam) & oEndParams);

  //
  // nettoyage de l'environnement   
  void Clear ();
  //		     
  //
  // Gestion de la degenerescence de cellules (portees par l'axe de revolution)
  //
  virtual void MakeSelfSafe();
  
  CATBody   * BuildSafeBody();

  static CATVertex * SafeVersion(CATVertex*, CATDomain *, CATDomain *, CATBody *, ListPOfCATCell&);

  static CATEdge   * SafeVersion(CATEdge  *, CATDomain *, CATDomain *, CATBody *, ListPOfCATCell&,
                                 CATGeoFactory * iGeoFactory, CATMathLine & iMainLine, const CATAngle & iStartAngle, const CATAngle & iEndAngle);
  //KY1: Cette méthode est remplacee par la methode static CATRevolPrismeTools::CheckIfRevolAxisCutsFace
  //
  //static CATFace   * SafeVersion(CATFace  *, CATDomain *, CATDomain *, CATBody *, ListPOfCATCell&,
  //                               CATGeoFactory * iGeoFactory, CATMathAxis & iAxis, CATMathLine & iMainLine, CATTopData & iTopData ,
  //                               CATSweepJournal * iJournal );

  static CATCell   * SafeVersion(CATCell  *, CATDomain *, CATDomain *, CATBody *, ListPOfCATCell&,
                                 CATGeoFactory * iGeoFactory, CATMathAxis & iAxis, CATMathLine & iMainLine, CATTopData & iTopData ,
                                 CATSweepJournal * iJournal, const CATAngle & iStartAngle, const CATAngle & iEndAngle);

  static CATDomain * SafeVersion(CATDomain*, CATBody *, ListPOfCATCell& oDegenerateCells,
                                 CATGeoFactory  * iGeoFactory, CATMathAxis & iAxis, CATMathLine & iMainLine, CATTopData & iTopData,
                                 CATSweepJournal * iJournal, const CATAngle & iStartAngle, const CATAngle & iEndAngle, CATCGMOperator * iOper);

  static CATBody   * SafeVersion(CATBody  *, ListPOfCATCell& oDegenerateCells,
                                 CATGeoFactory  * iGeoFactory, CATMathAxis & iAxis, CATMathLine & iMainLine, CATTopData & iTopData,
                                 CATSweepJournal * iJournal, const CATAngle & iStartAngle, const CATAngle & iEndAngle, CATCGMOperator * iOper);
  
  void AddDegenerateCell(CATCell*);

  virtual int  IsDegenerate ( CATCell * );

  virtual int  IsDegenerate ( CATDomain * );

  virtual void PostGeoExtrude();

  static void BuildOutAndInnerShellStatic ( const int          iNbConnectedComponents     , 
                                            const int          iOuterConnectedComponent   ,
                                            CATBody         *  iResultBody                ,
                                            CATCell         *  iCurVolume                 ,
                                            ListPOfCATCell **  iListOfConnectedComponents ,
                                            CATDomain       *& ioCurOutShell              );
  
  static void ComputeConnectedComponents(CATBody * iResultBody, CATDomain * iDomain, ListPOfCATCell *** oLsComp, CATLONG32 *oNbComp);

  void ComputeNewInternalDomains();

  static void MergeIdenticalCells ( CATGeoFactory    * iGeoFactory,
                                    CATTopData       & iTopData,
                                    CATBody          * iProfBody,
                                    const CATBoolean   iIsCntClosed,
                                    ListPOfCATCell   & iDegenerateCells,
                                    CATSweepBRep     * iBrep[2][3]);

  static void MergePlanarTopBottomFaces ( CATSweepBasic *  iSweepBasic,
                                          CATGeoFactory *  iGeoFactory,
                                          CATTopData    &  iTopData,
                                          CATMathAxis   &  iAxis,
                                          CATBody       *  iCntContour,
                                          CATBody       *  iProfBody,
                                          CATBody       *& ioResultBody);

  static void MergeWiresImageOfVertexInFace ( CATBody * iResultBody );

  static void MergePlanarFirstLastFaces ( CATSweepBasic  *  iSweepBasic,
                                          CATGeoFactory  *  iGeoFactory,
                                          CATTopData     &  iTopData,
                                          CATMathAxis    &  iAxis,
                                          CATMathLine    &  iMainLine,
                                          CATBody        *  iCntContour,
                                          CATBody        *  iProfBody,
                                          CATBody        *  iResultBody,
                                          ListPOfCATCell &  iDegenerateCells,
                                          CATSweepBRep   *  iBrep[2][3]);

  static void CalculateRelimitedEdges( CATBody               * iProfBody , 
                                       CATMathLine           & iMainLine,   
                                       ListPOfCATCell        & oRelimitedEdges, 
                                       CATLISTP(CATCrvParam) & oStartParams,
                                       CATLISTP(CATCrvParam) & oEndParams);

  static void ResetRelimitedEdges ( ListPOfCATCell        & ioRelimitedEdges, 
                                    CATLISTP(CATCrvParam) & ioStartParams,
                                    CATLISTP(CATCrvParam) & ioEndParams);

  //
  // fonction membre de verification des inputs  
  //
  CATDomain * TopoMerge (CATDomain * iCntManif, CATDomain * iProfManif, CATDomain * iManifold);

  static CATDomain * TopoMergeStatic  ( CATSweepBasic    * iSweepBasic,
                                        CATDomain        * iCntManif, 
                                        CATDomain        * iProfManif, 
                                        CATDomain        * iDomain,
                                        CATGeoFactory    * iGeoFactory,
                                        const CATBoolean   iIsCntClosed,
                                        CATBody         *& ioResultBody);
 
  // MergePoec
  static CATPointOnEdgeCurve * MergePoec ( CATGeoFactory  * iFactory,
                                           CATEdge        * iEdge1, 
                                           CATEdge        * iEdge2,
                                           CATMergedCurve * iMergedCurve, 
                                           CATEdgeCurve   * iCurve1, 
                                           CATEdgeCurve   * iCurve2,
                                           CATSide          iSide);

  // MergeEdges
  static void MergeEdges ( CATGeoFactory * iFactory,
                           CATTopData    * iTopData,
                           CATEdge       * iEdge1,
                           CATEdge       * iEdge2);
  
  // Donnees membres
  //----------------
  CATMathLine _MainLine;
  CATAngle    _StartAngle;
  CATAngle    _EndAngle;
  CATBoolean  _IsCntClosed;
  //
  // Cellules qui rencontrent l'axe
  ListPOfCATCell        _DegenerateCells;

  // Cellules relimitees pour que la surface de revolution ne soit pas twistee
  ListPOfCATCell        _RelimitedEdges;
  CATLISTP(CATCrvParam) _StartParams, _EndParams;

};
#endif

