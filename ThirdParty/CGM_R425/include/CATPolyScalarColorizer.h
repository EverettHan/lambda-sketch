#ifndef CATPolyScalarColorizer_h__
#define CATPolyScalarColorizer_h__

// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyScalarColorizer.h : colorize a mesh according a scalar field on  vertices (rainbow map)
//
//===================================================================
// December 2017  Creation NUA
//===================================================================

#include <map>
#include <vector>


  #include <array>


// export
#include "ExportedByCATPolyFeatureLineOperator.h"

class ExportedByCATPolyFeatureLineOperator CATPolyScalarColorizer
{
public :

  struct InternalColor_t // entre 0 et 1
  {
    double m_r, m_g, m_b;
    InternalColor_t() : m_r(0.), m_g(0.), m_b(0.) {}
    InternalColor_t(double r, double g, double b) : m_r(r), m_g(g), m_b(b) {}
  };

  CATPolyScalarColorizer(const std::map<int, double> & iVertVal);

  void Run();


  std::array<double,3> Get(int NumV) const;


private:

  std::map<int, double> m_VertVal;
  
  std::vector<InternalColor_t> m_AllColors;
};

#endif // CATPolyScalarColorizer_h__
