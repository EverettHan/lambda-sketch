//-------------------------------------------------------------------------
// COMPOSANT : COMPONENTV2
//
//-------------------------------------------------------------------------
//  HISTORIQUE :   
//      Creation   97/01/12                                           ADH
//-------------------------------------------------------------------------
//    Definition de la macro a placer en tete du fichier source genere -
//    La Shared-Library de la carte d'identite est construite a partir
//    de ce fichier genere 
//    
//    Include dans le fichier CATComponent.h
//
//--------------------------------------------------------------------------

#ifndef _CATIDENTITYMACRO_H_
#define _CATIDENTITYMACRO_H_


// COPYRIGHT DASSAULT SYSTEMES 2000

//
// --> Parametres de WINDOWS_NT
//
#if defined __IdentityCard
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
//     FWname       : nom original du Framework (avec son extension eventuelle)
//     FWmacroIdent : macro-identificateur calcule a partir du nom original du Framework
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
#define FWnameStr(t)  #t

#define GenerateIdentityCard(FWname, FWmacroIdent)                                                    \
        class ExportedByIdentityCard FWmacroIdent : public CATComponent { public: FWmacroIdent (); }; \
        extern "C" ExportedByIdentityCard void* fctCreate(FWmacroIdent) (void);                       \
        void* fctCreate(FWmacroIdent) (void) { return (new FWmacroIdent ()); }                        \
        FWmacroIdent::FWmacroIdent (void) : CATComponent(FWnameStr(FWname))

#endif /* _CATIDENTITYMACRO_H_ */
