/* -*-C++-*- */

#ifndef CATAlgoElt_H
#define CATAlgoElt_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "TopoOperModel.h"
#include "CATErrThrower.h"
#include "CATChainMaster.h"
#include "CATDataType.h"
#include "CATMathInline.h"

class CATAlgoContext;
class CATSubscription;
class CATCGMOutput;
/** @c++ansi fbq 2004-08-05.10:18:26 [Replace forward declaration by #include <iosfwd.h>] **/
#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif

#ifdef NOT_USE_UNCOMPILED_FOR_COVERAGE

#define OBJNUM(obj) (( obj ) ? ( obj -> GetNum()) : 0 )

// OBJNAME ne doit etre utilise que dans une ecriture, pour y inserer
// le nom de l'objet (obj est un CATAlgoElt*, mais peut etre "NULL"), sur 4+lon
// caracteres, les 4 premiers servant au nom (_ShortClassName) de la classe 
#define OBJNAME(lon,obj) cgmsetw(4) << (( obj ) ? ( obj -> Logo()) : "    ") << \
                                    (( obj ) ? "#" : " ") \
                                 << cgmsetw( lon ) << OBJNUM( obj )

// Implementation commune aux methodes statiques "SafeCast" en un type directement
// associe a un administrateur de chaine, ou un de ses sur-types (ex: GEdge). Cette
// macro ne doit pas etre utilisee un sous-type de type chaine (tel que bipoint par
// exemple, il faut passer dans ce cas par une fonction virtuelle donc non statique)
#define ImplementSafeCastUpChain( motherName , motherShortName , sonName , sonAdminName ) \
  motherName * sonName::SafeCastTo##motherShortName(const CATAlgoElt * iElt) \
{                                            \
  motherName * ret = 0;                          \
  if (iElt)                                  \
    ret = ( motherName *)                        \
    (iElt -> SafeCastToChain(iElt -> GetContext() -> Get##sonAdminName##Admin())); \
  return ret; \
}
#endif // fin de debranchement du code pour le coverage



class ExportedByTopoOperModel CATAlgoElt
{
  
public:

  
  // Destructeur: ote l'element de la chaine mais ne decremente pas le compteur
  // afin de ne pas risquer de re-attribuer un vieux numero a un futur objet
  virtual ~CATAlgoElt();

#ifdef NOT_USE_UNCOMPILED_FOR_COVERAGE

  // Copy-constructeur et operateur = (affectation) dans la meme chaine
  // Attention, ces methodes n'etant pas heritees, elles devront etre
  // explicitement appelees dans les classes derivees (via les listes
  // d'initialisation pour les constructeurs, de base ou de copie)
  CATAlgoElt(CATAlgoElt& iOrig);
  CATAlgoElt& operator= (const CATAlgoElt& iRight);


  // Test d'identite logique
  INLINE short operator == (const CATAlgoElt &iReference) const;

  // Acces a la racine, ou a l'objet operateur, ou a l'administrateur
  INLINE CATAlgoElt * GetRoot() const;
  INLINE CATAlgoContext * GetContext() const;
  INLINE CATChainMaster * GetAdmin() const;
       
  // Acces au numero d'identification
  INLINE CATLONG32 GetNum() const;

  // Compteur d'objets de la classe
  static CATLONG32 GetCount(CATChainMaster * iAdmin);
#endif // fin de debranchement du code pour le coverage
  
  // Recherche de l'element suivant dans une classe donnee
  static CATAlgoElt * NextElt(const CATChainMaster * iAdmin,
                                const CATAlgoElt * iCur);

  // Recherche de l'element precedent dans une classe donnee
  static CATAlgoElt * PrevElt(const CATChainMaster * iAdmin,
                                const CATAlgoElt * iCur);

#ifdef NOT_USE_UNCOMPILED_FOR_COVERAGE
  // Ajout ou suppression d'un contrat d'abonnement individuel
  void AppendContract(void * iSubscriber,
                      CATSubscription::UpdateAction iAction);
  void RemoveContract(void * iSubscriber);

  // Information des abonnes pour un remplacement d'objet 
  // (la suppression est directement geree par le destructeur)
  void TellSubscribersIAmReplaced(CATLONG32 iNbNewElts,
                                  CATAlgoElt ** iListOfNewElts);
#endif // fin de debranchement du code pour le coverage

  // Suppression de tous les elements d'une chaine donnee
  // (l'objet administrateur n'est pas detruit, mais "resette")
  static void DeleteAllObjects(CATChainMaster * iAdmin);

#ifdef NOT_USE_UNCOMPILED_FOR_COVERAGE
  // Initialisation et lecture des zones de travail (iZtrNum commence en 1)
  //+++ PR64
  // INLINE void SetZtr(short iZtrNum, CATLONG32 iVal);
  // INLINE CATLONG32 GetZtr(short iZtrNum) const;
  INLINE void SetZtr(short iZtrNum, CATLONGPTR iVal);
  INLINE CATLONGPTR GetZtr(short iZtrNum) const;
  // Pour la methode qui suit, iZtrNum=0 signifie "toutes les ztravs"
  static void SetZtrForAllObjects(CATChainMaster * iAdmin, 
  //                              short iZtrNum=0, CATLONG32 iVal=0);
                                  short iZtrNum=0, CATLONGPTR iVal=0);
  //+++ PR64

  // Reservation d'une zone de travail (methodes statiques)
  static short GetFreeZtrNum(CATChainMaster * iAdmin);
  static void LockZtr(CATChainMaster * iAdmin, short iZtrNum,
                      char * iDebugPostIt=NULL);

#endif // fin de debranchement du code pour le coverage

  // Liberation d'une zone de travail (methode statique):
  // iZtrNum=0 libere toutes les zones. Si le post-it est precise, on le 
  // compare a celui qui a ete depose a la reservation de la zone
  static void UnlockZtr(CATChainMaster * iAdmin, short iZtrNum=0,
                        char * iDebugPostItControl=NULL); 

#ifdef NOT_USE_UNCOMPILED_FOR_COVERAGE
  // Remplacement d'une valeur donnee d'une ztrav par une autre pour tous
  // les objets de la classe
  static void ReplaceZtr(CATChainMaster * iAdmin, short iZtrNum, 
  //+++ PR64
  //                     CATLONG32 iOldVal, CATLONG32 iNewVal);
                         CATLONGPTR iOldVal, CATLONGPTR iNewVal);
  //+++ PR64

  // Acces a un objet par son numero (numero > = 1)
  // la version INLINE rend un objet de la meme chaine (non statique)
  static CATAlgoElt * GetAlgoElt(CATChainMaster * iAdmin, CATLONG32 iNum);
  INLINE CATAlgoElt * GetAlgoElt(CATLONG32 iNum);
#endif // fin de debranchement du code pour le coverage

  // Dump
#ifdef DEBUG_DUMP
  char * Logo() const; // rend nom abrege de la classe (facilite debug)
#endif // fin de DEBUG_DUMP

#ifdef NOT_USE_UNCOMPILED_FOR_COVERAGE

  friend CATCGMOutput& operator<< (CATCGMOutput& s, const CATAlgoElt& iObj);

#endif // fin de debranchement du code pour le coverage

  virtual void DumpObj(CATCGMOutput& s, short iLongDump=0,
                       short iZtrNoDump=0) const = 0;

#ifdef NOT_USE_UNCOMPILED_FOR_COVERAGE


  // Le dump de toute la classe prend en argument optionnel un pointeur sur
  // fonction (ipDumpIt) qui prend un CATAlgoElt* et un void* et rend un
  // char=0 s'il ne faut pas dumper cet objet-la, et =1 sinon; le void* sert
  // a passer en entree des infos de contexte a la fonction de filtrage, qui
  // doivent alors etre comuniquees en dernier argument de DumpClass
  static void DumpClass(CATChainMaster * iAdmin, short iLongDump=0,
                        char (*ipDumpIt) (CATAlgoElt*,void*) = NULL,
                        void * iContextForIPDumpIt = NULL);

  // Idem que DumpClass avec la possibilite de choisir un stream
  static void DumpClassOnStream(CATCGMOutput & iOutStream, 
                        CATChainMaster * iAdmin, short iLongDump=0,
                        char (*ipDumpIt) (CATAlgoElt*,void*) = NULL,
                        void * iContextForIPDumpIt = NULL);

  // Verifications de base (ne doit premunir que des erreurs fatales)
  // Le niveau de "check" en entree augmente avec le cgmout (0 = rapide)
  // lance une exception si un probleme est detecte
  virtual void CheckValid(short iCostLevel=0);
  static void CheckAllObjects(CATChainMaster * iAdmin, short iCostLevel=0);

  // Rend l'objet lui-meme s'il appartient a la chaine donnee
  const CATAlgoElt * SafeCastToChain(const CATChainMaster * iTargetChain) const;
#endif // fin de debranchement du code pour le coverage

protected:
  
  // Constructeur recevant l'objet operateur et la structure (agregee par cet
  // objet operateur) qui federe toutes les donnees administratives pour gerer
  // une chaine d'objets algorithmiques dans le contexte Shell / Thickness:
  // racine de la chaine, compteur d'objets, reservations des zones de travail.

  // Le constructeur est protege afin de rendre la classe virtuelle pure.
  CATAlgoElt(CATAlgoContext * iContext, CATChainMaster * iAdmin);

  // Donnees membres:
  CATLONG32                _Num;
  CATAlgoElt     *  _Next;
  CATAlgoElt     *  _Prev;
  CATAlgoContext     *  _Context;
  CATChainMaster *  _Admin;
  #ifdef NOT_USE_UNCOMPILED_FOR_COVERAGE
  CATSubscription * _IndividualSubs;
  #endif // fin de debranchement du code pour le coverage
  //+++ PR64
  // CATLONG32                _Ztr[CATChainMaster::MAXZTR];
  CATLONGPTR        _Ztr[CATChainMaster::MAXZTR];
  //+++ PR64
};

#ifdef NOT_USE_UNCOMPILED_FOR_COVERAGE
// Implementations INLINE

ExportedByTopoOperModel short CATAlgoElt::operator == (const CATAlgoElt &iReference) const
{ if (_Num==iReference._Num) return 1; else return 0; }

ExportedByTopoOperModel CATAlgoElt * CATAlgoElt::GetRoot() const { return _Admin -> _Root; }

ExportedByTopoOperModel CATAlgoContext * CATAlgoElt::GetContext() const { return _Context; }

ExportedByTopoOperModel CATChainMaster * CATAlgoElt::GetAdmin() const { return _Admin; }

ExportedByTopoOperModel CATLONG32 CATAlgoElt::GetNum() const {
    if (_Num<=0)
      { BFTIERthrow(1120,"CATAlgoElt.h",Shell,"Shell")}
    return _Num; }

//+++ PR64
// ExportedByTopoOperModel void CATAlgoElt::SetZtr(short iZtrNum, CATLONG32 iVal) {
ExportedByTopoOperModel void CATAlgoElt::SetZtr(short iZtrNum, CATLONGPTR iVal) {
//+++ PR64
#ifdef DEBUG_THICK
  if (iZtrNum<1 || iZtrNum>CATChainMaster::MAXZTR)
    { BFTIERthrow(1001,"CATAlgoElt.h",Shell,"Shell")}
#endif
  _Ztr[iZtrNum-1] = iVal; }

//+++ PR64
// ExportedByTopoOperModel CATLONG32 CATAlgoElt::GetZtr(short iZtrNum) const {
ExportedByTopoOperModel CATLONGPTR CATAlgoElt::GetZtr(short iZtrNum) const {
//+++ PR64
#ifdef DEBUG_THICK
  if (iZtrNum<1 || iZtrNum>CATChainMaster::MAXZTR)
    { BFTIERthrow(1002,"CATAlgoElt.h",Shell,"Shell")}
#endif
  return  _Ztr[iZtrNum-1];
}
#endif // fin de debranchement du code pour le coverage


#endif
  
