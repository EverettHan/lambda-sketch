#ifndef CATVizBaseAbstractManager_H
#define CATVizBaseAbstractManager_H

/* COPYRIGHT DASSAULT SYSTEMES 2002 */

#include "SGInfra.h"
#include "CATEventSubscriber.h"

class CATRep;
class CATModelIdentificator;
class CATManipulator;


class ExportedBySGInfra CATVizBaseAbstractManager : public CATEventSubscriber
{
  CATDeclareClass;

  public :
  virtual HRESULT RepIsDying(CATRep *i_pRep, CATModelIdentificator &iId, int i2DRep = 0) = 0; 
  virtual HRESULT ViewpointIsDying(CATBaseUnknown* i_spViewpoint) = 0; 
  virtual void ManipulatorIsDying(CATManipulator *i_pManipulator) = 0;
};

#endif
