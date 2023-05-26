// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATPolyMeshMappingFunctionStapler.h
// The dialog : 
// It is a command.
//
//===================================================================
//
// Usage notes:
// Utilities to manage the attribut of CATPolyMeshMappingFunction
//===================================================================
//  Sept 2013  Creation: ktu
//===================================================================

#ifndef CATPolyMeshMappingFunctionStapler_H
#define CATPolyMeshMappingFunctionStapler_H

#include "Polygon2Surface.h"
class CATBody;
class CATPolyMeshMappingFunction;
class CATSoftwareConfiguration;
class CATMathPoint;
class CATFace;
class CATICGMObject;

/** 
	* Puts the attribut of CATPolyMeshMappingFunction on the body .
	* @param ipBody
	* the  body  object
	* @param ipMappingFunction
	* the fonction to hook up 
	* @param ipConfig
	* CATSofwareConfiguration Object.
	* @return
	*   0 on success and another error otherwise.
	*/
int  ExportedByPolygon2Surface PutPolyMeshMappingFunctionAttr ( CATBody * iopBody,  CATPolyMeshMappingFunction * ipMappingFunction,  CATSoftwareConfiguration* ipConfig );

/** 
	* Retrieves the object CATPolyMeshMappingFunction from  the body .
	* @param ipBody
	* the  body  object
	* @param ipConfig
	* CATSofwareConfiguration Object.
	* @param opMappingFunction
	* the  result , must be NULL in Input
	* @return
	*   0 on success and another error otherwise.
	*/
int  ExportedByPolygon2Surface GetPolyMeshMappingFunction ( CATBody * ipBody, CATSoftwareConfiguration* ipConfig,  CATPolyMeshMappingFunction *& opMappingFunction);

/** 
	* Releases the attribut of CATPolyMeshMappingFunction on the body 
	* @param iopBody
	* the  body  object
	* @param ipConfig
	* CATSofwareConfiguration Object.
	* @return
	*  0 on success and another error otherwise.
	*/
int  ExportedByPolygon2Surface ReleasePolyMeshMappingFunctionAttr ( CATBody * iopBody, CATSoftwareConfiguration* ipConfig);

//[GMOperatorsInterfaces CATIPGMPolyMeshMappingFunctionAttrManager.h]
/** 
	* Evaluates the image of <tt>iPointToEval</tt> 
	* This method is recommended in the presence of tears. 
	* In this case the bijection is localy broken
	* @param ipMappingFunction
	* The mapping function 
	* @param iPointToEval
	* The point to evaluate
	* @param ipPointSuppport
	* the support of the the point. It will be used to choose 
	* the correct image if the point is on the tear line.
	* @param  oUV
	* the result.
	* @return
	*   0 on success or non-zero otherwise.
	*/
int  ExportedByPolygon2Surface EvalPolyMeshMappingFunction (
	CATPolyMeshMappingFunction * ipMappingFunction
	, const CATMathPoint & iPointToEval
	, CATFace* ipPointSuppport
	, double oUV[2] );

/** 
	* Puts the attribut of CATPolyMeshMappingFunction on the CATICGMObject .
	* @param iopObject
	* the  CATICGMObject  object
	* @param ipMappingFunction
	* the fonction to hook up 
	* @param ipConfig
	* CATSofwareConfiguration Object.
	* @return
	*   0 on success and another error otherwise.
	*/
int  ExportedByPolygon2Surface PutPolyMeshMappingFunctionAttr ( CATICGMObject * iopObject,  CATPolyMeshMappingFunction * ipMappingFunction,  CATSoftwareConfiguration* ipConfig );

/** 
	* Retrieves the object CATPolyMeshMappingFunction from  the CATICGMObject .
	* @param ipObject
	* the  CATICGMObject  object
	* @param ipConfig
	* CATSofwareConfiguration Object.
	* @param opMappingFunction
	* the  result , must be NULL in Input
	* @return
	*   0 on success and another error otherwise.
	*/
int  ExportedByPolygon2Surface GetPolyMeshMappingFunction ( CATICGMObject * ipObject, CATSoftwareConfiguration* ipConfig,  CATPolyMeshMappingFunction *& opMappingFunction);

/** 
	* Releases the attribut of CATPolyMeshMappingFunction on the CATICGMObject 
	* @param iopObject
	* the  CATICGMObject  object
	* @param ipConfig
	* CATSofwareConfiguration Object.
	* @return
	*  0 on success and another error otherwise.
	*/
int  ExportedByPolygon2Surface ReleasePolyMeshMappingFunctionAttr ( CATICGMObject * iopObject, CATSoftwareConfiguration* ipConfig);




#endif

