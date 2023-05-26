#ifndef VolumetricSweepFunctions_H
#define VolumetricSweepFunctions_H

// COPYRIGHT DASSAULT SYSTEMES 2014

#include "CATCGMVolumetricSweepCmp.h" // NLD260917 #include "AdvVolSweep.h"

#include "CATBoolean.h"
#include "CATListOfCATCurves.h"

class CATMathPoint;
class CATMathVector;

class CATMathTransformation;

class CATGeoFactory;
class CATTopData;
class CATSoftwareConfiguration;
class CATBody;
class CATEdge;

class VswpInterpPathDef;
class VswpCircularPathDef;

class VswpAxisymBodyDef;
class VswpRotSurfDef;
class CATBodyMotion;



// Given a motion definition, transform the swept body to the given
// time instant.

ExportedByCATCGMVolumetricSweepCmp CATBody *
VolumetricSweepCreateMotionSnapshot( 
                            CATGeoFactory      *  ipFactory,
                            CATTopData         *  ipTopData,
                            CATBodyMotion const & iBodyMotion,
                            double                iTime,
                            CATBody            *  ipBodyToTransform,
                            CATBoolean            EvalBelow = FALSE
                            );

// Create a planar skin from the profile definition.

ExportedByCATCGMVolumetricSweepCmp CATBody * 
VolumetricSweepCreateAxiSymProfile( 
                        CATGeoFactory          *  iFactory,
                        CATTopData             *  iTopData,
                        VswpRotSurfDef   const  & iRotSf,
                        CATBoolean                Simplify,
                        double           const    Eps
                        );

ExportedByCATCGMVolumetricSweepCmp CATBody * 
VolumetricSweepCreateAxiSymProfile( 
                        CATGeoFactory          *  iFactory,
                        CATTopData             *  iTopData,
                        VswpRotSurfDef    const & iRotSf,
                        CATBoolean                Simplify,
                        double            const   Eps,
                        double            const   ProfileResolution,
                        CATBoolean                ReturnWire = FALSE
                        );

// Create an axisymmetric body from a profile and axis of symmetry.

ExportedByCATCGMVolumetricSweepCmp CATBody * 
VolumetricSweepCreateAxiSym( 
                    CATGeoFactory              *  pFactory,
                    CATTopData                 *  pTopData,
                    VswpRotSurfDef        const & iDef,
                    CATBoolean                    Simplify,
                    double                const   Eps
                    );
ExportedByCATCGMVolumetricSweepCmp CATBody * 
VolumetricSweepCreateAxiSym( 
                    CATGeoFactory              *  pFactory,
                    CATTopData                 *  pTopData,
                    VswpRotSurfDef        const & iDef,
                    CATBoolean                    Simplify,
                    double                const   Eps,
                    double                const   ProfileResolution,
                    CATBoolean                    ReturnWire = FALSE
                    );

// Create the sweep boundary curve starting from the specified vertex
// of the initial characteristic zone of a sweep.

ExportedByCATCGMVolumetricSweepCmp void
VolumetricSweepCreateBndryCurve(        
                        CATBody                *  ipSheetBdy,
                        VswpAxisymBodyDef const & iBodyToSweep,
                        CATEdge                *  ipSheetBndryEdge,
                        CATBoolean                iVertexAtStart,
                        CATBodyMotion     const & iBodyMotion,
                        double            const & iStartTime,
                        CATBoolean                iFwd,
                        CATGeoFactory          *  ipFactory,
                        CATSoftwareConfiguration * ipConfig,
                        CATCurve               *& opBndryCu
                        );

// Create the sweep SEDE curves from the given edge of the 
// initial characteristic zone of a sweep.

ExportedByCATCGMVolumetricSweepCmp void 
VolumetricSweepCreateSedeCurves(                        
                        CATEdge                *  pSheetBndryEdge,
                        CATBody                *  pSheetBdy,
                        VswpAxisymBodyDef const & iWhDef,
                        CATBodyMotion     const & iBodyMotion,
                        CATBoolean                OrthoParameterization,
                        CATBoolean                SubsetToEdge,
                        CATGeoFactory          *  pFactory,
                        CATTopData             *  pTopData,
                        CATSoftwareConfiguration * pConfig,
                        CATListPtrCATCurve      & oSedeCurves
                        );

#endif


