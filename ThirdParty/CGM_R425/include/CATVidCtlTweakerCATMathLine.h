#ifndef CATVidCtlTweakerCATMathLine_h
#define CATVidCtlTweakerCATMathLine_h

// COPYRIGHT Dassault Systemes 2012

// Local framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidBoxing.h>

// Mathematics framework
#include <CATMathLine.h>

class ExportedByVisuDialogEx CATVidCtlTweakerCATMathLine : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATMathLine);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerCATMathLine();

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();

  void SetOriginX(const double &i_Origin);
  double GetOriginX() const;

  void SetOriginY(const double &i_Origin);
  double GetOriginY() const;

  void SetOriginZ(const double &i_Origin);
  double GetOriginZ() const;

  void SetDirectionX(const double &i_Vector);
  double GetDirectionX() const;

  void SetDirectionY(const double &i_Vector);
  double GetDirectionY() const;

  void SetDirectionZ(const double &i_Vector);
  double GetDirectionZ() const;

protected:

  virtual ~CATVidCtlTweakerCATMathLine();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerCATMathLine (CATVidCtlTweakerCATMathLine &);
  CATVidCtlTweakerCATMathLine& operator=(CATVidCtlTweakerCATMathLine& original);
};

#endif // CATVidCtlTweakerCATMathLine_h
