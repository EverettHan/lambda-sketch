// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATPLMMajorIdQueryPolicy.h
// Header definition of CATPLMMajorIdQueryPolicy
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//===================================================================
/**
 * @level Protected
 * @usage U3
 */
#ifndef CATPLMMajorIdQueryPolicy_H
#define CATPLMMajorIdQueryPolicy_H

#include "CATPLMServicesItf.h"
#include "stddef.h"

class ExportedByCATPLMServicesItf CATPLMMajorIdQueryPolicy
{
   public:
      enum MajorIdPolicy { PhyId_Overload = 2, MajorId_Preserved = 1 };

      CATPLMMajorIdQueryPolicy (MajorIdPolicy policy);
      virtual ~CATPLMMajorIdQueryPolicy ();

      static int GetMajorIdCBPPolicy ();

   private:

      // Copy constructor and equal operator
      // -----------------------------------
      CATPLMMajorIdQueryPolicy (CATPLMMajorIdQueryPolicy &);
      CATPLMMajorIdQueryPolicy& operator=(CATPLMMajorIdQueryPolicy&);

      void* operator new(size_t);

      int _increment;

      static int gCBPPolicy;
//-----------------------------------------------------------------------
};
#endif
