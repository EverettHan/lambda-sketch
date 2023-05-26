#ifndef CATLowestLine_H
#define CATLowestLine_H

#include "AdvTopoOpeItf.h"
#include "CATTopMultiResultStreamed.h"
#include "CATCGMSharedPtr.h"

#include <memory>

class CATGeoFactory;
class CATTopData;
class CATLowestLineImp;
class CATIPolyMesh;
class CATLowestLineObserver;

class ExportedByAdvTopoOpeItf CATLowestLine final : public CATTopMultiResultStreamed
{
  CATCGMVirtualDeclareClass(CATLowestLine);
public:
  ~CATLowestLine() = default;
  CATLowestLine() = delete;
  CATLowestLine(CATLowestLine const&) = delete;
  CATLowestLine& operator=(CATLowestLine const&) = delete;

  static std::unique_ptr<CATLowestLine> Create(CATGeoFactory * ipFactory, CATTopData * ipTopData, CATCGMSharedPtr<CATIPolyMesh const> iPolyMesh);
  static std::unique_ptr<CATLowestLine> Create(CATGeoFactory * ipFactory, CATTopData * ipTopData);

  //void SetMinAngle(double);
  //double GetMinAngle() const;

  void SetMaxAngle(double);
  double GetMaxAngle() const;

  void SetMinLength(double);
  double GetMinLength() const;

  CATIPolyMesh const*  GetInputMesh() const;

  void SetObserver(std::unique_ptr<CATLowestLineObserver> ipObserver);
  CATLowestLineObserver* GetObserver() const;

private:
  using CATTopMultiResultStreamed::CATTopMultiResultStreamed;

  int RunOperator() override;
};

ExportedByAdvTopoOpeItf std::unique_ptr<CATLowestLine> CATCreateLowestLine(CATGeoFactory* ipFactory, CATTopData* ipTopData, CATCGMSharedPtr<CATIPolyMesh const> iPolyMesh);

inline std::unique_ptr<CATLowestLine> CATCreateLowestLine(CATGeoFactory* ipFactory, CATTopData* ipTopData)
{
  return CATLowestLine::Create(ipFactory, ipTopData);
}
#endif
