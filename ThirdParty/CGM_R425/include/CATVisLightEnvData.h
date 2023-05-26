// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisLightEnvData_H
#define CATVisLightEnvData_H

#include "SGInfra.h"

#include "CATVisColor.h" 
#include "CATVisColorf.h"
#include "CATMathDirectionf.h"
#include "CATMathPointf.h"
#include "CATString.h"

//-----------------------------------------------------------------------
// light data

class ExportedBySGInfra CATVisLightEnvData
{
public:
  enum CATVisLightType
  {
    BasicLight          = 0,
    SunLight            = 1,
    MinerLamp           = 2,
    RealisticSunLight   = 3,
    RealisticMoonLight  = 4,
  };

  enum CATVisShadowType
  {
    GroundShadow       = 0,
    InterObjectShadow  = 1,
    MixShadows         = 2
  };

  enum CATVisShadowBlurType
  {
    ConstantBlur      = 0,
    LinearBlur        = 1,
    QuadraticBlur     = 2
  };

  CATVisLightEnvData();
  virtual ~CATVisLightEnvData();

  CATVisLightEnvData(const CATVisLightEnvData& iData);
  const CATVisLightEnvData& operator=(const CATVisLightEnvData& iData);
  bool operator==(const CATVisLightEnvData& iData) const;
  bool operator!=(const CATVisLightEnvData& iData) const;


  // geometry
  CATMathDirectionf     _direction;         // direction de la light infinie

  // lighting
  CATVisColor           _color;             // couleur visuelle de la source lumineuse
  float                 _intensity;         // intensite de la source lumineuse
  float                 _kDiff, _kSpec;     // modulation de l'intensite diffuse et speculaire

  // shadow
  unsigned int          _shadowActivation;     // activation des ombres portees sur les plans
  CATVisShadowType      _shadowType;           // typde shadow (sol, inter-objet ou les deux)
  unsigned int          _shadowMapSize;        // Taille de la shadowmap
                                               // 0:64 1:128 2:256 3:512 4:1024 5:2024 6:4096 7:8192
  unsigned int          _cascadedShadow;       // 1 to enable cascaded shadows else 0
  float                 _radiusForSoftShadow ; // Used only for soft shadows. The radius is used to compute the penumbra size.
  // shadows ground
  int                   _shadowGroundMapSize; // Taille maximum de la texture pour la shadow sur le sol, lorsque l'algo est different des shadow inter-objet
                                              // 0:64 1:128 2:256 3:512 4:1024 5:2024 6:4096 7:8192
                                              // -1: identique a _shadowMapSize;
  CATVisColor           _shadowColor;         // couleur de la shadow
  CATVisShadowBlurType  _shadowBlurType;      // type de floutage
  unsigned int          _shadowBlurSize;      // largeur du floutage en pixel

  // other
  unsigned int          _geometryActivation;  // permet de desactiver le creation de light source openGL

  unsigned int IsShadowOnGroundActivated      () const;
  unsigned int IsShadowInterObbjectActivated  () const;
  unsigned int IsCascadedShadowMapActivated   () const;
  unsigned int GetShadowMapSize               () const;
  unsigned int GetShadowGroundMapSize         () const;


  // ATTENTION : les donnees suivantes ne servent a rien
  // ces donnees sont gardees juste pour ne pas casser le build actuel
  // Les donnees relatives au soleil se trouvent dans CATVisSunEnvData maintenant
  unsigned int          _influencedByPlane;
  float                 _angle;
  float                 _angleHalo;
  CATVisColor           _colHalo;
};

class ExportedBySGInfra CATVisLightEnvAdditionalData
{
public:
  CATVisLightEnvAdditionalData();
  virtual ~CATVisLightEnvAdditionalData();
};

class ExportedBySGInfra CATVisSunEnvData : public CATVisLightEnvAdditionalData
{
public:    
  CATVisSunEnvData();
  virtual ~CATVisSunEnvData();

  CATVisSunEnvData(const CATVisSunEnvData& iData);
  const CATVisSunEnvData& operator=(const CATVisSunEnvData& iData);

  float               _angle;         // _angle permettant de decrire la taille de la tache lumineuse dans le ciel
  float               _angleHalo;     // _angle permettant de decrire la taille du halo lumineux dans le ciel

  CATVisColor         _colHalo;       // couleur visuelle du halo autour de la source lumineuse

  unsigned int        _visuActivation     : 1; // permet de desactiver la visu de la source dans le background
};

class ExportedBySGInfra CATVisRealisticSunEnvData : public CATVisLightEnvAdditionalData
{
public:    
  CATVisRealisticSunEnvData();
  virtual ~CATVisRealisticSunEnvData();

  CATVisRealisticSunEnvData(const CATVisRealisticSunEnvData& iData);
  const CATVisRealisticSunEnvData& operator=(const CATVisRealisticSunEnvData& iData);
};

class ExportedBySGInfra CATVisRealisticMoonEnvData : public CATVisLightEnvAdditionalData
{
public:    
  CATVisRealisticMoonEnvData();
  virtual ~CATVisRealisticMoonEnvData();

  CATVisRealisticMoonEnvData(const CATVisRealisticMoonEnvData& iData);
  const CATVisRealisticMoonEnvData& operator=(const CATVisRealisticMoonEnvData& iData);  
  
  float				  _moonPhase;
  CATString			_textureMoon;
};

#endif
