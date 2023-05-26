#ifndef CATVidCtlTweakerCATMathPointf_h
#define CATVidCtlTweakerCATMathPointf_h

// COPYRIGHT Dassault Systemes 2012

// VisuImmersiveDialogEx framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidBoxing.h>

// Mathematics framework
#include <CATMathPointf.h>

class ExportedByVisuDialogEx CATVidCtlTweakerCATMathPointf : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATMathPointf);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerCATMathPointf();

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();

  void SetX(float i_x);
  float GetX() const;

  void SetY(float i_y);
  float GetY() const;

  void SetZ(float i_z);
  float GetZ() const;

  void SetXAsDouble(double i_x);
  double GetXAsDouble() const;

  void SetYAsDouble(double i_y);
  double GetYAsDouble() const;

  void SetZAsDouble(double i_z);
  double GetZAsDouble() const;

protected:

  virtual ~CATVidCtlTweakerCATMathPointf();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerCATMathPointf (CATVidCtlTweakerCATMathPointf &);
  CATVidCtlTweakerCATMathPointf& operator=(CATVidCtlTweakerCATMathPointf& original);
};

#endif // CATVidCtlTweakerCATMathPointf_h
