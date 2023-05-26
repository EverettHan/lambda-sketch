// COPYRIGHT Dassault Systemes 2012

#ifndef CATVisStyle_H
#define CATVisStyle_H

#include "SGInfra.h"
#include "CATVisInfiniteEnvironmentOverload.h"
#include "list.h"
#include "CATString.h"
#include "CATVisEffectPositionEnum.h"

class CATVisEffectData;
class CATVisEffectOverload;
class CATVisColorf;
class CATVisStreamer;
class CATUnicodeString;
class CATVisColorModifier;
class CATVisParameters;
class ExportedBySGInfra CATVisStyle: public CATVisInfiniteEnvironmentOverload
{
  friend class CATVisStyleFactory;

public:
  //-------------------------
  // lifecycle

  // si iID est différent d'une chaine vide, on utilise une factory
  // pour creer un des environnement predefinis
  static CATVisStyle* Create(const CATString& iID = "");

  // clone
  CATVisStyle*        Clone();

  //-------------------------
  // General

  const CATString&    GetID() const;

  const CATString&    GetName() const;
  void                SetName(const CATString& iName);

  //-------------------------
  // Settings

  void            SaveToSettings          (const CATString& iID);
  static HRESULT  GetStyleIDFromSettings  (unsigned int iID, CATString& oID, CATString& oName);
  static HRESULT  SwapInSettings          (unsigned int iID1, unsigned int iID2);
  static unsigned int GetStyleNumberInSettings();
  static HRESULT  IsPresentInSettings     (const CATString& iID);
  static void     DeleteInSettings        (const CATString& iID);
  static void     DeleteAllInSettings     ();

  //-------------------------
  // Effets

  int     AddEffect               (const CATVisEffectData& iData);  

  HRESULT GetEffectData           (unsigned int iID, CATVisEffectData& oEffectData) const;
  HRESULT GetEffectParamName      (unsigned int iID, unsigned int iParamID, CATString& oParamShader) const;
  HRESULT GetEffectParamValue     (unsigned int iID, const CATString& iParamName, float& oValue, float& oMinValue, float& oMaxValue, float& oStepValue) const;
  HRESULT GetEffectParamValue     (unsigned int iID, const CATString& iParamName, CATVisColorf& oColor) const;
  HRESULT GetEffectParamValue     (unsigned int iID, const CATString& iParamName, CATString& oString) const;
  HRESULT GetEffectParameters     (unsigned int iID, CATVisParameters& oParameters) const;

  HRESULT Activate                (unsigned int iID, bool iActivation);
  HRESULT ModifyRecursivity       (unsigned int iID, unsigned int iNum);
  HRESULT ModifyEffectParameters  (unsigned int iID, const CATVisParameters& iParameters);
  HRESULT ModifyEffectParamValue  (unsigned int iID, const CATString& iParamName, const float iValue);
  HRESULT ModifyEffectParamValue  (unsigned int iID, const CATString& iParamName, const CATVisColorf& iColor);
  HRESULT ModifyEffectParamValue  (unsigned int iID, const CATString& iParamName, const CATString& iString);
  HRESULT SwapEffects             (unsigned int iFirstID, unsigned int iSecondID);

  HRESULT RemoveEffect            (unsigned int iID);
  void    RemoveAllEffects        ();

  //-------------------------
  // Background Color impact

  void AddBgColorModifier         (CATVisColorModifier* iColorModifier);

  //-------------------------
  // Dump

  void DumpCCode(CATUnicodeString& oCode);

protected:
  virtual void Overload(CATVisInfiniteEnvironmentExtendedData& ioData) const;

private:
  CATVisStyle(const CATString& iID);
  virtual ~CATVisStyle();

  CATVisStyle (CATVisStyle &);
  CATVisStyle& operator=(CATVisStyle&);

  static void  InitStreamer(CATVisStreamer& oStreamer);

  void  Read  (CATVisStreamer& ioStreamer, const CATString& iID);
  void  Write (CATVisStreamer& ioStreamer, const CATString& iID);

  list<CATVisEffectOverload> _effects;
  list<CATVisColorModifier>  _bgColorModifiers;
  CATString                  _id;
  CATString                  _name;
};

//-----------------------------------------------------------------------

#endif
