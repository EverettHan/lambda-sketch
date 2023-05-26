// COPYRIGHT DASSAULT SYSTEMES 2021, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : ZUT
//
// DESCRIPTION  : Software bridge allowing dynamic loading of the pairing
//                recognition service from outside of the TopologicalOperators library
//
//=============================================================================
// Creation ZUT April 2021
//=============================================================================

//=============================================================================
// April  2021  Creation                                        ZUT
//=============================================================================


#ifndef CATTopPairingRecognizerOpeBridge_H
#define CATTopPairingRecognizerOpeBridge_H

#include "AdvOpeInfra.h"
#include "ListPOfCATFace.h"
#include "CATListOfDouble.h"
#include "CATSysBoolean.h"
#include "IUnknown.h"

class CATGeoFactory;
class CATTopData;
class CATBody;

extern "C" ExportedByAdvOpeInfra HRESULT CATRunPairingRecognition(CATGeoFactory           *  iFactory,
                                                                  CATTopData              *  iTopData,
                                                                  CATBody                 *  iInputBody,
                                                                  double                     iMaxThickness,
                                                                  const CATLISTP(CATFace)  & iSubsetOfFaces,
                                                                  CATBoolean                 iKeepFacePairingAttributes,
                                                                  CATLISTP(CATFace)          oListsOfPairingFaces[2],
                                                                  CATListOfDouble          & oMaxDistances);

#endif /* CATTopPairingRecognizerOpeBridge_H */
