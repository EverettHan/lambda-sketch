#ifndef _CATIViewContainer_H
#define _CATIViewContainer_H

#include <CATBaseUnknown.h>
#include <CATViewItf.h>

extern ExportedByCATViewItf IID IID_CATIViewContainer;

class CATRep;
class CATMathPoint2Df;
class CATMathVectorf;

/**
 * Interface for interop between CATView and VisuImmersiveDialog.
 * OBSOLETE class. Replaced by CATIVidViewAdaptor.
 * DON'T USE!!!!
 **/
class ExportedByCATViewItf CATIViewContainer : public CATBaseUnknown
{
  CATDeclareInterface;

  public:
    /**
    * Get visibility
    **/
    virtual int GetContainerVisibility (void) = 0;

    /**
    * Add CATView visualization representation to VID BagRep
    **/
    virtual void AddRep (CATRep *ipRep) = 0;

    /**
    * Set VID effective dimensions to enable VID scrolling
    **/
    virtual void SetEffectiveDimensions (const CATMathPoint2Df & i_requestedEffectiveDimension) = 0;

    /**
    * Get absolute translation of CATView object in viewer
    **/
    virtual void GetTranslation (CATMathVectorf & oTranslation) = 0;
};

CATDeclareHandler( CATIViewContainer, CATBaseUnknown );

#endif
