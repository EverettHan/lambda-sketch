// COPYRIGHT DASSAULT SYSTEMES 2023, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyWithVolumesConvertor.h
// 
// If you have a solid CATPolyBody without volumes
//
//===================================================================
// Fev 2023 : F1Z : Creation
//===================================================================
#pragma once

// Systems&co
#include "CATPolyBodyBoolean.h"
#include "CATSoftwareConfiguration.h"

class CATPolyBody;
class CATMathTransformation;
class CATPolyBodyNaryObserver;

class ExportedByPolyBodyBoolean CATPolyBodyWithVolumesConvertor
{
public:
  CATPolyBodyWithVolumesConvertor();
  ~CATPolyBodyWithVolumesConvertor();

  void SetSoftwareConfiguration(const CATSoftwareConfiguration * config);

  HRESULT Run(const CATPolyBody & body,
              const CATMathTransformation * transfo,
              CATPolyBody *& result,
              CATPolyBodyNaryObserver * obs = nullptr);

private:
  CATSoftwareConfiguration * _config;
};
