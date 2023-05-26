/* -*-C++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2004
//=============================================================================
// CATNewtonConvergeDistanceSurSur :
//=============================================================================
//=============================================================================
// Apr 04  Creation                          OAU
//=============================================================================
/**
* @quickReview OAU 04:04:08
* @fullreview AAD OAU 04:04:04
*/
#ifndef CATNewtonConvergeDistanceSurSur_h
#define CATNewtonConvergeDistanceSurSur_h

//#include "ExportedByCATTopImpl.h"
#include "ExportedByBOOLight.h"

#include "CATTopOperator.h"
#include "CATMathNxNMatrix.h"
#include "CATMathPoint.h"
#include "CATSurParam.h"
#include "CATFace.h"
#include "ListPOfCATFace.h"

class CATSurface;
class CATMathVector;
class CATBody;
class CATCell;
class CATMathDirection;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATTopData;
class CATTopologicalOperator;
class CATCGMJournalList;
//-----------------------------------------------------------------------------
class  ExportedByBOOLight CATNewtonConvergeDistanceSurSur : public CATTopOperator
{
  public :
    //-------------------------------------------------------------------------
    // Constructor/Destructor
    //-------------------------------------------------------------------------
    CATNewtonConvergeDistanceSurSur(CATBody		*&Skin1,		CATBody			*&Skin2,
									CATMathPoint&Point1,		CATMathPoint	&Point2,		
									CATGeoFactory  *iFactory, CATTopData		*iData);

    ~CATNewtonConvergeDistanceSurSur();     

    //-------------------------------------------------------------------------
    // Method
    //-------------------------------------------------------------------------
	int Run();
    void GetMathPoints(CATMathPoint &oPoint1, CATMathPoint &oPoint2);
	void GetSupportCells(CATCell*  &oSupportCell1,CATCell*  &oSupportCell2);
	double GetDistance();

  protected :

	int RunOperator();

  private :

	// Topology
	HRESULT InitNewton();
	void FindGeometricSurfaceFromTopology(CATCell * pCell,CATSurface * &pSurface,CATFace * &pFace);
	HRESULT FindGeometricSupportFromPoint(CATMathPoint &ioMathPoint,CATBody * ipSkin,CATLISTP(CATFace) &ioListOfFaces,CATSurface * &opSurface,CATCell * &opCell,CATFace * &opFace,CATSurParam &oPointParam,CATMathDirection * iDir = NULL);

	// Geo-Topo
	CATMathDiagnostic Converge();

	// Geometry
	CATMathDiagnostic Newton(const double * X0, double * X1);
	void F(const double * iX, double * oFX);
	void DLS(const CATSurface * iSur,const double iu0,const double iv0,const double iu1,const double iv1, CATMathPoint &oFU);
	void S(const CATSurface * iSur,const CATSurParam &iU, CATMathPoint &oFU);
	void DS(const CATSurface * iSur,const CATSurParam &iU, CATMathVector & oDSu, CATMathVector & oDSv);
	void D2S(const CATSurface * iSur,const CATSurParam &iU, CATMathVector & oD2Su, CATMathVector & oD2Suv, CATMathVector & oD2Sv);
	void Jacobien(const CATSurParam &iU1,const CATSurParam &iU2);

    // Private Data
	CATGeoFactory * _pGeoFactory;
	CATSoftwareConfiguration	*_pConfig;
	CATCGMJournalList	* _pJournal;
	CATTopData	* _pTopData;
	CATTopologicalOperator * _pTopToolkit;
	
	CATBody * _Skin1;
	CATBody * _Skin2;
	CATMathPoint _CurPt1;
	CATMathPoint _CurPt2;
	double _Distance;
	CATSurface * _Sur1;
	CATSurface * _Sur2;
	CATFace * _Face1;
	CATFace * _Face2;
	CATCell * _CurSpprtCell1;
	CATCell * _CurSpprtCell2;
	CATSurParam _CurParamPt1;
	CATSurParam _CurParamPt2;

	CATLISTP(CATFace) _ListOfFaces1;
	CATLISTP(CATFace) _ListOfFaces2;

	CATMathNxNMatrix * _J;
};
#endif
