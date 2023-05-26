#ifndef CATVidCtlTweakerCATMathVector2Df_h
#define CATVidCtlTweakerCATMathVector2Df_h

// COPYRIGHT Dassault Systemes 2005

// VisuImmersiveDialogEx framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidBoxing.h>

// Mathematics framework
#include <CATMathVector2Df.h>

class ExportedByVisuDialogEx CATVidCtlTweakerCATMathVector2Df : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATMathVector2Df);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerCATMathVector2Df();

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

  virtual ~CATVidCtlTweakerCATMathVector2Df ();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerCATMathVector2Df (CATVidCtlTweakerCATMathVector2Df &);
  CATVidCtlTweakerCATMathVector2Df& operator=(CATVidCtlTweakerCATMathVector2Df& original);

};

#endif // CATVidCtlTweakerCATMathVector2Df_h
