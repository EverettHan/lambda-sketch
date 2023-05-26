#ifndef CATVidAbstractCloneProvider_H
#define CATVidAbstractCloneProvider_H

#include "VisuDialog.h"
#include "CATBaseUnknown.h"
#include "CATISYPIntrospectable.h"

class ExportedByVisuDialog CATVidAbstractCloneProvider : public CATBaseUnknown
{
  CATDeclareClass;

public:
  virtual CATBaseUnknown_var Clone(const CATBaseUnknown_var & i_spObject) = 0;

protected:
  CATVidAbstractCloneProvider();
  virtual ~CATVidAbstractCloneProvider();

private:
  CATVidAbstractCloneProvider (CATVidAbstractCloneProvider &);
  CATVidAbstractCloneProvider& operator=(CATVidAbstractCloneProvider&);
};

//-----------------------------------------------------------------------------
#endif
