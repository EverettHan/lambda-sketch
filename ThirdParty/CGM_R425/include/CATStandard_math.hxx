/*
                     Copyright (C) 1991,1995 by

                      MATRA DATAVISION, FRANCE

This software is furnished in accordance with the terms and conditions
of the contract and with the inclusion of the above copyright notice
This software or any other copy thereof may not be provided or otherwise
be made available to any other person. No title to an ownership of the
software is hereby transferred

At the termination of the contract, the software and all copies of this
software must be deleted

Facility : CAS-CADE V1.3A

*/

#ifdef WNT
#include "SysCascade.h"

# ifndef __MATH_WNT_H
#  define __MATH_WNT_H
/*
#  ifndef ExportedBySysCascade 
#   ifdef __CATStandard_DLL
#    define ExportedBySysCascade  __declspec( dllexport )
#   else
#    define ExportedBySysCascade  __declspec( dllimport )
#   endif  /* __CATStandard_DLL */
/*
#  endif  /* ExportedBySysCascade  */

ExportedBySysCascade  double __cdecl acosh ( double );
ExportedBySysCascade  double __cdecl asinh ( double );
ExportedBySysCascade  double __cdecl atanh ( double );

# define M_SQRT1_2  7.0710678118654752440E-1
# define M_PI_2     1.5707963267948966192E0

# endif  /* __MATH_WNT_H */

#endif  /* WNT */

