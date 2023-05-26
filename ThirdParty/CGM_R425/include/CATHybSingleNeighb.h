/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// CATHybSingleNeighb: Neighbourhood computation by recursive space discretization
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: CATHybNeighbour
//------------------------------------------------------------------------------
//
#ifndef CATHybSingleNeighb_h
#define CATHybSingleNeighb_h

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
//---------------------------------------------------------------------------
#include "CATHybNeighbour.h"

class ExportedByPBELight CATHybSingleNeighb : public CATHybNeighbour
{
public:
  CATHybSingleNeighb(CATGeoFactory*,CATPoints&);
  CATHybSingleNeighb(CATGeoFactory*,CATPoint**,int nbPoints);
  virtual ~CATHybSingleNeighb();
  CATPoint* NextNeighbour(CATPoint* point,CATPoint* neighb,int maxLevel=3)const;
  
protected:
  CATHybSingleNeighb(CATGeoFactory*);
  void Initialize();
  void FindNextNeighbours(int maxLevel);

private:
  int  _size;
  int  _searchLevel;
  CATPoints* _searchList;
  CATPoint*  _point;
};

#endif
