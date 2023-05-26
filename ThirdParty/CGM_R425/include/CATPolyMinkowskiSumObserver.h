// Copyright Dassault Systemes Provence 2015, All Rights Reserved
//============================================================================================
// CATPolyMinkowskiSumObserver
//============================================================================================
// Usage notes: Observer class for the Minkowski Sum operator
//              Allow user to keep track of the creation of triangle in the result, 
//              and maintain a correspondance between triangle index in the result 
//              and pair of element in each operand
//============================================================================================
// Jun 2020 : VKH1: Creation in PolyhedralOperatorsAdv
//============================================================================================

#ifndef CATPolyMinkowskiSumObserver_h__
#define CATPolyMinkowskiSumObserver_h__

#include <utility>

class CATPolyMinkowskiSumObserver
{
public:

  // ctor / dor
  CATPolyMinkowskiSumObserver(){}
  virtual ~CATPolyMinkowskiSumObserver() {};

  // call-back method
  // A triangle can be output in result from three cases : 
  // - A vertex from first operand times a triangle from second operand : V1xT2
  // - An edgefrom first operand times an edge from second operand : E1xE2
  // - A triangle from first operand times a vertexfrom second operand : T1xV2

  // will be called for V1xT2 case
  virtual void OnResultFromV1xT2Case(int NumVertexFirstOpe, int NumTriangleSecondOpe, int NumGeneratedTriangle) = 0;
  virtual void OnResultFromV1xT2Case(int NumVertexFirstOpe, int NumTriangleSecondOpe, int NumGeneratedTriangle, int& iMult) {};
  virtual void OnResultFromV1xT2Case(int NumVertexFirstOpe, int NumTriangleSecondOpe, int NumGeneratedTriangle, int& iMultV1, int& iMultT2) {};


  // will be called for E1xE2 case
  // an edge is represented by its vertices index (pair of int).
  // in this case, 2 triangles are output at the same time
  virtual void OnResultFromE1xE2Case(std::pair<int, int> EdgeFirstOpe, std::pair<int, int> EdgeSecondOpe, std::pair<int, int> NumGeneratedTriangles) = 0;
  virtual void OnResultFromE1xE2Case(std::pair<int, int> EdgeFirstOpe, std::pair<int, int> EdgeSecondOpe, std::pair<int, int> NumGeneratedTriangles, int& iMult) {};
  
  // will be called for T1xV2 case
  virtual void OnResultFromT1xV2Case(int NumTriangleFirstOpe, int NumVertexSecondOpe, int NumGeneratedTriangle) = 0;
  virtual void OnResultFromT1xV2Case(int NumTriangleFirstOpe, int NumVertexSecondOpe, int NumGeneratedTriangle, int& iMult) {};
  virtual void OnResultFromT1xV2Case(int NumTriangleFirstOpe, int NumVertexSecondOpe, int NumGeneratedTriangle, int& iMultT1, int& iMultV2) {};


};

#endif // CATPolyMinkowskiSumObserver_h__
