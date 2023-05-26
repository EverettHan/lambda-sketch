/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIContainerFactory_h
#define CATIContainerFactory_h


#include "stringDef.h"
#include "booleanDef.h"
#include "sequence_octet.h"
#include "sequence_CATIdent.h"
#include "CATBaseUnknown.h"



#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIContainerFactory ;

class ExportedByAD0XXBAS CATIContainerFactory : public CATBaseUnknown
{
  CATDeclareInterface;

public:
    virtual CATBaseUnknown* CreateContainer (
					const CATIdent interface_id)=0 ;

    virtual CATBaseUnknown* CreateSpecializedContainer (
				const SEQUENCE(CATIdent)& requiredInterfaces,
				const CATIdent interface_id)=0 ;

    virtual CATBaseUnknown* LoadContainer (
				char* const storagePrintableName, 
				boolean readOnly,
				const CATIdent interface_id)=0;

    virtual CATBaseUnknown* LoadContainer_B (
				const SEQUENCE(octet)& storageName, 
				boolean readOnly,
				const CATIdent interface_id)=0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIContainerFactory, CATBaseUnknown ) ;


#endif



