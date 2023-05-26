/**
 * @level Private
 * @usage U1
 */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef __CATIReference_h__
#define __CATIReference_h__
// ==============================================
// ==============================================

#include "CATBaseUnknown.h"
#include "AD0XXBAS.h"


// ==============================================
// definition of classCATIReference
// ==============================================

extern ExportedByAD0XXBAS IID IID_CATIReference;

class ExportedByAD0XXBAS CATIReference : public   CATBaseUnknown
{
public:
    virtual CATBaseUnknown_var Bind() const=0;
private:
 CATDeclareInterface;

};

 CATDeclareHandler(CATIReference,CATBaseUnknown);

#endif
