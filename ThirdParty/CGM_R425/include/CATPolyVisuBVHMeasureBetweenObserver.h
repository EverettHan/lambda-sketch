//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2020
//=============================================================================
//
// Observer for the Visu Interface to the Measure Between
// Operator. Inherits of the BVH Measure Between Observer. Allows to
// log visu specific errors and warnings. Can be enhanced by adding
// several observations according to needs.
//
//=============================================================================
// 2020-04-02   XXC: New.
//=============================================================================

#ifndef CATPolyVisuBVHMeasureBetweenObserver_h
#define CATPolyVisuBVHMeasureBetweenObserver_h

#include "PolyVisuMeasureBetween.h"
#include "CATPolyBVHMeasureBetweenObserver.h"

class ExportedByPolyhedralMeasureBetween CATPolyVisuBVHMeasureBetweenObserver : public CATPolyBVHMeasureBetweenObserver
{
public:
  enum VisuErrorType
  {
    EqualSubPathOperand, // Happens when a rep path operand is contained in the rep path of the other operand
  };
  enum VisuWarningType
  {
  };

public:
  CATPolyVisuBVHMeasureBetweenObserver() {}
  virtual ~CATPolyVisuBVHMeasureBetweenObserver() {}

public:

  virtual void LogError(const VisuErrorType iError) {}
  virtual void LogWarning(const VisuWarningType iWarning) {}

};

#endif // CATPolyVisuBVHMeasureBetweenObserver_h
