#ifndef CATVidCtlTweakerCATUnicodeString_h
#define CATVidCtlTweakerCATUnicodeString_h

// COPYRIGHT Dassault Systemes 2008

#include <VisuDialogEx.h>
#include <CATVid.h>
#include <CATVidCtlTweaker.h>
#include <CATVidBoxing.h>

class CATSYPEventArgs;
class CATUnicodeString;

class ExportedByVisuDialogEx CATVidCtlTweakerCATUnicodeString : public CATVidCtlTweaker
{
  CATDeclareTweaker(CATUnicodeString);

public:

  // Standard constructors and destructors
  CATVidCtlTweakerCATUnicodeString();

  // Overriden methods
  virtual void InternalSetData();

  void SetCropPolicy(CATVid::CropPolicy i_cropPolicy);
  CATVid::CropPolicy GetCropPolicy() const;

  void SetIncludeStrokeFontsFlag(int i_includeStrokeFonts);
  int GetIncludeStrokeFontsFlag() const;

protected:

  virtual ~CATVidCtlTweakerCATUnicodeString();
  void CATSYPModifyEditedProperties();

private:

  // Copy constructor and equal operator
  CATVidCtlTweakerCATUnicodeString (CATVidCtlTweakerCATUnicodeString &);
  CATVidCtlTweakerCATUnicodeString& operator=(CATVidCtlTweakerCATUnicodeString& original);

  HRESULT _BuildListComboFonts( const CATUnicodeString& i_tweakerData );

		/**
		 * Comparison function for CATListOfCATUnicodeString::QuickSort
		 */
		static int _CompareString(
			CATUnicodeString* iString1,
			CATUnicodeString* iString2);

    unsigned int _cropPolicy        :2;
    unsigned int _includeStrokeFonts:29;

  friend class CATVidCtlTweakerCATUnicodeStringSYPIntro;
};

#endif // CATVidCtlTweakerCATUnicodeString_h
