// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATDataShadowMapping.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2003  Creation: jov
//===================================================================
#ifndef CATDataShadowMapping_H
#define CATDataShadowMapping_H

#include "CATVizBaseIUnknown.h"
#include "CAT4x4Matrix.h"
#include "SGInfra.h"
#include "CATShadowEnum.h"
#include "CAT3DLightSourceRep.h"
#include "CATVisColor.h"
#include "CATMathPointf.h"

class CATVisuTexture;
class CAT3DBagRepWithBox;
class CATRepWeakRef;
class CAT3DBagRep;
class CATGraphicMaterial;
class CAT3DViewpoint;
class CATVisEffect;

//-----------------------------------------------------------------------

/**
 * this obejcts is OBSOLETE.
 * Since NRE, is useless.
 */
class ExportedBySGInfra CATDataShadowMapping : public CATVizBaseIUnknown
{
public:
  
  // Standard constructors and destructors
  // -------------------------------------
  CATDataShadowMapping (CAT3DLightSourceRep* i_pLightSource);
  CATDataShadowMapping (const CATDataShadowMapping & i_dataShadowMapping);

  void  SetLightSource(CAT3DLightSourceRep* i_pLightSource);
  CAT3DLightSourceRep* GetLightSource();

  void  SetLightViewFitting (const CATVisLightViewFittingMode i_lightViewFitting);
  CATVisLightViewFittingMode GetLightViewFitting ();
  
  void  SetShadowColor(const CATVisColor& i_shadowColor);

  void  SetNear(float i_nearPlan);
  float GetNear();

  void  SetProjectionMatrix(CAT4x4Matrix &i_projectionMatrix);
  CAT4x4Matrix GetProjectionMatrix();

  void  SetModelviewMatrix(CAT4x4Matrix &i_modelviewMatrix);
  CAT4x4Matrix GetModelviewMatrix();

  void  SetMapSize(const unsigned int i_mapSize);
  const unsigned int GetMapSize() const;

protected:
  virtual ~CATDataShadowMapping ();
};

//-----------------------------------------------------------------------

#endif
