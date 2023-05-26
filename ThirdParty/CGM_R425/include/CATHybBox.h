/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// CATHybBox: Defines the space coordinates of a CATHybPart
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: CATHybVicinity
//------------------------------------------------------------------------------
//
#ifndef CATHybBox_h
#define CATHybBox_h

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
//------------------------------------------------------------------------------
#include "CATHybVicinity.h"

class ExportedByPBELight CATHybBox : public CATHybVicinity
{
  class CATHybBulk
    {	
    public:	
      CATHybBulk(CATMathBox*);
      CATHybBulk(const CATHybBulk&);
      CATHybBulk();
      ~CATHybBulk();

      void Trim(CATHybPosition* position, double* point);
      void ComputeCenter(double* point)const;
      void Initialize(CATPoint* pt);
      void AddPoint(CATPoint* pt);
      
      const double* GetFirstEnd()const;
      const double* GetSecondEnd()const;

#ifdef CATHybDebugPart
      void	Dump(char* ="")const;
#endif
    private:
      double	_p1[3];
      double	_p2[3];
    };
  
  
public:
  virtual ~CATHybBox();
  CATHybBox(CATHybNeighbour*);
  CATHybBox(CATMathBox* box,CATHybNeighbour* n);
  CATHybBox(CATHybPosition* position, const CATHybBox* fatherspace,
	          CATHybNeighbour *n);

  short   GetPtPosition(const CATPoint* pt, CATHybPosition* position)const;

  double* GetQuantils()const;
  void    SetQuantils(double* quantils);
  
  const double* GetFirstEnd()const;
  const double* GetSecondEnd()const;

#ifdef CATHybDebugPart
  void   DumpBulk(char* ="")const;
#endif

protected:
  double* 	_quantils;
  CATHybBulk* 	_bulk;
  
};

#endif
