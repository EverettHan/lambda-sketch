// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisPlaneEnvData_H
#define CATVisPlaneEnvData_H

#include "SGInfra.h"

#include "CATVisColor.h" 
#include "CATVisColorf.h"
#include "CATMathDirectionf.h"
#include "CATMathPointf.h"
#include "CATMathPoint.h"
#include "CATString.h"
#include "CATVisParameters.h"

//-----------------------------------------------------------------------
// plane data

class ExportedBySGInfra CATVisPlaneEnvData
{
public:
  enum CATVisPlaneTextureType
  {
    CATVisNoTexture,
    CATVisBasicTexture,
    CATVisMultiTexture,
    CATVisShader,
    CATVisFacticeCatcher,          // Only available in NRE
    CATVisInvisible
  };

  enum CATVisPlanePositionMode
  {
    CATVisPositionAutomatic,                          // Position: Automatic                                          Radius:Automatic    
    CATVisPositionHalfManual,                         // Position: projection of automatic position on manual plane   Radius:Automatic   
    CATVisPositionHalfManualWithZBuffer,              // Position: projection of automatic position on manual plane   Radius:Automatic   
    CATVisPositionAutomaticRadiusManualWithZBuffer,   // Position: Automatic                                          Radius:Manual      -> only NRE
    CATVisPositionManual,                             // Position: Manual                                             Radius:Manual      
    CATVisPositionManualWithZBuffer                   // Position: Manual                                             Radius:Manual      
  };

  enum CATVisColorMode
  {
    CATVisColorAutomatic,
    CATVisColorManual,
    CATVisBiColorManual,
  };  
  
  enum EType
  {
    eInfinitePlane,
    eSphere
  };

  enum EFadingMode
  {
    eLinear = 0,
    eCubic,
    eBicubic
  };
  
  CATVisPlaneEnvData();
  CATVisPlaneEnvData(const CATVisPlaneEnvData& iData);
  virtual ~CATVisPlaneEnvData();
  const CATVisPlaneEnvData& operator=(const CATVisPlaneEnvData& iData);
  bool operator==(const CATVisPlaneEnvData& iData);
  bool operator!=(const CATVisPlaneEnvData& iData);

  // general
  unsigned int              _activation;                // activation du plan
  unsigned int              _backFaceActivation;        // visulization ou non de la face arriere du plan

  unsigned int              _altitudeRatio;             // en mode auto, cette proprietes permet de determiner
                                                        // la distance a laquelle le plan se situe de la scene
                                                        // cette distance sera egal a la valeur suivante :
                                                        // d = sceneSize * (_altitudeRatio/100) * (20/100);

  unsigned int              _fadingStrength;            // parametre permettant de controller la vitesse de disparition du sol
                                                        //  en fonction de l'angle direction de pointage de la camera/normal du Plan

  unsigned int              _radialRatioFading;         // pourcentage du rayon a partir duquel l'effet d'evanescence commence
  unsigned int              _radiusNeverNull;           // flag pour imposer que le sol et la grille prenne une taille de 1 en cas de taille egale a 0
  EFadingMode               _radiusFadingMode;          // mode de fading entre le centre le pourtour

  bool             _removeFromRTRTBVHWhenSeenFromBelow; // if true, when camera is under the ground, the ground geometry gets removed from
                                                        // the Bounding Volume Hierarchy used for Real-Time Ray Tracing

  EType                     _type;                      // type (plan infini, sphere finie)
  
  CATVisPlanePositionMode   _positionMode;              // degre de positionnement automatique du plan du plan pra rapport a la scene 
  
  // Set/Get the plane origin (only for CATVisManual, CATVisHalfManual mode)
  struct PointD
  {
    PointD()                          {x=0; y=0; z=0;};
    PointD(const PointD&        iPt)  {x=iPt.x; y=iPt.y; z=iPt.z;};
    PointD(const CATMathPointf& iPt)  {x=iPt.x; y=iPt.y; z=iPt.z;};
    PointD(const CATMathPoint&  iPt)  {x=iPt.GetX(); y=iPt.GetY(); z=iPt.GetZ();};

    double x,y,z;
  };
  PointD                    _origin;                    // origine du plan. 
                                                        // NB: elle etait d'abord encodée sur des float mais pour gerer le large scale on est passé sur des double, 
                                                        //     La structure, PointD sert juste a ne pas peter le build plutot que d'utiliser un CATMathPoint
  CATMathDirectionf         _normal;                    // normale au plan
  CATMathDirectionf         _direction;                 // direction principale pour positionner la grille

