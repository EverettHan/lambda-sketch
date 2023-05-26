
#ifndef CATIAfrItemViewer_H
#define CATIAfrItemViewer_H

// COPYRIGHT Dassault Systemes 2013/06/14

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

/**
* The type of representation to work with. This will determine the way 
* the representation is displayed.
*/
enum CATAfrItemViewerRepresentationRole{
  /** Standard rep, using advanced drawing algorithm */
  StandardRole  = 1,
  /** Furtive rep, used mainly for prehighlight */
  FurtiveRole   = 1<<1, 
  /** Highlight rep, used mainly to draw highlighted part of model */
  HighlightRole = 1<<2,
  /** Multi color Highlight rep, used mainly to draw highlighted part of model with a different color using Multicolor Highlight feature */
  MultiColorHighlightRole = 1 << 3,
  /** All the representation are impacted by the action */
  AllRoles     = 1|1<<1|1<<2 | 1 << 3 
};

extern ExportedByCATAfrItf IID IID_CATIAfrItemViewer ;

//-----------------------------------------------------------------------------
/**
* Interface managing CATAfrItemViewer.
*
*/
class ExportedByCATAfrItf CATIAfrItemViewer: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Attach to visu manager
    */
    virtual HRESULT AttachToVisuManager( CATBaseUnknown* ipRootObject ) = 0;

    /**
    * Reframe
    */
    virtual HRESULT Reframe() = 0;

    /**
    * AddRep
    */
    virtual HRESULT AddRep( CATBaseUnknown* ipBaseRep, const CATAfrItemViewerRepresentationRole& i_repType) = 0;

    /**
    * RemoveRep
    */
    virtual HRESULT RemoveRep( CATBaseUnknown* ipBaseRep, const CATAfrItemViewerRepresentationRole& i_repType) = 0;
};

#endif
