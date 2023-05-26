//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2020
//=============================================================================
//
// Observer for the Measure Between Operator. Allows to log
// errors. Can be enhanced by adding several observations according to
// needs.
//
//=============================================================================
// 2020-04-02   XXC: New. Log errors and warning mechanism.
//=============================================================================

#ifndef CATPolyBVHMeasureBetweenObserver_h
#define CATPolyBVHMeasureBetweenObserver_h

#include "PolyBodyMeasureBetween.h"

class ExportedByPolyBodyMeasureBetween CATPolyBVHMeasureBetweenObserver
{
public:
  enum ErrorType
  {
  };
  enum WarningType
  {
    EmptySurface
  };

public:
  CATPolyBVHMeasureBetweenObserver() {}
  virtual ~CATPolyBVHMeasureBetweenObserver() {}

public:

  virtual void LogError(const ErrorType iError) {}
  virtual void LogWarning(const WarningType iWarning) {}

};

#endif // CATPolyBVHMeasureBetweenObserver_h
