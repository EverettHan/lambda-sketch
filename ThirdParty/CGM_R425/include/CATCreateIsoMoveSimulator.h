// COPYRIGHT DASSAULT SYSTEMES 2020
//=============================================================================
//
// CATCreateIsoMoveSimulator 
//  Method to create a CATTopMaxIsoMoveCalculator
//
//
//=============================================================================
//  June 2020  Creation                                                 DLR6
//=============================================================================

#ifndef CATCreateIsoMoveSimulator_H
#define CATCreateIsoMoveSimulator_H


class CATGeoFactory;
class CATTopData;

class CATBody;

class CATTopMaxIsoMoveCalculator;

#include "ListPOfCATFace.h"

#include "BODYNOPE.h"

//=============================================================================
//
// Operator under development.
// DO NOT CALL IT !!!
//
// If you think you need it, please contact DLR6.
//
ExportedByBODYNOPE CATTopMaxIsoMoveCalculator* CATCreateIsoMoveSimulator(
    CATGeoFactory           * ipFactory,            CATTopData  * iTopData,
    const ListPOfCATFace     &iListOfMobileFaces,   CATBody     * ipInputBody,
    const CATMathDirection   &iDisplacementAxis);


#endif //CATCreateIsoMoveSimulator_H
