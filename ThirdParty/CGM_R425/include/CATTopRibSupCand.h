/* -*-C++-*- */

#ifndef CATTopRibSupCand_H
#define CATTopRibSupCand_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//===================================================================
//===================================================================
//
// CATTopRibSupCand
// Classe servant a stocker les infos permettant de determiner les 
// prochains supports d'un support 
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
#include "CATMathDef.h" 
#include "CATMathInline.h"
#include "CATTopRibDef.h"  
#include "CATTopRibObject.h"
#include "ListPOfCATTopRibSupports.h"
#include "CATCGMNewArray.h"

class CATTopRibSupport;
class CATTopRibNuplet;
class CATBody;
class CATCell;
class CATVertex;
class CATTopRibNupletCand;

#include "CATSafe.h"
CATSafeDefine(CATTopRibSupCand);

class ExportedByRIBLight CATTopRibSupCand : public CATTopRibObject
{
 public: 

  //-----------------------------------------------------------------
  // Constructor
  //-----------------------------------------------------------------
  CATTopRibSupCand();
  CATCGMNewClassArrayDeclare; // Pool allocation

  //-----------------------------------------------------------------
  // Destructor
  //-----------------------------------------------------------------
  ~CATTopRibSupCand();

  //-----------------------------------------------------------------
  // Detruit les candidats 
  //-----------------------------------------------------------------
  void Clear();

  //-----------------------------------------------------------------
  //-----------------------------------------------------------------
  // Writing-Reading methods 
  //-----------------------------------------------------------------
  //-----------------------------------------------------------------

  void SetSupportCandidate(int                iNumCand,
			   CATTopRibSupport * iNewSupCand);

  void InsertSupportCandidate(int                iNumCand,
                              CATTopRibSupport * iNewSupCand);

  void ClearSupportCandidates(int iStartNum, 
			      int iEndNum);

  ListPOfCATTopRibSupports & GetSupportCandidatesList();

  CATTopRibSupport * ReadSupportCandidate(int iNumCand);

  CATTopRibSupport * GetSupportCandidate(int               iNumCand                      ,
                                         int               iNumSupport  =0               ,
					 CATTopRibNuplet * iOldNuplet   =NULL            ,
					 CATTopRibSign     iOldDirection=UnknownDirection); 

  INLINE int   GetNbSupportCandidates();
  int          HasNewSupport();
  INLINE int   GetCurrentSupportPosition();
  INLINE void  SetCurrentSupportPosition(int iNumCurrentSup);
  CATBoolean   IsUpToDate(CATTopRibPropagation iMode=PropagStandard);
  void         Lock(CATTopRibPropagation iMode=PropagStandard);
  void         UnLock();
  CATBoolean   IsFrozen();
  void         Freeze();
  void         UnFreeze();
  void         ResetLastAsNew();

  //-----------------------------------------------------------------
  // Ajouts d'une liste de candidats possibles avec verif de non 
  // creation de doublons. 
  //
  // WARNING : Si iDuplicate==0:
  // -------    * les supports de NewCandidates non ajoutes sont 
  //              detruits
  //            * les pointeurs de NewCandidates sont mis a NULL
  //-----------------------------------------------------------------
  int AddIfNew(ListPOfCATTopRibSupports &ioNewCandidates,
               CATBoolean iDuplicate=0);

  //-----------------------------------------------------------------
  // Ajouts d'un candidat a une liste de candidats possibles 
  //-----------------------------------------------------------------
  CATBoolean Add (CATTopRibSupport * iNewSupport, int ForceToAddCandidate, CATBoolean iDuplicate=0);

  //-----------------------------------------------------------------
  // Ajouts d'un candidat a une liste de candidats possibles avec 
  // verif de non creation de doublons. Destruction du nouveau support
  // s'il existe deja et iDuplicate==0. Renvoie 1 si ajout, 0 sinon.
  //
  // Si iNumCand>0, alors la methode insere le candidat (par appel a
  // InsertSupportCandidate) plutot que de l'ajouter a la fin de la
  // liste des candidats
  //-----------------------------------------------------------------
  CATBoolean AddIfNew(CATTopRibSupport * iNewSupport, 
                      CATBoolean         iDuplicate=0,
                      int                iNumCand=0);

  //-----------------------------------------------------------------
  // Lecture d'un support candidat sans modifier l'index du
  // support candidat courant (iNumCand >= 1)
  //-----------------------------------------------------------------
  CATTopRibSupport * GetSupportCandidateOnly (int               iNumCand,
                                              int               iNumSupport,
                                              CATTopRibNuplet * iOldNuplet,
                                              CATTopRibSign     iOldDirection);

  //------------------------------------------------------------------------------
  // Remove a given candidate 
  //------------------------------------------------------------------------------
  void Remove(const int iNumCand) ;

  //------------------------------------------------------------------------------
  // Remove a given candidate if there is an equivalent support among the
  // other candidates ("before" or "after" this candidate)
  //
  // Please note: If the candidate is equivalent to another candidate, it
  //              will be removed from the list and destroyed; in this case
  //              the method returns CATBoolean(1), otherwise it returns
  //              CATBoolean(0)
  //------------------------------------------------------------------------------
  CATBoolean RemoveIfOld (int iNumCand);

  //------------------------------------------------------------------------------
  // HasClearCand
  //------------------------------------------------------------------------------
  CATBoolean HasClearCand(int &oNumSuppToClearCand);

  void ClearCand(CATBoolean iClearCand, int iNumSuppIndexToClear);

 private: 

  ListPOfCATTopRibSupports   _Candidates;
  int                        _NumCurrentSup;
  CATTopRibPropagation       _UpToDate;
  CATBoolean                 _IsFrozen;
  CATTopRibSupport  *        _CurrentSupp;
  CATBoolean                 _ClearCand;
  int                        _NumSuppIndexToClear;

};

//-----------------------------------------------------------------
// INLINE method
//-----------------------------------------------------------------

INLINE int CATTopRibSupCand::GetCurrentSupportPosition()
{
  return _NumCurrentSup;
} 

INLINE void CATTopRibSupCand::SetCurrentSupportPosition(int iNumCurrentSup)
{
  _NumCurrentSup = iNumCurrentSup;
}

INLINE int CATTopRibSupCand::GetNbSupportCandidates()
{
  return _Candidates.Size();
}

#endif 
