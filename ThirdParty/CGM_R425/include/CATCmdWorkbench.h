#ifndef CATCmdWorkbench_H
#define CATCmdWorkbench_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include <CATAfrFoundation.h>
#include <CATCmdContainer.h>
#include <CATListPV.h>
#include <CATListOfCATString.h>
#include <CATString.h>
#include <CATUnicodeString.h>
#include <CATBoolean.h>

class CATCmdWorkbenchLoader;
class CATCmdWorkshop;
class CATDialog;
#ifdef AfrCAA2
class CATAfrGen;
#endif

/**
 * Class to create the workbench's access .
 * <b>Role</b>: The workbench's access is a @href CATCmdContainer which contains containers:
 * one for it's menubar and one for each toolbar.<br>
 * To create an instance of <tt>CATCmdWorkbench</tt> use the macro @href NewAccess 
 * with <tt>CATCmdWorkbench</tt> as <tt>classname</tt> parameter. 
 * @see CATIWorkbench 
 */
class ExportedByCATAfrFoundation CATCmdWorkbench : public CATCmdContainer
{
  friend class CATMarshallableCmdWorkbench;
  
  CATDeclareKindOf;
  
public:

	/**
	* Defines the button representation in the toolbars.
	* @param Icons
	*  Each button in all toolbars of the workbench are represented by an icon.
	* <br>Icons are defined in the CATRsc file of the header.  
	* @param Text
	*  Each button in all toolbars of the workbench are represented by a text. 
	*  <br>The text is the title of the button. See the CATNls file of the header.
	*/
  enum CATAfrToolbarStyle {Icons, Text};

    /*---------------------------------*/
    //     CONSTRUCTORS  
    /*---------------------------------*/

  /** 
  * @nodoc 
  */
  CATCmdWorkbench (const CATString & name, Persistence = Code);


  /**
    * @nodoc
    */
  CATCmdWorkbench (const CATString & implClass, CATCmdWorkshop * father);

  virtual ~CATCmdWorkbench ();
  /** 
  * @nodoc 
  */  
  CATCmdWorkbench (CATCmdWorkbench & toCopy);
  /** 
  * @nodoc 
  */  
  virtual CATCmdAccess * Clone(int noNext = 0,CATCmdAccess * toBeCompleted = NULL);
			       

    /*---------------------------------*/
    //     PRIORITY MANAGEMENT 
    /*---------------------------------*/
  /** 
  * @nodoc 
  */  
  int  GetPriority();
  /** 
  * @nodoc 
  */
  void SetPriority(int priority);


    /*---------------------------------*/
    //     MENU MANAGEMENT 
    /*---------------------------------*/

  /** 
  * @nodoc 
  */
  CATCmdContainer * GetMenu() const;
  /** 
  * @nodoc 
  */
  virtual void SetMenu (CATCmdContainer *);
  /** 
  * @nodoc 
  */
  void ExtractMenus(CATCmdContainer * from, LocalMode mode = Workshop);
  /** 
  * @nodoc 
  */
  virtual void InsertMenus (CATCmdContainer * into);
  /** 
  * @nodoc 
  */  
  void Merge(CATCmdWorkbench * toMerge, int replaceMode = 0);

    /*---------------------------------*/
    //     3DEXP TOOLBAR MANAGEMENT 
    /*---------------------------------*/
  /** 
  * @nodoc 
  */
  void ExtractToolbars(CATCmdContainer * from, LocalMode mode = Workshop);
  /** 
  * @nodoc 
  */
  virtual void InsertToolbars (CATCmdContainer * into);

  
    /*---------------------------------*/
    //     SHOW-HIDE 
    /*---------------------------------*/

  /** 
  * @nodoc 
  */
  virtual int  FillViews(CATDialog * parent);
  /** 
  * @nodoc 
  */
  virtual void ClearViews(int deleteTlb = 0);


    /*---------------------------------*/
    //     FOR INTERNAL USAGE 
    /*---------------------------------*/
  /** @nodoc */
  virtual char * GenerateVariableName(const char *);
  /** @nodoc */
  virtual void FlatDump(DumpMode = Simple, int noNext = 0) const;

  /**
  * @nodoc
  * Sets the access's type.
  * <b>Role</b>: The type is necessary for the <tt>CATCmdContainer</tt> access. 
  * <b>Legal values</b>: Menubar,Toolbar,Workshop,Workbench,Starter,
  * Separator,IconBox, Submenu and Menu.
  */
  virtual void SetType (const CATString & type);  
  
  /** @nodoc */
  virtual void CreateHeaders();

  /** 
  * @nodoc 
  * Gets a palette from its name.
  */
  virtual CATCmdContainer * GetContainer(const CATString & name);


