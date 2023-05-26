#ifndef CATCompoSmoothMap_H
#define CATCompoSmoothMap_H

#include "InfraMorph.h"

#include "CATIAV5Level.h"
#include "CATMathStream.h"
#include "CATStreamMapFunctionXYZ.h"

class CATSoftwareConfiguration;
class CATMathVector;
class CATMathPoint;
class CATCldPolygon;
class CATTopoConvolFunction;

// Utilisation de CATIPolyMesh
#if defined CATIAV5R20 || defined CATIAR208
#define UsingPolyMesh
#endif

#ifdef UsingPolyMesh
class CATIPolyMesh;
class CATIPolyMeshTriangleIterator;
class CATPolyPointMeshDistanceAccelerator;
#endif

class ExportedByInfraMorph CATCompoSmoothMap : public CATStreamMapFunctionXYZ/*CATMapFunctionXYZ*/
{
public:


	CATCompoSmoothMap(CATGeoFactory* iFactory, CATSoftwareConfiguration * ipConfig/*CATTopData* iTopData*/, int iNbFunction, 
		double *iKernelWidths, CATCldPolygon* iCldPoly, float** iHeights, float iGlobalHeight);

#ifdef UsingPolyMesh
	CATCompoSmoothMap(CATGeoFactory* iFactory,CATSoftwareConfiguration * ipConfig/*CATTopData* iTopData*/, int iNbFunction, 
		double *iKernelWidths, CATIPolyMesh* iPolyMesh, float** iHeights, float iGlobalHeight);
#endif

	~CATCompoSmoothMap();

	void SetLevel(const int iLevel = 1);

	// Init method must be directly called BEFORE any other method except SetLevel
	void Init();

	int SetParameters(const double *iKernelWidth, const double iTriangleMaxLength);

	CATBoolean IsModelDependant() const;

	CATBoolean IsThreadSafe() const { return FALSE;/*TRUE;*/}

	int GetDeformationAlongNormal() const;

	CATBoolean IsAKindOf(const char* ic) const;

	CATBoolean IsALinearMap() const;

	CATLONG32 GetMathTransformation(CATMathTransformation & oTransformation) const;

	CATLONG32 Eval(const CATMathPoint& iPInitial, CATMathPoint & oPModified) const;

	CATLONG32 EvalFirstDeriv(const CATMathPoint& iPInitial, 
		CATMathVector& oDu, CATMathVector& oDV,CATMathVector& oDw) const;

	CATLONG32 EvalSecondDeriv(const CATMathPoint& iPInitial, 
		CATMathVector& oD2u, CATMathVector& oD2v, CATMathVector& oD2w,
		CATMathVector& oDuv, CATMathVector& oDuw, CATMathVector& oDvw) const;

	int GetMaxKernNormErr(double * oErrors) const;

	// To normalize convolution
	int SetNormalizeConvolution( CATBoolean iUseNormalizeConvol );


	// Clone pour MultiThreading
	CATLONG32 Clone(CATMapFunctionXYZ * & oCopyMapFunctionXYZ, CATGeoFactory * ifactory) const;

	// Set un nouveau CldPolygon
	int SetCldPolygon( CATCldPolygon * & iCldPolygon ) ;

	// Copy du _CldPolygon
	//int CloneCldPolygon( CATGeoFactory * iFactory, CATCldPolygon * & oCopyCldPolygon ) const;

#ifdef UsingPolyMesh
	// Set un nouveau PolyMesh
	int SetPolyMesh( CATIPolyMesh * & iPolyMesh ) ;

	// Copy du _PolyMesh
	//int ClonePolyMesh( CATIPolyMesh * & oCopyPolyMesh ) const;

	// utilitaire pour le PolyMesh
	CATBoolean ProjectPoint(const CATMathPoint & point, CATMathPoint & proj, int & type, int & num1, int & num2, CATListOfInt & oNeighbors) const;

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
	CATCompoSmoothMap(CATGeoFactory* iFactory, CATSoftwareConfiguration * ipConfig,CATMathStream& ioReadStream );

