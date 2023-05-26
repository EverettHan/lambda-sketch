// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATDocLocatorManager_h_
#define CATDocLocatorManager_h_

// Objet qui gere l'ensemble des doclocators en vue de resoudre les liens

/**
* @level Private
* @usage U1
*/

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "booleanDef.h"
#include "CATListOfCATUnicodeString.h"
#include "CATString.h"
#include "CATIDocEnvironment.h"
class CATRawCollint;
class CATIDocId;
class CATIDocDescriptor;
class CATIDocLocator;
class CATDocument;
class CATSettingRepository;
class V5OmbSession ;

class ExportedByAC0XXLNK CATDocLocatorManager : public CATBaseUnknown 
{
  CATDeclareClass;
friend class CATOmbServicesForFBDI;
friend class FBDIServices;

private:
  CATDocLocatorManager();
  virtual ~CATDocLocatorManager();

  CATDocLocatorManager( const CATDocLocatorManager& );	// not implemented
  CATDocLocatorManager& operator=( const CATDocLocatorManager& );	// not implemented

public:


  /** 
  * Return locators activation status
  *
  * <br><b>Role</b>: This method returns a list containing all the locators known for every environment 
  * we know in CATIA. It also returns a list that states wether a locator is active or not. 
  * This method does not provide any side effect.Locators initialized here won't be used in the retrieve method
  * A locator activation set is given as follow Locator result[i] is activated if activated[i] is 1
  * @param result [inout]
  *   List of Locators
  * @param activated [inout]
  *   List of integer
  *
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise...
  *
  */
  HRESULT GetResolutionLocators( CATListValCATBaseUnknown_var& result, CATRawCollint& activated );

  // Changement des locators ( position et activation )
  HRESULT ChangeLocators ( const CATRawCollint& order, const CATRawCollint& activated );

  // Recuperation du manager pour la session
  static CATDocLocatorManager* GetDocLocatorManager();

  // Destruction du locator manager
  static void DeleteDocLocatorManager();

  // Methode de resolution du lien
  HRESULT Retrieve (CATIDocId* iDocId, CATIDocDescriptor ** oDocDescriptor, CATIDocId* iPointingDocId = NULL, CATListValCATUnicodeString* parameters=0);

  // Configuration potentielle
  int IsConfigurable( int pos );

  // les 4 Methodes ci dessous permettent la gestion des settings dans Tools\Option
  // After user's Settings
  HRESULT SetUserSettingsValue ( const CATRawCollint& order, const CATRawCollint& activated); 	            


  /**
  * @author BES
  * METHOD HRESULT ResetUserSettingsValue ()
  *
  * <br><b>Role</b>: THis method sets the locator to their default states:
  * Default State is decided as follow :
  *
  * For users : 
  * ---------------------------------------------------------------
  * | User Setting    | Admin Setings | After Pushing Reset       |
  * ---------------------------------------------------------------
  * |     no          |       no      | sets to _default_locator  |
  * ---------------------------------------------------------------
  * |     no          |       yes     | sets to admin value       |
  * ---------------------------------------------------------------
  * |     yes         |       yes     | sets to admin value       |
  * ---------------------------------------------------------------
  * |     yes         |       no      | sets to _default_locator  |
  * ---------------------------------------------------------------
  *
  * For admin :
  * reset to _default_locator
  *
  * @return
  *   <code>
  *     S_OK : Settings has been reset
  *     S_FALSE : current settings are the same. No need to reset
  *     E_FAIL : unexpected error
  *   </code>
  *	
  */
  HRESULT ResetUserSettingsValue ();

  //After pushing CANCEL
  HRESULT CancelModification ();

  //After pushing OK
  HRESULT CommitModification ();	
  /**
  * @author BES
  * This method returns the locator that are activated by default (when CATIA is launched with no settings)
  * Previously all locators were activated
  * Since R14 : Only theses locators are activated
  * New locators will not be used unless CATIA is told to do so. 
  */
  static const char* GetDefaultLocator();
  /*
  * @author BES
  * This method reads the settings about the locator. 
  * It is better to use this method than to read directly in the SymboliLinks.CATSettings file
  * Here we take into acount that some old catsetting may not have information for all locators. 
  * All locators that have no infomration are considered as inactive. (different from past behavior)
  * However, we ensure that some locators are considered as active even if there is no information. 
  *
  * Settings read : 
  *
  *
  * For users : 
  * ---------------------------------------------------------------
  * | User Setting    | Admin Setings | After Pushing Reset       |
  * ---------------------------------------------------------------
  * |     no          |       no      | reads _default_locator    |
  * ---------------------------------------------------------------
  * |     no          |       yes     | reads admin values        |
  * ---------------------------------------------------------------
  * |     yes         |       yes     | reads user values         |
  * ---------------------------------------------------------------
  * |     yes         |       no      | reads user values         |
  * ---------------------------------------------------------------
  * |     yes         |  yes (locked) | reads admin values        |
  * ---------------------------------------------------------------
  *
  * @return
  *      The catstring that contains the settings
  */  
  static const CATString ReadSetting();

private:

  int AddLocatorsForEnv(const CATIDocEnvironment_var& iEnvironment);

  static CATDocLocatorManager*  _session_manager;

  CATListValCATBaseUnknown_var* _liste_locators; /*locators active in the current session*/
  CATRawCollint*		      _activated;

  CATListValCATBaseUnknown_var* _liste_locators_for_display; /*if goes to option->document, we must create all locators. But we cannot had them to the current session list, otherwise it would change the session behavior*/
  CATRawCollint*		      _activated_for_display;

  CATString                     _settings;
  CATListOfCATUnicodeString     _treatedEnvironments;    
  unsigned char                 _everyEnvTreated;
  static const char* _default_locator;

  void AddResolutionHit(V5OmbSession* iSession,CATIDocId* iDocId, CATIDocId * iPointingDocId, CATListValCATUnicodeString* parameters ) ;
  HRESULT isCacheableLocator(const char* iLocatorIdentifier) ;
  HRESULT RegisterInCache(CATIDocId* iDocId, CATIDocDescriptor ** oDocDescriptor,HRESULT ResultOfRetrieve,const char* iTypeOfLocator,V5OmbSession* iSession) ;
  HRESULT RetrieveInCache(CATIDocId* iDocId, CATIDocDescriptor ** oDocDescriptor,const char* iTypeOfLocator,V5OmbSession* iSession) ;

  /**
  * @author BHG
  * This method scan the first argument formatted as "loc1:0;loc2:1;loc3:0;...locX:1;" and set the second one to "loc1" 
  * and the third to 0 . The return value is the rest of the CATString "loc2:1;loc3:0;...locX:1;" or NULL if no locatorId 
  * and Activated status has been found.
  * @param ioSettings The original string of settings formatted as "loc1:0;loc2:1;loc3:0;...locX:1;". After the call of the method ioSettings, will contain "loc2:1;loc3:0;...locX:1;
  * @param oLocatorId The first locatorId (here "loc1")
  * @param oActivated The status of the locatorId (here "0")
  */
  static HRESULT GetFirstLocatorFromStr(CATUnicodeString& ioSettings, CATUnicodeString& oLocatorId, CATUnicodeString& oActivated);
  /**
  * @author BHG
  * This method sort locators stored in the _liste_locators and _activated list using the order
  * of the setting string given in argument
  * @param isettings The string model to sort _liste_locators and _activated list. Formatted as (locIsA1:{0,1};[locIsA2:{0,1};]*")
  * @return S_OK
  */
  HRESULT SortLocatorList(const CATUnicodeString& isettings);
};

#endif
