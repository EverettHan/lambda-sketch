// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATTopCornerCx2 :
// Implementation class for TopCorner operator.
//
//=============================================================================
// Usage notes:
// classe prive generique pour tous les corners :
//  cette genericite va nous permettre de retraiter tous les probles de trim, de relimitation
// de relimitation de cercle et tutti quanti
// sample of use :
// to provide :
//    classe virtuelle, il faut en deriver
//
//=============================================================================
// April 99     Creation                          JHN
// 10/01/02 ALV Mise en place d'un Index des solutions 
//              et ajout de iNbWires dans les constructeurs.
// 07/08/02 ALV Mise en place du Trim partiel.(TrimSide)
// 29/01/03 ALV Gestion des confusions entre les wires inputs ou les parallels.
// 30/04/03 ALV Gestion des Parallels utilisé pour le calcul des corners.
// 29/01/04 ALV Ajout de GetResultWithConditions pour permettre de trouver parmis plusieurs
//              Corners solutions celui repondant aux maximum de conditions (cf RI0424593)
// 23/09/05 ALV Rendre le corner sur Shell aussi performant que le corner sur plan
//              i.e. remplacer un shell support plan par un plan pour le calcul
//              méthode ::ReplaceInputShellByPlane + :: ReplacePlaneByInputShell activé par la
//              la vairable _ReplaceInputShellByPlane
//=============================================================================
#ifndef CATTopCornerCx2_H
#define CATTopCornerCx2_H

#include "Parallel.h"
#include "CATTopCorner.h"
#include "CATMathDef.h"
#include "CATTopDef.h"
#include "ListPOfCATCell.h"
#include "CATListOfInt.h"
#include "CATCrvParam.h"
#include "CATTopCornerType.h"

class CATPlane;
class CATCurve;
class CATGeoFactory;
class CATBody;
class CATShell;
class CATFace;
class CATCGMJournalList;
class CATSurLimits;
class CATCell;
class CATMathDirection;
class CATTopCornerData;
class CATTopCornerParallelData;
class CATIPGMTopCornerCx2;

//-----------------------------------------------------------------------------
class ExportedByParallel CATTopCornerCx2 : public CATTopCorner
{
  CATCGMVirtualDeclareClass(CATTopCornerCx2);
 public:

  //
  //  Constructor 
  //
  CATTopCornerCx2 (CATGeoFactory *, int iNbWires);

  CATTopCornerCx2 (CATGeoFactory *, CATTopData * iData, int iNbWires);

  CATTopCornerCx2(CATGeoFactory  * iFactory, CATCGMJournalList * iReport,
                  CATBody * iRef1, CATBody * iRef2, CATBody * iSupport, double iRadius, int iNbWires);
  CATTopCornerCx2(CATGeoFactory  * iFactory, CATTopData * iData,
                  CATBody * iRef1, CATBody * iRef2, CATBody * iSupport, double iRadius, int iNbWires);
  void InitDataCornerCx2();

  
  virtual ~CATTopCornerCx2();

  //
  //  Basic methods
  //
  int  Run();
  /** @nodoc @nocgmitf */
  int  RunOperator(); // for CGMReplay
  virtual int RunCornerByType() = 0;


