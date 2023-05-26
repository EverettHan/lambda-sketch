#ifndef CATVidCtlTweakerCATICkeParm_h
#define CATVidCtlTweakerCATICkeParm_h

// COPYRIGHT Dassault Systemes 2008

#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>
#include <CATVidBoxing.h>
#include <CATICkeParm.h>
#include <CATBaseUnknown_var.h>

class ExportedByVisuDialogEx CATVidCtlTweakerCATICkeParm : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATICkeParm_var);

public:
  CATVidCtlTweakerCATICkeParm();

  void SetUnitToUse(const CATBaseUnknown_var& i_spUnit);
  const CATBaseUnknown_var& GetUnitToUse() const;

protected:
  virtual ~CATVidCtlTweakerCATICkeParm();
  virtual void OnValueChanged();
  void OnCkeValueChanged(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

private:
  // Copy constructor and equal operator
  CATVidCtlTweakerCATICkeParm (CATVidCtlTweakerCATICkeParm &);
  CATVidCtlTweakerCATICkeParm& operator=(CATVidCtlTweakerCATICkeParm& original);
  CATBaseUnknown_var _spUnit;
};

#endif // CATVidCtlTweakerCATICkeParm_h
