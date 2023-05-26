// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisBackgroundEnvData_H
#define CATVisBackgroundEnvData_H

#include "SGInfra.h"

#include "CATVisColor.h" 
#include "CATVisColorf.h"
#include "CATMathDirectionf.h"
#include "CATMathPointf.h"
#include "CATString.h"
#include "CATVisParameters.h"

//-----------------------------------------------------------------------
// background data

class ExportedBySGInfra CATVisBackgroundEnvData
{   
public:
  enum CATVisBackgroundType
  {
    BasicBackground         = 0,
    CubeMapBackground       = 1,
    SkyBackground           = 2,
    TexturedBackground      = 3,
    ShaderBackground        = 4,
    Textured2DBackground    = 5,
    CloudBackground         = 6,
    RealisticSkyBackground  = 7
  };

  enum CATVisBackgroundPosition
  {
    BehindBackground  = 0,
    FrontBackground   = 1
  };

  CATVisBackgroundEnvData();
  virtual ~CATVisBackgroundEnvData();
  bool operator==(const CATVisBackgroundEnvData& iData) const;
  bool operator!=(const CATVisBackgroundEnvData& iData) const;

  // geometry
  CATMathDirectionf         _direction; // direction du zenith

  // visual
  CATVisColor               _color;     // couleur dominante du ciel

  CATVisBackgroundPosition  _position;  // position du background
                                        // * behind: le background sera positionne dans la pile de maniere
                                        //           a etre derriere les background front ainsi
                                        //           que les divers sources lumineuses (soleil).
                                        // * front: le background sera positionne dans la pile de maniere
                                        //           a etre devant les background behind ainsi
                                        //           que les divers sources lumineuses (soleil).

  // obsolete, garde uniquement pour ne pas peter le build
  // les donnees relaticves a ce point se trouvent dans CATVisSkyEnvData maintenant
  CATVisColor             _skyLineCol;    // couleur de la ligne d'horizon
};

class ExportedBySGInfra CATVisBackgroundEnvAdditionalData
{
public:
  CATVisBackgroundEnvAdditionalData();
  virtual ~CATVisBackgroundEnvAdditionalData();
};

class ExportedBySGInfra CATVisUniformBackgroundEnvData : public CATVisBackgroundEnvAdditionalData
{
public:
  CATVisUniformBackgroundEnvData();
  virtual ~CATVisUniformBackgroundEnvData();
  
  CATVisUniformBackgroundEnvData(const CATVisUniformBackgroundEnvData& iData);
  const CATVisUniformBackgroundEnvData& operator=(const CATVisUniformBackgroundEnvData& iData);
  bool operator==(const CATVisUniformBackgroundEnvData& iData) const;
  bool operator!=(const CATVisUniformBackgroundEnvData& iData) const;

  float _intensity; // intensité lumineuse du ciel
};

class ExportedBySGInfra CATVisSkyEnvData : public CATVisBackgroundEnvAdditionalData
{
public:
  CATVisSkyEnvData();
  virtual ~CATVisSkyEnvData();

  CATVisSkyEnvData(const CATVisSkyEnvData& iData);
  const CATVisSkyEnvData& operator=(const CATVisSkyEnvData& iData);
  bool operator==(const CATVisSkyEnvData& iData) const;
  bool operator!=(const CATVisSkyEnvData& iData) const;

  // position
  float                   _skyLineRatio;  // pourcentage du ciel sur lequel s'etend le degrade entre l'horizon
                                          // et le ciel 
  unsigned int            _skyLineType;   // mode de calcul du degrade 
                                          // 1: lineaire
                                          // 2: carre
                                          // 3: cubic

  // visual properties
  CATVisColor _color;               // couleur du ciel
  CATVisColor _skyLineCol;          // couleur de la ligne d'horizon
  float       _skyIntensity;        // facteur multiplicatif global du ciel
};

class ExportedBySGInfra CATVisTexturedBackgroundEnvData : public CATVisBackgroundEnvAdditionalData
{
public:
  CATVisTexturedBackgroundEnvData();
  virtual ~CATVisTexturedBackgroundEnvData();

