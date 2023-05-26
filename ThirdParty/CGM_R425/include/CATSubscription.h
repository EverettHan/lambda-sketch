/* -*-C++-*- */

#ifndef CATSubscription_H
#define CATSubscription_H
#ifdef NOT_USE_UNCOMPILED_FOR_COVERAGE
// COPYRIGHT DASSAULT SYSTEMES 2000

/*  
=============================================================================

RESPONSABLE  : A Deleglise 

DESCRIPTION  : Gestion des objets abonnes aux suppressions / remplacement
               d'un objet, individuellement ou a toute la classe

=============================================================================
*/

#include "TopoOperModel.h"
#include "CATDataType.h"

class CATAlgoElt;
class CATChainMaster;

//--------------------------------------------------------------------------

class ExportedByTopoOperModel CATSubscription
{

public:
  
  typedef void (* UpdateAction) (void * iSubscriber, CATAlgoElt * iOld,
                                 CATLONG32 iNbNewElts, CATAlgoElt ** iListOfNewElts);

  // constructeur (ne fait rien)
  // On fournit soit un objet, soit une chaine (pas les deux)
  CATSubscription(CATAlgoElt * iElt, CATChainMaster * iChain);

  // cpy-cst et operateur = non implementes
  CATSubscription(CATSubscription & iOrig);
  CATSubscription & operator= (const CATSubscription & iRight);

  // destructeur
  ~CATSubscription();

  // Ajout d'un contrat
  void AppendContract(void * iSubscriber, UpdateAction iAction);

  // Suppression de tous les contrats d'un abonne
  void RemoveContract(void * iSubscriber);

  // Information des abonnes suite a une destruction ou un remplacement
  // (destruction si iNbNewElts = 0)
  void InformSubscribers(CATAlgoElt * iOld, CATLONG32 iNbNewElts,
                         CATAlgoElt ** iListOfNewElts);

  // Classe locale definissant un contrat d'abonnement
  struct Contract {
    void       * _Subscriber;
    UpdateAction _Action;
  };

private:

  // Recherche d'un indice de contrat, rend (-1) s'il n'y en a plus
  CATLONG32 NextContractFor(void * iSubscriber, CATLONG32 iFirstIndexToSearch = 0);
  
  // Suppression d'un seul contrat (et tass de la liste)
  void RemoveAction(CATLONG32 iContractIndex);

  // --------------------------------------------------------------------

  CATAlgoElt     * _OwnerElt;
  CATChainMaster * _OwnerChain;

  CATLONG32               _NbContracts;
  CATLONG32               _NbAllocated;
  Contract         * _List;
};

#endif // fin de debranchement du code pour le coverage

#endif
