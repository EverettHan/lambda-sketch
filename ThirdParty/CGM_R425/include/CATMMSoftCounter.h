/**
 * @COPYRIGHT: DASSAULT SYSTEMES 2002
 *
 * @Description: Macros and Definitions of MipMip Software Counters
 *
 * @History:
 *   Nov. 2002: Raphael Junqueira (RJA): 
 *     - MipMip New Architecture (Version 3) and Windows Software Counter Implemetation 
 *   Nov. 2002: David Morisot (DMO): 
 *     - Promotion to System
 *   Dec. 2002: Raphael Junqueira (RJA): 
 *     - Sun Software Counter Implemetation 
 */

#if !defined( __CATMMSoftCounter_h__)
#define        __CATMMSoftCounter_h__

/**
 * RJA:
 * @WARNING: ce fichier est un header PRIVE !!!
 *   Ne peut etre utilise sans l'autorisation de FCV, RJA, LLE, SGT, DMO ou FBQ 
 * 
 * @WARNING: this file is a PRIVATE header !!!
 *   DO NOT USE without FCV, RJA, LLE, SGT, DMO or FBQ permission
 */

/// active les compteurs d'appels
#define MM_CALL_COUNTER 1

#if defined( MM_CALL_COUNTER )

# if defined( _WINDOWS_SOURCE )
#  define ExportedBydsMMModel __declspec(dllimport)
#  define StandardCall _cdecl
# else
#  define ExportedBydsMMModel
#  define StandardCall 
# endif

/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#  if defined( __dsMMTestLib ) || defined( __JS0CORBA )
# define ExportedByMMSoftwareCounter  DSYExport
#else  // __dsMMTestLib || __JS0CORBA
# define ExportedByMMSoftwareCounter  DSYImport
#endif // __dsMMTestLib || __JS0CORBA

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
#include "DSYExport.h"

/// les types des fonctions
typedef void (StandardCall *dsMMSoftwareCounterFunc_t)(void);

/// fonctions drivers des software counter
extern "C" ExportedBydsMMModel int dsMMIncSoftwareCounter(void);

/// fonctions d'initialisations des software counter
extern "C" ExportedByMMSoftwareCounter dsMMSoftwareCounterFunc_t getCATMMIncSoftwareCounterFunc(void);

/**
 * RJA: Ci dessous se trouve les macros d'acces publique au software-counter
 *  le code est auto-suffisant.
 *
 *  @WARNING: actuellement celles-ci sont uniquement active sous windows
 *  @WARNING: le code des software compteurs est non reentrant (cf dsMMModel.cpp dans le code MipMip)
 */

#include "CATBaseUnknown.h"
#include "CATLib.h"

#if !defined( CNEXT_CLIENT ) || defined( __dsMMTestLib )
# include <stdlib.h>

/**
 * Macro de verification du niveau voulu des software counter cf env('MIPMIP_COUNTER')
 *
 * @val 0 ou non value: desactive les software counter 
 * @val 1 software counter de base
 *
 * @WARNING: toute autre valeur n'est actuellement pas prise en compte
 */
# define CATCheckdsMMSoftwareCounterLevelBegin \
{ \
  static int s_level = -1; \
  const char* cntLevel = NULL; \
  /*if (0 == s_level) return 0;*/ \
  if (-1 == s_level) { cntLevel = ::CATGetEnv("MIPMIP_COUNTER"); s_level = ((NULL != cntLevel) ? atoi(cntLevel) : 0); } \
  if (0  < s_level) { 

# define CATCheckdsMMSoftwareCounterLevelEnd \
  } \
}

/**
 * Fonction de classique software-counter
 * @WARNING: a utiliser avec d'enormes precautions car penalise le temps d'execution
 */
# if defined( _WINDOWS_SOURCE )
#  define CATMMIncSoftwareCounter \
{ \
    CATCheckdsMMSoftwareCounterLevelBegin \
      static dsMMSoftwareCounterFunc_t dsMMIncSoftwareCounter_f = NULL; \
      if (NULL == dsMMIncSoftwareCounter_f) { \
        dsMMIncSoftwareCounter_f = getCATMMIncSoftwareCounterFunc(); \
      } \
      if (NULL != dsMMIncSoftwareCounter_f) { \
        (*dsMMIncSoftwareCounter_f)(); \
      } \
    CATCheckdsMMSoftwareCounterLevelEnd \
}

# elif defined( _SUNOS_SOURCE )
#  define CATMMIncSoftwareCounter \
{ \
    CATCheckdsMMSoftwareCounterLevelBegin \
      static dsMMSoftwareCounterFunc_t dsMMIncSoftwareCounter_f = NULL; \
      if (NULL == dsMMIncSoftwareCounter_f) { \
        dsMMIncSoftwareCounter_f = getCATMMIncSoftwareCounterFunc(); \
      } \
      if (NULL != dsMMIncSoftwareCounter_f) { \
        (*dsMMIncSoftwareCounter_f)(); \
      } \
    CATCheckdsMMSoftwareCounterLevelEnd \
}
# else
// portage != _WINDOWS_SOURCE && portage != _SUNOS_SOURCE
#  define CATMMIncSoftwareCounter
# endif
#else // CNEXT_CLIENT
# define CATMMIncSoftwareCounter
#endif

#endif // MM_CALL_COUNTER

#endif // __dsMMSoftCounter_h__
