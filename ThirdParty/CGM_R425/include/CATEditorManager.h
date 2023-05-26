/**
 * @fullreview DBN-CMG CVE 01:09:03
 * @error MISC Y manque include CATBaseUnknown_var
 * @error MISC Y include CATUnicodeString inutile
 * @error UDOO Y pas de constructeur par copie, d'operateur =
 * @error UDOO Y destructeur non virtuel
 */

/**
 *  @quickReview CMG-ERS 02:02:19
 *  @quickReview CMG-JAC 02:05:03
 */

#ifndef CATEditorManager_h
#define CATEditorManager_h

// COPYRIGHT DASSAULT SYSTEMES 2000


//---------------------------------------------------------------------------
// CATEditorManager :
// 
// Abstract: Class to define a the manage the editors creation
//---------------------------------------------------------------------------
// Nov. 96   Creation                                     O. BAUDE
//---------------------------------------------------------------------------
//
// Inheritance:  CATEditorManager
//                   CATImplementationAdapter
//                 
//---------------------------------------------------------------------------
// Main methods:
//
//            GetEditorManager
//            GetEditorNumber
//            AddEditor
//            GetEditor 
//            GetCurrentIndiceOfEditor
//            SetCurrentIndiceOfEditor 
//---------------------------------------------------------------------------


#include "CATBaseUnknown_var.h"
#include "CATEventSubscriberTypedefs.h"
#include "CATImplementationAdapter.h"

//#include "CATIProgressTaskUI.h"
#include "CATListOfCATString.h"
#include "CATAfrProperties.h"

class CATLISTV(CATBaseUnknown_var);
class CATNotification;
class CATPathElement;
class CATIProgressTaskUI;


class ExportedByCATAfrProperties CATEditorManager: public CATImplementationAdapter
{
  CATDeclareKindOf;
  
public:
  
  static CATEditorManager * GetEditorManager(CATPathElement * path=NULL, 
                                             HRESULT * hr=NULL);
  static int GetMode();
  static void ChangeMode();
  static void SetLightMode();
  static void SetNormalMode();
  static void UnsetNormalMode();
  static int IsLightModeActive();
  
  virtual ~CATEditorManager();
  
  void AddEditor(const CATBaseUnknown_var &);
  CATLISTV(CATBaseUnknown_var) GetSelectedObjects();
  int GetEditorNbr();
  CATListOfCATString GetMainEditors();
  CATBaseUnknown_var GetEditor(int);
  int GetCurrentIndiceOfEditor();
  int GetCurrentSubIndiceOfEditor();
  void SetCurrentIndiceOfEditor(int); 
  void SetCurrentSubIndiceOfEditor(int); 
  HRESULT ScanDictionary(CATIProgressTaskUI*);
  
  // PHB : Clean the list of path elements kept from selection
  static void CleanSelection();
  

private:

  // Copy constructor (not implemented)
  CATEditorManager(const CATEditorManager&);
  
  // Assignment operator (not implemented)
  CATEditorManager& operator=(const CATEditorManager&);
  
  static CATEditorManager * _EditorManager;
  static int DestroyManager(int);

  // Variable statique pour savoir dans quel mode d'Edit/Prop. on se trouve
  // Quatre valeurs possibles :
  // 0 -> Mode light 1er passage
  // 1 -> Mode normal 1er passage
  // 2 -> Mode light 2eme passage et suivants
  // 3 -> Mode normal 2eme passage et suivants
  static int _Mode;

  // Indice du dernier onglet visualise
  int _Indice;
  int _SubIndice;  //YAY : to save the currect subeditor number.
  
  CATEditorManager();

  CATLISTV(CATBaseUnknown_var) _selection;
  CATLISTV(CATBaseUnknown_var) * _editors;
  CATListOfCATString * _LoadedEditors;
  CATListOfCATString _MainEditors;

//  int ScanDictionary();
  HRESULT UpdateManager(CATPathElement * path);

  void LicenceHasChanged(CATCallbackEvent, void*, CATNotification*,
                         CATSubscriberData, CATCallback);
}; 
#endif