    /*---------------------------------*/
    //     NLS QUERIES
    /*---------------------------------*/
  /** @nodoc */
  virtual const CATUnicodeString & GetTitle();


    /*---------------------------------*/
    //     CUSTOM IID 
    /*---------------------------------*/
  /** @nodoc */
  void SetIIDList(CATListPV * DefaultIIDList, CATListPV * CustomIIDList);
  /** @nodoc */
  IID * GetCustomIID(IID & DefaultIID) const;

    /*---------------------------------*/
    //     SAVE 
    /*---------------------------------*/
  
#ifdef AfrCAA2
  /** @nodoc */
  virtual void SaveAsXml (CATAfrGen * Gen, int depth);
#endif

    /*---------------------------------*/
    //     MISC 
    /*---------------------------------*/
  /** 
  * @nodoc 
  * used before saving preferences.
  */
  virtual void FilterPersistence(Persistence, int keep, int inDepth = 1);

  /** @nodoc */
  CATBoolean GetTransient () const;
  /** @nodoc */
  void    SetTransient (CATBoolean);

  /** @nodoc */
  CATAfrToolbarStyle GetToolbarStyle () const;
  /** @nodoc */
  void    SetToolbarStyle (CATAfrToolbarStyle);

  /** @nodoc */
  void    SetToolbarsExclusive(const int & iExclusiveFlag = 1);
  /** @nodoc */
  int     GetToolbarsExclusivity() const;

  /** @nodoc */
  void    RemoveToolbar (const CATString &);
  /** @nodoc */
  const CATListOfCATString & GetRemovedToolbars ();

  /** @nodoc */
  void    HideToolbar (const CATString &);
  void    UnhideToolbar (const CATString &);
  /** @nodoc */
  const CATListOfCATString & GetHiddenToolbars ();

  /** @nodoc */
  void UseAdaptiveToolbar ();
  /** @nodoc */
  CATBoolean UsesAdaptiveToolbar ();

  /** @nodoc */
  void SetLoader (CATCmdWorkbenchLoader *);
  /** @nodoc */
  CATCmdWorkbenchLoader * GetLoader ();

  /** @nodoc
      Do not use, reserved for declarative purpose */
  CATCmdWorkbench (Persistence = Code);

  /**
   * @nodoc
   * VV6 - Declarative AfrFoundation
   * Merge the administrator settings retrieved from settings repository
   * These settings correspond to the commands disabled by an administrator.
   */
  virtual void MergeAdminSettings();

  /**
   * Get the list of forbidden command headers by the Tools/Options page
   * Commands Availability Management.
   *
   * @return the list of forbidden command headers.
   */
  const CATListOfCATString & GetForbiddenHeaders();

protected:
  
  /** @nodoc */
  void InsertMenuContents(CATCmdContainer * fromMenu,
			  CATCmdAccess    * toCopy,
			  CATCmdContainer * intoMenuBar,
			  const CATString * beforeMenu,
			  const CATString * beforeItem);

  /**
   * Set the list of forbidden command headers by the Tools/Options page
   * Commands Availability Management.
   *
   * @param the list of forbidden command headers.
   */
  void SetForbiddenHeaders(const CATListOfCATString & i_forbiddenHeaders);

  /**
   * Load the forbidden command headers set by the Tools/Options page
   * Commands Availability Management.
   */
  void LoadForbiddenHeaders();

  
private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATCmdWorkbench & operator= (const CATCmdWorkbench &);

  void Init();

  virtual void _LoadForbiddenHeaders();
  /**
   * Update the list of forbidden command headers of l_CATApplicationFrame when
   * the current workshop or workbench changes.
   */
  virtual void UpdateAdminForbiddenCommandHeaders();
  
  int                     _priority;
  int                     _titleResource;
  int                     _toolbarsExclusivity;

  CATBoolean              _isTransient;
  CATAfrToolbarStyle      _toolbarStyle;

  CATListPV             * _DefaultIIDList;
  CATListPV             * _CustomIIDList;
  
  CATCmdWorkbenchLoader * _loader;

  CATListOfCATString      _RemovedToolbars;
  CATListOfCATString      _HiddenToolbars;
  CATListOfCATString      _forbiddenHeaders;
  int _forbiddenHeadersLoaded;


  CATBoolean              _UseAdaptiveToolbar;

  void ExtractSubMenus(CATCmdContainer *currentMenu,  CATCmdContainer **subExtractedMenu, LocalMode mode);
  void ExtractSubContainers(CATCmdContainer *currentContainer,  CATCmdContainer **subExtractedContainer, LocalMode mode);

};

#endif
