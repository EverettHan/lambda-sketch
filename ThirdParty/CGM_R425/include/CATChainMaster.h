/* -*-C++-*- */

#ifndef CATChainMaster_H
#define CATChainMaster_H

// COPYRIGHT DASSAULT SYSTEMES 2000

/*  
=============================================================================

RESPONSABLE  : A Deleglise 

DESCRIPTION  : Administration d'une chaine d'objets algorithmiques
               (gestion commune = identification, creation / suppression
               gestion des zones de travail)

=============================================================================
*/
#include "TopoOperModel.h"
#include "CATSubscription.h" // pour recuperer le typdef Action
#include "CATDataType.h"
#include "CATMathInline.h"

class CATAlgoElt;
class CATCGMOutput;
class CATGeometry;

//----------------------------------------------------------------------------
// Generateur du code d'acces a l'objet algo associe a un objet modele
#define ImplementGetObjAssociatedWith( clname, mdlname, getadm ) \
  clname * clname::GetObjAssociatedWith(CATAlgoContext * iContext, mdlname * iModelObj) {\
  CATChainMaster * adm = iContext -> getadm();\
  CATAlgoElt * ret = adm -> GetAlgoEltAssociatedWith(iModelObj);\
  return ( clname *)(ret);\
}
//----------------------------------------------------------------------------


//--------------------------------------------------------------------------

class ExportedByTopoOperModel CATChainMaster
{

public:

  enum { MAXZTR = 3 }; // nombre maximum de zones de travail pour un objet
  
  CATAlgoElt      * _Root;
  CATAlgoElt      * _Oldest;
  CATLONG32                _LastId;
  short               _GlobalDelete;  // 1 si on detruit tous les objets chaines
  short               _NbZtr;
  short               _IsZtrLocked[MAXZTR];
  char              * _ZtrPostIt[MAXZTR];
  char                _ShortClassName[20];
  int                 _AttribKeyForModelObject;
#ifdef NOT_USE_UNCOMPILED_FOR_COVERAGE
  CATSubscription   * _Subscription; // Gestion des effacements et remplacements
#endif // fin de debranchement du code pour le coverage

  // Stream destine a recevoir le dump complet de la classe en fin d'algo (debug)
  CATCGMOutput * _DumpDestinationBeforeBeingDeleted;
  
  // Constructeur
  CATChainMaster(short iNbZtr = MAXZTR, char * iShortClassName = 0);

  // Destructeur
  ~CATChainMaster();

  #ifdef NOT_USE_UNCOMPILED_FOR_COVERAGE
  // Gestion des destructions de tous les objets chaines
  INLINE short GetGlobalDelete() const;
  INLINE void SetGlobalDelete(short iVal=1);

  // Ajout ou suppression d'un contrat d'abonnement a la chaine d'elements
  void AppendContract(void * iSubscriber,
                      CATSubscription::UpdateAction iAction);
  void RemoveContract(void * iSubscriber);

  // Lecture du numero de l'objet le plus jeune (_Root, ou zero)
  int YoungestNum() const;

  // Gestion de la cle d'attribut (optionnelle, zero si sans interet) par laquelle
  // les objets modeles correspondant pointent vers les objets de la chaine
  INLINE int GetAttribKeyForModelObject();
  INLINE void SetAttribKeyForModelObject(int iKey);

  // Recherche de l'algo-elt associe a un objet modele
  CATAlgoElt * GetAlgoEltAssociatedWith( CATGeometry * iObj) const;

  // Methodes de dump. DumpChain ne dumpe que les objets + recents que (chaines
  // par _Next au dela de ..) l'objet de numero iAfterNum s'il est present, et
  // filtre les objets par ipDumpIt (avec un contexte) s'il est fourni, ou dump
  // de l'objet numero iJustThisNumber si ce numero est > 0
  void DumpChain(CATCGMOutput & iOutStream,
                 int iAfterNum = 0,
                 short iLongDump = 0,
                 char (*ipDumpIt) (CATAlgoElt*,void*) = 0,
                 void * iContextForIPDumpIt = 0,
                 CATLONG32 iJustThisNumber = 0);

  friend CATCGMOutput & operator<< (CATCGMOutput& s, const CATChainMaster& iAdmin);

  // Dump d'un objet par son nom precede de l'adresse du contexte (debug)
  // ex: SearchObj("0x4682f600,VRep71");
  static void SearchObj(char * iInfo);

  // Verifications de base (ne doit premunir que des erreurs fatales)
  // Le niveau de "check" en entree augmente avec le cgmout (0 = rapide)
  // lance une exception si un probleme est detecte
  // ne doit jamais verifier les objets accroches ou le contexte (sinon boucle)
  virtual void CheckValid(short iCostLevel=0);

  // Recherche d'un objet par son numero 
  // (la version INLINE est accessible au debugger)
  INLINE CATAlgoElt * GetAlgoElt(CATLONG32 iNum);
  CATAlgoElt * ImplementGetAlgoElt(CATLONG32 iNum);
#endif // fin de debranchement du code pour le coverage

};

#ifdef NOT_USE_UNCOMPILED_FOR_COVERAGE

// Implementations INLINE
ExportedByTopoOperModel CATAlgoElt * CATChainMaster::GetAlgoElt(CATLONG32 iNum) {
  CATAlgoElt * ret = ImplementGetAlgoElt(iNum);
  return ret;
}

ExportedByTopoOperModel short CATChainMaster::GetGlobalDelete() const {
  return _GlobalDelete; }

ExportedByTopoOperModel void CATChainMaster::SetGlobalDelete(short iVal) {
  _GlobalDelete = iVal; }

ExportedByTopoOperModel int CATChainMaster::GetAttribKeyForModelObject() {
  return _AttribKeyForModelObject; }

ExportedByTopoOperModel void CATChainMaster::SetAttribKeyForModelObject(int iKey) {
 _AttribKeyForModelObject = iKey; }
#endif // fin de debranchement du code pour le coverage 

#endif















