#ifndef CATEditorManager2_h
#define CATEditorManager2_h

// COPYRIGHT DASSAULT SYSTEMES 1999


#include <CATAfrProperties.h>
#include <CATBaseUnknown.h>
#include <CATCollec.h>
#include <CATUnicodeString.h>
#include <CATListOfCATString.h>
#include "CATListOfCATUnicodeString.h"

class CATLISTV(CATBaseUnknown_var);

/**
 * @nodoc
 * Class to manage editors in Tools Options property page.
 * <b>Role</b>: All factories of objects implementing the CATIUserSettings interface
 * are defined as data extensions of the CATEditorManager2 class. 
 * @see CATIUserSettings
 */
class ExportedByCATAfrProperties CATEditorManager2 : public CATBaseUnknown
{
  CATDeclareClass;
  
public:
  /** @nodoc 
   */
  // Ruse pour autoriser la derivation de cette classe. Utilisee par CATUserSettingsManager pour la R5
  CATEditorManager2();

  /** @nodoc 
   */
  // Destructeur passe en non virtuel, pour que le destructeur de CATUserSettingsManager 
  // n'appelle pas celui de CATEditorManager2.
  // Ne fonctionne pas si dans la chaine d'heritage, une des classes a un destructeur 
  // virtuel, comme c'est le cas pour CATBaseUnknwon!!!!
  ~CATEditorManager2();

  /** @nodoc */  
  static CATEditorManager2 * GetEditorManager(CATClassId);

  /** @nodoc */  
  int  GetEditorNbr ();
  /** @nodoc */
  int  GetCurrentIndiceOfEditor();
  /** @nodoc */
  void SetCurrentIndiceOfEditor(int);

  /** @nodoc */ 
  CATBaseUnknown_var GetEditor(int);
  /** @nodoc */
  void BuildInterfacePointer(const CATString& InterfaceName, int Position);

  /** @nodoc */
  CATString GetEditorClassName(int i);
  /** @nodoc */
  CATUnicodeString GetEditorNLSTitle(int i);
  /** @nodoc */
  int* GetIndexArray() const;

private:  
  CATEditorManager2(CATClassId);
  int ScanDictionnary();
  void SortEditorTitleList();

  static CATEditorManager2 * _EditorManager;
  
  CATClassId  _type;
  //Ne pas changer _NbOfEditors en _nbOfEditors, sinon conflit avec la meme variable dans CATUserSettingsManager!!!
  int         _NbOfEditors; 
  int         _currentEditor;
  int         _nbOfBuiltEditors;

  CATListOfCATString             _editorId;
  CATListOfCATUnicodeString      _editorTitleList;
  int*                           _SortedToUnsortedIndexArray;
  CATLISTV(CATBaseUnknown_var) * _editors;
}; 
#endif
