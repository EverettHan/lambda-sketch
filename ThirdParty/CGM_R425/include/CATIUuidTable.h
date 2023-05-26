/* -*-c++-*- */

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1999
//-----------------------------------------------------------------------------
// class CATIUuidTable (interface) :
//   
//
//-----------------------------------------------------------------------------
// Usage Notes: Interface to handle the UUID corresponding table
//
//
//-----------------------------------------------------------------------------
// Creation : June 1999      HAG
// Modified : 
//-----------------------------------------------------------------------------

#ifndef CATIUuidTable_H
#define CATIUuidTable_H

/**
 * @level Private
 * @usage U3
 */

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"

class CATUuid;

extern ExportedByAD0XXBAS IID IID_CATIUuidTable ;

class ExportedByAD0XXBAS CATIUuidTable : public CATBaseUnknown
{
  CATDeclareInterface;
 public:
  virtual HRESULT AddUuidsInTable(const CATUuid& oldUuid, const CATUuid& newUuid) = 0 ;
  virtual HRESULT GetNewUuid(const CATUuid& oldUuid, CATUuid& newUuid) const = 0;
  virtual HRESULT InverseTable() = 0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIUuidTable, CATBaseUnknown ) ;

#endif 

