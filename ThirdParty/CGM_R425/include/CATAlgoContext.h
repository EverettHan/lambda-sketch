/* -*-C++-*- */

#ifndef CATAlgoContext_H
#define CATAlgoContext_H

// COPYRIGHT DASSAULT SYSTEMES 2000

/*  
=============================================================================

RESPONSABLE  : A Deleglise 

DESCRIPTION  : Donnees contextuelles pour l'operateur shell/thickness
               et soft d'acces et d'edition de ces donnees

=============================================================================
Oct. 98  Ajout utilitaires modele (AddRef et Release)                L. Alt
=============================================================================
*/

#include "CATChainMaster.h"
// #include "CATDBGDefine.h"
#include "CATGeometry.h"
#include "CATMathInline.h"
//BEGIN_TCX (pour simplifier la vie AddRef-Release)
#include "CATCGMFormol.h"
#include "CATCGMNewArray.h"
//END_TCX

class CATTopologicalOperator;
class CATBody;
class CATGeoFactory;
class CATDomain;
class CATCGMActivateDebug;
class CATManThick;
class CATAlgoElt;
class CATCGMJournalList;
//--------------------------------------------------------------------------

class ExportedByTopoOperModel CATAlgoContext
{

public:

  // constructeur a partir d'une CATGeoFactory initiale
  CATAlgoContext( CATGeoFactory * iFactory );

  //TCX (pour simplifier la vie AddRef-Release)
  CATCGMNewClassArrayDeclare;

  // destructeur 
  ~CATAlgoContext();

  // acces au journal
  INLINE CATCGMJournalList * GetJournal() ;

  INLINE void SetJournal( CATCGMJournalList * iJournal );
  INLINE CATGeoFactory * GetFactory() const;

#ifdef NOT_USE_UNCOMPILED_FOR_COVERAGE

  // copy constructeur et operateur = (lancent une exception)
  CATAlgoContext(CATAlgoContext& iOrig);
  CATAlgoContext& operator= (const CATAlgoContext& iRight);

  // acces a la n-eme chaine
  virtual CATChainMaster * GetAdmin( CATLONG32 iAdminIndex )=0;

  // acces sequentiel aux administrateurs de chaines
  virtual CATLONG32 GetNbAdmin() = 0;

  // acces a un AlgoElt (INLINE pour etre accessible au debugger)
  // Si on fournit un algoelt de reference, on cherchera dans sa chaine
  INLINE CATAlgoElt * GetAlgoElt(CATChainMaster * iAdmin,
                                   CATLONG32 iNum);
  INLINE CATAlgoElt * GetSameChainElt(CATAlgoElt * iRefElt,
                                   CATLONG32 iNum);
  CATAlgoElt * ImplementGetSameChainElt(CATAlgoElt * iRefElt,
                                   CATLONG32 iNum);

  // Utilitaires modele (encapsulent les Addref et Release + verifications)
  INLINE void AddRef( CATGeometry * iObject );
  short IsAlive( CATGeometry * iObject );
  void Release( CATGeometry * iObject );
  void Remove( CATGeometry * iObject, short iRecursiveMode=0 );

  // dump
  friend CATCGMOutput& operator<< (CATCGMOutput& s, const CATAlgoContext& iOpe);
  void DumpClasses( CATCGMOutput & iOutStream, short iLongDump, char ** iComment=NULL);
  void ImplementDumpAll();
  INLINE int DumpAll();

  // Verifications de base (ne doit premunir que des erreurs fatales)
  // Le niveau de "check" en entree augmente avec le cgmout (0 = rapide)
  // lance une exception si un probleme est detecte
  // ne doit jamais verifier les chaines d'objets ou admin. (sinon boucle)
  virtual void CheckValid(short iCostLevel=0);

  #endif // fin de debranchement du code pour le coverage


private:

  // caracteristiques du body initial
  CATGeoFactory * _Factory;

  // journal topologique
  CATCGMJournalList * _Journal;

   // TCX: pour se simplifier la vie sur les AddRef-Release
  CATCGMFormol      _formol;

};

ExportedByTopoOperModel CATGeoFactory * CATAlgoContext::GetFactory() const {
	return _Factory; }

ExportedByTopoOperModel CATCGMJournalList * CATAlgoContext::GetJournal()  {
	return _Journal; }

ExportedByTopoOperModel void CATAlgoContext::SetJournal(CATCGMJournalList * iJournal) {
	_Journal= iJournal; }

#ifdef NOT_USE_UNCOMPILED_FOR_COVERAGE

ExportedByTopoOperModel CATAlgoElt * CATAlgoContext::GetAlgoElt(CATChainMaster * iAdmin, CATLONG32 iNum) {
  return ((iAdmin) ? iAdmin -> GetAlgoElt(iNum) : NULL); }

ExportedByTopoOperModel CATAlgoElt * CATAlgoContext::GetSameChainElt(CATAlgoElt * iRefElt, CATLONG32 iNum) {
	return ImplementGetSameChainElt(iRefElt, iNum); }

ExportedByTopoOperModel int CATAlgoContext::DumpAll() {
  // cette fonction est INLINE uniquement pour etre accessible au debugger
  ImplementDumpAll();
  return 1;
}

ExportedByTopoOperModel void CATAlgoContext::AddRef( CATGeometry * iGeometry ) { 
  // TCX: changement d'implementation dur AddRef
  _formol.lock(iGeometry); 
}
#endif // fin de debranchement du code pour le coverage


#endif
