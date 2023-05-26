#ifndef CATFrmWindowCommand_H
#define CATFrmWindowCommand_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include <CATAfrFoundation.h>

#include <CATString.h>
#include <CATUnicodeString.h>
#include <CATListOfCATString.h>

class CATCmdAccess;
class CATCmdContainer;
class CATCmdStarter;

enum  CATFrmItemType{CATFrmStarter,
		     CATFrmSubMenu,
		     CATFrmChooser,
		     CATFrmChecker,
         CATFrmFlyOut};

class ExportedByCATAfrFoundation CATFrmWindowCommand
{
   public:
     // Constructor
       CATFrmWindowCommand(const CATString& cmdName,
			   const CATUnicodeString& cmdTitle,
			   const CATString& menuName,
			   const CATString& subMenuName = "",
			   int separate = 0);

       CATFrmWindowCommand(const CATString& cmdName,
         const CATListOfCATString& cmdNames,
			   const CATString& menuName,
         const CATString& anchorItem = "",
			   const CATString& subMenuName = "",
			   int separate = 0);

       CATFrmWindowCommand(const CATString& cmdName,
         const CATListOfCATString& cmdNames,
         const CATListOfCATString& cmdAccessNames,
         const CATString& menuName,
         const CATString& anchorItem = "",
         const CATString& subMenuName = "",
         int separate = 0);

       CATFrmWindowCommand(const CATString& cmdName,
			   const CATUnicodeString& cmdTitle,
			   const CATString& menuName,
			   CATFrmItemType itemType,
			   int separate = 0);

       CATFrmWindowCommand(const CATString& cmdName,
			   const CATUnicodeString& cmdTitle,
			   const CATString& menuName,
			   CATFrmItemType itemType,
         const CATString& anchorItem,
			   int separate = 0);

     // Copy Constructor
//       CATFrmWindowCommand(const CATFrmWindowCommand& cmd);

     // Destructor
       virtual ~CATFrmWindowCommand();

     // operator = 
//       CATFrmWindowCommand& operator =(const CATFrmWindowCommand& cmd);

       CATString GetName();
       void      AddToMenu(const CATString * beforeItem = NULL);
       void      RemoveFromMenu();
       void      SetAsToolsBarItem(const CATString& toolsBarName, int isMenuItem=1);
       void      SetStatus(int status); //=0: command unavailable; =1: command available;

       static CATCmdContainer* GetMenu(CATCmdContainer *menu,
				       const CATString& menuName);
       static CATCmdStarter  * GetItem(CATCmdContainer *menu,
				       const CATString& itemName);
       void SetSecondaryCommand();
   private:

      // Data
      CATString        _cmdName;
      CATUnicodeString _cmdTitle;
      CATString        _menuName;
      CATString        _subMenuName;
      CATString        _toolsBarName;
      int              _separate;
      int              _toolsBarItem;
      int              _isMenuItem;
      CATFrmItemType   _itemType;
      CATCmdAccess *   _obj;
      CATString        _anchorItem; // name of the item to use as anchor
      CATListOfCATString _cmdNames;
      CATListOfCATString _cmdAccessNames;
      int              _cmdAccessNamesUse;
      int              _secondaryCmd;

      CATCmdAccess * GetAccess(CATCmdContainer *menu, const CATString& itemName, CATFrmItemType itemType);
      CATCmdAccess * CreateAs (CATFrmItemType itemType=CATFrmStarter);
      void           AddItemToMenu(const CATString * beforeItem);
      void           AddItemToTBar(const CATString * beforeItem);
      void           RemoveItemFromTBar();
      void           SetSelect();

      static const CATUnicodeString _class;
};
#endif
