#ifndef CATDLGICC_H
#define CATDLGICC_H

// COPYRIGHT DASSAULT SYSTEMES 2000

class CATNotification;
class l_CATDlgICC;

//--------------------------------------------------------------------------
#include "CATCommand.h"
#include "DI0PANV2.h"
#ifdef DRIVER_MOTIF
#include "CATDlgPortable.h"
#include "CATNotification.h"
#include "CATDialog.h"


class ExportedByDI0PANV2 CATDlgICCWritePerformedNotification : public CATNotification
{

 public:

    CATDlgICCWritePerformedNotification();
    virtual ~CATDlgICCWritePerformedNotification();
    virtual int IsAKindOf(CATClassId kind) const;
    virtual CATClassId IsA() const;
    static  CATClassId ClassName();

};

class ExportedByDI0PANV2 CATDlgICCReadRequestNotification : public CATNotification
{

 public:

    CATDlgICCReadRequestNotification();
    virtual ~CATDlgICCReadRequestNotification();
    virtual int IsAKindOf(CATClassId kind) const;
    virtual CATClassId IsA() const;
    static  CATClassId ClassName();

};

//--------------------------------------------------------------------------
class ExportedByDI0PANV2 CATDlgICC : public CATCommand
{

//--------------------------------------------------------------------------
 public:

//      constructor - destructor
        CATDlgICC( CATDialog *pParent, const CATString& name);
        virtual ~CATDlgICC();

//      get event notifications
        CATNotification *GetICCWritePerformedNotification() const;
        CATNotification *GetICCReadRequestNotification() const;

//      get X/Windows environment
        XtAppContext GetXtAppContext();
        Display*     GetXtDisplay();
        Widget       GetAppWidget();
        Time         GetNewTransactionTime();
        Atom         GetTransactionAtom();

//      read/write
        void         InitiateRead(Time);
        void         GetBuffer(char**, int*);
        int          InitiateWrite(Time, char*, int);

//      get internal object
        l_CATDlgICC* GetLetterObject();

//      resets the internal object.
        virtual void ResetLetterObject();

//--------------------------------------------------------------------------
 private:

//      address of internal object.
        l_CATDlgICC *_frameICC;        
};


// Protocole de communication
#define DIALOG_NAME "CATDialog"
#define DIALOG_EDIT_PROTOCOL 1   
//
// valeur de data du clientmessage l[0] = atome, l[1] = DIALOG_EDIT_PROTOCOL, l[2] = Time, l[3] = l[4] = 0

typedef enum { SendDialogTree = 0,
               SetValues      = 1,
               GetValues      = 2,
               Flash          = 3
             } DialogEditCommand;

typedef enum { TypeUnspecified,
               TypeBarMenu,
               TypeCheckButton,
               TypeCheckItem,
               TypeCombo,
               TypeContainer,
               TypeContextualMenu,
               TypeDialog,
               TypeDocument,
               TypeEditor,
               TypeFile,
               TypeFrame,
               TypeIconBox,
               TypeLabel,
               TypeMotif,
               TypeMultiList,
               TypeNotify,
               TypePushButton,
               TypePushItem,
               TypeRadioButton,
               TypeRadioItem,
               TypeSelectorList,
               TypeSeparator,
               TypeSeparatorItem,
               TypeSlider,
               TypeSpinner,
               TypeSplitter,
               TypeStatusBar,
               TypeSubMenu,
               TypeTabContainer,
               TypeTabPage,
               TypeToolBar
             } DialogObjectType;

typedef struct { DRECT GeomAtt;
                 CATBool SensitivityAtt;
                 CATULong VisibilityAtt;
		 int TitleAttOffset;
             } DialogObjectAttribute;

typedef l_CATDialog* DialogID;

typedef struct { DialogID DlgID;
		 int DlgType;
                 int DlgOffsetName;
               } DialogTreeElement;
               
typedef struct { Time eventTime;
                 int  sizeBuffer;
                 DialogEditCommand order;
                 int returnCode;
               } DialogEditHeader;

#define SUCCESS 0
#define BAD_PROTOCOL 1
#define BAD_COMMAND 2
#define BAD_DIALOG 2
#endif
#endif
