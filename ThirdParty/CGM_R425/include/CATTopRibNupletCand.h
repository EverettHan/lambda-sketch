/* -*-C++-*- */

#ifndef CATTopRibNupletCand_H
#define CATTopRibNupletCand_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//===================================================================
//===================================================================
//
// CATTopRibNupletCand
// Classe servant a stocker les infos permettant de determiner le 
// prochain n-uplet 
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// June. 97    Creation                         J-M.Guillard
// Apr.  99    Modification                       I.Levy
//===================================================================
//===================================================================
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATTopRibObject.h"

#include "CATTopRibDef.h"   
#include "CATMathDef.h"   
#include "CATCGMNewArray.h"
#include "ListPOfCATTopRibSupCand.h"
#include "CATListOfInt.h"

class CATTopRibSupport;
class CATTopRibNuplet;
class CATBody;
class CATCell;
class CATVertex;
class CATCGMActivateDebug;

#include "CATSafe.h"
CATSafeDefine(CATTopRibNupletCand);

class ExportedByRIBLight CATTopRibNupletCand : public CATTopRibObject
{
 public: 

  //-----------------------------------------------------------------
  // Constructor
  //-----------------------------------------------------------------
  CATTopRibNupletCand(CATTopRibSign    iDirection, CATTopRibNuplet *iOldNuplet);
  CATCGMNewClassArrayDeclare; // Pool allocation
  
  //-----------------------------------------------------------------
  // Destructor
  //-----------------------------------------------------------------
  ~CATTopRibNupletCand();

  //-----------------------------------------------------------------
  // "Vide" un support candidat 
  //-----------------------------------------------------------------
  void ClearSupCand(int iNumSupCand);

  //-----------------------------------------------------------------
  // Methode permettant de savoir et d'indiquer si la recherche des   
  // candidats d'un nuplet a deja ete effectuee.  
  //-----------------------------------------------------------------
  CATBoolean IsUpToDate(CATTopRibPropagation iMode=PropagStandard);
  void       Lock(CATTopRibPropagation iMode=PropagStandard);
  void       UnLock();

  //-----------------------------------------------------------------
  // Determination de candidats possibles
  //-----------------------------------------------------------------
  virtual CATBoolean GetNextCandidate(CATTopRibSupport ** & oNuplet,
                                      CATBoolean            iSavePrev = TRUE);

  //-----------------------------------------------------------------
  // Indique s'il reste des candidats non explores 
  //-----------------------------------------------------------------
  CATBoolean HasCandidate();

  //------------------------------------------------------------------------------
  // Lecture des SupCandidates
  //------------------------------------------------------------------------------
  CATTopRibSupCand * ReadSupCandidate(CATLONG32 iNumCand);

  //-----------------------------------------------------------------
  // Determiner un support candidat a une position donnee sans modifier
  // les donnees internes du NupletCand
  // (i.e. sans influence sur le comportement des methodes
  // GetFirstCandidate et GetNextCandidate)
  // (iNumCand >= 1 && iSupportInd >= 1)
  //-----------------------------------------------------------------

  CATBoolean GetSupportCandidate (CATLONG32                 iNumCand,
                                  CATLONG32                 iSupportIndex,
                                  CATTopRibSupport * & oNupletSupport);

  //-----------------------------------------------------------------
  // Rend le nombre de supports candidats pour le support choisi
  //-----------------------------------------------------------------
  CATLONG32 GetNbSupportCandidates(CATLONG32 iSupportIndex);

  //------------------------------------------------------------------------------
  // Insertion d un support candidat.
  // Retourne FALSE au cas ou ce support existerait deja.
  //------------------------------------------------------------------------------
  // CATBoolean Insert(const CATLONG32 iSupportIndex, const CATTopRibSupport & iNewSupport);

  //------------------------------------------------------------------------------
  // Revient a l etat avant le dernier GetNextCandidate.
  // Retourne FALSE si ce n est pas posible.
  //------------------------------------------------------------------------------
  CATBoolean ResetToPrevCandidate();
  
  //-----------------------------------------------------------------
  // Debug : Visu et traces
  //-----------------------------------------------------------------
  void Show(CATCGMActivateDebug * iBrkPntMngr= NULL, CATBody* iCreationBody = NULL);

  //-----------------------------------------------------------------
  // Sauvegarde l etat courant pour ResetToPrevCandidate
  //-----------------------------------------------------------------
  void SaveIndex() ;

 private: 

  //-----------------------------------------------------------------
  // Determination de candidats possibles
  //-----------------------------------------------------------------
  CATBoolean GetFirstCandidate(CATTopRibSupport ** & oNuplet,
                               CATBoolean            iSavePrev = TRUE);

  //-----------------------------------------------------------------
  // Calculate TabIndex values
  //-----------------------------------------------------------------
  CATBoolean FirstIndex(CATBoolean iSavePrev=TRUE);
  CATBoolean NextIndex(CATBoolean iSavePrev=TRUE); //argument optionnel qui inidique si on sauve l'index prec
  CATBoolean NextCrossingIndex(int iCand);
 
 //-----------------------------------------------------------------
  // Verification de validite de la nouvelle combinaison de
  // support.
  // Elle est invalide si:
  //
  // 1) Il n'y a qu'un seul NOUVEAU support candidat et il est
  //    de plus marque _InvalidIfSingleNewCandidate
  //
  // 2) A suivre ...
  //
  //-----------------------------------------------------------------
 public:
  virtual CATBoolean IsNewIndexValid();

 //-----------------------------------------------------------------
  // Donnes
  //-----------------------------------------------------------------
  private :

  CATTopRibSupport **     _TabSupports;     
  CATTopRibSign           _Dir;
  CATTopRibPropagation    _UpToDate;
  int                     _ScanMode;

  // Data for ResetToPrevCandidate
  CATBoolean              _CanResetToPrevCandidate;
  CATTopRibSupport **     _PrevTabSupports;     
  int                     _PrevScanMode;
  CATListOfInt            _PrevTabSupCandIndex;
  CATListOfInt            _PrevNumCurrentSup;

  protected :
  CATTopRibNuplet   *     _OldNuplet; // le Nuplet apres lequel on a ces candidats
  CATListOfInt            _TabSupCandIndex;
  ListPOfCATTopRibSupCand _TabSupCandidates;
  
  private :
  CATSoftwareConfiguration* _SoftwareConfiguration; // Config a utiliser
};
#endif
