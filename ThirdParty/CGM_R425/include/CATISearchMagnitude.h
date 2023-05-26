/* -*-c++-*- */
#ifndef CATISearchMagnitude_H
#define CATISearchMagnitude_H
//
// COPYRIGHT DASSAULT SYSTEMES 2000
//---------------------------------------------------------------------------------
// Abstract: Interface to enable the translation of a string (i.e. "3mm", "3,4 kg",
//           "1.4 in", etc.) into the MKS value.
//           There should be only one implementation of this interface, as a code
//           extension of the CATSearchDimensionedAttributeCriteria class.
//           The implementation is in LiteralFeatures/CK0FEAT.m/src/CATLifSearchMagnitudeImpl
//
//           This solution has been adopted in order to be able to benefit from non
//           COM service from a COM module (CATIAApplicationFrame).
//---------------------------------------------------------------------------------
//

// Module
#include "UIModelInterfaces.h"

// Héritage
#include "CATBaseUnknown.h"

// Besoin
#include "CATUnicodeString.h"

// iid OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATISearchMagnitude;
#else
extern "C" const IID IID_CATISearchMagnitude;
#endif

class ExportedByUIModelInterfaces CATISearchMagnitude : public CATBaseUnknown
{
  CATDeclareInterface;  

public:
  virtual HRESULT DecodeStringToMKSValue(const CATUnicodeString& iUnit,
                                         const CATUnicodeString& iString,
                                         double& oMKSValue) = 0;

  // Rajout LDI le 09/05/01
  // Donne le même résultat que ci-dessus, mais avec la précision en plus.
  virtual HRESULT DecodeStringToMKSValue(const CATUnicodeString& iUnit,
                                         const CATUnicodeString& iValue,
                                         double& oMKSValue,
                                         double& oEpsilon) = 0;

};
// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler(CATISearchMagnitude, CATBaseUnknown);

#endif
