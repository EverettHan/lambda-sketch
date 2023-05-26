#ifndef CATVisGraphicsOptimizerSettings_H
#define CATVisGraphicsOptimizerSettings_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "SGInfra.h"

#include "CATUnicodeString.h"

class CATSysPreferenceRepository;

typedef unsigned int CATVisEnvironmentFallbacks;

#define ENVFLBK_NONE      (0x0)
#define ENVFLBK_SHADER    (0x1)
#define ENVFLBK_SHADOW    (0x2)
#define ENVFLBK_MIRROR    (0x4)

enum CATVisSSAOQuality
{
  SSAOQUALITY_NONE  = 0,
  SSAOQUALITY_LOW   = 1,
  SSAOQUALITY_HIGH  = 2
};

class ExportedBySGInfra CATVisGraphicsOptimizerSettings
{
public:

  static HRESULT AreVertexArraysAllowed(CATBoolean& oValue);
  static HRESULT AreVertexBufferObjectsAllowed(CATBoolean& oValue);

  static HRESULT IsGenericDriverUsed(CATBoolean& oValue);

  static HRESULT IsAdvancedHighlightAllowed(CATBoolean& oValue);

  static HRESULT GetEnvironmentFallbacks(CATVisEnvironmentFallbacks& oValue);
  static HRESULT GetSSAOQuality(CATVisSSAOQuality& oValue);
  static HRESULT GetSSAOQualityMax(CATVisSSAOQuality& oValueMax);
  static HRESULT GetSSAOQuality(int& oValue);

  static HRESULT IsAAAllowed(CATBoolean & oValue);

  static HRESULT InvalidateSettings();

private:

  static HRESULT ReadValueFromSettings(const CATUnicodeString& iKeyName, unsigned int& oValue);
  static void ReadSSAOSettings();

  static void InitializeParametersRepository();

  static CATSysPreferenceRepository* _pGraphicsOptimizerParametersRepository;

  static CATBoolean _sbVertexArraysSettingValid;
  static CATBoolean _sbVertexBufferObjectsSettingValid;
  static CATBoolean _sbGenericDriverSettingValid;
  static CATBoolean _sbHighlightSettingValid;
  static CATBoolean _sbEnvironmentSettingValid;
  static CATBoolean _sbSSAOSettingValid;
  static CATBoolean _sbFSAASettingValid;

  static CATBoolean _sbCurrentVertexArraysSettingValue;
  static CATBoolean _sbCurrentVertexBufferObjectsSettingValue;
  static CATBoolean _sbCurrentGenericDriverSettingValue;
  static CATBoolean _sbCurrentHighlightSettingValue;
  static CATBoolean _sbCurrentFSAASettingValue;

  static CATVisEnvironmentFallbacks _sCurrentEnvironmentSettingValue;
  static CATVisSSAOQuality          _sCurrentSSAOSettingValue;
  static CATVisSSAOQuality          _sCurrentSSAOSettingValueMax;
};

#endif
