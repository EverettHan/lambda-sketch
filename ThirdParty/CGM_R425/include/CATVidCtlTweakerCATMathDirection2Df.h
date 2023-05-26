#ifndef CATVidCtlTweakerCATMathDirection2Df_h
#define CATVidCtlTweakerCATMathDirection2Df_h

// COPYRIGHT Dassault Systemes 2005

// VisuImmersiveDialogEx framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidBoxing.h>

// Mathematics framework
#include <CATMathDirection2Df.h>

class ExportedByVisuDialogEx CATVidCtlTweakerCATMathDirection2Df : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATMathDirection2Df);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerCATMathDirection2Df();

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();

  void SetX(float i_x);
  float GetX() const;

  void SetY(float i_y);
  float GetY() const;

  void SetXAsDouble(double i_x);
  double GetXAsDouble() const;

  void SetYAsDouble(double i_y);
  double GetYAsDouble() const;

protected:

  virtual ~CATVidCtlTweakerCATMathDirection2Df();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerCATMathDirection2Df (CATVidCtlTweakerCATMathDirection2Df &);
  CATVidCtlTweakerCATMathDirection2Df& operator=(CATVidCtlTweakerCATMathDirection2Df& original);
};

#endif // CATVidCtlTweakerCATMathDirection2Df_h
