//-------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2016-05-27
//-------------------------------------------------------------------

#ifndef CATIVisMoreAmbiances_H
#define CATIVisMoreAmbiances_H

#include "SGInfra.h"
#include "CATBaseUnknown.h"

extern ExportedBySGInfra IID IID_CATIVisMoreAmbiances ;

class CATViewer;
class CATFrmWindow;
class ExportedBySGInfra CATIVisMoreAmbiances : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  virtual bool IsAvailable  (CATViewer* iViewer) = 0;
  virtual void Run          (CATViewer* iViewer) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIVisMoreAmbiances, CATBaseUnknown );

#endif