  virtual CATLONG32  GetNumberOfCorners () const;
  virtual void  BeginningCorner();
  virtual CATBoolean NextCorner();
  virtual CATBody * GetCorner (CATCGMJournalList * CurJourn=NULL);

/**
  * Creates a corner choose with conditions.
  * @param iCrvOr
  * The array of three orientations of the parallel to the first, second and third wire.
  * Acceptables values: 0,-1,1. Use 0 if you don't want to use this condition.
  * @param iTngOr
  * The array of three tangency orientations between the corner and the first, second and third wire.
  * Acceptables values: 0,-1,1. Use 0 if you don't want to use this condition.
  * @param iNumBeginWire
  * The number of input wire where the corner begin.
  * iNumBeginWire = 0,1,2,3 : The input wire where the corner begin. 0 : don't use this condition.
  * @iIndex 
  * iIndex = -1,0,1,2,... : The index of the wanted solution, Use -1 if you don't want to use this condition.
  * @param oUseOrientationCondition
  * Return TRUE if the corner solution use the orientation condition.
  * @param oUseBeginWireCondition
  * Return TRUE if the corner solution use the orientation condition.
  * @param oUseIndexCondition
  * Return TRUE if the corner solution use the orientation condition.
  * @param CurJourn
  * The pointer to the journal corresponding to the creation of the current corner.
  * If <tt>NULL</tt>, the journal is not written.
  * @return
  * The pointer to the created body, or NULL if we cannot find it. If you do not want to keep it,
  * use the @CATICGMContainer#Remove method to remove it from the geometric factory, after the deletion
  * of <tt>this</tt> operator.
  * Put the iterator of the resulting corners on the solution.
  */ 
  virtual CATBody * GetResultWithConditions(CATOrientation * iCrvOr, CATOrientation * iTngOr, int iNumBeginWire, int iIndex,
                                            CATBoolean &oUseOrientationCondition, CATBoolean &oUseBeginWireCondition, CATBoolean &oUseIndexCondition,
                                            CATCGMJournalList * CurJourn=NULL);

  // Set the direction 
  // To be used only in case of 3D corner definition 
  // ( by default if this service is not called a direction will be automatically calculated )
  virtual void SetDirection ( const CATMathDirection & iDirectionFor3DCorner );

  // Get the direction 
  // To be used only in case of 3D corner definition  
  // ( by default a direction will be automatically calculated )
  virtual void GetDirection ( CATMathDirection & oDirectionFor3DCorner      , 
                              CATBoolean       & oAutomaticModeForDirection );

  // SetTension
  // To be used only in case of 3D corner definition
  // Define the tension value at each extremity ( 1 by default )
  virtual void SetTension ( const double iTension[2] );


  // Retourne tous les resultats dans le meme body
  virtual CATBody *    GetResult();
  virtual void GetCurOrients (CATOrientation &Or1, CATOrientation & Or2, CATOrientation &Or3) const;

//
//  Setting the Support Trimming Mode 
//  iMode = 0 : Off  
//  iMode = 1 : On
//  valeur 0 par defaut
//  
  virtual CATLONG32 SetSupportTrimmingMode     (const CATLONG32 iTrimmingMode);

//
//  Getting the Support Trimming Mode 
//  iMode = 0 : Off  
//  iMode = 1 : On
//  valeur 0 par defaut
//  
  virtual CATLONG32 GetSupportTrimmingMode     (CATLONG32 & oTrimmingMode);

//
//  Setting the Support Trimming Side
//  iTrimmingSide = 0 : Trim whith all input wires 
//  iTrimmingSide = 1 : Trim whith first input wires 
//  iTrimmingSide = 2 : Trim whith last input wires 
//  valeur 0 par defaut
//  And setting the Support Trimming Mode 
//  iMode = 0 : Off  
//  iMode = 1 : On
//  valeur 0 par defaut
//
  virtual CATLONG32 SetSupportTrimmingSideAndMode  (const CATLONG32 iTrimmingSide, const CATLONG32 iTrimmingMode);

//
//  Getting the Support Trimming Side 
//  oTrimmingSide = 0 : Trim whith all input wires 
//  oTrimmingSide = 1 : Trim whith first input wires 
//  oTrimmingSide = 2 : Trim whith last input wires 
//  valeur 0 par defaut
//  And getting the Support Trimming Mode 
//  iMode = 0 : Off  
//  iMode = 1 : On
//  valeur 0 par defaut
//  
  virtual CATLONG32 GetSupportTrimmingSideAndMode  (CATLONG32 & oTrimmingSide, CATLONG32 & oTrimmingMode);

//
//  Setting the Support Trimming Side
//  iTrimmingSide = 1 : Trim whith first input wires 
//  iTrimmingSide = 2 : Trim whith last input wires 
//  And setting the Support Trimming Mode 
//  iMode = 0 : Off  
//  iMode = 1 : Smooth Side
//  iMode = -1 : Reverse smooth side
//  valeur 0 par defaut
//
  virtual CATLONG32 SetSupportTrim  (const CATLONG32 iTrimmingSide, const CATLONG32 iTrimmingMode);

//
//  Getting the Support Trimming Side 
//  oTrimmingSide = 1 : Trim whith first input wires 
//  oTrimmingSide = 2 : Trim whith last input wires 
//  And getting the Support Trimming Mode 
//  iMode = 0 : Off  
//  iMode = 1 : Smooth Side
//  iMode = -1 : ReverseSmoothSide
//  valeur 0 par defaut
//  
  virtual CATLONG32 GetSupportTrim  (CATLONG32 iTrimmingSide, CATLONG32 & oTrimmingMode);

//
// initialisation du mode corner :
// corner complet, corner relimite ou corner complementaire
// le corner par defaut est le corner complet. ce mode n'autorise pas le
// le mode trim
// le corner relimite est le plus petit corner joignant les points de contact
// aux appuis
// le corner complementaire est l'autre corner.
// nous ne fournissons pas de mode angle pour les corners sur support
// quelconque. Ce mode n'est valide que pour les supports plans monofaces
//
  virtual CATLONG32 SetCircleMode(CATCircleMode iCircleMode, double iStart, double iEnd);
  virtual void GetCircleMode(CATCircleMode & iCircleMode, double &iStart,double &iEnd);
  // Not implemented - CATLONG32 SetCircleWire();
  
