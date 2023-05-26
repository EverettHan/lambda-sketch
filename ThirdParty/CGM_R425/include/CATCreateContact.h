#ifndef CATCreateContact_h
#define CATCreateContact_h

class CATICContact;
class CATIPContact;
class CATPCurve;
class CATCurve;
class CATSurface;
class CATCrvLimits;
class CATGeoFactory;
class CATMathVector;
class CATCrvParam;
class CATIPowerCldPolygon;
class CATICldContact;
class CATGeoFactory;

#include "GeoPlate.h"
#include "CATSoftwareConfiguration.h"
#include "CATTolerance.h"

// ***********************************
// Basics methods to build a contact
// ***********************************


// The Angular Tolerance <TolG1> has degree like units
 
/* A contact of order 0/1/2 by a PCurve

	iorder can be :
	0 : To have a G0 Contact
	1, -1 To have a G1 Contact (-1 to inverse the normal)
	2, -2 To have a G2 Contact (-2 to inverse the normal)
*/

ExportedByGeoPlate CATICContact * CreateContact(CATPCurve * iCurve, 
												const CATCrvLimits * iLim,
												const short iOrder, 
												const CATBoolean IsGeometricalContact,
												const double TolG0,
												const double TolG1 = 0.5,
												const double TolG2 = 0.1);

ExportedByGeoPlate CATICContact * CreateContact(CATGeoFactory * iFactory,
												CATPCurve * iPCurve1, 
													const CATCrvLimits * iLim1,
													CATPCurve * iPCurve2, 
													const CATCrvLimits * iLim2,
													const short iOrder, 
                          const CATBoolean IsGeometricalContact,
													const double TolG0,
													const double TolG1 = 0.5,
													const double TolG2 = 0.1,
													CATSoftwareConfiguration * iConfig=NULL);



ExportedByGeoPlate CATICContact * CreateContact(CATGeoFactory * iFactory,
											    CATPCurve * iPCurve1, 
													
													const CATCrvLimits * iLim1,
													CATCurve * iCurve2, 
													const CATCrvLimits * iLim2,
													const short iOrder, 
                          const CATBoolean IsGeometricalContact,
													const double TolG0,
													const double TolG1 = 0.5,
													const double TolG2 = 0.1,
													CATSoftwareConfiguration * iConfig=NULL);
                          

// A contact of order 0 by a Curve
ExportedByGeoPlate 	CATICContact * CreateContact(CATCurve * iCurve,
													 const CATCrvLimits * iLim,
													 const double TolG0);

// A contact of order 0 by a Point
ExportedByGeoPlate 	CATIPContact * CreateContact(const CATMathPoint & iPoint,
													 const double TolG0);

// A contact of order 0/1/2 by a (u,v) and a Surface
ExportedByGeoPlate 	CATIPContact * CreateContact(const double iu, const double iv, 
																	const CATSurface * iSurf,
																	const short iOrder, 
																	const CATBoolean IsGeometricalContact,
																	const double TolG0,
																	const double TolG1 = 0.5,
																	const double TolG2 = 0.1);

// A Geometrical contact of order 1 by a  Point and a Normal
ExportedByGeoPlate 	CATIPContact * CreateContact(const CATMathPoint & iPoint, 
													 const CATMathVector & iNormal,
													 const double TolG0,
													 const CATBoolean iHasContactOf0 = 1,
													 const double TolG1 = 0.5);

// A contact of order 1 by a  Point and the First derivatives
ExportedByGeoPlate 	CATIPContact * CreateContact(const CATMathPoint & iPoint, 
													 const CATMathVector & iD1U, 
													 const CATMathVector & iD1V,
													 const double TolG0,
													 const CATBoolean iHasContactOf0 = 1,
													 const double TolG1 = 0.5);

// A contact of order 2 by a  Point the First and Second derivatives
ExportedByGeoPlate 	CATIPContact * CreateContact
						(const CATMathPoint & iPoint, 
						const CATMathVector & iD1U,  const CATMathVector & iD1V,
						const CATMathVector & iD2U, const CATMathVector & iD2V,  
						const CATMathVector & iD2UV,
						const CATBoolean IsGeometricalContact,
						const double TolG0,
						const CATBoolean iHasContactOf0 = 1,
						const CATBoolean iHasContactOf1 = 1,
						const double TolG1 = 0.5,
						const double TolG2 = 0.1,
						const short  iLevelPriority = 0);

ExportedByGeoPlate 	CATICContact * CreateContact(CATCurve * iCurve,
						const CATCrvLimits * iLim,
						CATCurve * iCurveNormal,
						const CATBoolean isGeometrical,
						short iorder,
						const double TolG0,
						const double TolG1 = 0.5,
						CATPCurve * iPCurve = 0,
						const  CATCrvLimits * iPLimits = 0,
						CATSoftwareConfiguration * iConfig = 0,
						CATGeoFactory * iFactory = 0);

ExportedByGeoPlate 	CATICldContact * CreateContact(CATIPowerCldPolygon * iCld,
                                                    //CATBoolean iIsGeometric,
                                                    //short iOrder,
                                                    //double iTolG0,
                                                    double iRatioToSatisfied/*,
                                                    double iTolG1,
                                                    double iTolG2*/);

ExportedByGeoPlate CATICldContact * CreateCldContact( CATIPContact * iContact );

#endif
