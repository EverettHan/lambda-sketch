/**
 * @level Protected
 * @usage U5
 */
/* -*-c++-*- */

#ifndef CATImplementationCATIA_H
#define CATImplementationCATIA_H

#include "AC0CATPL.h"
#include "CATBaseUnknown.h"

extern ExportedByAC0CATPL IID IID_CATImplementationCATIA ;

class CATIAModel ;

class ExportedByAC0CATPL CATImplementationCATIA : public CATBaseUnknown
{
  CATDeclareInterface ;

  public:
    virtual int               GetReferenceJele()=0 ;
    virtual int               GetReferenceMnum()=0 ;
    virtual CATIAModel*       GetReferenceModel()=0 ;
    virtual CATBaseUnknown*   GetElementContainer( CATClassId InterfaceID )=0 ;
    virtual CATBaseUnknown*   GetElementContainer( const GUID& iid )=0 ;
} ;

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATImplementationCATIA, CATBaseUnknown ) ;

#endif
