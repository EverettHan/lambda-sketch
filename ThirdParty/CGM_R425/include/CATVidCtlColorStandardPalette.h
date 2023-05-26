// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidCtlColorStandardPalette.h
// Header definition of CATVidCtlColorStandardPalette
//
//===================================================================
#ifndef CATVidCtlColorStandardPalette_H
#define CATVidCtlColorStandardPalette_H

#include <VisuDialog.h>
#include <CATVidCtlColorPalette.h>

class ExportedByVisuDialog CATVidCtlColorStandardPalette: public CATVidCtlColorPalette
{
  CATDeclareClass;
public:
  
  enum PaletteType{
    NoPalette = 0,
    CATIAStandardColors,
    SimpleColors,
    WebColors,
    CustomColors,
    CustomizablePalette
  };

  CATVidCtlColorStandardPalette ();

  void SetPaletteType(const CATVidCtlColorStandardPalette::PaletteType& i_paletteType);
  const CATVidCtlColorStandardPalette::PaletteType& GetPaletteType() const;
  
  CATUnicodeString GetCustomColorsSettingsFile()const;
  void SetCustomColorsSettingsFile(CATUnicodeString iCustomColorsSettingsFile);

  int GetCustomColorsNumber()const;
  void SetCustomColorsNumber(int iCustomColorNumber);

	/**
	* Return the maximum custom colors visible rows number. If number of rows of the custom colors are greater than this number, a scrollbar will be displayed.
	*/
	int GetMaxCustomColorsVisibleRowsNumber()const;

	/**
	* Get the maximum custom colors visible rows number.
	*/
	void SetMaxCustomColorsVisibleRowsNumber(const int & i_maxCustomColorsVisibleRowsNumber);

protected:
  virtual ~CATVidCtlColorStandardPalette ();
  CATVidCtlColorStandardPalette(CreateLetterFunc i_pCreateLetterFunc);
  
  virtual void TemplateDataUpdated();

private:
  CATVidCtlColorStandardPalette (CATVidCtlColorStandardPalette &);
  CATVidCtlColorStandardPalette& operator=(CATVidCtlColorStandardPalette&);

  CATUnicodeString _customColorsSettingsFile;
  int _customColorsNumber;
	int _maxCustomColorsVisibleRowsNumber;

  friend class l_CATVidCtlColorStandardPalette;
};
CATSYP_DECLARE_ENUMFACTORY(ExportedByVisuDialog, CATVidCtlColorStandardPalette__PaletteType);

//-----------------------------------------------------------------------

#endif
