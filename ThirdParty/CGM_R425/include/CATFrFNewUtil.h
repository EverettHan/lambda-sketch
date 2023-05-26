#ifndef CATFrFNewUtil_H
#define CATFrFNewUtil_H

#include "FrFAdvancedObjects.h"
//==========================================================================
// Essai de chapeau d'allocateur pour 
// - trier les allocations mal gerees / bien gerees (avec test de pointeur et sortie en erreur)
// - ne pas tomber n fois sur les memes piles d'appel
// - conserver un mecanisme standard d'allocation/liberation (par delete [])
//   ce qui permet de communiquer l'allocation resultat d'objet en objet
//==========================================================================
// 07/08/13 NLD Creation avec CATFrFNewDouble()
// 17/09/13 NLD Ajout    de   CATFrFNewInt()
//              Ajout    de   CATFrFNewLong32
//              Ajout    de   CATFrFNewArrayOfPointers()
//              Ajout    de   CATFrFNewArrayOfMathVectors()
//              Ajout    de   CATFrFNewArrayOfMathPoints()
//              Ajout    de   CATFrFNewArrayOfMathBoxes()
//              Ajout    de   CATFrFNewArrayOfCrvLimits()
//==========================================================================
#include <CATDataType.h>
class CATMathPoint;
class CATMathVector;
class CATMathBox;
class CATCrvLimits; // #include <CATCrvLimits.h>

// voir aussi ExportedByCATMathematics  double *CATCGMTemporaryArrayDoubleNew(const size_t iNumberOfDouble,

// ces deux macros utilisees pour l'argument iThrow permettent des appels clairs sans definition d'une variable locale
#define CATFrFNewThrow_TRUE  1
#define CATFrFNewThrow_FALSE 0

// Secured allocation of a  double        array (must be deleted by delete[])
ExportedByFrFAdvancedObjects double        * CATFrFNewDouble            (const size_t iNumberOfElem, int iThrow = CATFrFNewThrow_TRUE);

// Secured allocation of an int           array (must be deleted by delete[])
ExportedByFrFAdvancedObjects int           * CATFrFNewInt               (const size_t iNumberOfElem, int iThrow = CATFrFNewThrow_TRUE);

// Secured allocation of a  CATLONG32     array (must be deleted by delete[])
ExportedByFrFAdvancedObjects CATLONG32     * CATFrFNewLong32            (const size_t iNumberOfElem, int iThrow = CATFrFNewThrow_TRUE);

// Secured allocation of a  pointers      array (must be deleted by delete[]) (pointers array means void* array)
ExportedByFrFAdvancedObjects void*         * CATFrFNewArrayOfPointers   (const size_t iNumberOfElem, int iThrow = CATFrFNewThrow_TRUE);

// Secured allocation of a  CATMathPoint  array (must be deleted by delete[])
ExportedByFrFAdvancedObjects CATMathPoint  * CATFrFNewArrayOfMathPoints (const size_t iNumberOfElem, int iThrow = CATFrFNewThrow_TRUE);

// Secured allocation of a  CATMathVector array (must be deleted by delete[])
ExportedByFrFAdvancedObjects CATMathVector * CATFrFNewArrayOfMathVectors(const size_t iNumberOfElem, int iThrow = CATFrFNewThrow_TRUE);

// Secured allocation of a  CATMathBox    array (must be deleted by delete[])
ExportedByFrFAdvancedObjects CATMathBox    * CATFrFNewArrayOfMathBoxes  (const size_t iNumberOfElem, int iThrow = CATFrFNewThrow_TRUE);

// Secured allocation of a  CATCrvLimits  array (must be deleted by delete[])
ExportedByFrFAdvancedObjects CATCrvLimits  * CATFrFNewArrayOfCrvLimits  (const size_t iNumberOfElem, int iThrow = CATFrFNewThrow_TRUE);

#endif
