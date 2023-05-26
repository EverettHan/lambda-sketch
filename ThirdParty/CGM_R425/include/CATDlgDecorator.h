#ifndef CATDLGDECORATOR_H
#define CATDLGDECORATOR_H

// COPYRIGHT DASSAULT SYSTEMES 2000

//--------------------------------------------------------------------------
#include "CATDialog.h"

//--------------------------------------------------------------------------
class CATString;
class l_CATDlgDecorator;

//--------------------------------------------------------------------------
// CATDlgDecorator was created for a specific usage in "ApplicationFrame".
// You are strongly recommended against using it in any other case.
class ExportedByDI0PANV2 CATDlgDecorator : public CATDialog
{

//--------------------------------------------------------------------------
 public:

        CATDlgDecorator( CATDialog *pParent, const CATString& rObjectName, CATDlgStyle nStyle=NULL);
        virtual ~CATDlgDecorator();
        virtual l_CATDialog* GetLetterObject();
        virtual void ResetLetterObject();
        CATDeclareClass ;

//--------------------------------------------------------------------------
 private:

//      address of internal object.
        l_CATDlgDecorator* _frameDecorator;
};
#endif
