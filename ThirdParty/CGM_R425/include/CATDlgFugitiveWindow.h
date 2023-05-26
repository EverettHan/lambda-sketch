#ifndef CATDLGFUGITIVEWINDOW_H 
#define CATDLGFUGITIVEWINDOW_H

// COPYRIGHT DASSAULT SYSTEMES 2004


#include "CATDlgWindow.h"

class l_CATDlgFugitiveWindow;
class CATInteractiveApplication;

class ExportedByDI0PANV2 CATDlgFugitiveWindow : public CATDlgWindow
{
  public:

    CATDlgFugitiveWindow( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

    virtual ~CATDlgFugitiveWindow();

    void AddSensitiveObject(CATDialog* iObj);
    void RemoveSensitiveObject(CATDialog* iObj);

    /** @nodoc
    * Get internal object.
    */
    virtual l_CATDialog* GetLetterObject();

    /** @nodoc 
    * Resets internal object.
    */
    virtual void ResetLetterObject();

    /**
    * @nodoc
    * Requests the ClassName, IsA, and IsAKindOf methods to be created.
    */
    CATDeclareClass ;

  private:

    /** @nodoc
    * Address of internal object.
    */
    l_CATDlgFugitiveWindow* _frameFugitiveWindow;
};
#endif