  virtual CATBoolean GetCircularData( CATMathPoint &oCenter, CATAngle &oRadius,
                                      CATMathDirection &oFirst, CATMathDirection &oSecond,
                                      CATAngle   &oStartAngle, CATAngle &oEndAngle ) const;

  
  // methodes générales utilisé dans le create les constructeurs ou dans le Run global:
  CATLONG32 CheckModeCompatibility(CATBoolean iWithError);//Regarde si le circleMode et le mode de trim sont compatible(pas de trim en mode complet)
  void SetCornerType(CATTopCornerType iCornerType);
  CATTopCornerType GetCornerType();

//
// methodes permettant l'indexation des solutions: a appeler a la fin du Run()
//
  void  SetNumberOfInputWires(int iNbInputWires);
  void  InitPt(int iNbCornerOpe,CATLONG32 * iNbSol,CATBody *** ioPtCenter,
              CATBody *** ioPtContact1,CATBody *** ioPtContact2,CATBody *** ioPtContact3=NULL);
  void  InitArraysOfLocalisation(int iNbSol,int * iaIndCrv,CATCrvParam * iaCrvParam,CATOrientation * iaOri);
  void  ClearIndexData();
  void  InitIndexData();
  void  InitAllCornerDataWhithoutPtContact(CATLONG32 nbcorn=0, CATLONG32 * IndiceDebut=NULL);
  int   ComputeTangencyOrientation(CATBody * iCorner, int iNumInWire, int iIndCorner,
                                   CATBody * PtContact = NULL, CATBoolean WithPtContact = FALSE);
  // Not implemented -  int   ComputeOldTangencyOrientation(CATBody * iCorner, CATBody * iSupport, int iNumInWire, CATBody * PtContact = NULL);
  int   ComputeDataWireCornerWithPtContact(CATBody * iCurCorner , int iIndCorner, int iIndWire, int &oNumCrv, CATCrvParam &oCrvParam,
                                           CATOrientation &oCurveOnWireOri, CATBody * iPtContact=NULL);
  int   ComputeDataWireCornerWithIntersectionAndProjection(CATBody * iCurInputBody, int iIndInWire, int iIndCorner, CATBody * iCurCorner,
                                                           CATOrientation iCurOrient, int &oInWireNumCrv, CATCrvParam &oInWireCrvP,
                                                           CATOrientation &oCurveOnWireOri);
  void  RemovePtAndLocalisationsArrayWithBadTangency(int iNbCorner,CATBoolean * iaAcceptedBody);
  void  ComputeIndexOfCorner();
  void  DeletePt();
  // Not implemented - void  DeleteOrientData();
//Si les CurCornerData sont nulle et qu'il y a des corners solution on prend les cornerData du iRattrapCorner comme
//curCornerData(à lancer après le Run)
  void  UseRattrapCornerInfo(CATTopCornerCx2 * iRattrapCorner,int iNbCorner);
  void  UseRattrapCornerInfo(CATIPGMTopCornerCx2 * iRattrapCorner,int iNbCorner);

//
// Surcharge des methodes d'indexations de CATTopTangentCurveOperator:
//
  virtual void  GetOrientationOnWire(int & oTngtOrientation,int & oCrvtOrientation,
                             int & oIdem,int iIndWire);
  virtual CATLONG32  GetIndCurCorner();
  virtual void  GetDiscriminationIndex(int &oIndex);

//
// Surcharge des methodes d'indexations de CATTopCorner:
//
  virtual void GetCurBeginOfCorner(int & oNumWire);
  virtual void SetBeginOfCorner(int iNumWire);
  virtual void GetBeginOfCorner(int & oNumWire);

//
// Gestion des confusions entre les wires inputs ou entre les parallels
// A appeler après le Run().
//
//debug  int   GetNbConfusionsIni(); // Nombre de Cells en confusions pour les wires initiaux.
//debug  int   GetConfusionsIniCells(ListPOfCATCell& oListOfCells); //listes de ces cells
  int   AddConfusionsIniCells(CATCell * iIniCell1, int NumCell1, CATCell * iIniCell2, int NumCell2);
  void  ClearConfusionIni();

//
// Gestion des warnings Issus du calcul des corners.(Inclu les confusions ente wires inputs)
// A appeler après le Run().
//
//  int         GetNbWarning(); //Nombres de warnings.
//  CATError *  GetWarning(int iNumWarning); //Warning numero iNumWarning(entre 1 et NbWarning)
  void        AddWarning(CATError * iNewWarning);
  void        DeleteWarning();//Suppression de tous les warnings



