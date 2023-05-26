#ifndef CATGeoTopDeform_H
#define CATGeoTopDeform_H
/*  
=============================================================================

RESPONSABLE  :  

DESCRIPTION  : Implementation surface Deformation for PowerDef
=============================================================================
*/

#include "InfraMorph.h"

#include "CATMathDef.h"
#include "CATCrvLimits.h"
#include "CATSurLimits.h"
#include "CATListOfDouble.h"
#include "CATListOfCATPCurves.h"

class CATGeoFactory;


class CATSurface;
class CATCurve;
class CATPCurve;
class CATPoint;

class CATBuildPlateDeform;
class CATICContact;
class CATSoftwareConfiguration;
//
//--------------------------------------------------------------------------
//
class ExportedByInfraMorph CATGeoTopDeform
{

public:
	// Constructeur 
  CATGeoTopDeform (CATGeoFactory * iGeoFactory,
		               CATSoftwareConfiguration * iConfig,
	   				       const CATSurface * initSurface,
									 const CATSurLimits& iLimits);

	 CATGeoTopDeform (CATGeoFactory * iGeoFactory,
		                CATSoftwareConfiguration * iConfig);

	// Destructeur 
  ~CATGeoTopDeform();
	
	// controle du test de rejection
	int SetToleranceMax(const double iTolMax);
	// Tolerance de la deformation
//	int SetToleranceG0(const double iTolG0);
	int SetNormalizationCoefficient(const double iCfN);

  int SetCfEnergy0(const double iEnergyCoefficient);
	
  int	AddContact(CATPCurve* iPC,  CATCrvLimits& iLim, CATICContact* iContTarget , 
		             CATICContact* iContInit=0, const double iAuthorizedDeformation = 0.008);

	int AddContact3d(CATICContact* iContTarget, 
		               CATICContact* iContInit);

	int SetToleranceG0(const int Id, const double iTol);

	
  // Construction
  int Run();

  int IsValid(const double iMaxDef);


	CATSurface * GetSurface();

	CATSurface * GetInitialSurface () const;

private:
	CATSurface * CreatePonctualSurf(const CATSurLimits& iLimits);
	double       MaxDeviationOnContact(CATICContact* iCont);
	//void EraseContact();
	int SetOptionMode2D(CATBuildPlateDeform	* ioDeform);

  // Donnees membres
  //----------------
  CATGeoFactory	    *		  _GeoFactory;
  CATSoftwareConfiguration * _Config;
  CATBuildPlateDeform *		_Builder;
	CATListOfDouble         _ListOfDeviation;

	CATSurface *              _PSurface;
  CATSurface *              _NewSurface;
 // double                    _TolG0;
  double                    _TolMax;
	CATLONG32                      _NbConstraint;
	CATBoolean                _IsValid;
	CATBoolean                _PontualInit;
	CATBoolean                _CheckDeviation;

};
#endif




















//automate:27/09/01:suppression include de CATTopDef.h
//automate:27/09/01:suppression include de CATListOfInt.h
