// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// Usage notes: Classe create  a mapping function between  2 Meshs
// working  with CATIPolyMesh 
//
//===================================================================
//  April 2013  Creation: ktu
//===================================================================
#ifndef CATMeshToMeshMappingFunction_H
#define CATMeshToMeshMappingFunction_H
#include "CATPolyMeshMappingOper.h"
#include "CATPolyRefCounted.h"
#include "CATErrorDef.h"
class CATMathPoint;
class CATMathStream;
class CATIPolyMesh;
class CATPolyMeshMappingFunctionImp;
class CATSoftwareConfiguration;

/**
* CATMeshToMeshMappingFunction creates  a mapping function between  2 Meshs .
*
* <br><b>Role</b>: define a bijective appliction from Mesh1 to Mesh   F: Mesh0 -> Mesh1
*
*/

class ExportedByCATPolyMeshMappingOper CATPolyMeshMappingFunction: public CATPolyRefCounted
{

public :
	

/**
*
* <br><b>Constructor: defines a mapping function F: Mesh0 -> Mesh1</b>: 
* @param *ipPolyMesh0
*  the mesh M0
* @param *ipPolyMesh1
*  the mesh M1
* @param iConfig
*  SoftwareConfiguration
*/
	CATPolyMeshMappingFunction(CATIPolyMesh *ipPolyMesh0, CATIPolyMesh *ipPolyMesh1, CATSoftwareConfiguration * iConfig);

/**
*
* <br><b>Constructor of the fonction from the stream. </b>: 
* @param iConfig
*  SoftwareConfiguration
* @param ioReadStream
*  the stream to read
*/
	CATPolyMeshMappingFunction(CATSoftwareConfiguration * iConfig, CATMathStream & ioReadStream);

/**
*
* <br><b>Destructor</b>: 
*/
	~CATPolyMeshMappingFunction();

	/** 
	* Evaluates the image of <tt>iPoint</tt> on Mesh1
	* @param iPoint
	* The Point to evaluate.
	* @param oPoint
	* The image.
	* @return
	*   S_OK on success or E_FAIL or another error otherwise.
	*/
	
	HRESULT Eval (const CATMathPoint & iPoint,  CATMathPoint &oPoint); 

	/** 
	* Evaluates the feasible images of <tt>iPoint</tt> on Mesh1
	* in the presence of tears. In this case the bijection is localy broken
	* @Math iPoint
	* The Point to evaluate.
	* @oNbResults
	* the  number of images
	* @oPoints
	* The images. The c++ array of CATMathPoint. Its size is oNbResults
	* @return
	*   S_OK on success or E_FAIL or another error otherwise.
	*/

	HRESULT Eval (const CATMathPoint & iPoint, int &oNbResults, CATMathPoint *&oPoints ); 

	//HRESULT Eval (const CATMathPoint iPoint[3],  double oUV[6]);
	/** 
	* Evaluates the inverse image of <tt>iPoint</tt> on Mesh0
	* @param iPoint
	* The Point to evaluate.
	* @param oPoint
	* The inverse image.
	* @return
	*   S_OK on success or E_FAIL or another error otherwise.
	*/
	HRESULT EvalInverse (const CATMathPoint & iPoint,  CATMathPoint &oPoint); 


	/** 
	* Evaluates the  baryccentric parameters of the input (on Mesh)
	* @param iPoint
	* The Point to evaluate.
	* @param oTriangleIdx
	* the index of the element
	* @param ou
	* the parameter u.
	* @param ov
	* the parameter v.
	* @param ow
	* the parameter w.
	* @return
	*   S_OK on success or E_FAIL or another error otherwise.
	*/
	HRESULT EvalParam (const CATMathPoint & iPoint, int &oTriangleIdx, double &ou, double &ov, double &ow);
	
	/** 
	* Evaluates the  baryccentric parameters of the input (on Mesh1)
	* @param oTriangleIdx
	* the index of the element
	* @param ou
	* the parameter u.
	* @param ov
	* the parameter v.
	* @param ow
	* the parameter w.

	* @return
	*   S_OK on success or E_FAIL or another error otherwise.
	*/
	HRESULT EvalInverseParam (const CATMathPoint & iPoint, int &oTriangleIdx, double &ou, double &ov, double &ow);


	/** 
	* Evaluates the image from barycentric parameters 
	* @param iTriangleIdx
	* the index of the element
	* @param iu
	* the parameter u.
	* @param iv
	* the parameter v.
	* @param iw
	* the parameter w.
	* @param pPoint
	* The image 
	* @return
	*   S_OK on success or E_FAIL or another error otherwise.
	*/
	HRESULT Eval (const int iTriangleIdx, const double iu, const double iv, const double iw,  CATMathPoint &oPoint); 

	/** 
	* Evaluates the iverse  image from barycentric parameters 
	* @param iTriangleIdx
	* the index of the element
	* @param iu
	* the parameter u.
	* @param iv
	* the parameter v.
	* @param iw
	* the parameter w.
	* @param pPoint
	* The inverse image 
	* @return
	*   S_OK on success or E_FAIL or another error otherwise.
	*/
	HRESULT EvalInverse (const int iTriangleIdx, const double iu, const double iv, const double iw,  CATMathPoint &oPoint); 

	
	/** 
	* Call if you need several evaluation. CPU
	*/
	HRESULT Lock ();
	HRESULT UnLock ();

	// Stream the function
	void Stream(CATMathStream & ioStream) const;

	// Recuperation des PolyMesh.
	CATIPolyMesh* GetMesh0();
	CATIPolyMesh* GetMesh1();


	// On ne calcule que la distorion de l'aire au voisinage du point. 
	//   Calcul Area(M1) / Area(M0)
	// on  pas donc  pae les coordonnees barycentrique.  Acalculer au prealable s'il le faut.
	/** 
	* Evaluates the area distotion around the points given by its barycentric coordinates.
	* @param iTriangleIdx
	* the index of the element
	* @param iu
	* the parameter u.
	* @param iv
	* the parameter v.
	* @param iw
	* the parameter w.
	* @param od
	* The distortion value .
	* @return
	*   S_OK on success or E_FAIL or another error otherwise.
	*/
	HRESULT EvalDistortion (const int iTriangleIdx, const double iu, const double iv, const double iw, double &od); 
	
	CATSoftwareConfiguration * GetSoftwareConfiguration();
private:
	CATPolyMeshMappingFunction(const CATPolyMeshMappingFunction&);
	CATPolyMeshMappingFunction& operator=(const CATPolyMeshMappingFunction&);

	CATPolyMeshMappingFunctionImp * _pPolyMeshMappingFunctionImp;
//	~CATMeshToMeshMappingFunction(); //en private pour forcer un release dans la version finale.
};
#endif
