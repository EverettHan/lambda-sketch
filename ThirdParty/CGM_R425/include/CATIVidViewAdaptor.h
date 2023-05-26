#ifndef _CATIVidViewAdaptor_H
#define _CATIVidViewAdaptor_H

#include <CATBaseUnknown.h>
#include <CATViewItf.h>

extern ExportedByCATViewItf IID IID_CATIVidViewAdaptor;

class CATRep;
class CATMathPoint2Df;
class CATMathVectorf;
class CATDrawView;

/**
 * Interface for interop between CATView and VisuImmersiveDialog.
 * Allows the CATDrawView to call CATVidViewAdaptor methods
 **/
class ExportedByCATViewItf CATIVidViewAdaptor : public CATBaseUnknown
{
  CATDeclareInterface;

  public:
    /**
    * Set child CATView object. iView should be a child of this.
    **/
    virtual void SetView (CATDrawView *iView) = 0;

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

CATDeclareHandler( CATIVidViewAdaptor, CATBaseUnknown );

#endif
