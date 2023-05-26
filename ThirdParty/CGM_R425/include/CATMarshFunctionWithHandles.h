// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2001
//

#ifndef CATMarshFunctionWithHandles_h
#define CATMarshFunctionWithHandles_h

#include "CATMathMarshFunction.h"
#include "InfraMorph.h"

#include "CATMarshHandle.h"

class CATMathTransformation;



class ExportedByInfraMorph CATMarshFunctionWithHandles : public CATMathMarshFunction
{
public:

	CATMarshFunctionWithHandles (int nbH=0);
	~CATMarshFunctionWithHandles ();
	void AddRef();
	void Release();
	CATBoolean IsAKindOf(const char *Type) const;
	void Init();
	CATLONG32 Clone(CATMathMarshFunction * &copy, const CATBoolean iCloneAll=FALSE) const;
	CATLONG32 Evaluate(const CATMathVector &, CATMathVector&) const;
	/*		CATBoolean IsIsotrope()  const;
	CATBoolean IsCompact()  const;
	int GetFunctionCoef(CATMathVector*& oFunctionCoef, int& oNbRadFunc, int&oNbPolyFunc) const;
	int GetRadialCoef(double*& iSetOfPoints, int iNbPoints, double*& oRadialCoef) const;
	int GetPolynomialCoef(double*& iSetOfPoints, int iNbPoints, double*& oPolynomialCoef) const;*/

	CATLONG32 EvaluateDerivative(const CATMathVector &,
		const int ix,
		const int iy,
		const int iz,
		CATMathVector&) const;

	CATLONG32 EvaluateDerivatives(const CATMathVector &,
		const int iNbDer,
		const int* idx,
		const int* idy,
		const int* idz,
		CATMathVector* oResEval) const;

	void GetCenter(CATMathVector& oCenter)const;
	int SetMultiQuadC(const double iC, const double iNativeC );
	double GetMultiQuadC()const;
	double GetMaxMultiQuad(const double iTolerance)  const;

	void SetPolynomialPartOnly(const CATBoolean PPOnly = 0);
  void SetPreFuncOnly(const CATBoolean iPrefFuncOnly = TRUE);

	void SetFunction0(CATMathMarshFunction * F0);
	void SetFunction1(const CATMathMarshFunction * F1);
	int SetFunction(const int index, CATMathMarshFunction * F);
	int SetHandle(const int index, CATMarshHandle * H);

	/** 
	* Returns the number of sources in  the final resolution.		
	*/
	int GetNumberOfSources() const;

  void SetHasCache(CATBoolean iHascache) {}; //NYI
  CATBoolean HasCache() const {return TRUE;} //toujours en attendant une implementation.

  CATMathMarshFunction * GetFunction0 () { return _Function0; } 

	int InitMesh(
		int ID,
		int iNumberOfFaces,
		int *iNumberOfVerticies,
		cat_fpoint **iVerticies,
		CATMathTransformation*   iPreTransfo,
		CATMathTransformation*   inverseTransfo,
    CATMathVector * iCorrection = NULL);


	int EvalMesh(int ID,
		int iNumberOfFaces,
		int *iNumberOfVerticies,
		cat_fpoint **iVerticies,
		cat_fpoint **iNormals,
		cat_fpoint **oVerticies,
		cat_fpoint **oNormals,
		CATMathTransformation*   iPreTransfo =0,
		CATMathTransformation*   inverseTransfo=0,
    CATMathVector * iCorrection = 0);

	//
	// this function returns :  "this" + TabCoef[0]*(TabFunctions[0] -"this")
	// + TabCoef[1]*(TabFunctions[1]-"this") +...+TabCoef[NbFunctions-1]* (TabFunctions[NbFunctions-1]-"this")
	// .. with a reference counter set to 1... so... do a ->Release() when you are done.
	// it returns a null pointer if it fails (means that the true types are not consistent ...)
	//

	CATMathMarshFunction *CreateLinearCombinationWith(const int NbFunctions, 
		CATMathMarshFunction **TabFunctions,
		double *TabCoef) const;

	/**
	*
	* <br><b>Tells if the object supports Stream or not</b>: 
	* @return
	* <br><b>Legal values</b>: <tt>TRUE</tt> if stream is implemented,
	* <tt>FALSE</tt> otherwise.
	* 
	*/
	CATBoolean IsStreamable(const CATCGMStreamVersion iTargetVersion, CATBoolean & ioReversible)const; 

	/**
	*
	* <br><b>To stream this</b>: 
	* @param ioWriteStream
	* the stream
	* @return
	* 
	*/
	void Stream( CATMathStream& ioWriteStream )const;

	/**
	*
	* <br><b>Constructor equivalent to Unstream</b>: 
	* @param ioReadStream
	* the stream
	*/
	CATMarshFunctionWithHandles( CATMathStream& ioReadStream );


private:

	void InitForConstructor( );
  void ResetCache();

	CATMathMarshFunction *_Function0;  //MBP
	CATMathMarshFunction *_Function1;  //MBP

	CATMathMarshFunction **_TAbOfFunction;
	CATMarshHandle **_TabOfHandle;

	CATMathMarshFunction *_CacheOptim;
	double *_CacheTabCoef;
  CATBoolean _PrefFuncOnly;  //MBP

	unsigned int _Count;
	const int _nbHandle;



	class FMesh
	{
	public:

		int * _NumberOfVerticies;
		//			cat_fpoint**	_Verticies;  // utile ???
		cat_fpoint***	_VImageH;
		CATMath3x3Matrix *** _MatH;

		int _ID;
		int _IsOK;
		int _NbHandles;
		int _NumberOfFaces;
		CATMathTransformation*   _PreTransfo;
		CATMathTransformation*   _inverseTransfo;

		FMesh(int NbHandles, 
			int ID, int iNumberOfFaces,
			int *iNumberOfVerticies,
			cat_fpoint **iVerticies, 
			CATMathTransformation*   iPreTransfo=NULL,
			CATMathTransformation*   inverseTransfo=NULL);
		~FMesh();
		void Eval(double *HandleValues,
			cat_fpoint** iNormals, cat_fpoint** oVerticies, cat_fpoint**oNormals);

	} *_theMesh;

};


#endif
//automate:28/09/01:suppression include de 
