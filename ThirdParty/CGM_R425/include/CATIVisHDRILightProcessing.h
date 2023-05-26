
#ifndef CATIVisHDRILightProcessing_h_
#define CATIVisHDRILightProcessing_h_

#include <CATVisHDRILightProcessing.h>
#include <CATString.h>
#include <CATVisColorf.h>
#include <CATMathDirection.h>
#include <CATMathDirectionf.h>
#include <CATMathTransformation.h>
#include <CATPixelImage.h>
#include <vector>

class CATPixelImage;

class ExportedByCATVisHDRILightProcessing CATIVisHDRILightProcessing
{
public:
    
  // @nodoc
  enum ReductionTechnique 
  {
    eSimpleThreshold,
    eIdentifyArea
  };

  // @nodoc
  struct InternalParams 
  {
    bool _useDilation;
    bool _useBlur;
    bool _useSolidAngle;
    int _zoomFactor;
    int _dilationIteration;
    float _blurRadius;
    ReductionTechnique _reduction;

    InternalParams() : _useDilation(true), _useBlur(true),
      _useSolidAngle(true), _zoomFactor(4), _dilationIteration(1),
      _blurRadius(5.0f), _reduction(eSimpleThreshold) 
    {
    }
  };

  struct InputParams 
  {
    // @nodoc
    InternalParams _exParams;
    // input image, if set to NULL, _fileName should be valid.
    CATPixelImage* _pImage; 
    // if _pImage is NULL _fileName should be valid
    CATUnicodeString _fileName;
    // absolute value of the threshold to use
    float _intensityThreshold;
    // Maximum number of lights to add
    int _lightCap;
    // Dome data
    float _domeGroundScale;
    float _domeSize;
    CATMathTransformation _domeRotation;
    // Ground data if dome data is not used
    // ground scaling ratio (ambience editor)
#ifdef CAT_HDRILP_DEBUG
    float _groundScaleRatio;
    CATMathDirection _groundPlaneNormal;
#endif
    // ground offset 
    // float _groundOffset;
    // fileName to where you want to save, 0 length string will return 
    // the output in Result::_pOutImage;
    CATUnicodeString _savePath;

    InputParams() :_pImage(NULL), _intensityThreshold(1.4f)
      ,_lightCap(1), _domeGroundScale(0.0f), _domeSize(1.0f)
#ifdef CAT_HDRILP_DEBUG
      ,_groundScaleRatio(0.0f)
#endif
    {
    }

  };

  struct Light 
  {
    double _origLatitude;
    double _origLongitude;
    
#ifdef CAT_HDRILP_DEBUG

    CATMathDirection _dirFromDomeData; 
    CATMathDirection _dirFromGroundData;

#else

    CATMathDirectionf _direction;

#endif
    int _numPixelsAvgd;
    float _intensity;
    CATVisColorf  _color;
  };

  struct Result 
  {
    float _maxIntensity;
    CATPixelImage* _pOutImage;
    std::vector<Light> _lights;

    Result() : _pOutImage(NULL), _maxIntensity(0) {}
    ~Result() { if (_pOutImage) _pOutImage->Release(); _pOutImage = NULL; }
  };

  
  virtual ~CATIVisHDRILightProcessing();
  
  // Create an instance 
  static CATIVisHDRILightProcessing* CreateInstance();

  // @remarks This function can be as the main entry and exit point
  virtual HRESULT Process(const InputParams& iValue, Result& oRes) = 0;

  /* @nodoc */
  virtual void GetPixelInfo(int x, int y, CATVisColorf& oOriginal, CATVisColorf& oModified) = 0;
};


#endif //CATIVisHDRILightProcessing_h_
