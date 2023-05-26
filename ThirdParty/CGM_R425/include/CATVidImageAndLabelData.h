// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATVidImageAndLabelData.h
// Header definition of CATVidImageAndLabelData
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  2008  Creation: jov
//===================================================================
#ifndef CATVidImageAndLabelData_H
#define CATVidImageAndLabelData_H

#include <CATBaseUnknown.h>
#include <VisuDialog.h>
#include <CATBoolean.h>
#include <CATUnicodeString.h>
#include <CATVidEnum.h>
#include <CATDlgUtility.h>

class CATVidGPSquare;
class CATVidGPLabel;
class CATString;
class CATPixelImage;
class CATVidCtlEditor;

//-----------------------------------------------------------------------
class ExportedByVisuDialog CATVidImageAndLabelData: public CATBaseUnknown
{
  CATDeclareClass;

public:

  // Standard constructors and destructors
  // -------------------------------------
  CATVidImageAndLabelData ();

  void SetResourceImage(const CATUnicodeString& i_image);
  const CATUnicodeString& GetResourceImage() const;

  void SetImage(CATPixelImage* i_spImage);
  CATPixelImage* GetImage() const;

  void SetLabel(const CATUnicodeString& i_label);
  const CATUnicodeString& GetLabel() const;

  void SetTooltipTitle(const CATUnicodeString& i_tooltipTitle);
  const CATUnicodeString& GetTooltipTitle() const;

  void SetTooltipShortHelp(const CATUnicodeString& i_tooltipShortHelp);
  const CATUnicodeString& GetTooltipShortHelp() const;

  void SetTooltipLongHelp(const CATUnicodeString& i_tooltipLongHelp);
	const CATUnicodeString& GetTooltipLongHelp() const;

	void SetShortTooltipTemplateName(const CATUnicodeString& i_ShortTooltipTemplateName);
	const CATUnicodeString& GetShortTooltipTemplateName() const;

	void SetShortTooltipStyleSheet(const CATUnicodeString& i_ShortTooltipStyleSheet);
	const CATUnicodeString& GetShortTooltipStyleSheet() const;

	void SetLongTooltipTemplateName(const CATUnicodeString& i_LongTooltipTemplateName);
	const CATUnicodeString& GetLongTooltipTemplateName() const;

	void SetLongTooltipStyleSheet(const CATUnicodeString& i_LongTooltipStyleSheet);
	const CATUnicodeString& GetLongTooltipStyleSheet() const;							

  CATString & GetName();

  void  SetName(CATString & iIdentifier);

  //CATISYPResource implementation.
  char* GetResourceFilename(int i_depth) const;

  CATString& GetResourceID();

  int GetUseIconFlag() const;

protected:

  virtual ~CATVidImageAndLabelData ();

private:  

  // Copy constructor and equal operator
  // -----------------------------------
  CATVidImageAndLabelData (CATVidImageAndLabelData &);
  CATVidImageAndLabelData& operator=(CATVidImageAndLabelData& original);

  CATUnicodeString _label;
  CATUnicodeString _resourceImage;
  CATPixelImage * _pImage;
  CATUnicodeString _tooltipTitle;
  CATUnicodeString _tooltipShortHelp;
  CATUnicodeString _tooltipLongHelp;
	CATUnicodeString _shortTooltipTemplateName;
	CATUnicodeString _shortTooltipStyleSheet;
	CATUnicodeString _longTooltipTemplateName;
	CATUnicodeString _longTooltipStyleSheet;
  CATString _name;
};

#endif
