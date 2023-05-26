/* -*-C++-*- */
#ifndef ListPOfCATVertexOnNuplet_h
#define ListPOfCATVertexOnNuplet_h

#include "ExportedByRIBLight.h"

class CATVertex;
class CATRlmRib;

class CATVertexOnNuplet {
public :
   CATVertex * _Vertex;
   int _NumNup;
   double _ParamValue;
   CATRlmRib *_CuttingRib ;
};

#include "CATCGMLISTPP_Declare.h"

CATCGMLISTPP_DECLARE(CATVertexOnNuplet);

typedef CATLISTP(CATVertexOnNuplet) ListPOfCATVertexOnNuplet;

//------------------------------------------------------------------------------
// Global methods for comparison of two PointOnNuplet objects
//------------------------------------------------------------------------------
ExportedByRIBLight int  CompareNupletNumberInList ( CATVertexOnNuplet *First,
			                                         CATVertexOnNuplet *Second);

ExportedByRIBLight int CompareVertexParamValueInList ( CATVertexOnNuplet *First,
			                                          CATVertexOnNuplet *Second);

#endif
