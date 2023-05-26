#ifndef _CATUVCompressedTangent_
#define _CATUVCompressedTangent_

class CATMathVector;
#include "SGInfra.h"

class ExportedBySGInfra CATUVCompressedTangent
{
public:
  CATUVCompressedTangent();
  CATUVCompressedTangent(unsigned short *tangent);
  CATUVCompressedTangent(const CATMathVector & tangent);
  CATUVCompressedTangent(double x, double y, double z);

  double GetX();
  double GetY();
  double GetZ();
  void GetTangent(CATMathVector & tangent);
  const unsigned short *GetTangent() const;
  void SetTangent(unsigned short *tangent);
  void Get(double tangent[3]);
protected:

  unsigned short _tangent[2];
};

#endif
