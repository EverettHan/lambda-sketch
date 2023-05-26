
#ifndef CATIVidTweakerWidget_H
#define CATIVidTweakerWidget_H

// COPYRIGHT DASSAULT SYSTEMES 2011/02/09

#include "VisuDialogEx.h"
#include "CATBaseUnknown.h"

class CATVidWidget;
class CATCommand;
class CATString;
class CATBaseUnknown_var;

//-----------------------------------------------------------------------------
/**
* Interface created a tweaker widget to add in form.
*
*<br> Sample *<br> ...
*<br> ...
*<br> CATIVidTweakerWidget * piTweakerWidget = NULL;
*<br> CATInstantiateComponent ("CATMyVidTweakerWidget",
*<br>                          IID_CATIVidTweakerWidget,
*<br>                          (void **)&piTweakerWidget);
*<br> if( piTweakerWidget )
*<br> {
*<br>    ...
*<br>    piTweakerWidget->Release(); piTweakerWidget = NULL,
*<br> }
*<br>
*
*/
extern ExportedByVisuDialogEx IID IID_CATIVidTweakerWidget ;

class ExportedByVisuDialogEx CATIVidTweakerWidget: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Creates an immersive widget for the given object.<br>
    * The caller has to embed the created widget in a VID container (for example a CATVidLayGrid).
    * @param iParent
      * The parent command. Must not be NULL
    * @param iName
      * The name of the widget built by this method
    * @param iObjet
      * The object with the created widget.
    * @return
    * The create immersive editor widget
    */
    virtual CATVidWidget* CreateVidTweaker( CATCommand* ipParent, const CATString &iName, 
                                            const CATBaseUnknown_var& iObjet ) = 0;
};
#endif