 protected :
   virtual CATBody *  GetRelimitDomain(CATLONG32 numdom) = 0;
   virtual void       GetSupportCells(CATLONG32 iNumCorn,CATLONG32 & oNbCells,CATCell **& oCells) = 0;
   virtual void       GetBuildingCells(CATLONG32 iNumCorn,CATLONG32 & oNbCells,CATCell **& oCells) = 0;
   virtual void       GetCurReport(CATLONG32 iNumCorn, CATBody * iBody, CATCGMJournalList * iCurJourn);
   virtual void       GetSupportBodies(CATLONG32 & nbsupports,CATBody **& TabSupports) = 0;
   virtual void       GetCurReportVertices(CATBody * iBody, CATCGMJournalList * iCurJourn);
   virtual void       SetTrim(CATBody * Corner, CATBody *&AssmbledBody) = 0;
   void               AddCurOrients(CATLONG32 nbcorn,CATBody ** NewBodies,CATCGMJournalList ** Journaux,
                                    CATOrientation Or[3]);
   CATBoolean         CheckBeginningOfCorner(CATBody * LayDownCorner,const CATMathPoint & PointContact,CATBoolean iInversedInputs = FALSE);
   void               ComputeMathPointOnWire (CATBody * CurBody,int iIndCorner,int nBody,
                                              CATBody * PtContact,CATBoolean iBool,CATMathPoint &MathPointOnCrv1);
   void               DeleteBodyInJourn(CATBody * iBody);
   void               DeleteNonInOutEltInJourn( CATBody ** iaBodiesInOut, int NbBodyInOut, CATBody * iBodyToDelete,
                                                CATCGMJournalList * ioJournToClean);
   void               DeletePtInJourn();

