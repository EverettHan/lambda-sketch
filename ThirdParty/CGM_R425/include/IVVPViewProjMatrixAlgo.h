//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 2019
//-----------------------------------------------------------------------------
#ifndef IVVPViewProjMatrixAlgo_H
#define IVVPViewProjMatrixAlgo_H

#include <array>

//=============================================================================
/**
 * IVVPViewProjMatrixAlgo
 */
class IVVPViewProjMatrixAlgo
{
public:

  //
  virtual ~IVVPViewProjMatrixAlgo() = default;
  
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

    std::array<double, 16> view{};
    std::array<double, 16> proj{};
  };
  
  //
  virtual Output Run(Input const& iInput) const = 0;
};

#endif
