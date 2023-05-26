#ifndef CATVidCtlTweakerCATVidColor_h
#define CATVidCtlTweakerCATVidColor_h

// COPYRIGHT Dassault Systemes 2005

// VisuImmersiveDialogEx framework
#include <VisuDialogEx.h>
#include <CATVidCtlTweaker.h>

// VisuImmersiveDialog framework
#include <CATVidBoxing.h>
#include <CATVidColor.h>

// System framework
#include <CATBoolean.h>

class ExportedByVisuDialogEx CATVidCtlTweakerCATVidColor : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATVidColor);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerCATVidColor();

  // Overriden methods
  virtual void CATSYPModifyEditedProperties();

  void SetR(int i_r);
  int GetR() const;

  void SetG(int i_g);
  int GetG() const;

  void SetB(int i_b);
  int GetB() const;

  void SetA(int i_a);
  int GetA() const;

  void SetAutoColor(int i_autoColor);
  int GetAutoColor() const;

  const CATVidColor& GetColor() const;

  CATBoolean GetAutoColorFlag() const;

  void SetColorRole(const CATUnicodeString &i_role);
  CATUnicodeString GetColorRole() const;

protected:

  virtual ~CATVidCtlTweakerCATVidColor();

  // Overriden methods
  virtual void OnValueChanged();

private:
  
  // Copy constructor and equal operator
  CATVidCtlTweakerCATVidColor(CATVidCtlTweakerCATVidColor &);
  CATVidCtlTweakerCATVidColor& operator=(CATVidCtlTweakerCATVidColor& original);

  void UpdateColor();

  // The tweaker has its own copy of the RGBA and autoColor values, since the 
  // CATVidColor class resets its own values when switching its AutoColor flag
  unsigned char _r;
  unsigned char _g;
  unsigned char _b;
  unsigned char _a;
  float _autoColor;
};

#endif // CATVidCtlTweakerCATVidColor_h
