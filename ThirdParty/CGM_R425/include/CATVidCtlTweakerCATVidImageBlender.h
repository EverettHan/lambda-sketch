#ifndef CATVidCtlTweakerCATVidImageBlender_h
#define CATVidCtlTweakerCATVidImageBlender_h

// COPYRIGHT Dassault Systemes 2005

// VisuImmersiveDialogEx framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidBoxing.h>
#include <CATVidImageBlender.h>
#include <CATVidImageProcessing.h>

class ExportedByVisuDialogEx CATVidCtlTweakerCATVidImageBlender : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATVidImageBlender);

public:
  
  // Standard constructors and destructors
  CATVidCtlTweakerCATVidImageBlender();

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();

  void SetColor(const CATVidColor& i_color);
  const CATVidColor& GetColor() const;

  void SetBlendingMode(CATVidImageProcessing::BlendingMode i_blendingMode);
  CATVidImageProcessing::BlendingMode GetBlendingMode() const;

protected:

  virtual ~CATVidCtlTweakerCATVidImageBlender();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerCATVidImageBlender (CATVidCtlTweakerCATVidImageBlender &);
  CATVidCtlTweakerCATVidImageBlender& operator=(CATVidCtlTweakerCATVidImageBlender& original);
};

#endif // CATVidCtlTweakerCATVidImageBlender_h
