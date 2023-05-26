#ifndef CATCompSkinAnimation_H
#define CATCompSkinAnimation_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "CATSGComposite.h"
#include "CATSGCompositeHost.h"
#include "CATCompositeTPtr.h"

class CATRep;
class VisRawBuffer;

/*
_boneTransformationsBuffer must be a 3x4 matrix
eg. 3x4 Translation matrix
float Tmat[]={ 1, 0,  0,  0,
               1, 0,  0,  0,
               1, Tx, Ty, Tz}
*/

class ExportedBySGInfra CATCompSkinAnimation : public CATSGComposite
{
public:
  virtual ~CATCompSkinAnimation() {};
  virtual HRESULT SetAnimation(VisRawBuffer* iBoneMatrices, unsigned int iNbBone, VisRawBuffer* iPositionMatrices = NULL, unsigned int iNbInstance = 1) = 0;
  virtual HRESULT GetAnimation(VisRawBuffer*& oBoneMatrices, unsigned int& oNbBone, VisRawBuffer*& oPositionMatrices, unsigned int& oNbInstance) const = 0;
  virtual void RemoveAnimation() = 0;
  //virtual HRESULT Activate() = 0;
  //virtual HRESULT Deactivate() = 0;
};

static const IID GUID_CATCompSkinAnimationTrait =
{ 0xa7bc80b8, 0xa79, 0x4e74, {0xbf, 0xd8, 0x46, 0x45, 0x16, 0x2d, 0xe0, 0x80 } };

template<>
class CATTraitInfo<CATCompSkinAnimation>
{
public:
  static const GUID& 			GetTraitGUID()
  {
    return GUID_CATCompSkinAnimationTrait;
  }
  static const int			GetTraitTag() {
    return CATECompositeTagSkinAnimation;
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

typedef CATCompositeTWeakPtr<CATCompSkinAnimation>       CATCompSkinAnimationWeakPtr;
typedef CATCompositeTPtr<CATCompSkinAnimation>           CATCompSkinAnimationPtr;
typedef CATOnStackBorrowPtr<CATCompSkinAnimation>        CATCompSkinAnimationBorrowPtr;

class ExportedBySGInfra CATCompSkinAnimationDefaultImpl : public CATSGCompositeHost1<CATCompSkinAnimation, CATSGComposite>
{
public:
  CATCompSkinAnimationDefaultImpl();
  virtual ~CATCompSkinAnimationDefaultImpl();

  virtual HRESULT SetAnimation(VisRawBuffer* iBoneMatrices, unsigned int iNbBone, VisRawBuffer* iPositionMatrices = NULL, unsigned int iNbInstance = 1);
  virtual HRESULT GetAnimation(VisRawBuffer*& oBoneMatrices, unsigned int& oNbBone, VisRawBuffer*& oPositionMatrices, unsigned int& oNbInstance) const;
  virtual void RemoveAnimation();
  //virtual HRESULT Activate();
  //virtual HRESULT Deactivate();

private:
  VisRawBuffer*  _boneMatrices;
  VisRawBuffer*  _positionMatrices;
  unsigned int   _nbInstance;
  unsigned int   _nbBone;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // CATCompSkinAnimation_H
