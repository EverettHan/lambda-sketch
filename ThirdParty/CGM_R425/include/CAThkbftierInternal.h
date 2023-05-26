#ifndef CAThkbftierInternal_H
#define CAThkbftierInternal_H

// COPYRIGHT DASSAULT SYSTEMES 2008

#include "CATDataType.h"
#include "Thick.h"

// fonction globale de traitement d'erreur destinee a assister le debug interne

// -> affiche un message qui explicite l'origine de l'erreur (grace au numero
// d'erreur "icod" et a la string (par exemple le nom du .cpp) fournis en
// arguments

// -> appelle une fonction fournie par son pointeur, en lui passant un bloc de
// donnees (void*) fourni aussi en argument. Cela permet en particulier de
// lancer une exception (CATThrow), en passant CATErrThrower(void*) comme
// pointeur sur fonction iPF, et une CATError* a la place du (void*) iData.

// exemples d'utilisation:
// CAThkbftier(17,"CATToto.cpp");  // affiche simplement le message (err. num.17)
// CAThkbftier(17,"CATToto.cpp",CATErrThrower,MyError) // fait un CATThrow 

// -> eventuellement, cree un "checkpoint" du debugger interactif qui permet de
// reprendre la main dans le frame Cnext avt que le traitement ne se poursuive
// Pour cela, il faut que le fichier pointe par $DBGSPECFILE contienne la
// sequence de 3 lignes suivantes (sans les // en debut de ligne):
// begin checkpt
// TopologicalOperators/Thick.m/src/CAThkbftier.cpp=1
// end checkpt
extern "C"
{

void ExportedByThick CAThkbftierInternal(const CATLONG32 iCod,
			                                   const char* iString,
			                                   void(*iPF)(void*),
			                                   void* iData);
}

#endif
