#ifndef CATVidCtlTweakerCATMathVectorf_h
#define CATVidCtlTweakerCATMathVectorf_h

// COPYRIGHT Dassault Systemes 2012

// VisuImmersiveDialogEx framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidBoxing.h>

// Mathematics framework
#include <CATMathVectorf.h>

class ExportedByVisuDialogEx CATVidCtlTweakerCATMathVectorf: public CATVidCtlTweaker
{
  CATDeclareTweaker(CATMathVectorf);

public:

  // Standard constructors and destructors
   CATVidCtlTweakerCATMathVectorf();

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

  virtual ~CATVidCtlTweakerCATMathVectorf();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerCATMathVectorf (CATVidCtlTweakerCATMathVectorf &);
  CATVidCtlTweakerCATMathVectorf& operator=(CATVidCtlTweakerCATMathVectorf& original);
};

#endif // CATVidCtlTweakerCATMathVectorf_h
