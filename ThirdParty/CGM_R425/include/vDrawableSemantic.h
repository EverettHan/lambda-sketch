#ifndef vDrawableSemantic_H
#define vDrawableSemantic_H

#include "SGInfra.h"

// According to the view mode, some of these semantics can be 
// or not displayed, or displayed differently. 
// This is why there are, for example, several types of edges.
//
// Moreover, semantics can be displayed differently according to the 
// rep they belong to.

class ExportedBySGInfra vDrawableSemantic
{
public:
  typedef unsigned int FSemantic;

  static const FSemantic kNone               = 0;
  static const FSemantic kAll                = -1;

  // standard
  // Mostly used by Scene Graph V6 'reps'.
  static const FSemantic kTriangle           = 1;
  static const FSemantic kLine               = 2;
  static const FSemantic kPoint              = 3;

  // advanced
  // Used by 'CATSurfacicRep' or other Scene Graph V5 'Reps'.
  static const FSemantic kFace               = 4;
  static const FSemantic kEdge               = 5;
  static const FSemantic kBoundaryEdge       = 6;

  static const FSemantic kInternalSharpEdge  = 7;
  static const FSemantic kInternalSmoothEdge = 8;
  static const FSemantic kWireEdge           = 9;

  static const FSemantic kBoundaryPoint      = 10;
  static const FSemantic kInternalSharpPoint = 11;
  static const FSemantic kInternalSmoothPoint= 12;
  static const FSemantic kSurfacicPoint      = 13;
  static const FSemantic kFreePoint          = 14;
  static const FSemantic kIsopar             = 15;

  // user defined
  static const FSemantic kApplicationDefined = 16;
  static const FSemantic kMaxAllowed         = 1>>1;

  
  //static bool CreateNewSemantic(FSemantic& oSemantic);

  static const char* ConvertToChar(FSemantic semantic)
  {
    switch (semantic)
    {
    case kNone: return "None";
    case kAll: return "All";
    case kTriangle: return "Triangle";
    case kLine: return "Line";
    case kPoint: return "Point";
    case kFace: return "Face";
    case kEdge: return "Edge";
    case kBoundaryEdge: return "BoundaryEdge";
    case kInternalSharpEdge: return "InternalSharpEdge";
    case kInternalSmoothEdge: return "InternalSmoothEdge";
    case kWireEdge: return "WireEdge";
    case kBoundaryPoint: return "BoundaryPoint";
    case kInternalSharpPoint: return "InternalSharpPoint";
    case kInternalSmoothPoint: return "InternalSmoothPoint";
    case kSurfacicPoint: return "SurfacicPoint";
    case kFreePoint: return "FreePoint";
    case kIsopar: return "Isopar";
    case kApplicationDefined: return "ApplicationDefined";
    default: return "Error";
    }
  }

private:
  vDrawableSemantic();
  ~vDrawableSemantic();

  //static FSemantic s_currentSemantic;
};

#endif 
