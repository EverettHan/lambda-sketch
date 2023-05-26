#ifndef CATCompAlternateRep_H
#define CATCompAlternateRep_H

#include "CATSGUtil.h"
#include "SGComposites.h"
#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"
#include "CATCompositeTPtr.h"

class CATSurfacicRep;

class ExportedBySGComposites CATCompAlternateRep : public CATSGComposite
{
public:

  CATCompAlternateRep() : CATSGComposite() {}
  virtual ~CATCompAlternateRep() {}

virtual void SetAlternateRep(CATSurfacicRep* iAlternateRep) = 0;
virtual CATSurfacicRep* GetAlternateRep() const = 0;
};

// {D31334EB-E49F-40B5-8C8D-AF48522620A7}
static const GUID GUID_CATCompAlternateRep =
{ 0xd31334eb, 0xe49f, 0x40b5, { 0x8c, 0x8d, 0xaf, 0x48, 0x52, 0x26, 0x20, 0xa7 } };


template<>
class CATTraitInfo<CATCompAlternateRep>
{
public:
  static const GUID& GetTraitGUID()
  {
    return GUID_CATCompAlternateRep;
  }
  static const int GetTraitTag() {
    return CATTraitTag(CATECompositeTagAlternateRep);
  }
  static const CATECompositionMode GetCompositeMode()
  {
    return CATECompositionModeExclusive;
  }
  static const CATTraitRawInfo GetRaw()
  {
    DefaultGetRawImplementation;
  }
};

typedef CATCompositeTWeakPtr<CATCompAlternateRep> CATCompAlternateRepWeakPtr;
typedef CATCompositeTPtr<CATCompAlternateRep> CATCompAlternateRepPtr;
typedef CATOnStackBorrowPtr<CATCompAlternateRep> CATCompAlternateRepBorrowPtr;

class ExportedBySGComposites CATCompAlternateRepImpl : public CATSGCompositeHost1NoListeners<CATCompAlternateRep, CATSGComposite>
{
public:
  CATCompAlternateRepImpl();
  virtual ~CATCompAlternateRepImpl();
  
  virtual void SetAlternateRep(CATSurfacicRep* iAlternateRep);
  virtual CATSurfacicRep* GetAlternateRep() const;

private:
  CATSurfacicRep* _AlternateRep;
};

#endif
