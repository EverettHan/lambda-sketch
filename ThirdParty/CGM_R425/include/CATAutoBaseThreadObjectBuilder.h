#ifndef CATAutoBaseThreadObjectBuilder_H
#define CATAutoBaseThreadObjectBuilder_H
//===================================================================
// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATAutoBaseThreadObjectBuilder.h
// 		
//===================================================================
//  Oct 2003  Creation: JHG
//===================================================================

#include "CATCGMThread.h"
#include "CATCGMNewArray.h"

#include "CFSEngine.h"

class CATAutoBaseObjectBuilder;

class ExportedByCFSEngine CATAutoBaseThreadObjectBuilder : public CATCGMThread
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation

  CATAutoBaseThreadObjectBuilder(CATAutoBaseObjectBuilder &iObjectBuilder);

  virtual ~CATAutoBaseThreadObjectBuilder();

  // builds the CSF
  virtual int Run();

private:
  CATAutoBaseObjectBuilder &_ObjectBuilder;
};

#endif
