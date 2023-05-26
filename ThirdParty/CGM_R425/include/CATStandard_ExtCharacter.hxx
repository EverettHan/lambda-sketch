//============================================================================
//==== Titre: CATStandard_ExtCharacter.hxx
//==== Role : The headr file of primitve type "ExtCharacter" from package 
//====        "CATStandard"
//==== 
//==== Implementation:  This is a primitive type implemented with typedef
//====                  Excepting "Unicod encoding"
//============================================================================

#ifndef _CATStandard_ExtCharacter_HeaderFile
#define _CATStandard_ExtCharacter_HeaderFile

#ifndef _CATStandard_ctype_HeaderFile
#include "CATStandard_ctype.hxx"
#endif

#include <string.h>

//typedef short CATStandard_ExtCharacter;

#include "SysCascade.h"

#ifndef _CATStandard_TypeDef_HeaderFile
#include "CATStandard_TypeDef.hxx"
#endif
//#ifndef _CATStandard_Integer_HeaderFile
//#include "CATStandard_Integer.hxx"
//#endif
//#ifndef _CATStandard_Character_HeaderFile
//#include "CATStandard_Character.hxx"
//#endif

class Handle_CATStandard_Type;
/*
#ifndef ExportedBySysCascade 
# ifdef WNT
#  ifdef __CATStandard_DLL
#   define ExportedBySysCascade  __declspec( dllexport )
#  else
#   define ExportedBySysCascade  __declspec( dllimport )
#  endif  // __CATStandard_DLL
# else
#  define ExportedBySysCascade 
# endif  // WNT
#endif  // ExportedBySysCascade 
*/
ExportedBySysCascade  Handle_CATStandard_Type& CATStandard_ExtCharacter_Type_();
//class CATStandard_OStream;
//void ShallowDump (const CATStandard_ExtCharacter, CATStandard_OStream& );
// =====================================
// Method implemented in CATStandard_ExtCharacter.cxx
// =====================================
ExportedBySysCascade  CATStandard_Integer HashCode(const CATStandard_ExtCharacter, const CATStandard_Integer);

// ===============================================
// Methods from CATStandard_Entity class which are redefined:  
//    - Hascode
//    - IsEqual
//    - IsSimilar
//    - Shallowcopy
//    - ShallowDump
// ===============================================

// ===============
// inline methods 
// ===============

// ------------------------------------------------------------------
// ToExtCharacter : Returns an ExtCharacter from a Character
// ------------------------------------------------------------------
inline CATStandard_ExtCharacter ToExtCharacter(const CATStandard_Character achar)
{
//  extension a zero (partie haute-->octet de gauche) de achar
    CATStandard_ExtCharacter val = (achar & 0x000000ff) ;
    return val;
}

// ------------------------------------------------------------------
// ToCharacter : Returns an Character from an ExtCharacter
// ------------------------------------------------------------------
inline CATStandard_Character ToCharacter(const CATStandard_ExtCharacter achar)
{
//  recuperer partie basse(octet de droite) de achar
    CATStandard_Character val = (achar & 0x000000ff) ;
    return val;
}

// ------------------------------------------------------------------
// IsAnAscii : Returns True if an ExtCharacter is in the "Ascii Range"
// ------------------------------------------------------------------
inline CATStandard_Boolean IsAnAscii(const CATStandard_ExtCharacter achar)
{
    CATStandard_Integer j = ( (achar & 0x0000ff00) >> 8);
    if (j != 0 ) 
          return CATStandard_False;
    else
          return CATStandard_True;
}

// ------------------------------------------------------------------
// IsEqual : Returns CATStandard_True if two characters have the same value
// ------------------------------------------------------------------
inline CATStandard_Boolean IsEqual(const CATStandard_ExtCharacter One,
				const CATStandard_ExtCharacter Two)
{ return One == Two; }

// ------------------------------------------------------------------
// IsSimilar : Returns CATStandard_True if two characters have the same value
// ------------------------------------------------------------------
inline CATStandard_Boolean IsSimilar(const CATStandard_ExtCharacter One, 
				  const CATStandard_ExtCharacter Two)
{ return One == Two; }


// ------------------------------------------------------------------
// ShallowCopy : Make a copy of one Character
// ------------------------------------------------------------------
inline CATStandard_ExtCharacter ShallowCopy (const CATStandard_ExtCharacter me) 
{ return me; }

#endif














