/**

 * @fullreview DBN-CMG CVE 01:08:27
 * @error MISC Y include CATUnicodeString inutile
 * @error UDOO Y pas de constructeur par copie, d'operateur =
 * @error UDOO Y Destructeur non virtuel
*/

#ifndef CATPropertyDialog_h
#define CATPropertyDialog_h
//
//---------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES  1996               
//---------------------------------------------------------------------------
//                                                 
// CATPropertyDialog :                             
// Abstract: Class to define the properties editors
//                   
//---------------------------------------------------------------------------
// Nov. 96   Creation
//---------------------------------------------------------------------------
//
// Inheritance:  CATPropertyDialog
//                    CATFrmDialog
//                 
//---------------------------------------------------------------------------
//

#include "CATBoolean.h"
#include "CATFrmDialog.h"
#include "CATIEditProperties.h"
#include "CATListOfCATUnicodeString.h"
#include "CATLISTP_CATCmdGlobalUndo.h"
#include "CATLISTV_CATBaseUnknown.h"
//#include "CATUnicodeString.h"
#include "CATAfrProperties.h"
#include "PropertyMode.h"

class CATCommand;
class CATDlgCombo;
class CATDlgFrame;
class CATDlgLabel;
class CATDlgPushButton;
class CATDlgTabContainer;
class CATEditorManager;
class CATFrmNotify;
class CATLISTP(CATEditorContainer);
class CATNotification;
class CATPathElement;


class ExportedByCATAfrProperties CATPropertyDialog: public CATFrmDialog
{
public:
  
  CATDeclareCBEvent(PropModified);

  // style=0 => fenetre modale (fonctionnement par defaut)
  // style=1 => fenetre non modale (pour Material)
  CATPropertyDialog(CATPathElement * path=NULL, int style=0);
  virtual ~CATPropertyDialog();

  int NbrPropertyEditors();
  CATLISTP(CATCommandGlobalUndo) GetListUndoRedo() const;
  void CancelModifications();
  void CommitModifications(CATBoolean OnOK=TRUE);
  void UpdateComboBox();
  void ResetModifiedState();

  int ComparePath(CATPathElement * ipath);

  CATBoolean _istobedestroy;
  

private:
  
  // Copy constructor (not implemented)
  CATPropertyDialog(const CATPropertyDialog&);
  
  // Assignment operator (not implemented)
  CATPropertyDialog& operator=(const CATPropertyDialog&);
  
  DRECT _dialogrect;
  CATDlgCombo * _view;
  CATDlgFrame * _main_fr;
  CATDlgFrame * _more_fr;
  CATDlgLabel * _label;
  CATDlgPushButton * _bt_more;
  CATDlgTabContainer * _container;
  CATFrmNotify * _warn_select;
  CATFrmNotify * _warn_more;
  CATFrmNotify * _warn_no_more;
  
  CATPathElement * _pathElement;
  CATPathElement * _pathElementCopy;
  CATIEditProperties_var _curEditor;
  CATLISTP(CATEditorContainer) * _pages;
  CATLISTV(CATBaseUnknown_var) _selection;
  CATLISTV(CATBaseUnknown_var) _currentObjects;
  
  CATListOfCATUnicodeString _LastListOfEditors;
  
  CATLISTP(CATCommandGlobalUndo) _undo_redo;

  ModeReadWrite _mode;
  int * _sel;
  int * _sel_sub; //YAY : to save the subindice number.
  int _curPage, _curState, _MaxEditorSize ;
  int _build;
  

  void UpdateCurrentObjects(int);
  
  void SwapEditor(CATCommand*, CATNotification*, CATCommandClientData);
  void UpdateSelection(CATCommand*, CATNotification*, CATCommandClientData);
  void SetLongHelpId(CATEditorManager*);

  void PushMORE(CATCommand*, CATNotification*, CATCommandClientData);

  // Panel _warn_select
  void PushNoWarnSelect(CATCommand*, CATNotification*, CATCommandClientData);
  void PushYesWarnSelect(CATCommand*, CATNotification*, CATCommandClientData);

  // Panel _warn_no_more
  void PushOKWarnNoMore(CATCommand*, CATNotification*, CATCommandClientData);

  // Panel Resize
  void PropDResize (CATCommand *, CATNotification *, CATCommandClientData);

//  CATLISTV(CATBaseUnknown_var) GetObjectInCurrentCso();
  void UpdateSensitivity();
  void UpdateCSO(CATLISTV(CATBaseUnknown_var) objects);
  void ShowPageList();

  void SetWarnSelectPanel();
  void SetWarnMorePanel();
  void SetWarnNoMorePanel();

}; 
#endif
