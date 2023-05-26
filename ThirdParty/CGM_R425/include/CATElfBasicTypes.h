#ifndef CATElfBasicTypes_H
#define CATElfBasicTypes_H

/** =============================================================
  * COPYRIGHT DASSAULT SYSTEMES 1999
  * =============================================================
  *
  * This header defines some basic types which are garanteed to 
  * have a certain size (given in bytes) throughout all the operating
  * systems.
  *
  * The purpose of this is to maintain compatibility with the 
  * fortran routines for which types are directly associated
  * with the amount of memory they use, e.g. INTEGER*4,  
  * REAL*8 etc...
  *
  * For the moment, the declaration are not O.S. dependant.
  * 
  * Note that the System framework also defines the same kind
  * of types but the file (liblum.h where the sizes are in bits)
  * is larger and depends on other files.
  * 
  * =============================================================
  */

typedef float                   Real4 ;
typedef double                  Real8 ;

typedef short                Integer2 ;
typedef unsigned short      UInteger2 ;
typedef int                  Integer4 ;
typedef unsigned int        UInteger4 ;
/*
typedef long                 Integer4 ;
typedef unsigned long       UInteger4 ;
typedef long long            Integer8 ;
typedef unsigned long long  UInteger8 ;
*/

#ifdef PLATEFORME_DS64
#ifdef _WINDOWS_SOURCE
#define LongInt __int64
#else
#define LongInt long long
#endif
#else
#define LongInt size_t
#endif



#endif
