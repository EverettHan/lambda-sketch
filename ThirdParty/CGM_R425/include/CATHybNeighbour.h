/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// CATHybNeighbour: Neighbourhood computation root
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: 
//------------------------------------------------------------------------------
//
#ifndef CATHybNeighbour_h
#define CATHybNeighbour_h

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
//------------------------------------------------------------------------------
#include "CATHybDef.h"
#include "CATPoints.h"
#include "CATCGMVirtual.h"

class ExportedByPBELight CATHybNeighbour : public CATCGMVirtual
{
  public:

    CATHybNeighbour(CATGeoFactory*,double tolerance=-1.0);
    CATHybNeighbour(CATGeoFactory*,CATPoints&,double tolerance=-1.0);
    CATHybNeighbour(CATGeoFactory*,CATPoint**,int nbPoints,double tolerance=-1.0);
    virtual ~CATHybNeighbour();

    //virtual CATPoint* Next(CATPoint*)const;
    CATPoints& GetList();
    void SetList(CATPoints&);
    double GetInfini()const;
    int GetKey()const;
    double GetTolerance()const;
#ifdef CATHybDumpPart
    CATGeoFactory* GetFactory();
#endif
    
  protected:
    virtual void Initialize()=0;
    void AddPts(CATHybPart* main);
    int Size()const;
    CATMathBox* GetBox();

    CATMathBox*      	_be;
    CATPoints*       	_list ;
    short 		_listNew;
    CATHybPart* 	_mainPart;
    CATGeoFactory*	_factory;
    double	 	_tolerance;

  private:	
    int			_key;

    CATMathBox* ComputeBox();
    static void Maximalize(double& min,double& max,double x );
};

#endif
