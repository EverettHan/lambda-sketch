#ifndef CATVidCtlTweakerCATString_h
#define CATVidCtlTweakerCATString_h

// COPYRIGHT Dassault Systemes 2008

// VisuImmersiveDialogEx framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidBoxing.h>

// System framework
#include <CATString.h>
#include <CATUnicodeString.h>

class CATSYPEventArgs;

class ExportedByVisuDialogEx CATVidCtlTweakerCATString : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATString);

public:

  // Standard constructor
  CATVidCtlTweakerCATString();

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();

  void SetValueAsCATUnicodeString(const CATUnicodeString& i_value);
  CATUnicodeString GetValueAsCATUnicodeString() const;

  void OnTextEdited(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  void HandleEditingFinishedEvent(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

protected:

  virtual ~CATVidCtlTweakerCATString ();

private:
  
  // Copy constructor and equal operator
  CATVidCtlTweakerCATString (CATVidCtlTweakerCATString &);
  CATVidCtlTweakerCATString& operator=(CATVidCtlTweakerCATString& original);
};

#endif // CATVidCtlTweakerCATString_h
