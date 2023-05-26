// COPYRIGHT Dassault Systemes 2014

#ifndef CATVisSkyLightingData_H
#define CATVisSkyLightingData_H

#include "SGInfra.h"

#include "CATString.h"
#include "CAT4x4Matrix.h"
#include "IVisTexturePtr.h"
#include "CATMathPoint.h"

class IVisTexture;
class CATVisParameters;

//-------------------------------------------------------------------------------------
// Sky Lighting Data

class ExportedBySGInfra CATVisSkyLightingData
{
public:
  virtual ~CATVisSkyLightingData();

  enum EType
  {
    eNone,
    eIBL,
    eProceduralIBL,
    eEnvMap
  };

  virtual void GetParameters(CATVisParameters& oParameters) const = 0;
  virtual void SetParameters(const CATVisParameters& iParameters) = 0;

protected:
  CATVisSkyLightingData();
  CATVisSkyLightingData(const CATVisSkyLightingData& iData);
  const CATVisSkyLightingData& operator=(const CATVisSkyLightingData& iData);
};

//-------------------------------------------------------------------------------------
// Base IBL

class ExportedBySGInfra CATVisBaseIBLData : public CATVisSkyLightingData
{
public:
  virtual ~CATVisBaseIBLData();

  float             _specularScaleFactor;
  float             _diffuseScaleFactor;

  CAT4x4Matrix      _transfoMatrix;
  
  enum ECorrectionType // Copied from CATMaterialIBLParameters
  {
    eCorrection_None = 0,
    eCorrection_Box,
    eCorrection_Cylinder,
    eCorrection_Sphere,
    eCorrection_CutSphere,
    eCorrection_Count
  };
  ECorrectionType   _correctionActivation;
  float             _correctionShapeSize[3];
  CAT4x4Matrix      _correctionShapeSpace;

  enum ECorrectionLink
  {
    eCorrectionLink_None = 0,
    eCorrectionLink_ModelBE,
    eCorrectionLink_Ground,
    eCorrectionLink_Count
  };
  ECorrectionLink   _correctionLinkForShape;
  ECorrectionLink   _correctionLinkForShotPos;
  float             _correctionShotPosLinkScale;

  virtual void GetParameters(CATVisParameters& oParameters) const;
  virtual void SetParameters(const CATVisParameters& iParameters);

protected:
  CATVisBaseIBLData();
  CATVisBaseIBLData(const CATVisBaseIBLData& iData);
  const CATVisBaseIBLData& operator=(const CATVisBaseIBLData& iData);
  bool operator==(const CATVisBaseIBLData& iData) const;
  bool operator!=(const CATVisBaseIBLData& iData) const;
};

//-------------------------------------------------------------------------------------
// Classical IBL

class ExportedBySGInfra CATVisIBLData : public CATVisBaseIBLData
{
public:
  CATVisIBLData();
  CATVisIBLData(const CATVisIBLData& iData);
  virtual ~CATVisIBLData();

  const CATVisIBLData& operator=(const CATVisIBLData& iData);
  bool operator==(const CATVisIBLData& iData) const;
  bool operator!=(const CATVisIBLData& iData) const;

  CATString   _specularCubeMap;
  CATString   _diffuseCubeMap;
  
  void SetSpecularMap(const IVisTexturePtr& iTexture);
  inline const IVisTexturePtr& GetSpecularMap() const {return m_SpecularMap;};

  void SetDiffuseMap(const IVisTexturePtr& iTexture);
  inline const IVisTexturePtr& GetDiffuseMap() const {return m_DiffuseMap;};

  virtual void GetParameters(CATVisParameters& oParameters) const;
  virtual void SetParameters(const CATVisParameters& iParameters);

private:
  IVisTexturePtr m_SpecularMap;
  IVisTexturePtr m_DiffuseMap;
};


//-------------------------------------------------------------------------------------
// Procedural IBL

class ExportedBySGInfra CATVisProceduralIBLData : public CATVisBaseIBLData
{
public:
  enum EInputType
  {
    eLatLong,
    eCubeMap,
    eAutomatic
  };
  
  enum Sampling
  {
    eSamplingNormal,
    eSamplingFiltered
  };

  CATVisProceduralIBLData();
  CATVisProceduralIBLData(const CATVisProceduralIBLData& iData);
  virtual ~CATVisProceduralIBLData();

  const CATVisProceduralIBLData& operator=(const CATVisProceduralIBLData& iData);
  bool operator==(const CATVisProceduralIBLData& iData) const;
  bool operator!=(const CATVisProceduralIBLData& iData) const;

  EInputType      _inputType;
  
  // only used by eLatLong or eCubeMap
  CATString       _inputMap;      
  void SetInputMap(const IVisTexturePtr& iTexture);
  inline const IVisTexturePtr& GetInputMap() const { return m_InputMap; };

  // only used by eAutomatic
  CATMathPoint _shootPosition;

  // for All
  unsigned int  _specularSize;
  unsigned int  _specularBRDFSamples;
  unsigned int  _diffuseSize;
  unsigned int  _diffuseBRDFSamples;
  Sampling      _sampling;
  float         _maxIntensity;
  bool          _updated;

  unsigned int ComputeSpecularMipLevel        () const;
  unsigned int ComputeDiffuseDeferredNumStep  () const;
  unsigned int ComputeSpecularDeferredNumStep () const;

  virtual void GetParameters(CATVisParameters& oParameters) const;
  virtual void SetParameters(const CATVisParameters& iParameters);

private:
  unsigned int _ComputeDeferredNumStep(unsigned int iSize, unsigned int iBRDFSamples) const;

  IVisTexturePtr m_InputMap;
};


#endif
