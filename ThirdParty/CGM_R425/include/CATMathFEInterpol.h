/* COPYRIGHT DASSAULT SYSTEMES PROVENCE 2004
 * --------------------------------------------------------
 
 * HISTORY:
 * Dec 2001 :  definition
 **/
 


#ifndef _CATMathFEInterpol_H
#define _CATMathFEInterpol_H
#include "PlateFE.h"


class CATMathFunctionX;
class CATSoftwareConfiguration;
class CATMathBeamFE;
class CATTolerance;

#include"CATBoolean.h"


class ExportedByPlateFE CATMathFEInterpol 
{
public:
	 CATMathFEInterpol(CATSoftwareConfiguration * iConfig,
										const int iN,
										const double * iParam,
										const double * iValue,
										CATBoolean isClosed,
                    const CATTolerance& iTol);

   /*
    * Virtual Constructor
    */
   virtual ~CATMathFEInterpol();

   /*
    * Virtual Constructor
   */
   virtual int Run();

/* ====================================================================== */
/* ========================= Init methods =============================== */
/* ====================================================================== */
   
   
	 virtual CATMathFunctionX*  GetFunction() const; 
   
private:

	 int SetOption(CATMathBeamFE * iBeamOpe);


   CATSoftwareConfiguration * _Config;
	 const double* _Params;
	 const double* _Values;
	 CATMathFunctionX*  _Interpolation;
	 int _NbParams;
	 CATBoolean _isClosed;
   const CATTolerance& _Tol;
};

/*
ExportedByPlateFE CATMathFEInterpol * CreateFEInterpol (const int iN,
																												const double * iParam,
																												const double * iValue,
																											CATBoolean isClosed); */

#endif






 
