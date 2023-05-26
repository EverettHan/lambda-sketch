#ifndef CATCompSkeleton_H
#define CATCompSkeleton_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"
#include "CATCompositeTPtr.h"

class CATRep;
class vDrawInformation;
class CAT4x4Matrix;
class VisRawBuffer;



class ExportedBySGInfra CATCompSkeleton : public CATSGComposite
{
public:
  virtual ~CATCompSkeleton() {};
  virtual HRESULT SetSkeleton(VisRawBuffer* iBones, VisRawBuffer* iBoneWeights) = 0;
  virtual HRESULT GetSkeleton(VisRawBuffer*& oBones, VisRawBuffer*& oBoneWeights) const = 0;
  virtual void RemoveSkeleton() = 0;
};


static const IID GUID_CATCompSkeletonTrait =
{ 0x30cf89f1, 0x4b26, 0x4add, {0x8e, 0x77, 0x94, 0xbd, 0x36, 0xea, 0x39, 0x7a } };

template<>
class CATTraitInfo<CATCompSkeleton>
{
public:
  static const GUID& 			GetTraitGUID()
  {
    return GUID_CATCompSkeletonTrait;
  }
  static const int			GetTraitTag() {
    return CATECompositeTagSkeleton;
  }
  static const CATECompositionMode	GetCompositeMode()
  {
    return CATECompositionModeExclusive;
  }
  static const CATTraitRawInfo 		GetRaw()
  {
      DefaultGetRawImplementation;
  }
};

typedef CATCompositeTWeakPtr<CATCompSkeleton>       CATCompSkeletonWeakPtr;
typedef CATCompositeTPtr<CATCompSkeleton>           CATCompSkeletonPtr;
typedef CATOnStackBorrowPtr<CATCompSkeleton>        CATCompSkeletonsBorrowPtr;

class ExportedBySGInfra CATCompSkeletonDefaultImpl : public CATSGCompositeHost1<CATCompSkeleton, CATSGComposite>
{
public:
  CATCompSkeletonDefaultImpl();
  virtual ~CATCompSkeletonDefaultImpl();

  virtual HRESULT SetSkeleton(VisRawBuffer* iBones, VisRawBuffer* iBoneWeights);
  virtual HRESULT GetSkeleton(VisRawBuffer*& oBones, VisRawBuffer*& oBoneWeights) const;
  virtual void RemoveSkeleton();

private:
  VisRawBuffer*  _boneIds;
  VisRawBuffer*  _boneWeights;
};
#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompSkeleton_H