  float                     _radius;                    // radius pour le mode CATVisManual
  float                     _radiusRatio;               // facteur multiplicateur pour agmenter la taille du rayon
                                                        // (c'est surtout util en mode ou ka rayon est calcul automatiquement)
  
  float                     _height;                    // Epaisseur du sol (a priori util pour le type sphere)

  float                     _intensity;                 // intensité lumineuse retournée par tous les elements du plan (ground, background, grid)
                                                        // toutes les couleurs sont multipliées par ce facteur


  // ground
  unsigned int              _groundActivation;          // activation de la grille ou non
  unsigned int              _lightColorActivation;      // prise en compte des sources lumineuse pour la couleur du plan
  CATVisColorMode           _colorMode;                 // mode de gestion des couleurs (automatique fonction du background ou manuel)
  CATVisColor               _color;                     // couleur du plan au niveau de la scene 3D
  float                     _kDiff, _kAmb;              // coef diffuse et ambient du materiau du plan
  float                     _mirrorCoef;                // effet mirroir sur le plan, ce coef va de 0 (pas de miroir) a 1 (totallement reflechissant)
  float                     _mirrorBlur;                // level of blurring effect on the mirror 
  unsigned int              _mirrorBlurNum;             // blurring pass'number
  bool                      _mirrorBlurAlphaMode;       // blur algorythm take into account alpha value to moderate blur level
  float                     _groundRadiusRatio;         // facteur multiplicateur uniquement pour la taille du ground (la grille n'est pas impactee)
  float                     _mirrorScaleFactor;         // utilise pour downscale la map de mirroir. Valeur entre 0 et 1. 0.5 signifie que la map sera /2.
  bool                      _mirrorFilterFireFly;      
  float                     _mirrorFilterFireFlyStrength;
  float                     _mirrorFilterFireFlyThreshold;

  //background
  unsigned int              _backgroundGeneration;      // generation automatique d'un background 
  unsigned int              _skyLineFading;             // effet de flou au niveau de l'horizon entre le ciel et le sol
                                                        // 0 : on passe du sol  au ciel d'un seul coup
  CATVisColor               _colorBackgound;            // couleur du plan a l"infini
  CATString                 _backgroundShader;
  CATVisParameters          _backgroundParameters;
   
  // grid 
  unsigned int              _gridActivation;            // activation de la grille ou non
  unsigned int              _gridNum;                   // nombre total de lignes primaires dans la grille sur un des ses cotes
  unsigned int              _subGridNum;                // nombre de lignes secondaires entre chaque couple de lignes primaires
  CATVisColor               _gridCol;                   // couleur de la grille primaire
  CATVisColor               _subGridCol;                // couleur de la grille secondaire

  // render mode of shadow on the ground
  // * eNone:         no shadow
  // * eShadowMap:    same algorythm than inter-objets shadowd
  // * eGroundShadow: independant algorythm with a blur pass
  enum EShadowMode
  {
    eNone = 0,
    eShadowMap,
    eGroundShadow
  };
  EShadowMode             _shadowMode;

private:
  // New functionalities only available on NRE
  // ans not exposed yet
  friend class CATVisInfiniteEnvironmentFactory;
  friend class l_vREPassSystemFactory;
  friend class vREGround;
  friend class CATVisInfiniteEnvGridOverload;

};

class ExportedBySGInfra CATVisPlaneTextureEnvData
{
public:
  CATVisPlaneTextureEnvData();
  virtual ~CATVisPlaneTextureEnvData();
};

class ExportedBySGInfra CATVisPlaneShaderEnvData : public CATVisPlaneTextureEnvData
{
public:
  CATVisPlaneShaderEnvData();
  ~CATVisPlaneShaderEnvData();

  CATString         _shaderFile;
  CATVisParameters  _parameters;
  unsigned int      _tesselation;
  bool              _lightingActivation;
  bool              _prePassZ;
  bool              _useGroundBe;
};


// Only available in NRE
class ExportedBySGInfra CATVisPlaneFacticeCatcherEnvData : public CATVisPlaneTextureEnvData
{
public:
  CATVisPlaneFacticeCatcherEnvData();
  ~CATVisPlaneFacticeCatcherEnvData();
  
  unsigned int _shadowCatcher;
  unsigned int _mirrorCatcher;
};

// Only available in NRE
class ExportedBySGInfra CATVisPlaneInvisibleEnvData : public CATVisPlaneTextureEnvData
{
public:
  CATVisPlaneInvisibleEnvData();
  ~CATVisPlaneInvisibleEnvData();
};


#endif
