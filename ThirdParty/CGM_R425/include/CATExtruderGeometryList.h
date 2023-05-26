#ifndef CATExtruderGeometryList_H
#define CATExtruderGeometryList_H
// COPYRIGHT DASSAULT SYSTEMES 2010
//=============================================================================
//
// CATExtruder:
// Base class for producing extrusion of Geometric entities. Internal geometry list. (private)
//
//=============================================================================
// Usage notes:
//
// Dedicated to CATExtruder; do not use outside
//=============================================================================

//=============================================================================
// HISTORIC
//=============================================================================
//              Historiquement CATExtruder manipule des CATLISTP(CATGeometry)
// 17/10/10 NLD Classe CATExtruderGeometryList() pour encapsulation des listes d'elements
//              et switch perfos vers hashtables
//              cout de Subscribe sur SweepAllStars passant de 0.11 a 0.03,
//              et gain 1.0s sur Case1235
// 22/10/10 NLD CATExtruderGeometryList est isolée dans un fichier dédié
//              pour facilité de génération de l'interface de CATExtruder
//=============================================================================

// Switch perfos
#include <CATCGMDebugSwitchNLD.h> // A faire avant toutes choses

//=============================================================================
// ALGO OPTIONS
//
//=============================================================================
#ifndef CATCGMDebugSwitchNLD_ForceShuntOldPerfo
  #define CATExtruderGeometryListWithHashTable
#endif
#include "Extrude.h"
#include "CATListOfCATGeometries.h"


#ifdef CATExtruderGeometryListWithHashTable
#include "CATCGMHashTable.h"
#endif

//=============================================================================
// @nocgmitf
class CATExtruderGeometryList
  {
   private:

   #ifdef CATExtruderGeometryListWithHashTable
   CATCGMHashTable       _List;
   #else
   CATLISTP(CATGeometry) _List;
   #endif

   public:

   CATExtruderGeometryList();
   virtual    ~CATExtruderGeometryList();

   // Toutes les fonctions se comportent comme celles des listes:
   // en particulier Locate() , Set() et [] manipulent des positions variant de 1 a la taille utilisée
           int          Size       ();

           int          Locate     (CATGeometry* iElem    );

           // ATTENTION: depuis le switch sur HashTable, ne gère pas les doublons:
           // (ne réalise pas l'ajout, mais ne le dit pas) NLD100222
           void         Append     (CATGeometry* iElem    );

           CATGeometry* operator[] (int          iPos     );
   /*
           void         Set        (int          iPos     ,
                                    CATGeometry* iGeometry);
   */

           void         RemoveAll  ();

  };

#endif

