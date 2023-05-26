// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyRepType.h
//
//===================================================================
// October 2012  Creation: NDO
//===================================================================
#ifndef CATPolyRepType_H
#define CATPolyRepType_H


class CATPolyRepType
{

public:

  /**
   * Enumerator listing the various types of reps that can be processed by the 
   * polyhedral adapters or importers.
   */
  enum RepType
  {
    /** */ eUnknown = 0,
    /** */ e3DCurvedPipeRep,
    /** */ e3DCurveRep,
    /** */ e3DCustomRep,
    /** */ e3DCylinderRep,
    /** */ e3DLineRep,
    /** */ e3DPlanRep,
    /** */ e3DPointRep,
    /** */ eMonoWireRep,
    /** */ eSurfacicRep,
    /** */ eVizMonoWireRep,
    /** */ eVizUV3DRep,
    /** */ eVizVertexBufferRep,
    /** Not supported by the adapters. */ eVisPrimitiveGroupRep,
    /** */ e3DCanonicalRep
  };

};

#endif // !CATPolyRepType_H
