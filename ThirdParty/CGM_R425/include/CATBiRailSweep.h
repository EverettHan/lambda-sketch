// COPYRIGHT DASSAULT SYSTEMES 1998
//==========================================================================
//
// CATBiRailSweep:
// Interface class of the SWEEP Operator.
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for simple Generalized Sweep or derived
// in order to implement specific algorithm or capabilities.
//
//==========================================================================
// April 98     Creation                       JBX
// 16/05/00 NLD Ajout GetProfileOrientation()
// 30/01/01 CPL Ajout SetAnchorPoints
// 28/02/01 CPL Ajout SetCouplingType
// 26 10 03 MNA Ajout de SetIndexOfPackedcrvInCcvProfile (Pour le Sweep Checker)
//==========================================================================

#ifndef CATBiRailSweep_H
#define CATBiRailSweep_H

#include <CATGeneralizedSweepSurface.h>
#include <FrFAdvancedOpeSur.h>
#include <CATMathDef.h>

#include <CreateBiRailSweep.h>
#include <CATCouplingType.h>

class CATSurface;
class CATLaw;
class CATMathAxis;
class CATFrFCompositeCurve;
class CATGeometry;
class CATCurve;
class CATGeoFactory;
class CATMathTransformation;
class CATMathDirection;
class CATFrFProfile;

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedOpeSur CATBiRailSweep : public CATGeneralizedSweepSurface
{
  public :

    virtual ~CATBiRailSweep();

    //----------------------------
    // Set the Sweep Configuration
    //----------------------------

    virtual void SetMovingFrameType(int MvFrType = 4 ,
                                    const CATMathDirection * Dir =0 ) =0;

    virtual void SetProfilePositionType(CATLONG32 iPositionType) = 0;

    virtual void SetAnchorPoints( const CATMathPoint& iPoint1,
                                  const CATMathPoint& iPoint2 ) = 0;

        //--------------
    //INFOS SWEEPCHECKER
    //--------------

    virtual void SetIndexOfPackedcrvInCcvProfile(CATListOfInt * iListOfPackedcrvInCcv)= 0;


    // Gives 1 when profile goes from first to second guide,
    // and -1 if not
    virtual int GetProfileOrientation() = 0;

    void SetCouplingType( CATCouplingType iType );

    virtual void SetProfileScalingOption(CATLONG32 iActivate=0) = 0; //Default is iActivate=1 (means "active" scaling).
};

#endif
