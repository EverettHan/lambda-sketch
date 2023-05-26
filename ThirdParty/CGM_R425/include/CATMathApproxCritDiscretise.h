#ifndef _CATMathApproxCritDiscretise_HeaderFile
#define _CATMathApproxCritDiscretise_HeaderFile


#include "CATMathApproxCriterion.h"
#include "CATMathPoint.h"
#include "CATMathPoint2D.h"


class  CATMathApproxCritDiscretise : public CATMathApproxCriterion
{
public:

 	virtual void Add (const CATMathPoint2D  & iUV, const CATMathPoint & iXYZ,	const int iOrder, const double & iTol) = 0;
  virtual void RemoveAllAdd()=0;

  virtual  int GetPointEtTol(CATMathPoint &oPoint, double &oTol, int i)=0;
  virtual int GetSizeOf()=0; 
  virtual int GetNbPntOnCurves()=0;
  virtual int GetNbPntOnSurface()=0;
  virtual void AddPntOnCurves()=0;
  virtual void AddPntOnSurface()=0;



};

#endif
