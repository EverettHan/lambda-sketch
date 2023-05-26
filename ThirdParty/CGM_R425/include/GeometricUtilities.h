#ifndef GeometricUtilities_H
#define GeometricUtilities_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "RibbonLight.h"
#include "CATMath.h"
//#include "GeometricBasic.h"
#include "CATCrvParam.h"
#include "CATSurParam.h"

class CATMathVector;
class CATMathDirection;
class CATMathTransformation;
class CATMathBox;
class CATMathPoint;

class CATCrvLimits;
class CATSurLimits;
class CATCurve;
class CATSurface;

// S9L : Start
class CATMathSetOfPointsND;
// S9L : End

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATCGMOutput;

typedef int CATPositionOnLimits;
const int Inside       = 0;                   // =  0000
const int Outside      = 16;                  // = 10000
const int BrdrUMin     = 1;                   // =  0001
const int BrdrUMax     = 2;                   // =  0010
const int BrdrVMin     = 4;                   // =  0100
const int BrdrVMax     = 8;                   // =  1000
const int CrnrUMinVMin = BrdrUMin | BrdrVMin; // =  0101
const int CrnrUMinVMax = BrdrUMin | BrdrVMax; // =  1001
const int CrnrUMaxVMin = BrdrUMax | BrdrVMin; // =  0110
const int CrnrUMaxVMax = BrdrUMax | BrdrVMax; // =  1010
const int BrdrU        =  3;                  // =  0011
const int BrdrV        = 12;                  // =  1100
const int Brdr         = 15;                  // =  1111


ExportedByRibbonLight CATBoolean IsParamIncludedInPLine(CATGeoFactory* iFactory, 
                                                   CATSoftwareConfiguration* iConfig, 
                                                   CATSurface* iSurface, 
                                                   const double iTol,
                                                   CATSurParam &iParam, 
                                                   CATSurParam &iStartParam, 
                                                   CATSurParam &iEndParam);

//------------------------------------------------------------------------------
// Compute the extension of CATMathBox in a given direction
//------------------------------------------------------------------------------

ExportedByRibbonLight void ComputeBoxExtension (CATMathDirection &iDirection,
                                           CATMathBox       &iMathBox,
                                           double           &oExtension,
                                           double           *oMinHeight=NULL,
                                           double           *oMaxHeight=NULL,
                                           CATMathVector    *iReferenceVector=NULL);


//------------------------------------------------------------------------------
// Resize the box if it is bigger than the model size
//------------------------------------------------------------------------------

ExportedByRibbonLight void ComputeBoxWithinMaxLimits (CATMathBox &iMathBox,
                                                 double      iModelSize);

//------------------------------------------------------------------------------
// First order estimate of surface limits that make it possible to intersect
// a given 3D box
//------------------------------------------------------------------------------

ExportedByRibbonLight CATBoolean GetExtrapolSurfaceHeuristicLimits(CATSurface   *iSurface,
                                                              CATSurLimits &iSurLimits,
                                                              CATSurParam  &iSurParam,
                                                              const CATMathBox  &iBoxToCross,
                                                              CATSurLimits &oNewSurLimits);

//------------------------------------------------------------------------------
// Generate a cylindrical box of a CATMathBox for a given direction
//------------------------------------------------------------------------------
ExportedByRibbonLight void ComputeCylinderBox (const CATMathBox       &iMathBox,
                                          const CATMathDirection &iDirection,
                                          CATMathPoint           &oLowCylinderCenterPoint,
                                          double                 &oCylinderRadius,
                                          double                 &oCylinderHeight);

//------------------------------------------------------------------------------
// Dump a CATMathTransformation
//------------------------------------------------------------------------------
ExportedByRibbonLight void DumpTransformation(const CATMathTransformation &iTransfo, CATCGMOutput& os);

// S9L : Start
//------------------------------------------------------------------------------
// Tesselate a curve
//------------------------------------------------------------------------------
ExportedByRibbonLight void CurveTessellation(CATGeoFactory         *  ipFactory,
																						 CATCurve              *  ipCurve, 
																						 CATMathSetOfPointsND  *& opMeshPoints, // 3D points
																						 CATMathSetOfPointsND  *& opCrvParams,  // 1D points
																						 double                   iSag);
// S9L : End
//------------------------------------------------------------------------------

#endif
