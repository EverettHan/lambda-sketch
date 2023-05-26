#ifndef CATThickPlusContextForFastRunExt_h
#define CATThickPlusContextForFastRunExt_h
/* -*-C++-*-*/
//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010
// 
//==========================================================================
// Jun. 2010  Creation                                                 JJ3
//==========================================================================

#include "CATContextForFastRunExt.h"

class CATBody;
class CATCGMHashTable;

class CATThickPlusContextForFastRunExt: public CATContextForFastRunExt
{

public:
  CATThickPlusContextForFastRunExt();
  virtual ~CATThickPlusContextForFastRunExt();

  virtual CATString GetType();

  virtual CATBoolean IsAttributeManagementActive();
  virtual void TransferFastRunAttributeToResult();
  virtual void FillFastRunBuffer(CATCGMStream & oBuffer);

  //CATBody * GetOldInput();
  //CATCGMHashTable * GetPersistentFaces();

};

#endif


