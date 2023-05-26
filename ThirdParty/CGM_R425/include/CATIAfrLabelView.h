
#ifndef CATIAfrLabelView_H
#define CATIAfrLabelView_H

// COPYRIGHT DASSAULT SYSTEMES 2011/02/08

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

class CATIAfrLabel;
class CATVizViewer;
class CATString;
class CATVidFraDialogBox;
class CATICAfrForm;
class CATICAfrComponentController;

enum CATAfrLabelViewMode
{
  CATAfrLabelViewExpand    = 0, 
  CATAfrLabelViewCollapse  = 1
};

//-----------------------------------------------------------------------------
/**
* Interface creted Label View.
* Created a CID label view.
* The user may precise options with the <tt>SetXxx</tt> methods.
*
*<br> Sample *<br> ...
*<br> ...
*<br> CATIAfrLabelView * piAfrLabelView = NULL;
*<br> CATInstantiateComponent ("CATAfrLabelView",
*<br>                          IID_CATIAfrLabelView,
*<br>                          (void **)&piAfrLabelView);
*<br> if( piAfrLabelView )
*<br> {
*<br>    ...
*<br>    piAfrLabelView->Release(); piAfrLabelView = NULL,
*<br> }
*<br>
*
*/
extern ExportedByCATAfrItf  IID IID_CATIAfrLabelView ;
class ExportedByCATAfrItf CATIAfrLabelView: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Creates a CID immersive Label.
    *   @param ipiAfrLabel
    *     Object to define the Label.
    *   @param iTitleDim
    *     Dimension of the title, if the title length is superior, the title is cropped by the middle.
    *     If the default value is -1.0f, the length is automaticly calculated.
    *   @param iAttrDim
    *     Dimension of the Attribut name, if the Attribut name length is superior, the Attribut name is cropped by the middle.
    *   @param iValueDim
    *     Dimension of the value , if the value length is superior, the value is cropped by the middle.
    */
    virtual HRESULT CreateCompassLabelView( CATIAfrLabel* ipiAfrLabel, 
                                            CATICAfrComponentController* ipiCAfrComponentController, 
                                            const float& iTitleDim = -1.0f, 
                                            const float& iAttrDim = 150.0f, 
                                            const float& iValueDim = 250.0f ) = 0;

    /**
    * Removes all component.
    */
    virtual HRESULT RemoveComponents( ) = 0;

    /**
    * Creates a CID immersive Label.
    *   @param ipParent
    *     The father
    *   @param ipiAfrLabel
    *     Object to define the Label.
    *   @param iName
    *     Identifier
    *   @param opVidFraDialog
    *     The CID Label must call RequestDelayedDestruction after use
    *   @param iMode
    *     Mode to display the CID Label
    *   @param iTitleDim
    *     Dimension of the title, if the title length is superior, the title is cropped by the middle.
    *     If the default value is -1.0f, the length is automaticly calculated.
    *   @param iAttrDim
    *     Dimension of the Attribut name, if the Attribut name length is superior, the Attribut name is cropped by the middle.
    *   @param iValueDim
    *     Dimension of the value , if the value length is superior, the value is cropped by the middle.
    */
    virtual HRESULT CreateLabelView( CATVizViewer* ipParent, 
                                     CATIAfrLabel* ipiAfrLabel, 
                                     const CATString& iName, 
                                     CATVidFraDialogBox** opVidFraDialog, 
                                     const CATAfrLabelViewMode& iMode = CATAfrLabelViewExpand, 
                                     const float& iTitleDim = -1.0f, 
                                     const float& iAttrDim = 150.0f, 
                                     const float& iValueDim = 250.0f ) = 0;

    /**
    * Creates a CID floating Label, a floating Label is a Label with resizable style, a title and the close button.
    *   @param ipParent
    *     The father
    *   @param ipiAfrLabel
    *     Object to define the Label.
    *   @param iName
    *     Identifier
    *   @param opVidFraDialog
    *     The CID Label must call RequestDelayedDestruction after use
    *   @param iTitleDim
    *     Dimension of the title, if the title length is superior, the title is cropped by the middle.
    *     If the default value is -1.0f, the length is automaticly calculated.
    *   @param iAttrDim
    *     Dimension of the Attribut name, if the Attribut name length is superior, the Attribut name is cropped by the middle.
    *   @param iValueDim
    *     Dimension of the value , if the value length is superior, the value is cropped by the middle.
    */
    virtual HRESULT CreateFloatingLabelView( CATVizViewer* ipParent, 
                                             CATIAfrLabel* ipiAfrLabel, 
                                             const CATString& iName, 
                                             CATVidFraDialogBox** opVidFraDialog, 
                                             const float& iTitleDim = -1.0f, 
                                             const float& iAttrDim = 150.0f, 
                                             const float& iValueDim = 250.0f ) = 0;

};
#endif
