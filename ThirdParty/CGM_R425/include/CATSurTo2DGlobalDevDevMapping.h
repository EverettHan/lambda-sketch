/*
=============================================================================

  COPYRIGHT   : DASSAULT SYSTEMES 1999       
  //==========================================================================
  DESCRIPTION 
  
    // CATSurTo2DGlobalDevDevMapping:
    // derives from CATSurTo2DGlobalMapping
    //
    //==========================================================================
    //
    // Usage notes:
    //      This virtual Object describes the mapping between one set of CATSurface and a
    //       virtual  2 dimension space defined by an axis 
    //       
    //Methods : 
    //             - CreateLocalMapping 
    //
    //==========================================================================
    // August     99     Creation                                    OB       
    // May        01     Amelioration precision                      NDN
    // 29/09/03 NLD gestion de la softwareconfiguration
    //========================================================================== 
    //
*/  
#ifndef CATSurTo2DGlobalDevDevMapping_H
#define CATSurTo2DGlobalDevDevMapping_H 

#include "CATSurTo2DGlobalMapping.h"
#include "FrFAdvancedObjects.h"
#include "CATMathLine.h"
#include "CATMathAxis.h"
#include "CATFrFCCvParam.h" 
class CATFrFCompositeCurveMapping; 
class CATFrFCompositeCurve; 
class CATSoftwareConfiguration;

//----------------------------------------------------------------------------
class ExportedByFrFAdvancedObjects CATSurTo2DGlobalDevDevMapping: public CATSurTo2DGlobalMapping
{ 
  CATCGMVirtualDeclareClass(CATSurTo2DGlobalDevDevMapping);
public :
  //-------------
  // Constructor
  //-------------
  CATSurTo2DGlobalDevDevMapping ( CATGeoFactory *iFactory,
                                  CATSoftwareConfiguration* iConfig,
                                  CATFrFCompositeCurve *iIsoUWire, 
                                  const CATMathAxis &iAxisOnSupport,  
                                  double  iShellMappingOrientation, 
                                  const CATMathLine &iRevolAxis) ;
  //-------------
  // Destructor
  //-------------
  ~CATSurTo2DGlobalDevDevMapping();
  //-------------
  
  //-------------
  // Methods
  //-------------
  //  Create LocalMapping 
  
  CATSurTo2DMapping *  CreateLocalMapping(CATSurface * iLocalReference ,
                                          const double & iRefOrientation,
                                          const CATSurLimits &iRefLimits ) const;
  
  //----------------------
  // Set and Get Methods 
  //----------------------   
  //  Set Radiantness ( this is a neologism : tentative translation from french rayonnance which is itself a nelologism)
  //  Transformation of output X and Y as follows :
  //  X'= X    and Y' = (R+Y*Radiantness)*X / (R + Y)  ;R being the Radius at Invariant point .
  
  void SetRadiantness(double iRadiantness ) {_Radiantness=iRadiantness;}; 
  
  //  Set Inclination ( Radian)
  //  Transformation of output X and Y as follows :
  //  X'= X    and Y' = Y + X*tan(Inclination)
  //  Rq : Inclinaison is applied first then Radiantness.
  
  void SetInclination(double iInclination )  {_Inclination=iInclination;}; 
  //  Set Inversion
  //  Inversion of the X according to the standard axis on support 
  //  standard axis on Support depends itself on mapping mode in Create  ( implicit (outside) or 
  //   Explicte according to Shell normal.
  
  void SetInversion(double iInversion )  {_Inversion=iInversion;}; 
  
  //  Get Inversion
  //  Inversion of the X according to the standard axis on support 
  //  standard axis on Support depends itself on mapping mode in Create  ( implicit (outside) or 
  //   Explicte according to Shell normal.
  
  double GetInversion()  {return _Inversion;}; 
  
  //  Able or disable fast run operator.
  //  To enhance performance, for preview mode for example
  //  Default is accuracy run mode (with worse accuracy, iAccuracy=0).
  
  void SetPerformanceMode(CATLONG32 iAccuracy=0);
  
  //  Able or disable InvertMode.
  //  This option allow you to invert the way operations are done.
  //  First develop will be done along axis direction, and then along
  //  circle direction.
  //  Default is FALSE.
  void SetInvertDevDevOption(CATBoolean iSet=TRUE);

  CATBoolean GetInvertDevDevOption();

protected :

//  Stream and UnStream Utilities
virtual void GetCreatorId(CATString& oCreatorId, CATString& oSharedLibId) const;
virtual void Write(CATCGMStream& Str) const;
void Dump( CATCGMOutput& os );

private :
  
  //----------------------
  // DATA 
  //----------------------  
  // global data 
  CATFrFCompositeCurve * _GlobalIsoOnV; 
  CATFrFCompositeCurveMapping *_GlobalSOnV;
  double _SMappingOrientation ;
  double _ShellMappingOrientation ;
  CATMathPoint _InvariantPoint;
  double _InvariantS;
  double _Inversion;
  double _Radiantness;
  double _Inclination;
  const CATMathLine _RevolAxis;
  CATFrFCCvParam _CCVParam;
  CATLONG32 _Mode;
  CATBoolean _InvertDev;
  
  CATMathAxis _AxisOnSupport;
};
#endif
