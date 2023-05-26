#ifndef CATWorkbenchServices_h
#define CATWorkbenchServices_h
//
///////////////////////////////////////////////////////////////////////////////
// COPYRIGHT DASSAULT SYSTEMES  2000                                         //
// ========================================================================= //
//                                                                           //
// CATWorkbenchServices :                                                    //
// Resume : Classe pour avoir acces aux resultats de la classe CATWorkbench  //
//          sans en modifier la valeur                                       //
// ========================================================================= //
// Creation : Mai 2000 par Johann CHEMIN (jac)                               //
///////////////////////////////////////////////////////////////////////////////
//
// Heritage :  CATWorkbenchServices
//                    
//                 
//-----------------------------------------------------------------------------
//
#include "CATAfrFoundation.h"

class CATString;
#include "CATListOfCATString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATCreateEnvironmentWorkshop.h"

class CATLISTP(CATWorkbench);

class ExportedByCATAfrFoundation CATWorkbenchServices
{
public:
  
  static void GetWorkbenches(CATListOfCATUnicodeString & titles, CATListOfCATUnicodeString & names);
  static CATListOfCATString        *  GetMarketList();
  static CATListOfCATUnicodeString *  GetMarketTitleList();
  static CATListOfCATString        *  GetMarketIconList();
  static CATListOfCATString        ** GetMarketAndWorkbenches();
  static void GetWorkbenchesForSubmarket(const CATString &,
    CATListOfCATString *& oWbNames, CATListOfCATUnicodeString *& oWbTitles, CATListOfCATString *& oWbIcons);

  static int GetWorkbenchTitleAndIconName(const CATString & iName,
                                          CATUnicodeString& oTitle, CATString& oIconName);

  static void DoTransition(const CATString & FromWorkshop, 
	  const CATString & FromWorkbench, 
	  const CATString & ToWorkshop,
	  const CATString & ToWorkbench);

  // Tells whether iWsName corresponds to an existing workshop identifier.
  static CATBoolean IsAWorkshop (CATString & iWsName);

  // Changes the preferred workbench for a workshop.
  // This changes the user preference so that the next time the user will enter the workshop
  // this workbench will be chosen.
  // No check is made that the names correspond to actual workshop and workbench.
  static void SetWorkshopPreferredWorkbench (CATString & iWsName, CATString & iWbName);

  // Retrieves the preferred workbench for a workshop.
  // It reads the user preference, returning the next workbench to be launched
  // the next time the user will enter the workshop.
  // No check is made that the names correspond to actual workshop and workbench.
  static void GetWorkshopPreferredWorkbench (CATString & iWsName, CATString & oWbName);

  // Check if the workbench supports the workshop. Works only with a multi-workshop workbench. It is based on its CATRsc definition .MultiWorkshop
  static CATBoolean IsWorkshopSupportedByWorkbenchMultiWs(CATString & iWbName, CATString & iWsName);

  /**
   * Tell whether the current interaction is a selection or an edition.
   * @note Only useful when called on selection filtering (CATICustomFilteredSelection implementation)
   * Returns 0 if no interaction is current.
   * Returns 1 if a selection is current.
   * Returns 2 if an edition is current.
   */
  static int CATAfrGetSelectionModeForFilter();

private:
  CATWorkbenchServices();
  virtual ~CATWorkbenchServices();
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATWorkbenchServices (const CATWorkbenchServices &);
  CATWorkbenchServices & operator= (const CATWorkbenchServices &);

  static int _SelectionModeForFilter;
  friend class CATNoCustomFilterAgent;
  friend class CATSelectObjectAgent;
  friend class CATWorkbenchServices_UT;
  static void CATAfrSetSelectionModeForFilter(int iMode);
};
#endif

