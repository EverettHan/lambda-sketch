// COPYRIGHT Dassault Systemes 2011

#ifndef CATVisParameters_H
#define CATVisParameters_H

#include "SGInfra.h"
#include "CATListOfCATUnicodeString.h"
#include "CATString.h"

class CATVisColorf;
class CATGraphicMaterial;
class CATMathDirectionf;
class CATMathVectorf;
class CATMathVector;
class CATMathPoint;
class CATMathVector2Df;
class CATMathPoint2D;
class CAT4x4Matrix;
class l_CATVisParameters;
class IVisTexturePtr;
class ExportedBySGInfra CATVisParameters
{
public:
  enum EParamType
  {
    eUndefined,
    eValue,
    eColorRGBA,
    eColorRGB,
    eDirection,
    eVector,
    ePosition,
    eVector2D,
    ePosition2D,
    eState,
    eBool,
    eTexture,
    eIVisTexture,
    eString,
    eShaderOption,
    eUVTransfo,
    eMatrix
  };

  CATVisParameters();
  CATVisParameters(const CATVisParameters& iData);
  CATVisParameters& operator=(const CATVisParameters& iData);
  ~CATVisParameters();
  
  int operator!=(const CATVisParameters& iParameters) const;
  bool IsSameShaderOptions(const CATVisParameters& iParameters) const;

  unsigned int GetParamNumber() const;
  unsigned int IsParamAvailable(const char* iParamName) const;

  HRESULT GetParamName          (unsigned int iParamID, CATString& oParamShader) const;
  HRESULT GetParamName          (unsigned int iParamID, CATString& oParamShader, EParamType& oType) const;
  HRESULT GetParamName          (unsigned int iParamID, CATString& oParamShader, EParamType& oType, unsigned int& oCustomType) const;
  HRESULT GetParamValue         (const char*      iParamName, float& oValue) const;
  HRESULT GetParamValue         (const char*      iParamName, float& oValue, float& oMinValue, float& oMaxValue, float& oStepValue) const;
  HRESULT GetParamColor         (const char*      iParamName, CATVisColorf& oColor) const;
  HRESULT GetParamTexture       (const char*      iParamName, CATString& oString) const;
  HRESULT GetParamTexture       (const char*      iParamName, IVisTexturePtr& oTexture) const;
  HRESULT GetParamString        (const char*      iParamName, CATString& oString) const;
  HRESULT GetParamState         (const char*      iParamName, int& oValue) const;
  HRESULT GetParamState         (const char*      iParamName, int& oValue, int& oMinValue, int &oMaxValue, CATListOfCATUnicodeString& oEnumValues) const;
  HRESULT GetParamBool          (const char*      iParamName, bool& oFlag) const;
  HRESULT GetParamDirection     (const char*      iParamName, CATMathDirectionf&  oDirection) const;
  HRESULT GetParamVector        (const char*      iParamName, CATMathVectorf&     oVector)    const;
  HRESULT GetParamVector        (const char*      iParamName, CATMathVector&      oVector)    const;
  HRESULT GetParamPosition      (const char*      iParamName, CATMathPoint&       oPoint)     const;
  HRESULT GetParamVector2D      (const char*      iParamName, CATMathVector2Df&   oVector)    const;
  HRESULT GetParamPosition2D    (const char*      iParamName, CATMathPoint2D&     oPoint)     const;
  HRESULT GetParamShaderOption  (const char*      iParamName, bool& oActivation, unsigned int& oValue) const;
  HRESULT GetParamUVTransfo     (const char*      iParamName, CAT4x4Matrix& oMatrix) const;
  HRESULT GetParamUVTransfo     (const char*      iParamName, CATMathVector2Df& oScale, CATMathVector2Df& oTranslate, float& oRotate) const;
  HRESULT GetParamMatrix        (const char*      iParamName, CAT4x4Matrix& oMatrix) const;
  
  enum EModificationMode
  {
    eOnlyModify,        // a parameter can only be modifed (it can't be created if doesn't exist yet)
    eOnlyModifyValue,   // same as eOnlyModify but only value can be modified, Meta data (value min, max, step, enum) can't be modified.
    eCreateAndModify    // a new parameter can be created and modified
  };
  void SetModificationMode(EModificationMode iMode);
  
  HRESULT SetParamValue         (const char* iParamName, float iValue,  unsigned int iType = 0);
  HRESULT SetParamValue         (const char* iParamName, float iValue, float iMinValue, float iMaxValue, float iStepValue, unsigned int iType = 0);
  HRESULT SetParamColorRGBA     (const char* iParamName, const CATVisColorf& iColor, unsigned int iType = 0);
  HRESULT SetParamColorRGB      (const char* iParamName, const CATVisColorf& iColor, unsigned int iType = 0);
  HRESULT SetParamTexture       (const char* iParamName, const CATString&  iString,  unsigned int iType=0);
  HRESULT SetParamTexture       (const char* iParamName, const IVisTexturePtr& iTexture, unsigned int iType = 0);
  HRESULT SetParamString        (const char* iParamName, const CATString&  iString,  unsigned int iType = 0);
  HRESULT SetParamState         (const char* iParamName, int iValue, unsigned int iType = 0);
  HRESULT SetParamState         (const char* iParamName, int iValue, int iMinValue, int iMaxValue, unsigned int iType = 0);
  HRESULT SetParamState         (const char* iParamName, int iValue, const CATListOfCATUnicodeString& iEnumValues, unsigned int iType = 0);
  HRESULT SetParamState         (const char* iParamName, int iValue, const CATUnicodeString& iEnumValues, unsigned int iType = 0);
  HRESULT SetParamBool          (const char* iParamName, bool  iFlag, unsigned int iType = 0);
  HRESULT SetParamDirection     (const char* iParamName, const CATMathDirectionf&  iDirection, unsigned int iType = 0);
  HRESULT SetParamVector        (const char* iParamName, const CATMathVector&      iVector,    unsigned int iType = 0);
  HRESULT SetParamVector        (const char* iParamName, const CATMathVectorf&     iVector,    unsigned int iType = 0);
  HRESULT SetParamPosition      (const char* iParamName, const CATMathPoint&       iPoint,     unsigned int iType = 0);
  HRESULT SetParamVector2D      (const char* iParamName, const CATMathVector2Df&   iVector,    unsigned int iType = 0);
  HRESULT SetParamPosition2D    (const char* iParamName, const CATMathPoint2D&    iPoint,     unsigned int iType = 0);
  HRESULT SetParamUVTransfo     (const char* iParamName, const CATMathVector2Df&   iScale, const CATMathVector2Df& iTranslate, float iRotate, unsigned int iType = 0);
  HRESULT SetParamMatrix        (const char* iParamName, const CAT4x4Matrix&       iMatrix, unsigned int iType = 0);
  HRESULT SetParamShaderOption  (const char* iParamName, bool iActivation = true, unsigned int iValue = 1);

  HRESULT ReplaceParamName      (const char* iLastParamName, const char* iNewParamName);

  void    EmptyParams           ();
  
  void Update                   (const CATVisParameters& iParameters, const char* iPrefix="", const char* iSuffix="");

private:
  l_CATVisParameters*   m_Letter;
};

//-----------------------------------------------------------------------

#endif
