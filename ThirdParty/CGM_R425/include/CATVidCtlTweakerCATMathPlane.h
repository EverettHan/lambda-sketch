#ifndef CATVidCtlTweakerCATMathPlane_h
#define CATVidCtlTweakerCATMathPlane_h

// COPYRIGHT Dassault Systemes 2012

// Local framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidBoxing.h>

// Mathematics framework
#include <CATMathPlane.h>

class ExportedByVisuDialogEx CATVidCtlTweakerCATMathPlane : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATMathPlane);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerCATMathPlane();

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();

  void SetOriginX(const double &i_Origin);
  double GetOriginX() const;

  void SetOriginY(const double &i_Origin);
  double GetOriginY() const;

  void SetOriginZ(const double &i_Origin);
  double GetOriginZ() const;

  void SetNormalX(const double &i_Vector);
  double GetNormalX() const;

  void SetNormalY(const double &i_Vector);
  double GetNormalY() const;

  void SetNormalZ(const double &i_Vector);
  double GetNormalZ() const;

protected:

  virtual ~CATVidCtlTweakerCATMathPlane();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerCATMathPlane (CATVidCtlTweakerCATMathPlane &);
  CATVidCtlTweakerCATMathPlane& operator=(CATVidCtlTweakerCATMathPlane& original);
};

#endif // CATVidCtlTweakerCATMathPlane_h
