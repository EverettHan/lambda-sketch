/* -*-C++-*-*/
#ifndef CATImplicitVersioningHelp_H
#define CATImplicitVersioningHelp_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2021
//
// CATImplicitVersioningHelp 
//
// DESCRIPTION :
// Manage the versioning according to a software configuration and the current bsf level
// Created from versionin help in GMPoly FWs
//
// History
//
// Nov 2021 WZC Creation
//
//=============================================================================

#include "GMScalarFieldsOperators.h" // ExportedBy

#include "CATErrorDef.h"        // HRESULT
#include "CATMathInline.h"      // inline Methods

#include "CATBoolean.h" 
#include "CATSysBoolean.h" 

#include "CATIAV5Level.h"

class CATSoftwareConfiguration;

// ------------------------------------------------------------------------------
/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMScalarFieldsOperators CATImplicitVersioningHelp
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
    _V5R31SP4_V6R423_FD08_ = 9899
  };
  // Beware, CXR30 is the only level where we are not downporting our code. Promotions to 31/423 are ported to 422 only.

public:

  /**
  * Constructor
  */
  CATImplicitVersioningHelp (CATSoftwareConfiguration * iConfig=NULL);

  /**
  * Destructor
  */
  ~CATImplicitVersioningHelp();

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
  CATSoftwareConfiguration * UpdateLevel(CATImplicitVersioningHelp::DefaultLevel iRequestedLevel = _V5R29SP4_V6R421_FD04_);

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

  CATImplicitVersioningHelp & operator =(const CATImplicitVersioningHelp & iOneOf);
  CATImplicitVersioningHelp(const CATImplicitVersioningHelp & iOneOf); 


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

INLINE CATBoolean CATImplicitVersioningHelp::CheckActivationLevel(int iVersioningVarValue) {
  CATBoolean ret = (_ConfigLevel >= iVersioningVarValue);
  return ret; }

INLINE CATSoftwareConfiguration * CATImplicitVersioningHelp::GetSoftwareConfiguration() {
  return _Config;
}

#endif
