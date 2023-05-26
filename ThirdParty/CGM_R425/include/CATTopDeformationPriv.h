//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013
//==========================================================================

#ifndef CATTopDeformationPriv_H
#define CATTopDeformationPriv_H


#include "InfraMorph.h"
#include "CATTopDeformation.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATBody.h"

class CATGeoTopoSurfacicProgressBar;
class CATGeoFactory;
class CATTopData;
class CATBody;
class CATFace;
class CATSpaceDeformationTopoMap;

class ExportedByInfraMorph CATTopDeformationPriv : public CATTopDeformation
{
public:

	
	virtual void SetProgressBar(CATGeoTopoSurfacicProgressBar * iProgressBar, const int iNbUsedStep, const int iNbTotalStep)=0;

	

	// Get the ratio Erreur / Tol of the approximation
	virtual double GetCritRatio() const=0;
	// Get the ratio Erreur / Tol of the approximation
	virtual double GetCritError() const=0;
	// Get the maximum G2 gap (after deformation)on G2-edge (before deformation)
	virtual double GetG2Gap() const=0;

  //Get the number Faces Impactees
	virtual CATLONG32 GetNbFacesImpactees() const=0;
  virtual int  GetFacesImpactees(const int iF, CATFace*& oFaceInit, CATFace*& oFaceResult) const=0;

  //Healing methodes
  virtual int SetG1ToleranceToCorrect ( const double iTolAngular )=0;


	virtual int SetConstraintWire(ListPOfCATBody & iWire, ListPOfCATBody & iWiresVariables)=0;


	virtual int SetBodyBase(CATBody * iBody)=0;

	virtual int SetListOfConstFaces(ListPOfCATFace& ioListOfFace)=0;
	

protected:
  CATTopDeformationPriv(CATGeoFactory* iFactory, CATTopData* iTopData);

		
};

ExportedByInfraMorph CATTopDeformationPriv * CATCreateCATTopDefAndHeal(CATGeoFactory*     iFactory,
		                                              CATSpaceDeformationTopoMap*     iMap,
		                                              CATBody*           iBodyToBeDeformed,
		                                              CATTopData*        iTopData);
#endif
