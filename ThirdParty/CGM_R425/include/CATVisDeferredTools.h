// COPYRIGHT Dassault Systemes 2022

#ifndef CATVisDeferredTools_H
#define CATVisDeferredTools_H

#include "SGInfra.h"

class CATSupport;
class ExportedBySGInfra CATVisDeferredTools 
{
  friend class vREVideoShooter;
  
private:
  static void InitDeferredDraw(CATSupport& iSupport);
  static void NextDeferredStep(CATSupport& iSupport, bool& oRefreshVisu);

  CATVisDeferredTools();
  ~CATVisDeferredTools();
};

#endif
