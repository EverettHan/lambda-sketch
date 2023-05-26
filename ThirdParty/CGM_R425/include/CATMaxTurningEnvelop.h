#ifndef CATMaxTurningEnvelop_H
#define CATMaxTurningEnvelop_H

#include "CATTopOperator.h"
#include "ExportedByMaxTurningEnvelop.h"

#include <memory>

class CATGeoFactory;
class CATTopData;
class CATMathLine;
class CATPolyPolygon2D;
class CATMaxTurningEnvelopImp;
class CATMathPlane;

class ExportedByMaxTurningEnvelop CATMaxTurningEnvelop final : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATMaxTurningEnvelop);
public:
  ~CATMaxTurningEnvelop() = default;
  CATMaxTurningEnvelop() = delete;
  CATMaxTurningEnvelop(CATMaxTurningEnvelop const&) = delete;
  CATMaxTurningEnvelop& operator=(CATMaxTurningEnvelop const&) = delete;

  static std::unique_ptr<CATMaxTurningEnvelop> Create(CATGeoFactory *ipFactory, CATTopData *ipTopData);

  // Set/Get the rotation axis wrt compute the turning envelop profile
  // Default (Oz)
  void SetRotationAxis(CATMathLine const&);
  CATMathLine const& GetRotationAxis() const;

  // Set/Get output wire plane
  // First axis coordinate is the abscissa on the rotation axis
  // Second axis coordinate is the distance to the rotation axis
  // Default (Ozx)
  void SetOutputPlane(CATMathPlane const&);
  CATMathPlane const& GetOutputPlane() const;

  void SetTolerance(double iTolerance);
  double GetTolerance() const;
  
private:
  using CATTopOperator::CATTopOperator;

  int RunOperator() override;
};

inline std::unique_ptr<CATMaxTurningEnvelop> CATCreateMaxTurningEnvelop(CATGeoFactory* ipFactory, CATTopData* ipTopData)
{
  return CATMaxTurningEnvelop::Create(ipFactory, ipTopData);
}

#endif
