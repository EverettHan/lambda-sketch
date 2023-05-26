#ifndef CATVidCtlTweakerCATVidHyperlink_h
#define CATVidCtlTweakerCATVidHyperlink_h

// COPYRIGHT Dassault Systemes 2008

#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>
#include <CATVidBoxing.h>
#include <CATVidHyperlink.h>

class CATSYPEventArgs;

class ExportedByVisuDialogEx CATVidCtlTweakerCATVidHyperlink : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATVidHyperlink);

public:
  // Standard constructors and destructors
  CATVidCtlTweakerCATVidHyperlink();
  void OnTextEdited(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  void HandleEditingFinishedEvent(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();

  void SetURL(const CATUnicodeString& i_url);
  CATUnicodeString GetURL() const;
  void SetTooltip(const CATUnicodeString& i_url);
  const CATUnicodeString& GetTooltip() const;
  void SetVisitedFlag(int i_visitedFlag);
  int GetVisitedFlag() const;

protected:
  virtual ~CATVidCtlTweakerCATVidHyperlink();
private:
  // Copy constructor and equal operator
  CATVidCtlTweakerCATVidHyperlink (CATVidCtlTweakerCATVidHyperlink &);
  CATVidCtlTweakerCATVidHyperlink& operator=(CATVidCtlTweakerCATVidHyperlink& original);
  friend class CATVidCtlTweakerCATVidHyperlinkSYPIntro;
};

#endif // CATVidCtlTweakerCATVidHyperlink_h
