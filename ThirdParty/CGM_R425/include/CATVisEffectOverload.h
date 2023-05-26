// COPYRIGHT Dassault Systemes 2011

#ifndef CATVisEffectOverload_H
#define CATVisEffectOverload_H

//-----------------------------------------------------------------------

#include "SGInfra.h"
#include "CATVisInfiniteEnvironmentOverload.h"
#include "CATVisEffectPositionEnum.h"

class CATString;
class CATVisColorf;
class CATVisEffectData;
class CATVisInfiniteEnvironmentExtendedData;
class CATVisParameters;

class ExportedBySGInfra CATVisEffectOverload : public CATVisInfiniteEnvironmentOverload
{
public:
  static CATVisEffectOverload* Create(const CATVisEffectData& iData, unsigned int iRemoveSimilarEffect=0);
  
  HRESULT GetData       (CATVisEffectData& oEffectData) const;
  HRESULT GetParamName  (unsigned int iParamID, CATString& oParamShader) const;
  HRESULT GetParamValue (const CATString& iParamShader, float& oValue) const;
  HRESULT GetParamValue (const CATString& iParamShader, float& oValue, float& oMinValue, float& oMaxValue, float& oStepValue) const;
  HRESULT GetParamValue (const CATString& iParamShader, CATVisColorf& oColor) const;
  HRESULT GetParamValue (const CATString& iParamShader, CATString& oString) const;
  HRESULT GetParameters (CATVisParameters& oParameters) const;

  HRESULT Activate         (bool iActivation);
  HRESULT ModifyPosition   (CATVisEffectPositionEnum iPos);
  HRESULT ModifyRecursivity(unsigned int iNum);
  HRESULT ModifyParameters (const CATVisParameters& iParameters);
  HRESULT ModifyParamValue (const CATString& iParamShader, const float iValue);
  HRESULT ModifyParamValue (const CATString& iParamShader, const CATVisColorf& iColor);
  HRESULT ModifyParamValue (const CATString& iParamShader, const CATString& iString);

protected:
  virtual void Overload(CATVisInfiniteEnvironmentExtendedData& ioData) const;

  CATVisEffectOverload(const CATVisEffectData& iData, unsigned int removeSimilarEffect);
  virtual ~CATVisEffectOverload();

private:
  CATVisEffectData* _effectData;
  unsigned int      _removeSimilarEffect;
};

//-----------------------------------------------------------------------

#endif
