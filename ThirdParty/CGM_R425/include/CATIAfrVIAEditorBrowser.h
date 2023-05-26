
#ifndef CATIAfrVIAEditorBrowser_H
#define CATIAfrVIAEditorBrowser_H

// COPYRIGHT DASSAULT SYSTEMES 2013/01/28

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

extern ExportedByCATAfrItf  IID IID_CATIAfrVIAEditorBrowser ;

//-----------------------------------------------------------------------------
/**
* Interface to manage the behaviors of the Browser with the Editor
* Cf CATIVIATreeViewFrame
*/
class ExportedByCATAfrItf CATIAfrVIAEditorBrowser: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Get ExtractedFlag mode
    * Default value is FALSE
    **/
    virtual const CATBoolean GetExtractedFlag() = 0 ;

    /**
    * Get VisibleFlag mode
    * Default value is TRUE
    **/
    virtual const CATBoolean GetVisibleFlag() = 0 ;

    /**
    * Get MaximizeFlag mode
    * Default value is FALSE
    **/
    virtual const CATBoolean GetMaximizeFlag() = 0 ;

    /**
    * Get DockContent mode
    * Default value is TRUE
    **/
    virtual const CATBoolean GetDockContentVisibleFlag() = 0 ;

    /**
    * Get DockLeftFlag mode
    * Default value is TRUE
    **/
    virtual const CATBoolean GetDockLeftFlag() = 0 ;

    /**
    * Call the custom setting
    **/
    virtual HRESULT UpdateComponent( ) = 0 ;
};
#endif
