#ifndef CATVidCtlTweakerCATVidRGBAGradient_h
#define CATVidCtlTweakerCATVidRGBAGradient_h

// COPYRIGHT Dassault Systemes 2015

// VisuImmersiveDialogEx framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweakerCATVidRGBA.h>


class CATVidColor;
class CATVidRGBA;

class ExportedByVisuDialogEx CATVidCtlTweakerCATVidRGBAGradient : public CATVidCtlTweakerCATVidRGBA
{
  //CATDeclareClass; 
  CATDeclareTweaker(CATVidRGBAGradient);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerCATVidRGBAGradient();  

  virtual void CATSYPModifyEditedProperties();

  CATVidRGBA GetStartValue()const;
  void SetStartValue(const CATVidRGBA & i_startColor);
  CATVidRGBA GetEndValue()const;
  void SetEndValue(const CATVidRGBA & i_endColor);
  CATVidRGBA GetCurrentValue()const;
  void SetCurrentValue(const CATVidRGBA & i_currentColor);
  CATVidColor GetStartColorAsVidColor()const;
  void SetStartColorAsVidColor(const CATVidColor i_StartVidColor);
  CATVidColor GetEndColorAsVidColor()const;
  void SetEndColorAsVidColor(const CATVidColor i_EndVidColor);
  CATVidColor GetCurrentColorAsVidColor()const;
  void SetCurrentColorAsVidColor(const CATVidColor i_CurrentVidColor);
 
protected:

  virtual ~CATVidCtlTweakerCATVidRGBAGradient();
   
  //void TemplateDataUpdated();

  virtual void InternalSetData();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerCATVidRGBAGradient (CATVidCtlTweakerCATVidRGBAGradient &);
  CATVidCtlTweakerCATVidRGBAGradient& operator=(CATVidCtlTweakerCATVidRGBAGradient& original);  

  void BuildTweakerView();
  void BuildReadOnlyView();
  void BuildEditionView();

};

#endif // CATVidCtlTweakerCATVidRGBAGradient_h
