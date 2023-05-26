#ifndef CATVidCtlTweakerCATVidLayGridWeight_h
#define CATVidCtlTweakerCATVidLayGridWeight_h

// COPYRIGHT Dassault Systemes 2005

// VisuImmersiveDialogEx framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidLayGridWeight.h>
#include <CATVidBoxing.h>

class CATSYPEventArgs;

class ExportedByVisuDialogEx CATVidCtlTweakerCATVidLayGridWeight : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATVidLayGridWeight);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerCATVidLayGridWeight();

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();

  void SetValueAsString(const CATUnicodeString& i_value);
  CATUnicodeString GetValueAsString();

  void HandleEditingFinishedEvent(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

protected:

  virtual ~CATVidCtlTweakerCATVidLayGridWeight();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerCATVidLayGridWeight (CATVidCtlTweakerCATVidLayGridWeight &);
  CATVidCtlTweakerCATVidLayGridWeight& operator=(CATVidCtlTweakerCATVidLayGridWeight& original);
};

#endif // CATVidCtlTweakerCATVidLayGridWeight_h
