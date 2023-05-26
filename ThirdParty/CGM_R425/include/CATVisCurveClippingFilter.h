#ifndef CATVisCurveClippingFilter_H
#define CATVisCurveClippingFilter_H
//
// CATIA Version 6 Release -- Framework Visualization
// Copyright Dassault Systemes 2016

#include "SGInfra.h"
#include "CATVisFilter.h"
#include "VisClippingDesc.h"

class IVisSGCurveClippingFilter;
class VisSGFilterVisitor;


class ExportedBySGInfra CATVisCurveClippingFilter : public CATVisFilter
{

  CATDeclareVisFilter(CATVisCurveClippingFilter);

  // Maximum of 2048 vertices on a curve
  //static const unsigned int kMaxVerticesForCurveClipping = 2048;

  // Maximum of 8 filters in the scene
  //static const unsigned int kMaxFiltersForCurveClipping = 8;

public:

  CATVisDeclarePublicInterfaceAdhesion(CATVisCurveClippingFilter, IVisSGCurveClippingFilter, CATVisCurveClippingFilterIVisSGCurveClippingFilterBOAImpl);

  /**
  @brief Create a curve clipping filter based on the input vertices and normals.
         In order to apply one or multiple curve clipping filters to the same object,
         just create only one instance of this class and put all the curves data into it.
         The filter can contain up to kMaxFiltersForCurveClipping curves.
         If a curve does not respect the projected vertices rule, it will be split into multiple curves which respect this constraint.

  @param iCurveCount the number of curves contained in this filter (maximum of kMaxFiltersForCurveClipping per scene)
  @param iVertexCounts the array containing the vertex count for each curve (maximum of VisClipCurveDesc::kMaxVerticesForCurveClipping per curve)
  @param iVertices the array containing the concatenated vertex list for all curves (maximum of VisClipCurveDesc::kMaxVerticesForCurveClipping*VisClipCurveDesc::kMaxFiltersForCurveClipping)
  @param iNormals the array containing the normals for each curve (maximum of VisClipCurveDesc::kMaxFiltersForCurveClipping per scene i.e. 8)
  @param iTransformVertices if true, the last matrix pushed will be used to transform the vertices in world space, otherwise the vertices are expected to be in world space already
  @param iFlags VisClippingDesc flags to specify if to be applied on some special elements like furtive, hidden, etc. By default, it allows uncutting by the CATVisAnnotation filter.
  @return the CATVisCurveClippingFilter pointer containing all of the input data
  */
  static CATVisCurveClippingFilter* Create(unsigned int iCurveCount, unsigned int* iVertexCounts, const float* iVertices, const float* iNormals, bool iTransformVertices = true, unsigned int iFlags = VisClippingDesc::fAllowUncutting);

  unsigned int GetClippingDescFlags() const;
  HRESULT SetClippingDescFlags(unsigned int iFlags);

  HRESULT GetClippingCurves(unsigned int** iCurveCount, unsigned int** iVertexCounts, float** iVertices, float** iNormals, bool** iTransformVertices, unsigned int** iFlags);
  HRESULT SetClippingCurves(unsigned int iCurveCount, unsigned int* iVertexCounts, const float* iVertices, const float* iNormals, bool iTransformVertices = true, unsigned int iFlags = VisClippingDesc::fAllowUncutting);

  virtual void Visit(VisSGFilterVisitor& iVisitor) const;

  HRESULT GetData(unsigned int& oCurveCount, unsigned int** oVertexCounts, float** oVertices, float** oNormals, bool& oTransformVertices);

protected:

  CATVisCurveClippingFilter(unsigned int iCurveCount, unsigned int* iVertexCounts, const float* iVertices, const float* iNormals, bool iTransformVertices, unsigned int iFlags);

  virtual ~CATVisCurveClippingFilter();
};
#endif
