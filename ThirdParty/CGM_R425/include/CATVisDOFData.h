// COPYRIGHT Dassault Systemes 2014

#ifndef CATVisDOFData_H
#define CATVisDOFData_H

#include "SGInfra.h"
#include "CATString.h"
#include "CATVisParameters.h"
#include "IVisTexturePtr.h"

//-----------------------------------------------------------------------
// Depth Of Field

class CATVisParameters;

class ExportedBySGInfra CATVisDOFData
{
public:
  enum EType
  {
    eNone,
    eBokeh,
    eCustomShader
  };

  CATVisDOFData ();
  virtual ~CATVisDOFData();
};

class ExportedBySGInfra CATVisDOFBokehData : public CATVisDOFData
{
public:
  CATVisDOFBokehData ();
  CATVisDOFBokehData(const CATVisDOFBokehData& iData);
  const CATVisDOFBokehData& operator=(const CATVisDOFBokehData& iData);
  virtual ~CATVisDOFBokehData();
  
  // this texture represents the  bokeh pattern
  // _bokehTexture is the path to this texture's file
  // if _bokehIVisTexture is set, then it is used instead of _bokehTexture
  CATString       _bokehTexture;
  IVisTexturePtr  _bokehIVisTexture;
  
  bool operator!=(const CATVisDOFBokehData& iData) const;
  bool operator==(const CATVisDOFBokehData& iData) const;
};

class ExportedBySGInfra CATVisDOFShaderData : public CATVisDOFData
{
public:
  CATVisDOFShaderData();  
  CATVisDOFShaderData(const CATVisDOFShaderData& iData);
  const CATVisDOFShaderData& operator=(const CATVisDOFShaderData& iData);
  virtual ~CATVisDOFShaderData();

  CATString        _shaderFile[2];
  CATVisParameters _parameters;

  bool operator!=(const CATVisDOFShaderData& iData) const;
  bool operator==(const CATVisDOFShaderData& iData) const;
};

#endif
