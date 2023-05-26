#ifndef CATVidCtl_CATMathDirection_h
#define CATVidCtl_CATMathDirection_h

// COPYRIGHT Dassault Systemes 2012

// Local framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidBoxing.h>

// Mathematics framework
#include <CATMathDirection.h>

class ExportedByVisuDialogEx CATVidCtlTweakerCATMathDirection : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATMathDirection);

public:

  // Standard constructor
  CATVidCtlTweakerCATMathDirection();

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();

  void SetX(double i_x);
  double GetX() const;

  void SetY(double i_y);
  double GetY() const;

  void SetZ(double i_z);
  double GetZ() const;

protected:

  virtual ~CATVidCtlTweakerCATMathDirection();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerCATMathDirection (CATVidCtlTweakerCATMathDirection &);
  CATVidCtlTweakerCATMathDirection& operator=(CATVidCtlTweakerCATMathDirection& original);
};

#endif // CATVidCtl_CATMathDirection_h
