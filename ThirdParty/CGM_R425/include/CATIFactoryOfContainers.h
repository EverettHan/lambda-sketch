/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIFactoryOfContainers_h
#define CATIFactoryOfContainers_h

/**
 * @level Protected 
 * @usage U3
 */

#include "CATBaseUnknown.h"


#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIFactoryOfContainers ;
/**
* @deprecated : use HRESULT CATCreateContainerForApplicativeData(...) @href CATOmbContainerServices instead
*/
class ExportedByAD0XXBAS CATIFactoryOfContainers : public CATBaseUnknown
{
  CATDeclareInterface;

public:
    virtual CATBaseUnknown* CreateContainer (const CATIdent containerType,
                  const CATIdent interfaceID, const CATIdent containerSuperType="")=0 ;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIFactoryOfContainers, CATBaseUnknown ) ;


#endif
