#ifndef VisClipSphereDesc_H
#define VisClipSphereDesc_H
#include "CATMathPoint.h"
// COPYRIGHT DASSAULT SYSTEMES 2017




// Make sphere description consistent across renders and filters.
// Although this structure will be used internally, the flags
// are public.
struct VisClipSphereDesc
{
  
  enum
  {
    // WARNING : Do not change following value without checking CATVisClippingSphereFilter and every CATRepRender behavior !
    kMaxClippingSpheres = 6,
  };

  CATMathPoint m_position;
  float m_radius;
};

struct VisClipSphereDescWithID : public VisClipSphereDesc
{
  // data
  int identifier[VisClipSphereDesc::kMaxClippingSpheres];
};

#endif //VisClipSphereDesc_H
