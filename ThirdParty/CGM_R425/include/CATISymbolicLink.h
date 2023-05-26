/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATISymbolicLink_h
#define CATISymbolicLink_h

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"

#include "CosLinkable.h"
#include "booleanDef.h"
#include "sequence_octet.h"
#include "CATLISTV_CATBaseUnknown.h"

#include "CATObjectModelerBase.h"
extern ExportedByCATObjectModelerBase IID IID_CATISymbolicLink;

class ExportedByCATObjectModelerBase CATISymbolicLink : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual SEQUENCE(octet) GetName_B(CATNameKind kind, boolean IntraDocument) = 0;
  virtual HRESULT GetName_B(SEQUENCE(octet)& oName, CATNameKind kind, boolean IntraDocument) = 0;

  virtual CATBaseUnknown_var GetPointedObject() const = 0;

  // For Inverse Links :

  virtual void AddInverseLink(CATBaseUnknown_var inverse_handler) = 0;
  virtual void RemoveInverseLink(CATBaseUnknown_var inverse_handler) = 0;
  virtual CATLISTV(CATBaseUnknown_var) GetInverseLinks() = 0;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler(CATISymbolicLink, CATBaseUnknown);

#endif








