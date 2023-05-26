// COPYRIGHT DASSAULT SYSTEMES 2021, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyMakeManifold.h
// 
// Duplicate the topology/geometry so we do not have any
// non manifold element. Instead, we will have intersection.
// This is useful for algorithm based on manifold element (for propagation etc...)
//
//===================================================================
// Oct 2021 : F1Z : Creation
//===================================================================

#pragma once

// System & co
#include "CATSoftwareConfiguration.h"

// PolyhedralObjects
#include "CATPolyBody.h"
#include "CATPolyBodyNaryObserver.h"

// PolyhedralBodyOperator
#include "PolyBodyBoolean.h"

class ExportedByPolyBodyBoolean CATPolyBodyMakeManifold
{
public:
  CATPolyBodyMakeManifold();
  ~CATPolyBodyMakeManifold();

  void SetSoftwareConfiguration(CATSoftwareConfiguration * iConfig);

  HRESULT Run(CATPolyBody & iBody,
              CATPolyBody * & oResult,
              CATPolyBodyNaryObserver * iObs=nullptr);

private:
  CATSoftwareConfiguration * _config;
};