  CATVisTexturedBackgroundEnvData(const CATVisTexturedBackgroundEnvData& iData);
  const CATVisTexturedBackgroundEnvData& operator=(const CATVisTexturedBackgroundEnvData& iData);
  bool operator==(const CATVisTexturedBackgroundEnvData& iData) const;
  bool operator!=(const CATVisTexturedBackgroundEnvData& iData) const;

  // visual properties
  CATString   _textureFiles[6];   // nom des fichiers des textures d'une cubemap
  float       _intensity;         // facteur multiplicateur de l'intensite du ciel
  float       _scale;
};

class ExportedBySGInfra CATVisShaderBackgroundEnvData : public CATVisBackgroundEnvAdditionalData
{
public:
  CATVisShaderBackgroundEnvData();
  virtual ~CATVisShaderBackgroundEnvData();

  CATVisShaderBackgroundEnvData(const CATVisShaderBackgroundEnvData& iData);
  const CATVisShaderBackgroundEnvData& operator=(const CATVisShaderBackgroundEnvData& iData);
  bool operator==(const CATVisShaderBackgroundEnvData& iData) const;
  bool operator!=(const CATVisShaderBackgroundEnvData& iData) const;

  // visual properties
  CATString         _shaderFile;      // nom du shader
  CATVisParameters  _parameters;      // paremetres du shader
};

class ExportedBySGInfra CATVisTextured2DBackgroundEnvData : public CATVisBackgroundEnvAdditionalData
{
public:
  CATVisTextured2DBackgroundEnvData();
  virtual ~CATVisTextured2DBackgroundEnvData();

  CATVisTextured2DBackgroundEnvData(const CATVisTextured2DBackgroundEnvData& iData);
  const CATVisTextured2DBackgroundEnvData& operator=(const CATVisTextured2DBackgroundEnvData& iData);
  bool operator==(const CATVisTextured2DBackgroundEnvData& iData) const;
  bool operator!=(const CATVisTextured2DBackgroundEnvData& iData) const;

  // visual properties
  CATString             _textureFile;   // nom du fichier de texture
};

class ExportedBySGInfra CATVisCloudEnvData : public CATVisBackgroundEnvAdditionalData
{
public:
  CATVisCloudEnvData();
  virtual ~CATVisCloudEnvData();

  CATVisCloudEnvData(const CATVisCloudEnvData& iData);
  const CATVisCloudEnvData& operator=(const CATVisCloudEnvData& iData);
  bool operator==(const CATVisCloudEnvData& iData) const;
  bool operator!=(const CATVisCloudEnvData& iData) const;

  // visual properties
  CATString           _texture;	  // nom du fichier de texture
  unsigned int        _textureFilter; // rend les bord de la texture totallement transparent
  unsigned int        _textureChanelMode; // 0:red, 1:green, 2:blue, 3:luminance

  CATMathDirectionf   _direction; // direction des nuages dans le plan defini par la normale aux nuages
  float               _altitude;
  float               _scale;     // facteur de zoom des nuages 

  CATVisColorf	_colorSky[3]; // day, sunset, night
  CATVisColorf	_colorSun[3]; // day, sunset, night
  float					_sampleStep;
  float					_densitySharpness;
  float					_densityBias;
};

class ExportedBySGInfra CATVisRealisticSkyEnvData : public CATVisBackgroundEnvAdditionalData
{
public:    
  CATVisRealisticSkyEnvData();
  virtual ~CATVisRealisticSkyEnvData();

  CATVisRealisticSkyEnvData(const CATVisRealisticSkyEnvData& iData);
  const CATVisRealisticSkyEnvData& operator=(const CATVisRealisticSkyEnvData& iData);
  bool operator==(const CATVisRealisticSkyEnvData& iData) const;
  bool operator!=(const CATVisRealisticSkyEnvData& iData) const;

  CATString			_textureStars;
};

#endif
