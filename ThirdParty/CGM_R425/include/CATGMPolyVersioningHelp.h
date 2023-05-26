/* -*-C++-*-*/
#ifndef CATGMPolyVersioningHelp_H
#define CATGMPolyVersioningHelp_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2019
//
// CATGMPolyVersioningHelp 
//
// DESCRIPTION :
// Manage the versioning according to a software configuration and the current bsf level
//
// History
//
// March 2019 DPS Creation
//
//=============================================================================

// For Windows NT export

// En R422, pas besoin d'exportedby, mais ca devient necessaire de facon inconditionnelle sur les niveaux courants off/prj a partir de 31/423
// sans ifdef pour ne pas peter la compil d'envs exotiques
#include "GMPolyUtilities.h" // ExportedBy

#include "CATErrorDef.h"        // HRESULT
#include "CATMathInline.h"      // inline Methods

#include "CATBoolean.h" 
#include "CATSysBoolean.h" 

#include "CATIAV5Level.h"

class CATSoftwareConfiguration;

// ------------------------------------------------------------------------------
/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyUtilities CATGMPolyVersioningHelp
{
public:

  // Centralized default levels
  enum DefaultLevel
  {
    // Oldest default level used in all poly top operators
    _V5R29SP4_V6R421_FD04_ = 8711,
    // Default level for Importer, matches the split 30/31 and 422/423 from january 2020.
    _V5R30SP1_V6R422_FD01_ = 9019,
    // Default level for Partitioning, matches the split 31/32 and 423/424 from june 2021.
    _V5R31SP4_V6R423_FD08_ = 9899,
    // Default level for PolyBodyAdapter, may 2022.
    _V5R32SP2_V6R424_FD03_ = 10313,
    // Default level for CavityExtract, feb 2023.
    _V5R33SP1_V6R425_FD01_ = 10704,
  };
  // Beware, CXR30 is the only level where we are not downporting our code. Promotions to 31/423 are ported to 422 only.

public:

  /**
  * Constructor
  */
  CATGMPolyVersioningHelp (CATSoftwareConfiguration * iConfig=NULL);

  /**
  * Destructor
  */
  ~CATGMPolyVersioningHelp();

  /**
  * Update with a new config.
  * If iConfig is NULL, does nothing.
  */
  void UpdateConfig(CATSoftwareConfiguration * iConfig);

  /**
   * Update with a config level.
   * Default is _GMPolyVersionLevel_V5R29SP4_V6R421_FD04_.
   *            _GMPolyVersionLevel_V5R30SP1_V6R422_FD01_ is also available.
   * Should it be an enum ?
   * If input level <= current level, does nothing.
   */
  CATSoftwareConfiguration * UpdateLevel(CATGMPolyVersioningHelp::DefaultLevel iRequestedLevel = _V5R29SP4_V6R421_FD04_);

  /**
  * Check if a specific variable is activated with current config
  */
  INLINE CATBoolean CheckActivationLevel(int iVersioningVarValue);

  /**
   * Get config
   */
  INLINE CATSoftwareConfiguration * GetSoftwareConfiguration();

  // Check if the current config has a level equal to the BSFLevel
  CATBoolean IsConfigLevelBestSoFar();


private:

  //===========================================================================
  // COPY-CONSTRUCTOR & DEFAULT CONSTRUCTOR  & OPERATOR: No implementation = Not defined
  //===========================================================================

  CATGMPolyVersioningHelp & operator =(const CATGMPolyVersioningHelp & iOneOf);
  CATGMPolyVersioningHelp(const CATGMPolyVersioningHelp & iOneOf); 


private:

  // Input Data
  // ==========

  CATSoftwareConfiguration   * _Config;


  // Internal Data
  // =============

  short                        _ConfigLevel;
};


// INLINE methods
// ---------------

INLINE CATBoolean CATGMPolyVersioningHelp::CheckActivationLevel(int iVersioningVarValue) {
  CATBoolean ret = (_ConfigLevel >= iVersioningVarValue);
  return ret; }

INLINE CATSoftwareConfiguration * CATGMPolyVersioningHelp::GetSoftwareConfiguration() {
  return _Config;
}

#endif
