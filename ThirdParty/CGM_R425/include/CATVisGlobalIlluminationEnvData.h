// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisGlobalIlluminationEnvData_H
#define CATVisGlobalIlluminationEnvData_H

#include "SGInfra.h"

#include "CATVisColor.h" 
#include "CATVisColorf.h"
#include "CATMathDirectionf.h"
#include "CATMathPointf.h"
#include "CATString.h"

//-----------------------------------------------------------------------
// Global Illumination

class ExportedBySGInfra CATVisGlobalIlluminationEnvData
{
public:
  enum EType
  {
    eNone,
    eUniform,
    eFacticeLights
  };
  
  CATVisGlobalIlluminationEnvData();
  virtual ~CATVisGlobalIlluminationEnvData();
  void Apply(const CATVisGlobalIlluminationEnvData& iData);

  unsigned int    _activation;
  float           _coef;

  unsigned int    _automaticColor; // si ce flag est 0, on utilise la couleur, sinon
                                   // la couleur de la lumiere ambient est calculee de maniere
                                   // automotique par rapport a l'environement.
  CATVisColor     _color;
};

class ExportedBySGInfra CATVisUniformGIEnvData : public CATVisGlobalIlluminationEnvData
{
public:
  CATVisUniformGIEnvData();
  virtual ~CATVisUniformGIEnvData();
};

class ExportedBySGInfra CATVisFacticeLightsGIEnvData : public CATVisGlobalIlluminationEnvData
{
public:
  CATVisFacticeLightsGIEnvData();
  virtual ~CATVisFacticeLightsGIEnvData();

  float           _kAmbEye;
  float           _kAmbLight;

  // obsolete: A priori cette donnee ne sert plus a rien
  float           _kAmb; 
};

// util pour eviter erreurs de compils dure axu divers migration de nom
// et d'API
#include "CATVisAmbOcclusionData.h"

// 2eme migration
// l'AO est decorelée de la Global Illumination
typedef CATVisSSAOData                            CATVisAmbOcclusionGIEnvData;      

// 1ere migration
typedef CATVisAmbOcclusionGIEnvData               CATVisSSAOGIEnvData;  
typedef CATVisAmbOcclusionGIEnvData::ERadiusType  CATVisSSAORadiusType;

         


#endif
