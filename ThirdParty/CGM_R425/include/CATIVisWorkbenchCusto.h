#ifndef CATIVisWorkbenchCusto_H
#define CATIVisWorkbenchCusto_H

#include "CATBaseUnknown.h"
#include "CATVisItf.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCATVisItf IID IID_CATIVisWorkbenchCusto;
#else
	extern "C" const IID IID_CATIVisWorkbenchCusto;
#endif

class ExportedByCATVisItf CATIVisWorkbenchCusto : public CATBaseUnknown
{
	CATDeclareInterface;

public:
  enum EType
  {
    eAmbiances,
    eStyles
  };

	virtual bool IsEnable(EType iType) = 0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler(CATIVisWorkbenchCusto, CATBaseUnknown);

#endif // CATIVisWorkbenchCusto_H
