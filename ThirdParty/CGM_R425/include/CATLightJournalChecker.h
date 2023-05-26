/* -*-C++-*- */

#ifndef CATLightJournalChecker_H
#define CATLightJournalChecker_H

/**
 * @nocgmitf (do not create phase 2 interface)
 */ 

// COPYRIGHT DASSAULT SYSTEMES 2019

//=============================================================================
//=============================================================================
//
// CATLightJournalChecker : Fait une verification 'rapide' de la validite
//                            d'un journal
//                          Inspiration libre depuis le check de journal
//                            implemente pour les CGMReplays
//
// Outil dedie pour Draft On Sheet Bodies - ne pas utiliser tel quel pour
//  tout autre usage
// Class dedicated to Draft On Sheet Bodies - Do not use for any other
//  purpose without appropriate change in the implementation
//
// Note: Le check de journal est implemente sur les CATExtTopOperator
//       Ici, on voudrait faire un check apres le Run d'un CATDraft.
//       Mais CATDraft ne derive pas de CATExtTopOperator/CATTopOperator
//          - C'est un simple CATTopRibObject
//
//=============================================================================

//=============================================================================
// Mar  2019  Creation                                                    PRL
//=============================================================================
//=============================================================================

// Derivation
#include "RibbonLight.h"
#include "CATCGMVirtual.h"

// Classes de base
#include "CATBoolean.h"
class CATGeoFactory;
class CATTopData;
class CATSoftwareConfiguration;
class CATCGMHashTable;

// Topolo
class CATShell;
#include "ListPOfCATCell.h"
#include "ListPOfCATBody.h"
#include "ListPOfCATEdge.h"

// Journal
class CATCGMJournalList;

// Gestion erreur
#include "CATThrowForNullPointer.h"
class CATError;
class CATTopOpInError;
class CATCGMDiagnosis;


class ExportedByRibbonLight  CATLightJournalChecker : public CATCGMVirtual
{

public: 
//===========================================================================================================
  enum UsageType
  {
    CATLJCheck_Und,  // Non defini
    CATLJCheck_Dos,  // Draft On Sheet Bodies
    CATLJCheck_Sew,  // TrimSew bords libres - Juste le check     - proto!
    CATLJCheck_Sch   // TrimSew bords libres - check + reparation - proto! (Sew check heal)
  };


public: 
//===========================================================================================================

  //------------------------------------------------------------------------------
  // Ctor/Dtor
  //------------------------------------------------------------------------------   
  CATLightJournalChecker (CATGeoFactory*              iGeoFac,
                          CATSoftwareConfiguration*   iConfig,                          
                          UsageType                   iJType);

  virtual ~CATLightJournalChecker();

  //------------------------------------------------------------------------------
  // Pool allocation
  //------------------------------------------------------------------------------   
  CATCGMNewClassArrayDeclare;        

  //------------------------------------------------------------------------------
  // Set
  //------------------------------------------------------------------------------
  void                  SetInitShell    (CATShell*           iShell);
  void                  SetNtrlShell    (CATShell*           iShell);   // Draft!
  void                  SetSkinShell    (CATShell*           iShell);   // TSew
  void                  SetRlimShell    (CATShell*           iShell);   // TSew
  void                  SetInputBodies  (ListPOfCATBody&     iLBodies);
  void                  SetOutputBody   (CATBody*            iBody);
  void                  SetJournal      (CATCGMJournalList*  iJournal);

  //------------------------------------------------------------------------------
  // Get infos
  //------------------------------------------------------------------------------
  CATBoolean            HasNtrlShell();

  //------------------------------------------------------------------------------
  // Calcul des cellules input a suivre
  //------------------------------------------------------------------------------
  void                  ComputeExpectedInCells();

  //------------------------------------------------------------------------------
  // Recup info avec calcul eventuel
  //------------------------------------------------------------------------------     
  CATBoolean            IsValid();


protected :
//===========================================================================================================

  //------------------------------------------------------------------------------
  // Check proprement dit
  //------------------------------------------------------------------------------   
  void                  CheckValidity();
  void                  CheckValidity_Dos();
  void                  CheckValidity_Dos_c();
  void                  CheckValidity_Sew();
  void                  CheckValidity_Sew_c();

  //------------------------------------------------------------------------------
  // Services
  //------------------------------------------------------------------------------   
  void                  GetExpCells(      CATShell*          iShell,
                                          ListPOfCATCell&    oLCells);
  void                  RetrieveMissings( ListPOfCATCell& oLInpCells,
                                          ListPOfCATCell& oLOutCells);

  //------------------------------------------------------------------------------
  // Pour creation d'un body d'erreur - Cas avec des edges a afficher
  //------------------------------------------------------------------------------
  void                  CheckForErrorBodyCreation(CATCGMHashTable& iMissingReportInputCells, 
                                                  CATCGMHashTable& iMissingReportOutputCells);

  void                  CreateErrorBody(ListPOfCATEdge&       iLEdges,
                                        CATTopOpInError*      iError,
                                        CATCGMDiagnosis*      iDiag);



protected :
//===========================================================================================================
    
  // Entrees  
  CATSoftwareConfiguration* _Config;
  CATShell*                 _InitShell;
  CATShell*                 _NtrlShell;
  CATShell*                 _SkinShell;
  CATShell*                 _RlimShell;
  ListPOfCATBody            _LInputBody;
  CATBody*                  _OutputBody;
  UsageType                 _JType;
  CATCGMJournalList*        _Journal;  

  // Deduit
  CATGeoFactory*            _ImplFac;   // Factory implicite  
  //short                     _CGMLevel;

  // Autres donnees
  CATBoolean                _CalcExp;
  ListPOfCATCell            _ExpInpEdgs;
  ListPOfCATCell            _ExpOutEdgs;
  int                       _IsValid;

  // Dbg
  int                       _NbPb;
    
private:
//===========================================================================================================
  
  //------------------------------------------------------------------------------
  // Pour debug facilite
  //------------------------------------------------------------------------------    
  void                  NotifyProblem();
  void                  JCHKThrow_InvInput();
  //void                  JCHKThrow_BadTopo();
  void                  JCHKThrow();

  //------------------------------------------------------------------------------
  // Juste pour eviter que le compilo ne definisse par lui-meme ces operateurs
  //------------------------------------------------------------------------------    
  CATLightJournalChecker();
  CATLightJournalChecker(CATLightJournalChecker& iObj);
  CATLightJournalChecker& operator=(const CATLightJournalChecker & iObj);

};
#endif

// Ne rien ecrire sous cette ligne
//===========================================================================================================


