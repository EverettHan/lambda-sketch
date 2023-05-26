//-------------------------------------------------------------------------
// COMPOSANT : COMPONENTV2
//
//-------------------------------------------------------------------------
//  HISTORIQUE :   
//      Creation   97/06/06                                           ADH
//-------------------------------------------------------------------------
//    Definition de la macro a placer en tete du fichier source genere -
//    La Shared-Library de la carte d'identite est construite a partir
//    de ce fichier genere 
//    
//--------------------------------------------------------------------------

#ifndef _CATIDENTITYMACROPRODUCTINCLUDE_H_
#define _CATIDENTITYMACROPRODUCTINCLUDE_H_


// COPYRIGHT DASSAULT SYSTEMES 2000

//
// --> Parametres de WINDOWS_NT
//
#ifdef __IdentityCard

#define ExportedByIdentityCard DSYExport
#else
#define ExportedByIdentityCard DSYImport
#endif
#include "DSYExport.h"

//==========================================================================
//                  IMPORTATION
//==========================================================================



//==========================================================================
//                  EXPORTATION
//==========================================================================



////////////////////////////////////////////////////////////////////////////
// MACROS
////////////////////////////////////////////////////////////////////////////


//
// ARGUMENTS:
// //////////
//
//     name       : nom original du ProductInclude (avec son extension eventuelle)
//     macroIdent : macro-identificateur calcule a partir du nom original
//                    par la methode CATComponent::MakeMacroIdent
//
// DESCRIPTION:
// ////////////
//
//     1- Definition du point d'entree de la SHARED-LIBRARY necessaire au LOADER-BINDER
//     2- Creation d'une classe derivee de CATComponent pour instanciation 
//     3- Appel du constructeur de la classe derivee pour invocation de constructeur de CATComponent
//     4- Debut de la definition du constructeur de la classe derivee
//

#define fctCreate(t)  fctCreate##t
#define nameStr(t)  #t

#define GenerateIdentityCardProductInclude(name, macroIdent)                                           \
        class ExportedByIdentityCard macroIdent : public CATComponentProductInclude { public: macroIdent (); }; \
        extern "C" ExportedByIdentityCard void* fctCreate(macroIdent) (void);                       \
        void* fctCreate(macroIdent) (void) { return (new macroIdent ()); }                        \
        macroIdent::macroIdent (void) : CATComponentProductInclude(nameStr(name))


#endif