	/**
	*
	* <br><b>To stream this</b>: 
	* @param ioWriteStream
	* the stream
	* @return
	* 
	*/
	void Stream( CATMathStream& ioWriteStream )const ;
	//void UnStream( CATMathStream& ioStream );
	//// master
	void GetPrerequisiteObjects( CATLISTP(CATICGMObject)& olObjects)const;
	//void Finalize( CATGeoFactory * ipFactory, const CATSoftwareConfiguration* ipSoftwareConfiguration);


private:
	void UnStream2( CATMathStream& ioStream ); // mettre en private ..

	// returns the number of triangles in the sphere of center iP.
	// if iListToStore=0, the result is stored in _IndexTrianglesInSphere,
	// else it is stored in _IndexTrianglesInSphereExtrap.
	int IntersectSphereTriangles(const CATMathPoint& iPInitial, const double iTestRadius, int& oNbTriangle, int iListToStore);

	// ktu
	CATLONG32 EvalNormalizeConvol(const CATMathPoint& iPInitial
		,CATMathPoint & oPModified
		) const;

	CATLONG32 EvalNormalizeConvolFirstDeriv(const CATMathPoint& iPInitial
		,CATMathVector& oDu, CATMathVector& oDV,CATMathVector& oDw
		) const;

	CATLONG32 EvalNormalizeConvolSecondDeriv(const CATMathPoint& iPInitial
		,CATMathVector& oD2u, CATMathVector& oD2v, CATMathVector& oD2w
		,CATMathVector& oDuv, CATMathVector& oDuw, CATMathVector& oDvw
		) const;

	void InitMembers(CATGeoFactory* iFactory, CATSoftwareConfiguration * ipConfig, int iNbFunction, 
		double *iKernelWidths, float** iHeights, float iGlobalHeight);

	//  double  
	//prameters of the kernel and of the mesh
	double _ExtrapolWidth, _TriangleMaxLength;
	double _TestRadius, _ExtrapolRadius;
	/////Debug
	double _KernNormError, _DerKernNormError, _D2KernNormError;
	double _MaxKernelWidth;

	// float 
	float _GlobalHeight;

	//  ptr
	CATGeoFactory* _Factory;
	//CATTopData     *_TopData;
	CATSoftwareConfiguration* _Config;
	CATCldPolygon* _CldPolygon;
#ifdef UsingPolyMesh
	CATIPolyMesh* _PolyMesh;
	//Polymesh description  
	CATIPolyMeshTriangleIterator *_PMTriIter;  
	CATPolyPointMeshDistanceAccelerator * _PMDAccel;
#endif
	float** _VerticesHeights;
	CATBoolean** _SameHeightTriangles; // array that stores for each triangle if its 3 vvertices have the same height

	//Convol Functions
	CATTopoConvolFunction **_ExtrapolF; //array of extrapolation (convolution) function
	CATTopoConvolFunction **_ConvolF;	//array of convolution functions
	//Cld description
	double * _VerticesCoord; 
	int * _NoVertices;
	int * _NoNgbrs;
	unsigned char* _TreatedTriangles;
	CATListOfInt *_IndexTrianglesInSphere, *_IndexTrianglesInSphereExtrap;
	CATMathPoint* _TempPoint;
	CATListOfInt* _ToTreat; //list used to intersect a sphere with a mesh
	double *_KernelWidth;
	//Variables used to detect flat zones where no integration is required
	float *_CommonHeight;
	//
	CATBoolean *_SameHeight;

	// int 
	int _IMLSurfaceLevel;
	int _NbFunction;
	int _NbTriangles;

	// 1 byte
	CATBoolean _NormalizeConvol;
	CATBoolean _BorderTriangle;
	// Champs pour savoir si on gere un clone 
	CATBoolean _IsClone;
	CATBoolean _FromStream;

};

#endif
