#ifndef CATTessEdgeQueryInterface_H
#define CATTessEdgeQueryInterface_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "TessAPI.h"
#include "CATBoolean.h"
#include "CATDataType.h"
class CATMathVector;
class CATEdge;

// This is as a pure virtual base class that acts as a query interface for seeking information 
// on known tessellation of a CATEdge. The application should derive from this class and provide 
// the implementation. This can be used by the application to convey information about known 
// tessellation of a CATEdge to CATTessellate (in method AddEdgeKnown), in the context of incremental 
// tessellation in CATTessIncrModeNoPropagation or CATTessIncrModeNoPropagationDegenTriangles mode.
// Note that the sequence of points should be aligned with the orientation of the CATEdge
// (i.e. in the same way as the convention in CATTessStore)

class ExportedByTessAPI CATTessEdgeQueryInterface
{
public:

  CATTessEdgeQueryInterface();
  virtual ~CATTessEdgeQueryInterface();

  virtual CATEdge* GetEdgeInQuestion() const = 0;

  // Queries for tessellation points
  
  virtual int GetNumberOfPoints() const = 0;
  
  virtual void GetPtCoord(
                int iNumPoint, // numbering starts with 0
                double oPtCoord[3]
                ) const = 0; 
  
  virtual void GetCrvParam(
                int iNumPoint, // numbering starts with 0
                double& oCrvParam
                ) const = 0; 
};


#endif //CATTessEdgeQueryInterface_H

