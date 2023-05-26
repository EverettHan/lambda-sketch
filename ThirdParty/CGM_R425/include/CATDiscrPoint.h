#ifndef CATDiscrPoint_h
#define CATDiscrPoint_h

#include "CATMathPoint.h"
#include "CATMathPoint2D.h"

#include "MathPlate.h"
 
class  ExportedByMathPlate  CATDiscrPoint 
 
{
 
public :
 
	~CATDiscrPoint();	
 
	CATDiscrPoint ();
 
	
	CATDiscrPoint (const CATMathPoint2D & iUV,
				const CATMathPoint & iXYZ,
				const int iOrder,
				const double & iTol);
 

	inline void SetValue2d(const CATMathPoint2D & iUV); 
 
	inline void SetValue3d(const CATMathPoint & iXYZ); 

	inline void SetOrder(const int iOrder);

	inline void SetTolerance(const double & iTol);

	const CATMathPoint2D& GetValue2d() const;
 
	const CATMathPoint& GetValue3d() const;
 
	int GetOrder();
 
	double GetTolerance();

private :
	CATMathPoint _XYZ ;
	CATMathPoint2D _UV;
	double _Tol;	
	int _Order;
};

inline void CATDiscrPoint:: SetValue2d(const CATMathPoint2D & iUV) 
{
	_UV = iUV;
}
 
inline void CATDiscrPoint::SetValue3d(const CATMathPoint & iXYZ) 
{
	_XYZ = iXYZ;
}

inline void CATDiscrPoint::SetOrder(const int iOrder)
{	
	_Order = iOrder;
}

inline void CATDiscrPoint::SetTolerance(const double & iTol)
{	
	_Tol = iTol;
}

#endif
