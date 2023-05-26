//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 2019
//-----------------------------------------------------------------------------
#ifndef IVVPMatrixAlgo_H
#define IVVPMatrixAlgo_H

#include <array>
#include "CATProjectionType.h"

//=============================================================================
/**
 * IVVPMatrixAlgo
 */
class IVVPMatrixAlgo
{
public:

  //
  virtual ~IVVPMatrixAlgo() = default;
  
  //
  struct Input
  {
    std::array<float, 3> sphereCenter{};
    float sphereRadius{};
    float sphereRadiusMM{};
  };
  
  //
  struct Output
  {
    bool valid{};

    std::array<double, 6> frustum{};
    std::array<double, 16> matrix{};
    CATProjectionType projType{CATProjectionType::CONIC};
  };

  //
  virtual Output Run(Input const& iInput) const = 0;
};

#endif
