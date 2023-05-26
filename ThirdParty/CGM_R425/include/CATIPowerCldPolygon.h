/* COPYRIGHT DASSAULT SYSTEMES PROVENCE 2003
* --------------------------------------------------------
*=========================================================
*   PROJET:............Polygon2Surface                             
*   FRAMEWORK:.........SurfacicGeoOperators       
*   DATE:..............fev 2003
*   Purpose : 
*=========================================================
* HISTORY:
* 22.07.2019 : RAQ : Ajout boundary vertices services for P2S
* fev 2003 : ktu definition
*=========================================================
*/

#ifndef CATIPowerCldPolygon_h
#define CATIPowerCldPolygon_h

//#include "CATBaseUnknown.h"
#include "GeoPlate.h"
//#include "CATBoolean.h"
#include "CATPowerCldPolygon.h"

//STL
#ifndef _AIX_SOURCE
#include <string>
#include <vector>
#endif  //!_AIX_SOURCE


class CATMathPoint ;
class CATCldPolygon;
class CATMathVector;


class ExportedByGeoPlate CATIPowerCldPolygon : public CATPowerCldPolygon   
{
public :   




	int GetNumberOfPoints() const { return _NumberOfPoints; };

	//
	int SetTolerancesG0( int iIndex, double iTolG0 );
	int ToleranceG0( int iIndex, double  & oTol ) const ;

	virtual int GetPoint( int iIndex, CATMathPoint * oPoint ) const ;
	virtual int GetPoint( int iIndex, double & oX, double & oY, double & oZ ) const ;
	virtual int SetPoint(int iIndex, double  oX, double  oY, double  oZ ) ;

	int  SetIsFilterable( int iIdx, const CATBoolean iIsFilterable );
	int  GetIsFilterable( int iIdx, CATBoolean & oIsFilterable  ) const;
	//
	int  SetIsFiltered( int iIdx, const CATBoolean iIsFiltered );
	int  GetIsFiltered(  int iIdx, CATBoolean & oIsFiltered ) const;

	//
	int   SetUV( int Index, double iU, double iV );
	int   GetUV( int iIndex, double & oU, double & oV, CATBoolean & oIsDefined  ) const;

	//
	int  SetIsOutOfTolerance( int iIdx, const CATBoolean iIsOut );
	int  GetIsOutOfTolerance( int iIdx, CATBoolean & oIsOut ) const;

	int IsAKindOf(const char *iName) const;


	CATBoolean IsValid() const { return  _IsValid; }


	int ResetUV();

	//  ktu 
	virtual int Normalize3D( const double iRadius );
	int DesactivateNormalize3D();

	int GetTransfo( double &oScale, double &oTx, double &oTy, double &oTz ) const ; 



	// methods 
	int ToleranceG1( int iIndex, double  & oTol ) const ;
	virtual CATBoolean IsG1(const int iIdx ) const;
	//const CATMathVector * GetNormal(const int iIdx ) const;
	int D1( int Index,  CATMathVector &oDU, CATMathVector &oDV)const;
	int SetD1( int Index,  const CATMathVector &iDU, const CATMathVector &iDV);


	   
	int SetIsNotFree( int Index, const CATBoolean iIsNotFree );
	CATBoolean IsFree( int iIndex) const;

  //Flag boundary vertices (0 <= iIndex < nb points), currently only used in P2S
#ifndef _AIX_SOURCE
  virtual int SetIsOnBoundary(const int iIndex, const CATBoolean iIsOnBoundary) override;
  virtual CATBoolean IsOnBoundary(const int iIndex) const override;
#endif  //!_AIX_SOURCE



protected:

	CATIPowerCldPolygon( /*const int iNumberOfPoints */);
	virtual ~CATIPowerCldPolygon() ;


	void CleanG1Tools();
	int InitG1( const int iNumberOfG1); // le 1er set definit si via normal ou du,dv
	//int SetNormal(const int iIdx, const CATMathVector* ipNormal );

	int Init(const int iNumberOfPoints )  ;
	inline CATBoolean IsValidIx( const int Idx)const ;
	int InitIsFree();

	double _TolG1; 
	double _TranslateX, _TranslateY, _TranslateZ, _Scale;
	double * _TableOfUV;
	double * _TableOfTolG0;
	double * _TableOfPoints;
	unsigned char* _TableOfIsFiterable;
	unsigned char* _TabbleOfIsFitered;
	unsigned char* _TableOfIsDefinedUV;
	unsigned char* _ptPointsOutOfTolerance;
	unsigned char* _pIsFree;

#ifndef _AIX_SOURCE
  std::vector<bool> m_boundaryFlags;
#endif  //!_AIX_SOURCE
	

	//CATMathVector **_ppNormals;
	CATMathVector **_ppDU;
	CATMathVector **_ppDV;
	//int * _pNormalIdxOfPoint;

	int _NumberOfPoints;
	//int _NumberOfNormals;
	//int _NumberOfDefinedNormals;

	CATBoolean  _IsValid;
	CATBoolean _NormalzeIsActive;
	///CATBoolean _G1IsDefinedByNormal;

private:


};

inline CATBoolean CATIPowerCldPolygon::IsValidIx(const int iIdx ) const
{
	return ( _IsValid && (iIdx>-1) && (iIdx<_NumberOfPoints) );
}

#endif
