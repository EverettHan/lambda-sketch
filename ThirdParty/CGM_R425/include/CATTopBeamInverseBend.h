/* -*-C++-*- */

#ifndef CATTopBeamInverseBend_H
#define CATTopBeamInverseBend_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//------------------------------------------------------------------------------
//
// Computes a set of Line inside a Beam to check further Bending
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// September 2006    Creation                         R. Rorato
//------------------------------------------------------------------------------

#include "BOIMPOPE.h"
#include "CATListOfDouble.h"
#include "CATListOfInt.h"
#include "CATListOfCATPCurves.h"
#include "CATMathDef.h"
#include "CATPGMTopBeamInverseBend.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATBody;
class CATWire;
class CATMathPoint;
class CATMathVector;
class CATPlane;

class ExportedByBOIMPOPE CATTopBeamInverseBend: public CATPGMTopBeamInverseBend
{
 public:

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATTopBeamInverseBend(CATGeoFactory*            iWorkingFactory,
                        CATSoftwareConfiguration* iConfig,
                        CATBody*                  iBeamWire,           // Wire of Beam, the Body must contain one and only one Wire
                        CATPlane*                 iBeamSupportPlane,   // Support Plane of the Beam
                        const CATLength           iBeamThicknesses[2], // Position of Beam Limits wersus Wire (Positive in (Tangent to Wire)^(normal to plane) Direction
                        const CATPositiveLength   iMaxLineLength,      // Line Length will not be greater than iMaxLineLength (Length is measured along BeamWire). iMaxLineLength>2*iLineOverlap
                        const CATPositiveLength   iLineOverlap    );   // Length of Overlap between adjacent Lines (Length is measured along BeamWire)

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  ~CATTopBeamInverseBend();
 
  //------------------------------------------------------------------------------
  // Get Number of Lines
  //------------------------------------------------------------------------------
  int GetNumberOfLines(); 

  //------------------------------------------------------------------------------
  // Get One Line
  // UV are parameters on iBeamSupportPlane
  // 1 <= iPointIndex <= LinesNumber
  //------------------------------------------------------------------------------
  void GetLine(const int iPointIndex, double & UStart,  double & VStart, double & UEnd,  double & VEnd); 

  //------------------------------------------------------------------------------
  // Find Out Beam SupportPlane from Beam Wire
  //------------------------------------------------------------------------------
  static CATPlane* FindOutBeamSupportPlane(CATSoftwareConfiguration* iConfig, CATBody* iBeamWire);


  //------------------------------------------------------------------------------

private :

  void              Run();
  void              ComputeDataOnce();
  void              EvalOffsetPoint(const double W, const CATPositiveLength iOffset, CATMathPoint &oPoint, CATMathVector &oTangent);
  int               EvalTangentPoint(const CATMathPoint &iPoint, const CATMathVector &iTangent, double &oW);
  int               EvalIntersectionPoint(const CATMathPoint &iPoint, const CATMathVector &iTangent, double &oW);
  CATPositiveLength EvalLengthFromParam(const int iCurveIndex, const double iParam);
  static CATWire*   FindOutWire(CATBody* iBeamWire);


  CATGeoFactory*            _Factory;
  CATSoftwareConfiguration* _Config;
  CATBody*                  _Wire;    
  CATPlane*                 _Plane;   
  CATPositiveLength         _Offset[2]; // _Offset[0] is offset in inside direction, _Offset[1] is offset in outside direction,     
  CATPositiveLength         _MaxLineLength;
  CATPositiveLength         _Overlap; 
  CATListOfDouble           _W[2];    // Ratios (between 0. & 1.) of points on Wire, Line[i] goes from _W[0][i] to _W[1][i]
  CATLISTP(CATPCurve)       _Curves;
  CATListOfInt              _Orns;
  CATListOfDouble           _Params[2];
  CATListOfDouble           _Lengthes;
  CATPositiveLength         _WireLength;
  CATBoolean                _Run;

  //------------------------------------------------------------------------------

};
#endif
