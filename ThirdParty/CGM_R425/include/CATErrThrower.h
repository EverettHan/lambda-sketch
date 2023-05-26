#ifndef CATErrThrower_H
#define CATErrThrower_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATErrThrowerDeclare.h"
#include "CATTopOpIntError.h"
#include "CATTopOpInError.h"

#include "CAThkbftier.h"

// Les "define" suivant permettent de lancer simplement une erreur en appelant
// CAThkbftier

// exemples: { BFTIERthrow(13,"toto.cpp",
//             ShellCurrentVersion,"ShellCurrentVersion") }
//                      appelle CAThkbftier avec iCod=13, iString="topo.cpp"
//                      et "lance" une CATTopOpIntError
//                      construite avec TopOpIntShellCurrentVersion
//                      (type enumere) associee au message du meme nom
//           { BFTIERthrowInput(13,"toto.cpp",OffsetValue,"OffsetValue") }
//                      fait la meme chose avec une CATTopOpInError construite
//                      avec TopOpInOffsetValue

// pour appeler CAThkbftier sans lancer d'exception, il suffit de l'appeler
// directement: exemple: CAThkbftier(13,"toto.cpp");

#define BFTIERthrow(ercod,finame,ername,ermessage) \
  { CAThkbftierThrowErr(ercod, finame, TopOpInt##ername, ermessage, CATErrThrower); }

#define BFTIERthrowInput(ercod,finame,ername,ermessage) \
  { CAThkbftierThrowInputErr(ercod, finame, TopOpIn##ername, ermessage, CATErrThrower); }


// Le "define" suivant permet de lancer simplement une erreur en appelant
// CAThkbftier

// exemples: { BFTIERthrowJGD(1,"Init",RibbonInitialization); }
//                      appelle CAThkbftier avec iCod=1, iString="Init"
//                      et "lance" une CATTopOpIntError
//                      construite avec TopOpIntRibbonInitialization
//                      (type enumere)

#define BFTIERthrowJGD(ercod,finame,ername) \
            CATTopOpIntError *err =\
	    new CATTopOpIntError( TopOpInt##ername,"TopOpInt##ername",\
				  TopOpIntFile);\
        CAThkbftier(ercod,finame,CATErrThrower,err);


// Le #define suivant permet, pour l'environnement shell, de lancer une exception
// si un pointeur ou un entier est nul.
// La syntaxe d'appel est, par exemple: CAThkAssert(mon_pointeur,4302,__FILE__);
// On peut aussi faire le test de plusieurs variables:
//  CAThkAssert(mon_pointeur1 && mon_pointeur2,4302,__FILE__);
// Une exception de type TopOpIntShell est lancee en cas d'invalidite du pointeur.

#include "ThickLight.h"
ExportedByThickLight void CATThrowForNullPointerThickness( const CATLONG32 ercod, const char * finame );

#define CAThkAssert(ptvalue,ercod,finame)                  \
  if ( !(ptvalue) )                                        \
    CATThrowForNullPointerThickness(ercod, finame)

#endif
