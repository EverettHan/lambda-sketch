#ifndef CATVidCtlTweakerCATMathPoint2Df_h
#define CATVidCtlTweakerCATMathPoint2Df_h

// COPYRIGHT Dassault Systemes 2005

// VisuImmersiveDialogEx framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidBoxing.h>

// Mathematics framework
#include <CATMathPoint2Df.h>

class ExportedByVisuDialogEx CATVidCtlTweakerCATMathPoint2Df : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATMathPoint2Df);

public:

  // Standard constructor
  CATVidCtlTweakerCATMathPoint2Df();

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

  virtual ~CATVidCtlTweakerCATMathPoint2Df();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerCATMathPoint2Df (CATVidCtlTweakerCATMathPoint2Df &);
  CATVidCtlTweakerCATMathPoint2Df& operator=(CATVidCtlTweakerCATMathPoint2Df& original);
};

#endif // CATVidCtlTweakerCATMathPoint2Df_h