   /*void               SlimInputWires( CATBody * iWire1, CATBody * iWire2, double iRadius,
                                      CATBoolean iOutputConnex, ListPOfCATCell oListEdge1, ListPOfCATCell oListEdge2);*/

   //Suivis des cells et des points de contacts:
   /*int                GetIndiceCell(int iIndSol, int iIndWire);
   void               SetIndiceCell(int iIndSol, int iIndWire, int iIndCell);
   void               RemoveIndiceCell(int iIndSol);
   void               RemoveAllIndiceCell();*/

   CATBody           * _SupportShell;
   CATBody           * _inCrv[3];//les wires inputs
   CATOrientation    * _OrientCorn[3];
   CATCGMJournalList * _Report;
   double              _Radius;
   CATLONG32           _trimmode[2];
   CATLONG32           _BeginOfCornerSelection;
   CATCircleMode       _CircMode;
   int                 _NbWires;
   
   //Donnees de l'index
   CATTopCornerData  * _aCornerData;//[0.._NbCorner-1]
   int                 _NbCorner;
   int                 _NbComputeCorner;//= -1 (non utilisable) a part dans le cas de l'usage d'un RattrapCorner ou cela vaut le _NbCorner du l'operateur qui n'a pas marché...
   int               * _aIndCrv;  //utile pour le pt de contact1 du cas CrvPoc, et sur l'unique pt de contact de TgtCenterOnPt
   CATCrvParam       * _aCrvParam;//idem
   CATOrientation    * _aOri;     //idem
   CATOrientation    * _aTngtOri; //utile uniquement pour l'unique pt de contact de TgtCenterOnPt 
   double            * _aVarRadius; //utile uniquement pour stocker le rayon des corner TgtCenterOnPt 
   CATBody          ** _PtContact[3];
   CATBody          ** _PtCenter;
   int               * _IndexOfLocalisation;//les valeurs du tableau([0.._NbCorner-1]) sont entre 1 et _NbCorner
   CATLONG32         * _BeginOfCorner;
   CATBoolean          _Confusion;//indique si le calcul des centres de corners a pu etre possible sans créer de zones de confusions
                                  // si Confusion = TRUE on a eu des zones de confusion sinon tout les centres trouvés ont été des points valides
   CATBoolean       ** _aConfusion; //Mise sous forme de tableau pour mettre en confusion tout les corners de meme orientationgarder l'orientation
                                    //indique si le calcul des centres de corners a pu etre possible sans créer de zones de confusions
                                    // si Confusion = TRUE on a eu des zones de confusion sinon tout les centres trouvés ont été des points valides
   CATTopCornerType    _CornerType;
   
   void PosOfCorner(CATBody * LayDownCorner,const CATMathPoint &MathPointOnCrv1, CATLONG32 & oNumWire, CATBoolean iInversedInputs = FALSE);
   void AssertPosOfWire(CATLONG32 inbassertions, CATLONG32 * iTabOfAssertion);

   //Données pour la gestion des confusions:
   ListPOfCATCell     _ListCellIniConf1;
   ListPOfCATCell     _ListCellIniConf2;
   CATListOfInt       _ListNumCellIniConf1;
   CATListOfInt       _ListNumCellIniConf2;

   //Données pour la gestion des erreurs:
   CATError         * _StockErr[8];
   int                _NbError;

   //Données pour la gestion des Parallels construits pour le corner.
   CATTopCornerParallelData * _ParallelData;

   //Données temporaires pour le calcul des solutions:
   int                  _NbCornerIni;       //Nb de corner déja construit avant le lancement du run par orientation
   int                  _NbOfCurrentCorner; //Nb de corner avant et pendant le lancement du run par orientation
   //CATListOfInt       * _ListOfIndiceCell;  //Indices d'edges pour la redondance
   //CATLISTP(CATBody *)* _ListBodyPtContact; //Point de contact non posé pour la redondance

   //Gestion du remplacement de support: _SupportShell par un plan 
   CATBody            * _SavedSupportShell;
   CATBody            * _NewSupportShell;

};
#endif
