#ifndef CATVidCtlTweakerCATMathAxis_h
#define CATVidCtlTweakerCATMathAxis_h

// COPYRIGHT Dassault Systemes 2012

// Local framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidBoxing.h>

// Mathematics framework
#include <CATMathAxis.h>

class ExportedByVisuDialogEx CATVidCtlTweakerCATMathAxis : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATMathAxis);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerCATMathAxis();

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();

  void SetOriginX(const double &i_Origin);
  double GetOriginX() const;

  void SetOriginY(const double &i_Origin);
  double GetOriginY() const;

  void SetOriginZ(const double &i_Origin);
  double GetOriginZ() const;

  void SetFirstDirectionX(const double &i_Vector);
  double GetFirstDirectionX() const;

  void SetFirstDirectionY(const double &i_Vector);
  double GetFirstDirectionY() const;

  void SetFirstDirectionZ(const double &i_Vector);
  double GetFirstDirectionZ() const;

  void SetSecondDirectionX(const double &i_Vector);
  double GetSecondDirectionX() const;

  void SetSecondDirectionY(const double &i_Vector);
  double GetSecondDirectionY() const;

  void SetSecondDirectionZ(const double &i_Vector);
  double GetSecondDirectionZ() const;

  void SetThirdDirectionX(const double &i_Vector);
  double GetThirdDirectionX() const;

  void SetThirdDirectionY(const double &i_Vector);
  double GetThirdDirectionY() const;

  void SetThirdDirectionZ(const double &i_Vector);
  double GetThirdDirectionZ() const;

protected:

  virtual ~CATVidCtlTweakerCATMathAxis();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerCATMathAxis (CATVidCtlTweakerCATMathAxis &);
  CATVidCtlTweakerCATMathAxis& operator=(CATVidCtlTweakerCATMathAxis& original);
};

#endif // CATVidCtlTweakerCATMathAxis_h
