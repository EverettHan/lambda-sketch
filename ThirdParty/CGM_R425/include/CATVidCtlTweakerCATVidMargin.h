#ifndef CATVidCtlTweakerCATVidMargin_h
#define CATVidCtlTweakerCATVidMargin_h

// COPYRIGHT Dassault Systemes 2005

// VisuImmersiveDialogEx framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidMargin.h>
#include <CATVidBoxing.h>

class ExportedByVisuDialogEx CATVidCtlTweakerCATVidMargin : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATVidMargin);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerCATVidMargin();

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();

  void SetLeftMargin(int i_leftMargin);
  int GetLeftMargin(void);

  void SetRightMargin(int i_rightMargin);
  int GetRightMargin(void);

  void SetTopMargin(int i_topMargin);
  int GetTopMargin(void);

  void SetBottomMargin(int i_bottomMargin);
  int GetBottomMargin(void);

protected:

  virtual ~CATVidCtlTweakerCATVidMargin ();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerCATVidMargin (CATVidCtlTweakerCATVidMargin &);
  CATVidCtlTweakerCATVidMargin& operator=(CATVidCtlTweakerCATVidMargin& original);
};

#endif // CATVidCtlTweakerCATVidMargin_h
