#ifndef CATTopEnvelopeRegion_H
#define CATTopEnvelopeRegion_H

// COPYRIGHT DASSAULT SYSTEMES 2014

#include "CATCGMVolumetricSweepCmp.h" // NLD260917 #include "AdvVolSweep.h"

#include "CATTopOperator.h"
#include "VolumetricSweepFunctions.h"
#include "CATBodyMotion.h"
#include "CATMathInterval.h"

class CATBody;
class CATGeoFactory;
class CATTopData;
class CGMVswpAxisymBodyDef;

/**
 * Class defining the operator that creates a body containing a volumetric sweep characteristic zone.
 */

class ExportedByCATCGMVolumetricSweepCmp CATTopEnvelopeRegion: public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopEnvelopeRegion);

public:

    /**
    * Constructor
    * TODO: need to generalize this operator to work without :
    * VswpAxisymBodyDef const& iWhDef
    */
    CATTopEnvelopeRegion(
        CATGeoFactory          * ipFactory,
        CATTopData             * ipTopData,
        CATBodyMotion     const& iBodyMotion,
        CATMathInterval   const& TDm,
        CATBody                * ipIngressBody,
        CATBody                * ipEgressBody,
        CATBody                * ipSweepBody,
        VswpAxisymBodyDef const* ipWhDef,
        double                   iTolerance);

    /**
    * Destructor
    */
    virtual ~CATTopEnvelopeRegion();

    /** 
    * @nocgmitf
    * Allows turning off and on this operator's ProgressBar management.
    * <br><b>Role</b>: By default this operator manages the current progress bar, 
    * which can lead to conflicts with other management of the progress bar.
    * This method is a way to resolve the conflict.
    *
    * @param iProgBarIsAuthorized [in]
    *   TRUE : The ProgressBar management is turned ON.
    *   FALSE: The ProgressBar management is turned OFF.
    */
    void SetProgressBarAuthorized(CATBoolean iProgBarIsAuthorized);


    //===================================
    // Public methods for CGM Replay.
    //===================================
    /**
    * @nocgmitf
    */
    static const  CATString  *GetDefaultOperatorId(){ return &_OperatorId; }

    // Overrides
    /**
    * @nocgmitf
    * Defines whether or not the resulting body should be frozen.
    * @param iFreezeMode
    * The freeze mode.
    */
    void SetFreezeMode(CATBodyFreezeMode iFreezeMode) ;

    /**
    * @nocgmitf
    * Whether the envelope was generated completely.
    * The freeze mode.
    */
    CATBoolean IsEnvelopeComplete() const { return _ShellComplete; }

protected:

    int                RunOperator();

    //========================================================
    // Protected methods for CGM Replay.
    //========================================================
    const  CATString  *GetOperatorId();
    void               RequireDefinitionOfInputAndOutputObjects();

    CATExtCGMReplay   *IsRecordable(short &LevelOfRuntime, short &VersionOfStream);
    void               WriteInput(CATCGMStream &Str);

    void               Dump(CATCGMOutput &os);

private:

    static  CATString         _OperatorId;

    // Required properties
    CATBodyMotion            _BodyMotion;
    CATMathInterval          _TDm;
    CATBody                * _pIngressBody;
    CATBody                * _pEgressBody;
    CATBody                * _pSweepBody;
    VswpAxisymBodyDef const* _pWhDef;
    double                   _Tolerance;
    CATBoolean               _ShellComplete;

    // Optional properties
    CATBoolean               _freezeModeIsDefault;

    CATBoolean               _progBarIsAuthorizedIsDefault;
    CATBoolean               _progBarIsAuthorized;

};

/**
 * Creates an instance of the operator that generates a characteristic zone body 
 */
ExportedByCATCGMVolumetricSweepCmp CATTopEnvelopeRegion *CATCreateTopEnvelopeRegion(
        CATGeoFactory          * ipFactory,
        CATTopData             * ipTopData,
        CATBodyMotion const    & iBodyMotion,
        CATBody                * ipIngressBody,
        CATBody                * ipEgressBody,
        CATBody                * ipSweepBody,
        VswpAxisymBodyDef const* iWhDef,
        double                   iTolerance);

/**
 * Creates an instance of the operator that generates a characteristic zone body 
 * in the time domain provided. 
 */
CATTopEnvelopeRegion           * CATCreateTopEnvelopeRegion(
        CATGeoFactory          * ipFactory,
        CATTopData             * ipTopData,
        CATBodyMotion     const& iBodyMotion,
        CATMathInterval   const& TDm,
        CATBody                * ipIngressBody,
        CATBody                * ipEgressBody,
        CATBody                * ipSweepBody,
        VswpAxisymBodyDef const* iWhDef,
        double                   iTolerance);

ExportedByCATCGMVolumetricSweepCmp void DeleteCATTopEnvelopeRegionOperator( CATTopEnvelopeRegion*& op );

#endif /* CATTopEnvelopeRegion_h */
