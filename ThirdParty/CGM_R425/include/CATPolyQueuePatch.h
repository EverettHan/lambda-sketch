// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyQueuePatch.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// June 2008  Creation: ZFI
//===================================================================

#ifndef CATPolyQueuePatch_H
#define CATPolyQueuePatch_H

#include "CATPolyElementsPatch.h"

class ExportedByCATPolySegmentCommon CATPolyQueuePatch : public CATPolyElementsPatch
{
public:
  //constrcutor destructor
  CATPolyQueuePatch() ;
  virtual ~CATPolyQueuePatch();

  virtual CATBoolean IsQueue();


};

#endif
