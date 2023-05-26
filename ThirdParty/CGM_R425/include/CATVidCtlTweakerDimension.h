#ifndef CATVidCtlTweakerDimension_h
#define CATVidCtlTweakerDimension_h

// COPYRIGHT Dassault Systemes 2011

#include <VisuDialogEx.h>
#include <CATVidCtlTweakerdouble.h>
#include <CATVidBoxing.h>
class CATVidValidator;

class ExportedByVisuDialogEx CATVidCtlTweakerDimension : public CATVidCtlTweakerdouble
{
  CATDeclareClass;

public:
  // Standard constructors and destructors
  CATVidCtlTweakerDimension();
protected:
  virtual ~CATVidCtlTweakerDimension();
private:
  // Copy constructor and equal operator
  CATVidCtlTweakerDimension (CATVidCtlTweakerDimension &);
  CATVidCtlTweakerDimension& operator=(CATVidCtlTweakerDimension& original);
};

#endif // CATVidCtlTweakerDimension_h
