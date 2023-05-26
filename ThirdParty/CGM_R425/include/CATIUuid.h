/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
//  CATIUuid:
//  
//  This interface allows to get an uuid
//
//==================================================================
//  Usage notes
//    
//  - useful on containers
//
//==================================================================
#ifndef CATIUuid_H
#define CATIUuid_H

/**
 * @level Protected 
 * @usage U3
 */

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"
class CATUuid;


extern ExportedByAD0XXBAS IID IID_CATIUuid ;

class ExportedByAD0XXBAS CATIUuid : public CATBaseUnknown
{
  CATDeclareInterface;

    public:

	 virtual HRESULT SetUuid (CATUuid* newUuid) = 0;
    virtual const CATUuid* GetUuid () const = 0 ;
    virtual HRESULT RegenerateUuid () = 0;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler (CATIUuid , CATBaseUnknown) ;


#endif
