#ifndef CATDLGDIRECTORYCONCATENATION_H
#define CATDLGDIRECTORYCONCATENATION_H
// COPYRIGHT DASSAULT SYSTEMES 2011

//------------------------------------------------------------------------------
// Abstract: Class for creating a directory concatenation
//------------------------------------------------------------------------------

#include "CATDlgStandard.h"
#include "CATDlgDialog.h"
#include "CATListOfCATUnicodeString.h"
#include "CATBoolean.h"

//include System
class CATCommand;
class CATNotification;
class CATString;

//include Dialog
class CATDialog;
class CATDlgSelectorList;
class CATDlgCheckButton;
class CATDlgPushButton;

/**
 * Class delivering a file or folder selection box, permitting the creation 
 * of a concatenated path.
 */
class ExportedByCATDlgStandard CATDlgDirectoryConcatenation : public CATDlgDialog
{
  CATDeclareClass;

public:

  // NCT - Jan 2016 - Third parameter is useless, and only for compatibility with CATDlgStdFileConcatenation
  // It will be removed as soon as CATSbuDocumentationSettingsFrame has been modified
  CATDlgDirectoryConcatenation(CATDialog *iParent, const CATString& iDialogObjectName, CATDlgStyle iStyle = 0);

  virtual ~CATDlgDirectoryConcatenation();

  /**
   * Sets the concatenated path
   */
  void SetConcatenatedPath(const CATUnicodeString& iConcatenatedPath);

  /**
   * Retrieves the concatenated path
   */
  void GetConcatenatedPath(CATUnicodeString& oConcatenatedPath);

private:
  CATDlgDirectoryConcatenation(const CATDlgDirectoryConcatenation&);
  CATDlgDirectoryConcatenation& operator = (const CATDlgDirectoryConcatenation&);

  HRESULT RefreshConcatenation();

  void AddCB(CATCommand*, CATNotification*, CATCommandClientData);
  void SelectionUpCB(CATCommand*, CATNotification*, CATCommandClientData);
  void SelectionDownCB(CATCommand*, CATNotification*, CATCommandClientData);
  void SelectionDeleteCB(CATCommand*, CATNotification*, CATCommandClientData);
  void SelectionChangedCB(CATCommand*, CATNotification*, CATCommandClientData);

  CATDlgSelectorList *_PathList;
  CATUnicodeString   _ConcatenatedPath;

  CATDlgCheckButton* _AddButton;
  CATDlgPushButton* _UpButton;
  CATDlgPushButton* _DownButton;
  CATDlgPushButton* _DeleteButton;

};
#endif
