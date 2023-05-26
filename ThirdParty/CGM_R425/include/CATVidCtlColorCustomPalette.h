// COPYRIGHT Dassault Systemes 2014
//===================================================================
//
// CATVidCtlColorCustomPalette.h
// Header definition of CATVidCtlColorCustomPalette
//
// This Palette type has to be enttirely filled by the customer
//
//===================================================================
#ifndef CATVidCtlColorCustomPalette_H
#define CATVidCtlColorCustomPalette_H

#include <VisuDialog.h>
#include <CATVidCtlColorStandardPalette.h>

class ExportedByVisuDialog CATVidCtlColorCustomPalette: public CATVidCtlColorStandardPalette
{
  CATDeclareClass;
public:


  CATVidCtlColorCustomPalette ();
  
  //Add a new swatch in the custom palette.
  void AddSwatch(const CATVidRGBA& iColor, const CATUnicodeString & iColorName="");
  

protected:
  virtual ~CATVidCtlColorCustomPalette ();
  CATVidCtlColorCustomPalette(CreateLetterFunc i_pCreateLetterFunc);
  
  virtual void TemplateDataUpdated();

private:
  CATVidCtlColorCustomPalette (CATVidCtlColorCustomPalette &);
  CATVidCtlColorCustomPalette& operator=(CATVidCtlColorCustomPalette&);
 
};

//-----------------------------------------------------------------------

#endif
