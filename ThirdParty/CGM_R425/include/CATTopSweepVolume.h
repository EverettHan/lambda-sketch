#ifndef CATTopSweepVolume_H
#define CATTopSweepVolume_H

// COPYRIGHT DASSAULT SYSTEMES  2014

/**
 * @level Protected
 * @usage U1
 */ 
#include "CATCGMVolumetricSweepCmp.h" // NLD260917 #include "AdvVolSweep.h"
#include "CATTopOperator.h"


#include "CATCGMOperatorDebug.h"

#include "CATBodyMotion.h"
#include "CATListOfDouble.h"
#include "CATMathPlane.h"
#include "CATLISTV_CATMathPoint2D.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATlsoProgressBarManager;
class CATMathVector;
class CATMathPoint;
class CATMathInterval;
class SweepVolumeResultHandler;

/**
 * @nodoc
 * Class defining the operator that sweeps a smooth axisymmetric body according to the given sweeping object.
 * <br><b>Role:</b> The sweeping object defines the body motion path.
 * <ul>
 *   <li> A <tt>CATICGMTopSweepVolume</tt> operator is created with the <tt>CATCGMCreateTopSweepVolume</tt> global function. 
 *   <li> It is the user's responsibility to release the operator with the <tt>Release</tt> method after it has been used.
 * </ul>
 */
class ExportedByCATCGMVolumetricSweepCmp CATTopSweepVolume : public CATTopOperator
{
    CATCGMVirtualDeclareClass( CATTopSweepVolume );

    friend ExportedByCATCGMVolumetricSweepCmp CATTopSweepVolume * CATCreateTopSweepVolume(
                                                        CATGeoFactory                  * ipFactory,
                                                        CATTopData                     * ipTopData,
                                                        CATLISTV(CATMathPoint2D) const & iBodyProfilePoints,
                                                        CATListOfDouble          const & iBodyProfileRadii,
                                                        CATMathPoint             const & iBodyAxisOrigin,
                                                        CATMathVector            const & iBodyAxisDirection,
                                                        CATBodyMotion            const & iBodyMotion
                                                        );

    friend ExportedByCATCGMVolumetricSweepCmp CATTopSweepVolume * CATCreateTopSweepVolume(
                                                        CATGeoFactory       * ipFactory,
                                                        CATTopData          * ipTopData,
                                                        CATBody             * ipProfileWire,
                                                        CATMathPoint  const & iBodyAxisOrigin,
                                                        CATMathVector const & iBodyAxisDirection,
                                                        CATBodyMotion const & iBodyMotion
                                                        );

    friend ExportedByCATCGMVolumetricSweepCmp CATTopSweepVolume * CATCreateTopSweepVolume(
                                                        CATGeoFactory                  * ipFactory,
                                                        CATTopData                     * ipTopData,
                                                        CATLISTV(CATMathPoint2D) const & iBodyProfilePoints,
                                                        CATListOfDouble          const & iBodyProfileRadii,
                                                        CATMathPlane             const & iBodyTargetPlane,
                                                        CATBodyMotion            const & iBodyMotion
                                                        );

    friend ExportedByCATCGMVolumetricSweepCmp CATTopSweepVolume * CATCreateTopSweepVolume(
                                                        CATGeoFactory                  * ipFactory,
                                                        CATTopData                     * ipTopData,
                                                        CATBody                        * ipProfileWire,
                                                        CATMathPlane             const & iBodyRefPlane,
                                                        CATMathPlane             const & iBodyTargetPlane,
                                                        CATBodyMotion            const & iBodyMotion
                                                        );

public :
    /**
    * Destructor.
    */
    virtual ~CATTopSweepVolume() ;

    void SetSpecialXmlMode() { _vswpXmlMode = TRUE; }

    /**
     * @nodoc
    */
    void SetOpVersion( short iVer ) { _VolSwpOpVersion = iVer; }

protected:
    
    CATTopSweepVolume(
                CATGeoFactory                  * ipFactory,
                CATTopData                     * ipTopData,
                CATLISTV(CATMathPoint2D) const & iBodyProfilePoints,
                CATListOfDouble          const & iBodyProfileRadii,
                CATMathPlane             const & iBodyTargetPlane,
                CATBodyMotion            const & iBodyMotion
                );

