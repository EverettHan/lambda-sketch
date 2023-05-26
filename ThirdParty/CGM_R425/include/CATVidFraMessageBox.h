#ifndef CATVidFraMessageBox_h
#define CATVidFraMessageBox_h

// COPYRIGHT Dassault Systemes 2009

#include <VisuDialog.h>
#include <CATVidFraDialog.h>
#include <CATUnicodeString.h>

class CATString;

/**
 * @ingroup VIDFrame
 */
class ExportedByVisuDialog CATVidFraMessageBox: public CATVidFraDialog
{
  CATDeclareClass;
public:

  CATVidFraMessageBox();
  CATVidFraMessageBox(CATCommand *i_pParent, const CATString & i_pIdentifier);

  void SetActionIcon(CATVidFraWindow::ActionIcon i_actionIcon);
  CATVidFraWindow::ActionIcon GetActionIcon() const;

  void SetDetailedText(const CATUnicodeString& i_detailedText);
  const CATUnicodeString& GetDetailedText() const;

  /**
  * Hides or shows the detailed text.
  * By default, the ShowDetailedTextFlag property is set to FALSE.
  */
  void SetShowDetailedTextFlag(CATBoolean i_showDetailedTextFlag);
  CATBoolean GetShowDetailedTextFlag() const;

  void SetInformativeText(const CATUnicodeString& i_informativeText);
  const CATUnicodeString& GetInformativeText() const;

  void SetText(const CATUnicodeString& i_text);
  const CATUnicodeString& GetText() const;

  CATBoolean GetUseDetailedTextFlag();

protected:
  virtual ~CATVidFraMessageBox ();
  virtual void Build();

private:

  CATUnicodeString _detailedText;
  CATUnicodeString _text;
  CATUnicodeString _informativeText;
  CATVidFraWindow::ActionIcon _actionIcon;
  unsigned int _showDetailedTextFlag;
};

#endif // CATVidFraMessageBox_h
