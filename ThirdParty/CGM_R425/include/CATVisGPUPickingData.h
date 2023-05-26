// COPYRIGHT Dassault Systemes 2012

#ifndef CATVisGPUPickingData_H
#define CATVisGPUPickingData_H

#include "SGInfra.h"
#include "CATPickPathList.h"

// Structure for managing GPU Picking settings
// In future, new options will be added to this strcture
class ExportedBySGInfra CATVisGPUPickingData
{
public:
  enum class Mode
  {
    eNormal,
    eFastPicking  // Rep level picking, correct reppath but not pickpath
  };

  CATVisGPUPickingData();
  CATVisGPUPickingData(Mode iMode);
  ~CATVisGPUPickingData();

  void SetMode(Mode iMode); // inine
  Mode GetMode() const;

protected:
  Mode m_mode;
};

#endif
