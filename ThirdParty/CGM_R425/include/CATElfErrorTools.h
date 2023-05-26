#ifndef CATElfErrorTools_H
#define CATElfErrorTools_H

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// Routines factorisant du code autour de la gestion des erreurs.              
//
// Les 2 méthodes sont ammenées à générer une trace contenant la call stack.
//
//=============================================================================

// ExportedByCATELFMathKernel
#include "CATELFMathKernel.h"
// class CATElfTypeEncapError
#include "CATElfTypeEncapError.h"
// NULL macro
#include <stddef.h>

class ExportedByCATELFMathKernel CATElfErrorTools
{
    
public :
    
// -----------------------------------------------------------------------
// CATElfErrorTools::Create : creation d'une erreur avec son message
// -----------------------------------------------------------------------
//
// Exemple d'utilisation :
// -----------------------
// 
// supposons que l'on veuille generer l'erreur (fictive) numero 687 qui 
// necessite de passer comme donnees 1 int, 2 doubles, et une chaine
// de caractere.
//
// supposons que dans le programme on a les variables suivantes :
//   int numelt			(numero de l'element en cours)
//   int* ier			(qui pointe sur la valeur 687)
//   float epaisseur	(une valeur recuperee)
//
// appel :
//   CATElfErrorTools::Create(*ier,numelt,"SHELL3D",double(epaisseur),10e-12) ;
//
// Remarques :
// -----------
// 
// - seul l'ordre d'apparition des donnees au sein du meme type compte
// - les erreur n'acceptent pas les parametres R4 (float), il est donc
//   necessaire de convertir le float en double par une conversion 
//   explicite.
//
// -----------------------------------------------------------------------

    static void Create(int ier, 
					   CATElfTypeEncapError p1 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p2 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p3 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p4 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p5 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p6 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p7 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p8 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p9 =CATElfTypeEncapError::EmptyEncapEr
					   ) ;

// -----------------------------------------------------------------------
// CATElfErrorTools::CreateError : creation d'une erreur avec son message
//                                 en specifiant le Catalogue d'erreurs
// -----------------------------------------------------------------------
//
// Exemple d'utilisation :
// -----------------------
// 
// supposons que l'on veuille generer l'erreur (fictive) numero 687 qui 
// necessite de passer comme donnees 1 int, 2 doubles, et une chaine
// de caractere.
//
// supposons que dans le programme on a les variables suivantes :
//   int numelt			(numero de l'element en cours)
//   int* ier			(qui pointe sur la valeur 687)
//   float epaisseur	(une valeur recuperee)
//
// appel :
//   CATElfErrorTools::Create(*ier,numelt,"SHELL3D",double(epaisseur),10e-12) ;
//
// Remarques :
// -----------
// 
// - seul l'ordre d'apparition des donnees au sein du meme type compte
// - les erreur n'acceptent pas les parametres R4 (float), il est donc
//   necessaire de convertir le float en double par une conversion 
//   explicite.
//
// -----------------------------------------------------------------------

   static void CreateError(int ier, 
             const char* MsgCatalog, 
					   CATElfTypeEncapError p1 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p2 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p3 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p4 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p5 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p6 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p7 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p8 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p9 =CATElfTypeEncapError::EmptyEncapEr
					   ) ;

// -----------------------------------------------------------------------
// CATElfErrorTools::CreateWarning :creation d'un warning avec son message
//                                  en specifiant le Catalogue d'erreurs
// -----------------------------------------------------------------------
//
// Exemple d'utilisation :
// -----------------------
// 
// supposons que l'on veuille generer l'erreur (fictive) numero 687 qui 
// necessite de passer comme donnees 1 int, 2 doubles, et une chaine
// de caractere.
//
// supposons que dans le programme on a les variables suivantes :
//   int numelt			(numero de l'element en cours)
//   int* ier			(qui pointe sur la valeur 687)
//   float epaisseur	(une valeur recuperee)
//
// appel :
//   CATElfErrorTools::Create(*ier,numelt,"SHELL3D",double(epaisseur),10e-12) ;
//
// Remarques :
// -----------
// 
// - seul l'ordre d'apparition des donnees au sein du meme type compte
// - les erreur n'acceptent pas les parametres R4 (float), il est donc
//   necessaire de convertir le float en double par une conversion 
//   explicite.
//
// -----------------------------------------------------------------------

   static void CreateWarning(int ier, 
             const char* MsgCatalog, 
					   CATElfTypeEncapError p1 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p2 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p3 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p4 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p5 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p6 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p7 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p8 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p9 =CATElfTypeEncapError::EmptyEncapEr
					   ) ;

// -----------------------------------------------------------------------
// CATElfErrorTools::Create : creation d'une erreur programme (ier=301)
// avec eventuellement un message. Attention, le message est vu par le 
// client.
// -----------------------------------------------------------------------
//
//   CATElfErrorTools::Create("J'ai un problème au doigt de pied.") ;
//
// -----------------------------------------------------------------------

    static void Create(const char* iMessage=NULL) ;
};


// pour le coverage
//void ExportedByCATELFMathKernel TestErrorCreation() ;

// pour ne pas être obligé de faire l'impact tout de suite
// dans les routines qui utilisent l'ancienne version
// Attention, cette routine n'est pas exportée

void ExportedByCATELFMathKernel CreateElfiniError(int ier, 
					   CATElfTypeEncapError p1 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p2 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p3 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p4 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p5 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p6 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p7 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p8 =CATElfTypeEncapError::EmptyEncapEr,
					   CATElfTypeEncapError p9 =CATElfTypeEncapError::EmptyEncapEr
					   ) ;
#endif
