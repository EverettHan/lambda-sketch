/* -*-c++-*- */

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 1998
//-----------------------------------------------------------------------------
// class CATIUUIDManager (interface) :
//   through this interface, an objects container can:
//   - change all its members' UUID and fill in a corresponding uuid table
//   with the old uuid and the new one for each object.
//   - change accordingly all its intra-doc links
//   - locate a member by its UUID
//
//-----------------------------------------------------------------------------
// Usage Notes:
//
//
//-----------------------------------------------------------------------------
// Creation : Apr.1998       NLL
// Modified : June 1999      HAG
//-----------------------------------------------------------------------------

#ifndef CATIUUIDManager_H
#define CATIUUIDManager_H

/**
 * @level Private
 * @usage U3
 */

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"

class CATUuid;
class CATIUuidTable;

extern ExportedByAC0XXLNK IID IID_CATIUUIDManager ;

class ExportedByAC0XXLNK CATIUUIDManager : public CATBaseUnknown
{
  CATDeclareInterface;

 public:

  virtual HRESULT RegenerateAndPublishUuids(CATIUuidTable* uuidTable) = 0 ;

  virtual HRESULT ChangeLinks(CATIUuidTable* uuidTable) = 0 ;
	 
//  virtual HRESULT RegenerateMembersUUID() = 0 ;

  virtual CATBaseUnknown* FindObject( const CATUuid* prov_uuid, int recurs) const = 0;

  virtual HRESULT ReplaceUuids(CATIUuidTable* uuidTable) = 0;
  
//  virtual CATUuid* FindUUID(const CATBaseUnknown* prov_obj) = 0;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIUUIDManager, CATBaseUnknown ) ;

#endif 

