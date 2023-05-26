/**
 * @level Private
 * @usage U1
 */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIGenericNamed_h
#define CATIGenericNamed_h
//=================================================
// Allow GenericNaming to warn object referenced
//=================================================
#include "CATBaseUnknown.h"
#include "AD0XXBAS.h"

extern ExportedByAD0XXBAS IID IID_CATIGenericNamed;

#define CATIGenericNamedRefresh

class ExportedByAD0XXBAS CATIGenericNamed : public CATBaseUnknown
{
  CATDeclareInterface;

public:
   enum CATWarning { linked, unlinked, deleted, datum, noNeedToSave, smart, unsmart, refresh };

   virtual void Warn(const CATIGenericNamed::CATWarning& event = CATIGenericNamed::linked ) const=0;
};

CATDeclareHandler(CATIGenericNamed,CATBaseUnknown);
#endif
