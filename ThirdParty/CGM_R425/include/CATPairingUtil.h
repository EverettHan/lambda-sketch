// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : ZUT
//
// DESCRIPTION  : CATPairingUtil
//                Helper methods for Pairing operators
//
//=============================================================================
// Creation ZUT October 2022
//=============================================================================

#ifndef CATPairingUtil_H
#define CATPairingUtil_H

// ++++ Includes ++++
#include "Thick.h"
#include "IUnknown.h" // For NULL definition (linux)
#include "ListPOfCATFace.h"

// ++++ Predeclarations ++++
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATBody;
class CATFace;
class CATMathPlane;

class ExportedByThick CATPairingUtil
{
public:

  /**
  * IsPlanarCase
  */
  static HRESULT IsCandidateForMirrorPairingPlanarCase(CATGeoFactory            * iFactory,
                                                       CATSoftwareConfiguration * iConfig,
                                                       CATBody                  * iBody,
                                                       const CATLISTP(CATFace)    GroupsOfFacesToPair[2]);

protected:

  //------------------------------------------------------------------------------
  // Forbidden (Declared but not Defined) : Copy constructor & assignment operator
  //------------------------------------------------------------------------------
  CATPairingUtil ( );                                    // Not Implemented
  CATPairingUtil ( const CATPairingUtil & );             // Not Implemented
  CATPairingUtil & operator=( const CATPairingUtil & );  // Not Implemented
};

#endif /* CATPairingUtil_H */
