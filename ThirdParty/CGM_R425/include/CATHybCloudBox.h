/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// CATHybBox: Defines the space volume of a cloud of points
//      
//------------------------------------------------------------------------------
// Usage Notes: To be used with CATHybPart
//------------------------------------------------------------------------------
// Inheritance: CATHybBox
//------------------------------------------------------------------------------
//
#ifndef CATHybCloudBox_h
#define CATHybCloudBox_h

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
//------------------------------------------------------------------------------
#include "CATHybBox.h"

class ExportedByPBELight CATHybCloudBox :public CATHybBox
{
public:
  virtual ~CATHybCloudBox();
  CATHybCloudBox(CATPoint* pt,CATHybNeighbour*);

  int   AddPoint(CATPoint* pt);

  short ComputeCenter();
};

#endif
