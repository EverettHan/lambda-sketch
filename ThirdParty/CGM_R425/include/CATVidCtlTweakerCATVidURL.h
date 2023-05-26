#ifndef CATVidCtlTweakerCATVidURL_h
#define CATVidCtlTweakerCATVidURL_h

// COPYRIGHT Dassault Systemes 2008

#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>
#include <CATVidBoxing.h>

class CATSYPEventArgs;

class ExportedByVisuDialogEx CATVidCtlTweakerCATVidURL : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATVidURL);
public:
  // Standard constructors and destructors
  CATVidCtlTweakerCATVidURL();
  void OnTextEdited(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  void HandleEditingFinishedEvent(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
protected:
  virtual ~CATVidCtlTweakerCATVidURL();
private:
  // Copy constructor and equal operator
  CATVidCtlTweakerCATVidURL (CATVidCtlTweakerCATVidURL &);
  CATVidCtlTweakerCATVidURL& operator=(CATVidCtlTweakerCATVidURL& original);
  friend class CATVidCtlTweakerCATVidURLSYPIntro;
};

#endif // CATVidCtlTweakerCATVidURL_h
