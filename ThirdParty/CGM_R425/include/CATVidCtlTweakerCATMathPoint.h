#ifndef CATVidCtlTweakerCATMathPoint_h
#define CATVidCtlTweakerCATMathPoint_h

// COPYRIGHT Dassault Systemes 2012

// Local framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidBoxing.h>

// Mathematics framework
#include <CATMathPoint.h>

class ExportedByVisuDialogEx CATVidCtlTweakerCATMathPoint : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATMathPoint);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerCATMathPoint();

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();

  void SetX(double i_x);
  double GetX() const;

  void SetY(double i_y);
  double GetY() const;

  void SetZ(double i_z);
  double GetZ() const;

protected:

  virtual ~CATVidCtlTweakerCATMathPoint();

private:
  
  // Copy constructor and equal operator
  CATVidCtlTweakerCATMathPoint (CATVidCtlTweakerCATMathPoint &);
  CATVidCtlTweakerCATMathPoint& operator=(CATVidCtlTweakerCATMathPoint& original);
};

#endif // CATVidCtlTweakerCATMathPoint_h
