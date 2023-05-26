#ifndef CATTopCharacteristicZone_H
#define CATTopCharacteristicZone_H

// COPYRIGHT DASSAULT SYSTEMES 2014

#include "CATCGMVolumetricSweepCmp.h" // NLD260917 #include "AdvVolSweep.h"

#include "CATTopOperator.h"
#include "VolumetricSweepFunctions.h"
#include "CATBodyMotion.h"

class CATBody;
class CATGeoFactory;
class CATTopData;

/**
 * Class defining the operator that creates a body containing a volumetric sweep characteristic zone.
 */

class ExportedByCATCGMVolumetricSweepCmp CATTopCharacteristicZone: public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATTopCharacteristicZone);

public:

    /**
    * Constructor
    */
    CATTopCharacteristicZone(
        CATGeoFactory      * ipFactory,
        CATTopData         * ipTopData,
        CATBody            * ipSweepBody,
        CATBodyMotion const& iBodyMotion,
        double               iTime,
        int                  iIngressOrEgressOrChar);

    /**
    * Destructor
    */
    virtual ~CATTopCharacteristicZone();

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
    //void SetProgressBarAuthorized(CATBoolean iProgBarIsAuthorized);


    //===================================
    // Public methods for CGM Replay.
    //===================================
    /**
    * @nocgmitf
    */
    static const  CATString  *GetDefaultOperatorId()
    { return &_OperatorId; }

    // Overrides
    /**
    * @nocgmitf
    * Defines whether or not the resulting body should be frozen.
    * @param iFreezeMode
    * The freeze mode.
    */
    //void SetFreezeMode(CATBodyFreezeMode iFreezeMode) ;

protected:

    int                RunOperator();

    //========================================================
    // Protected methods for CGM Replay.
    //========================================================
    const  CATString  *GetOperatorId();
    void               RequireDefinitionOfInputAndOutputObjects();

    CATExtCGMReplay   *IsRecordable(short &LevelOfRuntime, short &VersionOfStream);
    //void               WriteInput(CATCGMStream &Str);

    //void               Dump(CATCGMOutput &os);

private:

    //friend CATTopCharacteristicZone * CreateTopCharacteristicZone(
    //                                            CATGeoFactory *ipFactory,
    //                                            CATTopData *ipTopData,
    //                                            CATBody *ipSweepBody,
    //                                            CATBodyMotion const& iBodyMotion,
    //                                            double iTime,
    //                                            int iIngressOrEgressOrChar,
    //                                            short CharOpVersion
    //                                            );

    static  CATString _OperatorId;

    // Required properties
    
    short _CharOpVersion;
    CATBody * _pSweepBody;
    CATBodyMotion _BodyMotion;
    
    // List of objects used by the CATBodyMotion
    
    CATLISTP(CATICGMObject) _listOfBodyMotionObj;

    // The time instant for which characyteristic zone is needed.

    double _Time;

    // The region of the swept body needed after the char zone wire
    // disconnects it.

    int _IngressOrEgressOrChar;

    // Optional properties
    
    CATBoolean _freezeModeIsDefault;
    CATBoolean _progBarIsAuthorizedIsDefault;
    CATBoolean _progBarIsAuthorized;
};

/**
 * Creates an instance of the operator that generates a characteristic zone body 
 */
ExportedByCATCGMVolumetricSweepCmp CATTopCharacteristicZone *CATCreateTopCharacteristicZone(
    CATGeoFactory      * ipFactory,
    CATTopData         * ipTopData,
    CATBody            * ipSweepBody,
    CATBodyMotion const& iBodyMotion,
    double               iTime,
    int                  iIngressOrEgressOrChar);

ExportedByCATCGMVolumetricSweepCmp void DeleteCATTopCharacteristicZoneOperator( CATTopCharacteristicZone*& op );

#endif /* CATTopCharacteristicZone_h */
