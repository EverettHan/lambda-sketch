// COPYRIGHT DASSAULT SYSTEMES 2019, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : ZUT
//
// DESCRIPTION  : Face pairing types for FacePairingAnalyzer
//
//=============================================================================
// Creation ZUT September 2019
//=============================================================================

#ifndef CATFacePairingTypeDef_H
#define CATFacePairingTypeDef_H 

#include "CATDataType.h"

/** @nodoc @nocgmitf */
enum CATFacePairingType
{
  CATFacePairingUnknown      = 0x00,
  CATFacePairingExact        = 0x01,
  CATFacePairingMirror       = 0x02,
  CATFacePairingVariable     = 0x04 
};

typedef CATULONG32 CATFacePairingTypes;

#define CATFacePairingAllTypes ( CATFacePairingExact | CATFacePairingMirror | CATFacePairingVariable )

/** @nodoc @nocgmitf */
enum CATFacePairingMode
{
  CATFacePairingModeUnknown     = 0x00,
  CATFacePairingModeLogical     = 0x01,
  CATFacePairingModeGeometrical = 0x02
};

typedef CATULONG32 CATFacePairingModes;

#define CATFacePairingAllModes ( CATFacePairingModeLogical | CATFacePairingModeGeometrical )

/** @nodoc @nocgmitf */
enum CATFacePairingComputationMode
{
  CATFacePairingComputationLight          = 0,
  CATFacePairingComputationNormal         = 1,
  CATFacePairingComputationAccurate       = 2,
  CATFacePairingComputationFilletLight    = 3,
  CATFacePairingComputationFilletNormal   = 4,
  CATFacePairingComputationFilletAccurate = 5
};

#include "CATFacePairingTypeDef_priv.h"

#endif /* CATFacePairingTypeDef_H */
