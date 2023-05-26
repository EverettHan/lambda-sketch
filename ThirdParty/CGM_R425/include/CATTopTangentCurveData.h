/* -*-c++-*- */
#ifndef CATTopTangentCurveData_h_
#define CATTopTangentCurveData_h_

//COPYRIGHT DASSAULT SYSTEMES 2000

#include "Parallel.h"
#include "CATMathDef.h"
#include "CATTopDef.h"
#include "CATCrvParam.h"
#include "CATGeoFactory.h"
#include "CATVertex.h"
#include "CATTopData.h"
#include "CATMathInline.h"

/**
 * @nodoc
 * Do not use.
 */
class ExportedByParallel CATTopTangentCurveData
{

public:

  // -------------------------------------------------------------------
  // CATTopTangentCurveData : usage reserve a CATTopTangentCurveOperator 
  // et a ses heritiers
  // -------------------------------------------------------------------

  CATTopTangentCurveData(int iNWiresInput = 0);

  ~CATTopTangentCurveData();

  void InitWiresInput(int iNWiresInput);

  void SetSoftwareConfiguration(CATSoftwareConfiguration * iSoftwareConfiguration);
  void SetFactory(CATGeoFactory * iFactory);

  // Attention : en cas de reallocation d'un tableau <tab> d'instances, on evite que
  // la destruction finale de ce tableau (delete [] <tab) ne detruise 
  // les pointeurs membres alloues dans chacune des cellules CATTopTangentCurveData
  // du tableau original <tab> EN LES METTANT A NULL. La methode NullifyAllocatedMembers
  // est donc publique.
  void NullifyAllocatedMembers();
  
  void DeleteAllocatedMembers();

  // definition des orientations relatives des (tangentes,courbures)/wires-input + longueur + Positionnement
  void SetOrient(int iTngtOrient,int iCrvtOrient,int iIWire);
  void SetLength(CATLength iLength);
  void SetPositionOnInput(CATGeoFactory * ImplFactory, CATTopData    * iData, CATVertex * iExtremityVertex, 
                          CATBody * iInputBodyWire, int iIndWire);


  // SetIndex : usage reserve a CATTopTangentCurveOperator
  void SetIndex(int iIndex); //entre 0 et n-1 indice d'un tableau de CATTopTangentCurveData

  void SetIndexSignature(int iIndexSig); //entre 1 et p (p<=n) (pour GSD qui garde la val 0 pour les erreurs)

  // retour
  INLINE int GetNWiresInput();

  int GetTngtOrient(int iIWire);
  int GetCrvtOrient(int iIWire);
  int GetConflict(int iIWire);
  
  INLINE CATLength  GetLength();
  CATCrvParam       GetCrvParam(int iIndWire);
  INLINE int        GetIndexSignature();
  CATSoftwareConfiguration * GetSoftwareConfiguration();
  CATGeoFactory * GetFactory();

  //methode de comparaison entre le CATTopCornerData et un jeu de critères:
  void OKForConditions( short * iaTanOrient, short * iaCrvOrient, int iIndex,
                        CATBoolean &oOKForOrientationCondition, CATBoolean &oOKForIndexCondition,
                        CATBoolean * oaRulesResult);


  //
  // HasSameOrientations : pour le tri
  //
  CATBoolean HasSameOrientations(CATTopTangentCurveData &iOther);

  int LocalisationIsDifferent(CATTopTangentCurveData * TangentData2,int iIndWire);

  static void SortTangentCurveData(CATTopTangentCurveData* iTTangentCurveData,
                                   int iNCurveData,
                                   CATLength iResolution,
                                   int* &oTRankSameOriented);

  //void  DebugTangentCurveData();

  typedef int t_CurveDataConflict[2][2];

private :
  
  int DiffXYZ(double iPt1[3] ,double iPt2[3]);

  void InitMembers();
 
  int _NWiresInput; // 1 ou 2

  CATLength         _Length;
  int             * _aNumCrv;//[_NbWires]
  CATCrvParam     * _aCrvParam;//[_NbWires]
  CATOrientation  * _aEdgeOri;//[_NbWires]
  int               _IndexSignature;  //Index par signature(il ya huit signatures possible selon les valeurs de _TTngtOrient et de _TCrvtOrient)
                                      //0...(Nb de curve de meme signature-1) avant versionning CGM_Versionning_BitangentLine_DiscriminationIndexBySignature
                                      //1...(Nb de curve de meme signature) apres (cf pb GSD RI0498386)
  double            _PtStart[3];     //Coordonnées des points de contacts.
  double            _PtEnd[3];

  int _Index;

  // <_Index> = index de la CurveData dans l'ensemble des resultats VALIDES
  // (soit dans [0..GetNumberOfResults[) des courbes-tangentes resultats.
  // N.B : GetNumberOfResult() n'est pas connu a priori avant traitement de toutes
  // les lignes; c'est le nombre de courbes-tangentes ayant produit les wires-resultats
  // specifies par CATTopMultiResults::AddResults
  //
  // A chaque fois qu'une courbe-tangente-resultat est consideree comme VALIDE,
  // on recupere une cellule CATTopTangentCurveData* <TCD> et son rang 
  // d'insertion <IRank> par :
  // CATTopTangentCurveData* TCD = AddTangentCurveData(IRank);
  // (service de CATTopTangentCurveOperator)
  // _Index est automatiquement value a <oIRank> par AddTangentCurveData.
  //
  // _TTngtOrient[i] : orientation de tangente-courbe-resultat/courbe-input <i>. 
  // _TCrvtOrient[i] : orientation de courbure-courbe-resultat/courbe-input <i>. 

  int* _TTngtOrient; // [1.._NWiresInput] 
  int* _TCrvtOrient; // [1.._NWiresInput]
  t_CurveDataConflict* _TCurveDataConflict; // [1.._NWiresInput]
  CATSoftwareConfiguration * _SoftwareConfiguration; //Versionning
  CATGeoFactory            * _Factory;
};

  INLINE int CATTopTangentCurveData::GetIndexSignature()
    {
      return _IndexSignature;
    }

#endif
