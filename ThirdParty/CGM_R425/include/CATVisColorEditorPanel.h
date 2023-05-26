#ifndef CATVisColorEditorPanel_H
#define CATVisColorEditorPanel_H
//
//------------------------------------------------------------------------------

#include "CATVisColorChooser.h"

#include "CATDlgDialog.h"
#include "CATDlgUtility.h"
#include "CATListOfCATUnicodeString.h"

class CATDlgTabContainer;
class CATDlgTabPage;

class CATVisColorEditorFrame;
class CATVisColorManager;
class CATDlgFrame;
class CATDialog;
class CATDlgCombo;
class CATString;
class CATCommand;
class CATNotification;
class CATDlgContainer;

class ExportedByCATVisColorChooser CATVisColorEditorPanel : public CATDlgDialog
{
   DeclareResource(CATVisColorEditorPanel,CATDlgDialog)
   CATDeclareClass;

//------------------------------------------------------------------------------
public:

   CATVisColorEditorPanel(CATDialog * iParent, const CATString & iName, CATDlgStyle iStyle = NULL);
   virtual ~CATVisColorEditorPanel();

//------------------------------------------------------------------------------
private:

   CATVisColorEditorPanel();
   CATVisColorEditorPanel(const CATVisColorEditorPanel &);               // no copy constructor
   CATVisColorEditorPanel& operator = (const CATVisColorEditorPanel &);  // no egal operator

   void OKCB        (CATCommand * cmd, CATNotification * notif, CATCommandClientData data);
   void CancelCB    (CATCommand * cmd, CATNotification * notif, CATCommandClientData data);
   void CloseCB     (CATCommand * cmd, CATNotification * notif, CATCommandClientData data);

   void TabPageChangeCB (CATCommand * cmd, CATNotification * notif, CATCommandClientData data);

   void FavoritePageCB (CATCallbackEvent event, void * sender, CATNotification * notif, CATSubscriberData data, CATCallback);

   void CatalogComboCB  (CATCommand * cmd, CATNotification * notif, CATCommandClientData data);

   void Build();
   void BuildStandardPage();
   void BuildFavoritePage();
   void BuildCatalogPage();

   CATDlgTabContainer * _tabContainer;
   CATDlgTabPage      * _pageStandard;
   CATDlgTabPage      * _pageFavorite;
   CATDlgTabPage      * _pageCatalog;
   CATDlgFrame        * _pageStandardFrame;
   CATDlgFrame        * _pageFavoriteFrame;
   CATDlgFrame        * _pageCatalogFrame;
   CATDlgContainer    * _pageCatalogContainer;

   CATDlgFrame            * _ColorSelectFrame;
   CATDlgFrame            * _ColorComponentFrame;
   CATDlgFrame            * _ColorPreviewFrame;
   CATDlgFrame            *_FavoriteColorFrame;

   CATDlgCombo            *_catalogCombo;

   CATVisColorManager * _ColorManager;

   CATListOfCATUnicodeString _interfaceList;

   int _currentPage;
};
#endif
