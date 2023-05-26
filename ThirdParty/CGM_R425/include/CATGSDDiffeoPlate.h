//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//==========================================================================
//
// Interface to define a diffeomophism 
//                                    3     3 
// ie a continous application  from IR to IR
//
// CATGSDDiffeoPlate :
// Implementation du diffeomorphisme D = Surface - Plan (S-P)
// Soit (X,Y,Z) un Point; (U,V) les coordonees de sa projection sur P
// alors D(X,Y,Z) = S(U,V) - P(U,V).
//
//==========================================================================
// Usage Notes
//==========================================================================
// Dec. 99     Creation                       PMG
//========================================================================== 
#ifndef CATGSDDiffeoPlate_H
#define CATGSDDiffeoPlate_H


#include "InfraMorph.h"

#include "CATStreamMapFunctionXYZ.h"
#include "CATMathDef.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMathPlane.h"
#include "CATSurParam.h"
#include "CATMathTransformation.h"


class CATSurface;
class CATFDFZone;

//#define CATGSDDiffeoPlate_EvalThirdDeriv

class ExportedByInfraMorph  CATGSDDiffeoPlate : public CATStreamMapFunctionXYZ
{
public:
	//=============
	//Constructeur
	//=============
	CATGSDDiffeoPlate(const CATMathPlane * iPlane, CATSurface * iSurf);
	~CATGSDDiffeoPlate();

	//=============
	//Complement of definition
	//=============
	// Define a zone of effective deformation
	void Set(CATFDFZone * iZone);

	//===========
	//Information
	//===========
	// return true when ic is "CATGSDDiffeoPlate"
	CATBoolean IsAKindOf(const char* ic) const;

	CATBoolean IsALinearMap() const;

	/*
	if it is a LinearMap this methode give the equivalent Transformation
	*/
	CATLONG32 GetMathTransformation(CATMathTransformation & oTransformation) const;

	//===========
	//Evaluators
	//===========	
	CATLONG32 Eval(const CATMathPoint& iPInitial, CATMathPoint & oPModified) const;

	CATLONG32 EvalFirstDeriv(const CATMathPoint& iPInitial, 
		CATMathVector& oDu, CATMathVector& oDV,CATMathVector& oDw) const;

	CATLONG32 EvalSecondDeriv(const CATMathPoint& iPInitial, 
		CATMathVector& oD2u, CATMathVector& oD2v, CATMathVector& oD2w,
		CATMathVector& oDuv, CATMathVector& oDuw, CATMathVector& oDvw) const;

#ifdef CATGSDDiffeoPlate_EvalThirdDeriv
	CATLONG32 EvalThirdDeriv(const CATMathPoint& iPInitial, 
		CATMathVector& oD3x, CATMathVector& oD3y, CATMathVector& oD3z,
		CATMathVector& oD2xDy, CATMathVector& oD2xDz, CATMathVector& oD2yDx,
		CATMathVector& oD2yDz, CATMathVector& oD2zDx, CATMathVector& oD2zDy,
		CATMathVector& oDxyz) const;
#endif


	//  prevoir de le mettre en private  et de definir le Mproc en friend
	/**
	*
	* <br><b>Tells if the object supports Stream or not</b>: 
	* @return
	* <br><b>Legal values</b>: <tt>TRUE</tt> if stream is implemented,
	* <tt>FALSE</tt> otherwise.
	* 
	*/
	CATBoolean IsStreamable(const CATCGMStreamVersion iTargetVersioniTargetVersion, CATBoolean & ioReversible)const ;
	/**
	*
	* <br><b>Constructor equivalent to Unstream</b>: 
	* @param iFactory
	* the  facrory	
	* @param ipConfig
	*  the software configuration
	* @param ioReadStream
	* the stream
	*/
	CATGSDDiffeoPlate(CATGeoFactory* iFactory, CATSoftwareConfiguration * ipConfig,CATMathStream& ioReadStream );
	/**
	*
	* <br><b>To stream this</b>: 
	* @param ioWriteStream
	* the stream
	* @return
	* 
	*/
	void Stream( CATMathStream& ioWriteStream )const ;
	//void UnStream( CATMathStream& ioReadStream );
	//// master
	void GetPrerequisiteObjects( CATLISTP(CATICGMObject)& olObjects)const;
	//void Finalize( CATGeoFactory * ipFactory, const CATSoftwareConfiguration* ipConfig);



private :
	int Init(); // members
	CATMathPlane _ThePlane; // MBP must be persitent

	CATSurParam  _SurParam; 
	CATMathVector _Du;
	CATMathVector _Dv;

	CATMathVector _D2u;
	CATMathVector _D2v;
	CATMathVector _D2uv;

	CATMathVector _D3u;
	CATMathVector _D3v;
	CATMathVector _D2uDv;
	CATMathVector _DuD2v;

	double _dudx, _dudy, _dudz, _dvdx, _dvdy, _dvdz;		

	CATSurface * _TheSurf; // MBP must be persitent.
	CATFDFZone * _Zone;   // MBP must be persitent.

	CATLONG32 _SurfaceTag; 

	CATBoolean _is2D;
};
#endif
