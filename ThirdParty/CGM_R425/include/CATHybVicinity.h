/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// CATHybVicinity: base class for Neighbourhood  computation by
//		 recursive space discretization mean
//      
//------------------------------------------------------------------------------
// Usage Notes:  
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATHybVicinity_h
#define CATHybVicinity_h

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
//------------------------------------------------------------------------------
#include "CATHybDef.h"
#include "CATCGMVirtual.h"

class ExportedByPBELight CATHybVicinity : public CATCGMVirtual
{
public:
  
  CATHybVicinity(CATHybNeighbour* =NULL);
  virtual ~CATHybVicinity();

  int GetKey()const;
  
protected:
  // Norm2 for points p1 & p2
  static double ComputeNorm2(const double* p1, const double* p2);

  static const int      _dim;		// dimension
  static const int      _dimtot;	// 2^_dim
  CATHybNeighbour*	_neighbour;	// current neighb operator
};

#endif
