// COPYRIGHT DASSAULT SYSTEMES  2016
#ifndef CATCDSGraphClasses_H
#define CATCDSGraphClasses_H

#include "CATCDSString.h"
#include "CATCDSGraph.h"
#include "CATCDSArray.h"
class CATCDSGraphEdge;
class CATCDSGraphVertex;

class CATCDSGraphObject
{
public:
  virtual CATCDSString const& GetName() const =0;
};

class CATCDSVertexEdge
{
public : 
  CATCDSGraphVertex* _pV;
  CATCDSGraphEdge* _pE;
  CATCDSVertexEdge(CATCDSGraphVertex*ipV,CATCDSGraphEdge* ipE) : _pV(ipV), _pE(ipE) {}
};

/*
  *@param the pointers to vertex to compare
  *@ return 1 if Couple1>Couple2, otherwise
  * couple1 and couple2 are compared thanks to the vertex's _index
*/
int IsSmaller(CATCDSVertexEdge const& iCouple1, CATCDSVertexEdge const& iCouple2);

class ExportedByGraph CATCDSAdjacent
{
protected:
  CATCDSArray<CATCDSVertexEdge> _verticesEdges;
public:
  CATCDSGraphVertex* const& operator[] (int i) const;
  CATCDSGraphEdge* const& operator() (int i) const;
  CATCDSGraphVertex*& operator[] (int i);
  CATCDSGraphEdge*& operator() (int i);
  void Append(CATCDSGraphVertex* ipV, CATCDSGraphEdge* ipE);
  int Size() const;
  void SetFirstEdge(CATCDSGraphEdge* ipEdge);
  CATCDSVertexEdge* Begin();
  CATCDSVertexEdge* End();
};

class CATCDSPath : public CATCDSAdjacent
{
protected :
  int _priorities[2]; // _priorities[0] contains the number of edges with priority P0 in the path; _priorities[1] contains the number of P1 edges.
public :
  CATCDSPath();
  int const GetNumberOfP0() const ;
  int const GetNumberOfP1() const;
  void UpdatePriorities(int iPriority);
};

class CATCDSTriplet : public CATCDSPath // triplet is a CATCDSPath composed of 3 couples : (v1,0); (v2, edge v1-v2); (v3, edge v2-v3)
{
public :
  CATCDSTriplet();
  CATCDSTriplet(CATCDSGraphVertex* ipV1, CATCDSGraphEdge* ipE1, CATCDSGraphVertex* ipV2, CATCDSGraphEdge* ipE2, CATCDSGraphVertex* ipV3, CATCDSGraphEdge* ipE3); //BEWARE : order is important!
  void Append(CATCDSGraphVertex* ipVertex, CATCDSGraphEdge* ipEdge);
  void SetFirstEdge(CATCDSGraphVertex* ipV3, CATCDSGraphEdge* ipE1); //a utiliser seulement si le triplet est un triangle (ie existent 3 edges : ipE3-ipE1, ipE1-ipE2, ipE2-ipE3)
};

/*
  *@param the 2 paths to compare
  *@return 1 if path1<path2, 0 if path1>path2
*/
int ExportedByGraph ComparePath(CATCDSPath const& ipath1, CATCDSPath const& ipath2);

/*
  *@param the 2 edges (pointers) to compare
  *@return 1 if edge1->_weight < edge2->_weight, 0 otherwise
*/
int ExportedByGraph CompareEdgeWeights(CATCDSGraphEdge* const& ipath1, CATCDSGraphEdge* const& ipath2);

#endif
