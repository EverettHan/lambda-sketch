//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATFreeFormOpeVersioning:
//    Header file for the CATFreeFormOpeVersioning class
//
//=============================================================================
//
//=============================================================================
// 14/06/22 JSX Creation (copied from CATIntersectionMultiSurfaceVersioning)
//=============================================================================

#ifndef CATFreeFormOpeVersioning_H
#define CATFreeFormOpeVersioning_H

// Base class
#include "CATPSDirectVersioning.h"

// System macros
#include "CATMathInline.h"

// Standard data types
#include "CATBoolean.h"
#include "CATDataType.h"  // for CATLONG32
#include "CATUnicodeString.h"

// Debug
#include "CATGeoOpDebug.h"



#include <FrFOpeUtil.h>

//=============================================================================

// Activation Weeks
// ----------------

// Note: Creation of this mechanism was in July 2017. Only a limited backwards timeline is kept
//       Older flags are given default active state as of Year2017_Week1

#define FRFOPE_ACTIVATION_WEEKS \
  PSDIRECT_CREATE_WEEK_BEGIN(NotActivated, CATPSDirectVersioning::_NotActivated), \
  PSDIRECT_CREATE_WEEK(Year2022_Week26),  \
  PSDIRECT_CREATE_WEEK(Year2022_Week27),  \
  PSDIRECT_CREATE_WEEK(Year2022_Week34),  \
  PSDIRECT_CREATE_WEEK(Year2022_Week35),  \
  PSDIRECT_CREATE_WEEK(Year2023_Week10),  \
  PSDIRECT_CREATE_WEEK(WeekEnd)

// Versioning Variables
// --------------------

#define FRFOPE_Flags \
  PSDIRECT_CREATE_FLAG_DATA(BdSur_SetOfGuideInCCS,           Year2022_Week26), /* SetOf Guides created in CrvCrvSweep (and not in SweepCrvCrv  */\
  PSDIRECT_CREATE_FLAG_DATA(BdSur_ExactG1,                   Year2022_Week26), /* G1 par difference direct entre le pt de ctrl de la surface G0 et du peigne */\
  PSDIRECT_CREATE_FLAG_DATA(BdSur_UseHomoMesh,               Year2022_Week27), /* Same parametrization for Curves and Combs */\
  PSDIRECT_CREATE_FLAG_DATA(BdSur_BetterOrientation,         Year2022_Week27), /* IR-908350: Prefer interpolation backup for tangential intersections*/\
  PSDIRECT_CREATE_FLAG_DATA(BdSur_ActivateMEC,               Year2022_Week34), /* delay Mise En Compatibilité des Combs , after all creations */       \
  PSDIRECT_CREATE_FLAG_DATA(BdSur_LocalG1Law,                NotActivated),    /* delay Mise En Compatibilité des Combs , after all creations */          \
  PSDIRECT_CREATE_FLAG_DATA(BdSur_CreateCombAfterG0Result,   Year2023_Week10), /* JSX Build G0 Result, then combs then G1 result */
  
// "set FRFOPE_BdSur_SetOfGuideInCCS=1" to activate
// "set FRFOPE_BdSur_SetOfGuideInCCS_OFF=1" to DEactivate

//=============================================================================

// Class for CATFreeFormOpeVersioning versioning
class ExportedByFrFOpeUtil CATFreeFormOpeVersioning : public CATPSDirectVersioning
{
public:

  // Public access to the enum of the order of the flags in the array
  enum _FlagI { StartIndex = -1, FRFOPE_Flags EndIndex };

protected:

  friend class CATFrFObject;

  // Static method to allow limited access to IntersectionMultiSurface versioning
  static const CATFreeFormOpeVersioning& GetVersioning   ();

  // Static method to get the default activation level (NotActivated)
  static       int                       GetDefaultLevel ();

  // Allow replay mechanism to force the current week (for "closed config" replays)
               void                      ForceCurrentWeek(const int iNewWeek) const;

private:

  // Private Member Functions
  // ------------------------

                                         CATFreeFormOpeVersioning();
                                        ~CATFreeFormOpeVersioning() ;
  
  // Update the current activation week if it has been set on the command line
               void                      UpdateCurrentWeek() const;

  // Access to the activation week strings
         const CATUnicodeString        & GetActivationWeekName(const int) const;

  // Private Member Data
  // -------------------

  // Enumeration for the activation weeks
  enum FRFOPE_ActivationWeek { FRFOPE_ACTIVATION_WEEKS };

  // =================================================================================
  // New array initializer syntax --> no need to be static
#ifdef Q48_StaticArraysForVersioning // defined (or not) in CATPSDirectVersioning.h
  // Names of the activation weeks
  static const CATUnicodeString          _FRFOPE_WeekNames[];

  // The flag data
  static const PSDirect_FlagData         _Flags[];
#else
  // Names of the activation weeks
         const CATUnicodeString          _FRFOPE_WeekNames[FRFOPE_ActivationWeek::WeekEnd + 1];

  // The flag data
         const PSDirect_FlagData         _Flags[_FlagI::EndIndex];
#endif
  // =================================================================================
};


//const CATFreeFormOpeVersioning& _VersioningFRFOPE;

// Function for public access to FRFOPE versioning
#define IsFreeFormOpeFlagActive(Flag) _VersioningFRFOPE.IsFlagActive(CATFreeFormOpeVersioning::Flag)





#endif
