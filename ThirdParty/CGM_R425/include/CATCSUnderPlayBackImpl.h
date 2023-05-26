// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
// CATCDSUnderPlayBack:  Singleton Interface for 
//=============================================================================
#ifndef CATCSUnderPlayBackImpl_h
#define CATCSUnderPlayBackImpl_h

#include "CATCDSVirtual.h"
#include "CATCDSUnderPlayBack.h"
#include "CATCDS.h"
 
class ExportedBySolverInterface CATCSUnderPlayBackImpl : public CATCDSUnderPlayBack   
{
public :
   CATCSUnderPlayBackImpl();
   ~CATCSUnderPlayBackImpl();


  // CreateStreamTool
  virtual CATCSStreamTool * CreateStreamTool() = 0;

protected :

  // LoadOperator
  virtual CATCDSOperator * LoadOperator(CATCDSStream & iStream, int & oStreamVersion) CATCDSOverride ;

};
 

#endif
