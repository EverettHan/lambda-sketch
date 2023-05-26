#ifndef CATCGMNoMoreMemory_H
#define CATCGMNoMoreMemory_H
//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2001
//  Methodologie CGM pour gerer les ressources memoires des objets et des operateurs
//   Pour emission d'un message d'erreur associe aux erreurs d'allocations
//==========================================================================
/*
Si vos ressources memoires sont deja obtenus par les allocateurs securise de style
     Mathematics\ProtectedInterfaces\CATCGMArrays.h
     Mathematics\ProtectedInterfaces\CATCGMNewArray.h
     Mathematics\ProtectedInterfaces\CATCGMVirtual.h
Vous n'avez aucune migration a envisager
*/
/*

  Une saturation de l'espace d'adressage m�moire  provoque des �checs d'allocation et degenere g�n�ralement en coredump.
  Voici des choix tactiques pr�conis�s a CGM pour r�duire ce type de coredump.

  Cette proposition est le choix tactique actuellement en vigueur a CGM (jusqu'a preuve d'une meilleure contre-proposition).
  m�me si de tels sc�narios V5 ne pourront pas �tre aujourd'hui garanti  sans coredump pour les raisons suivantes :
    - d�multiplication cons�quente des allocations directes OS  "a la main" sans protection
    - la certification RunTime (ODT) n'aborde nullement les configurations de saturations m�moires 
        (de plus mkCheckSource impuissant)
    - des offres g�n�riques (Collections/Listes du Fw System) ne sont pas encore robustes 
        en contexte de saturation m�moire

  Les grandes lignes de cette proposition sont :
     0) les objets gerent les requetes en ressources memoires par le biais d'allocateurs securises CATCGMNoMoreMemory.h 
     1) ne pas perdre la caract�risation d'une erreur de type �chec d'allocation 
     2) eviter de pers�v�rer dans les traitements iteratifs sur ce type d'erreur reconnaissable
  Ceci devrait permettre de confronter trop de logiciel en contexte de saturation memoire (Cf remarques precedentes)
  et potentiellement de  permettant a l'utilisateur de reprendre la main  
  et de tenter de sauvegarder son travail en cours (apr�s quelques Close)


 A)  Gestion des objets et op�rateurs g�om�triques conformes a deux lignes directrices suivantes :
 
       1) une CATError interne caracterisable  CATCGMIsANoMoreMemoryError  est lev�e en cas d'�chec d'allocation m�moire
       
        Pour les services ayant une signature a base de HRESULT, 
        on bloque bien sur la remont�e d'exception en traduisant  
        le diagnostic d'�chec avec la valeur ERROR_NOT_ENOUGH_MEMORY.

            a) Offre de services centralises pour les requ�tes en ressources m�moire
                    Cf   CATCGMemory.h  c'est le point de depart ..
                   catcxDoubleNew/catcxDoubleFree             a la place de new double []  et delete [] (double *)  
            b) Surcharge du new/delete par POOL des objets  ( CATICGMObject, ...)
                  rappel il s'agit ici d'un enrobage  des allocations m�moire pour des soucis performance CPU
                    int�grant en plus les notions de duree de vie et de classification.
            c) Surchage du new/delete par classe derivee CATCGMVirtual   ( CATCGMOperator, ...)
                  
          Les ressources m�moires sont donc obtenus par des services du Fw Mathematics
              sur lequel on peut introduire une politique centrale de la gestion m�moire.
          On �vite donc de s'appuyer sur des services operating system ( malloc, new double[] )
          Pour rappel, un �chec d'allocation de malloc m�ne a un pointeur NULL sans lev�e d'exception
          mkCheckSource ne previent pas les coredump si on enchaine directement par un memcpy/memset       

    2) la coh�rence des objets conserv�e malgr� les �checs d'allocations 
          permettant leur nettoyage/desallocation sans souci dans les traitements de CATCatch.
        (on �vite d'anticiper les tailles d'allocations suite a une reallocation)

 B) Usagers du modeleur g�om�trique �vitent de pers�v�rer sur des �checs d'allocation m�moire

      Il faut �viter d'effectuer un Flush pr�matur� sur l erreur sp�cifique de CATCGMNoMoreMemory.h
      Il suffit donc de caract�riser les situations de saturations m�moires selon la m�thodologie suivante
             1)   CATCatch(CATError *erreur)  
         {
            if ( CATCGMIsANoMoreMemoryError(erreur) )
                 ....
         }
      2) if ( HRESULT == ERROR_NOT_ENOUGH_MEMORY )

  L'utilisateur a de meilleure chance de reprendre la main en cas de saturation m�moire,
     pouvant tenter de lib�rer des ressources et sauvegarder l'�tat courant de son travail .

*/
//==========================================================================
#include <stdlib.h>
#include <stddef.h>

#include "CATMathematics.h"
#include "CATErrorMacros.h"
#include "CATCGMBuildDebug.h"
#include "CATCGMThrow.h"
#include "CATBoolean.h"

#include "CATCGMemory.h"

//----------------------------------------------------------------------------------------------
// CATCGMNoMoreMemoryError)     Pour generer un diagnostic d'allocation impossible
// CATCGMIsANoMoreMemoryError)  Pour tester si un diagnostic est celui d'une allocation CGM en echec
// CATCGMNoMoreMemory)          Pour ALLOCATION EN ECHEC , UNE LEVEE D'EXEPTION EST ALORS EMISE 
//----------------------------------------------------------------------------------------------
ExportedByCATMathematics CATError * CATCGMNoMoreMemoryError(size_t iNumberOfBytes); 
ExportedByCATMathematics CATBoolean CATCGMIsANoMoreMemoryError(CATError *iError); 

#define CATCGMNoMoreMemory(iNumberOfBytes) CATCGMThrow( CATCGMNoMoreMemoryError(iNumberOfBytes) )


#endif

