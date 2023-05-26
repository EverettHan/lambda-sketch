#ifndef CATErrThrower_H
#define CATErrThrower_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "Ribbon.h"

// fonction globale de lancement d'exception destinee a etre passee par 
// pointeur a un utilitaire de gestion d'erreur (CAThkbftier)

// CATErrThrower recoit une CATError*

void ExportedByRibbon CATErrThrower(void* iData);

// le "define" suivant permet de lancer simplement une erreur en appelant
// CAThkbftier

// exemples: { BFTIERthrow(13,"toto.cpp",ShellCurrentVersion) }
//                      appelle CAThkbftier avec iCod=13, iString="topo.cpp"
//                      et "lance" une CATTopOpIntError
//                      construite avec TopOpIntShellCurrentVersion
//                      (type enumere)
//           { BFTIERthrowInput(13,"toto.cpp",OffsetValue) }
//                      fait la meme chose avec une CATTopOpInError construite
//                      avec TopOpInOffsetValue

// pour appeler CAThkbftier sans lancer d'exception, il suffit de l'appeler
// directement: exemple: CAThkbftier(13,"toto.cpp");

#include "CATTopOpIntError.h"
#include "CATTopOpInError.h"

#include "CAThkbftier.h"

#define BFTIERthrow(ercod,finame,ername) \
            CATTopOpIntError *err =\
	    new CATTopOpIntError( TopOpInt##ername,"TopOpInt##ername",\
				  TopOpIntFile);\
        CAThkbftier(ercod,finame,CATErrThrower,err);

#define BFTIERthrowInput(ercod,finame,ername) \
            CATTopOpInError *err =\
	    new CATTopOpInError( TopOpIn##ername,"TopOpIn##ername",\
				 TopOpInFile );\
        CAThkbftier(ercod,finame,CATErrThrower,err);

#endif