    CATTopSweepVolume(
                CATGeoFactory       * ipFactory,
                CATTopData          * ipTopData,
                CATBody             * ipProfileWire,
                CATMathPlane  const & iBodyRefPlane,
                CATMathPlane  const & iBodyTargetPlane,
                CATBodyMotion const & iBodyMotion
                );

    CATCGMOperatorDebugDeclareRun( CATTopSweepVolume, CATCGMOperator );
    int RunOperator();

public:

    /** @nodoc @nocgmitf */
    static const CATString* GetDefaultOperatorId() { return & _OperatorId; };
    /** @nodoc @nocgmitf */
    //void ReadInput(CATCGMStream& Str, CATGeoFactory* iGeoFactory);
    /** @nodoc @nocgmitf */
    void SetRefPlaneInfoForStream(const CATMathPoint& RefPlaneOrigin,
                                  const CATMathVector& RefPlaneDir1,
                                  const CATMathVector& RefPlaneDir2);
     /** @nodoc @nocgmitf */
    void SetTargetPlaneInfoForStream(const CATMathPoint& TargetPlaneOrigin,
                                     const CATMathVector& TargetPlaneDir1,
                                     const CATMathVector& TargetPlaneDir2);

protected :

    // Inputs for the axisymmetric body case.

    CATLISTV(CATMathPoint2D)  _bodyProfilePoints;
    CATListOfDouble           _bodyProfileRadii;
    CATBody                 * _pProfileWire;

    // The reference and target planes of the profile of the 
    // axisymmetric body.
    
    CATMathPlane              _profileRefPlane, _profileTargetPlane;

    // The sweep body motion definition.

    CATBodyMotion _bodyMotion;
    
    // List of objects used by the CATBodyMotion
    
    CATLISTP(CATICGMObject) _listOfBodyMotionObj;

    // A temporarily variable till we merge all the entry points.

    CATBoolean _vswpXmlMode;

    // The version of the volumetric sweep operator.

    short _VolSwpOpVersion;

private :

    void Init();
    static CATString _OperatorId;

    CATlsoProgressBarManager * _ProgressBarManager;

    SweepVolumeResultHandler * 
    ComputeCATTopSweepVolume( CATMathInterval const & TDm,
                              CATTopData            & topData );
          int Run2();
    CATMathPoint  _RefPlaneOrigin,
                  _TargetPlaneOrigin;
    CATMathVector _RefPlaneD1,
                  _RefPlaneD2,
                  _TargetPlaneD1,
                  _TargetPlaneD2;


  // SweepVolumeResultHandler *  ComputeCATTopSweepVolume2(CATMathInterval const  & TDm,CATTopData & topdata);
    // CATCGMOperator infrastructure
public:

protected: 

    const CATString * GetOperatorId();
    void              Dump(CATCGMOutput& os);
    CATCGMOperator::CATCheckDiagnostic CheckInput(CATCGMOutput & os);
    void             WriteInput(CATCGMStream  & ioStream);
    //void DumpOutput(CATCGMOutput &os);
    CATCGMOperator::CATCheckDiagnostic CheckOutput(CATCGMOutput & os);
    //void WriteOutput(CATCGMStream & ioStream);
    //void DumpOutput(CATCGMStream& ioStream, CATCGMOutput& os, int VersionNumber);
    //CATBoolean ValidateOutput(CATCGMStream& ioStream, CATCGMOutput & os, int VersionNumber);
    CATBoolean ValidateTopOutput(CATTopCheckJournal* iEquivalent,CATCGMOutput& os);  

    //CATCGMOperator::CATCheckDiagnostic CheckOutput( CATCGMOutput & oStr );

protected:

    CATExtCGMReplay * IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
    void              RequireDefinitionOfInputAndOutputObjects();
};

