/*=============================================================================

 COPYRIGHT   : DASSAULT SYSTEMES 2002

=============================================================================
 July 2002 ELV Creation
=============================================================================*/

#ifndef CATFDFBestCylinder_h
#define CATFDFBestCylinder_h
#include "CATMathDef.h"

#include "MathApprox.h"
class CATMathSetOfPoints;
class CATMathVector; 
class CATMathPoint;
class CATMathLine;
class CATSoftwareConfiguration;
class CATTolerance;


class CATFDFBestCylinder 
{
public: 


	ExportedByMathApprox  virtual ~CATFDFBestCylinder();

	virtual	CATMathLine   GetAxis()=0;
	virtual	CATMathPoint   GetOrigin()=0;
	virtual double GetRay()=0; 

	virtual void Run()=0; 
	virtual void ComputeLimits(CATAngle &ioMinAngle,CATAngle &ioMaxAngle, double &ioParaInf, double & ioParaSup)=0 ;
	virtual void SetNbPoint(int  iNbPointOnBoundary)=0;
	virtual void SetOrder(int ik)=0;


};
ExportedByMathApprox CATFDFBestCylinder * CreateBuildBestCylinder(CATMathSetOfPoints * iCloud, 
																																	CATMathPoint&  Origin,
																																	CATMathVector&  Axis, 
																																	double Rayon, 
																																	CATMathVector&  Direction,
                                                                  const CATTolerance& iTolerance,
                                                                  CATSoftwareConfiguration* iConfig);

#endif 

