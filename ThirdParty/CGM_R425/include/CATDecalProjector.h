#ifndef CATDecalProjector_H_
#define CATDecalProjector_H_

#include "SGInfra.h"
#include "CATCallbackManager.h"
#include "CAT4x4Matrix.h"

class CATGraphicMaterial;

class ExportedBySGInfra CATDecalProjector
{
public:
  CATDeclareCBEvent(DecalMaterialChanged);
  CATDeclareCBEvent(DecalMatrixChanged);

  CATDecalProjector();
  ~CATDecalProjector();

  void AddRef() const;
  void Release() const;

  enum Projector_t
  {
    ePlanarMapping,
    eCylinderMapping,
    eInfiniteCylinderMapping,
    eSphericalMapping,
    eCubicalMapping,
    eInfiniteCylinderMappingAnglePreserving
  };

  enum BoundingShape_t
  {
    eBox,
    eCylinder,
    eSphere
  };

  enum Mode_t
  {
    eImplicit,
    eExplicit
  };

  void GetMatrix(CAT4x4Matrix& oMatrix) const;
  void SetMatrix(const CAT4x4Matrix& iMatrix);

  Projector_t GetProjector() const;
  void SetProjector(Projector_t iProjector);

  BoundingShape_t GetBoundingGeom() const;
  void SetBoundingGeom(BoundingShape_t iShape);

  Mode_t GetMode() const;
  void SetMode(Mode_t iMode);

  float GetImplicitScaleU() const;
  void SetImplicitScaleU(float iValue);

  float GetImplicitScaleV() const;
  void SetImplicitScaleV(float iValue);

  CATCallbackManager* GetCallbackManager() const;

protected:

  CAT4x4Matrix        m_Matrix;
  Projector_t         m_Projector;
  BoundingShape_t     m_Shape;
  Mode_t              m_Mode;
  float               m_ImplicitScaleU;
  float               m_ImplicitScaleV;
  CATCallbackManager* m_CallbackManager;

  mutable int m_RefCount;
};

struct CATDecalItem
{
  CATDecalProjector const* m_Projector;
  CATGraphicMaterial*      m_Material;
  CAT4x4Matrix             m_Matrix;
  float                    m_UVTrans[4];
};

#endif
