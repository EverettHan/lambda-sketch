#ifndef VisClipCurveDesc_H
#define VisClipCurveDesc_H
// COPYRIGHT DASSAULT SYSTEMES 2021
// Make sphere description consistent across renders and filters.
// Although this structure will be used internally, the flags
// are public.
struct VisClipCurveDesc
{
  enum
  {
    // WARNING : Do not change following value without checking CATVisClippingSphereFilter and every CATRepRender behavior !
    kMaxCurveClippingFilters = 8 ,
    kMaxVerticesForCurveClipping = 2048,
    kDimension = 3,
    kMinimumVertexCount =2
  };

  unsigned int vertexCounts;                                        // vertex count for each curve
  float vertices[kMaxVerticesForCurveClipping * kDimension];  // vertices for each curve
  float normals[kDimension];                                  // normal to the plan containing the curve vertices for each curve
  bool transformVertices;                                           // if true, the vertices will be transformed in world space using the last matrix pushed
};

#endif 
