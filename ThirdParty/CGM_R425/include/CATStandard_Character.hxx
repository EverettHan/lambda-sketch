//============================================================================
//==== Titre: CATStandard_Character.hxx
//==== Role : The headr file of primitve type "Character" from package 
//====        "CATStandard"
//==== 
//==== Implementation:  This is a primitive type implementadef with typedef
//====        typedef char CATStandard_Character
//============================================================================

#ifndef _CATStandard_Character_HeaderFile
#define _CATStandard_Character_HeaderFile

#ifndef _CATStandard_ctype_HeaderFile
#include "CATStandard_ctype.hxx"
#endif

#include <string.h>

//typedef char  CATStandard_Character;

#include "SysCascade.h"

#ifndef _CATStandard_TypeDef_HeaderFile
#include "CATStandard_TypeDef.hxx"
#endif
//#ifndef _CATStandard_Integer_HeaderFile
//#include "CATStandard_Integer.hxx"
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

ExportedBySysCascade  Handle_CATStandard_Type& CATStandard_Character_Type_();

//class CATStandard_OStream;
//void ShallowDump (const CATStandard_Character, CATStandard_OStream& );
// =====================================
// Method implemented in CATStandard_Character.cxx
// =====================================
ExportedBySysCascade  CATStandard_Integer   HashCode(const CATStandard_Character, const CATStandard_Integer);

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
// IsEqual : Returns CATStandard_True if two characters have the same value
// ------------------------------------------------------------------
inline CATStandard_Boolean IsEqual(const CATStandard_Character One,
				const CATStandard_Character Two)
{ return One == Two; }

// ------------------------------------------------------------------
// IsSimilar : Returns CATStandard_True if two characters have the same value
// ------------------------------------------------------------------
inline CATStandard_Boolean IsSimilar(const CATStandard_Character One, 
				  const CATStandard_Character Two)
{ return One == Two; }


// ==================================================================
// IsAlphabetic : Returns CATStandard_True if a character is alphabetic
// ==================================================================
inline CATStandard_Boolean IsAlphabetic(const CATStandard_Character me) 
{ return isalpha(me); }

// ==================================================================
// IsDigit : Returns CATStandard_True if a character is a digit
// ==================================================================
inline CATStandard_Boolean IsDigit(const CATStandard_Character me) 
{ return isdigit(me); }

// ==================================================================
// IsAlphanumeric : Returns CATStandard_True if a character is alphanumeric
// ==================================================================
inline CATStandard_Boolean IsAlphanumeric(const CATStandard_Character me) 
{ return (IsAlphabetic(me) || IsDigit(me)) ; }

// ==================================================================
// IsControl : Returns CATStandard_True if a character  is a control character
// ==================================================================
inline CATStandard_Boolean IsControl(const CATStandard_Character me) 
{ return iscntrl(me); }


// ==================================================================
// IsGraphic : Returns CATStandard_True if a character is graphic
// ==================================================================
inline CATStandard_Boolean IsGraphic(const CATStandard_Character me) 
{ return isgraph(me); }

// ==================================================================
// IsLowerCase : Returns CATStandard_True if a character is lowercase
// ==================================================================
inline CATStandard_Boolean IsLowerCase(const CATStandard_Character me) 
{ return islower(me); }

// ==================================================================
// IsPrintable : Returns CATStandard_True if a character is printable
// ==================================================================
inline CATStandard_Boolean IsPrintable(const CATStandard_Character me) 
{ return isprint(me); }

// ==================================================================
// IsPunctuation : Returns CATStandard_True if a character is a graphic and 
//                 not a alphanumeric character
// ==================================================================
inline CATStandard_Boolean IsPunctuation(const CATStandard_Character me) 
{ return ( IsGraphic(me) && !IsAlphanumeric(me)); }

// ==================================================================
// IsSpace : Returns CATStandard_True if a character is a space
// ==================================================================
inline CATStandard_Boolean IsSpace(const CATStandard_Character me) 
{ return isspace(me); }

// ==================================================================
// IsUppercase : Returns CATStandard_True if a character is uppercase
// ==================================================================
inline CATStandard_Boolean IsUpperCase(const CATStandard_Character me) 
{ return isupper(me); }

// ==================================================================
// LowerCase : Returns a lowercase character
// ==================================================================
inline CATStandard_Character LowerCase(const CATStandard_Character me) 
{ return tolower(me); }

// ==================================================================
// UpperCase : Returns a uppercase character
// ==================================================================
inline CATStandard_Character UpperCase(const CATStandard_Character me) 
{ return toupper(me); }

// ------------------------------------------------------------------
// ShallowCopy : Make a copy of one Character
// ------------------------------------------------------------------
inline CATStandard_Character ShallowCopy (const CATStandard_Character me) 
{ return me; }

#endif














