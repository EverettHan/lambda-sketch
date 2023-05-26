// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATSurfaceFlattener.h
// Header definition of CATSurfaceFlattener
//
//===================================================================
//
// Usage notes: Operator to develop/flatten a ruled/torus surface
//            with support for zero radius bends
//
// This is an abstract interface for the operator to develop/flatten 
// the surface which may be ruled or torus. 
// It is derived from CATGeoOperator. 
// It is created by the global method CreateSurfaceFlattener
//
//===================================================================
//
//  11:10:05  Creation               S9L
//  11:10:05  Modification           S9L
//
//===================================================================

#ifndef CATSurfaceFlattener_H
#define CATSurfaceFlattener_H

#include "FrFOpeSur.h"

#include "CATGeoOperator.h"
#include "CATSkillValue.h"
#include "CATCrvLimits.h"
#include "CATString.h"
#include "CATDevelopRuledSurface.h"

class CATCurve;
class CATSurface;
class CATNurbsSurface;
class CATGeoFactory;
class CATMathPoint;
class CATPlane;
class CATMathAxis;

// The enumeration provides the various available alternatives for flattening. 
// The value CATDevelopRotation indicates non-developable surface flattening by rotation, 
// while CATDevelopProjection indicates flattening by projection.
//enum CATDevelopMethod; {CATDevelopRotation, CATDevelopProjection};

//-----------------------------------------------------------------------
//
// Operator of flattening ruled/torus surfaces with zero radius bend support
//
 
class ExportedByFrFOpeSur CATSurfaceFlattener : public CATGeoOperator
{
public:
   //
   // Constructor
   //
   CATSurfaceFlattener(CATGeoFactory * iFactory);

   //
   // Destructor
   //
   virtual ~CATSurfaceFlattener ();

   //
   // This method provides the surface to be flattened, which may be ruled, torus or even planar
   //
   virtual void SetSurfaceToFlatten(const CATSurface * ipSurface, const CATSurLimits &iSurLimits, const CATBoolean iIsConstrainedRuled = FALSE) = 0;   

   //
   // This method provides choice for develop process of ruled or torus surface. 
   // The choice modifies the develop process of non-developable ruled surfaces. 
   // Presently, the choice has no effect on the develop process of torus or developable ruled surfaces.
   // iMethod = CATDevelopRotation - Flattening by rotation
   // iMethod = CATDevelopProjection - Flattening by projection      
   //
   virtual void SetDevelopMethod(const CATDevelopMethod iMethod) = 0; 

   //
   // This method sets the stretch factor for the surface being flattened. 
   // By default the stretch factor is -1.0. 
   // The negative value of stretch factor indicates that no stretching would happen during the develop process.
   //
   virtual void SetStretchRatio(const double iStrectch) = 0;  

   //
   // This method sets the length of profile curve used for sweep(by default it is unity for ruled surfaces)
   //
   virtual void SetProfileLength(const double iProfileLength) = 0;  

   //
   // This method sets the source profile axis
   //
   virtual void SetSourceAxis(const CATMathAxis & iSourceAxis) = 0;  

   //
   // This method sets the target profile axis
   //
   virtual void SetTargetAxis(const CATMathAxis & iTargetAxis) = 0;  

   //
   // This method provides the curve indicating the geometry of the edge in the folded body, 
   // which is common to the previous face and the current face being flattened.
   //
   virtual void SetOriginalCurve(const CATPCurve * iCurve, const CATCrvLimits &iCrvLimits) = 0;     
   
   //
   // Run operator - This method performs the unfold operation on the input surface to be flattened.
   //
   virtual int Run() = 0;

   //
   // Restore the result - This method gets the resulting flattened surface after the develop process.
   //
   virtual CATSurface * GetResult() = 0;   

   //
   // This method transfers a curve lying on the input surface to the resulting flattened surface. 
   // It takes an interface pointes and parametric domain of the curve to be transferred 
   // and yields the interface pointer and parametric domain of its image on the flattened surface.
   //
   virtual CATPCurve * TransferPCurve(               
                              const CATSurface *   ipOriginalSurface,
                              const CATSurface *   ipFlattenedSurface,
                              const CATPCurve  *   ipOriginalPCurve, 
                                    CATPCurve  *&  opImagePCurve, 
                                    double         iTolerance = -1.0) const = 0;
};


ExportedByFrFOpeSur CATSurfaceFlattener  *   CreateSurfaceFlattener(             
                                                         CATGeoFactory            * iFactory, 
                                                         CATSoftwareConfiguration * iSoftwareConfiguration,
                                                   const CATPCurve                * iCurve,
                                                   const CATCrvLimits              &iCrvLimits,
                                                   const CATPlane                 * iPlane,
                                                         CATSkillValue              iMode = ADVANCED);

//-----------------------------------------------------------------------

#endif
