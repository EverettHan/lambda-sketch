#ifndef CATUserSettingsManager_h
#define CATUserSettingsManager_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATCommand.h"

#include "CATAfrProperties.h"
//#include "CATBaseUnknown.h"
#include "CATCollec.h"
#include "CATUnicodeString.h"
#include "CATListOfCATString.h"
#include "CATListOfCATUnicodeString.h"
//#include "CATEditorManager2.h" //Test de mise en place de l'heritage pour CAA

class CATLISTV(CATBaseUnknown_var);
class CATNotification;
class CATUserSettingsDialog; //pour le changement dynamique de licences
class CATSysSettingRepository;
/**
 * @nodoc
 * Class to manage editors in Tools Options property page.
 * <b>Role</b>: All factories of objects implementing the CATIUserSettings interface
 * are defined as data extensions of the CATUserSettingsManager class. 
 * @see CATIUserSettings
 */
class ExportedByCATAfrProperties CATUserSettingsManager : public CATCommand//CATBaseUnknown
{
  CATDeclareClass;
  friend class CATUserSettingsDialog; //pour le changement dynamique de licences

public:
  /** @nodoc */
  ~CATUserSettingsManager();

  /** @nodoc */  
  static CATUserSettingsManager * GetEditorManager(CATClassId);

  /** @nodoc */ 
  CATBaseUnknown_var GetEditor(int solutionNb, int workbenchNb, int position);

  /** @nodoc */ 
  CATString GetEditorName(int solutionNb, int workbenchNb, int position);

  /** @nodoc */ 
  HRESULT GetEditorLongHelpId(const CATString& iImplClassName,
                              CATString& oLongHelpId);

  /** @nodoc */ 
  HRESULT GetEditorParametersFromName(const CATString& iImplClassName,
                                      int& oSolutionNb, int& oWorkbenchNb, int& oPosition);

  /** @nodoc */
  HRESULT GetEditorFromLongHelpId(const CATString& iLongHelpId,
                                  CATBaseUnknown_var& oPtrToEditor);

  /** @nodoc */
  CATBaseUnknown_var BuildInterfacePointer(const CATString& InterfaceName);

  /** @nodoc */
  CATLISTV(CATBaseUnknown_var) GetListOfBuiltEditors(const int solutionNb, 
                                                     const int workbenchNb);

  /** @nodoc */
  CATLISTV(CATBaseUnknown_var) GetListOfEditors(const int solutionNb, 
                                                const int workbenchNb);
  /** @nodoc */
  static int ReadDumpMode ();

  /** @nodoc */  
  int  GetNbOfEditors () const;
  int  GetNbOfSolutions();
  int* GetNbOfWorkbenches();
  const CATListOfCATString&  GetSolutionsList();
  CATListOfCATString* GetWorkbenchesList();
  CATListOfCATString* GetEditorsBySolution();
  CATListOfCATString** GetEditorsByWorkbench();
  const CATListOfCATString& GetEditorsList(int solutionNb, int workbenchNb);
  const CATListOfCATUnicodeString& GetEditorsTitlesList(int solutionNb, int workbenchNb);

  const CATListOfCATString& GetExtraInfrastructureWorkbenches();
  const CATListOfCATString& GetExtraMechanicalDesignWorkbenches();
  HRESULT DumpSettings(char** iPrefItemList, int nbItems, CATListOfCATUnicodeString& iRepoNameList, CATUnicodeString& iPageName);

private:  
  CATUserSettingsManager(CATClassId);
  CATUserSettingsManager(const CATUserSettingsManager& Original); //pas d'implémentation
  CATUserSettingsManager& operator = (const CATUserSettingsManager&); //pas d'implémentation
  void ScanDictionaries();

  /** @nodoc */
  void DeleteLists();

  HRESULT DumpSettings(const CATLISTV(CATBaseUnknown_var)& iListOfPointers,
		       CATUnicodeString *iDir=0, CATUnicodeString * iCSVDir=NULL, bool iGenerateCSVInTemp = false);

  static int DestroyManager(int);
  void ReleaseEditorsLists();
  HRESULT DestroyAndRebuildLists();
  static void OnIdle(CATCommand * ToClient, int state, CATCommand * ClientData);
  
  CATBoolean GeneralTest(const CATString& iCatalogName);
  CATBoolean TestOnPxLook (const CATString& iCatalogName);
  CATBoolean TestOnProduct(const CATString& iCatalogName);
  CATBoolean TestOnEnvVariable(const CATString& iCatalogName);
  CATBoolean TestOnFwLevel(const CATString& iCatalogName);
//  int TestOnVersion(const CATString iCatalogName);

  void LicenceChanged(CATCallbackEvent iEvent, void *, CATNotification *iNotification,
      CATSubscriberData iData, CATCallback iCbId);

  static CATUserSettingsManager * _EditorManager;
  
  // Nom de l'interface a laquelle adherent les editeurs des onglets
  CATClassId  _Type;

  // Nombre de classe d'implementation de l'interface
  int         _nbOfEditors;

  // La liste des Solutions ne comporte que ceux ayant un onglet ou un etabli 
  // ayant un onglet. 
  // Pour chaque Solution, les noms des classes d'implementation de l'interface, 
  // le pointeur sur l'implementation, les titres des onglets correspondants, 
  // sont conserves.
  int                            _nbOfSolutions;
  CATListOfCATString             _SolutionsList;
  CATListOfCATString            *_EditorsBySolution;
  CATListOfCATString            *_LongHelpIdBySolution;
  CATListOfCATUnicodeString     *_EditorsTitlesBySolution;
  CATLISTV(CATBaseUnknown_var)  *_EditorsPointersBySolution;

  // La liste des Etablis (indexee sur les Solutions tels que definis plus haut)
  // ne comporte que ceux ayant un onglet.
  // Pour chaque Etabli, les noms des classes d'implementation de l'interface, 
  // le pointeur sur l'implementation, les titres des onglets correspondants, 
  // sont conserves.
  int                           *_nbOfWorkbenches;
  CATListOfCATString            *_WorkbenchesList;
  CATListOfCATString           **_EditorsByWorkbench;
  CATListOfCATString           **_LongHelpIdByWorkbench;
  CATListOfCATUnicodeString    **_EditorsTitlesByWorkbench;
  CATLISTV(CATBaseUnknown_var) **_EditorsPointersByWorkbench;

  // Liste des établis supplémentaires s'insérant dans la solution
  // Infrastructure (en dernière position).
  CATListOfCATString  _ExtraInfrastructureWorkbenches;
  CATListOfCATString  _ExtraMechanicalDesignWorkbenches;

  CATListOfCATString  _EditorsId;
  //CATListOfCATString  _OldEditorsId;
  int                 _currentLook;//pour gérer les apparences P1, P2, Px
  CATBoolean _ODTEnvironment;
}; 
#endif
