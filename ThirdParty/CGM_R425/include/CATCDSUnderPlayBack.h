// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
// CATCDSUnderPlayBack:
//   Singleton Interface for 
//=============================================================================

#ifndef CATCDSUnderPlayBack_h
#define CATCDSUnderPlayBack_h

#include "CATCDSUtilities.h"
#include "CATCDSBoolean.h"
#include "CATCDSString.h"
#include "CATCDSInline.h"
#include "CATCDSOperator.h"

class CATCDSOperator;
class CATCDSStream;
class CATCSStreamTool;

class ExportedByCATCDSUtilities CATCDSUnderPlayBack  
{
public:
  ~CATCDSUnderPlayBack();

  // IsRecording
  virtual CATCDSBoolean IsRecording() = 0;

  // Mayday
  virtual void             Mayday(int i0Before_1After, CATCDSOperator *iOperator, CATCDSStream  * pStreamPlayBack ) = 0;

  // LoadOperator
  virtual CATCDSOperator * LoadOperator(CATCDSStream & iStream, int & oStreamVersion) = 0;

  // FlushCGMtkJournaling
  virtual void FlushCGMtkJournaling() = 0;
 
  // GetSingleton
  static CATCDSUnderPlayBack * GetSingleton(CATCDSBoolean iForceLoading);

protected :
  CATCDSUnderPlayBack();
  static CATCDSBoolean         _DynamicLoadingHasBeenTried;
  static CATCDSUnderPlayBack * _Singleton;
};
 

#endif