/**
* Creates an instance of the volumetric sweep operator for a smooth axisymmetric body.
* @param ipFactory
* The pointer to the factory.
* @param ipTopData
* The pointer to the <tt>CATTopData</tt>.
* @param iBodyProfilePoints
* The profile points defining linear segments for the axisymmetric body.
* @param iBodyProfileRadii
* The filleting radius values between consecutive segments of the profile for the axisymmetric body.
* @param iBodyAxisOrigin
* The origin of the axis about which to revolve the profile.
* @param iBodyAxisDirection
* The direction of the axis about which to revolve the profile.
* @param iBodyMotion
* The <tt>CATBodyMotion</tt> object to use for sweeping.
* @return [out, IUnknown#Release]
* The pointer to the created operator. Delete with the usual C++ delete operator after use.
*/  
ExportedByCATCGMVolumetricSweepCmp CATTopSweepVolume * 
CATCreateTopSweepVolume(
                CATGeoFactory                  * ipFactory,
                CATTopData                     * ipTopData,
                CATLISTV(CATMathPoint2D) const & iBodyProfilePoints,
                CATListOfDouble          const & iBodyProfileRadii,
                CATMathPoint             const & iBodyAxisOrigin,
                CATMathVector            const & iBodyAxisDirection,
                CATBodyMotion            const & iBodyMotion
                );

/**
* Creates an instance of the volumetric sweep operator for a smooth axisymmetric body.
* @param ipFactory
* The pointer to the factory.
* @param ipTopData
* The pointer to the <tt>CATTopData</tt>.
* @param ipProfileWire
* The profile of the axisymmetric body.
* @param iBodyAxisOrigin
* The origin of the axis about which to revolve the profile.
* @param iBodyAxisDirection
* The direction of the axis about which to revolve the profile.
* @param iBodyMotion
* The <tt>CATBodyMotion</tt> object to use for sweeping.
* @return [out, IUnknown#Release]
* The pointer to the created operator. Delete with the usual C++ delete operator after use.
*/  
ExportedByCATCGMVolumetricSweepCmp CATTopSweepVolume * 
CATCreateTopSweepVolume(
                    CATGeoFactory       * ipFactory,
                    CATTopData          * ipTopData,
                    CATBody             * ipProfileWire,
                    CATMathPoint  const & iBodyAxisOrigin,
                    CATMathVector const & iBodyAxisDirection,
                    CATBodyMotion const & iBodyMotion
                    );

/**
* Creates an instance of the volumetric sweep operator for a smooth axisymmetric body.
* @param ipFactory
* The pointer to the factory.
* @param ipTopData
* The pointer to the <tt>CATTopData</tt>.
* @param iBodyProfilePoints
* The profile points defining linear segments for the axisymmetric body.
* @param iBodyProfileRadii
* The filleting radius values between consecutive segments of the profile for the axisymmetric body.
* @param iBodyTargetPlane
* The target plane representing initial position of the profile plane. The first vector corresponds to axis of symmetry.
* @param iBodyMotion
* The <tt>CATBodyMotion</tt> object to use for sweeping.
* @return [out, IUnknown#Release]
* The pointer to the created operator. Delete with the usual C++ delete operator after use.
*/  
ExportedByCATCGMVolumetricSweepCmp CATTopSweepVolume * 
CATCreateTopSweepVolume(
                CATGeoFactory                  * ipFactory,
                CATTopData                     * ipTopData,
                CATLISTV(CATMathPoint2D) const & iBodyProfilePoints,
                CATListOfDouble          const & iBodyProfileRadii,
                CATMathPlane             const & iBodyTargetPlane,
                CATBodyMotion            const & iBodyMotion
                );

/**
* Creates an instance of the volumetric sweep operator for a smooth axisymmetric body.
* @param ipFactory
* The pointer to the factory.
* @param ipTopData
* The pointer to the <tt>CATTopData</tt>.
* @param ipProfileWire
* The profile of the axisymmetric body.
* @param iBodyRefPlane
* The plane in which the profile wire is defined. The first vector corresponds to axis of symmetry.
* @param iBodyTargetPlane
* The target plane representing initial position of the profile plane. The first vector corresponds to axis of symmetry.
* @param iBodyMotion
* The <tt>CATBodyMotion</tt> object to use for sweeping.
* @return [out, IUnknown#Release]
* The pointer to the created operator. Delete with the usual C++ delete operator after use.
*/  
ExportedByCATCGMVolumetricSweepCmp CATTopSweepVolume * 
CATCreateTopSweepVolume(
                    CATGeoFactory       * ipFactory,
                    CATTopData          * ipTopData,
                    CATBody             * ipProfileWire,
                    CATMathPlane  const & iBodyRefPlane,
                    CATMathPlane  const & iBodyTargetPlane,
                    CATBodyMotion const & iBodyMotion
                    );

#endif 





