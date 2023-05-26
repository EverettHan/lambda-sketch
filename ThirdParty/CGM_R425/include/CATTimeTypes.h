/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//								   
// CATLimitsTime:						   
//          Definitions de Variables pour CATTime et CATTimeSpan
//
//=============================================================================
//
// Ces definitions permettront de faciliter une possible migration future vers
// un autre type de base que time_t, ce qui impliquera unemodification de
// l'intervalle de dates admissibles.
//
// Pour time_t, l'intervalle est le suivant :
//
//                   du 01 janvier 1970 au 18 Janvier 2038
//
//=============================================================================
//								   
// November 97   No base for Creation L. JOSEPH (LJH) 
//								   
//=============================================================================
#ifndef CATTIMETYPES_H
#define CATTIMETYPES_H

#include <time.h>
#include <wchar.h>

// Pour la longueur max de la chaine en sortie de Format
// Restriction du a l'utilisation de la fonction strftime
// Cependant, cette restriction ne s'applique pas a la methode ConvertToString
#define MAX_SIZE_STRING 30

// Les restrictions suivantes sont dues a l'utilisation du type time_t
// Les dates et heures doivent etre comprise dans l'intervalle suivant :
#ifdef PLATEFORME_DS64
#define _MORE_SPAN
#else // PLATEFORME_DS64
#undef _MORE_SPAN
#endif  // PLATEFORME_DS64
#ifdef _MORE_SPAN
// ==============> du 01 janvier 1970 au 18 Janvier 2200 <==============
# define MAX_TIMESPAN 7259587200
# define DAYS_MAX     84023
# define YEAR_MAX     2200
#else // _MORE_SPAN
// ==============> du 01 janvier 1970 au 18 Janvier 2038 <==============
# define MAX_TIMESPAN 2147385600
# define DAYS_MAX     24854
# define YEAR_MAX     2038
#endif  // _MORE_SPAN

#define YEAR_MIN  1970

#define MONTH_MAX 1

#define DAY_MAX   18

#endif
