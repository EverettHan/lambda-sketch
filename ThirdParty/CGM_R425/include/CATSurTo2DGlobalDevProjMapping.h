 /*
=============================================================================

 COPYRIGHT   : DASSAULT SYSTEMES 1999       
//==========================================================================
 DESCRIPTION 

// CATSurTo2DGlobalDevProjMapping:
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
// 29/09/03 NLD Gestion de la softwareconfiguration
// 06/12/10 JSX Drole de gestion : _Config existe aussi dans la classe mere
//                je renome en ConfigPrivate
//              au dessus du level CGM_Versionning_WireDevProj_ReduceNewtonDomainOnPifPaf
//              la config est gerée par la classe mere. Je surcharge GetSoftwareConfiguration() pour gerer cela . 
//              (avant la config de la classe mere etait nulle)
//              Prise en compte dans le CGMReplay
//========================================================================== 
//
*/  
#ifndef CATSurTo2DGlobalDevProjMapping_H
#define CATSurTo2DGlobalDevProjMapping_H 
 
#include "CATSurTo2DGlobalMapping.h"
#include "FrFAdvancedObjects.h"

#include "CATMath.h" 
#include "CATMathLine.h" 
#include "CATMathAxis.h" 
#include "CATCGMOutput.h"

class CATFrFCompositeCurveMapping; 
class CATFrFCompositeCurve; 
class CATWire; 
class CATVertex;  
class CATSoftwareConfiguration;
 
 

//----------------------------------------------------------------------------
class ExportedByFrFAdvancedObjects CATSurTo2DGlobalDevProjMapping: public CATSurTo2DGlobalMapping
{ 
  CATCGMVirtualDeclareClass(CATSurTo2DGlobalDevProjMapping);
 public :
 //-------------
 // Constructor
 //-------------
 CATSurTo2DGlobalDevProjMapping ( CATGeoFactory *iFactory, 
                                  CATSoftwareConfiguration* iSoftwareConfiguration,
                            const CATMathAxis &iAxisOnSupport,  
                            const CATMathLine &iRevolAxis,
                            const double iRadius) ;
 //-------------
 // Destructor
 //-------------
 ~CATSurTo2DGlobalDevProjMapping();
 //-------------
 
 //-------------
 // Methods
 //-------------
 //  Create LocalMapping 
 
 CATSurTo2DMapping *  CreateLocalMapping(CATSurface * iLocalReference ,
 const double & iRefOrientation,
 const CATSurLimits &iRefLimits) const; 

 CATSoftwareConfiguration *GetSoftwareConfiguration() const;

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

 void SetInclination(double iInclination )  {_Inclination=CATTan(iInclination);}; 
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
 CATMathPoint _InvariantPoint;
 CATMathAxis _CircleAxis; 
 double _Radius;
 double _Inversion;
 double _Radiantness;
 double _Inclination;
 const CATMathLine _RevolAxis;
 CATSoftwareConfiguration* _ConfigPRIVATE ;
 CATMathAxis _AxisOnSupport;
};
#endif
