#ifndef _CATStandard_Macro_HeaderFile
#define _CATStandard_Macro_HeaderFile

#define	  Handle(ClassName)  Handle_##ClassName
#define	  Oid(ClassName)     Oid_##ClassName

#define   STANDARD_TYPE(aType)   aType##_Type_()

#ifdef WNT
/*
# ifndef ExportedBySysCascade 
#  define ExportedBySysCascade  __declspec( dllexport )
# endif  // ExportedBySysCascade
*/
# ifndef CATStandard_IMPORT
#  define CATStandard_IMPORT __declspec( dllimport )
# endif  /* CATStandard_IMPORT */

#else  /* WNT */
/*
# ifndef ExportedBySysCascade 
#  define ExportedBySysCascade 
# endif  // ExportedBySysCascade
*/
# ifndef CATStandard_IMPORT
#  define CATStandard_IMPORT
# endif  /* CATStandard_IMPORT */

#endif  /* WNT */

#endif  
