#ifndef CATAutoBaseConstructionContext_H
#define CATAutoBaseConstructionContext_H
//===================================================================
// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATAutoBaseConstructionContext.h
// 		
//===================================================================
//  Oct 2003  Creation: JHG
//===================================================================

#include "CFSEngine.h"
#include "CATOracleObject.h"
#include "CATCGMNewArray.h"

class CATAutoOpConstructionContext;

class ExportedByCFSEngine CATAutoBaseConstructionContext : public CATOracleObject
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation
  DEFINE_ADVOP_CLASS(CATAutoBaseConstructionContext)

  CATAutoBaseConstructionContext(CATTopOracle &iOracle, const CATAutoBaseThreadContext &iThreadContext);

  virtual ~CATAutoBaseConstructionContext();

  virtual CATAutoOpConstructionContext *GetAsAutoOpConstructionContext();
  virtual CATPersistentBody *ReadConstructionBody();
 
  const CATAutoBaseThreadContext &GetThreadContext() { return _ThreadContext; }
 
private:

  const CATAutoBaseThreadContext &_ThreadContext;
};

#endif
