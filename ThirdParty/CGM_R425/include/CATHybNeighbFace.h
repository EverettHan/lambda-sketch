/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// CATHybNeighbFace : Face Neighbourhood 
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATHybNeighbFace_h
#define CATHybNeighbFace_h

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
//------------------------------------------------------------------------------
#include "CATHybSingleNeighb.h"

class ExportedByPBELight CATHybNeighbFace :public CATHybSingleNeighb
{
  public:

    CATHybNeighbFace(CATGeoFactory*,CATHybFaces&);
    virtual ~CATHybNeighbFace();

    CATHybFace* NextFace(CATHybFace* face,CATHybFace* neighb)const;
    
  private:
    CATPoints*	_ptList;
};

#endif
