#ifndef CATDisableRender_H_
#define CATDisableRender_H_

#include "CATRender.h"

class ExportedBySGInfra CATDisableRender : public CATRender
{
public:
  CATDisableRender(const CATSupport &iSupport);
  virtual ~CATDisableRender();

  virtual CATRender* PushMatrix (CAT4x4Matrix &matrix);
  virtual CATRender* PushMatrix (CAT3x3Matrix &iMatrix);
  virtual void PopMatrix(CATRender * render);
};


#endif
